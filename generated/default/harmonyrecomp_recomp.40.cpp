#include "harmonyrecomp_funcs.40.h"

DEFINE_REX_FUNC(sub_8226B218) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8226B220;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r27,-3160
	ctx.r27.s64 = ctx.r27.s64 + -3160;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8226b41c
	if (ctx.cr6.lt) goto loc_8226B41C;
	// bne cr6,0x8226b48c
	if (!ctx.cr6.eq) goto loc_8226B48C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82240348
	ctx.lr = 0x8226B250;
	sub_82240348(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226b33c
	if (ctx.cr0.eq) goto loc_8226B33C;
	// lis r10,-32108
	ctx.r10.s64 = -2104229888;
	// lis r9,-32108
	ctx.r9.s64 = -2104229888;
	// lwz r11,-27192(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -27192);
	// clrlwi. r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8226b288
	if (!ctx.cr0.eq) goto loc_8226B288;
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,-27192(r10)
	REX_STORE_U32(ctx.r10.u32 + -27192, ctx.r11.u32);
	// lfs f0,17508(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 17508);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,-27196(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27196, temp.u32);
	// b 0x8226b28c
	goto loc_8226B28C;
loc_8226B288:
	// lfs f0,-27196(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27196);
	ctx.f0.f64 = double(temp.f32);
loc_8226B28C:
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_8226B33C:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-2956
	ctx.r29.s64 = ctx.r29.s64 + -2956;
	// addi r30,r30,-2948
	ctx.r30.s64 = ctx.r30.s64 + -2948;
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// stfs f13,0(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x82242a88
	ctx.lr = 0x8226B370;
	sub_82242A88(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r28,r10,62388
	ctx.r28.u64 = ctx.r10.u64 | 62388;
	// lfs f31,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8226b3c8
	if (ctx.cr6.gt) goto loc_8226B3C8;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stfs f31,0(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f31,0(r29)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r11,r11,-3156
	ctx.r11.s64 = ctx.r11.s64 + -3156;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x8226b3c8
	if (ctx.cr6.eq) goto loc_8226B3C8;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfsx f31,r31,r28
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// ori r9,r9,62372
	ctx.r9.u64 = ctx.r9.u64 | 62372;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r7,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r7.u32);
	// stwx r10,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r10.u32);
loc_8226B3C8:
	// bl 0x8243f6d0
	ctx.lr = 0x8226B3CC;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226b48c
	if (ctx.cr0.eq) goto loc_8226B48C;
	// bl 0x82441b00
	ctx.lr = 0x8226B3D8;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8226b3e8
	if (!ctx.cr0.eq) goto loc_8226B3E8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8226b3ec
	goto loc_8226B3EC;
loc_8226B3E8:
	// bl 0x82441f48
	ctx.lr = 0x8226B3EC;
	sub_82441F48(ctx, base);
loc_8226B3EC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8226b48c
	if (!ctx.cr0.eq) goto loc_8226B48C;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-2720
	ctx.r3.s64 = ctx.r3.s64 + -2720;
	// bl 0x822b9c70
	ctx.lr = 0x8226B400;
	sub_822B9C70(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226b48c
	if (ctx.cr0.eq) goto loc_8226B48C;
	// lfsx f0,r31,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bl 0x82270530
	ctx.lr = 0x8226B418;
	sub_82270530(ctx, base);
	// b 0x8226b48c
	goto loc_8226B48C;
loc_8226B41C:
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8226B440;
	sub_8225CEC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// ori r9,r11,62580
	ctx.r9.u64 = ctx.r11.u64 | 62580;
	// addi r29,r29,-2716
	ctx.r29.s64 = ctx.r29.s64 + -2716;
	// li r30,20
	ctx.r30.s64 = 20;
	// ld r11,6272(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 6272);
	// stfs f1,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stfsx f1,r31,r9
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_8226B470:
	// li r4,1000
	ctx.r4.s64 = 1000;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c08c8
	ctx.lr = 0x8226B480;
	sub_825C08C8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r29.u32 = ea;
	// bne 0x8226b470
	if (!ctx.cr0.eq) goto loc_8226B470;
loc_8226B48C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8228D320) {
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
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r11,r11,63176
	ctx.r11.u64 = ctx.r11.u64 | 63176;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8228d3b8
	if (ctx.cr6.eq) goto loc_8228D3B8;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x8228D358;
	sub_82232BA0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8228d3b8
	if (ctx.cr0.eq) goto loc_8228D3B8;
	// lfs f0,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f13,92(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8228D388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12252(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8228d3b8
	if (ctx.cr6.gt) goto loc_8228D3B8;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f2,19088(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19088);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-10608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10608);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x8228D3B4;
	sub_825C0958(ctx, base);
	// stfs f1,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8228D3B8:
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

DEFINE_REX_FUNC(sub_82290DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82290DE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// clrlwi. r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82290e74
	if (ctx.cr0.eq) goto loc_82290E74;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82290E10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
	// bne 0x82290e40
	if (!ctx.cr0.eq) goto loc_82290E40;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwzx r8,r31,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82290e40
	if (!ctx.cr6.eq) goto loc_82290E40;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x82290e64
	goto loc_82290E64;
loc_82290E40:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82290e74
	if (!ctx.cr6.eq) goto loc_82290E74;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82290e74
	if (!ctx.cr6.eq) goto loc_82290E74;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82290E64:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8229ceb8
	ctx.lr = 0x82290E70;
	sub_8229CEB8(ctx, base);
	// b 0x82290ed8
	goto loc_82290ED8;
loc_82290E74:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62401
	ctx.r11.u64 = ctx.r11.u64 | 62401;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r31,500
	ctx.r7.s64 = ctx.r31.s64 + 500;
	// addi r6,r31,472
	ctx.r6.s64 = ctx.r31.s64 + 472;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82290ed0
	if (!ctx.cr0.eq) goto loc_82290ED0;
	// li r9,1
	ctx.r9.s64 = 1;
	// bl 0x82246df0
	ctx.lr = 0x82290EAC;
	sub_82246DF0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14392(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82290ed8
	if (!ctx.cr6.lt) goto loc_82290ED8;
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// b 0x82290ed8
	goto loc_82290ED8;
loc_82290ED0:
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x82246df0
	ctx.lr = 0x82290ED8;
	sub_82246DF0(ctx, base);
loc_82290ED8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8229CE08) {
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
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,456
	ctx.r11.s64 = ctx.r11.s64 + 456;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8229cea4
	if (!ctx.cr0.eq) goto loc_8229CEA4;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// lwz r11,-9776(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -9776);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229ce50
	if (ctx.cr6.eq) goto loc_8229CE50;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82599f08
	ctx.lr = 0x8229CE50;
	sub_82599F08(ctx, base);
loc_8229CE50:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82224210
	ctx.lr = 0x8229CE5C;
	sub_82224210(ctx, base);
	// bl 0x82440f20
	ctx.lr = 0x8229CE60;
	sub_82440F20(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,312
	ctx.r10.u64 = ctx.r10.u64 | 312;
	// addi r4,r4,296
	ctx.r4.s64 = ctx.r4.s64 + 296;
	// lfs f0,20084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20084);
	ctx.f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,24
	ctx.r5.s64 = 24;
	// stbx r9,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u8);
	// li r3,10
	ctx.r3.s64 = 10;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// bl 0x82441518
	ctx.lr = 0x8229CEA4;
	sub_82441518(ctx, base);
loc_8229CEA4:
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

DEFINE_REX_FUNC(sub_822A2D68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x822A2D70;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r26,r26,-3160
	ctx.r26.s64 = ctx.r26.s64 + -3160;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822a2e8c
	if (ctx.cr6.lt) goto loc_822A2E8C;
	// bne cr6,0x822a2eec
	if (!ctx.cr6.eq) goto loc_822A2EEC;
	// addis r28,r3,1
	ctx.r28.s64 = ctx.r3.s64 + 65536;
	// addi r28,r28,-2848
	ctx.r28.s64 = ctx.r28.s64 + -2848;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822a2db4
	if (!ctx.cr6.eq) goto loc_822A2DB4;
	// bl 0x822a67d0
	ctx.lr = 0x822A2DB4;
	sub_822A67D0(ctx, base);
loc_822A2DB4:
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r29,r29,-3152
	ctx.r29.s64 = ctx.r29.s64 + -3152;
	// addi r27,r11,12252
	ctx.r27.s64 = ctx.r11.s64 + 12252;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,-2100
	ctx.r11.s64 = ctx.r11.s64 + -2100;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lfs f31,232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// stb r31,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x822a2e24
	if (ctx.cr6.gt) goto loc_822A2E24;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x822a2e24
	if (ctx.cr6.eq) goto loc_822A2E24;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stb r31,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f31,0(r29)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// ori r11,r8,62372
	ctx.r11.u64 = ctx.r8.u64 | 62372;
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// ori r9,r9,63329
	ctx.r9.u64 = ctx.r9.u64 | 63329;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r8,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
	// stwx r10,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u32);
	// stbx r31,r30,r9
	REX_STORE_U8(ctx.r30.u32 + ctx.r9.u32, ctx.r31.u8);
loc_822A2E24:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9892(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9892);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a2eec
	if (ctx.cr6.eq) goto loc_822A2EEC;
	// bl 0x82441b00
	ctx.lr = 0x822A2E38;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822a2e48
	if (!ctx.cr0.eq) goto loc_822A2E48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x822a2e4c
	goto loc_822A2E4C;
loc_822A2E48:
	// bl 0x82441f48
	ctx.lr = 0x822A2E4C;
	sub_82441F48(ctx, base);
loc_822A2E4C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822a2eec
	if (!ctx.cr0.eq) goto loc_822A2EEC;
	// addis r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 65536;
	// addi r3,r3,-3044
	ctx.r3.s64 = ctx.r3.s64 + -3044;
	// bl 0x822b9c70
	ctx.lr = 0x822A2E60;
	sub_822B9C70(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a2eec
	if (ctx.cr0.eq) goto loc_822A2EEC;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822a2e80
	if (!ctx.cr6.lt) goto loc_822A2E80;
	// lfs f1,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822a2e84
	goto loc_822A2E84;
loc_822A2E80:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
loc_822A2E84:
	// bl 0x822aa770
	ctx.lr = 0x822A2E88;
	sub_822AA770(ctx, base);
	// b 0x822a2eec
	goto loc_822A2EEC;
loc_822A2E8C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63436
	ctx.r11.u64 = ctx.r11.u64 | 63436;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822a2ee4
	if (!ctx.cr0.eq) goto loc_822A2EE4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// li r9,98
	ctx.r9.s64 = 98;
	// lwzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r31,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r31.u32);
	// stw r31,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r31.u32);
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stb r31,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r31.u8);
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
loc_822A2EE4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_822A2EEC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822AC0B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756684
	ctx.lr = 0x822AC0C0;
	__savegprlr_15(ctx, base);
	// stfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.f30.u64);
	// stfd f31,-152(r1)
	REX_STORE_U64(ctx.r1.u32 + -152, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,5656
	ctx.r4.s64 = ctx.r11.s64 + 5656;
	// bl 0x8223fbb0
	ctx.lr = 0x822AC0DC;
	sub_8223FBB0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r26,r11,17768
	ctx.r26.s64 = ctx.r11.s64 + 17768;
	// ori r11,r10,62372
	ctx.r11.u64 = ctx.r10.u64 | 62372;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r10,r9,62396
	ctx.r10.u64 = ctx.r9.u64 | 62396;
	// lfs f31,-5284(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -5284);
	ctx.f31.f64 = double(temp.f32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// ori r9,r8,62400
	ctx.r9.u64 = ctx.r8.u64 | 62400;
	// lfs f30,-5516(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -5516);
	ctx.f30.f64 = double(temp.f32);
	// ori r11,r6,62380
	ctx.r11.u64 = ctx.r6.u64 | 62380;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,10720
	ctx.r8.s64 = ctx.r8.s64 + 10720;
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// ori r11,r10,62388
	ctx.r11.u64 = ctx.r10.u64 | 62388;
	// ori r10,r9,62392
	ctx.r10.u64 = ctx.r9.u64 | 62392;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r25,11
	ctx.r25.s64 = 11;
	// ori r8,r5,62384
	ctx.r8.u64 = ctx.r5.u64 | 62384;
	// stwx r25,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r25.u32);
	// stwx r25,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r25.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r7,r7,62376
	ctx.r7.u64 = ctx.r7.u64 | 62376;
	// ori r11,r4,62404
	ctx.r11.u64 = ctx.r4.u64 | 62404;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,62406
	ctx.r10.u64 = ctx.r10.u64 | 62406;
	// stwx r30,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// ori r8,r8,62408
	ctx.r8.u64 = ctx.r8.u64 | 62408;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r9,r9,62407
	ctx.r9.u64 = ctx.r9.u64 | 62407;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// ori r7,r7,62409
	ctx.r7.u64 = ctx.r7.u64 | 62409;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r11,r11,62405
	ctx.r11.u64 = ctx.r11.u64 | 62405;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r28,-32109
	ctx.r28.s64 = -2104295424;
	// ori r10,r5,62420
	ctx.r10.u64 = ctx.r5.u64 | 62420;
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// ori r8,r3,62428
	ctx.r8.u64 = ctx.r3.u64 | 62428;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r6,r6,62412
	ctx.r6.u64 = ctx.r6.u64 | 62412;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r29,0
	ctx.r29.s64 = 0;
	// ld r11,6848(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// lis r27,0
	ctx.r27.s64 = 0;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// ori r9,r4,62424
	ctx.r9.u64 = ctx.r4.u64 | 62424;
	// stdx r11,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u64);
	// ori r7,r29,62432
	ctx.r7.u64 = ctx.r29.u64 | 62432;
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r5,r27,62436
	ctx.r5.u64 = ctx.r27.u64 | 62436;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// ori r11,r11,62440
	ctx.r11.u64 = ctx.r11.u64 | 62440;
	// stfsx f31,r31,r5
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// ori r10,r10,62444
	ctx.r10.u64 = ctx.r10.u64 | 62444;
	// ori r9,r8,62448
	ctx.r9.u64 = ctx.r8.u64 | 62448;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfsx f30,r31,r9
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// ori r11,r8,62452
	ctx.r11.u64 = ctx.r8.u64 | 62452;
	// ori r10,r10,62456
	ctx.r10.u64 = ctx.r10.u64 | 62456;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// li r29,3
	ctx.r29.s64 = 3;
	// lfs f0,-8400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8400);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r27,-2932
	ctx.r27.s64 = ctx.r27.s64 + -2932;
	// stfsx f30,r31,r11
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_822AC248:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822abd08
	ctx.lr = 0x822AC250;
	sub_822ABD08(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r27,r27,32
	ctx.r27.s64 = ctx.r27.s64 + 32;
	// bge 0x822ac248
	if (!ctx.cr0.lt) goto loc_822AC248;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2776
	ctx.r11.s64 = ctx.r11.s64 + -2776;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822AC26C:
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f31,8(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f31,12(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f31,16(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfsu f31,20(r11)
	ea = 20 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822ac26c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC26C;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2736
	ctx.r11.s64 = ctx.r11.s64 + -2736;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822AC294:
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f31,8(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f31,12(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f31,16(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfsu f31,20(r11)
	ea = 20 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822ac294
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC294;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62868
	ctx.r11.u64 = ctx.r11.u64 | 62868;
	// ori r10,r10,62869
	ctx.r10.u64 = ctx.r10.u64 | 62869;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r9,r9,62872
	ctx.r9.u64 = ctx.r9.u64 | 62872;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r8,r8,62880
	ctx.r8.u64 = ctx.r8.u64 | 62880;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// ori r7,r7,62888
	ctx.r7.u64 = ctx.r7.u64 | 62888;
	// ld r11,6848(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stdx r11,r31,r9
	REX_STORE_U64(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u64);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ld r11,6848(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// ori r6,r10,62896
	ctx.r6.u64 = ctx.r10.u64 | 62896;
	// stdx r11,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u64);
	// li r11,4
	ctx.r11.s64 = 4;
	// ld r10,6848(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// stdx r10,r31,r7
	REX_STORE_U64(ctx.r31.u32 + ctx.r7.u32, ctx.r10.u64);
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r9,r9,62904
	ctx.r9.u64 = ctx.r9.u64 | 62904;
	// ld r10,6848(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stdx r10,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u64);
	// ori r7,r7,62920
	ctx.r7.u64 = ctx.r7.u64 | 62920;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// ori r4,r4,62924
	ctx.r4.u64 = ctx.r4.u64 | 62924;
	// ld r11,6272(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 6272);
	// stdx r11,r31,r9
	REX_STORE_U64(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u64);
	// lis r29,0
	ctx.r29.s64 = 0;
	// ld r11,6272(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 6272);
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfsx f31,r31,r4
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r8,r29,62940
	ctx.r8.u64 = ctx.r29.u64 | 62940;
	// ori r5,r5,62912
	ctx.r5.u64 = ctx.r5.u64 | 62912;
	// ori r10,r10,62928
	ctx.r10.u64 = ctx.r10.u64 | 62928;
	// ori r6,r6,62932
	ctx.r6.u64 = ctx.r6.u64 | 62932;
	// ori r3,r3,62936
	ctx.r3.u64 = ctx.r3.u64 | 62936;
	// addi r7,r7,-2592
	ctx.r7.s64 = ctx.r7.s64 + -2592;
	// addi r4,r4,-2572
	ctx.r4.s64 = ctx.r4.s64 + -2572;
	// stdx r11,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u64);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// stwx r29,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r29.u32);
	// stwx r29,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r29.u32);
	// stfs f31,0(r7)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f31,4(r7)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// addi r9,r9,-2556
	ctx.r9.s64 = ctx.r9.s64 + -2556;
	// stfs f31,8(r7)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f31,12(r7)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// stfs f31,16(r7)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r7.u32 + 16, temp.u32);
	// stfs f31,0(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f31,4(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f31,8(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// stfs f31,12(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f31,16(r4)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r4.u32 + 16, temp.u32);
loc_822AC3BC:
	// stfs f31,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f31,8(r9)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f31,12(r9)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// stfs f31,16(r9)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// stfsu f31,20(r9)
	ea = 20 + ctx.r9.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x822ac3bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC3BC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r10,r10,63068
	ctx.r10.u64 = ctx.r10.u64 | 63068;
	// ori r11,r11,63064
	ctx.r11.u64 = ctx.r11.u64 | 63064;
	// ori r7,r7,63077
	ctx.r7.u64 = ctx.r7.u64 | 63077;
	// ori r8,r8,63076
	ctx.r8.u64 = ctx.r8.u64 | 63076;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// ori r9,r9,63072
	ctx.r9.u64 = ctx.r9.u64 | 63072;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// ori r6,r6,63080
	ctx.r6.u64 = ctx.r6.u64 | 63080;
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r24,0
	ctx.r24.s64 = 0;
	// stfsx f30,r31,r9
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r11,r5,63084
	ctx.r11.u64 = ctx.r5.u64 | 63084;
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ori r10,r4,63088
	ctx.r10.u64 = ctx.r4.u64 | 63088;
	// ori r8,r27,63096
	ctx.r8.u64 = ctx.r27.u64 | 63096;
	// ori r7,r24,63100
	ctx.r7.u64 = ctx.r24.u64 | 63100;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r23,0
	ctx.r23.s64 = 0;
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// stwx r29,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r29.u32);
	// ori r9,r3,63092
	ctx.r9.u64 = ctx.r3.u64 | 63092;
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r6,r23,63104
	ctx.r6.u64 = ctx.r23.u64 | 63104;
	// stwx r30,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// addi r27,r27,-2428
	ctx.r27.s64 = ctx.r27.s64 + -2428;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// ori r10,r10,63144
	ctx.r10.u64 = ctx.r10.u64 | 63144;
	// stw r30,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r30.u32);
	// ori r11,r11,63124
	ctx.r11.u64 = ctx.r11.u64 | 63124;
	// stw r30,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r30.u32);
	// ori r7,r7,63148
	ctx.r7.u64 = ctx.r7.u64 | 63148;
	// stw r30,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r30.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stwx r29,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// ori r9,r9,63145
	ctx.r9.u64 = ctx.r9.u64 | 63145;
	// stwx r30,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// ori r8,r8,63146
	ctx.r8.u64 = ctx.r8.u64 | 63146;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// ori r23,r10,63168
	ctx.r23.u64 = ctx.r10.u64 | 63168;
	// ori r9,r5,63204
	ctx.r9.u64 = ctx.r5.u64 | 63204;
	// ori r3,r11,63160
	ctx.r3.u64 = ctx.r11.u64 | 63160;
	// ori r8,r4,63205
	ctx.r8.u64 = ctx.r4.u64 | 63205;
	// ori r6,r6,63200
	ctx.r6.u64 = ctx.r6.u64 | 63200;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// addis r24,r31,1
	ctx.r24.s64 = ctx.r31.s64 + 65536;
	// ori r4,r10,63152
	ctx.r4.u64 = ctx.r10.u64 | 63152;
	// ori r7,r7,63206
	ctx.r7.u64 = ctx.r7.u64 | 63206;
	// ori r5,r5,63208
	ctx.r5.u64 = ctx.r5.u64 | 63208;
	// addi r24,r24,-2324
	ctx.r24.s64 = ctx.r24.s64 + -2324;
	// ld r10,6848(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 6848);
	// stfsx f31,r31,r3
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stwx r11,r31,r23
	REX_STORE_U32(ctx.r31.u32 + ctx.r23.u32, ctx.r11.u32);
	// stwx r30,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u32);
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// stdx r10,r31,r4
	REX_STORE_U64(ctx.r31.u32 + ctx.r4.u32, ctx.r10.u64);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stbx r29,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r29.u8);
	// addi r28,r10,-30000
	ctx.r28.s64 = ctx.r10.s64 + -30000;
	// stwx r11,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r30,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r30.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r30,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r30.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stw r30,12(r24)
	REX_STORE_U32(ctx.r24.u32 + 12, ctx.r30.u32);
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r23,0
	ctx.r23.s64 = 0;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r6,r6,-2308
	ctx.r6.s64 = ctx.r6.s64 + -2308;
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lis r22,0
	ctx.r22.s64 = 0;
	// lis r21,0
	ctx.r21.s64 = 0;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,0
	ctx.r5.s64 = 0;
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r10,63268
	ctx.r10.u64 = ctx.r10.u64 | 63268;
	// stw r30,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r30.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r20,0
	ctx.r20.s64 = 0;
	// ori r17,r23,64232
	ctx.r17.u64 = ctx.r23.u64 | 64232;
	// ori r16,r22,64236
	ctx.r16.u64 = ctx.r22.u64 | 64236;
	// ori r15,r21,64240
	ctx.r15.u64 = ctx.r21.u64 | 64240;
	// ori r5,r5,63252
	ctx.r5.u64 = ctx.r5.u64 | 63252;
	// ori r4,r4,63256
	ctx.r4.u64 = ctx.r4.u64 | 63256;
	// ori r3,r3,63260
	ctx.r3.u64 = ctx.r3.u64 | 63260;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// ori r26,r26,63261
	ctx.r26.u64 = ctx.r26.u64 | 63261;
	// stfs f13,8(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// ori r9,r9,63264
	ctx.r9.u64 = ctx.r9.u64 | 63264;
	// ori r8,r8,63269
	ctx.r8.u64 = ctx.r8.u64 | 63269;
	// ori r7,r7,63270
	ctx.r7.u64 = ctx.r7.u64 | 63270;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// ori r20,r20,64556
	ctx.r20.u64 = ctx.r20.u64 | 64556;
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lis r19,0
	ctx.r19.s64 = 0;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lis r18,0
	ctx.r18.s64 = 0;
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// stfs f13,16(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 16, temp.u32);
	// addis r22,r31,1
	ctx.r22.s64 = ctx.r31.s64 + 65536;
	// stfs f12,12(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// stw r30,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r30.u32);
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stfsx f31,r31,r4
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// addi r23,r23,-1292
	ctx.r23.s64 = ctx.r23.s64 + -1292;
	// stfsx f31,r31,r20
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r20.u32, temp.u32);
	// addi r22,r22,-988
	ctx.r22.s64 = ctx.r22.s64 + -988;
	// addi r21,r21,-984
	ctx.r21.s64 = ctx.r21.s64 + -984;
	// stbx r30,r31,r3
	REX_STORE_U8(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u8);
	// ori r19,r19,64560
	ctx.r19.u64 = ctx.r19.u64 | 64560;
	// stbx r30,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r30.u8);
	// ori r18,r18,64564
	ctx.r18.u64 = ctx.r18.u64 | 64564;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// addi r10,r10,-968
	ctx.r10.s64 = ctx.r10.s64 + -968;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// stwx r30,r31,r17
	REX_STORE_U32(ctx.r31.u32 + ctx.r17.u32, ctx.r30.u32);
	// stwx r30,r31,r16
	REX_STORE_U32(ctx.r31.u32 + ctx.r16.u32, ctx.r30.u32);
	// stwx r11,r31,r15
	REX_STORE_U32(ctx.r31.u32 + ctx.r15.u32, ctx.r11.u32);
	// stb r30,0(r23)
	REX_STORE_U8(ctx.r23.u32 + 0, ctx.r30.u8);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r30,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r30.u32);
	// stw r30,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r30.u32);
	// addi r3,r3,-948
	ctx.r3.s64 = ctx.r3.s64 + -948;
	// stbx r30,r31,r19
	REX_STORE_U8(ctx.r31.u32 + ctx.r19.u32, ctx.r30.u8);
	// stwx r30,r31,r18
	REX_STORE_U32(ctx.r31.u32 + ctx.r18.u32, ctx.r30.u32);
	// stb r30,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r30.u8);
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// stw r30,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r30.u32);
	// stb r30,12(r10)
	REX_STORE_U8(ctx.r10.u32 + 12, ctx.r30.u8);
	// stb r30,13(r10)
	REX_STORE_U8(ctx.r10.u32 + 13, ctx.r30.u8);
	// stb r25,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r25.u8);
	// stw r30,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r30.u32);
	// bl 0x822232d8
	ctx.lr = 0x822AC698;
	sub_822232D8(ctx, base);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,-916
	ctx.r7.s64 = ctx.r7.s64 + -916;
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r3,-884
	ctx.r3.s64 = ctx.r3.s64 + -884;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r30.u8);
	// stvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f0,8(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stb r30,12(r7)
	REX_STORE_U8(ctx.r7.u32 + 12, ctx.r30.u8);
	// stfs f13,20(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// stfs f12,16(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 16, temp.u32);
	// stw r29,24(r7)
	REX_STORE_U32(ctx.r7.u32 + 24, ctx.r29.u32);
	// stw r30,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r30.u32);
	// bl 0x822232d8
	ctx.lr = 0x822AC70C;
	sub_822232D8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,64684
	ctx.r11.u64 = ctx.r11.u64 | 64684;
	// addi r3,r3,-848
	ctx.r3.s64 = ctx.r3.s64 + -848;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// bl 0x822232d8
	ctx.lr = 0x822AC724;
	sub_822232D8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,64720
	ctx.r11.u64 = ctx.r11.u64 | 64720;
	// addi r3,r3,-812
	ctx.r3.s64 = ctx.r3.s64 + -812;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// bl 0x822232d8
	ctx.lr = 0x822AC73C;
	sub_822232D8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-780
	ctx.r11.s64 = ctx.r11.s64 + -780;
	// addi r3,r3,-776
	ctx.r3.s64 = ctx.r3.s64 + -776;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// stb r29,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r29.u8);
	// bl 0x822232d8
	ctx.lr = 0x822AC758;
	sub_822232D8(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r9,r9,-744
	ctx.r9.s64 = ctx.r9.s64 + -744;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-728
	ctx.r3.s64 = ctx.r3.s64 + -728;
	// stb r30,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r30.u8);
	// stw r29,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r29.u32);
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// bl 0x822232d8
	ctx.lr = 0x822AC79C;
	sub_822232D8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-696
	ctx.r11.s64 = ctx.r11.s64 + -696;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
loc_822AC7AC:
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// stb r30,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r30.u8);
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// blt cr6,0x822ac7ac
	if (ctx.cr6.lt) goto loc_822AC7AC;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-688
	ctx.r3.s64 = ctx.r3.s64 + -688;
	// bl 0x822232d8
	ctx.lr = 0x822AC7D0;
	sub_822232D8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-656
	ctx.r11.s64 = ctx.r11.s64 + -656;
	// addi r3,r3,-648
	ctx.r3.s64 = ctx.r3.s64 + -648;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x822232d8
	ctx.lr = 0x822AC7EC;
	sub_822232D8(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r9,r9,-616
	ctx.r9.s64 = ctx.r9.s64 + -616;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-600
	ctx.r3.s64 = ctx.r3.s64 + -600;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r30.u8);
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stw r30,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r30.u32);
	// bl 0x822232d8
	ctx.lr = 0x822AC830;
	sub_822232D8(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2792
	ctx.r11.s64 = ctx.r11.s64 + -2792;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822AC840:
	// stfs f31,-252(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -252, temp.u32);
	// stw r30,-284(r11)
	REX_STORE_U32(ctx.r11.u32 + -284, ctx.r30.u32);
	// stfs f31,-236(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -236, temp.u32);
	// stw r30,-268(r11)
	REX_STORE_U32(ctx.r11.u32 + -268, ctx.r30.u32);
	// stfs f31,-220(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -220, temp.u32);
	// stfs f31,-204(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -204, temp.u32);
	// stfs f31,-188(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -188, temp.u32);
	// stfs f31,-172(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -172, temp.u32);
	// stfs f31,-156(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -156, temp.u32);
	// stfs f31,-12(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -12, temp.u32);
	// stfsu f31,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822ac840
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC840;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2680
	ctx.r11.s64 = ctx.r11.s64 + -2680;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822AC880:
	// stfs f31,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -12, temp.u32);
	// stfs f31,-4(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// stfsu f31,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822ac880
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC880;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82523e48
	ctx.lr = 0x822AC898;
	sub_82523E48(ctx, base);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r8,r8,-2408
	ctx.r8.s64 = ctx.r8.s64 + -2408;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r11,r11,-2364
	ctx.r11.s64 = ctx.r11.s64 + -2364;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// stw r30,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r30.u32);
	// stw r30,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r30.u32);
	// stw r30,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r30.u32);
loc_822AC8C8:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822ac8c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC8C8;
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r29,7
	ctx.r29.s64 = 7;
	// addi r26,r11,22392
	ctx.r26.s64 = ctx.r11.s64 + 22392;
loc_822AC8E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825fc4b0
	ctx.lr = 0x822AC8F0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822ac90c
	if (ctx.cr0.eq) goto loc_822AC90C;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// b 0x822ac910
	goto loc_822AC910;
loc_822AC90C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_822AC910:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r11,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r27.u32 = ea;
	// bne 0x822ac8e0
	if (!ctx.cr0.eq) goto loc_822AC8E0;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r9,r9,-1496
	ctx.r9.s64 = ctx.r9.s64 + -1496;
	// addi r11,r11,-2264
	ctx.r11.s64 = ctx.r11.s64 + -2264;
	// li r7,12
	ctx.r7.s64 = 12;
loc_822AC930:
	// li r8,16
	ctx.r8.s64 = 16;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_822AC93C:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stbx r30,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r30.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x822ac93c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822AC93C;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x822ac930
	if (!ctx.cr0.eq) goto loc_822AC930;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r5,8(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x822ac98c
	if (ctx.cr6.eq) goto loc_822AC98C;
	// subf r11,r5,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r6,r3
	ctx.r29.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x822ac988
	if (!ctx.cr0.gt) goto loc_822AC988;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x822AC988;
	sub_82755080(ctx, base);
loc_822AC988:
	// stw r29,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r29.u32);
loc_822AC98C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stb r30,0(r23)
	REX_STORE_U8(ctx.r23.u32 + 0, ctx.r30.u8);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r11,-9892(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9892);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ac9ec
	if (ctx.cr6.eq) goto loc_822AC9EC;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r3,r3,-1290
	ctx.r3.s64 = ctx.r3.s64 + -1290;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r3.u32);
	// bl 0x82756d30
	ctx.lr = 0x822AC9BC;
	sub_82756D30(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r3,-1032
	ctx.r3.s64 = ctx.r3.s64 + -1032;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r3.u32);
	// bl 0x82756d30
	ctx.lr = 0x822AC9D4;
	sub_82756D30(ctx, base);
	// lis r11,-32212
	ctx.r11.s64 = -2111045632;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r11,-30376
	ctx.r3.s64 = ctx.r11.s64 + -30376;
	// bl 0x82441618
	ctx.lr = 0x822AC9E8;
	sub_82441618(ctx, base);
	// stb r29,0(r23)
	REX_STORE_U8(ctx.r23.u32 + 0, ctx.r29.u8);
loc_822AC9EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822b88d8
	ctx.lr = 0x822AC9F4;
	sub_822B88D8(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-568
	ctx.r10.s64 = ctx.r10.s64 + -568;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822ACA08:
	// stbu r30,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822aca08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822ACA08;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stb r29,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r29.u8);
	// addi r11,r11,-26400
	ctx.r11.s64 = ctx.r11.s64 + -26400;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-9788(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -9788);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,140(r31)
	REX_STORE_U64(ctx.r31.u32 + 140, ctx.r11.u64);
	// beq cr6,0x822aca6c
	if (ctx.cr6.eq) goto loc_822ACA6C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,26168
	ctx.r3.s64 = ctx.r11.s64 + 26168;
	// bl 0x82486f58
	ctx.lr = 0x822ACA6C;
	sub_82486F58(ctx, base);
loc_822ACA6C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f31,-152(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x827566d4
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F1938) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_822F1F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x822F1F08;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,204
	ctx.r4.s64 = 204;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x822F1F28;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822f1f48
	if (ctx.cr0.eq) goto loc_822F1F48;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f1,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824970a0
	ctx.lr = 0x822F1F40;
	sub_824970A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822f1f4c
	goto loc_822F1F4C;
loc_822F1F48:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822F1F4C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// addi r30,r11,-29008
	ctx.r30.s64 = ctx.r11.s64 + -29008;
	// addi r11,r29,15672
	ctx.r11.s64 = ctx.r29.s64 + 15672;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-1224(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1224);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-3184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3184);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x822F1F6C;
	sub_825C0958(ctx, base);
	// lfs f0,-1236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1236);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,15672(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 15672);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825c0958
	ctx.lr = 0x822F1F84;
	sub_825C0958(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// beq cr6,0x822f2034
	if (ctx.cr6.eq) goto loc_822F2034;
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// lis r29,-32227
	ctx.r29.s64 = -2112028672;
	// lfs f1,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,168(r31)
	REX_STORE_U64(ctx.r31.u32 + 168, ctx.r11.u64);
	// lwz r11,26800(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 26800);
	// lfs f2,-23884(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -23884);
	ctx.f2.f64 = double(temp.f32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bl 0x825c0958
	ctx.lr = 0x822F1FBC;
	sub_825C0958(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f2,-23884(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -23884);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825c0958
	ctx.lr = 0x822F1FD4;
	sub_825C0958(ctx, base);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,176(r31)
	REX_STORE_U64(ctx.r31.u32 + 176, ctx.r10.u64);
	// li r4,5
	ctx.r4.s64 = 5;
	// lfs f0,26792(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26792);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f0,188(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 188, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F2004;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,26736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1216);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F202C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x822f2038
	goto loc_822F2038;
loc_822F2034:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822F2038:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82300158) {
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
	// bl 0x82247990
	ctx.lr = 0x82300170;
	sub_82247990(ctx, base);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r8,-3048
	ctx.r8.s64 = ctx.r8.s64 + -3048;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823001cc
	if (ctx.cr6.eq) goto loc_823001CC;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-9744(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9744);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823001cc
	if (!ctx.cr6.eq) goto loc_823001CC;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823001cc
	if (ctx.cr6.eq) goto loc_823001CC;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823001cc
	if (!ctx.cr0.eq) goto loc_823001CC;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,812(r11)
	REX_STORE_U32(ctx.r11.u32 + 812, ctx.r10.u32);
	// stw r7,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
loc_823001CC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62484
	ctx.r11.u64 = ctx.r11.u64 | 62484;
	// ori r10,r10,62372
	ctx.r10.u64 = ctx.r10.u64 | 62372;
	// ori r9,r9,62408
	ctx.r9.u64 = ctx.r9.u64 | 62408;
	// li r8,9
	ctx.r8.s64 = 9;
	// stbx r7,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r7.u8);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// stwx r7,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r7.u32);
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

DEFINE_REX_FUNC(sub_82304E80) {
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
	// addis r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 65536;
	// addi r7,r7,-3148
	ctx.r7.s64 = ctx.r7.s64 + -3148;
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82304fec
	if (ctx.cr6.lt) goto loc_82304FEC;
	// beq cr6,0x82304f8c
	if (ctx.cr6.eq) goto loc_82304F8C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82304efc
	if (ctx.cr6.eq) goto loc_82304EFC;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x82304ec8
	if (ctx.cr6.eq) goto loc_82304EC8;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x82305050
	if (!ctx.cr6.eq) goto loc_82305050;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x82303040
	ctx.lr = 0x82304EC4;
	sub_82303040(ctx, base);
	// b 0x82305050
	goto loc_82305050;
loc_82304EC8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82305050
	if (ctx.cr0.eq) goto loc_82305050;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62405
	ctx.r11.u64 = ctx.r11.u64 | 62405;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x82305050
	goto loc_82305050;
loc_82304EFC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,62596
	ctx.r9.u64 = ctx.r11.u64 | 62596;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lbzx r9,r3,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82304f1c
	if (ctx.cr0.eq) goto loc_82304F1C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82304F1C:
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,62404
	ctx.r9.u64 = ctx.r9.u64 | 62404;
	// lbzx r9,r3,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82304f34
	if (ctx.cr0.eq) goto loc_82304F34;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82304F34:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82305050
	if (ctx.cr0.eq) goto loc_82305050;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r8,15
	ctx.r8.s64 = 15;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// li r6,96
	ctx.r6.s64 = 96;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// addi r9,r11,68
	ctx.r9.s64 = ctx.r11.s64 + 68;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// stw r6,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r6.u32);
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
	// stw r5,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// b 0x82305050
	goto loc_82305050;
loc_82304F8C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82305050
	if (ctx.cr0.eq) goto loc_82305050;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,14
	ctx.r9.s64 = 14;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// li r8,98
	ctx.r8.s64 = 98;
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r9,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r9.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r9,r9,0,31,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r9,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// b 0x82305050
	goto loc_82305050;
loc_82304FEC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// lwzx r8,r3,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x823cf6f8
	ctx.lr = 0x82305000;
	sub_823CF6F8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,96
	ctx.r9.s64 = 96;
	// cmpwi cr6,r3,10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10, ctx.xer);
	// stb r10,120(r8)
	REX_STORE_U8(ctx.r8.u32 + 120, ctx.r10.u8);
	// stw r10,112(r8)
	REX_STORE_U32(ctx.r8.u32 + 112, ctx.r10.u32);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r9,116(r8)
	REX_STORE_U32(ctx.r8.u32 + 116, ctx.r9.u32);
	// beq cr6,0x82305024
	if (ctx.cr6.eq) goto loc_82305024;
	// li r11,16
	ctx.r11.s64 = 16;
loc_82305024:
	// stw r11,108(r8)
	REX_STORE_U32(ctx.r8.u32 + 108, ctx.r11.u32);
	// addi r11,r8,12
	ctx.r11.s64 = ctx.r8.s64 + 12;
	// addi r11,r8,68
	ctx.r11.s64 = ctx.r8.s64 + 68;
	// lwz r11,16(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,16(r8)
	REX_STORE_U32(ctx.r8.u32 + 16, ctx.r11.u32);
	// lwz r11,72(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 72);
	// rlwinm r11,r11,0,31,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r11,72(r8)
	REX_STORE_U32(ctx.r8.u32 + 72, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
loc_82305050:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82310D48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r8,r8,-2996
	ctx.r8.s64 = ctx.r8.s64 + -2996;
	// ori r9,r11,62440
	ctx.r9.u64 = ctx.r11.u64 | 62440;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82310df8
	if (ctx.cr0.eq) goto loc_82310DF8;
	// lwzx r11,r3,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r31,r7,-30000
	ctx.r31.s64 = ctx.r7.s64 + -30000;
	// addi r7,r11,12
	ctx.r7.s64 = ctx.r11.s64 + 12;
	// addi r7,r11,68
	ctx.r7.s64 = ctx.r11.s64 + 68;
	// stw r6,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r6.u32);
	// addi r4,r1,-48
	ctx.r4.s64 = ctx.r1.s64 + -48;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// addi r30,r1,-32
	ctx.r30.s64 = ctx.r1.s64 + -32;
	// stw r5,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r5.u32);
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r7,r7,4
	ctx.r7.u64 = ctx.r7.u64 | 4;
	// stw r7,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,72(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r7,r7,0,31,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r7,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r7.u32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r3,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// lfs f0,-48(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r7,72(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r7,r7,0,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r7,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r7.u32);
	// stfs f0,-48(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// stfs f13,-44(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// ld r11,-48(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// std r11,128(r3)
	REX_STORE_U64(ctx.r3.u32 + 128, ctx.r11.u64);
	// stb r10,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
loc_82310DF8:
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// lwzx r9,r3,r9
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// addi r11,r11,-3076
	ctx.r11.s64 = ctx.r11.s64 + -3076;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r9,72(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// rlwinm. r9,r9,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82310e4c
	if (ctx.cr0.eq) goto loc_82310E4C;
	// stb r6,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r6.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// ori r9,r9,62536
	ctx.r9.u64 = ctx.r9.u64 | 62536;
	// lis r6,-32207
	ctx.r6.s64 = -2110717952;
	// ori r8,r8,62472
	ctx.r8.u64 = ctx.r8.u64 | 62472;
	// addi r6,r6,3672
	ctx.r6.s64 = ctx.r6.s64 + 3672;
	// lfs f0,12484(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stwx r6,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r6.u32);
	// stbx r10,r3,r8
	REX_STORE_U8(ctx.r3.u32 + ctx.r8.u32, ctx.r10.u8);
loc_82310E4C:
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82317790) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8231784c
	if (ctx.cr0.eq) goto loc_8231784C;
	// bl 0x82242798
	ctx.lr = 0x823177C4;
	sub_82242798(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823178ac
	if (!ctx.cr0.eq) goto loc_823178AC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x822400e0
	ctx.lr = 0x823177E0;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x823177FC;
	sub_822400E0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82317838
	if (ctx.cr6.eq) goto loc_82317838;
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
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c3150
	ctx.lr = 0x82317834;
	sub_823C3150(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_82317838:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62444
	ctx.r11.u64 = ctx.r11.u64 | 62444;
	// stb r9,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r9.u8);
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
loc_8231784C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x82317868;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-3080
	ctx.r11.s64 = ctx.r11.s64 + -3080;
	// addi r10,r10,30920
	ctx.r10.s64 = ctx.r10.s64 + 30920;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x823178ac
	if (ctx.cr6.eq) goto loc_823178AC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32207
	ctx.r8.s64 = -2110717952;
	// ori r10,r10,62440
	ctx.r10.u64 = ctx.r10.u64 | 62440;
	// addi r8,r8,30920
	ctx.r8.s64 = ctx.r8.s64 + 30920;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f0,12484(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stb r7,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r7.u8);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_823178AC:
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

DEFINE_REX_FUNC(sub_8231CB58) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3056
	ctx.r30.s64 = ctx.r30.s64 + -3056;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8231cb8c
	if (ctx.cr0.eq) goto loc_8231CB8C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82872dfc
	ctx.lr = 0x8231CB8C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8231CB8C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-3072
	ctx.r11.s64 = ctx.r11.s64 + -3072;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r6,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r5,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// beq 0x8231cbd4
	if (ctx.cr0.eq) goto loc_8231CBD4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82872dec
	ctx.lr = 0x8231CBD4;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8231CBD4:
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8231ccc8
	if (ctx.cr0.eq) goto loc_8231CCC8;
	// bl 0x82440f20
	ctx.lr = 0x8231CBE4;
	sub_82440F20(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f0,20084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20084);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8231cc34
	if (!ctx.cr6.gt) goto loc_8231CC34;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r9,0
	ctx.r9.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// ori r11,r9,62460
	ctx.r11.u64 = ctx.r9.u64 | 62460;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,-7164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8231cc60
	goto loc_8231CC60;
loc_8231CC34:
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// addi r10,r10,-2512
	ctx.r10.s64 = ctx.r10.s64 + -2512;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,0
	ctx.r11.s64 = 0;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 784);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
loc_8231CC60:
	// fmuls f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lbz r3,108(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// bl 0x82440ec0
	ctx.lr = 0x8231CC70;
	sub_82440EC0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-3024
	ctx.r11.s64 = ctx.r11.s64 + -3024;
	// ori r10,r10,62432
	ctx.r10.u64 = ctx.r10.u64 | 62432;
	// lis r9,-32206
	ctx.r9.s64 = -2110652416;
	// addi r9,r9,-9440
	ctx.r9.s64 = ctx.r9.s64 + -9440;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stwx r3,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8231ccc8
	if (ctx.cr6.eq) goto loc_8231CCC8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lis r7,-32206
	ctx.r7.s64 = -2110652416;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// ori r9,r9,62516
	ctx.r9.u64 = ctx.r9.u64 | 62516;
	// addi r7,r7,-9440
	ctx.r7.s64 = ctx.r7.s64 + -9440;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,12484(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stbx r6,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u8);
loc_8231CCC8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

DEFINE_REX_FUNC(sub_82325568) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,204
	ctx.r4.s64 = 204;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x8232559C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823255c4
	if (ctx.cr0.eq) goto loc_823255C4;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,27608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2608);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x824970a0
	ctx.lr = 0x823255BC;
	sub_824970A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x823255c8
	goto loc_823255C8;
loc_823255C4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823255C8:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8232563c
	if (ctx.cr6.eq) goto loc_8232563C;
	// lis r30,-32240
	ctx.r30.s64 = -2112880640;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r10,r30,12488
	ctx.r10.s64 = ctx.r30.s64 + 12488;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-6328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6328);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,-236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -236);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825c0958
	ctx.lr = 0x823255F0;
	sub_825C0958(ctx, base);
	// lfs f0,12488(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12488);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fneg f30,f1
	ctx.f30.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825c0958
	ctx.lr = 0x82325608;
	sub_825C0958(ctx, base);
	// li r11,204
	ctx.r11.s64 = 204;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r10,255
	ctx.r10.s64 = 255;
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r9,127
	ctx.r9.s64 = 127;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// stb r9,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r9.u8);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,168(r31)
	REX_STORE_U64(ctx.r31.u32 + 168, ctx.r10.u64);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
loc_8232563C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

DEFINE_REX_FUNC(sub_8232F958) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3164
	ctx.r11.s64 = ctx.r11.s64 + -3164;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8232f974
	if (!ctx.cr6.eq) goto loc_8232F974;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8232F974:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r10,r10,62692
	ctx.r10.u64 = ctx.r10.u64 | 62692;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lfs f0,12484(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r3,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8232FF80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8232FF88;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x827576c8
	ctx.lr = 0x8232FF90;
	__savefpr_28(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r4,48
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(48));
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addis r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 65536;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r31,r31,-3160
	ctx.r31.s64 = ctx.r31.s64 + -3160;
	// lbz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 44);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8233030c
	if (ctx.cr6.lt) goto loc_8233030C;
	// beq cr6,0x82330004
	if (ctx.cr6.eq) goto loc_82330004;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x823305f0
	if (!ctx.cr6.lt) goto loc_823305F0;
	// lwz r11,252(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823305f0
	if (!ctx.cr6.lt) goto loc_823305F0;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82330000;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x823305f0
	goto loc_823305F0;
loc_82330004:
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r26,r1,96
	ctx.r26.s64 = ctx.r1.s64 + 96;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,80
	ctx.r28.s64 = ctx.r1.s64 + 80;
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r25,r1,96
	ctx.r25.s64 = ctx.r1.s64 + 96;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r27,r11,20804
	ctx.r27.s64 = ctx.r11.s64 + 20804;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r31)
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
	// lvx128 v12,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f0,-22276(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -22276);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v0,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// bl 0x82271ed0
	ctx.lr = 0x823300FC;
	sub_82271ED0(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r28,r10,-28872
	ctx.r28.s64 = ctx.r10.s64 + -28872;
	// addi r26,r11,14296
	ctx.r26.s64 = ctx.r11.s64 + 14296;
	// lfs f31,-2104(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2104);
	ctx.f31.f64 = double(temp.f32);
	// lfs f2,808(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 808);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825c0958
	ctx.lr = 0x82330120;
	sub_825C0958(ctx, base);
	// addi r11,r29,-4
	ctx.r11.s64 = ctx.r29.s64 + -4;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f30,-29476(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29476);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f13,f1,f13,f30
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f30.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x823302f8
	if (!ctx.cr6.gt) goto loc_823302F8;
	// lfs f29,28(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 28);
	ctx.f29.f64 = double(temp.f32);
	// li r25,0
	ctx.r25.s64 = 0;
loc_82330158:
	// extsw r11,r25
	ctx.r11.s64 = ctx.r25.s32;
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// lfd f13,136(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82330238
	if (!ctx.cr6.gt) goto loc_82330238;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x8233018C;
	sub_825C0958(ctx, base);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x823301A0;
	sub_825C0958(ctx, base);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f28,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f28,112(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f28,124(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f1,204(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f1,196(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f1,192(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f1,200(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x82330600
	ctx.lr = 0x82330238;
	sub_82330600(ctx, base);
loc_82330238:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r25,3
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 3, ctx.xer);
	// blt cr6,0x82330158
	if (ctx.cr6.lt) goto loc_82330158;
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x82330288
	if (!ctx.cr6.gt) goto loc_82330288;
	// lwz r11,252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82330288
	if (!ctx.cr6.lt) goto loc_82330288;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82330288;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82330288:
	// lfs f13,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-3100(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -3100);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823302f8
	if (!ctx.cr6.gt) goto loc_823302F8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x822400e0
	ctx.lr = 0x823302AC;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x823302C8;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f0.u64);
	// lwz r5,140(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// li r3,100
	ctx.r3.s64 = 100;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f0.u64);
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// bl 0x82250ad8
	ctx.lr = 0x823302F0;
	sub_82250AD8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r11,44(r31)
	REX_STORE_U8(ctx.r31.u32 + 44, ctx.r11.u8);
loc_823302F8:
	// lfs f13,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-2044(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -2044);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,16(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// b 0x823305f0
	goto loc_823305F0;
loc_8233030C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x822400e0
	ctx.lr = 0x82330320;
	sub_822400E0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// addi r28,r11,14296
	ctx.r28.s64 = ctx.r11.s64 + 14296;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lfs f29,-1812(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1812);
	ctx.f29.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne cr6,0x823303e8
	if (!ctx.cr6.eq) goto loc_823303E8;
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bge cr6,0x82330380
	if (!ctx.cr6.lt) goto loc_82330380;
	// lwz r11,252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// ble cr6,0x82330380
	if (!ctx.cr6.gt) goto loc_82330380;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82330380;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82330380:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x822400e0
	ctx.lr = 0x82330394;
	sub_822400E0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_823303E8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// cmpwi cr6,r29,5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 5, ctx.xer);
	// addi r27,r11,20804
	ctx.r27.s64 = ctx.r11.s64 + 20804;
	// lfs f30,-27132(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -27132);
	ctx.f30.f64 = double(temp.f32);
	// bne cr6,0x82330498
	if (!ctx.cr6.eq) goto loc_82330498;
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// ble cr6,0x82330438
	if (!ctx.cr6.gt) goto loc_82330438;
	// lwz r11,252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// ble cr6,0x82330438
	if (!ctx.cr6.gt) goto loc_82330438;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82330438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82330438:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x822400e0
	ctx.lr = 0x8233044C;
	sub_822400E0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f31,f30
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82330498:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822400e0
	ctx.lr = 0x823304AC;
	sub_822400E0(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-30272
	ctx.r11.s64 = ctx.r11.s64 + -30272;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// bl 0x82271ed0
	ctx.lr = 0x823304FC;
	sub_82271ED0(ctx, base);
	// lwz r11,252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82330534
	if (!ctx.cr6.lt) goto loc_82330534;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82330534;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82330534:
	// lfs f2,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f1,1376(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x82330544;
	sub_825C0958(ctx, base);
	// lfs f0,-1808(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1808);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f13,f1,f31
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r31,8
	ctx.r4.s64 = ctx.r31.s64 + 8;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r11.u64);
	// bl 0x82454930
	ctx.lr = 0x823305B4;
	sub_82454930(ctx, base);
	// addi r11,r29,-4
	ctx.r11.s64 = ctx.r29.s64 + -4;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// lfd f13,136(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmadds f0,f13,f0,f30
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f30.f64)));
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stb r10,44(r31)
	REX_STORE_U8(ctx.r31.u32 + 44, ctx.r10.u8);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823305F0:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82757714
	ctx.lr = 0x823305FC;
	__restfpr_28(ctx, base);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82334368) {
	REX_FUNC_PROLOGUE();
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62666
	ctx.r11.u64 = ctx.r11.u64 | 62666;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82334790) {
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
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x8243f6d0
	ctx.lr = 0x823347B0;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823347ec
	if (ctx.cr0.eq) goto loc_823347EC;
	// bl 0x82441b00
	ctx.lr = 0x823347BC;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823347cc
	if (!ctx.cr0.eq) goto loc_823347CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823347d0
	goto loc_823347D0;
loc_823347CC:
	// bl 0x82441f48
	ctx.lr = 0x823347D0;
	sub_82441F48(ctx, base);
loc_823347D0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,0
	ctx.r11.s64 = 0;
	// bne 0x823347f0
	if (!ctx.cr0.eq) goto loc_823347F0;
	// ori r11,r11,62712
	ctx.r11.u64 = ctx.r11.u64 | 62712;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// b 0x82334814
	goto loc_82334814;
loc_823347EC:
	// lis r11,0
	ctx.r11.s64 = 0;
loc_823347F0:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// lfs f0,12252(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12252);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8233481c
	if (ctx.cr6.lt) goto loc_8233481C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82334838
	ctx.lr = 0x82334810;
	sub_82334838(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_82334814:
	// beq 0x8233481c
	if (ctx.cr0.eq) goto loc_8233481C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8233481C:
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

DEFINE_REX_FUNC(sub_82339770) {
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
	// bl 0x82247990
	ctx.lr = 0x82339788;
	sub_82247990(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62476
	ctx.r11.u64 = ctx.r11.u64 | 62476;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823397a4
	if (ctx.cr6.eq) goto loc_823397A4;
	// stb r10,368(r11)
	REX_STORE_U8(ctx.r11.u32 + 368, ctx.r10.u8);
loc_823397A4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// ori r9,r9,62440
	ctx.r9.u64 = ctx.r9.u64 | 62440;
	// ori r8,r8,62452
	ctx.r8.u64 = ctx.r8.u64 | 62452;
	// li r6,9
	ctx.r6.s64 = 9;
	// lfs f0,12484(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stwx r6,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r6.u32);
	// stwx r10,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
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

DEFINE_REX_FUNC(sub_8233D788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8233D790;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// lfs f0,232(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// lfs f13,236(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// addi r11,r11,-3204
	ctx.r11.s64 = ctx.r11.s64 + -3204;
	// lwz r27,92(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfs f0,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lwz r31,-9960(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -9960);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r25,84(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233d818
	if (ctx.cr6.eq) goto loc_8233D818;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c3150
	ctx.lr = 0x8233D818;
	sub_823C3150(ctx, base);
loc_8233D818:
	// clrlwi r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233d838
	if (ctx.cr6.eq) goto loc_8233D838;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c3150
	ctx.lr = 0x8233D838;
	sub_823C3150(ctx, base);
loc_8233D838:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233d850
	if (!ctx.cr6.eq) goto loc_8233D850;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8233d8e0
	goto loc_8233D8E0;
loc_8233D850:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-27536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27536);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8233d868
	if (ctx.cr6.lt) goto loc_8233D868;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8233D868:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8233d8dc
	if (ctx.cr0.eq) goto loc_8233D8DC;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r9,r11,23952
	ctx.r9.s64 = ctx.r11.s64 + 23952;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// ld r11,6848(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8233d8d0
	if (ctx.cr6.eq) goto loc_8233D8D0;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c37d0
	ctx.lr = 0x8233D8D0;
	sub_823C37D0(ctx, base);
loc_8233D8D0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq 0x8233d8e0
	if (ctx.cr0.eq) goto loc_8233D8E0;
loc_8233D8DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8233D8E0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823485C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62496
	ctx.r11.u64 = ctx.r11.u64 | 62496;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823485d8
	if (!ctx.cr0.eq) goto loc_823485D8;
	// b 0x82241ba0
	sub_82241BA0(ctx, base);
	return;
loc_823485D8:
	// b 0x8234bc68
	sub_8234BC68(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823493A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823493A8;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r27,-3156
	ctx.r27.s64 = ctx.r27.s64 + -3156;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823496dc
	if (ctx.cr6.lt) goto loc_823496DC;
	// beq cr6,0x82349590
	if (ctx.cr6.eq) goto loc_82349590;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8234943c
	if (ctx.cr6.lt) goto loc_8234943C;
	// bne cr6,0x82349758
	if (!ctx.cr6.eq) goto loc_82349758;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x823493F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-23916
	ctx.r11.s64 = ctx.r11.s64 + -23916;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8234941c
	if (ctx.cr6.lt) goto loc_8234941C;
	// lfs f13,-5020(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5020);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82349758
	if (ctx.cr6.lt) goto loc_82349758;
loc_8234941C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32203
	ctx.r10.s64 = -2110455808;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,-29936
	ctx.r10.s64 = ctx.r10.s64 + -29936;
	// stw r9,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// b 0x82349758
	goto loc_82349758;
loc_8234943C:
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
	ctx.lr = 0x82349454;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lfs f0,-23916(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23916);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82349478
	if (ctx.cr6.lt) goto loc_82349478;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
loc_82349478:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x822400e0
	ctx.lr = 0x8234948C;
	sub_822400E0(ctx, base);
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
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x823494A8;
	sub_822400E0(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r29,r29,-3132
	ctx.r29.s64 = ctx.r29.s64 + -3132;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82232ba0
	ctx.lr = 0x823494D0;
	sub_82232BA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x823494E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8234b7d0
	ctx.lr = 0x823494F8;
	sub_8234B7D0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// beq 0x82349514
	if (ctx.cr0.eq) goto loc_82349514;
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
loc_82349514:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lfs f13,-232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-3136
	ctx.r10.s64 = ctx.r10.s64 + -3136;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f12,f31
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x82349758
	if (ctx.cr6.lt) goto loc_82349758;
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ba0
	ctx.lr = 0x8234954C;
	sub_82232BA0(ctx, base);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// lfs f1,-232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// stb r28,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r28.u8);
	// stb r28,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r28.u8);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,236(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82349574;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,76(r9)
	REX_STORE_U32(ctx.r9.u32 + 76, ctx.r11.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// b 0x82349758
	goto loc_82349758;
loc_82349590:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x822400e0
	ctx.lr = 0x823495A4;
	sub_822400E0(ctx, base);
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
	// bl 0x822400e0
	ctx.lr = 0x823495C0;
	sub_822400E0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ba0
	ctx.lr = 0x823495E8;
	sub_82232BA0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r11,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
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
	ctx.lr = 0x8234960C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r3.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82349628;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r9,r10,1732
	ctx.r9.s64 = ctx.r10.s64 + 1732;
	// addi r29,r11,12484
	ctx.r29.s64 = ctx.r11.s64 + 12484;
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// lfs f1,1732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1732);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,22620(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22620);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82233d28
	ctx.lr = 0x8234964C;
	sub_82233D28(ctx, base);
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
	ctx.lr = 0x82349664;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f12,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x8234969c
	if (!ctx.cr6.eq) goto loc_8234969C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lis r9,-32113
	ctx.r9.s64 = -2104557568;
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// ori r10,r10,62388
	ctx.r10.u64 = ctx.r10.u64 | 62388;
	// lfs f13,4120(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,28584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f13,r31,r11
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f12,r31,r10
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// b 0x823496cc
	goto loc_823496CC;
loc_8234969C:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// ori r9,r9,62384
	ctx.r9.u64 = ctx.r9.u64 | 62384;
	// ori r8,r8,62388
	ctx.r8.u64 = ctx.r8.u64 | 62388;
	// lfs f13,4120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f0,28584(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f13,r31,r9
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f12,r31,r8
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
loc_823496CC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// b 0x82349758
	goto loc_82349758;
loc_823496DC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// lfs f31,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8225cec0
	ctx.lr = 0x82349704;
	sub_8225CEC0(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,1732
	ctx.r11.s64 = ctx.r11.s64 + 1732;
	// lfs f1,-8060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8060);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,236(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82349728;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f31,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// ori r10,r10,62388
	ctx.r10.u64 = ctx.r10.u64 | 62388;
	// ori r9,r9,62400
	ctx.r9.u64 = ctx.r9.u64 | 62400;
	// li r8,1
	ctx.r8.s64 = 1;
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stw r8,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r8.u32);
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
loc_82349758:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82360DF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x82360E00;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r26,r26,-3020
	ctx.r26.s64 = ctx.r26.s64 + -3020;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lbz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// ori r27,r10,62520
	ctx.r27.u64 = ctx.r10.u64 | 62520;
	// ori r28,r9,62524
	ctx.r28.u64 = ctx.r9.u64 | 62524;
	// addi r30,r11,-5780
	ctx.r30.s64 = ctx.r11.s64 + -5780;
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82360f28
	if (ctx.cr0.eq) goto loc_82360F28;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// li r9,2
	ctx.r9.s64 = 2;
	// ori r8,r10,62428
	ctx.r8.u64 = ctx.r10.u64 | 62428;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r29,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r29.u32);
	// stw r29,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r29.u32);
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stb r29,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r29.u8);
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
	// lfsx f1,r3,r8
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82360EAC;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// ori r11,r11,62412
	ctx.r11.u64 = ctx.r11.u64 | 62412;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-27536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27536);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// bl 0x823627f0
	ctx.lr = 0x82360ED0;
	sub_823627F0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234ee40
	ctx.lr = 0x82360EDC;
	sub_8234EE40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f1,31044(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 31044);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r25,r11,-2512
	ctx.r25.s64 = ctx.r11.s64 + -2512;
	// lfs f2,1000(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 1000);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x82360EF4;
	sub_825C0958(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,980(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 980);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825c0958
	ctx.lr = 0x82360F08;
	sub_825C0958(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62400
	ctx.r11.u64 = ctx.r11.u64 | 62400;
	// lfsx f0,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfsx f1,r31,r28
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stb r29,0(r26)
	REX_STORE_U8(ctx.r26.u32 + 0, ctx.r29.u8);
loc_82360F28:
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r26,r26,-3140
	ctx.r26.s64 = ctx.r26.s64 + -3140;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bl 0x823627f0
	ctx.lr = 0x82360F4C;
	sub_823627F0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234ee40
	ctx.lr = 0x82360F58;
	sub_8234EE40(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,-548(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -548);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-5040(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -5040);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r31,r28
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823604a8
	ctx.lr = 0x82361004;
	sub_823604A8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62416
	ctx.r11.u64 = ctx.r11.u64 | 62416;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82361080
	if (!ctx.cr6.gt) goto loc_82361080;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r5,r11,4880
	ctx.r5.s64 = ctx.r11.s64 + 4880;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824d3cb8
	ctx.lr = 0x82361030;
	sub_824D3CB8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823201d0
	ctx.lr = 0x82361040;
	sub_823201D0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8228e530
	ctx.lr = 0x82361054;
	sub_8228E530(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4376(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4376);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82361070
	if (!ctx.cr6.lt) goto loc_82361070;
	// li r29,1
	ctx.r29.s64 = 1;
loc_82361070:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82361080
	if (ctx.cr0.eq) goto loc_82361080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823625e0
	ctx.lr = 0x82361080;
	sub_823625E0(ctx, base);
loc_82361080:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823626b0
	ctx.lr = 0x82361088;
	sub_823626B0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82372120) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82372128;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ori r31,r4,15
	ctx.r31.u64 = ctx.r4.u64 | 15;
	// li r11,-2
	ctx.r11.s64 = -2;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8237214c
	if (!ctx.cr6.gt) goto loc_8237214C;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// b 0x82372174
	goto loc_82372174;
loc_8237214C:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// li r9,3
	ctx.r9.s64 = 3;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// divwu r9,r31,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r31.u32 / ctx.r9.u32 : 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82372174
	if (!ctx.cr6.lt) goto loc_82372174;
	// subfic r9,r10,-2
	ctx.xer.ca = ctx.r10.u32 <= 4294967294;
	ctx.r9.u64 = static_cast<uint64_t>(-2) - ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x82372174
	if (ctx.cr6.gt) goto loc_82372174;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82372174:
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// addi r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x82372190;
	sub_825FC4B0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x823721c4
	if (ctx.cr6.eq) goto loc_823721C4;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x823721b0
	if (ctx.cr6.lt) goto loc_823721B0;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x823721b4
	goto loc_823721B4;
loc_823721B0:
	// addi r5,r30,4
	ctx.r5.s64 = ctx.r30.s64 + 4;
loc_823721B4:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82754fa8
	ctx.lr = 0x823721C4;
	sub_82754FA8(ctx, base);
loc_823721C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82371af8
	ctx.lr = 0x823721D4;
	sub_82371AF8(ctx, base);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// stw r31,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// stw r27,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r27.u32);
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// blt cr6,0x823721f0
	if (ctx.cr6.lt) goto loc_823721F0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_823721F0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stbx r10,r11,r27
	REX_STORE_U8(ctx.r11.u32 + ctx.r27.u32, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823762C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823762D0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,-9988(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9988);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237632c
	if (ctx.cr6.eq) goto loc_8237632C;
	// lwz r9,288(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// lwz r8,284(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 284);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82376320
	if (!ctx.cr6.lt) goto loc_82376320;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82376320
	if (ctx.cr6.eq) goto loc_82376320;
	// bl 0x82476250
	ctx.lr = 0x8237631C;
	sub_82476250(ctx, base);
	// b 0x82376324
	goto loc_82376324;
loc_82376320:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82376324:
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x82376330
	goto loc_82376330;
loc_8237632C:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82376330:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82376394
	if (ctx.cr6.eq) goto loc_82376394;
	// addi r31,r27,100
	ctx.r31.s64 = ctx.r27.s64 + 100;
	// li r29,2
	ctx.r29.s64 = 2;
loc_82376340:
	// lwz r11,-36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8237636c
	if (ctx.cr6.eq) goto loc_8237636C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82376388
	if (!ctx.cr6.eq) goto loc_82376388;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82376388
	if (ctx.cr6.eq) goto loc_82376388;
	// addi r3,r31,-8
	ctx.r3.s64 = ctx.r31.s64 + -8;
	// bl 0x8237abc0
	ctx.lr = 0x82376368;
	sub_8237ABC0(ctx, base);
	// b 0x82376388
	goto loc_82376388;
loc_8237636C:
	// addi r30,r31,-40
	ctx.r30.s64 = ctx.r31.s64 + -40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823763a0
	ctx.lr = 0x8237637C;
	sub_823763A0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82376810
	ctx.lr = 0x82376388;
	sub_82376810(ctx, base);
loc_82376388:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,124
	ctx.r31.s64 = ctx.r31.s64 + 124;
	// bne 0x82376340
	if (!ctx.cr0.eq) goto loc_82376340;
loc_82376394:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82379BA0) {
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
	// bl 0x82379bf8
	ctx.lr = 0x82379BC0;
	sub_82379BF8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82379bd8
	if (ctx.cr0.eq) goto loc_82379BD8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82379bd8
	if (ctx.cr6.eq) goto loc_82379BD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82379BD8;
	sub_825FC588(ctx, base);
loc_82379BD8:
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

DEFINE_REX_FUNC(sub_8237C6C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,292(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 292);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr
	if (!ctx.cr0.eq) return;
	// lbz r11,293(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 293);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr
	if (!ctx.cr0.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,292(r3)
	REX_STORE_U8(ctx.r3.u32 + 292, ctx.r11.u8);
	// stb r11,293(r3)
	REX_STORE_U8(ctx.r3.u32 + 293, ctx.r11.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8237D5C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8237D5D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,496
	ctx.r4.s64 = 496;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x8237D5F8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8237d614
	if (ctx.cr0.eq) goto loc_8237D614;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8237d620
	ctx.lr = 0x8237D610;
	sub_8237D620(ctx, base);
	// b 0x8237d618
	goto loc_8237D618;
loc_8237D614:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8237D618:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237EBF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,8
	ctx.r11.s64 = 8;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r9,6764
	ctx.r7.s64 = ctx.r9.s64 + 6764;
loc_8237EC10:
	// lwz r9,8(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r8,4(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8237ec30
	if (ctx.cr6.lt) goto loc_8237EC30;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8237ec38
	goto loc_8237EC38;
loc_8237EC30:
	// lwz r9,84(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwzx r9,r9,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_8237EC38:
	// lfsx f0,r11,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// stfs f0,96(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 96, temp.u32);
	// blt cr6,0x8237ec54
	if (ctx.cr6.lt) goto loc_8237EC54;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// li r8,5
	ctx.r8.s64 = 5;
	// ble cr6,0x8237ec58
	if (!ctx.cr6.gt) goto loc_8237EC58;
loc_8237EC54:
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_8237EC58:
	// stw r8,120(r9)
	REX_STORE_U32(ctx.r9.u32 + 120, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8237ec10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237EC10;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r9,272(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lfs f12,6748(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6748);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,6744(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 6744);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x8237ece8
	if (!ctx.cr6.gt) goto loc_8237ECE8;
loc_8237EC88:
	// lwz r9,8(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r8,4(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r10,280(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 280);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8237ecb0
	if (ctx.cr6.lt) goto loc_8237ECB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8237ecbc
	goto loc_8237ECBC;
loc_8237ECB0:
	// lwz r9,84(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8237ECBC:
	// clrlwi. r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8237eccc
	if (!ctx.cr0.eq) goto loc_8237ECCC;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8237ecd0
	goto loc_8237ECD0;
loc_8237ECCC:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8237ECD0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// stw r5,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r5.u32);
	// lwz r10,272(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8237ec88
	if (ctx.cr6.lt) goto loc_8237EC88;
loc_8237ECE8:
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r10,276(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 276);
	// addi r9,r3,284
	ctx.r9.s64 = ctx.r3.s64 + 284;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8237ECF8:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8237ed64
	if (!ctx.cr6.gt) goto loc_8237ED64;
loc_8237ED04:
	// lwz r8,8(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r7,4(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8237ed2c
	if (ctx.cr6.lt) goto loc_8237ED2C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8237ed38
	goto loc_8237ED38;
loc_8237ED2C:
	// lwz r8,84(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
loc_8237ED38:
	// clrlwi. r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8237ed48
	if (!ctx.cr0.eq) goto loc_8237ED48;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x8237ed4c
	goto loc_8237ED4C;
loc_8237ED48:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_8237ED4C:
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r5.u32);
	// lwz r10,276(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 276);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8237ed04
	if (ctx.cr6.lt) goto loc_8237ED04;
loc_8237ED64:
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// bdnz 0x8237ecf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237ECF8;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82388038) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,24136
	ctx.r3.s64 = ctx.r11.s64 + 24136;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_823881D0) {
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
	// bl 0x82388228
	ctx.lr = 0x823881F0;
	sub_82388228(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82388208
	if (ctx.cr0.eq) goto loc_82388208;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82388208
	if (ctx.cr6.eq) goto loc_82388208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82388208;
	sub_825FC588(ctx, base);
loc_82388208:
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

DEFINE_REX_FUNC(sub_82389FA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// std r11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r11.u64);
	// lfd f0,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// std r10,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f13,-32(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// std r11,236(r3)
	REX_STORE_U64(ctx.r3.u32 + 236, ctx.r11.u64);
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,244(r3)
	REX_STORE_U32(ctx.r3.u32 + 244, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8238E2D0) {
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
	// bl 0x827576c0
	ctx.lr = 0x8238E2E8;
	__savefpr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f13,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fmr f27,f1
	ctx.f27.f64 = ctx.f1.f64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8238e318
	if (ctx.cr6.lt) goto loc_8238E318;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,8(r3)
	REX_STORE_U8(ctx.r3.u32 + 8, ctx.r11.u8);
	// b 0x8238e474
	goto loc_8238E474;
loc_8238E318:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r11,-2512
	ctx.r30.s64 = ctx.r11.s64 + -2512;
	// lfs f12,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f31,f0,f27,f13
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f27.f64, ctx.f13.f64)));
	// lfs f30,116(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x822d2870
	ctx.lr = 0x8238E33C;
	sub_822D2870(ctx, base);
	// lfd f29,96(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r30.u32 + 96);
	// fmr f26,f1
	ctx.f26.f64 = ctx.f1.f64;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82755778
	ctx.lr = 0x8238E350;
	sub_82755778(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f28,464(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 464);
	ctx.f28.f64 = double(temp.f32);
	// lfs f9,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f13,f9,f26
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f26.f64));
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,52(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fmsubs f0,f13,f31,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f31.f64, -ctx.f0.f64)));
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
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
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f8,f0
	ctx.f8.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f11,f8
	ctx.cr6.compare(ctx.f11.f64, ctx.f8.f64);
	// bge cr6,0x8238e400
	if (!ctx.cr6.lt) goto loc_8238E400;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// lfs f9,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// fmadds f31,f27,f0,f9
	ctx.f31.f64 = double(float(std::fma(ctx.f27.f64, ctx.f0.f64, ctx.f9.f64)));
	// bl 0x822d2870
	ctx.lr = 0x8238E3B8;
	sub_822D2870(ctx, base);
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = ctx.f1.f64;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x82755778
	ctx.lr = 0x8238E3C8;
	sub_82755778(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f9,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f13,f9,f26
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f26.f64));
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fmsubs f0,f13,f31,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f31.f64, -ctx.f0.f64)));
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
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
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f8,f0
	ctx.f8.f64 = double(float(ctx.f0.f64));
loc_8238E400:
	// lfs f0,236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f13,f30,f0
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, ctx.f0.f64)));
	// bl 0x822d2870
	ctx.lr = 0x8238E410;
	sub_822D2870(ctx, base);
	// fmuls f13,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f12,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stfs f8,52(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// stfs f31,44(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,1732(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1732);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fmadds f0,f13,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
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
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// bne cr6,0x8238e474
	if (!ctx.cr6.eq) goto loc_8238E474;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x823d3330
	ctx.lr = 0x8238E474;
	sub_823D3330(ctx, base);
loc_8238E474:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8275770c
	ctx.lr = 0x8238E480;
	__restfpr_26(ctx, base);
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

DEFINE_REX_FUNC(sub_823961A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x823961A8;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x827576c0
	ctx.lr = 0x823961B0;
	__savefpr_26(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82757b0c
	ctx.lr = 0x823961B8;
	__savevmx_123(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f26,f2
	ctx.f26.f64 = ctx.f2.f64;
	// addi r29,r11,12484
	ctx.r29.s64 = ctx.r11.s64 + 12484;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// lis r26,-32110
	ctx.r26.s64 = -2104360960;
	// lfs f31,-232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82396298
	if (ctx.cr6.eq) goto loc_82396298;
	// lwz r11,-9800(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -9800);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82396200
	if (ctx.cr6.eq) goto loc_82396200;
	// lfs f30,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f30.f64 = double(temp.f32);
	// b 0x82396204
	goto loc_82396204;
loc_82396200:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f31.f64;
loc_82396204:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x826166d8
	ctx.lr = 0x8239620C;
	sub_826166D8(ctx, base);
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwa r11,84(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,1736(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1736);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f30,f13
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82396248
	if (!ctx.cr6.gt) goto loc_82396248;
	// rlwimi r10,r28,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// b 0x8239624c
	goto loc_8239624C;
loc_82396248:
	// rlwinm r10,r10,0,13,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFE7FFFF;
loc_8239624C:
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r28,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r28,24,7,8
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 24) & 0x1800000) | (ctx.r10.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwimi r10,r28,11,19,21
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 11) & 0x1C00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwimi r10,r28,14,16,18
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 14) & 0xE000) | (ctx.r10.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82616180
	ctx.lr = 0x82396298;
	sub_82616180(ctx, base);
loc_82396298:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x826151c0
	ctx.lr = 0x823962A4;
	sub_826151C0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823962cc
	if (ctx.cr0.eq) goto loc_823962CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82615010
	ctx.lr = 0x823962B4;
	sub_82615010(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82615080
	ctx.lr = 0x823962C8;
	sub_82615080(ctx, base);
	// b 0x823962d0
	goto loc_823962D0;
loc_823962CC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823962D0:
	// lhz r11,10(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 10);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lhz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f11,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// lfs f29,1908(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f13,f12,f29
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f29.f64));
	// stfs f13,84(r1)
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
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v62,v60,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lhz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fadds f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,12(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// stw r8,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r9,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r9.u32);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r9,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r9.u32);
	// addi r9,r11,-12
	ctx.r9.s64 = ctx.r11.s64 + -12;
	// lhz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lhz r10,10(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 10);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f11,f0,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r8,8(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r8,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r8.u32);
	// lwz r8,4(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r10,12(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stw r10,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r10.u32);
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// stw r7,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r7.u32);
	// lhz r10,10(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 10);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r7,12(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r8,8(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r8,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r8.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r6,0(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r10,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r10.u32);
	// stw r6,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r6.u32);
	// stw r7,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r7.u32);
	// lhz r8,10(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 10);
	// lhz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fdivs f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 / ctx.f13.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fdivs f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 / ctx.f0.f64));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fsubs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f0,f31,f13
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f13.f64));
	// ld r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// ld r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// std r8,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r8.u64);
	// std r7,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r7.u64);
	// std r6,152(r11)
	REX_STORE_U64(ctx.r11.u32 + 152, ctx.r6.u64);
loc_82396570:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stwu r11,40(r9)
	ea = 40 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82396570
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82396570;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vupkd3d128 v127,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v127 = vTemp;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-9800(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -9800);
	// vpermwi128 v126,v127,234
	simde_mm_store_si128((simde__m128i*)ctx.v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x15));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vpermwi128 v125,v127,186
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x45));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// vpermwi128 v124,v127,174
	simde_mm_store_si128((simde__m128i*)ctx.v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x51));
	// vpermwi128 v123,v127,171
	simde_mm_store_si128((simde__m128i*)ctx.v123.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x54));
	// stvx128 v126,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82396610
	if (ctx.cr6.eq) goto loc_82396610;
	// lfs f28,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f28.f64 = double(temp.f32);
	// b 0x82396614
	goto loc_82396614;
loc_82396610:
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f31.f64;
loc_82396614:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// fneg f3,f27
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = ctx.f27.u64 ^ 0x8000000000000000;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8228e288
	ctx.lr = 0x82396628;
	sub_8228E288(ctx, base);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// vspltw128 v62,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// vspltw128 v61,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// vspltw128 v60,v124,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xFF));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// vspltw128 v59,v123,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xFF));
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// vspltw128 v9,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// lwz r11,-12360(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12360);
	// vmulfp128 v8,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v6,v61,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v4,v60,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v5,v124,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xAA));
	// vmulfp128 v2,v59,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v3,v123,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xAA));
	// vspltw128 v1,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// lvx128 v11,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// vspltw128 v31,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// lwz r11,-12372(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -12372);
	// vspltw128 v29,v123,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x55));
	// vspltw128 v30,v124,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x55));
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// vspltw128 v28,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// fdivs f12,f31,f28
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f31.f64 / ctx.f28.f64));
	// vspltw128 v27,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// lfs f10,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// vspltw128 v25,v123,3
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x0));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// vmaddfp v9,v9,v12,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// fcfid f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(ctx.f0.s64);
	// vmaddfp v8,v7,v12,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vmaddfp v7,v5,v12,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// fcfid f13,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(ctx.f13.s64);
	// vmaddfp v12,v3,v12,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// lvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v1,v11,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// frsp f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// vspltw128 v26,v124,3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x0));
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vpermwi128 v63,v127,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x15));
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vpermwi128 v0,v127,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x45));
	// vpermwi128 v13,v127,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x51));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// vmaddfp v8,v31,v11,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v7,v30,v11,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// fmuls f0,f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// vmaddfp v12,v29,v11,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v28,v10,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// fmuls f13,f13,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f0,f0,f29,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, -ctx.f10.f64)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vmaddfp v9,v27,v10,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v8,v26,v10,v7
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v26.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v25,v10,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v25.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v62,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// fnmsubs f0,f13,f29,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f29.f64, -ctx.f11.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vor128 v61,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vmulfp128 v9,v58,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v60,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vor128 v59,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vspltw128 v12,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v56,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vmulfp128 v11,v57,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v10,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v3,v56,v63
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v2,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmulfp128 v5,v58,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v4,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xAA));
	// vmaddfp v29,v12,v0,v9
	simde_mm_store_ps(ctx.v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v1,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// vspltw128 v9,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x55));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vspltw128 v6,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// vspltw128 v7,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vmaddfp v30,v10,v0,v11
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v10,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v3,v2,v0,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v11,v59,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x0));
	// vmaddfp v0,v4,v0,v5
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v31,v31,v13,v29
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v1,v1,v13,v30
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v8,v8,v13,v3
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v0,v9,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v6,v6,v12,v31
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v7,v7,v12,v1
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v13,v10,v12,v8
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v0,v11,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827567d0
	ctx.lr = 0x823967F8;
	sub_827567D0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r10,2968
	ctx.r3.s64 = ctx.r10.s64 + 2968;
	// lwz r11,-12436(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12436);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82396814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x824732e0
	ctx.lr = 0x82396818;
	sub_824732E0(ctx, base);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stw r30,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r30.u32);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// stb r28,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r28.u8);
	// stfs f26,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,6988(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 6988);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x82472dc8
	ctx.lr = 0x8239685C;
	sub_82472DC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82757da4
	ctx.lr = 0x8239686C;
	__restvmx_123(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8275770c
	ctx.lr = 0x82396874;
	__restfpr_26(ctx, base);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D9810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// lfs f0,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// bne cr6,0x823d9840
	if (!ctx.cr6.eq) goto loc_823D9840;
	// addi r10,r10,12484
	ctx.r10.s64 = ctx.r10.s64 + 12484;
	// lfs f13,-232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// b 0x823d9844
	goto loc_823D9844;
loc_823D9840:
	// lfs f13,12484(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
loc_823D9844:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bne cr6,0x823d9850
	if (!ctx.cr6.eq) goto loc_823D9850;
	// li r11,0
	ctx.r11.s64 = 0;
loc_823D9850:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr
	if (ctx.cr0.eq) return;
	// b 0x823d9968
	sub_823D9968(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823DB268) {
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
	// lwz r10,992(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 992);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,153(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823db390
	if (!ctx.cr0.eq) goto loc_823DB390;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,968(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,988(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 988);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,968(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 968, temp.u32);
	// lfs f13,-15280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15280);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823db390
	if (ctx.cr6.lt) goto loc_823DB390;
	// lbz r11,972(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 972);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,968(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 968, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823db304
	if (ctx.cr0.eq) goto loc_823DB304;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x823db304
	if (!ctx.cr6.lt) goto loc_823DB304;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,973(r3)
	REX_STORE_U8(ctx.r3.u32 + 973, ctx.r11.u8);
	// stb r11,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r11.u8);
	// lwz r11,980(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 980);
	// lwz r10,992(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 992);
	// lwz r9,976(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 976);
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// subfe r9,r8,r9
	temp.u8 = (~ctx.r8.u32 + ctx.r9.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
	// b 0x823db37c
	goto loc_823DB37C;
loc_823DB304:
	// lwz r11,964(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 964);
	// lwz r10,976(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 976);
	// mulli r11,r11,120
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(120));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// rlwinm. r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r3,116(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r10,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// bne 0x823db33c
	if (!ctx.cr0.eq) goto loc_823DB33C;
	// addi r11,r11,12252
	ctx.r11.s64 = ctx.r11.s64 + 12252;
	// lfs f0,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823db340
	goto loc_823DB340;
loc_823DB33C:
	// lfs f0,12252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f0.f64 = double(temp.f32);
loc_823DB340:
	// stfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823d8e40
	ctx.lr = 0x823DB34C;
	sub_823D8E40(ctx, base);
	// lwz r4,976(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 976);
	// lwz r3,112(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// bl 0x823d8cf0
	ctx.lr = 0x823DB358;
	sub_823D8CF0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,116(r30)
	REX_STORE_U8(ctx.r30.u32 + 116, ctx.r11.u8);
	// lwz r11,964(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 964);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,964(r31)
	REX_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x823db37c
	if (ctx.cr6.lt) goto loc_823DB37C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,964(r31)
	REX_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
loc_823DB37C:
	// lbz r11,984(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 984);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823db390
	if (ctx.cr0.eq) goto loc_823DB390;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823dc270
	ctx.lr = 0x823DB390;
	sub_823DC270(ctx, base);
loc_823DB390:
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

DEFINE_REX_FUNC(sub_823E3850) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x823E3858;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r24,r6,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpw cr6,r24,r7
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x823e38ec
	if (ctx.cr6.gt) goto loc_823E38EC;
	// rlwinm r25,r6,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_823E3884:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// add r6,r25,r3
	ctx.r6.u64 = ctx.r25.u64 + ctx.r3.u64;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// add r28,r25,r6
	ctx.r28.u64 = ctx.r25.u64 + ctx.r6.u64;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823e3ed0
	ctx.lr = 0x823E38C0;
	sub_823E3ED0(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// beq cr6,0x823e38dc
	if (ctx.cr6.eq) goto loc_823E38DC;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x825fc588
	ctx.lr = 0x823E38DC;
	sub_825FC588(ctx, base);
loc_823E38DC:
	// subf r29,r24,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// cmpw cr6,r29,r24
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x823e3884
	if (!ctx.cr6.lt) goto loc_823E3884;
loc_823E38EC:
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// bgt cr6,0x823e3924
	if (ctx.cr6.gt) goto loc_823E3924;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bl 0x823e3268
	ctx.lr = 0x823E3920;
	sub_823E3268(ctx, base);
	// b 0x823e394c
	goto loc_823E394C;
loc_823E3924:
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// add r6,r11,r3
	ctx.r6.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823e3ed0
	ctx.lr = 0x823E394C;
	sub_823E3ED0(ctx, base);
loc_823E394C:
	// lwz r3,144(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823e395c
	if (ctx.cr6.eq) goto loc_823E395C;
	// bl 0x825fc588
	ctx.lr = 0x823E395C;
	sub_825FC588(ctx, base);
loc_823E395C:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823e396c
	if (ctx.cr6.eq) goto loc_823E396C;
	// bl 0x825fc588
	ctx.lr = 0x823E396C;
	sub_825FC588(ctx, base);
loc_823E396C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EBE60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823EBE68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,512(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 512);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823ebe84
	if (ctx.cr6.eq) goto loc_823EBE84;
	// bl 0x823e8470
	ctx.lr = 0x823EBE84;
	sub_823E8470(ctx, base);
loc_823EBE84:
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r28,512(r31)
	REX_STORE_U32(ctx.r31.u32 + 512, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,22392
	ctx.r29.s64 = ctx.r11.s64 + 22392;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823EBEA4;
	sub_825FC4B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x823ebedc
	if (ctx.cr0.eq) goto loc_823EBEDC;
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823EBEC0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823ebed0
	if (ctx.cr0.eq) goto loc_823EBED0;
	// bl 0x823de348
	ctx.lr = 0x823EBECC;
	sub_823DE348(ctx, base);
	// b 0x823ebed4
	goto loc_823EBED4;
loc_823EBED0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_823EBED4:
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// b 0x823ebee0
	goto loc_823EBEE0;
loc_823EBEDC:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_823EBEE0:
	// stw r30,512(r31)
	REX_STORE_U32(ctx.r31.u32 + 512, ctx.r30.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,468(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 468);
	// bl 0x82459238
	ctx.lr = 0x823EBEF0;
	sub_82459238(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823c9b70
	ctx.lr = 0x823EBEFC;
	sub_823C9B70(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x823ebf0c
	if (!ctx.cr6.lt) goto loc_823EBF0C;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_823EBF0C:
	// lwz r9,512(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bge cr6,0x823ebf28
	if (!ctx.cr6.lt) goto loc_823EBF28;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x823ebf34
	goto loc_823EBF34;
loc_823EBF28:
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// ble cr6,0x823ebf34
	if (!ctx.cr6.gt) goto loc_823EBF34;
	// li r11,9
	ctx.r11.s64 = 9;
loc_823EBF34:
	// stw r11,36(r9)
	REX_STORE_U32(ctx.r9.u32 + 36, ctx.r11.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-31904
	ctx.r4.s64 = ctx.r9.s64 + -31904;
	// lwz r11,512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// bl 0x827551c0
	ctx.lr = 0x823EBF5C;
	sub_827551C0(ctx, base);
	// stw r30,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r30.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823c8d50
	ctx.lr = 0x823EBF68;
	sub_823C8D50(ctx, base);
	// lwz r11,512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823de440
	ctx.lr = 0x823EBF78;
	sub_823DE440(ctx, base);
	// lwz r10,512(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// ori r11,r11,287
	ctx.r11.u64 = ctx.r11.u64 | 287;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F3478) {
	REX_FUNC_PROLOGUE();
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r10,205(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 205);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr
	if (ctx.cr0.eq) return;
	// lwz r4,196(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823da700
	sub_823DA700(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F4C50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x823F4C58;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x823d9de8
	ctx.lr = 0x823F4C7C;
	sub_823D9DE8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,-31516
	ctx.r10.s64 = ctx.r11.s64 + -31516;
	// stw r30,156(r28)
	REX_STORE_U32(ctx.r28.u32 + 156, ctx.r30.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r25,r11,22392
	ctx.r25.s64 = ctx.r11.s64 + 22392;
	// li r4,484
	ctx.r4.s64 = 484;
	// lwz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823F4CA8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f4d30
	if (ctx.cr0.eq) goto loc_823F4D30;
	// li r11,74
	ctx.r11.s64 = 74;
	// stw r28,480(r3)
	REX_STORE_U32(ctx.r3.u32 + 480, ctx.r28.u32);
	// stw r30,420(r3)
	REX_STORE_U32(ctx.r3.u32 + 420, ctx.r30.u32);
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// stw r30,444(r3)
	REX_STORE_U32(ctx.r3.u32 + 444, ctx.r30.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stb r30,448(r3)
	REX_STORE_U8(ctx.r3.u32 + 448, ctx.r30.u8);
	// stb r30,449(r3)
	REX_STORE_U8(ctx.r3.u32 + 449, ctx.r30.u8);
	// stb r30,450(r3)
	REX_STORE_U8(ctx.r3.u32 + 450, ctx.r30.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stb r30,451(r3)
	REX_STORE_U8(ctx.r3.u32 + 451, ctx.r30.u8);
	// stw r30,452(r3)
	REX_STORE_U32(ctx.r3.u32 + 452, ctx.r30.u32);
	// stw r30,456(r3)
	REX_STORE_U32(ctx.r3.u32 + 456, ctx.r30.u32);
	// stw r30,460(r3)
	REX_STORE_U32(ctx.r3.u32 + 460, ctx.r30.u32);
loc_823F4CE8:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823f4ce8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F4CE8;
	// stw r30,296(r3)
	REX_STORE_U32(ctx.r3.u32 + 296, ctx.r30.u32);
	// addi r11,r3,296
	ctx.r11.s64 = ctx.r3.s64 + 296;
	// stw r30,300(r3)
	REX_STORE_U32(ctx.r3.u32 + 300, ctx.r30.u32);
	// addi r11,r3,360
	ctx.r11.s64 = ctx.r3.s64 + 360;
	// li r10,2
	ctx.r10.s64 = 2;
loc_823F4D04:
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823F4D0C:
	// stw r30,-56(r11)
	REX_STORE_U32(ctx.r11.u32 + -56, ctx.r30.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x823f4d0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F4D0C;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x823f4d04
	if (!ctx.cr0.eq) goto loc_823F4D04;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,416(r3)
	REX_STORE_U32(ctx.r3.u32 + 416, ctx.r30.u32);
	// b 0x823f4d34
	goto loc_823F4D34;
loc_823F4D30:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_823F4D34:
	// stw r11,156(r28)
	REX_STORE_U32(ctx.r28.u32 + 156, ctx.r11.u32);
	// stw r31,420(r11)
	REX_STORE_U32(ctx.r11.u32 + 420, ctx.r31.u32);
	// lwz r31,156(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// lwz r3,420(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// bl 0x82470c18
	ctx.lr = 0x823F4D48;
	sub_82470C18(ctx, base);
	// bl 0x82619bf0
	ctx.lr = 0x823F4D4C;
	sub_82619BF0(ctx, base);
	// stw r3,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f5d78
	ctx.lr = 0x823F4D58;
	sub_823F5D78(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r26,r31,292
	ctx.r26.s64 = ctx.r31.s64 + 292;
	// addi r29,r11,8472
	ctx.r29.s64 = ctx.r11.s64 + 8472;
	// li r27,2
	ctx.r27.s64 = 2;
loc_823F4D68:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825fc4b0
	ctx.lr = 0x823F4D78;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f4d8c
	if (ctx.cr0.eq) goto loc_823F4D8C;
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x823d2280
	ctx.lr = 0x823F4D88;
	sub_823D2280(ctx, base);
	// b 0x823f4d90
	goto loc_823F4D90;
loc_823F4D8C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_823F4D90:
	// li r11,10
	ctx.r11.s64 = 10;
	// stwu r3,4(r26)
	ea = 4 + ctx.r26.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r26.u32 = ea;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r11,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x823f4d68
	if (!ctx.cr0.eq) goto loc_823F4D68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f5f58
	ctx.lr = 0x823F4DB0;
	sub_823F5F58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f6160
	ctx.lr = 0x823F4DB8;
	sub_823F6160(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823F4DC8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f4dd8
	if (ctx.cr0.eq) goto loc_823F4DD8;
	// bl 0x823dc9a0
	ctx.lr = 0x823F4DD4;
	sub_823DC9A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_823F4DD8:
	// stw r30,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,420(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r4,444(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// bl 0x823f62b8
	ctx.lr = 0x823F4DF4;
	sub_823F62B8(ctx, base);
	// bl 0x82223348
	ctx.lr = 0x823F4DF8;
	sub_82223348(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r3,4132
	ctx.r11.s64 = ctx.r3.s64 + 4132;
	// addi r10,r31,460
	ctx.r10.s64 = ctx.r31.s64 + 460;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823F4E0C:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823f4e0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F4E0C;
	// lwz r31,156(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// stw r24,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r24.u32);
	// bl 0x82223348
	ctx.lr = 0x823F4E24;
	sub_82223348(ctx, base);
	// addi r11,r3,4132
	ctx.r11.s64 = ctx.r3.s64 + 4132;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r10.u32);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r11,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824032C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x824032C8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r29,156(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r11,-31340
	ctx.r11.s64 = ctx.r11.s64 + -31340;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82403364
	if (ctx.cr6.eq) goto loc_82403364;
	// addi r31,r29,96
	ctx.r31.s64 = ctx.r29.s64 + 96;
	// li r30,5
	ctx.r30.s64 = 5;
loc_824032F8:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82403308
	if (ctx.cr6.eq) goto loc_82403308;
	// bl 0x823df788
	ctx.lr = 0x82403308;
	sub_823DF788(ctx, base);
loc_82403308:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x824032f8
	if (!ctx.cr0.eq) goto loc_824032F8;
	// lwz r3,96(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 96);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82403324
	if (ctx.cr6.eq) goto loc_82403324;
	// bl 0x823e62e8
	ctx.lr = 0x82403324;
	sub_823E62E8(ctx, base);
loc_82403324:
	// addi r31,r29,-4
	ctx.r31.s64 = ctx.r29.s64 + -4;
	// stw r27,96(r29)
	REX_STORE_U32(ctx.r29.u32 + 96, ctx.r27.u32);
	// li r30,24
	ctx.r30.s64 = 24;
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
loc_82403334:
	// lwz r11,-9992(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9992);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82403350
	if (ctx.cr6.eq) goto loc_82403350;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82403350
	if (ctx.cr6.eq) goto loc_82403350;
	// bl 0x82370798
	ctx.lr = 0x82403350;
	sub_82370798(ctx, base);
loc_82403350:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x82403334
	if (!ctx.cr0.eq) goto loc_82403334;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825fc588
	ctx.lr = 0x82403364;
	sub_825FC588(ctx, base);
loc_82403364:
	// stw r27,156(r26)
	REX_STORE_U32(ctx.r26.u32 + 156, ctx.r27.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823d8988
	ctx.lr = 0x82403370;
	sub_823D8988(ctx, base);
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82403380
	if (ctx.cr0.eq) goto loc_82403380;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825fc588
	ctx.lr = 0x82403380;
	sub_825FC588(ctx, base);
loc_82403380:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824091D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824091E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,124(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82409200
	if (ctx.cr6.eq) goto loc_82409200;
	// bl 0x823dbb88
	ctx.lr = 0x82409200;
	sub_823DBB88(ctx, base);
loc_82409200:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x82409220;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82409230
	if (ctx.cr0.eq) goto loc_82409230;
	// bl 0x823ddba0
	ctx.lr = 0x8240922C;
	sub_823DDBA0(ctx, base);
	// b 0x82409234
	goto loc_82409234;
loc_82409230:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82409234:
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,84(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// stw r29,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r29.u32);
	// stb r11,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240CED8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x8240d1c8
	sub_8240D1C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240CEFC) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8240CF00) {
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
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r4,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r3,-4
	ctx.r9.s64 = ctx.r3.s64 + -4;
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stb r11,64(r3)
	REX_STORE_U8(ctx.r3.u32 + 64, ctx.r11.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stb r11,65(r3)
	REX_STORE_U8(ctx.r3.u32 + 65, ctx.r11.u8);
	// stb r11,66(r3)
	REX_STORE_U8(ctx.r3.u32 + 66, ctx.r11.u8);
loc_8240CF40:
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8240cf40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240CF40;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bl 0x82223348
	ctx.lr = 0x8240CF54;
	sub_82223348(ctx, base);
	// lwz r11,19228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// beq cr6,0x8240cf8c
	if (ctx.cr6.eq) goto loc_8240CF8C;
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// beq cr6,0x8240cf84
	if (ctx.cr6.eq) goto loc_8240CF84;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x8240cf90
	if (!ctx.cr6.eq) goto loc_8240CF90;
	// lbz r10,229(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 229);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r10,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x8240cf90
	goto loc_8240CF90;
loc_8240CF84:
	// li r30,2
	ctx.r30.s64 = 2;
	// b 0x8240cf90
	goto loc_8240CF90;
loc_8240CF8C:
	// li r30,1
	ctx.r30.s64 = 1;
loc_8240CF90:
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// lbz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x82224210
	ctx.lr = 0x8240CFB4;
	sub_82224210(ctx, base);
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

DEFINE_REX_FUNC(sub_824114C8) {
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
	// bl 0x82411520
	ctx.lr = 0x824114E8;
	sub_82411520(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82411500
	if (ctx.cr0.eq) goto loc_82411500;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82411500
	if (ctx.cr6.eq) goto loc_82411500;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82411500;
	sub_825FC588(ctx, base);
loc_82411500:
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

DEFINE_REX_FUNC(sub_82413AC0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x82413ae8
	sub_82413AE8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82414110) {
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
	// lwz r30,156(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-30824
	ctx.r11.s64 = ctx.r11.s64 + -30824;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82414150
	if (ctx.cr6.eq) goto loc_82414150;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82414780
	ctx.lr = 0x82414148;
	sub_82414780(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x82414150;
	sub_825FC588(ctx, base);
loc_82414150:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// bl 0x823d8988
	ctx.lr = 0x82414160;
	sub_823D8988(ctx, base);
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

DEFINE_REX_FUNC(sub_824169E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824169E8;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x827576c8
	ctx.lr = 0x824169F0;
	__savefpr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,7
	ctx.r10.s64 = 7;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82416A04:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x82416a04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82416A04;
	// lbz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82416b6c
	if (ctx.cr0.eq) goto loc_82416B6C;
	// addi r8,r31,28
	ctx.r8.s64 = ctx.r31.s64 + 28;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x824761f0
	ctx.lr = 0x82416A2C;
	sub_824761F0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r27,r11,12252
	ctx.r27.s64 = ctx.r11.s64 + 12252;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r30,r11,2424
	ctx.r30.s64 = ctx.r11.s64 + 2424;
	// lfs f31,236(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 236);
	ctx.f31.f64 = double(temp.f32);
	// bne 0x82416ae8
	if (!ctx.cr0.eq) goto loc_82416AE8;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x82476250
	ctx.lr = 0x82416A50;
	sub_82476250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82416ae8
	if (ctx.cr0.eq) goto loc_82416AE8;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f1,16664(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16664);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// lfs f0,-17184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3268);
	ctx.f13.f64 = double(temp.f32);
	// fadds f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f3,-18464(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18464);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x823da0c8
	ctx.lr = 0x82416A8C;
	sub_823DA0C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// lwz r8,64(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// addi r11,r11,400
	ctx.r11.s64 = ctx.r11.s64 + 400;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lfs f1,-616(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -616);
	ctx.f1.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r6,52(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r9,-1
	ctx.r9.s64 = -1;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r4,0
	ctx.r4.s64 = 0;
	// frsp f3,f0
	ctx.f3.f64 = double(float(ctx.f0.f64));
	// frsp f2,f13
	ctx.f2.f64 = double(float(ctx.f13.f64));
	// bl 0x823dad28
	ctx.lr = 0x82416AE8;
	sub_823DAD28(ctx, base);
loc_82416AE8:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f30,-620(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -620);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// addi r30,r11,-17172
	ctx.r30.s64 = ctx.r11.s64 + -17172;
	// lfs f28,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// li r4,28
	ctx.r4.s64 = 28;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// lfs f0,36(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// lfs f13,32(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f3,f0,f30
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fsubs f2,f13,f29
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f29.f64));
	// bl 0x823dae00
	ctx.lr = 0x82416B38;
	sub_823DAE00(ctx, base);
	// lfs f0,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// li r4,29
	ctx.r4.s64 = 29;
	// lwz r6,52(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// fsubs f3,f0,f30
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fsubs f2,f13,f29
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f29.f64));
	// bl 0x823dae00
	ctx.lr = 0x82416B6C;
	sub_823DAE00(ctx, base);
loc_82416B6C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x82757714
	ctx.lr = 0x82416B78;
	__restfpr_28(ctx, base);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82422C70) {
	REX_FUNC_PROLOGUE();
	// lwz r11,160(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82423500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82423508;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-1216(r1)
	ea = -1216 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r11,-14512
	ctx.r27.s64 = ctx.r11.s64 + -14512;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r11,r27
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// bl 0x823dc188
	ctx.lr = 0x82423538;
	sub_823DC188(ctx, base);
	// lis r24,-32110
	ctx.r24.s64 = -2104360960;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,-9992(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -9992);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82423554
	if (!ctx.cr6.eq) goto loc_82423554;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x82423564
	goto loc_82423564;
loc_82423554:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82370628
	ctx.lr = 0x82423564;
	sub_82370628(ctx, base);
loc_82423564:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r25,1
	ctx.r25.s64 = 1;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// li r26,255
	ctx.r26.s64 = 255;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f31,12252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,60(r10)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f31,64(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r25,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r25.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r30,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r30.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r30,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r30.u8);
	// stb r30,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r30.u8);
	// stb r30,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r30.u8);
	// stb r30,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r30.u8);
	// stb r26,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r26.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824235F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r28,r11,-15928
	ctx.r28.s64 = ctx.r11.s64 + -15928;
	// lfs f12,-15928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15928);
	ctx.f12.f64 = double(temp.f32);
	// addi r29,r10,-18576
	ctx.r29.s64 = ctx.r10.s64 + -18576;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f30,-18576(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18576);
	ctx.f30.f64 = double(temp.f32);
	// lfs f0,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28560(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -28560);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,7660(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 7660);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fadds f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f2,f0,f30
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f1,f13,f30
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// bctrl
	ctx.lr = 0x82423638;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r10,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x823dc188
	ctx.lr = 0x82423654;
	sub_823DC188(ctx, base);
	// lwz r11,-9992(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -9992);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82423668
	if (!ctx.cr6.eq) goto loc_82423668;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x82423678
	goto loc_82423678;
loc_82423668:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82370628
	ctx.lr = 0x82423678;
	sub_82370628(ctx, base);
loc_82423678:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f31,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f31,64(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r30,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r30.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r25,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r25.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r30,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// stb r26,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r26.u8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824236F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28560(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -28560);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f12,-15940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15940);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmuls f2,f0,f30
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// lfs f0,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// bctrl
	ctx.lr = 0x8242372C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,16(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,68(r9)
	REX_STORE_U32(ctx.r9.u32 + 68, ctx.r10.u32);
	// lwz r11,7044(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 7044);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8242376c
	if (ctx.cr6.eq) goto loc_8242376C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r10,-6
	ctx.r10.s64 = -6;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
loc_8242376C:
	// lis r5,11
	ctx.r5.s64 = 720896;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// ori r5,r5,5
	ctx.r5.u64 = ctx.r5.u64 | 5;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc188
	ctx.lr = 0x82423780;
	sub_823DC188(ctx, base);
	// lwz r11,-9992(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -9992);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82423794
	if (!ctx.cr6.eq) goto loc_82423794;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x824237a4
	goto loc_824237A4;
loc_82423794:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82370628
	ctx.lr = 0x824237A4;
	sub_82370628(ctx, base);
loc_824237A4:
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f31,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f31,64(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r30,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r30.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r25,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r25.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stb r30,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r30.u8);
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// stb r26,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r26.u8);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82423820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lfs f13,-28560(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -28560);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,20(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,7660(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 7660);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f12,16(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f2,f0,f30
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f1,f13,f30
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// bctrl
	ctx.lr = 0x82423854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,1216
	ctx.r1.s64 = ctx.r1.s64 + 1216;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824428D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x824428E0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82442ef0
	if (ctx.cr0.eq) goto loc_82442EF0;
	// bl 0x82223348
	ctx.lr = 0x824428FC;
	sub_82223348(ctx, base);
	// lwz r28,4(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r25,4
	ctx.r25.s64 = 4;
	// cmpwi cr6,r28,254
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 254, ctx.xer);
	// beq cr6,0x824429d8
	if (ctx.cr6.eq) goto loc_824429D8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82655e68
	ctx.lr = 0x82442914;
	sub_82655E68(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8244292c
	if (ctx.cr6.eq) goto loc_8244292C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,1245
	ctx.r11.u64 = ctx.r11.u64 | 1245;
loc_82442924:
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r25,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r25.u32);
loc_8244292C:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82442d78
	if (ctx.cr6.lt) goto loc_82442D78;
	// beq cr6,0x82442c94
	if (ctx.cr6.eq) goto loc_82442C94;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82442ae0
	if (ctx.cr6.lt) goto loc_82442AE0;
	// beq cr6,0x824429e4
	if (ctx.cr6.eq) goto loc_824429E4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82442ef0
	if (!ctx.cr6.lt) goto loc_82442EF0;
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r3,r27,16
	ctx.r3.s64 = ctx.r27.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bne cr6,0x82442964
	if (!ctx.cr6.eq) goto loc_82442964;
	// bl 0x826562d0
	ctx.lr = 0x82442964;
	sub_826562D0(ctx, base);
loc_82442964:
	// lwz r3,56(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244297c
	if (ctx.cr6.eq) goto loc_8244297C;
	// bl 0x82655cb0
	ctx.lr = 0x82442978;
	sub_82655CB0(ctx, base);
	// stw r26,56(r27)
	REX_STORE_U32(ctx.r27.u32 + 56, ctx.r26.u32);
loc_8244297C:
	// lwz r3,60(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244298c
	if (ctx.cr6.eq) goto loc_8244298C;
	// bl 0x825fc588
	ctx.lr = 0x8244298C;
	sub_825FC588(ctx, base);
loc_8244298C:
	// stw r26,60(r27)
	REX_STORE_U32(ctx.r27.u32 + 60, ctx.r26.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824429cc
	if (ctx.cr6.eq) goto loc_824429CC;
	// lwz r3,228(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824429ac
	if (ctx.cr6.eq) goto loc_824429AC;
	// bl 0x825fc588
	ctx.lr = 0x824429AC;
	sub_825FC588(ctx, base);
loc_824429AC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r26,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r26.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824429cc
	if (!ctx.cr6.gt) goto loc_824429CC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,32775
	ctx.r10.u64 = ctx.r10.u64 | 32775;
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_824429CC:
	// stb r26,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
	// stb r26,12(r27)
	REX_STORE_U8(ctx.r27.u32 + 12, ctx.r26.u8);
	// b 0x82442ef0
	goto loc_82442EF0;
loc_824429D8:
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,1253
	ctx.r11.u64 = ctx.r11.u64 | 1253;
	// b 0x82442924
	goto loc_82442924;
loc_824429E4:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r30,r27,16
	ctx.r30.s64 = ctx.r27.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82442ef0
	if (ctx.cr6.eq) goto loc_82442EF0;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826562f8
	ctx.lr = 0x82442A0C;
	sub_826562F8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82442abc
	if (!ctx.cr0.eq) goto loc_82442ABC;
	// lwz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82442ab4
	if (!ctx.cr6.gt) goto loc_82442AB4;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82442ab4
	if (ctx.cr6.eq) goto loc_82442AB4;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mulli r11,r11,48
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(48));
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r11,-32188
	ctx.r11.s64 = -2109472768;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r6,r11,10376
	ctx.r6.s64 = ctx.r11.s64 + 10376;
	// divw r5,r10,r9
	ctx.r5.u64 = uint32_t((ctx.r9.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r10.s32 / ctx.r9.s32 : 0);
	// bl 0x824447b0
	ctx.lr = 0x82442A58;
	sub_824447B0(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82442ab4
	if (!ctx.cr6.gt) goto loc_82442AB4;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
loc_82442A6C:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82442aa0
	if (ctx.cr6.eq) goto loc_82442AA0;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// ld r8,48(r27)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r27.u32 + 48);
	// cmpld cr6,r11,r8
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r8.u64, ctx.xer);
	// bne cr6,0x82442a94
	if (!ctx.cr6.eq) goto loc_82442A94;
	// stw r10,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r10.u32);
loc_82442A94:
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
loc_82442AA0:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82442a6c
	if (ctx.cr6.lt) goto loc_82442A6C;
loc_82442AB4:
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// b 0x82442eec
	goto loc_82442EEC;
loc_82442ABC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82656390
	ctx.lr = 0x82442AC4;
	sub_82656390(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82442ad8
	if (ctx.cr0.eq) goto loc_82442AD8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82656390
	ctx.lr = 0x82442AD4;
	sub_82656390(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82442AD8:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// b 0x82442eec
	goto loc_82442EEC;
loc_82442AE0:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r28,r27,16
	ctx.r28.s64 = ctx.r27.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82442ef0
	if (ctx.cr6.eq) goto loc_82442EF0;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826562f8
	ctx.lr = 0x82442B08;
	sub_826562F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82442b48
	if (ctx.cr0.eq) goto loc_82442B48;
	// cmplwi cr6,r30,18
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 18, ctx.xer);
	// beq cr6,0x82442b48
	if (ctx.cr6.eq) goto loc_82442B48;
	// cmplwi cr6,r30,1627
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1627, ctx.xer);
	// beq cr6,0x82442b48
	if (ctx.cr6.eq) goto loc_82442B48;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82656390
	ctx.lr = 0x82442B28;
	sub_82656390(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82442b3c
	if (ctx.cr0.eq) goto loc_82442B3C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82656390
	ctx.lr = 0x82442B38;
	sub_82656390(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82442B3C:
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_82442B40:
	// stw r25,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r25.u32);
	// b 0x82442c7c
	goto loc_82442C7C;
loc_82442B48:
	// ld r3,48(r27)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r27.u32 + 48);
	// bl 0x8243f3d8
	ctx.lr = 0x82442B50;
	sub_8243F3D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82442b68
	if (!ctx.cr0.eq) goto loc_82442B68;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// ld r11,48(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 48);
	// std r11,240(r31)
	REX_STORE_U64(ctx.r31.u32 + 240, ctx.r11.u64);
loc_82442B68:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82442bdc
	if (!ctx.cr6.eq) goto loc_82442BDC;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r30,60(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82442bdc
	if (ctx.cr6.eq) goto loc_82442BDC;
loc_82442B84:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82442bc8
	if (!ctx.cr0.eq) goto loc_82442BC8;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82442bc8
	if (!ctx.cr0.eq) goto loc_82442BC8;
	// ld r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// bl 0x8243f3d8
	ctx.lr = 0x82442BA0;
	sub_8243F3D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82442bc8
	if (!ctx.cr0.eq) goto loc_82442BC8;
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// addi r11,r11,30
	ctx.r11.s64 = ctx.r11.s64 + 30;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stdx r10,r11,r31
	REX_STORE_U64(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u64);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
loc_82442BC8:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,196
	ctx.r30.s64 = ctx.r30.s64 + 196;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82442b84
	if (ctx.cr6.lt) goto loc_82442B84;
loc_82442BDC:
	// std r26,0(r28)
	REX_STORE_U64(ctx.r28.u32 + 0, ctx.r26.u64);
	// addi r30,r31,72
	ctx.r30.s64 = ctx.r31.s64 + 72;
	// std r26,8(r28)
	REX_STORE_U64(ctx.r28.u32 + 8, ctx.r26.u64);
	// addi r29,r31,240
	ctx.r29.s64 = ctx.r31.s64 + 240;
	// std r26,16(r28)
	REX_STORE_U64(ctx.r28.u32 + 16, ctx.r26.u64);
	// stw r26,24(r28)
	REX_STORE_U32(ctx.r28.u32 + 24, ctx.r26.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,232(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// bl 0x82655f08
	ctx.lr = 0x82442C1C;
	sub_82655F08(ctx, base);
	// cmplwi cr6,r3,122
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 122, ctx.xer);
	// bne cr6,0x82442c6c
	if (!ctx.cr6.eq) goto loc_82442C6C;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82442C3C;
	sub_825FC4B0(ctx, base);
	// stw r3,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r3.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r4,232(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82655f08
	ctx.lr = 0x82442C64;
	sub_82655F08(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82442c74
	if (ctx.cr6.eq) goto loc_82442C74;
loc_82442C6C:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// b 0x82442b40
	goto loc_82442B40;
loc_82442C74:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
loc_82442C7C:
	// lwz r3,60(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82442c8c
	if (ctx.cr6.eq) goto loc_82442C8C;
	// bl 0x825fc588
	ctx.lr = 0x82442C8C;
	sub_825FC588(ctx, base);
loc_82442C8C:
	// stw r26,60(r27)
	REX_STORE_U32(ctx.r27.u32 + 60, ctx.r26.u32);
	// b 0x82442ef0
	goto loc_82442EF0;
loc_82442C94:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r29,r27,16
	ctx.r29.s64 = ctx.r27.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82442ef0
	if (ctx.cr6.eq) goto loc_82442EF0;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826562f8
	ctx.lr = 0x82442CBC;
	sub_826562F8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82442cf0
	if (ctx.cr0.eq) goto loc_82442CF0;
	// cmplwi cr6,r30,996
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 996, ctx.xer);
	// beq cr6,0x82442ef0
	if (ctx.cr6.eq) goto loc_82442EF0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82656390
	ctx.lr = 0x82442CD4;
	sub_82656390(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82442ce8
	if (ctx.cr0.eq) goto loc_82442CE8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82656390
	ctx.lr = 0x82442CE4;
	sub_82656390(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82442CE8:
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// b 0x82442eec
	goto loc_82442EEC;
loc_82442CF0:
	// lwz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82442ab4
	if (!ctx.cr6.gt) goto loc_82442AB4;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82442d18
	if (ctx.cr6.eq) goto loc_82442D18;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
loc_82442D18:
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82442ab4
	if (!ctx.cr6.eq) goto loc_82442AB4;
	// ld r3,48(r27)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r27.u32 + 48);
	// bl 0x8243f3d8
	ctx.lr = 0x82442D2C;
	sub_8243F3D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82442ab4
	if (!ctx.cr0.eq) goto loc_82442AB4;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82442ab4
	if (!ctx.cr6.gt) goto loc_82442AB4;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
loc_82442D48:
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// ld r8,48(r27)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r27.u32 + 48);
	// ldx r9,r9,r10
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r10.u32);
	// cmpld cr6,r9,r8
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r8.u64, ctx.xer);
	// bne cr6,0x82442d60
	if (!ctx.cr6.eq) goto loc_82442D60;
	// stw r11,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
loc_82442D60:
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82442d48
	if (ctx.cr6.lt) goto loc_82442D48;
	// b 0x82442ab4
	goto loc_82442AB4;
loc_82442D78:
	// addi r29,r27,48
	ctx.r29.s64 = ctx.r27.s64 + 48;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x826560b8
	ctx.lr = 0x82442D88;
	sub_826560B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82442ee8
	if (!ctx.cr0.eq) goto loc_82442EE8;
	// lwz r30,208(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82442db8
	if (!ctx.cr6.eq) goto loc_82442DB8;
	// ld r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// bl 0x8243f3d8
	ctx.lr = 0x82442DA4;
	sub_8243F3D8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 & ctx.r30.u64;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
loc_82442DB8:
	// blt cr6,0x82442e78
	if (ctx.cr6.lt) goto loc_82442E78;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// beq cr6,0x82442e54
	if (ctx.cr6.eq) goto loc_82442E54;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// bge cr6,0x82442ea0
	if (!ctx.cr6.lt) goto loc_82442EA0;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r30,r27,56
	ctx.r30.s64 = ctx.r27.s64 + 56;
	// stw r26,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r26.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827511e0
	ctx.lr = 0x82442DF0;
	sub_827511E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82442ee8
	if (!ctx.cr0.eq) goto loc_82442EE8;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82442E10;
	sub_825FC4B0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r7,r27,16
	ctx.r7.s64 = ctx.r27.s64 + 16;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,60(r27)
	REX_STORE_U32(ctx.r27.u32 + 60, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x82656cf0
	ctx.lr = 0x82442E30;
	sub_82656CF0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82442e4c
	if (ctx.cr6.eq) goto loc_82442E4C;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82655cb0
	ctx.lr = 0x82442E44;
	sub_82655CB0(ctx, base);
	// stw r26,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
	// b 0x82442ad8
	goto loc_82442AD8;
loc_82442E4C:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82442ee0
	goto loc_82442EE0;
loc_82442E54:
	// addi r9,r27,56
	ctx.r9.s64 = ctx.r27.s64 + 56;
	// lwz r5,216(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// addi r7,r31,72
	ctx.r7.s64 = ctx.r31.s64 + 72;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82656040
	ctx.lr = 0x82442E74;
	sub_82656040(ctx, base);
	// b 0x82442e98
	goto loc_82442E98;
loc_82442E78:
	// addi r9,r27,56
	ctx.r9.s64 = ctx.r27.s64 + 56;
	// lwz r5,216(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r4,212(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// addi r7,r31,72
	ctx.r7.s64 = ctx.r31.s64 + 72;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82655fe0
	ctx.lr = 0x82442E98;
	sub_82655FE0(ctx, base);
loc_82442E98:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82442ee8
	if (!ctx.cr6.eq) goto loc_82442EE8;
loc_82442EA0:
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82442EB8;
	sub_825FC4B0(ctx, base);
	// stw r3,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r7,r27,16
	ctx.r7.s64 = ctx.r27.s64 + 16;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,56(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// bl 0x82656cf0
	ctx.lr = 0x82442ED4;
	sub_82656CF0(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82442ee8
	if (!ctx.cr6.eq) goto loc_82442EE8;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82442EE0:
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// b 0x82442ef0
	goto loc_82442EF0;
loc_82442EE8:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_82442EEC:
	// stw r25,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r25.u32);
loc_82442EF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246D9C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x8246D9D0;
	__savegprlr_23(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r23,60
	ctx.r23.s64 = 60;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246d9f8
	if (!ctx.cr6.eq) goto loc_8246D9F8;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8246da04
	goto loc_8246DA04;
loc_8246D9F8:
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r8,r10,r23
	ctx.r8.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
loc_8246DA04:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,1092
	ctx.r10.s64 = 71565312;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// ori r10,r10,17476
	ctx.r10.u64 = ctx.r10.u64 | 17476;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x8246da6c
	if (!ctx.cr6.lt) goto loc_8246DA6C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,1648
	ctx.r4.s64 = ctx.r11.s64 + 1648;
	// bl 0x82226b70
	ctx.lr = 0x8246DA34;
	sub_82226B70(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822269f0
	ctx.lr = 0x8246DA40;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x8246DA44;
	sub_82227110(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,1704
	ctx.r11.s64 = ctx.r11.s64 + 1704;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82227048
	ctx.lr = 0x8246DA58;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8246DA68;
	sub_82371AF8(ctx, base);
	// b 0x8246dd38
	goto loc_8246DD38;
loc_8246DA6C:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8246dbcc
	if (!ctx.cr6.lt) goto loc_8246DBCC;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8246da90
	if (!ctx.cr6.lt) goto loc_8246DA90;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8246da94
	goto loc_8246DA94;
loc_8246DA90:
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_8246DA94:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8246daa0
	if (!ctx.cr6.lt) goto loc_8246DAA0;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_8246DAA0:
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// mulli r24,r11,60
	ctx.r24.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(60));
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x8246DABC;
	sub_825FC4B0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r26,r11,r23
	ctx.r26.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// mulli r25,r26,60
	ctx.r25.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(60));
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8246dae0
	if (ctx.cr0.eq) goto loc_8246DAE0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DAE0;
	sub_8246D4A8(ctx, base);
loc_8246DAE0:
	// lwz r28,4(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// b 0x8246db08
	goto loc_8246DB08;
loc_8246DAEC:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8246db00
	if (ctx.cr6.eq) goto loc_8246DB00;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DB00;
	sub_8246D4A8(ctx, base);
loc_8246DB00:
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// addi r27,r27,60
	ctx.r27.s64 = ctx.r27.s64 + 60;
loc_8246DB08:
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8246daec
	if (!ctx.cr6.eq) goto loc_8246DAEC;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r27,8(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mulli r11,r11,60
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(60));
	// add r28,r11,r29
	ctx.r28.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8246db5c
	if (ctx.cr6.eq) goto loc_8246DB5C;
	// subf r11,r25,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r25.u64;
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-60
	ctx.r30.s64 = ctx.r11.s64 + -60;
loc_8246DB38:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8246db4c
	if (ctx.cr6.eq) goto loc_8246DB4C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DB4C;
	sub_8246D4A8(ctx, base);
loc_8246DB4C:
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8246db38
	if (!ctx.cr6.eq) goto loc_8246DB38;
loc_8246DB5C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// subf r10,r11,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r10,r10,r23
	ctx.r10.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
	// addi r27,r10,1
	ctx.r27.s64 = ctx.r10.s64 + 1;
	// beq cr6,0x8246dbb0
	if (ctx.cr6.eq) goto loc_8246DBB0;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8246dba0
	if (ctx.cr6.eq) goto loc_8246DBA0;
loc_8246DB84:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r28,4
	ctx.r3.s64 = ctx.r28.s64 + 4;
	// bl 0x82371af8
	ctx.lr = 0x8246DB94;
	sub_82371AF8(ctx, base);
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8246db84
	if (!ctx.cr6.eq) goto loc_8246DB84;
loc_8246DBA0:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246dbb0
	if (ctx.cr6.eq) goto loc_8246DBB0;
	// bl 0x825fc588
	ctx.lr = 0x8246DBB0;
	sub_825FC588(ctx, base);
loc_8246DBB0:
	// mulli r11,r27,60
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(60));
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// add r10,r24,r29
	ctx.r10.u64 = ctx.r24.u64 + ctx.r29.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8246dd38
	goto loc_8246DD38;
loc_8246DBCC:
	// subf r11,r30,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8246dc90
	if (!ctx.cr6.lt) goto loc_8246DC90;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DBE8;
	sub_8246D4A8(ctx, base);
	// addi r29,r30,60
	ctx.r29.s64 = ctx.r30.s64 + 60;
	// lwz r27,8(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8246dc20
	if (ctx.cr6.eq) goto loc_8246DC20;
	// addi r28,r29,-60
	ctx.r28.s64 = ctx.r29.s64 + -60;
loc_8246DBFC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8246dc10
	if (ctx.cr6.eq) goto loc_8246DC10;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DC10;
	sub_8246D4A8(ctx, base);
loc_8246DC10:
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// addi r29,r29,60
	ctx.r29.s64 = ctx.r29.s64 + 60;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8246dbfc
	if (!ctx.cr6.eq) goto loc_8246DBFC;
loc_8246DC20:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// divw r11,r10,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
	// subfic r29,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r29.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8246dc5c
	if (ctx.cr6.eq) goto loc_8246DC5C;
loc_8246DC3C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8246dc50
	if (ctx.cr6.eq) goto loc_8246DC50;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DC50;
	sub_8246D4A8(ctx, base);
loc_8246DC50:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// bne 0x8246dc3c
	if (!ctx.cr0.eq) goto loc_8246DC3C;
loc_8246DC5C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 + 60;
	// addi r29,r11,-60
	ctx.r29.s64 = ctx.r11.s64 + -60;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8246dc80
	goto loc_8246DC80;
loc_8246DC70:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8246dd40
	ctx.lr = 0x8246DC7C;
	sub_8246DD40(ctx, base);
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
loc_8246DC80:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8246dc70
	if (!ctx.cr6.eq) goto loc_8246DC70;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// b 0x8246dd2c
	goto loc_8246DD2C;
loc_8246DC90:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DC98;
	sub_8246D4A8(ctx, base);
	// lwz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r29,r28,-60
	ctx.r29.s64 = ctx.r28.s64 + -60;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8246dcd4
	if (ctx.cr6.eq) goto loc_8246DCD4;
loc_8246DCB0:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8246dcc4
	if (ctx.cr6.eq) goto loc_8246DCC4;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8246d4a8
	ctx.lr = 0x8246DCC4;
	sub_8246D4A8(ctx, base);
loc_8246DCC4:
	// addi r26,r26,60
	ctx.r26.s64 = ctx.r26.s64 + 60;
	// addi r27,r27,60
	ctx.r27.s64 = ctx.r27.s64 + 60;
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8246dcb0
	if (!ctx.cr6.eq) goto loc_8246DCB0;
loc_8246DCD4:
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8246dd00
	if (ctx.cr6.eq) goto loc_8246DD00;
	// subf r29,r29,r28
	ctx.r29.u64 = ctx.r28.u64 - ctx.r29.u64;
loc_8246DCE8:
	// addi r31,r31,-60
	ctx.r31.s64 = ctx.r31.s64 + -60;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r31,r29
	ctx.r3.u64 = ctx.r31.u64 + ctx.r29.u64;
	// bl 0x8246dd40
	ctx.lr = 0x8246DCF8;
	sub_8246DD40(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8246dce8
	if (!ctx.cr6.eq) goto loc_8246DCE8;
loc_8246DD00:
	// addi r29,r30,60
	ctx.r29.s64 = ctx.r30.s64 + 60;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8246dd28
	if (ctx.cr6.eq) goto loc_8246DD28;
loc_8246DD10:
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246dd40
	ctx.lr = 0x8246DD1C;
	sub_8246DD40(ctx, base);
	// addi r31,r31,60
	ctx.r31.s64 = ctx.r31.s64 + 60;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8246dd10
	if (!ctx.cr6.eq) goto loc_8246DD10;
loc_8246DD28:
	// addi r3,r1,228
	ctx.r3.s64 = ctx.r1.s64 + 228;
loc_8246DD2C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82371af8
	ctx.lr = 0x8246DD38;
	sub_82371AF8(ctx, base);
loc_8246DD38:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248A8D8) {
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
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8248a980
	if (ctx.cr6.lt) goto loc_8248A980;
	// beq cr6,0x8248a978
	if (ctx.cr6.eq) goto loc_8248A978;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// blt cr6,0x8248a914
	if (ctx.cr6.lt) goto loc_8248A914;
	// beq cr6,0x8248a984
	if (ctx.cr6.eq) goto loc_8248A984;
	// cmplwi cr6,r3,5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 5, ctx.xer);
	// blt cr6,0x8248a90c
	if (ctx.cr6.lt) goto loc_8248A90C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8248a988
	goto loc_8248A988;
loc_8248A90C:
	// bl 0x82529408
	ctx.lr = 0x8248A910;
	sub_82529408(ctx, base);
	// b 0x8248a984
	goto loc_8248A984;
loc_8248A914:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8248A924;
	sub_82371AF8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r11,-6824
	ctx.r4.s64 = ctx.r11.s64 + -6824;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82484c30
	ctx.lr = 0x8248A938;
	sub_82484C30(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8248a94c
	if (!ctx.cr6.lt) goto loc_8248A94C;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_8248A94C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248a964
	if (ctx.cr6.eq) goto loc_8248A964;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x8248A964;
	sub_82486F58(ctx, base);
loc_8248A964:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8248A974;
	sub_82371AF8(ctx, base);
	// b 0x8248a984
	goto loc_8248A984;
loc_8248A978:
	// bl 0x8254a288
	ctx.lr = 0x8248A97C;
	sub_8254A288(ctx, base);
	// b 0x8248a984
	goto loc_8248A984;
loc_8248A980:
	// bl 0x8253b740
	ctx.lr = 0x8248A984;
	sub_8253B740(ctx, base);
loc_8248A984:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8248A988:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8248E760) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8248E768;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r31,408(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 408);
	// lwz r29,412(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 412);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,-24184
	ctx.r11.s64 = ctx.r11.s64 + -24184;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8248e7a8
	goto loc_8248E7A8;
loc_8248E788:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e7a4
	if (ctx.cr6.eq) goto loc_8248E7A4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8248e7a4
	if (ctx.cr6.eq) goto loc_8248E7A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82591ab8
	ctx.lr = 0x8248E7A4;
	sub_82591AB8(ctx, base);
loc_8248E7A4:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_8248E7A8:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8248e788
	if (!ctx.cr6.eq) goto loc_8248E788;
	// addi r28,r30,404
	ctx.r28.s64 = ctx.r30.s64 + 404;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82523e48
	ctx.lr = 0x8248E7BC;
	sub_82523E48(ctx, base);
	// lwz r3,384(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 384);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e7fc
	if (ctx.cr6.eq) goto loc_8248E7FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1240(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1240);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E7D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8248e7e8
	if (ctx.cr0.eq) goto loc_8248E7E8;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825c0668
	ctx.lr = 0x8248E7E8;
	sub_825C0668(ctx, base);
loc_8248E7E8:
	// lwz r3,384(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 384);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E7FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8248E7FC:
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r3,376(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 376);
	// stw r31,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r31.u32);
	// bl 0x82656530
	ctx.lr = 0x8248E80C;
	sub_82656530(ctx, base);
	// lwz r3,428(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// addi r29,r30,424
	ctx.r29.s64 = ctx.r30.s64 + 424;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e820
	if (ctx.cr6.eq) goto loc_8248E820;
	// bl 0x825fc588
	ctx.lr = 0x8248E820;
	sub_825FC588(ctx, base);
loc_8248E820:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e83c
	if (ctx.cr6.eq) goto loc_8248E83C;
	// bl 0x825fc588
	ctx.lr = 0x8248E83C;
	sub_825FC588(ctx, base);
loc_8248E83C:
	// stw r31,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// addi r29,r30,388
	ctx.r29.s64 = ctx.r30.s64 + 388;
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
	// lwz r3,392(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 392);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e85c
	if (ctx.cr6.eq) goto loc_8248E85C;
	// bl 0x825fc588
	ctx.lr = 0x8248E85C;
	sub_825FC588(ctx, base);
loc_8248E85C:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// bl 0x82483320
	ctx.lr = 0x8248E870;
	sub_82483320(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82497C10) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r6,4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,164(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// bl 0x82533088
	ctx.lr = 0x82497C3C;
	sub_82533088(ctx, base);
	// stw r3,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r6,158(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 158);
	// lwz r5,164(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// bl 0x82533878
	ctx.lr = 0x82497C54;
	sub_82533878(ctx, base);
	// stfs f1,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 272, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82533c60
	ctx.lr = 0x82497C68;
	sub_82533C60(ctx, base);
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// stfs f1,276(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 276, temp.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82497ca4
	if (!ctx.cr6.eq) goto loc_82497CA4;
	// li r4,57
	ctx.r4.s64 = 57;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824838c8
	ctx.lr = 0x82497C88;
	sub_824838C8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82497c94
	if (!ctx.cr0.eq) goto loc_82497C94;
	// stb r30,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r30.u8);
loc_82497C94:
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// b 0x82497d00
	goto loc_82497D00;
loc_82497CA4:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-26900
	ctx.r4.s64 = ctx.r11.s64 + -26900;
	// bl 0x82226b70
	ctx.lr = 0x82497CB4;
	sub_82226B70(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82497cc8
	if (!ctx.cr6.lt) goto loc_82497CC8;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
loc_82497CC8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82483918
	ctx.lr = 0x82497CD4;
	sub_82483918(ctx, base);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
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
	ctx.lr = 0x82497CF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82371af8
	ctx.lr = 0x82497D00;
	sub_82371AF8(ctx, base);
loc_82497D00:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,-9960(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -9960);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82497d3c
	if (ctx.cr6.eq) goto loc_82497D3C;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
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
	// bl 0x823c3150
	ctx.lr = 0x82497D38;
	sub_823C3150(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82497D3C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,384(r31)
	REX_STORE_U8(ctx.r31.u32 + 384, ctx.r11.u8);
	// stb r30,350(r31)
	REX_STORE_U8(ctx.r31.u32 + 350, ctx.r30.u8);
	// stb r10,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_824A50C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x824A50C8;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r23,r3,364
	ctx.r23.s64 = ctx.r3.s64 + 364;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82523e48
	ctx.lr = 0x824A50E0;
	sub_82523E48(ctx, base);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r25,1
	ctx.r25.s64 = 1;
	// lfs f31,-14512(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -14512);
	ctx.f31.f64 = double(temp.f32);
	// li r24,-1
	ctx.r24.s64 = -1;
	// lis r26,-32110
	ctx.r26.s64 = -2104360960;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// addi r28,r11,-30320
	ctx.r28.s64 = ctx.r11.s64 + -30320;
	// addi r30,r10,-30448
	ctx.r30.s64 = ctx.r10.s64 + -30448;
	// addi r27,r9,4288
	ctx.r27.s64 = ctx.r9.s64 + 4288;
	// ble cr6,0x824a52b0
	if (!ctx.cr6.gt) goto loc_824A52B0;
	// ld r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 400);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r29,-9960(r26)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r26.u32 + -9960);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r27,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r27.u32);
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stw r25,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r25.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v57,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// vsubfp128 v59,v57,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// vaddfp128 v62,v60,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// std r10,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r10.u64);
	// beq cr6,0x824a524c
	if (ctx.cr6.eq) goto loc_824A524C;
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c3150
	ctx.lr = 0x824A5248;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824A524C:
	// lfs f0,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,159(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// lfs f1,276(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// beq cr6,0x824a5294
	if (ctx.cr6.eq) goto loc_824A5294;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823c4c40
	ctx.lr = 0x824A5290;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824A5294:
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x824b96f8
	ctx.lr = 0x824A52A4;
	sub_824B96F8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,4268
	ctx.r11.s64 = ctx.r11.s64 + 4268;
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
loc_824A52B0:
	// lfs f0,420(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 420);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x824a5448
	if (!ctx.cr6.gt) goto loc_824A5448;
	// ld r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 408);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r30,-9960(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + -9960);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r27,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r27.u32);
	// lvx128 v57,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v57,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r25,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r25.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v57,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v57,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v57,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v57,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v58
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// std r11,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r11.u64);
	// beq cr6,0x824a53f0
	if (ctx.cr6.eq) goto loc_824A53F0;
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c3150
	ctx.lr = 0x824A53EC;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824A53F0:
	// lfs f0,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,159(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// lfs f1,276(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// beq cr6,0x824a5438
	if (ctx.cr6.eq) goto loc_824A5438;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823c4c40
	ctx.lr = 0x824A5434;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824A5438:
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x824b96f8
	ctx.lr = 0x824A5448;
	sub_824B96F8(ctx, base);
loc_824A5448:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824CD910) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824CD918;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,-16664
	ctx.r11.s64 = ctx.r11.s64 + -16664;
	// addi r31,r3,404
	ctx.r31.s64 = ctx.r3.s64 + 404;
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_824CD934:
	// addi r31,r31,-12
	ctx.r31.s64 = ctx.r31.s64 + -12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824f6238
	ctx.lr = 0x824CD940;
	sub_824F6238(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824cd950
	if (ctx.cr6.eq) goto loc_824CD950;
	// bl 0x825fc588
	ctx.lr = 0x824CD950;
	sub_825FC588(ctx, base);
loc_824CD950:
	// li r11,0
	ctx.r11.s64 = 0;
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bge 0x824cd934
	if (!ctx.cr0.lt) goto loc_824CD934;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82483320
	ctx.lr = 0x824CD968;
	sub_82483320(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D0CE0) {
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
	// lwz r11,376(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 376);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x824d0d38
	if (ctx.cr6.eq) goto loc_824D0D38;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x824d0d38
	if (ctx.cr6.eq) goto loc_824D0D38;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r3,380
	ctx.r3.s64 = 380;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
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
	// bl 0x82250ad8
	ctx.lr = 0x824D0D30;
	sub_82250AD8(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
loc_824D0D38:
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

DEFINE_REX_FUNC(sub_824D3168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824D3170;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r9,-30256
	ctx.r9.s64 = ctx.r9.s64 + -30256;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-9960(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// stvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,4288
	ctx.r10.s64 = ctx.r10.s64 + 4288;
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r5,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f9,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// beq cr6,0x824d32a0
	if (ctx.cr6.eq) goto loc_824D32A0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c3150
	ctx.lr = 0x824D329C;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824D32A0:
	// lfs f0,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,159(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f1,276(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// beq cr6,0x824d32e8
	if (ctx.cr6.eq) goto loc_824D32E8;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823c4c40
	ctx.lr = 0x824D32E4;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824D32E8:
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824E1748) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x824E1750;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,472(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 472);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,468(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 468);
	// addi r31,r3,464
	ctx.r31.s64 = ctx.r3.s64 + 464;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824e17cc
	if (ctx.cr0.eq) goto loc_824E17CC;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824e17cc
	if (ctx.cr0.eq) goto loc_824E17CC;
	// li r30,0
	ctx.r30.s64 = 0;
loc_824E178C:
	// lwz r11,468(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 468);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824e17a0
	if (ctx.cr6.eq) goto loc_824E17A0;
	// bl 0x825fc588
	ctx.lr = 0x824E17A0;
	sub_825FC588(ctx, base);
loc_824E17A0:
	// lwz r11,468(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 468);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwx r10,r11,r30
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824e178c
	if (ctx.cr6.lt) goto loc_824E178C;
loc_824E17CC:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x824e17fc
	if (ctx.cr6.eq) goto loc_824E17FC;
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
	// ble 0x824e17f8
	if (!ctx.cr0.gt) goto loc_824E17F8;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x824E17F8;
	sub_82755080(ctx, base);
loc_824E17F8:
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_824E17FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824ECC50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824ECC58;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r5,25
	ctx.r5.s64 = 25;
	// addi r30,r11,18812
	ctx.r30.s64 = ctx.r11.s64 + 18812;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r30,6324
	ctx.r4.s64 = ctx.r30.s64 + 6324;
	// bl 0x82483918
	ctx.lr = 0x824ECC74;
	sub_82483918(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r29,1
	ctx.r29.s64 = 1;
	// bne 0x824ecc84
	if (!ctx.cr0.eq) goto loc_824ECC84;
	// stb r29,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r29.u8);
loc_824ECC84:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r4,360(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824ECCA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r7,44(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,364(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 364, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// lwz r10,368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// lwz r9,364(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r10,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r10.u32);
	// stw r9,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r9.u32);
	// stw r9,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r9.u32);
	// stw r10,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r10.u32);
	// blt cr6,0x824ecd58
	if (ctx.cr6.lt) goto loc_824ECD58;
	// beq cr6,0x824ecd4c
	if (ctx.cr6.eq) goto loc_824ECD4C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x824ecd60
	if (!ctx.cr6.lt) goto loc_824ECD60;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f9,-11828(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11828);
	ctx.f9.f64 = double(temp.f32);
	// b 0x824ecd64
	goto loc_824ECD64;
loc_824ECD4C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f9,14892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14892);
	ctx.f9.f64 = double(temp.f32);
	// b 0x824ecd64
	goto loc_824ECD64;
loc_824ECD58:
	// lfs f9,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// b 0x824ecd64
	goto loc_824ECD64;
loc_824ECD60:
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
loc_824ECD64:
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f0,236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// bne cr6,0x824ecd8c
	if (!ctx.cr6.eq) goto loc_824ECD8C;
	// bl 0x822d2870
	ctx.lr = 0x824ECD84;
	sub_822D2870(ctx, base);
	// stfs f1,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// b 0x824ecd98
	goto loc_824ECD98;
loc_824ECD8C:
	// bl 0x822d2870
	ctx.lr = 0x824ECD90;
	sub_822D2870(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
loc_824ECD98:
	// fmr f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x822d2870
	ctx.lr = 0x824ECDA0;
	sub_822D2870(ctx, base);
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// lwz r10,356(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,-11720
	ctx.r11.s64 = ctx.r11.s64 + -11720;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824ecdcc
	if (ctx.cr6.eq) goto loc_824ECDCC;
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// stb r29,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r29.u8);
	// addi r11,r11,-11720
	ctx.r11.s64 = ctx.r11.s64 + -11720;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
loc_824ECDCC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F7EA0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,512(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 512);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr
	if (!ctx.cr0.eq) return;
	// b 0x824822b8
	sub_824822B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F8AF0) {
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
	// lbz r11,512(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 512);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824f8c60
	if (!ctx.cr0.eq) goto loc_824F8C60;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r8,44(r3)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x824f8b58
	if (ctx.cr6.gt) goto loc_824F8B58;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824F8B58:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r11,-30336
	ctx.r8.s64 = ctx.r11.s64 + -30336;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,-9960(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9960);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824f8bd8
	if (ctx.cr0.eq) goto loc_824F8BD8;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824f8c14
	if (ctx.cr6.eq) goto loc_824F8C14;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823c2720
	ctx.lr = 0x824F8BD4;
	sub_823C2720(ctx, base);
	// b 0x824f8c10
	goto loc_824F8C10;
loc_824F8BD8:
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824f8c14
	if (ctx.cr6.eq) goto loc_824F8C14;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823c2468
	ctx.lr = 0x824F8C10;
	sub_823C2468(ctx, base);
loc_824F8C10:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824F8C14:
	// mullw. r11,r11,r11
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f8c58
	if (ctx.cr0.eq) goto loc_824F8C58;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r10,-29712
	ctx.r10.s64 = ctx.r10.s64 + -29712;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
loc_824F8C58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824823a0
	ctx.lr = 0x824F8C60;
	sub_824823A0(ctx, base);
loc_824F8C60:
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

DEFINE_REX_FUNC(sub_82503238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82503240;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,380(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 380);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r28,r11,12252
	ctx.r28.s64 = ctx.r11.s64 + 12252;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8250327c
	if (ctx.cr0.eq) goto loc_8250327C;
	// lfs f0,232(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stb r27,380(r3)
	REX_STORE_U8(ctx.r3.u32 + 380, ctx.r27.u8);
loc_8250327C:
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
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
	ctx.lr = 0x82503298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lfs f13,364(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 364);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,100(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,-16128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16128);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmadds f1,f0,f31,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f1.f64)));
	// bctrl
	ctx.lr = 0x825032BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825032D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lfs f13,364(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 364);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,100(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,-16124(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16124);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmadds f1,f0,f31,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f1.f64)));
	// bctrl
	ctx.lr = 0x825032FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ba0
	ctx.lr = 0x8250330C;
	sub_82232BA0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82503384
	if (ctx.cr0.eq) goto loc_82503384;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
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
	ctx.lr = 0x82503330;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	ctx.lr = 0x82503358;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82503374;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82503384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82503384:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f11,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r11,1800
	ctx.r29.s64 = ctx.r11.s64 + 1800;
	// lfs f0,2872(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x8250344c
	if (!ctx.cr6.lt) goto loc_8250344C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,216(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// li r30,255
	ctx.r30.s64 = 255;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f12,27796(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 27796);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,408(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// fsubs f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f0,f30,f12
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f12.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lbz r11,111(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 111);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl
	ctx.lr = 0x825033FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lbz r10,111(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 111);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8250343C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// b 0x825034ac
	goto loc_825034AC;
loc_8250344C:
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x825034a4
	if (ctx.cr6.eq) goto loc_825034A4;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x82503464;
	sub_82232BA0(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825034a4
	if (ctx.cr0.eq) goto loc_825034A4;
	// stb r27,84(r11)
	REX_STORE_U8(ctx.r11.u32 + 84, ctx.r27.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r27,85(r11)
	REX_STORE_U8(ctx.r11.u32 + 85, ctx.r27.u8);
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ab0
	ctx.lr = 0x82503484;
	sub_82232AB0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8250349c
	if (ctx.cr0.eq) goto loc_8250349C;
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x822329c8
	ctx.lr = 0x8250349C;
	sub_822329C8(ctx, base);
loc_8250349C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
loc_825034A4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_825034AC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82514FA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// lfs f0,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82514fe0
	if (ctx.cr6.lt) goto loc_82514FE0;
	// addi r11,r11,17476
	ctx.r11.s64 = ctx.r11.s64 + 17476;
	// lfs f12,464(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 464);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f13,0(r5)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82515000
	if (!ctx.cr6.lt) goto loc_82515000;
	// b 0x82514ffc
	goto loc_82514FFC;
loc_82514FE0:
	// lfs f12,476(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 476);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,17476(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17476);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f13,0(r5)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82515000
	if (!ctx.cr6.gt) goto loc_82515000;
loc_82514FFC:
	// stfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
loc_82515000:
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfs f0,480(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// blt cr6,0x8251501c
	if (ctx.cr6.lt) goto loc_8251501C;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// b 0x82515028
	goto loc_82515028;
loc_8251501C:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_82515028:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82517980) {
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
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,216(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r7,-32109
	ctx.r7.s64 = -2104295424;
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,-7164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2360(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2360);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13944(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -13944);
	ctx.f12.f64 = double(temp.f32);
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
	ctx.lr = 0x825179E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,376(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 376);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82517a0c
	if (ctx.cr0.eq) goto loc_82517A0C;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
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
	ctx.lr = 0x82517A0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82517A0C:
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

DEFINE_REX_FUNC(sub_8251C170) {
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
	// addi r11,r11,-5912
	ctx.r11.s64 = ctx.r11.s64 + -5912;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82483410
	ctx.lr = 0x8251C194;
	sub_82483410(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2312
	ctx.r11.s64 = ctx.r11.s64 + -2312;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82483320
	ctx.lr = 0x8251C1A8;
	sub_82483320(ctx, base);
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

DEFINE_REX_FUNC(sub_8251DDB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x8251DDC0;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r10,-23504
	ctx.r4.s64 = ctx.r10.s64 + -23504;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x8251DDFC;
	sub_82534A18(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,-5424
	ctx.r10.s64 = ctx.r11.s64 + -5424;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,460(r31)
	REX_STORE_U32(ctx.r31.u32 + 460, ctx.r30.u32);
	// addi r28,r11,22392
	ctx.r28.s64 = ctx.r11.s64 + 22392;
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// li r4,48
	ctx.r4.s64 = 48;
	// stw r30,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r30.u32);
	// addi r29,r31,456
	ctx.r29.s64 = ctx.r31.s64 + 456;
	// stw r30,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r30.u32);
	// addi r25,r31,472
	ctx.r25.s64 = ctx.r31.s64 + 472;
	// stw r30,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r30.u32);
	// addi r21,r31,488
	ctx.r21.s64 = ctx.r31.s64 + 488;
	// stw r30,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r30.u32);
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x8251DE48;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8251de54
	if (ctx.cr0.eq) goto loc_8251DE54;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_8251DE54:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8251de60
	if (ctx.cr0.eq) goto loc_8251DE60;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_8251DE60:
	// stw r3,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r30.u32);
	// li r4,48
	ctx.r4.s64 = 48;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// addi r24,r31,500
	ctx.r24.s64 = ctx.r31.s64 + 500;
	// bl 0x825fc4b0
	ctx.lr = 0x8251DE7C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8251de88
	if (ctx.cr0.eq) goto loc_8251DE88;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_8251DE88:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8251de94
	if (ctx.cr0.eq) goto loc_8251DE94;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_8251DE94:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r3,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r3.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r30,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r30.u32);
	// addi r9,r11,12252
	ctx.r9.s64 = ctx.r11.s64 + 12252;
	// stb r22,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r22.u8);
	// addic r8,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r8.s64 = ctx.r26.s64 + -1;
	// stb r23,158(r31)
	REX_STORE_U8(ctx.r31.u32 + 158, ctx.r23.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,12252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f13.f64 = double(temp.f32);
	// subfe r11,r8,r26
	temp.u8 = (~ctx.r8.u32 + ctx.r26.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r26.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r8.u64 + ctx.r26.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lfs f12,-8904(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8904);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,516(r31)
	REX_STORE_U8(ctx.r31.u32 + 516, ctx.r11.u8);
	// stfs f12,520(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 520, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,512(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 512, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f12,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-30224
	ctx.r10.s64 = ctx.r10.s64 + -30224;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f12,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stb r30,404(r31)
	REX_STORE_U8(ctx.r31.u32 + 404, ctx.r30.u8);
	// stfs f13,400(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// stw r10,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r10.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,96
	ctx.r11.s64 = 96;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r31,532
	ctx.r11.s64 = ctx.r31.s64 + 532;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r10,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r10.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// stfs f13,524(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 524, temp.u32);
	// stw r30,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r30.u32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r30.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stw r30,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r30.u32);
	// stw r30,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r30.u32);
	// stw r30,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r30.u32);
	// stfs f0,440(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 440, temp.u32);
	// stfs f0,448(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 448, temp.u32);
	// stfs f0,444(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 444, temp.u32);
	// stfs f0,452(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 452, temp.u32);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,528(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 528, temp.u32);
	// lwz r30,8(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8251e014
	if (ctx.cr6.eq) goto loc_8251E014;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r30
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8251e010
	if (ctx.cr6.eq) goto loc_8251E010;
loc_8251DFF0:
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827567d0
	ctx.lr = 0x8251E000;
	sub_827567D0(ctx, base);
	// addi r28,r28,24
	ctx.r28.s64 = ctx.r28.s64 + 24;
	// addi r27,r27,24
	ctx.r27.s64 = ctx.r27.s64 + 24;
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8251dff0
	if (!ctx.cr6.eq) goto loc_8251DFF0;
loc_8251E010:
	// stw r27,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r27.u32);
loc_8251E014:
	// lwz r28,4(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// lwz r30,8(r25)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8251e054
	if (ctx.cr6.eq) goto loc_8251E054;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r30
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8251e050
	if (ctx.cr6.eq) goto loc_8251E050;
loc_8251E030:
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827567d0
	ctx.lr = 0x8251E040;
	sub_827567D0(ctx, base);
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// addi r28,r28,56
	ctx.r28.s64 = ctx.r28.s64 + 56;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8251e030
	if (!ctx.cr6.eq) goto loc_8251E030;
loc_8251E050:
	// stw r28,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r28.u32);
loc_8251E054:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x824f6238
	ctx.lr = 0x8251E05C;
	sub_824F6238(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x824f6238
	ctx.lr = 0x8251E064;
	sub_824F6238(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82530C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x82530C18;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82530c44
	if (!ctx.cr6.eq) goto loc_82530C44;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825313b0
	goto loc_825313B0;
loc_82530C44:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r24,1
	ctx.r24.s64 = 1;
	// stb r10,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r10.u8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r31,8(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lfs f1,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// ld r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 20);
	// bl 0x825313c0
	ctx.lr = 0x82530C6C;
	sub_825313C0(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r11,-29984
	ctx.r30.s64 = ctx.r11.s64 + -29984;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f0,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r28,r1,176
	ctx.r28.s64 = ctx.r1.s64 + 176;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r27,r11,-30096
	ctx.r27.s64 = ctx.r11.s64 + -30096;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r31,8
	ctx.r4.s64 = ctx.r31.s64 + 8;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lfs f30,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f31.f64 = double(temp.f32);
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f12,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82530D64;
	sub_824D3CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x824d3cb8
	ctx.lr = 0x82530D74;
	sub_824D3CB8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8252e2f8
	ctx.lr = 0x82530D88;
	sub_8252E2F8(ctx, base);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82530f08
	if (ctx.cr0.eq) goto loc_82530F08;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f30,172(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f30,164(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f30,160(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82531630
	ctx.lr = 0x82530E20;
	sub_82531630(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// ld r31,128(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r31,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r31.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82530E38;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-30400
	ctx.r10.s64 = ctx.r10.s64 + -30400;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// bl 0x82454930
	ctx.lr = 0x82530E64;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82530EE4;
	sub_824D3CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82340028
	ctx.lr = 0x82530EF4;
	sub_82340028(ctx, base);
	// ld r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// ld r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// b 0x8253138c
	goto loc_8253138C;
loc_82530F08:
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f0,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// addi r23,r1,160
	ctx.r23.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r28,r11,-30400
	ctx.r28.s64 = ctx.r11.s64 + -30400;
	// stfs f0,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x82340028
	ctx.lr = 0x82530FDC;
	sub_82340028(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8252e2f8
	ctx.lr = 0x82530FF0;
	sub_8252E2F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// beq 0x825311a0
	if (ctx.cr0.eq) goto loc_825311A0;
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r30,128(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r30,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r30.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82531074;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// bl 0x82454930
	ctx.lr = 0x82531098;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82531118;
	sub_824D3CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82340028
	ctx.lr = 0x82531128;
	sub_82340028(ctx, base);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// ld r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82531384
	goto loc_82531384;
loc_825311A0:
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f30,176(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f30,180(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f30,188(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,184(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x82340028
	ctx.lr = 0x82531204;
	sub_82340028(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8252e2f8
	ctx.lr = 0x82531218;
	sub_8252E2F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825313a8
	if (ctx.cr0.eq) goto loc_825313A8;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// ld r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82531630
	ctx.lr = 0x8253124C;
	sub_82531630(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// ld r31,128(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r31,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r31.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82531264;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// bl 0x82454930
	ctx.lr = 0x82531288;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmulfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82531308;
	sub_824D3CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82340028
	ctx.lr = 0x82531318;
	sub_82340028(ctx, base);
	// stfs f30,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f30,184(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f30,180(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ld r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f30,176(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vxor128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
loc_82531384:
	// stfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
loc_8253138C:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82531a60
	ctx.lr = 0x82531394;
	sub_82531A60(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// b 0x825313ac
	goto loc_825313AC;
loc_825313A8:
	// li r24,0
	ctx.r24.s64 = 0;
loc_825313AC:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_825313B0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257B3F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x8257B400;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
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
	// li r31,0
	ctx.r31.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// stb r31,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r31.u8);
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// stb r31,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r31.u8);
	// lfs f0,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r9,164(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 164);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r26,16384
	ctx.r26.s64 = 1073741824;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r30,4(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r24,8(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-9744(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -9744);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ori r26,r26,8
	ctx.r26.u64 = ctx.r26.u64 | 8;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8257b50c
	if (!ctx.cr6.eq) goto loc_8257B50C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8257b50c
	if (ctx.cr6.eq) goto loc_8257B50C;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257b50c
	if (ctx.cr0.eq) goto loc_8257B50C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82448730
	ctx.lr = 0x8257B4D0;
	sub_82448730(ctx, base);
	// lwz r11,-9960(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9960);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257b508
	if (ctx.cr6.eq) goto loc_8257B508;
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
	// bl 0x823c3150
	ctx.lr = 0x8257B508;
	sub_823C3150(ctx, base);
loc_8257B508:
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8257B50C:
	// bl 0x82223348
	ctx.lr = 0x8257B510;
	sub_82223348(ctx, base);
	// lwz r11,4024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4024);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8257b524
	if (!ctx.cr6.eq) goto loc_8257B524;
	// lis r26,16384
	ctx.r26.s64 = 1073741824;
	// ori r26,r26,10
	ctx.r26.u64 = ctx.r26.u64 | 10;
loc_8257B524:
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8257b6d0
	if (ctx.cr6.eq) goto loc_8257B6D0;
	// lis r25,16384
	ctx.r25.s64 = 1073741824;
loc_8257B530:
	// bl 0x82223348
	ctx.lr = 0x8257B534;
	sub_82223348(ctx, base);
	// lwz r11,4024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4024);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8257b558
	if (ctx.cr6.eq) goto loc_8257B558;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,0,0,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x8257b558
	if (!ctx.cr6.eq) goto loc_8257B558;
	// rlwinm r11,r26,0,29,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// ori r26,r11,2
	ctx.r26.u64 = ctx.r11.u64 | 2;
loc_8257B558:
	// lwz r3,-9960(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -9960);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// stb r31,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r31.u8);
	// stb r31,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r31.u8);
	// beq cr6,0x8257b63c
	if (ctx.cr6.eq) goto loc_8257B63C;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8257b594
	if (!ctx.cr6.eq) goto loc_8257B594;
loc_8257B58C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// b 0x8257b624
	goto loc_8257B624;
loc_8257B594:
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r7,r11,12,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x3FC;
	// rlwinm. r9,r11,0,0,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r11,10
	ctx.r10.u64 = ctx.r11.u32 & 0x3FFFFF;
	// lwzx r11,r7,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// beq 0x8257b600
	if (ctx.cr0.eq) goto loc_8257B600;
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x8257b5e0
	if (ctx.cr6.eq) goto loc_8257B5E0;
	// lis r8,-32768
	ctx.r8.s64 = -2147483648;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8257b58c
	if (!ctx.cr6.eq) goto loc_8257B58C;
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8257b58c
	if (!ctx.cr6.lt) goto loc_8257B58C;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// b 0x8257b61c
	goto loc_8257B61C;
loc_8257B5E0:
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r8,52(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8257b58c
	if (!ctx.cr6.lt) goto loc_8257B58C;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// b 0x8257b61c
	goto loc_8257B61C;
loc_8257B600:
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lwz r8,68(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8257b58c
	if (!ctx.cr6.lt) goto loc_8257B58C;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
loc_8257B61C:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_8257B624:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x823c5098
	ctx.lr = 0x8257B634;
	sub_823C5098(ctx, base);
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_8257B63C:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257b6c4
	if (ctx.cr0.eq) goto loc_8257B6C4;
	// lwz r11,-9744(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -9744);
	// lwz r3,16(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8257b6c4
	if (!ctx.cr6.eq) goto loc_8257B6C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8257b6c4
	if (ctx.cr6.eq) goto loc_8257B6C4;
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r8,r11,31,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8257b6b4
	if (!ctx.cr0.eq) goto loc_8257B6B4;
	// rlwinm. r8,r11,30,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8257b6b4
	if (!ctx.cr0.eq) goto loc_8257B6B4;
	// rlwinm. r8,r11,26,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8257b6b4
	if (!ctx.cr0.eq) goto loc_8257B6B4;
	// rlwinm. r8,r11,0,27,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8257b69c
	if (!ctx.cr0.eq) goto loc_8257B69C;
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257b6c4
	if (ctx.cr0.eq) goto loc_8257B6C4;
loc_8257B69C:
	// lbz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 8);
	// clrlwi r9,r27,24
	ctx.r9.u64 = ctx.r27.u32 & 0xFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8257b6c4
	if (!ctx.cr6.eq) goto loc_8257B6C4;
	// lwz r3,164(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 164);
	// b 0x8257b6d4
	goto loc_8257B6D4;
loc_8257B6B4:
	// lbz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 8);
	// clrlwi r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8257b6d4
	if (ctx.cr6.eq) goto loc_8257B6D4;
loc_8257B6C4:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x8257b530
	if (!ctx.cr6.eq) goto loc_8257B530;
loc_8257B6D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8257B6D4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82590680) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82590688;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32109
	ctx.r26.s64 = -2104295424;
	// li r30,-1
	ctx.r30.s64 = -1;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2832(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2832);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// bl 0x82657aa8
	ctx.lr = 0x825906AC;
	sub_82657AA8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,-15328
	ctx.r11.s64 = ctx.r11.s64 + -15328;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_825906C4:
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r7,-1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -1, ctx.xer);
	// beq cr6,0x82590704
	if (ctx.cr6.eq) goto loc_82590704;
	// addi r9,r9,28
	ctx.r9.s64 = ctx.r9.s64 + 28;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,28
	ctx.r8.s64 = ctx.r8.s64 + 28;
	// cmplwi cr6,r9,1792
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1792, ctx.xer);
	// blt cr6,0x825906c4
	if (ctx.cr6.lt) goto loc_825906C4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_825906E8:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82590710
	if (!ctx.cr6.eq) goto loc_82590710;
	// lwz r3,2832(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2832);
	// bl 0x82657ab0
	ctx.lr = 0x825906F8;
	sub_82657AB0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_825906FC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
loc_82590704:
	// mulli r10,r10,28
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(28));
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x825906e8
	goto loc_825906E8;
loc_82590710:
	// bl 0x825908d0
	ctx.lr = 0x82590714;
	sub_825908D0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8259072c
	if (!ctx.cr0.eq) goto loc_8259072C;
loc_8259071C:
	// lwz r3,2832(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2832);
	// bl 0x82657ab0
	ctx.lr = 0x82590724;
	sub_82657AB0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x825906fc
	goto loc_825906FC;
loc_8259072C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r8,r10,61439
	ctx.r8.u64 = ctx.r10.u64 | 61439;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r8,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// stw r28,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r28.u32);
	// stw r27,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r27.u32);
	// stw r29,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r29.u32);
	// stw r29,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r29.u32);
	// stb r11,20(r4)
	REX_STORE_U8(ctx.r4.u32 + 20, ctx.r11.u8);
	// stw r30,24(r4)
	REX_STORE_U32(ctx.r4.u32 + 24, ctx.r30.u32);
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
loc_8259076C:
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stbx r8,r10,r9
	REX_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne 0x8259076c
	if (!ctx.cr0.eq) goto loc_8259076C;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// b 0x8259071c
	goto loc_8259071C;
}

DEFINE_REX_FUNC(sub_825960B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x825960C0;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32110
	ctx.r24.s64 = -2104360960;
	// li r11,44
	ctx.r11.s64 = 44;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// li r21,0
	ctx.r21.s64 = 0;
	// lwz r29,-9784(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + -9784);
	// lwz r10,252(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 252);
	// lwz r9,248(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 248);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825961bc
	if (ctx.cr0.eq) goto loc_825961BC;
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// lwz r31,-9772(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + -9772);
	// addi r26,r10,6124
	ctx.r26.s64 = ctx.r10.s64 + 6124;
	// addi r25,r11,6108
	ctx.r25.s64 = ctx.r11.s64 + 6108;
loc_8259610C:
	// lwz r11,248(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 248);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// add r30,r11,r27
	ctx.r30.u64 = ctx.r11.u64 + ctx.r27.u64;
	// beq cr6,0x82596130
	if (ctx.cr6.eq) goto loc_82596130;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8259b9c0
	ctx.lr = 0x82596128;
	sub_8259B9C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82596134
	goto loc_82596134;
loc_82596130:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
loc_82596134:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825961b0
	if (ctx.cr6.eq) goto loc_825961B0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82249098
	ctx.lr = 0x82596144;
	sub_82249098(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822492f8
	ctx.lr = 0x82596154;
	sub_822492F8(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822495b8
	ctx.lr = 0x82596168;
	sub_822495B8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822492f8
	ctx.lr = 0x82596178;
	sub_822492F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8259618c
	if (!ctx.cr6.lt) goto loc_8259618C;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_8259618C:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826565f0
	ctx.lr = 0x82596194;
	sub_826565F0(ctx, base);
	// stw r3,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x825961A8;
	sub_82371AF8(ctx, base);
	// lwz r29,-9784(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + -9784);
	// lwz r31,-9772(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + -9772);
loc_825961B0:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r27,r27,44
	ctx.r27.s64 = ctx.r27.s64 + 44;
	// bne 0x8259610c
	if (!ctx.cr0.eq) goto loc_8259610C;
loc_825961BC:
	// stb r21,240(r29)
	REX_STORE_U8(ctx.r29.u32 + 240, ctx.r21.u8);
	// addi r9,r22,4
	ctx.r9.s64 = ctx.r22.s64 + 4;
loc_825961C4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r21,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825961c4
	if (!ctx.cr0.eq) goto loc_825961C4;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x825961fc
	if (ctx.cr6.eq) goto loc_825961FC;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825961FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825961FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259ECA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8259ECA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,23
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 23, ctx.xer);
	// bgt cr6,0x8259eea8
	if (ctx.cr6.gt) goto loc_8259EEA8;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-4552
	ctx.r12.s64 = ctx.r12.s64 + -4552;
	// lbzx r0,r12,r3
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r3.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32166
	ctx.r12.s64 = -2108030976;
	// nop
	// addi r12,r12,-4896
	ctx.r12.s64 = ctx.r12.s64 + -4896;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r3.u32) {
	case 0:
		goto loc_8259ECE0;
	case 1:
		goto loc_8259ECF0;
	case 2:
		goto loc_8259ECF8;
	case 3:
		goto loc_8259ED00;
	case 4:
		goto loc_8259ED08;
	case 5:
		goto loc_8259ED10;
	case 6:
		goto loc_8259ED18;
	case 7:
		goto loc_8259ED20;
	case 8:
		goto loc_8259ED28;
	case 9:
		goto loc_8259ED30;
	case 10:
		goto loc_8259ED38;
	case 11:
		goto loc_8259ED40;
	case 12:
		goto loc_8259ED48;
	case 13:
		goto loc_8259ED50;
	case 14:
		goto loc_8259ED58;
	case 15:
		goto loc_8259EDC8;
	case 16:
		goto loc_8259EE00;
	case 17:
		goto loc_8259EE28;
	case 18:
		goto loc_8259EE50;
	case 19:
		goto loc_8259EEA8;
	case 20:
		goto loc_8259EEA8;
	case 21:
		goto loc_8259EEA8;
	case 22:
		goto loc_8259EEA8;
	case 23:
		goto loc_8259EEA8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8259ECE0:
	// li r3,13
	ctx.r3.s64 = 13;
loc_8259ECE4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82445228
	ctx.lr = 0x8259ECEC;
	sub_82445228(ctx, base);
	// b 0x8259eeac
	goto loc_8259EEAC;
loc_8259ECF0:
	// li r3,14
	ctx.r3.s64 = 14;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ECF8:
	// li r3,15
	ctx.r3.s64 = 15;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED00:
	// li r3,16
	ctx.r3.s64 = 16;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED08:
	// li r3,9
	ctx.r3.s64 = 9;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED10:
	// li r3,10
	ctx.r3.s64 = 10;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED18:
	// li r3,7
	ctx.r3.s64 = 7;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED20:
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED28:
	// li r3,5
	ctx.r3.s64 = 5;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED30:
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED38:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED40:
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED48:
	// li r3,3
	ctx.r3.s64 = 3;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED50:
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x8259ece4
	goto loc_8259ECE4;
loc_8259ED58:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82445228
	ctx.lr = 0x8259ED64;
	sub_82445228(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82445228
	ctx.lr = 0x8259ED74;
	sub_82445228(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,3
	ctx.r3.s64 = 3;
loc_8259ED7C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x824451b0
	ctx.lr = 0x8259ED84;
	sub_824451B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8259ED8C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x824451b0
	ctx.lr = 0x8259ED94;
	sub_824451B0(ctx, base);
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259edbc
	if (ctx.cr0.eq) goto loc_8259EDBC;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259edbc
	if (ctx.cr0.eq) goto loc_8259EDBC;
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8259edb4
	if (!ctx.cr0.eq) goto loc_8259EDB4;
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259edbc
	if (ctx.cr0.eq) goto loc_8259EDBC;
loc_8259EDB4:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8259edc0
	goto loc_8259EDC0;
loc_8259EDBC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8259EDC0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// b 0x8259eeac
	goto loc_8259EEAC;
loc_8259EDC8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82445228
	ctx.lr = 0x8259EDD4;
	sub_82445228(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82445228
	ctx.lr = 0x8259EDE4;
	sub_82445228(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,3
	ctx.r3.s64 = 3;
loc_8259EDEC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x824451b0
	ctx.lr = 0x8259EDF4;
	sub_824451B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8259ed8c
	goto loc_8259ED8C;
loc_8259EE00:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82445228
	ctx.lr = 0x8259EE0C;
	sub_82445228(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82445228
	ctx.lr = 0x8259EE1C;
	sub_82445228(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x8259ed7c
	goto loc_8259ED7C;
loc_8259EE28:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82445228
	ctx.lr = 0x8259EE34;
	sub_82445228(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82445228
	ctx.lr = 0x8259EE44;
	sub_82445228(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x8259edec
	goto loc_8259EDEC;
loc_8259EE50:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82445228
	ctx.lr = 0x8259EE5C;
	sub_82445228(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8259edb4
	if (!ctx.cr0.eq) goto loc_8259EDB4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82445228
	ctx.lr = 0x8259EE70;
	sub_82445228(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8259edb4
	if (!ctx.cr0.eq) goto loc_8259EDB4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82445228
	ctx.lr = 0x8259EE84;
	sub_82445228(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8259edb4
	if (!ctx.cr0.eq) goto loc_8259EDB4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82445228
	ctx.lr = 0x8259EE98;
	sub_82445228(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq 0x8259edc0
	if (ctx.cr0.eq) goto loc_8259EDC0;
	// b 0x8259edb4
	goto loc_8259EDB4;
loc_8259EEA8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8259EEAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A8520) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r31,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r31.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// bgt 0x825a8554
	if (ctx.cr0.gt) goto loc_825A8554;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825A8554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A8554:
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

DEFINE_REX_FUNC(sub_825AB080) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lbz r10,129(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 129);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x825ab0a4
	if (!ctx.cr0.eq) goto loc_825AB0A4;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x825ab0a8
	if (ctx.cr0.eq) goto loc_825AB0A8;
loc_825AB0A4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_825AB0A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825AD338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x825AD340;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// stb r11,77(r3)
	REX_STORE_U8(ctx.r3.u32 + 77, ctx.r11.u8);
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x825ad45c
	if (!ctx.cr6.eq) goto loc_825AD45C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r3,48
	ctx.r30.s64 = ctx.r3.s64 + 48;
	// addi r11,r11,14396
	ctx.r11.s64 = ctx.r11.s64 + 14396;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
loc_825AD370:
	// lbzu r29,2(r7)
	ea = 2 + ctx.r7.u32;
	ctx.r29.u64 = REX_LOAD_U8(ea);
	ctx.r7.u32 = ea;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x823d1f10
	ctx.lr = 0x825AD388;
	sub_823D1F10(ctx, base);
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r29,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r29.u32);
	// bne 0x825ad370
	if (!ctx.cr0.eq) goto loc_825AD370;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stb r28,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r28.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x825ad460
	if (ctx.cr6.lt) goto loc_825AD460;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bge cr6,0x825ad460
	if (!ctx.cr6.lt) goto loc_825AD460;
	// bl 0x82223348
	ctx.lr = 0x825AD3B0;
	sub_82223348(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825ad400
	if (!ctx.cr0.eq) goto loc_825AD400;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82441b00
	ctx.lr = 0x825AD3C8;
	sub_82441B00(ctx, base);
	// stb r3,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r3.u8);
	// bl 0x82223348
	ctx.lr = 0x825AD3D0;
	sub_82223348(ctx, base);
	// lwz r11,19228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r3,r11,304
	ctx.r3.s64 = ctx.r11.s64 + 304;
	// bl 0x827567d0
	ctx.lr = 0x825AD3E4;
	sub_827567D0(ctx, base);
	// bl 0x82223348
	ctx.lr = 0x825AD3E8;
	sub_82223348(ctx, base);
	// lwz r11,19228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,304
	ctx.r4.s64 = ctx.r11.s64 + 304;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x82441518
	ctx.lr = 0x825AD400;
	sub_82441518(ctx, base);
loc_825AD400:
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r30,60(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r29,68(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,24
	ctx.r4.s64 = 24;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x825AD420;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825ad450
	if (ctx.cr0.eq) goto loc_825AD450;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r29,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r29.u32);
	// li r10,275
	ctx.r10.s64 = 275;
	// stw r30,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// addi r11,r11,22424
	ctx.r11.s64 = ctx.r11.s64 + 22424;
	// stw r28,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r28.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r28,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r28.u32);
	// b 0x825ad454
	goto loc_825AD454;
loc_825AD450:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_825AD454:
	// bl 0x825becc0
	ctx.lr = 0x825AD458;
	sub_825BECC0(ctx, base);
	// b 0x825ad460
	goto loc_825AD460;
loc_825AD45C:
	// stb r11,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r11.u8);
loc_825AD460:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825ad488
	if (ctx.cr6.eq) goto loc_825AD488;
	// bl 0x8245cd58
	ctx.lr = 0x825AD470;
	sub_8245CD58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825ad480
	if (ctx.cr0.eq) goto loc_825AD480;
	// lwz r4,72(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// bl 0x82448160
	ctx.lr = 0x825AD480;
	sub_82448160(ctx, base);
loc_825AD480:
	// stw r28,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r28.u32);
	// stw r28,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r28.u32);
loc_825AD488:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B7268) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x825B7270;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r30,4(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,18552
	ctx.r11.s64 = ctx.r11.s64 + 18552;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x825b72c8
	if (ctx.cr6.eq) goto loc_825B72C8;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r29,r11,-12304
	ctx.r29.s64 = ctx.r11.s64 + -12304;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82615138
	ctx.lr = 0x825B72A0;
	sub_82615138(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826217d0
	ctx.lr = 0x825B72A8;
	sub_826217D0(ctx, base);
	// lwsync
	// li r10,0
	ctx.r10.s64 = 0;
loc_825B72B0:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r10,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825b72b0
	if (!ctx.cr0.eq) goto loc_825B72B0;
loc_825B72C8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,18556
	ctx.r11.s64 = ctx.r11.s64 + 18556;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BA300) {
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
	// addi r11,r11,18560
	ctx.r11.s64 = ctx.r11.s64 + 18560;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x825ba32c
	if (ctx.cr0.eq) goto loc_825BA32C;
	// bl 0x825fc588
	ctx.lr = 0x825BA32C;
	sub_825FC588(ctx, base);
loc_825BA32C:
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

DEFINE_REX_FUNC(sub_825BC6B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x825BC6C0;
	__savegprlr_24(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825bc6e4
	if (!ctx.cr6.eq) goto loc_825BC6E4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x825bc6f0
	goto loc_825BC6F0;
loc_825BC6E4:
	// lwz r10,12(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r9,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 7;
loc_825BC6F0:
	// lwz r31,8(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lis r10,511
	ctx.r10.s64 = 33488896;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 7;
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x825bc758
	if (!ctx.cr6.lt) goto loc_825BC758;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,1648
	ctx.r4.s64 = ctx.r11.s64 + 1648;
	// bl 0x82226b70
	ctx.lr = 0x825BC720;
	sub_82226B70(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822269f0
	ctx.lr = 0x825BC72C;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x825BC730;
	sub_82227110(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,1704
	ctx.r11.s64 = ctx.r11.s64 + 1704;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82227048
	ctx.lr = 0x825BC744;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x825BC754;
	sub_82371AF8(ctx, base);
	// b 0x825bca08
	goto loc_825BCA08;
loc_825BC758:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x825bc890
	if (!ctx.cr6.lt) goto loc_825BC890;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x825bc77c
	if (!ctx.cr6.lt) goto loc_825BC77C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x825bc780
	goto loc_825BC780;
loc_825BC77C:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_825BC780:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x825bc78c
	if (!ctx.cr6.lt) goto loc_825BC78C;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_825BC78C:
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// rlwinm r24,r11,7,0,24
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x825BC7A8;
	sub_825FC4B0(ctx, base);
	// lwz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// srawi r27,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r27.s64 = ctx.r11.s32 >> 7;
	// rlwinm r25,r27,7,0,24
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 7) & 0xFFFFFF80;
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x825bc7d0
	if (ctx.cr0.eq) goto loc_825BC7D0;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC7D0;
	sub_827567D0(ctx, base);
loc_825BC7D0:
	// lwz r30,4(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// b 0x825bc7fc
	goto loc_825BC7FC;
loc_825BC7DC:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x825bc7f4
	if (ctx.cr6.eq) goto loc_825BC7F4;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC7F4;
	sub_827567D0(ctx, base);
loc_825BC7F4:
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// addi r28,r28,128
	ctx.r28.s64 = ctx.r28.s64 + 128;
loc_825BC7FC:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x825bc7dc
	if (!ctx.cr6.eq) goto loc_825BC7DC;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// lwz r28,8(r26)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x825bc854
	if (ctx.cr6.eq) goto loc_825BC854;
	// subf r11,r25,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r25.u64;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r29,r11,-128
	ctx.r29.s64 = ctx.r11.s64 + -128;
loc_825BC82C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825bc844
	if (ctx.cr6.eq) goto loc_825BC844;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC844;
	sub_827567D0(ctx, base);
loc_825BC844:
	// addi r29,r29,128
	ctx.r29.s64 = ctx.r29.s64 + 128;
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x825bc82c
	if (!ctx.cr6.eq) goto loc_825BC82C;
loc_825BC854:
	// lwz r3,4(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// srawi r11,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 7;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x825bc874
	if (ctx.cr6.eq) goto loc_825BC874;
	// bl 0x825fc588
	ctx.lr = 0x825BC874;
	sub_825FC588(ctx, base);
loc_825BC874:
	// rlwinm r11,r30,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 7) & 0xFFFFFF80;
	// stw r31,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r31.u32);
	// add r10,r24,r31
	ctx.r10.u64 = ctx.r24.u64 + ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r10,12(r26)
	REX_STORE_U32(ctx.r26.u32 + 12, ctx.r10.u32);
	// stw r11,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r11.u32);
	// b 0x825bca08
	goto loc_825BCA08;
loc_825BC890:
	// subf r11,r29,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// srawi r11,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 7;
	// li r5,128
	ctx.r5.s64 = 128;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bge cr6,0x825bc968
	if (!ctx.cr6.lt) goto loc_825BC968;
	// bl 0x827567d0
	ctx.lr = 0x825BC8B0;
	sub_827567D0(ctx, base);
	// addi r30,r29,128
	ctx.r30.s64 = ctx.r29.s64 + 128;
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825bc8e8
	if (ctx.cr6.eq) goto loc_825BC8E8;
	// addi r28,r30,-128
	ctx.r28.s64 = ctx.r30.s64 + -128;
loc_825BC8C0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825bc8d8
	if (ctx.cr6.eq) goto loc_825BC8D8;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC8D8;
	sub_827567D0(ctx, base);
loc_825BC8D8:
	// addi r28,r28,128
	ctx.r28.s64 = ctx.r28.s64 + 128;
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// cmplw cr6,r28,r31
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x825bc8c0
	if (!ctx.cr6.eq) goto loc_825BC8C0;
loc_825BC8E8:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// srawi r11,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 7;
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825bc92c
	if (ctx.cr6.eq) goto loc_825BC92C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_825BC908:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825bc920
	if (ctx.cr6.eq) goto loc_825BC920;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC920;
	sub_827567D0(ctx, base);
loc_825BC920:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,128
	ctx.r31.s64 = ctx.r31.s64 + 128;
	// bne 0x825bc908
	if (!ctx.cr0.eq) goto loc_825BC908;
loc_825BC92C:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// addi r30,r11,-128
	ctx.r30.s64 = ctx.r11.s64 + -128;
	// stw r11,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825bca08
	if (ctx.cr6.eq) goto loc_825BCA08;
loc_825BC948:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC958;
	sub_827567D0(ctx, base);
	// addi r31,r31,128
	ctx.r31.s64 = ctx.r31.s64 + 128;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825bc948
	if (!ctx.cr6.eq) goto loc_825BC948;
	// b 0x825bca08
	goto loc_825BCA08;
loc_825BC968:
	// bl 0x827567d0
	ctx.lr = 0x825BC96C;
	sub_827567D0(ctx, base);
	// addi r28,r31,-128
	ctx.r28.s64 = ctx.r31.s64 + -128;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r31
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825bc9a8
	if (ctx.cr6.eq) goto loc_825BC9A8;
loc_825BC980:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825bc998
	if (ctx.cr6.eq) goto loc_825BC998;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC998;
	sub_827567D0(ctx, base);
loc_825BC998:
	// addi r27,r27,128
	ctx.r27.s64 = ctx.r27.s64 + 128;
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x825bc980
	if (!ctx.cr6.eq) goto loc_825BC980;
loc_825BC9A8:
	// stw r30,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r30.u32);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x825bc9dc
	if (ctx.cr6.eq) goto loc_825BC9DC;
	// addi r30,r28,128
	ctx.r30.s64 = ctx.r28.s64 + 128;
loc_825BC9BC:
	// addi r31,r31,-128
	ctx.r31.s64 = ctx.r31.s64 + -128;
	// addi r30,r30,-128
	ctx.r30.s64 = ctx.r30.s64 + -128;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC9D4;
	sub_827567D0(ctx, base);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x825bc9bc
	if (!ctx.cr6.eq) goto loc_825BC9BC;
loc_825BC9DC:
	// addi r30,r29,128
	ctx.r30.s64 = ctx.r29.s64 + 128;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825bca08
	if (ctx.cr6.eq) goto loc_825BCA08;
loc_825BC9EC:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827567d0
	ctx.lr = 0x825BC9FC;
	sub_827567D0(ctx, base);
	// addi r31,r31,128
	ctx.r31.s64 = ctx.r31.s64 + 128;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825bc9ec
	if (!ctx.cr6.eq) goto loc_825BC9EC;
loc_825BCA08:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D3E60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x825D3E68;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D3E88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825d3ed0
	if (ctx.cr6.eq) goto loc_825D3ED0;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lhz r9,316(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 316);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwz r7,252(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 252);
	// lwz r6,116(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// lwzx r29,r8,r7
	ctx.r29.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl
	ctx.lr = 0x825D3EB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmpw cr6,r29,r5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x825d3ed0
	if (ctx.cr6.lt) goto loc_825D3ED0;
loc_825D3EC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
loc_825D3ED0:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d3f6c
	if (ctx.cr6.eq) goto loc_825D3F6C;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lhz r31,1(r11)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r11.u32 + 1);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,65535
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 65535, ctx.xer);
	// beq cr6,0x825d3f6c
	if (ctx.cr6.eq) goto loc_825D3F6C;
loc_825D3EF0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D3F08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x825d3f44
	if (ctx.cr6.eq) goto loc_825D3F44;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,116(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 116);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwzx r29,r10,r9
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl
	ctx.lr = 0x825D3F38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmpw cr6,r29,r7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x825d3ec4
	if (!ctx.cr6.lt) goto loc_825D3EC4;
loc_825D3F44:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D3F5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,65535
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 65535, ctx.xer);
	// bne cr6,0x825d3ef0
	if (!ctx.cr6.eq) goto loc_825D3EF0;
loc_825D3F6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825DA520) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x825DA528;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl
	ctx.lr = 0x825DA550;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbzx r8,r3,r31
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stb r7,9(r29)
	REX_STORE_U8(ctx.r29.u32 + 9, ctx.r7.u8);
	// stb r8,8(r29)
	REX_STORE_U8(ctx.r29.u32 + 8, ctx.r8.u8);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,72(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 72);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl
	ctx.lr = 0x825DA578;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825DCF98) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// cmplwi cr6,r8,255
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 255, ctx.xer);
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825dcfc4
	if (ctx.cr6.eq) goto loc_825DCFC4;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// b 0x825dcfcc
	goto loc_825DCFCC;
loc_825DCFC4:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
loc_825DCFCC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825dcfdc
	if (ctx.cr6.eq) goto loc_825DCFDC;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// b 0x825dcfe0
	goto loc_825DCFE0;
loc_825DCFDC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825DCFE0:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mullw r11,r8,r9
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rldicl r5,r7,59,46
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 59) & 0x3FFFF;
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// tdllei r5,0
	if (ctx.r5.s64 == 0ll || ctx.r5.u64 < 0ull) ppc_trap(ctx, base, 0);
	// mulli r3,r4,1000
	ctx.r3.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(1000));
	// rotldi r11,r3,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u64, 1);
	// divd r10,r3,r5
	ctx.r10.s64 = (ctx.r5.s64 && !(ctx.r3.s64 == INT64_MIN && ctx.r5.s64 == -1)) ? ctx.r3.s64 / ctx.r5.s64 : 0;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// andc r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 & ~ctx.r9.u64;
	// tdlgei r8,-1
	if (ctx.r8.s64 == -1ll || ctx.r8.u64 > 18446744073709551615ull) ppc_trap(ctx, base, 0);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825E08F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x825E08F8;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// lwz r7,20(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// lwz r6,56(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// lwz r25,308(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 308);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r26,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r26.u32);
	// stw r26,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r26.u32);
	// stw r8,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,32(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825E0950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// stb r11,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// bl 0x82657af0
	ctx.lr = 0x825E096C;
	sub_82657AF0(ctx, base);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// addic r9,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// ori r7,r10,14
	ctx.r7.u64 = ctx.r10.u64 | 14;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r22,r26
	ctx.r22.u64 = ctx.r26.u64;
	// and r29,r6,r7
	ctx.r29.u64 = ctx.r6.u64 & ctx.r7.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x825e0a74
	if (ctx.cr6.lt) goto loc_825E0A74;
	// lis r11,-30009
	ctx.r11.s64 = -1966669824;
	// ori r21,r11,25
	ctx.r21.u64 = ctx.r11.u64 | 25;
loc_825E0998:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x825e0b60
	if (ctx.cr6.eq) goto loc_825E0B60;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825e09b8
	if (ctx.cr6.eq) goto loc_825E09B8;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// b 0x825e09c8
	goto loc_825E09C8;
loc_825E09B8:
	// lbz r11,6(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 6);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r6,r9,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_825E09C8:
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825e9c88
	ctx.lr = 0x825E09E0;
	sub_825E9C88(ctx, base);
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825e0a4c
	if (ctx.cr6.lt) goto loc_825E0A4C;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// bne cr6,0x825e0aec
	if (!ctx.cr6.eq) goto loc_825E0AEC;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// rlwinm r10,r10,27,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFFFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// bge cr6,0x825e0aec
	if (!ctx.cr6.lt) goto loc_825E0AEC;
	// li r28,1
	ctx.r28.s64 = 1;
loc_825E0A20:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x825e0a4c
	if (ctx.cr6.lt) goto loc_825E0A4C;
loc_825E0A28:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0A40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x825e0a6c
	if (ctx.cr6.eq) goto loc_825E0A6C;
loc_825E0A4C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825e0a6c
	if (ctx.cr6.eq) goto loc_825E0A6C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0A6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E0A6C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x825e0998
	if (!ctx.cr6.lt) goto loc_825E0998;
loc_825E0A74:
	// clrlwi r30,r24,24
	ctx.r30.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825e0abc
	if (ctx.cr6.eq) goto loc_825E0ABC;
loc_825E0A80:
	// addi r11,r30,255
	ctx.r11.s64 = ctx.r30.s64 + 255;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r9,r11,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwzx r3,r9,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e0ab4
	if (ctx.cr6.eq) goto loc_825E0AB4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0AB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E0AB4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825e0a80
	if (!ctx.cr6.eq) goto loc_825E0A80;
loc_825E0ABC:
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stb r26,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r26.u8);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825e0adc
	if (ctx.cr6.eq) goto loc_825E0ADC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x82657b88
	ctx.lr = 0x825E0AD8;
	sub_82657B88(ctx, base);
	// stw r26,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
loc_825E0ADC:
	// stw r26,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
loc_825E0AEC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0B04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825e0b48
	if (ctx.cr6.lt) goto loc_825E0B48;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// blt cr6,0x825e0b30
	if (ctx.cr6.lt) goto loc_825E0B30;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bgt cr6,0x825e0b30
	if (ctx.cr6.gt) goto loc_825E0B30;
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
loc_825E0B30:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// rlwinm r9,r24,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0x3FC;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// clrlwi r24,r8,24
	ctx.r24.u64 = ctx.r8.u32 & 0xFF;
	// stwx r30,r9,r10
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r30.u32);
loc_825E0B48:
	// cmpw cr6,r29,r21
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r21.s32, ctx.xer);
	// bne cr6,0x825e0a20
	if (!ctx.cr6.eq) goto loc_825E0A20;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// b 0x825e0a28
	goto loc_825E0A28;
loc_825E0B60:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x825e0a74
	if (ctx.cr6.lt) goto loc_825E0A74;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x825e0b84
	if (ctx.cr6.eq) goto loc_825E0B84;
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825e0b84
	if (!ctx.cr6.eq) goto loc_825E0B84;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// b 0x825e0a74
	goto loc_825E0A74;
loc_825E0B84:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stb r24,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r24.u8);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825e0ba4
	if (ctx.cr6.eq) goto loc_825E0BA4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E0BA4:
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FCD28) {
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
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r11,r11,-12504
	ctx.r11.s64 = ctx.r11.s64 + -12504;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825fcd84
	if (!ctx.cr6.eq) goto loc_825FCD84;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,-9600(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -9600);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825fcd78
	if (ctx.cr6.eq) goto loc_825FCD78;
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
	ctx.lr = 0x825FCD78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825FCD78:
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// b 0x825fce28
	goto loc_825FCE28;
loc_825FCD84:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_825FCD88:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fcd88
	if (!ctx.cr0.eq) goto loc_825FCD88;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825fce24
	if (!ctx.cr6.eq) goto loc_825FCE24;
	// lis r31,-32109
	ctx.r31.s64 = -2104295424;
	// lwz r3,6880(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 6880);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825fcdcc
	if (ctx.cr6.eq) goto loc_825FCDCC;
	// bl 0x82223200
	ctx.lr = 0x825FCDC4;
	sub_82223200(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,6880(r31)
	REX_STORE_U32(ctx.r31.u32 + 6880, ctx.r11.u32);
loc_825FCDCC:
	// lis r10,-32108
	ctx.r10.s64 = -2104229888;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r31,-32008(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -32008);
	// stw r11,-32008(r10)
	REX_STORE_U32(ctx.r10.u32 + -32008, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi r31,0
	ctx.cr0.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x825fcdfc
	if (ctx.cr0.eq) goto loc_825FCDFC;
loc_825FCDE8:
	// lwz r31,2948(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 2948);
	// bl 0x825fc588
	ctx.lr = 0x825FCDF0;
	sub_825FC588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x825fcde8
	if (!ctx.cr6.eq) goto loc_825FCDE8;
loc_825FCDFC:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r11,r11,-9600
	ctx.r11.s64 = ctx.r11.s64 + -9600;
	// lwz r11,-2872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -2872);
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x825fce1c
	if (ctx.cr0.eq) goto loc_825FCE1C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r10.u8);
loc_825FCE1C:
	// bl 0x825fc760
	ctx.lr = 0x825FCE20;
	sub_825FC760(ctx, base);
	// bl 0x825fc6d0
	ctx.lr = 0x825FCE24;
	sub_825FC6D0(ctx, base);
loc_825FCE24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825FCE28:
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

DEFINE_REX_FUNC(sub_82602988) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82602990;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826029C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r27,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r27.u64);
	// stw r26,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r26.u32);
	// bl 0x826027b8
	ctx.lr = 0x826029E4;
	sub_826027B8(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826029f4
	if (ctx.cr6.eq) goto loc_826029F4;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_826029F4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826047A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x826047A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x8260f488
	ctx.lr = 0x826047B8;
	sub_8260F488(ctx, base);
	// lbz r11,6(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 6);
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826047cc
	if (ctx.cr0.eq) goto loc_826047CC;
	// lwz r3,0(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
loc_826047CC:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// bl 0x82656e38
	ctx.lr = 0x826047E8;
	sub_82656E38(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// bne cr6,0x82604804
	if (!ctx.cr6.eq) goto loc_82604804;
loc_826047FC:
	// bl 0x82604860
	ctx.lr = 0x82604800;
	sub_82604860(ctx, base);
	// b 0x82604858
	goto loc_82604858;
loc_82604804:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82657030
	ctx.lr = 0x82604810;
	sub_82657030(ctx, base);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// bl 0x826563c8
	ctx.lr = 0x82604818;
	sub_826563C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82656df0
	ctx.lr = 0x82604824;
	sub_82656DF0(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82604844
	if (!ctx.cr6.eq) goto loc_82604844;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82604844
	if (ctx.cr6.eq) goto loc_82604844;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826580e8
	ctx.lr = 0x82604840;
	sub_826580E8(ctx, base);
	// b 0x826047fc
	goto loc_826047FC;
loc_82604844:
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82656938
	ctx.lr = 0x82604854;
	sub_82656938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82604858:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82607A10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x82607A18;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 204);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r31,r3,176
	ctx.r31.s64 = ctx.r3.s64 + 176;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82607a40
	if (ctx.cr0.eq) goto loc_82607A40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82872dfc
	ctx.lr = 0x82607A40;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82607A40:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826078b0
	ctx.lr = 0x82607A50;
	sub_826078B0(ctx, base);
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82607a68
	if (ctx.cr0.eq) goto loc_82607A68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82872dec
	ctx.lr = 0x82607A68;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82607A68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8260BB08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8260BB10;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8260bbb8
	if (ctx.cr6.eq) goto loc_8260BBB8;
	// addi r31,r3,4
	ctx.r31.s64 = ctx.r3.s64 + 4;
	// cmplw cr6,r31,r4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8260bbb8
	if (ctx.cr6.eq) goto loc_8260BBB8;
	// subfic r28,r3,4
	ctx.xer.ca = ctx.r3.u32 <= 4;
	ctx.r28.u64 = static_cast<uint64_t>(4) - ctx.r3.u64;
loc_8260BB34:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lhz r9,94(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 94);
	// lhz r11,94(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 94);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8260bb80
	if (!ctx.cr6.gt) goto loc_8260BB80;
	// add r11,r28,r31
	ctx.r11.u64 = ctx.r28.u64 + ctx.r31.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8260bb78
	if (!ctx.cr0.gt) goto loc_8260BB78;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// subf r11,r4,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r4.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// bl 0x82755080
	ctx.lr = 0x8260BB78;
	sub_82755080(ctx, base);
loc_8260BB78:
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// b 0x8260bbac
	goto loc_8260BBAC;
loc_8260BB80:
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// b 0x8260bb9c
	goto loc_8260BB9C;
loc_8260BB8C:
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwzu r11,-4(r10)
	ea = -4 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lhz r9,94(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 94);
loc_8260BB9C:
	// lhz r7,94(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 94);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bgt cr6,0x8260bb8c
	if (ctx.cr6.gt) goto loc_8260BB8C;
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
loc_8260BBAC:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8260bb34
	if (!ctx.cr6.eq) goto loc_8260BB34;
loc_8260BBB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82610D20) {
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
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r3,144
	ctx.r4.s64 = ctx.r3.s64 + 144;
loc_82610D38:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x826105d8
	ctx.lr = 0x82610D40;
	sub_826105D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82610d6c
	if (ctx.cr0.eq) goto loc_82610D6C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// cmplwi cr6,r7,6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 6, ctx.xer);
	// blt cr6,0x82610d38
	if (ctx.cr6.lt) goto loc_82610D38;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82610D5C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
loc_82610D6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82610d5c
	goto loc_82610D5C;
}

DEFINE_REX_FUNC(sub_82612C48) {
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
	// lwz r11,324(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612c7c
	if (ctx.cr6.eq) goto loc_82612C7C;
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// b 0x82612d84
	goto loc_82612D84;
loc_82612C7C:
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612ca8
	if (ctx.cr6.eq) goto loc_82612CA8;
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612ca0
	if (ctx.cr6.eq) goto loc_82612CA0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x826134d8
	ctx.lr = 0x82612C9C;
	sub_826134D8(ctx, base);
	// b 0x82612ca8
	goto loc_82612CA8;
loc_82612CA0:
	// addi r3,r31,280
	ctx.r3.s64 = ctx.r31.s64 + 280;
	// bl 0x826132b8
	ctx.lr = 0x82612CA8;
	sub_826132B8(ctx, base);
loc_82612CA8:
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612cd4
	if (ctx.cr6.eq) goto loc_82612CD4;
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612ccc
	if (ctx.cr6.eq) goto loc_82612CCC;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x826134d8
	ctx.lr = 0x82612CC8;
	sub_826134D8(ctx, base);
	// b 0x82612cd4
	goto loc_82612CD4;
loc_82612CCC:
	// addi r3,r31,304
	ctx.r3.s64 = ctx.r31.s64 + 304;
	// bl 0x826132b8
	ctx.lr = 0x82612CD4;
	sub_826132B8(ctx, base);
loc_82612CD4:
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82612d00
	if (ctx.cr6.eq) goto loc_82612D00;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612d00
	if (ctx.cr6.eq) goto loc_82612D00;
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r10,348(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82612d00
	if (ctx.cr6.eq) goto loc_82612D00;
	// bl 0x826134d8
	ctx.lr = 0x82612D00;
	sub_826134D8(ctx, base);
loc_82612D00:
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612d14
	if (ctx.cr6.eq) goto loc_82612D14;
	// addi r3,r31,352
	ctx.r3.s64 = ctx.r31.s64 + 352;
	// bl 0x826132b8
	ctx.lr = 0x82612D14;
	sub_826132B8(ctx, base);
loc_82612D14:
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612d28
	if (ctx.cr6.eq) goto loc_82612D28;
	// addi r3,r31,328
	ctx.r3.s64 = ctx.r31.s64 + 328;
	// bl 0x826132b8
	ctx.lr = 0x82612D28;
	sub_826132B8(ctx, base);
loc_82612D28:
	// lwz r4,16(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612d54
	if (ctx.cr6.eq) goto loc_82612D54;
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612d4c
	if (ctx.cr6.eq) goto loc_82612D4C;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x826134d8
	ctx.lr = 0x82612D48;
	sub_826134D8(ctx, base);
	// b 0x82612d54
	goto loc_82612D54;
loc_82612D4C:
	// addi r3,r31,376
	ctx.r3.s64 = ctx.r31.s64 + 376;
	// bl 0x826132b8
	ctx.lr = 0x82612D54;
	sub_826132B8(ctx, base);
loc_82612D54:
	// lwz r4,20(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82612d80
	if (ctx.cr6.eq) goto loc_82612D80;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82612d78
	if (ctx.cr6.eq) goto loc_82612D78;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x826134d8
	ctx.lr = 0x82612D74;
	sub_826134D8(ctx, base);
	// b 0x82612d80
	goto loc_82612D80;
loc_82612D78:
	// addi r3,r31,400
	ctx.r3.s64 = ctx.r31.s64 + 400;
	// bl 0x826132b8
	ctx.lr = 0x82612D80;
	sub_826132B8(ctx, base);
loc_82612D80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82612D84:
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

DEFINE_REX_FUNC(sub_8261A928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8261A930;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r25,r11,-12328
	ctx.r25.s64 = ctx.r11.s64 + -12328;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82615358
	ctx.lr = 0x8261A948;
	sub_82615358(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-12336
	ctx.r29.s64 = ctx.r11.s64 + -12336;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8261a998
	if (!ctx.cr6.eq) goto loc_8261A998;
	// lwsync
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
loc_8261A968:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261a968
	if (!ctx.cr0.eq) goto loc_8261A968;
	// bl 0x826239d0
	ctx.lr = 0x8261A984;
	sub_826239D0(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82615358
	ctx.lr = 0x8261A98C;
	sub_82615358(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8261aa34
	if (ctx.cr6.eq) goto loc_8261AA34;
loc_8261A998:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8261a9d0
	if (ctx.cr0.eq) goto loc_8261A9D0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8261A9D0:
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8261aa34
	if (ctx.cr0.eq) goto loc_8261AA34;
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,-12324(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12324);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-12324(r28)
	REX_STORE_U32(ctx.r28.u32 + -12324, ctx.r11.u32);
	// bl 0x8262b730
	ctx.lr = 0x8261AA00;
	sub_8262B730(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x8261aa68
	if (ctx.cr0.eq) goto loc_8261AA68;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8262b9f8
	ctx.lr = 0x8261AA20;
	sub_8262B9F8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8261aa5c
	if (!ctx.cr0.eq) goto loc_8261AA5C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8262b798
	ctx.lr = 0x8261AA30;
	sub_8262B798(ctx, base);
	// b 0x8261aa68
	goto loc_8261AA68;
loc_8261AA34:
	// lwsync
loc_8261AA38:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r25
	ea = ctx.r25.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r25
	ea = ctx.r25.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261aa38
	if (!ctx.cr0.eq) goto loc_8261AA38;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8261AA54:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
loc_8261AA5C:
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8261aaec
	if (!ctx.cr6.eq) goto loc_8261AAEC;
loc_8261AA68:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r9,r31,28
	ctx.r9.s64 = ctx.r31.s64 + 28;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
loc_8261AA7C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261aa7c
	if (!ctx.cr0.eq) goto loc_8261AA7C;
	// lwsync
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,-12324(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + -12324);
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,-12324(r28)
	REX_STORE_U32(ctx.r28.u32 + -12324, ctx.r9.u32);
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8261AACC:
	// lwsync
loc_8261AAD0:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r25
	ea = ctx.r25.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r25
	ea = ctx.r25.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261aad0
	if (!ctx.cr0.eq) goto loc_8261AAD0;
	// b 0x8261aa54
	goto loc_8261AA54;
loc_8261AAEC:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,-8480(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -8480);
	// cmplwi cr6,r11,8191
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8191, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// blt cr6,0x8261ab08
	if (ctx.cr6.lt) goto loc_8261AB08;
	// li r11,1
	ctx.r11.s64 = 1;
loc_8261AB08:
	// stw r11,-8480(r10)
	REX_STORE_U32(ctx.r10.u32 + -8480, ctx.r11.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// clrlwi r9,r9,17
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFF;
	// stw r8,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// rlwimi r10,r11,15,4,16
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFF8000) | (ctx.r10.u64 & 0xFFFFFFFFF0007FFF);
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r9,r31,28
	ctx.r9.s64 = ctx.r31.s64 + 28;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_8261AB34:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261ab34
	if (!ctx.cr0.eq) goto loc_8261AB34;
	// lwsync
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// lwz r11,-12320(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12320);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x8261aacc
	goto loc_8261AACC;
}

DEFINE_REX_FUNC(sub_82632298) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x826322A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,-8412(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -8412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826322f4
	if (ctx.cr6.eq) goto loc_826322F4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x826322ec
	goto loc_826322EC;
loc_826322C4:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826322D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82632300
	if (ctx.cr6.eq) goto loc_82632300;
	// lwz r11,-8412(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -8412);
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_826322EC:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x826322c4
	if (!ctx.cr6.eq) goto loc_826322C4;
loc_826322F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826322F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
loc_82632300:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// b 0x826322f8
	goto loc_826322F8;
}

DEFINE_REX_FUNC(sub_82634618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82634620;
	__savegprlr_26(ctx, base);
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r11,48(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 48);
	// addi r10,r10,31616
	ctx.r10.s64 = ctx.r10.s64 + 31616;
	// li r8,8
	ctx.r8.s64 = 8;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// li r31,12
	ctx.r31.s64 = 12;
	// addi r7,r7,-30000
	ctx.r7.s64 = ctx.r7.s64 + -30000;
	// lvx128 v63,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lvsr v7,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r3,0
	ctx.r3.s64 = 0;
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r10,r10,-30032
	ctx.r10.s64 = ctx.r10.s64 + -30032;
	// lvsr v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v11,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r8,-30528
	ctx.r10.s64 = ctx.r8.s64 + -30528;
	// lvsl v7,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,4
	ctx.r8.s64 = 4;
	// vsel v13,v12,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lvsr v6,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v12,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v5,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vperm128 v61,v13,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsr v4,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vperm128 v11,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vsubfp128 v0,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsel v12,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vperm128 v62,v12,v12,v5
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vsubfp128 v13,v62,v60
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vsel v0,v12,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// blt cr6,0x826348b4
	if (ctx.cr6.lt) goto loc_826348B4;
	// beq cr6,0x82634820
	if (ctx.cr6.eq) goto loc_82634820;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82634788
	if (ctx.cr6.lt) goto loc_82634788;
	// beq cr6,0x826346f4
	if (ctx.cr6.eq) goto loc_826346F4;
	// vor128 v62,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v63,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v61,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// b 0x82634950
	goto loc_82634950;
loc_826346F4:
	// addi r11,r1,-80
	ctx.r11.s64 = ctx.r1.s64 + -80;
	// stfs f1,-68(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// stfs f1,-72(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f1,-76(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// stfs f1,-80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// vperm128 v62,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f1,-84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// vperm128 v11,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v9,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stfs f2,-68(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// vperm128 v10,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stfs f2,-72(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f2,-76(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vperm128 v62,v0,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// stfs f2,-80(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lvx128 v57,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// stfs f1,-88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f1,-92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// vspltw128 v63,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f1,-96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// vor128 v62,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vaddfp128 v12,v59,v57
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vsel v8,v0,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vor v11,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v63,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vsel128 v62,v11,v13,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vperm128 v60,v63,v63,v5
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vsubfp128 v13,v60,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// b 0x82634948
	goto loc_82634948;
loc_82634788:
	// addi r10,r1,-80
	ctx.r10.s64 = ctx.r1.s64 + -80;
	// stfs f1,-68(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f1,-72(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// addi r11,r1,-96
	ctx.r11.s64 = ctx.r1.s64 + -96;
	// stfs f1,-76(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vperm128 v62,v0,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// stfs f1,-80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// vperm128 v8,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stfs f2,-84(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// vperm128 v61,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v9,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f2,-88(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f2,-92(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// vperm128 v10,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// stfs f2,-96(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// vor v11,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v63,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vor v12,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vsel128 v63,v11,v13,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// addi r11,r1,-96
	ctx.r11.s64 = ctx.r1.s64 + -96;
	// vor128 v62,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// stfs f1,-96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// vor128 v61,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// stfs f1,-84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// vsubfp128 v13,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vperm128 v60,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f1,-88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f1,-92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vsel128 v62,v12,v13,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsubfp128 v13,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// b 0x82634948
	goto loc_82634948;
loc_82634820:
	// addi r11,r1,-80
	ctx.r11.s64 = ctx.r1.s64 + -80;
	// stfs f2,-80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// stfs f1,-84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// stfs f1,-88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// vperm128 v62,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f1,-92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// vperm128 v7,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// stfs f1,-96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// vperm128 v61,v0,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// stfs f2,-68(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// vperm128 v8,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f1,-84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// stfs f1,-88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// vperm128 v9,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stfs f2,-72(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vor v10,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// stfs f2,-76(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vor128 v63,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stfs f1,-92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// stfs f1,-96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// vor v12,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v62,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// lvx128 v57,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v11,v60,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v57.f32)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel128 v63,v10,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vaddfp128 v13,v58,v60
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vperm128 v60,v63,v63,v5
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vsel128 v62,v12,v13,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vaddfp128 v13,v60,v59
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// b 0x82634944
	goto loc_82634944;
loc_826348B4:
	// vperm128 v62,v0,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// addi r11,r1,-80
	ctx.r11.s64 = ctx.r1.s64 + -80;
	// stfs f2,-68(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// vperm128 v5,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stfs f2,-72(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vperm128 v61,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stfs f2,-76(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f2,-80(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lvx128 v58,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// stfs f1,-100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// vperm128 v8,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// stfs f1,-104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// vperm128 v9,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vaddfp128 v11,v60,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// stfs f1,-108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// vor v10,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vor128 v63,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v5.u8));
	// stfs f1,-84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// stfs f1,-88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// vor v12,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// stfs f1,-92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// vor128 v62,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// stfs f1,-96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel128 v63,v10,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vaddfp128 v13,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f1,-112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// vperm128 v59,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel128 v62,v12,v13,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vspltw128 v59,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vaddfp128 v13,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
loc_82634944:
	// vor128 v61,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
loc_82634948:
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vsel128 v61,v12,v13,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
loc_82634950:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lwz r6,4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// addi r9,r11,12484
	ctx.r9.s64 = ctx.r11.s64 + 12484;
	// li r7,16
	ctx.r7.s64 = 16;
	// cmplw cr6,r6,r10
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, ctx.xer);
	// lwz r11,-9664(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -9664);
	// lfs f0,-232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x82634a74
	if (ctx.cr6.eq) goto loc_82634A74;
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x826349c0
	if (ctx.cr6.eq) goto loc_826349C0;
	// lhz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lwz r8,4(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r10.u64);
	// lfd f13,-80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,8(r4)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// lhz r10,10(r8)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r8.u32 + 10);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r10.u64);
	// lfd f13,-80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,12(r4)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r4.u32 + 12, temp.u32);
loc_826349C0:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f13,-72(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f13,-68(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// beq cr6,0x82634a44
	if (ctx.cr6.eq) goto loc_82634A44;
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r6,r1,-80
	ctx.r6.s64 = ctx.r1.s64 + -80;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// li r30,17
	ctx.r30.s64 = 17;
	// lwz r8,20(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r29,28
	ctx.r29.s64 = 28;
	// addi r9,r10,28
	ctx.r9.s64 = ctx.r10.s64 + 28;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r26,r10,12
	ctx.r26.s64 = ctx.r10.s64 + 12;
	// lwz r28,0(r6)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r27,4(r6)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r26,8(r6)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r6,12(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// sth r30,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r30.u16);
	// sth r29,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r29.u16);
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// stw r31,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r31.u32);
	// stw r28,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r28.u32);
	// stw r27,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r27.u32);
	// stw r26,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r26.u32);
	// stw r6,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// b 0x82634a74
	goto loc_82634A74;
loc_82634A44:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// sth r7,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r7.u16);
	// sth r8,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r8.u16);
	// stw r3,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r3,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r3.u32);
loc_82634A74:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82634c88
	if (ctx.cr6.eq) goto loc_82634C88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lfs f11,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lfs f9,24(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f13,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r6,13
	ctx.r6.s64 = 13;
	// lfs f12,16(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f10,20(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// li r31,4
	ctx.r31.s64 = 4;
	// lfs f8,28(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// li r4,5
	ctx.r4.s64 = 5;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r7,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r7.u16);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// sth r4,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r4.u16);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stw r6,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lvsl v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// stw r31,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r31.u32);
	// vperm128 v60,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsl v6,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v59,v62,v62,v6
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v7,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r1,-80
	ctx.r10.s64 = ctx.r1.s64 + -80;
	// vperm128 v62,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsl v6,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r31,r1,-80
	ctx.r31.s64 = ctx.r1.s64 + -80;
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// vperm128 v58,v0,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// addi r7,r1,-96
	ctx.r7.s64 = ctx.r1.s64 + -96;
	// vspltw128 v59,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// addi r6,r1,-144
	ctx.r6.s64 = ctx.r1.s64 + -144;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// li r4,4
	ctx.r4.s64 = 4;
	// vspltw128 v58,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// fdivs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f11.f64));
	// stfs f12,-128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -128, temp.u32);
	// li r30,4
	ctx.r30.s64 = 4;
	// stvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v59,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -96);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f7,-112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -112);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -144);
	ctx.f6.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// addi r10,r10,80
	ctx.r10.s64 = ctx.r10.s64 + 80;
	// lvsl v0,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v62,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// sth r10,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r10.u16);
	// stfs f11,-140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -140, temp.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r10,r10,80
	ctx.r10.s64 = ctx.r10.s64 + 80;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f11,-80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f6,-144(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + -144, temp.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stfs f10,-124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -124, temp.u32);
	// stfs f9,-112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f7,-108(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f13,-96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f10,-92(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// lvsl v0,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r6,r1,-96
	ctx.r6.s64 = ctx.r1.s64 + -96;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// ld r29,-96(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// addi r4,r1,-96
	ctx.r4.s64 = ctx.r1.s64 + -96;
	// lvsl v0,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// ld r10,-144(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// ld r3,-128(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// fadds f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// stfs f0,-140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -140, temp.u32);
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f0,-124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -124, temp.u32);
	// ld r30,-112(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// stfs f13,-144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -144, temp.u32);
	// stfs f12,-128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -128, temp.u32);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r7,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r7.u32);
	// stfs f11,-76(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,-128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r10.u64);
	// lfs f12,-112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -112);
	ctx.f12.f64 = double(temp.f32);
	// std r11,68(r7)
	REX_STORE_U64(ctx.r7.u32 + 68, ctx.r11.u64);
	// lfs f0,-96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -96);
	ctx.f0.f64 = double(temp.f32);
	// ld r11,-144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r3,8(r7)
	REX_STORE_U64(ctx.r7.u32 + 8, ctx.r3.u64);
	// lfs f13,-96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -96);
	ctx.f13.f64 = double(temp.f32);
	// stw r5,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r5.u32);
	// stfs f12,-92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// stw r5,36(r7)
	REX_STORE_U32(ctx.r7.u32 + 36, ctx.r5.u32);
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// std r30,20(r7)
	REX_STORE_U64(ctx.r7.u32 + 20, ctx.r30.u64);
	// std r29,28(r7)
	REX_STORE_U64(ctx.r7.u32 + 28, ctx.r29.u64);
	// stw r5,56(r7)
	REX_STORE_U32(ctx.r7.u32 + 56, ctx.r5.u32);
	// stw r5,76(r7)
	REX_STORE_U32(ctx.r7.u32 + 76, ctx.r5.u32);
	// std r11,48(r7)
	REX_STORE_U64(ctx.r7.u32 + 48, ctx.r11.u64);
	// ld r10,-80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// stfs f13,-96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// ld r9,-96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// std r10,40(r7)
	REX_STORE_U64(ctx.r7.u32 + 40, ctx.r10.u64);
	// std r9,60(r7)
	REX_STORE_U64(ctx.r7.u32 + 60, ctx.r9.u64);
loc_82634C88:
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826961E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826961fc
	if (ctx.cr6.lt) goto loc_826961FC;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r7,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// b 0x82696220
	goto loc_82696220;
loc_826961FC:
	// subf r6,r10,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r10.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// add r6,r11,r7
	ctx.r6.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// sth r6,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r6.u16);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
loc_82696220:
	// sth r11,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r11.u16);
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// bne cr6,0x82696270
	if (!ctx.cr6.eq) goto loc_82696270;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lhz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// lhz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r3.u16);
	// sth r3,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r3.u16);
	// blr
	return;
loc_82696270:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lhz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// lhz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r4.u16);
	// sth r4,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r4.u16);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8269FB58) {
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
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8269FB7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bne 0x8269fbac
	if (!ctx.cr0.eq) goto loc_8269FBAC;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8269fbac
	if (ctx.cr6.eq) goto loc_8269FBAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269f9d0
	ctx.lr = 0x8269FBA0;
	sub_8269F9D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8266f5f8
	ctx.lr = 0x8269FBA8;
	sub_8266F5F8(ctx, base);
	// b 0x8269fbc0
	goto loc_8269FBC0;
loc_8269FBAC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8269FBC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8269FBC0:
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

DEFINE_REX_FUNC(sub_826A0BA8) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r3,252
	ctx.r5.s64 = ctx.r3.s64 + 252;
	// addi r4,r10,5984
	ctx.r4.s64 = ctx.r10.s64 + 5984;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826A0BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826a0c24
	if (ctx.cr0.lt) goto loc_826A0C24;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r30,256
	ctx.r5.s64 = ctx.r30.s64 + 256;
	// addi r4,r10,7636
	ctx.r4.s64 = ctx.r10.s64 + 7636;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826A0C0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// ori r11,r11,16386
	ctx.r11.u64 = ctx.r11.u64 | 16386;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_826A0C24:
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

DEFINE_REX_FUNC(sub_826A61B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x826A61C0;
	__savegprlr_14(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r7,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r7.u64);
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// lwz r26,404(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 404);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r15,12(r4)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// li r17,1
	ctx.r17.s64 = 1;
	// lwz r16,16(r4)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// cmpwi cr6,r26,6
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 6, ctx.xer);
	// lwz r24,4(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// std r8,408(r1)
	REX_STORE_U64(ctx.r1.u32 + 408, ctx.r8.u64);
	// beq cr6,0x826a6220
	if (ctx.cr6.eq) goto loc_826A6220;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826a6218
	if (ctx.cr6.eq) goto loc_826A6218;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,32000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32000, ctx.xer);
	// blt cr6,0x826a6218
	if (ctx.cr6.lt) goto loc_826A6218;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,44100
	ctx.r9.u64 = ctx.r10.u64 | 44100;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x826a6220
	if (ctx.cr6.lt) goto loc_826A6220;
loc_826A6218:
	// li r14,0
	ctx.r14.s64 = 0;
	// b 0x826a6224
	goto loc_826A6224;
loc_826A6220:
	// mr r14,r17
	ctx.r14.u64 = ctx.r17.u64;
loc_826A6224:
	// lwz r11,400(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 400);
	// li r27,0
	ctx.r27.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// bne cr6,0x826a625c
	if (!ctx.cr6.eq) goto loc_826A625C;
	// lhz r10,118(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 118);
	// lwz r9,276(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 276);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// lwz r7,256(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// slw r6,r8,r26
	ctx.r6.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r26.u8 & 0x3F));
	// srawi r4,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 6;
	// mullw r10,r4,r9
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// divw r22,r10,r7
	ctx.r22.u64 = uint32_t((ctx.r7.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r10.s32 / ctx.r7.s32 : 0);
	// b 0x826a6260
	goto loc_826A6260;
loc_826A625C:
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826A6260:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r19,404(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 404);
	// lwz r20,268(r3)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// add r18,r11,r15
	ctx.r18.u64 = ctx.r11.u64 + ctx.r15.u64;
	// add r21,r10,r5
	ctx.r21.u64 = ctx.r10.u64 + ctx.r5.u64;
loc_826A6274:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmpw cr6,r11,r19
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r19.s32, ctx.xer);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// bgt cr6,0x826a6288
	if (ctx.cr6.gt) goto loc_826A6288;
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
loc_826A6288:
	// cmpw cr6,r29,r20
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r20.s32, ctx.xer);
	// bge cr6,0x826a6458
	if (!ctx.cr6.lt) goto loc_826A6458;
	// lbz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x826a644c
	if (!ctx.cr6.eq) goto loc_826A644C;
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// slw r9,r29,r26
	ctx.r9.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r26.u8 & 0x3F));
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r11,r9,6
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 6;
	// add r10,r10,r23
	ctx.r10.u64 = ctx.r10.u64 + ctx.r23.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x826a62cc
	if (ctx.cr6.gt) goto loc_826A62CC;
loc_826A62BC:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x826a62bc
	if (!ctx.cr6.gt) goto loc_826A62BC;
loc_826A62CC:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// beq cr6,0x826a62ec
	if (ctx.cr6.eq) goto loc_826A62EC;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r25,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x3FC;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lwzx r7,r10,r24
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// stwx r7,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x826a6440
	goto loc_826A6440;
loc_826A62EC:
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826a6300
	if (ctx.cr6.lt) goto loc_826A6300;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_826A6300:
	// rlwinm r7,r28,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r7,r23
	ctx.r11.u64 = ctx.r7.u64 + ctx.r23.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// blt cr6,0x826a631c
	if (ctx.cr6.lt) goto loc_826A631C;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
loc_826A631C:
	// slw r11,r30,r26
	ctx.r11.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r26.u8 & 0x3F));
	// srawi r11,r11,6
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 6;
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// blt cr6,0x826a6330
	if (ctx.cr6.lt) goto loc_826A6330;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_826A6330:
	// addi r9,r27,1
	ctx.r9.s64 = ctx.r27.s64 + 1;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x826a635c
	if (ctx.cr6.gt) goto loc_826A635C;
loc_826A634C:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826a634c
	if (!ctx.cr6.gt) goto loc_826A634C;
loc_826A635C:
	// cmpw cr6,r27,r28
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x826a6380
	if (!ctx.cr6.eq) goto loc_826A6380;
	// lwzx r3,r7,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r24.u32);
	// bl 0x826a6070
	ctx.lr = 0x826A636C;
	sub_826A6070(ctx, base);
	// rlwinm r10,r25,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x3FC;
	// fmuls f0,f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfsx f0,r10,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// b 0x826a6440
	goto loc_826A6440;
loc_826A6380:
	// cmpwi cr6,r26,6
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 6, ctx.xer);
	// ble cr6,0x826a63a0
	if (!ctx.cr6.gt) goto loc_826A63A0;
	// addi r11,r26,-7
	ctx.r11.s64 = ctx.r26.s64 + -7;
	// addi r10,r26,-6
	ctx.r10.s64 = ctx.r26.s64 + -6;
	// slw r11,r17,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r11.u8 & 0x3F));
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sraw r31,r9,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r31.s64 = ctx.r9.s32 >> temp.u32;
	// b 0x826a63a8
	goto loc_826A63A8;
loc_826A63A0:
	// subfic r11,r26,6
	ctx.xer.ca = ctx.r26.u32 <= 6;
	ctx.r11.u64 = static_cast<uint64_t>(6) - ctx.r26.u64;
	// slw r31,r8,r11
	ctx.r31.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
loc_826A63A8:
	// lwzx r3,r7,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r24.u32);
	// bl 0x826a6070
	ctx.lr = 0x826A63B0;
	sub_826A6070(ctx, base);
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f1.f64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x826a6070
	ctx.lr = 0x826A63C0;
	sub_826A6070(ctx, base);
	// extsw r6,r31
	ctx.r6.s64 = ctx.r31.s32;
	// fmuls f9,f10,f10
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// subf r9,r29,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r29.u64;
	// fmuls f12,f1,f1
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// std r6,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f5,104(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// extsw r7,r29
	ctx.r7.s64 = ctx.r29.s32;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f7,88(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f6,96(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// rlwinm r5,r25,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x3FC;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f8
	ctx.f3.f64 = double(ctx.f8.s64);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fcfid f0,f7
	ctx.f0.f64 = double(ctx.f7.s64);
	// fcfid f13,f6
	ctx.f13.f64 = double(ctx.f6.s64);
	// frsp f11,f3
	ctx.f11.f64 = double(float(ctx.f3.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// frsp f8,f13
	ctx.f8.f64 = double(float(ctx.f13.f64));
	// fsubs f7,f11,f2
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f2.f64));
	// fsubs f6,f2,f8
	ctx.f6.f64 = double(float(ctx.f2.f64 - ctx.f8.f64));
	// fdivs f5,f7,f10
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f10.f64));
	// fdivs f4,f6,f10
	ctx.f4.f64 = double(float(ctx.f6.f64 / ctx.f10.f64));
	// fmuls f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fmadds f2,f4,f9,f3
	ctx.f2.f64 = double(float(std::fma(ctx.f4.f64, ctx.f9.f64, ctx.f3.f64)));
	// stfsx f2,r5,r4
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r5.u32 + ctx.r4.u32, temp.u32);
loc_826A6440:
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r25,r11,24
	ctx.r25.u64 = ctx.r11.u32 & 0xFF;
loc_826A644C:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r21,r21,4
	ctx.r21.s64 = ctx.r21.s64 + 4;
	// b 0x826a6274
	goto loc_826A6274;
loc_826A6458:
	// clrlwi r28,r25,24
	ctx.r28.u64 = ctx.r25.u32 & 0xFF;
	// addic. r11,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r11.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x826a64c8
	if (!ctx.cr0.gt) goto loc_826A64C8;
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_826A6470:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// beq cr6,0x826a649c
	if (ctx.cr6.eq) goto loc_826A649C;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwzx r8,r31,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// lwz r7,-4(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// subf r3,r7,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r7.u64;
	// bl 0x826a6070
	ctx.lr = 0x826A6494;
	sub_826A6070(ctx, base);
	// stfsx f1,r31,r16
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r16.u32, temp.u32);
	// b 0x826a64bc
	goto loc_826A64BC;
loc_826A649C:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lfsx f0,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// stfsx f11,r31,r16
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r16.u32, temp.u32);
loc_826A64BC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x826a6470
	if (!ctx.cr0.eq) goto loc_826A6470;
loc_826A64C8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x826a64e4
	if (ctx.cr6.eq) goto loc_826A64E4;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r9,r11,r16
	ctx.r9.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lfs f0,5864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
loc_826A64E4:
	// stb r25,0(r15)
	REX_STORE_U8(ctx.r15.u32 + 0, ctx.r25.u8);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C2BE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x826C2BE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826c2c0c
	if (!ctx.cr6.eq) goto loc_826C2C0C;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
loc_826C2C0C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c2c24
	if (ctx.cr6.eq) goto loc_826C2C24;
	// li r3,13
	ctx.r3.s64 = 13;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
loc_826C2C24:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bc408
	ctx.lr = 0x826C2C2C;
	sub_826BC408(ctx, base);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x826c2c3c
	if (ctx.cr6.eq) goto loc_826C2C3C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826c2c44
	if (!ctx.cr6.eq) goto loc_826C2C44;
loc_826C2C3C:
	// rlwinm r11,r30,0,20,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFF0;
	// ori r30,r11,15
	ctx.r30.u64 = ctx.r11.u64 | 15;
loc_826C2C44:
	// lwz r11,15332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15332);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r30,15588(r31)
	REX_STORE_U32(ctx.r31.u32 + 15588, ctx.r30.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826c2c64
	if (!ctx.cr6.eq) goto loc_826C2C64;
	// lwz r11,15400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c2c8c
	if (ctx.cr6.eq) goto loc_826C2C8C;
loc_826C2C64:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,15344(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r6,15340(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826be788
	ctx.lr = 0x826C2C84;
	sub_826BE788(ctx, base);
	// sth r28,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r28.u16);
	// b 0x826c2c9c
	goto loc_826C2C9C;
loc_826C2C8C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c27c0
	ctx.lr = 0x826C2C9C;
	sub_826C27C0(ctx, base);
loc_826C2C9C:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x826c2cac
	if (!ctx.cr6.eq) goto loc_826C2CAC;
	// stw r28,3700(r31)
	REX_STORE_U32(ctx.r31.u32 + 3700, ctx.r28.u32);
loc_826C2CAC:
	// lwz r11,3704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3704);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c2cc4
	if (ctx.cr6.eq) goto loc_826C2CC4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,3700(r31)
	REX_STORE_U32(ctx.r31.u32 + 3700, ctx.r28.u32);
	// stw r11,3704(r31)
	REX_STORE_U32(ctx.r31.u32 + 3704, ctx.r11.u32);
loc_826C2CC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bc468
	ctx.lr = 0x826C2CCC;
	sub_826BC468(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826DA7A0) {
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
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,21884(r3)
	REX_STORE_U32(ctx.r3.u32 + 21884, ctx.r30.u32);
	// stw r30,3452(r3)
	REX_STORE_U32(ctx.r3.u32 + 3452, ctx.r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,3464(r3)
	REX_STORE_U32(ctx.r3.u32 + 3464, ctx.r30.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,3460(r3)
	REX_STORE_U32(ctx.r3.u32 + 3460, ctx.r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r30,21768(r3)
	REX_STORE_U32(ctx.r3.u32 + 21768, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,22092(r3)
	REX_STORE_U32(ctx.r3.u32 + 22092, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,21900(r3)
	REX_STORE_U32(ctx.r3.u32 + 21900, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,3472(r3)
	REX_STORE_U32(ctx.r3.u32 + 3472, ctx.r30.u32);
	// stw r10,21800(r3)
	REX_STORE_U32(ctx.r3.u32 + 21800, ctx.r10.u32);
	// stw r30,404(r3)
	REX_STORE_U32(ctx.r3.u32 + 404, ctx.r30.u32);
	// stw r30,21888(r3)
	REX_STORE_U32(ctx.r3.u32 + 21888, ctx.r30.u32);
	// stw r30,21896(r3)
	REX_STORE_U32(ctx.r3.u32 + 21896, ctx.r30.u32);
	// stw r30,21892(r3)
	REX_STORE_U32(ctx.r3.u32 + 21892, ctx.r30.u32);
	// stw r30,3988(r3)
	REX_STORE_U32(ctx.r3.u32 + 3988, ctx.r30.u32);
	// stw r30,22008(r3)
	REX_STORE_U32(ctx.r3.u32 + 22008, ctx.r30.u32);
	// stw r30,336(r3)
	REX_STORE_U32(ctx.r3.u32 + 336, ctx.r30.u32);
	// stw r30,328(r3)
	REX_STORE_U32(ctx.r3.u32 + 328, ctx.r30.u32);
	// stw r30,3696(r3)
	REX_STORE_U32(ctx.r3.u32 + 3696, ctx.r30.u32);
	// stw r30,3692(r3)
	REX_STORE_U32(ctx.r3.u32 + 3692, ctx.r30.u32);
	// bl 0x826c7d08
	ctx.lr = 0x826DA828;
	sub_826C7D08(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826da874
	if (!ctx.cr6.eq) goto loc_826DA874;
	// lwz r10,22284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22284);
	// lwz r11,22280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22280);
	// lwz r9,22104(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 22104);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// stw r30,3700(r31)
	REX_STORE_U32(ctx.r31.u32 + 3700, ctx.r30.u32);
	// stw r30,22164(r31)
	REX_STORE_U32(ctx.r31.u32 + 22164, ctx.r30.u32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x826da870
	if (ctx.cr6.gt) goto loc_826DA870;
	// lwz r9,22120(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 22120);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x826da870
	if (ctx.cr6.gt) goto loc_826DA870;
	// lwz r11,22124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22124);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x826da870
	if (ctx.cr6.gt) goto loc_826DA870;
	// stw r30,22108(r31)
	REX_STORE_U32(ctx.r31.u32 + 22108, ctx.r30.u32);
	// b 0x826da874
	goto loc_826DA874;
loc_826DA870:
	// li r3,14
	ctx.r3.s64 = 14;
loc_826DA874:
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

DEFINE_REX_FUNC(sub_826E1400) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x826E1408;
	__savegprlr_23(ctx, base);
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r7,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// mulli r10,r10,34
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(34));
	// lbzx r9,r11,r4
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// lbz r29,0(r8)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// rotlwi r31,r9,1
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// add r30,r7,r30
	ctx.r30.u64 = ctx.r7.u64 + ctx.r30.u64;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// rlwinm r31,r30,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r9,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// addi r24,r6,-4
	ctx.r24.s64 = ctx.r6.s64 + -4;
	// add r30,r9,r29
	ctx.r30.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r9,r31,r4
	ctx.r9.u64 = ctx.r31.u64 + ctx.r4.u64;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// add r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 + ctx.r4.u64;
	// srawi r31,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 5;
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// stw r31,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r31.u32);
	// lbz r31,0(r4)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// lbzx r29,r11,r4
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// rotlwi r28,r29,3
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r29.u32, 3);
	// mulli r30,r31,25
	ctx.r30.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(25));
	// subf r31,r29,r28
	ctx.r31.u64 = ctx.r28.u64 - ctx.r29.u64;
	// add r31,r30,r31
	ctx.r31.u64 = ctx.r30.u64 + ctx.r31.u64;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// srawi r31,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 5;
	// stw r31,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r31.u32);
	// lbz r31,0(r8)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbzx r28,r11,r4
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// lbz r29,0(r9)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r30,0(r4)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// rotlwi r30,r30,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// subf r31,r31,r30
	ctx.r31.u64 = ctx.r30.u64 - ctx.r31.u64;
	// rotlwi r27,r28,3
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r28.u32, 3);
	// rlwinm r30,r31,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r28,r27
	ctx.r28.u64 = ctx.r27.u64 - ctx.r28.u64;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// rlwinm r31,r28,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r30,r31
	ctx.r31.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r31,r31,r29
	ctx.r31.u64 = ctx.r31.u64 + ctx.r29.u64;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// srawi r31,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 5;
	// stw r31,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r31.u32);
	// lbz r31,0(r8)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r28,0(r4)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// lbzx r30,r11,r4
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// rotlwi r27,r30,3
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r30.u32, 3);
	// rotlwi r29,r31,1
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// subf r30,r30,r27
	ctx.r30.u64 = ctx.r27.u64 - ctx.r30.u64;
	// add r31,r31,r29
	ctx.r31.u64 = ctx.r31.u64 + ctx.r29.u64;
	// rlwinm r30,r30,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r31,r31,r30
	ctx.r31.u64 = ctx.r31.u64 + ctx.r30.u64;
	// subf r31,r28,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r28.u64;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r31,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 5;
	// stw r31,12(r5)
	REX_STORE_U32(ctx.r5.u32 + 12, ctx.r31.u32);
	// ble cr6,0x826e15b0
	if (!ctx.cr6.gt) goto loc_826E15B0;
	// addi r31,r24,-5
	ctx.r31.s64 = ctx.r24.s64 + -5;
	// rlwinm r30,r7,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r31,r31,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r29,r11,r30
	ctx.r29.u64 = ctx.r30.u64 - ctx.r11.u64;
	// addi r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 1;
	// addi r31,r5,12
	ctx.r31.s64 = ctx.r5.s64 + 12;
	// subf r28,r11,r4
	ctx.r28.u64 = ctx.r4.u64 - ctx.r11.u64;
	// add r29,r29,r4
	ctx.r29.u64 = ctx.r29.u64 + ctx.r4.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
loc_826E1520:
	// lbz r30,0(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r26,0(r8)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// rotlwi r30,r30,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// lbz r25,0(r9)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// rotlwi r23,r26,3
	ctx.r23.u64 = __builtin_rotateleft32(ctx.r26.u32, 3);
	// lbzux r27,r29,r11
	ea = ctx.r29.u32 + ctx.r11.u32;
	ctx.r27.u64 = REX_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// subf r30,r25,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r25.u64;
	// subf r26,r26,r23
	ctx.r26.u64 = ctx.r23.u64 - ctx.r26.u64;
	// rlwinm r25,r30,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r26,r26,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r25
	ctx.r30.u64 = ctx.r30.u64 + ctx.r25.u64;
	// add r30,r30,r26
	ctx.r30.u64 = ctx.r30.u64 + ctx.r26.u64;
	// add r30,r30,r27
	ctx.r30.u64 = ctx.r30.u64 + ctx.r27.u64;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// srawi r30,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 5;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// lbz r25,0(r8)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbzux r27,r28,r11
	ea = ctx.r28.u32 + ctx.r11.u32;
	ctx.r27.u64 = REX_LOAD_U8(ea);
	ctx.r28.u32 = ea;
	// lbz r26,0(r9)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// rotlwi r26,r26,1
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r26.u32, 1);
	// lbz r30,0(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r23,r25,3
	ctx.r23.u64 = __builtin_rotateleft32(ctx.r25.u32, 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r30,r30,r26
	ctx.r30.u64 = ctx.r26.u64 - ctx.r30.u64;
	// subf r25,r25,r23
	ctx.r25.u64 = ctx.r23.u64 - ctx.r25.u64;
	// rlwinm r26,r30,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r30,r30,r26
	ctx.r30.u64 = ctx.r30.u64 + ctx.r26.u64;
	// rlwinm r26,r25,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r26
	ctx.r30.u64 = ctx.r30.u64 + ctx.r26.u64;
	// add r30,r30,r27
	ctx.r30.u64 = ctx.r30.u64 + ctx.r27.u64;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// srawi r30,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 5;
	// stwu r30,8(r31)
	ea = 8 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r31.u32 = ea;
	// bdnz 0x826e1520
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E1520;
loc_826E15B0:
	// addi r11,r6,-6
	ctx.r11.s64 = ctx.r6.s64 + -6;
	// mullw r10,r24,r7
	ctx.r10.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r7.s32);
	// lbzx r29,r10,r4
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// mullw r9,r11,r7
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// lbzx r31,r9,r4
	ctx.r31.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// rotlwi r28,r29,3
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r29.u32, 3);
	// addi r8,r6,-2
	ctx.r8.s64 = ctx.r6.s64 + -2;
	// rotlwi r30,r31,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// mullw r11,r8,r7
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// lbzx r27,r11,r4
	ctx.r27.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// subf r29,r29,r28
	ctx.r29.u64 = ctx.r28.u64 - ctx.r29.u64;
	// add r31,r31,r30
	ctx.r31.u64 = ctx.r31.u64 + ctx.r30.u64;
	// rlwinm r30,r29,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r24,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r31,r30
	ctx.r31.u64 = ctx.r31.u64 + ctx.r30.u64;
	// addi r30,r6,-8
	ctx.r30.s64 = ctx.r6.s64 + -8;
	// subf r31,r27,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r27.u64;
	// mullw r30,r30,r7
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r7.s32);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r31,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 5;
	// add r27,r8,r5
	ctx.r27.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stwx r31,r29,r5
	REX_STORE_U32(ctx.r29.u32 + ctx.r5.u32, ctx.r31.u32);
	// addi r8,r6,-3
	ctx.r8.s64 = ctx.r6.s64 + -3;
	// lbzx r31,r10,r4
	ctx.r31.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lbzx r26,r9,r4
	ctx.r26.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// rlwinm r29,r8,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r30,r30,r4
	ctx.r30.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r4.u32);
	// lbzx r8,r11,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r25,r31,3
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r31.u32, 3);
	// subf r8,r26,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r26.u64;
	// subf r26,r31,r25
	ctx.r26.u64 = ctx.r25.u64 - ctx.r31.u64;
	// rlwinm r31,r8,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// rlwinm r31,r26,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// srawi r8,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 5;
	// stwx r8,r29,r5
	REX_STORE_U32(ctx.r29.u32 + ctx.r5.u32, ctx.r8.u32);
	// lbzx r8,r11,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// lbzx r31,r10,r4
	ctx.r31.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// rotlwi r30,r31,3
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r31.u32, 3);
	// mulli r8,r8,25
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(25));
	// subf r31,r31,r30
	ctx.r31.u64 = ctx.r30.u64 - ctx.r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// srawi r8,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 5;
	// stwx r8,r28,r5
	REX_STORE_U32(ctx.r28.u32 + ctx.r5.u32, ctx.r8.u32);
	// lbzx r10,r10,r4
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r9,r9,r4
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// lbzx r11,r11,r4
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// mulli r8,r11,34
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(34));
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// stw r10,-4(r27)
	REX_STORE_U32(ctx.r27.u32 + -4, ctx.r10.u32);
	// ble cr6,0x826e16e4
	if (!ctx.cr6.gt) goto loc_826E16E4;
	// subf r10,r7,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r7.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// li r9,255
	ctx.r9.s64 = 255;
loc_826E16C0:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// ble cr6,0x826e16d8
	if (!ctx.cr6.gt) goto loc_826E16D8;
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
loc_826E16D8:
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// stbux r11,r10,r7
	ea = ctx.r10.u32 + ctx.r7.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826e16c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E16C0;
loc_826E16E4:
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826FFB58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x826FFB60;
	__savegprlr_29(ctx, base);
	// lwz r11,20912(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20912);
	// li r9,71
	ctx.r9.s64 = 71;
	// lwz r6,21892(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 21892);
	// li r10,2
	ctx.r10.s64 = 2;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,21896(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 21896);
	// lwz r7,368(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 368);
	// addic r5,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subfe r5,r5,r6
	temp.u8 = (~ctx.r5.u32 + ctx.r6.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r5.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// rlwinm r11,r3,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addic r9,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r9.s64 = ctx.r4.s64 + -1;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subfe r3,r9,r4
	temp.u8 = (~ctx.r9.u32 + ctx.r4.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r9.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r29,9
	ctx.r29.s64 = 9;
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lis r11,14563
	ctx.r11.s64 = 954400768;
	// lis r30,256
	ctx.r30.s64 = 16777216;
	// ori r31,r11,36409
	ctx.r31.u64 = ctx.r11.u64 | 36409;
loc_826FFBB8:
	// mulhw r11,r10,r31
	ctx.r11.s64 = (int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32)) >> 32;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf. r11,r9,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826ffbf0
	if (ctx.cr0.eq) goto loc_826FFBF0;
	// add r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r7,r11,r5
	ctx.r7.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// slw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r11.u8 & 0x3F));
	// subf r9,r5,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r5.u64;
	// b 0x826ffbf8
	goto loc_826FFBF8;
loc_826FFBF0:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826FFBF8:
	// divw. r11,r10,r29
	ctx.r11.u64 = uint32_t((ctx.r29.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r10.s32 / ctx.r29.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826ffc18
	if (ctx.cr0.eq) goto loc_826FFC18;
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// slw r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r8.u8 & 0x3F));
	// subf r8,r3,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r3.u64;
	// b 0x826ffc20
	goto loc_826FFC20;
loc_826FFC18:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826FFC20:
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// slw r11,r6,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r11.u8 & 0x3F));
	// rlwimi r8,r9,4,0,27
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0) | (ctx.r8.u64 & 0xFFFFFFFF0000000F);
	// rlwinm r9,r11,24,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// rlwinm r8,r8,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r11,r30,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r30.u64;
	// clrlwi r9,r7,28
	ctx.r9.u64 = ctx.r7.u32 & 0xF;
	// or r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 | ctx.r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r4.u32 = ea;
	// bdnz 0x826ffbb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFBB8;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827081E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x827081E8;
	__savegprlr_21(ctx, base);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x82708358
	if (!ctx.cr6.gt) goto loc_82708358;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// addi r27,r3,5
	ctx.r27.s64 = ctx.r3.s64 + 5;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// addi r29,r3,7
	ctx.r29.s64 = ctx.r3.s64 + 7;
	// addi r30,r3,8
	ctx.r30.s64 = ctx.r3.s64 + 8;
	// addi r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 1;
	// addi r6,r3,2
	ctx.r6.s64 = ctx.r3.s64 + 2;
	// addi r26,r3,6
	ctx.r26.s64 = ctx.r3.s64 + 6;
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
loc_82708214:
	// lbz r25,0(r28)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// lbz r24,0(r27)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// subf r9,r24,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r24.u64;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// addze. r23,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r23.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq 0x82708334
	if (ctx.cr0.eq) goto loc_82708334;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r8,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 3;
	// xor r7,r9,r23
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r23.u64;
	// rlwinm r8,r7,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82708334
	if (ctx.cr6.eq) goto loc_82708334;
	// srawi r8,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 31;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// subf r22,r8,r7
	ctx.r22.u64 = ctx.r7.u64 - ctx.r8.u64;
	// cmpw cr6,r22,r5
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x82708334
	if (!ctx.cr6.lt) goto loc_82708334;
	// lbz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// lbz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lbz r21,0(r29)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// subf r9,r25,r8
	ctx.r9.u64 = ctx.r8.u64 - ctx.r25.u64;
	// subf r8,r7,r24
	ctx.r8.u64 = ctx.r24.u64 - ctx.r7.u64;
	// subf r10,r10,r21
	ctx.r10.u64 = ctx.r21.u64 - ctx.r10.u64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r21,r8,2
	ctx.r21.s64 = ctx.r8.s64 + 2;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r21,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 3;
	// srawi r10,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 3;
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// xor r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// xor r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 ^ ctx.r8.u64;
	// subf r11,r9,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r9.u64;
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x827082e8
	if (!ctx.cr6.lt) goto loc_827082E8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_827082E8:
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bge cr6,0x82708334
	if (!ctx.cr6.lt) goto loc_82708334;
	// subf r11,r11,r22
	ctx.r11.u64 = ctx.r22.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// srawi r10,r23,31
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r23.s32 >> 31;
	// xor r9,r23,r10
	ctx.r9.u64 = ctx.r23.u64 ^ ctx.r10.u64;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82708318
	if (ctx.cr6.lt) goto loc_82708318;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82708318:
	// cmpw cr6,r25,r24
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x82708324
	if (!ctx.cr6.lt) goto loc_82708324;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
loc_82708324:
	// subf r10,r11,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r11.u64;
	// add r9,r11,r24
	ctx.r9.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stb r10,0(r28)
	REX_STORE_U8(ctx.r28.u32 + 0, ctx.r10.u8);
	// stb r9,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r9.u8);
loc_82708334:
	// add r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r26,r26,r4
	ctx.r26.u64 = ctx.r26.u64 + ctx.r4.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// add r31,r31,r4
	ctx.r31.u64 = ctx.r31.u64 + ctx.r4.u64;
	// add r30,r30,r4
	ctx.r30.u64 = ctx.r30.u64 + ctx.r4.u64;
	// add r29,r29,r4
	ctx.r29.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r28,r28,r4
	ctx.r28.u64 = ctx.r28.u64 + ctx.r4.u64;
	// add r27,r27,r4
	ctx.r27.u64 = ctx.r27.u64 + ctx.r4.u64;
	// bdnz 0x82708214
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82708214;
loc_82708358:
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8270E030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8270E038;
	__savegprlr_27(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8270e06c
	if (ctx.cr6.eq) goto loc_8270E06C;
	// lwz r7,136(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// lwz r30,1928(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 1928);
	// rlwinm r7,r7,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r31,r7,r5
	ctx.r31.u64 = ctx.r5.u64 - ctx.r7.u64;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_8270E06C:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8270e0e8
	if (ctx.cr6.eq) goto loc_8270E0E8;
	// lwz r30,1924(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 1924);
	// addic. r29,r5,-32
	ctx.xer.ca = ctx.r5.u32 > 31;
	ctx.r29.s64 = ctx.r5.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8270e108
	if (ctx.cr0.eq) goto loc_8270E108;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8270e0e8
	if (ctx.cr6.eq) goto loc_8270E0E8;
	// lwz r7,1920(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 1920);
	// lwz r6,1916(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 1916);
	// addi r5,r7,-16
	ctx.r5.s64 = ctx.r7.s64 + -16;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r6,r29
	ctx.r6.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r29.u32);
	// lhzx r5,r5,r31
	ctx.r5.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r31.u32);
	// lhzx r7,r7,r31
	ctx.r7.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// subf r6,r6,r5
	ctx.r6.u64 = ctx.r5.u64 - ctx.r6.u64;
	// subf r5,r7,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// srawi r27,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 ^ ctx.r27.u64;
	// subf r7,r7,r6
	ctx.r7.u64 = ctx.r6.u64 - ctx.r7.u64;
	// subf r6,r27,r5
	ctx.r6.u64 = ctx.r5.u64 - ctx.r27.u64;
	// cmpw cr6,r7,r6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8270e0e8
	if (!ctx.cr6.lt) goto loc_8270E0E8;
	// lwz r30,1928(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 1928);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_8270E0E8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8270e108
	if (ctx.cr6.eq) goto loc_8270E108;
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r6,r7,0,27,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x18;
	// subfic r5,r6,0
	ctx.xer.ca = ctx.r6.u32 <= 0;
	ctx.r5.u64 = static_cast<uint64_t>(0) - ctx.r6.u64;
	// subfe r7,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r28,r7,r28
	ctx.r28.u64 = ctx.r7.u64 & ctx.r28.u64;
loc_8270E108:
	// stw r29,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x8270e118
	if (!ctx.cr6.eq) goto loc_8270E118;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8270E118:
	// lwz r11,1928(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1928);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82719718) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x82719720;
	__savegprlr_14(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r31,256(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// srawi r27,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r27.s64 = ctx.r11.s32 >> 2;
	// stw r4,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// stw r6,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r6.u32);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r7,52(r1)
	REX_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// stw r8,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r8.u32);
	// stw r9,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r9.u32);
	// stw r30,-480(r1)
	REX_STORE_U32(ctx.r1.u32 + -480, ctx.r30.u32);
	// stw r27,-464(r1)
	REX_STORE_U32(ctx.r1.u32 + -464, ctx.r27.u32);
	// ble cr6,0x8271a340
	if (!ctx.cr6.gt) goto loc_8271A340;
	// lwz r26,116(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// srawi r25,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r25.s64 = ctx.r10.s32 >> 2;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r25,-436(r1)
	REX_STORE_U32(ctx.r1.u32 + -436, ctx.r25.u32);
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r10,-456(r1)
	REX_STORE_U32(ctx.r1.u32 + -456, ctx.r10.u32);
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
loc_82719780:
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8271979c
	if (ctx.cr6.eq) goto loc_8271979C;
	// addi r10,r27,-1
	ctx.r10.s64 = ctx.r27.s64 + -1;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x827197a0
	if (ctx.cr6.eq) goto loc_827197A0;
loc_8271979C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_827197A0:
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r10,-484(r1)
	REX_STORE_U32(ctx.r1.u32 + -484, ctx.r10.u32);
	// stw r4,-488(r1)
	REX_STORE_U32(ctx.r1.u32 + -488, ctx.r4.u32);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// stw r28,-472(r1)
	REX_STORE_U32(ctx.r1.u32 + -472, ctx.r28.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x8271a304
	if (!ctx.cr6.gt) goto loc_8271A304;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r29,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// srawi r27,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r27.s64 = ctx.r26.s32 >> 1;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r26,r8,r4
	ctx.r26.u64 = ctx.r8.u64 + ctx.r4.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r26,-448(r1)
	REX_STORE_U32(ctx.r1.u32 + -448, ctx.r26.u32);
	// add r4,r29,r30
	ctx.r4.u64 = ctx.r29.u64 + ctx.r30.u64;
	// stw r7,-460(r1)
	REX_STORE_U32(ctx.r1.u32 + -460, ctx.r7.u32);
	// rlwinm r30,r27,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r10,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,-424(r1)
	REX_STORE_U32(ctx.r1.u32 + -424, ctx.r4.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,-468(r1)
	REX_STORE_U32(ctx.r1.u32 + -468, ctx.r30.u32);
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r27,-440(r1)
	REX_STORE_U32(ctx.r1.u32 + -440, ctx.r27.u32);
	// stw r10,-432(r1)
	REX_STORE_U32(ctx.r1.u32 + -432, ctx.r10.u32);
	// stw r7,-452(r1)
	REX_STORE_U32(ctx.r1.u32 + -452, ctx.r7.u32);
	// b 0x82719824
	goto loc_82719824;
loc_82719820:
	// lwz r4,-424(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -424);
loc_82719824:
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82719840
	if (ctx.cr6.eq) goto loc_82719840;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82719844
	if (ctx.cr6.eq) goto loc_82719844;
loc_82719840:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82719844:
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r30,-500(r1)
	REX_STORE_U32(ctx.r1.u32 + -500, ctx.r30.u32);
	// addi r10,r1,-529
	ctx.r10.s64 = ctx.r1.s64 + -529;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82719854:
	// lbz r7,0(r5)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r5.u32 + 0);
	// lbz r6,1(r5)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r5.u32 + 1);
	// lbz r28,2(r5)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r5.u32 + 2);
	// lbz r27,3(r5)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r5.u32 + 3);
	// lbz r26,4(r5)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r5.u32 + 4);
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// stb r7,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// stb r6,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r6.u8);
	// stb r28,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r28.u8);
	// stb r27,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r27.u8);
	// stbu r26,5(r10)
	ea = 5 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r26.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82719854
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82719854;
	// lwz r8,-448(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -448);
	// li r6,3
	ctx.r6.s64 = 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r7,r8,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r8.u64;
	// addi r8,r1,-544
	ctx.r8.s64 = ctx.r1.s64 + -544;
	// stw r7,-428(r1)
	REX_STORE_U32(ctx.r1.u32 + -428, ctx.r7.u32);
	// addi r7,r1,-560
	ctx.r7.s64 = ctx.r1.s64 + -560;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// addi r6,r1,-543
	ctx.r6.s64 = ctx.r1.s64 + -543;
loc_827198A8:
	// lbz r5,0(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// addi r28,r1,-559
	ctx.r28.s64 = ctx.r1.s64 + -559;
	// lbz r27,0(r3)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r26,r1,-542
	ctx.r26.s64 = ctx.r1.s64 + -542;
	// lbz r25,1(r9)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// addi r24,r1,-558
	ctx.r24.s64 = ctx.r1.s64 + -558;
	// lbz r23,1(r3)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r22,2(r9)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// lbz r21,2(r3)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + ctx.r29.u64;
	// stbx r5,r10,r8
	REX_STORE_U8(ctx.r10.u32 + ctx.r8.u32, ctx.r5.u8);
	// stbx r27,r10,r7
	REX_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r27.u8);
	// stbx r25,r10,r6
	REX_STORE_U8(ctx.r10.u32 + ctx.r6.u32, ctx.r25.u8);
	// stbx r23,r10,r28
	REX_STORE_U8(ctx.r10.u32 + ctx.r28.u32, ctx.r23.u8);
	// stbx r22,r10,r26
	REX_STORE_U8(ctx.r10.u32 + ctx.r26.u32, ctx.r22.u8);
	// stbx r21,r10,r24
	REX_STORE_U8(ctx.r10.u32 + ctx.r24.u32, ctx.r21.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// bdnz 0x827198a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827198A8;
	// subf r9,r4,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r4.u64;
	// lbz r10,-510(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -510);
	// subf r8,r4,r3
	ctx.r8.u64 = ctx.r3.u64 - ctx.r4.u64;
	// lbz r7,-540(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -540);
	// lbz r6,-556(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -556);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r9,-444(r1)
	REX_STORE_U32(ctx.r1.u32 + -444, ctx.r9.u32);
	// stw r8,-420(r1)
	REX_STORE_U32(ctx.r1.u32 + -420, ctx.r8.u32);
	// beq cr6,0x82719964
	if (ctx.cr6.eq) goto loc_82719964;
	// lbz r9,-525(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -525);
	// lbz r8,-520(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -520);
	// lbz r5,-515(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -515);
	// lbz r4,-505(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -505);
	// lbz r3,-543(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + -543);
	// lbz r30,-559(r1)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r1.u32 + -559);
	// lbz r29,-537(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + -537);
	// lbz r28,-553(r1)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r1.u32 + -553);
	// stb r9,-524(r1)
	REX_STORE_U8(ctx.r1.u32 + -524, ctx.r9.u8);
	// stb r8,-519(r1)
	REX_STORE_U8(ctx.r1.u32 + -519, ctx.r8.u8);
	// stb r5,-514(r1)
	REX_STORE_U8(ctx.r1.u32 + -514, ctx.r5.u8);
	// stb r10,-509(r1)
	REX_STORE_U8(ctx.r1.u32 + -509, ctx.r10.u8);
	// stb r4,-504(r1)
	REX_STORE_U8(ctx.r1.u32 + -504, ctx.r4.u8);
	// stb r3,-542(r1)
	REX_STORE_U8(ctx.r1.u32 + -542, ctx.r3.u8);
	// stb r30,-558(r1)
	REX_STORE_U8(ctx.r1.u32 + -558, ctx.r30.u8);
	// stb r7,-539(r1)
	REX_STORE_U8(ctx.r1.u32 + -539, ctx.r7.u8);
	// stb r6,-555(r1)
	REX_STORE_U8(ctx.r1.u32 + -555, ctx.r6.u8);
	// stb r29,-536(r1)
	REX_STORE_U8(ctx.r1.u32 + -536, ctx.r29.u8);
	// stb r28,-552(r1)
	REX_STORE_U8(ctx.r1.u32 + -552, ctx.r28.u8);
loc_82719964:
	// lwz r5,-484(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -484);
	// lbz r9,-511(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -511);
	// lbz r8,-512(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -512);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lbz r22,-513(r1)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r1.u32 + -513);
	// beq cr6,0x827199bc
	if (ctx.cr6.eq) goto loc_827199BC;
	// lbz r5,-509(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -509);
	// lbz r4,-541(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -541);
	// lbz r3,-557(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + -557);
	// lbz r30,-539(r1)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r1.u32 + -539);
	// lbz r29,-555(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + -555);
	// stb r22,-508(r1)
	REX_STORE_U8(ctx.r1.u32 + -508, ctx.r22.u8);
	// stb r8,-507(r1)
	REX_STORE_U8(ctx.r1.u32 + -507, ctx.r8.u8);
	// stb r9,-506(r1)
	REX_STORE_U8(ctx.r1.u32 + -506, ctx.r9.u8);
	// stb r10,-505(r1)
	REX_STORE_U8(ctx.r1.u32 + -505, ctx.r10.u8);
	// stb r5,-504(r1)
	REX_STORE_U8(ctx.r1.u32 + -504, ctx.r5.u8);
	// stb r4,-538(r1)
	REX_STORE_U8(ctx.r1.u32 + -538, ctx.r4.u8);
	// stb r3,-554(r1)
	REX_STORE_U8(ctx.r1.u32 + -554, ctx.r3.u8);
	// stb r7,-537(r1)
	REX_STORE_U8(ctx.r1.u32 + -537, ctx.r7.u8);
	// stb r6,-553(r1)
	REX_STORE_U8(ctx.r1.u32 + -553, ctx.r6.u8);
	// stb r30,-536(r1)
	REX_STORE_U8(ctx.r1.u32 + -536, ctx.r30.u8);
	// stb r29,-552(r1)
	REX_STORE_U8(ctx.r1.u32 + -552, ctx.r29.u8);
loc_827199BC:
	// lbz r10,-522(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -522);
	// rlwinm r28,r8,1,23,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1FE;
	// lbz r24,-517(r1)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r1.u32 + -517);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lbz r23,-521(r1)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r1.u32 + -521);
	// lbz r25,-523(r1)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r1.u32 + -523);
	// clrlwi r21,r22,24
	ctx.r21.u64 = ctx.r22.u32 & 0xFF;
	// add r30,r24,r10
	ctx.r30.u64 = ctx.r24.u64 + ctx.r10.u64;
	// lbz r7,-516(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -516);
	// lbz r26,-527(r1)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r1.u32 + -527);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// add r9,r30,r23
	ctx.r9.u64 = ctx.r30.u64 + ctx.r23.u64;
	// lbz r6,-526(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -526);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// lbz r17,-528(r1)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r1.u32 + -528);
	// add r20,r10,r25
	ctx.r20.u64 = ctx.r10.u64 + ctx.r25.u64;
	// lbz r18,-518(r1)
	ctx.r18.u64 = REX_LOAD_U8(ctx.r1.u32 + -518);
	// add r14,r30,r25
	ctx.r14.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// rotlwi r25,r25,1
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r25.u32, 1);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// add r6,r9,r29
	ctx.r6.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r9,r25,r17
	ctx.r9.u64 = ctx.r25.u64 + ctx.r17.u64;
	// add r5,r20,r26
	ctx.r5.u64 = ctx.r20.u64 + ctx.r26.u64;
	// stw r9,-496(r1)
	REX_STORE_U32(ctx.r1.u32 + -496, ctx.r9.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// add r20,r28,r21
	ctx.r20.u64 = ctx.r28.u64 + ctx.r21.u64;
	// add r19,r8,r28
	ctx.r19.u64 = ctx.r8.u64 + ctx.r28.u64;
	// rlwinm r22,r22,1,23,30
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0x1FE;
	// rlwinm r16,r5,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r20,r3
	ctx.r7.u64 = ctx.r20.u64 + ctx.r3.u64;
	// add r5,r19,r3
	ctx.r5.u64 = ctx.r19.u64 + ctx.r3.u64;
	// add r3,r22,r18
	ctx.r3.u64 = ctx.r22.u64 + ctx.r18.u64;
	// add r10,r23,r10
	ctx.r10.u64 = ctx.r23.u64 + ctx.r10.u64;
	// stw r3,-492(r1)
	REX_STORE_U32(ctx.r1.u32 + -492, ctx.r3.u32);
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r26
	ctx.r4.u64 = ctx.r10.u64 + ctx.r26.u64;
	// rotlwi r26,r26,1
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r26.u32, 1);
	// rlwinm r15,r4,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r26,r17
	ctx.r4.u64 = ctx.r26.u64 + ctx.r17.u64;
	// rotlwi r7,r17,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r17.u32, 8);
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// add r26,r27,r26
	ctx.r26.u64 = ctx.r27.u64 + ctx.r26.u64;
	// stw r7,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r7.u32);
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r5,r4,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(85));
	// lwz r7,-496(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -496);
	// stw r5,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r5.u32);
	// add r30,r16,r30
	ctx.r30.u64 = ctx.r16.u64 + ctx.r30.u64;
	// mulli r4,r26,85
	ctx.r4.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(85));
	// stw r4,-312(r1)
	REX_STORE_U32(ctx.r1.u32 + -312, ctx.r4.u32);
	// add r16,r15,r27
	ctx.r16.u64 = ctx.r15.u64 + ctx.r27.u64;
	// rlwinm r14,r14,1,0,30
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r5,r7,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(85));
	// stw r5,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r5.u32);
	// mulli r4,r30,28
	ctx.r4.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(28));
	// stw r4,-292(r1)
	REX_STORE_U32(ctx.r1.u32 + -292, ctx.r4.u32);
	// mulli r7,r16,28
	ctx.r7.s64 = static_cast<int64_t>(ctx.r16.u64 * static_cast<uint64_t>(28));
	// stw r7,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r7.u32);
	// rotlwi r24,r24,1
	ctx.r24.u64 = __builtin_rotateleft32(ctx.r24.u32, 1);
	// add r15,r14,r18
	ctx.r15.u64 = ctx.r14.u64 + ctx.r18.u64;
	// add r25,r18,r25
	ctx.r25.u64 = ctx.r18.u64 + ctx.r25.u64;
	// mulli r7,r6,28
	ctx.r7.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(28));
	// stw r7,-264(r1)
	REX_STORE_U32(ctx.r1.u32 + -264, ctx.r7.u32);
	// lwz r7,-492(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -492);
	// add r14,r24,r18
	ctx.r14.u64 = ctx.r24.u64 + ctx.r18.u64;
	// mulli r5,r25,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r25.u64 * static_cast<uint64_t>(85));
	// stw r5,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r5.u32);
	// mulli r4,r15,28
	ctx.r4.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(28));
	// stw r4,-268(r1)
	REX_STORE_U32(ctx.r1.u32 + -268, ctx.r4.u32);
	// add r24,r24,r29
	ctx.r24.u64 = ctx.r24.u64 + ctx.r29.u64;
	// rotlwi r6,r18,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r18.u32, 8);
	// mulli r5,r14,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r14.u64 * static_cast<uint64_t>(85));
	// stw r6,-248(r1)
	REX_STORE_U32(ctx.r1.u32 + -248, ctx.r6.u32);
	// stw r5,-244(r1)
	REX_STORE_U32(ctx.r1.u32 + -244, ctx.r5.u32);
	// mulli r4,r24,85
	ctx.r4.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(85));
	// stw r4,-240(r1)
	REX_STORE_U32(ctx.r1.u32 + -240, ctx.r4.u32);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// mulli r6,r7,85
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(85));
	// add r4,r3,r29
	ctx.r4.u64 = ctx.r3.u64 + ctx.r29.u64;
	// lwz r26,-484(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -484);
	// add r5,r9,r18
	ctx.r5.u64 = ctx.r9.u64 + ctx.r18.u64;
	// stw r6,-224(r1)
	REX_STORE_U32(ctx.r1.u32 + -224, ctx.r6.u32);
	// mulli r10,r4,28
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(28));
	// stw r10,-216(r1)
	REX_STORE_U32(ctx.r1.u32 + -216, ctx.r10.u32);
	// mulli r3,r5,28
	ctx.r3.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// stw r3,-220(r1)
	REX_STORE_U32(ctx.r1.u32 + -220, ctx.r3.u32);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82719b44
	if (ctx.cr6.eq) goto loc_82719B44;
	// rlwinm r10,r21,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 8) & 0xFFFFFF00;
	// mulli r9,r20,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r20.u64 * static_cast<uint64_t>(85));
	// stw r10,-200(r1)
	REX_STORE_U32(ctx.r1.u32 + -200, ctx.r10.u32);
	// stw r9,-196(r1)
	REX_STORE_U32(ctx.r1.u32 + -196, ctx.r9.u32);
	// mulli r7,r19,85
	ctx.r7.s64 = static_cast<int64_t>(ctx.r19.u64 * static_cast<uint64_t>(85));
	// stw r7,-192(r1)
	REX_STORE_U32(ctx.r1.u32 + -192, ctx.r7.u32);
	// b 0x82719b88
	goto loc_82719B88;
loc_82719B44:
	// lbz r10,-507(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -507);
	// lbz r9,-508(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -508);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lbz r7,-506(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -506);
	// add r4,r9,r22
	ctx.r4.u64 = ctx.r9.u64 + ctx.r22.u64;
	// add r5,r10,r21
	ctx.r5.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r6,r7
	ctx.r10.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mulli r9,r4,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(85));
	// stw r9,-200(r1)
	REX_STORE_U32(ctx.r1.u32 + -200, ctx.r9.u32);
	// mulli r7,r3,28
	ctx.r7.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(28));
	// stw r7,-196(r1)
	REX_STORE_U32(ctx.r1.u32 + -196, ctx.r7.u32);
	// mulli r6,r10,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(28));
	// stw r6,-192(r1)
	REX_STORE_U32(ctx.r1.u32 + -192, ctx.r6.u32);
loc_82719B88:
	// lbz r9,-525(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -525);
	// rlwinm r7,r27,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r30,-500(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -500);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// stw r7,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r7.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r6,r10,r27
	ctx.r6.u64 = ctx.r10.u64 + ctx.r27.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-304(r1)
	REX_STORE_U32(ctx.r1.u32 + -304, ctx.r5.u32);
	// beq cr6,0x82719bbc
	if (ctx.cr6.eq) goto loc_82719BBC;
	// rlwinm r10,r9,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r10.u32);
	// b 0x82719bcc
	goto loc_82719BCC;
loc_82719BBC:
	// lbz r7,-524(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -524);
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r5.u32);
loc_82719BCC:
	// lbz r10,-520(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -520);
	// rlwinm r6,r23,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r5,r6,r27
	ctx.r5.u64 = ctx.r6.u64 + ctx.r27.u64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mulli r4,r5,85
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(85));
	// stw r4,-284(r1)
	REX_STORE_U32(ctx.r1.u32 + -284, ctx.r4.u32);
	// add r3,r7,r23
	ctx.r3.u64 = ctx.r7.u64 + ctx.r23.u64;
	// rlwinm r5,r3,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 + ctx.r27.u64;
	// mulli r4,r5,28
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// stw r4,-280(r1)
	REX_STORE_U32(ctx.r1.u32 + -280, ctx.r4.u32);
	// beq cr6,0x82719c10
	if (ctx.cr6.eq) goto loc_82719C10;
	// mulli r9,r7,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(85));
	// stw r9,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r9.u32);
	// b 0x82719c30
	goto loc_82719C30;
loc_82719C10:
	// lbz r5,-519(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -519);
	// lbz r4,-524(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -524);
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r3,r5,r9
	ctx.r3.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// mulli r7,r9,28
	ctx.r7.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(28));
	// stw r7,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r7.u32);
loc_82719C30:
	// lbz r9,-515(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -515);
	// add r7,r6,r29
	ctx.r7.u64 = ctx.r6.u64 + ctx.r29.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mulli r6,r7,85
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(85));
	// stw r6,-260(r1)
	REX_STORE_U32(ctx.r1.u32 + -260, ctx.r6.u32);
	// add r5,r10,r23
	ctx.r5.u64 = ctx.r10.u64 + ctx.r23.u64;
	// rlwinm r7,r5,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r7,r29
	ctx.r4.u64 = ctx.r7.u64 + ctx.r29.u64;
	// mulli r3,r4,28
	ctx.r3.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(28));
	// stw r3,-256(r1)
	REX_STORE_U32(ctx.r1.u32 + -256, ctx.r3.u32);
	// lbz r3,-514(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + -514);
	// beq cr6,0x82719c70
	if (ctx.cr6.eq) goto loc_82719C70;
	// mulli r10,r10,85
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r10,-252(r1)
	REX_STORE_U32(ctx.r1.u32 + -252, ctx.r10.u32);
	// b 0x82719c88
	goto loc_82719C88;
loc_82719C70:
	// lbz r6,-519(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -519);
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r10,r3
	ctx.r5.u64 = ctx.r10.u64 + ctx.r3.u64;
	// mulli r4,r5,28
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// stw r4,-252(r1)
	REX_STORE_U32(ctx.r1.u32 + -252, ctx.r4.u32);
loc_82719C88:
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r29,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r7,-236(r1)
	REX_STORE_U32(ctx.r1.u32 + -236, ctx.r7.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-232(r1)
	REX_STORE_U32(ctx.r1.u32 + -232, ctx.r5.u32);
	// beq cr6,0x82719cb4
	if (ctx.cr6.eq) goto loc_82719CB4;
	// rlwinm r10,r9,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-228(r1)
	REX_STORE_U32(ctx.r1.u32 + -228, ctx.r10.u32);
	// b 0x82719cc4
	goto loc_82719CC4;
loc_82719CB4:
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// mulli r7,r10,85
	ctx.r7.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r7,-228(r1)
	REX_STORE_U32(ctx.r1.u32 + -228, ctx.r7.u32);
loc_82719CC4:
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r5,-510(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -510);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r4,r6,r29
	ctx.r4.u64 = ctx.r6.u64 + ctx.r29.u64;
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// mulli r4,r4,85
	ctx.r4.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(85));
	// stw r4,-212(r1)
	REX_STORE_U32(ctx.r1.u32 + -212, ctx.r4.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r4,r29
	ctx.r5.u64 = ctx.r4.u64 + ctx.r29.u64;
	// mulli r4,r5,28
	ctx.r4.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// stw r4,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r4.u32);
	// lbz r4,-509(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -509);
	// beq cr6,0x82719d10
	if (ctx.cr6.eq) goto loc_82719D10;
	// mulli r9,r7,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(85));
	// stw r9,-204(r1)
	REX_STORE_U32(ctx.r1.u32 + -204, ctx.r9.u32);
	// b 0x82719d2c
	goto loc_82719D2C;
loc_82719D10:
	// add r5,r4,r10
	ctx.r5.u64 = ctx.r4.u64 + ctx.r10.u64;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mulli r5,r7,28
	ctx.r5.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r5,-204(r1)
	REX_STORE_U32(ctx.r1.u32 + -204, ctx.r5.u32);
loc_82719D2C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82719d70
	if (ctx.cr6.eq) goto loc_82719D70;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// mulli r7,r9,85
	ctx.r7.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(85));
	// stw r8,-188(r1)
	REX_STORE_U32(ctx.r1.u32 + -188, ctx.r8.u32);
	// stw r7,-184(r1)
	REX_STORE_U32(ctx.r1.u32 + -184, ctx.r7.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82719d5c
	if (ctx.cr6.eq) goto loc_82719D5C;
	// rlwinm r10,r28,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r10.u32);
	// b 0x82719dcc
	goto loc_82719DCC;
loc_82719D5C:
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mulli r9,r10,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r9,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r9.u32);
	// b 0x82719dcc
	goto loc_82719DCC;
loc_82719D70:
	// lbz r7,-505(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -505);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r9,-506(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -506);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r7,r3,85
	ctx.r7.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(85));
	// stw r7,-188(r1)
	REX_STORE_U32(ctx.r1.u32 + -188, ctx.r7.u32);
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mulli r5,r6,28
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(28));
	// stw r5,-184(r1)
	REX_STORE_U32(ctx.r1.u32 + -184, ctx.r5.u32);
	// beq cr6,0x82719db0
	if (ctx.cr6.eq) goto loc_82719DB0;
	// mulli r10,r10,85
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r10,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r10.u32);
	// b 0x82719dcc
	goto loc_82719DCC;
loc_82719DB0:
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// lbz r9,-504(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -504);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mulli r6,r7,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r6,-180(r1)
	REX_STORE_U32(ctx.r1.u32 + -180, ctx.r6.u32);
loc_82719DCC:
	// lbz r8,-544(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -544);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r7,-543(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -543);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r8.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r5.u32);
	// beq cr6,0x82719e08
	if (ctx.cr6.eq) goto loc_82719E08;
	// rlwinm r10,r7,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r10.u32);
	// b 0x82719e18
	goto loc_82719E18;
loc_82719E08:
	// lbz r7,-542(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -542);
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r5.u32);
loc_82719E18:
	// lbz r5,-540(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -540);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r6,-541(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -541);
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// rotlwi r4,r6,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// add r6,r4,r9
	ctx.r6.u64 = ctx.r4.u64 + ctx.r9.u64;
	// add r29,r3,r8
	ctx.r29.u64 = ctx.r3.u64 + ctx.r8.u64;
	// mulli r6,r6,85
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r6,-356(r1)
	REX_STORE_U32(ctx.r1.u32 + -356, ctx.r6.u32);
	// rlwinm r6,r29,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// add r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 + ctx.r9.u64;
	// mulli r9,r5,28
	ctx.r9.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// lbz r5,-539(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -539);
	// stw r9,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r9.u32);
	// beq cr6,0x82719e70
	if (ctx.cr6.eq) goto loc_82719E70;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r8,r9,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(85));
	// stw r8,-348(r1)
	REX_STORE_U32(ctx.r1.u32 + -348, ctx.r8.u32);
	// b 0x82719e8c
	goto loc_82719E8C;
loc_82719E70:
	// add r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lbz r6,-542(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -542);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mulli r6,r8,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(28));
	// stw r6,-348(r1)
	REX_STORE_U32(ctx.r1.u32 + -348, ctx.r6.u32);
loc_82719E8C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82719ecc
	if (ctx.cr6.eq) goto loc_82719ECC;
	// rlwinm r9,r7,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// mulli r8,r3,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(85));
	// stw r9,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r9.u32);
	// stw r8,-340(r1)
	REX_STORE_U32(ctx.r1.u32 + -340, ctx.r8.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82719eb8
	if (ctx.cr6.eq) goto loc_82719EB8;
	// rlwinm r10,r29,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r10.u32);
	// b 0x82719f28
	goto loc_82719F28;
loc_82719EB8:
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mulli r9,r10,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r9,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r9.u32);
	// b 0x82719f28
	goto loc_82719F28;
loc_82719ECC:
	// lbz r9,-538(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -538);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r8,-537(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -537);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mulli r8,r4,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(85));
	// stw r8,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r8.u32);
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r8,r3,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mulli r6,r7,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r6,-340(r1)
	REX_STORE_U32(ctx.r1.u32 + -340, ctx.r6.u32);
	// beq cr6,0x82719f0c
	if (ctx.cr6.eq) goto loc_82719F0C;
	// mulli r10,r10,85
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r10,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r10.u32);
	// b 0x82719f28
	goto loc_82719F28;
loc_82719F0C:
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// lbz r9,-536(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -536);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mulli r6,r7,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r6,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r6.u32);
loc_82719F28:
	// lbz r8,-560(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -560);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r7,-559(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -559);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,-416(r1)
	REX_STORE_U32(ctx.r1.u32 + -416, ctx.r8.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-412(r1)
	REX_STORE_U32(ctx.r1.u32 + -412, ctx.r5.u32);
	// beq cr6,0x82719f64
	if (ctx.cr6.eq) goto loc_82719F64;
	// rlwinm r10,r7,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-408(r1)
	REX_STORE_U32(ctx.r1.u32 + -408, ctx.r10.u32);
	// b 0x82719f74
	goto loc_82719F74;
loc_82719F64:
	// lbz r7,-558(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -558);
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// mulli r5,r6,85
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r5,-408(r1)
	REX_STORE_U32(ctx.r1.u32 + -408, ctx.r5.u32);
loc_82719F74:
	// lbz r5,-556(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -556);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r6,-557(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -557);
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// rotlwi r4,r6,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// add r6,r4,r9
	ctx.r6.u64 = ctx.r4.u64 + ctx.r9.u64;
	// add r29,r3,r8
	ctx.r29.u64 = ctx.r3.u64 + ctx.r8.u64;
	// mulli r6,r6,85
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(85));
	// stw r6,-404(r1)
	REX_STORE_U32(ctx.r1.u32 + -404, ctx.r6.u32);
	// rlwinm r6,r29,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// add r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 + ctx.r9.u64;
	// mulli r9,r5,28
	ctx.r9.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(28));
	// lbz r5,-555(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -555);
	// stw r9,-400(r1)
	REX_STORE_U32(ctx.r1.u32 + -400, ctx.r9.u32);
	// beq cr6,0x82719fcc
	if (ctx.cr6.eq) goto loc_82719FCC;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r8,r9,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(85));
	// stw r8,-396(r1)
	REX_STORE_U32(ctx.r1.u32 + -396, ctx.r8.u32);
	// b 0x82719fe8
	goto loc_82719FE8;
loc_82719FCC:
	// add r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lbz r6,-558(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -558);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mulli r6,r8,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(28));
	// stw r6,-396(r1)
	REX_STORE_U32(ctx.r1.u32 + -396, ctx.r6.u32);
loc_82719FE8:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8271a028
	if (ctx.cr6.eq) goto loc_8271A028;
	// rlwinm r9,r7,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// mulli r8,r3,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(85));
	// stw r9,-392(r1)
	REX_STORE_U32(ctx.r1.u32 + -392, ctx.r9.u32);
	// stw r8,-388(r1)
	REX_STORE_U32(ctx.r1.u32 + -388, ctx.r8.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8271a014
	if (ctx.cr6.eq) goto loc_8271A014;
	// rlwinm r10,r29,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,-384(r1)
	REX_STORE_U32(ctx.r1.u32 + -384, ctx.r10.u32);
	// b 0x8271a084
	goto loc_8271A084;
loc_8271A014:
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mulli r9,r10,85
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r9,-384(r1)
	REX_STORE_U32(ctx.r1.u32 + -384, ctx.r9.u32);
	// b 0x8271a084
	goto loc_8271A084;
loc_8271A028:
	// lbz r9,-554(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -554);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r8,-553(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -553);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mulli r8,r4,85
	ctx.r8.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(85));
	// stw r8,-392(r1)
	REX_STORE_U32(ctx.r1.u32 + -392, ctx.r8.u32);
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r8,r3,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mulli r6,r7,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r6,-388(r1)
	REX_STORE_U32(ctx.r1.u32 + -388, ctx.r6.u32);
	// beq cr6,0x8271a068
	if (ctx.cr6.eq) goto loc_8271A068;
	// mulli r10,r10,85
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(85));
	// stw r10,-384(r1)
	REX_STORE_U32(ctx.r1.u32 + -384, ctx.r10.u32);
	// b 0x8271a084
	goto loc_8271A084;
loc_8271A068:
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// lbz r9,-552(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -552);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mulli r6,r7,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(28));
	// stw r6,-384(r1)
	REX_STORE_U32(ctx.r1.u32 + -384, ctx.r6.u32);
loc_8271A084:
	// lwz r6,-488(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -488);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,-432(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -432);
	// addi r3,r1,-316
	ctx.r3.s64 = ctx.r1.s64 + -316;
	// lwz r9,-440(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -440);
	// lis r7,154
	ctx.r7.s64 = 10092544;
	// add r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lwz r8,-460(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -460);
	// add r4,r9,r6
	ctx.r4.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stw r10,-500(r1)
	REX_STORE_U32(ctx.r1.u32 + -500, ctx.r10.u32);
	// stw r6,-476(r1)
	REX_STORE_U32(ctx.r1.u32 + -476, ctx.r6.u32);
	// stw r4,-496(r1)
	REX_STORE_U32(ctx.r1.u32 + -496, ctx.r4.u32);
	// stw r5,-492(r1)
	REX_STORE_U32(ctx.r1.u32 + -492, ctx.r5.u32);
loc_8271A0B8:
	// srawi r30,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r30.s64 = ctx.r10.s32 >> 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// rlwinm r9,r30,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// add r29,r30,r9
	ctx.r29.u64 = ctx.r30.u64 + ctx.r9.u64;
	// subf r26,r8,r5
	ctx.r26.u64 = ctx.r5.u64 - ctx.r8.u64;
	// subf r27,r8,r4
	ctx.r27.u64 = ctx.r4.u64 - ctx.r8.u64;
	// addi r23,r1,-416
	ctx.r23.s64 = ctx.r1.s64 + -416;
	// addi r22,r1,-368
	ctx.r22.s64 = ctx.r1.s64 + -368;
loc_8271A0DC:
	// addi r9,r10,-2
	ctx.r9.s64 = ctx.r10.s64 + -2;
	// lwz r6,-4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + -4);
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// srawi r30,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r30.s64 = ctx.r9.s32 >> 1;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r21,r1,-416
	ctx.r21.s64 = ctx.r1.s64 + -416;
	// add r25,r30,r29
	ctx.r25.u64 = ctx.r30.u64 + ctx.r29.u64;
	// mulli r30,r6,297
	ctx.r30.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(297));
	// rlwinm r6,r25,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r1,-368
	ctx.r20.s64 = ctx.r1.s64 + -368;
	// addi r19,r1,-416
	ctx.r19.s64 = ctx.r1.s64 + -416;
	// addi r18,r1,-368
	ctx.r18.s64 = ctx.r1.s64 + -368;
	// lwzx r24,r6,r23
	ctx.r24.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r23.u32);
	// lwzx r6,r6,r22
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r22.u32);
	// mulli r25,r24,-208
	ctx.r25.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(-208));
	// mulli r17,r6,100
	ctx.r17.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(100));
	// subf r25,r17,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r17.u64;
	// subf r24,r11,r24
	ctx.r24.u64 = ctx.r24.u64 - ctx.r11.u64;
	// subf r6,r11,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r11.u64;
	// add r17,r25,r30
	ctx.r17.u64 = ctx.r25.u64 + ctx.r30.u64;
	// mulli r24,r24,408
	ctx.r24.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(408));
	// rlwinm r25,r6,9,0,22
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 9) & 0xFFFFFE00;
	// add r6,r17,r7
	ctx.r6.u64 = ctx.r17.u64 + ctx.r7.u64;
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// srawi r6,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 16;
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// srawi r24,r24,16
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xFFFF) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 16;
	// srawi r17,r30,16
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFFF) != 0);
	ctx.r17.s64 = ctx.r30.s32 >> 16;
	// srawi r25,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r25.s64 = ctx.r5.s32 >> 1;
	// mulli r30,r4,297
	ctx.r30.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(297));
	// lbzx r5,r6,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r31.u32);
	// lbzx r4,r24,r31
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + ctx.r31.u32);
	// lbzx r6,r17,r31
	ctx.r6.u64 = REX_LOAD_U8(ctx.r17.u32 + ctx.r31.u32);
	// add r25,r25,r29
	ctx.r25.u64 = ctx.r25.u64 + ctx.r29.u64;
	// rlwimi r5,r4,5,11,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0x1FFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFE000FF);
	// rlwinm r4,r25,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r5,3,16,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFE0;
	// rlwinm r6,r6,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// or r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 | ctx.r6.u64;
	// lwzx r6,r4,r21
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r21.u32);
	// lwzx r4,r4,r20
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r20.u32);
	// sthux r5,r28,r8
	ea = ctx.r28.u32 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r5.u16);
	ctx.r28.u32 = ea;
	// mulli r25,r6,-208
	ctx.r25.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(-208));
	// mulli r5,r4,100
	ctx.r5.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(100));
	// subf r25,r5,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r5.u64;
	// subf r6,r11,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r11.u64;
	// subf r5,r11,r4
	ctx.r5.u64 = ctx.r4.u64 - ctx.r11.u64;
	// add r4,r25,r30
	ctx.r4.u64 = ctx.r25.u64 + ctx.r30.u64;
	// mulli r24,r6,408
	ctx.r24.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(408));
	// rlwinm r25,r5,9,0,22
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 9) & 0xFFFFFE00;
	// add r6,r4,r7
	ctx.r6.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r5,r24,r30
	ctx.r5.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r4,r25,r30
	ctx.r4.u64 = ctx.r25.u64 + ctx.r30.u64;
	// srawi r6,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 16;
	// srawi r5,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 16;
	// srawi r4,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 16;
	// mulli r30,r9,297
	ctx.r30.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(297));
	// lbzx r9,r6,r31
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r31.u32);
	// lbzx r6,r5,r31
	ctx.r6.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r31.u32);
	// lbzx r5,r4,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r31.u32);
	// srawi r25,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r25.s64 = ctx.r10.s32 >> 1;
	// rlwimi r9,r6,5,11,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0x1FFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFE000FF);
	// add r4,r25,r29
	ctx.r4.u64 = ctx.r25.u64 + ctx.r29.u64;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r9,3,16,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFE0;
	// rlwinm r9,r5,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// or r5,r4,r9
	ctx.r5.u64 = ctx.r4.u64 | ctx.r9.u64;
	// lwzx r9,r6,r18
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r18.u32);
	// lwzx r4,r6,r19
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r19.u32);
	// sthux r5,r27,r8
	ea = ctx.r27.u32 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r5.u16);
	ctx.r27.u32 = ea;
	// mulli r5,r9,100
	ctx.r5.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(100));
	// mulli r6,r4,-208
	ctx.r6.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(-208));
	// subf r25,r5,r6
	ctx.r25.u64 = ctx.r6.u64 - ctx.r5.u64;
	// subf r4,r11,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r11.u64;
	// add r6,r25,r30
	ctx.r6.u64 = ctx.r25.u64 + ctx.r30.u64;
	// mulli r25,r4,408
	ctx.r25.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(408));
	// subf r5,r11,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r4,r25,r30
	ctx.r4.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// rlwinm r25,r5,9,0,22
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 9) & 0xFFFFFE00;
	// srawi r6,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 16;
	// srawi r5,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 16;
	// add r4,r25,r30
	ctx.r4.u64 = ctx.r25.u64 + ctx.r30.u64;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// srawi r9,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 16;
	// lbzx r6,r6,r31
	ctx.r6.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r31.u32);
	// addi r4,r10,-2
	ctx.r4.s64 = ctx.r10.s64 + -2;
	// lbzx r5,r5,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r31.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// cmpwi cr6,r4,6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 6, ctx.xer);
	// rlwimi r6,r5,5,11,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0x1FFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFE000FF);
	// lbzx r4,r9,r31
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r31.u32);
	// rlwinm r9,r6,3,16,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFE0;
	// rlwinm r6,r4,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// or r5,r9,r6
	ctx.r5.u64 = ctx.r9.u64 | ctx.r6.u64;
	// sthux r5,r26,r8
	ea = ctx.r26.u32 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r5.u16);
	ctx.r26.u32 = ea;
	// blt cr6,0x8271a0dc
	if (ctx.cr6.lt) goto loc_8271A0DC;
	// lwz r9,-468(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -468);
	// lwz r10,-500(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -500);
	// lwz r6,-476(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -476);
	// lwz r5,-492(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -492);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r4,-496(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -496);
	// add r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 + ctx.r5.u64;
	// stw r10,-500(r1)
	REX_STORE_U32(ctx.r1.u32 + -500, ctx.r10.u32);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stw r6,-476(r1)
	REX_STORE_U32(ctx.r1.u32 + -476, ctx.r6.u32);
	// stw r5,-492(r1)
	REX_STORE_U32(ctx.r1.u32 + -492, ctx.r5.u32);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// stw r4,-496(r1)
	REX_STORE_U32(ctx.r1.u32 + -496, ctx.r4.u32);
	// blt cr6,0x8271a0b8
	if (ctx.cr6.lt) goto loc_8271A0B8;
	// lwz r9,-488(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -488);
	// lwz r10,-472(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -472);
	// lwz r8,-452(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -452);
	// lwz r7,-428(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -428);
	// addi r28,r10,1
	ctx.r28.s64 = ctx.r10.s64 + 1;
	// lwz r6,-444(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -444);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r3,-420(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -420);
	// addi r5,r7,4
	ctx.r5.s64 = ctx.r7.s64 + 4;
	// lwz r25,-436(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -436);
	// addi r9,r6,2
	ctx.r9.s64 = ctx.r6.s64 + 2;
	// lwz r29,68(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 68);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// lwz r8,60(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// cmpw cr6,r28,r25
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r25.s32, ctx.xer);
	// stw r28,-472(r1)
	REX_STORE_U32(ctx.r1.u32 + -472, ctx.r28.u32);
	// stw r4,-488(r1)
	REX_STORE_U32(ctx.r1.u32 + -488, ctx.r4.u32);
	// blt cr6,0x82719820
	if (ctx.cr6.lt) goto loc_82719820;
	// lwz r26,116(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r7,52(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 52);
	// lwz r6,44(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 44);
	// lwz r5,36(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// lwz r4,28(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// lwz r30,-480(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -480);
	// lwz r27,-464(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -464);
loc_8271A304:
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,-456(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -456);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r30,-480(r1)
	REX_STORE_U32(ctx.r1.u32 + -480, ctx.r30.u32);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r4,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// stw r6,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r6.u32);
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// stw r7,52(r1)
	REX_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// blt cr6,0x82719780
	if (ctx.cr6.lt) goto loc_82719780;
loc_8271A340:
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(__restvmx_105) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v105.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v106.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v107.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v108.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v109.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v110.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v111.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v112.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v113.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v114.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v115.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v116.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v117.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v118.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v119.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v120.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v121.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v122.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v123.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8275A228) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82761168
	ctx.lr = 0x8275A248;
	sub_82761168(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8275a274
	if (!ctx.cr0.eq) goto loc_8275A274;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275a274
	if (ctx.cr6.eq) goto loc_8275A274;
	// bl 0x8275a3e0
	ctx.lr = 0x8275A260;
	sub_8275A3E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8275a274
	if (ctx.cr0.eq) goto loc_8275A274;
	// bl 0x8275a3e0
	ctx.lr = 0x8275A26C;
	sub_8275A3E0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8275A274:
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
}

DEFINE_REX_FUNC(sub_8275DF2C) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// addi r30,r11,-6344
	ctx.r30.s64 = ctx.r11.s64 + -6344;
	// b 0x8275df58
	goto loc_8275DF58;
loc_8275DF58:
	// lwz r3,80(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// bl 0x82872dec
	ctx.lr = 0x8275DF60;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r30,-8(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// lwz r12,-16(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8275EC20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
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
	// lwz r30,180(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// b 0x8275ec58
	goto loc_8275EC58;
loc_8275EC58:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82762210
	ctx.lr = 0x8275EC60;
	sub_82762210(ctx, base);
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

DEFINE_REX_FUNC(sub_82761168) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x82761170;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r30,-4096
	ctx.r30.s64 = -4096;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827611c0
	if (ctx.cr6.eq) goto loc_827611C0;
	// divwu r11,r30,r3
	ctx.r11.u64 = uint32_t(ctx.r3.u32 ? ctx.r30.u32 / ctx.r3.u32 : 0);
	// twllei r3,0
	if (ctx.r3.s32 == 0 || ctx.r3.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x827611c0
	if (!ctx.cr6.lt) goto loc_827611C0;
	// bl 0x8275a3e0
	ctx.lr = 0x82761198;
	sub_8275A3E0(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8275a2a0
	ctx.lr = 0x827611B8;
	sub_8275A2A0(ctx, base);
loc_827611B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82761234
	goto loc_82761234;
loc_827611C0:
	// mullw. r31,r3,r4
	ctx.r31.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x827611cc
	if (!ctx.cr0.eq) goto loc_827611CC;
	// li r31,1
	ctx.r31.s64 = 1;
loc_827611CC:
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
loc_827611D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x827611f4
	if (ctx.cr6.gt) goto loc_827611F4;
	// bl 0x8265d608
	ctx.lr = 0x827611E0;
	sub_8265D608(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8265c168
	ctx.lr = 0x827611EC;
	sub_8265C168(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82761234
	if (!ctx.cr0.eq) goto loc_82761234;
loc_827611F4:
	// lwz r11,-25124(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -25124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82761224
	if (ctx.cr6.eq) goto loc_82761224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8275e358
	ctx.lr = 0x82761208;
	sub_8275E358(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x827611d0
	if (!ctx.cr0.eq) goto loc_827611D0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x827611b8
	if (ctx.cr6.eq) goto loc_827611B8;
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x827611b8
	goto loc_827611B8;
loc_82761224:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82761234
	if (ctx.cr6.eq) goto loc_82761234;
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_82761234:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82767CC8) {
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
	// lis r5,2
	ctx.r5.s64 = 131072;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,2
	ctx.r6.s64 = 2;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827672f8
	ctx.lr = 0x82767D00;
	sub_827672F8(ctx, base);
	// lis r5,4
	ctx.r5.s64 = 262144;
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82766dd0
	ctx.lr = 0x82767D14;
	sub_82766DD0(ctx, base);
	// lhz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// li r11,16
	ctx.r11.s64 = 16;
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r7,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// rlwinm r9,r10,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// lvrx128 v63,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r9,r8,32448
	ctx.r9.s64 = ctx.r8.s64 + 32448;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lvrx128 v61,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v61,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vor128 v62,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vcuxwfp128 v61,v61,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v61.f32, rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r7,10788
	ctx.r11.s64 = ctx.r7.s64 + 10788;
	// vcuxwfp128 v62,v62,0
	simde_mm_store_ps(ctx.v62.f32, rex::ppc::simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r5,r5,10792
	ctx.r5.s64 = ctx.r5.s64 + 10792;
	// vmulfp128 v0,v61,v63
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vmaddfp v12,v13,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vmaddfp v0,v13,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82767DE8:
	// rlwinm r11,r6,4,26,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0x30;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// rlwinm r6,r6,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lvx128 v63,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// bdnz 0x82767de8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82767DE8;
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

DEFINE_REX_FUNC(sub_8277A958) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8277A960;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82771e60
	ctx.lr = 0x8277A978;
	sub_82771E60(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// lis r9,4095
	ctx.r9.s64 = 268369920;
	// addi r10,r10,-29924
	ctx.r10.s64 = ctx.r10.s64 + -29924;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
	// stw r30,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stw r30,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r30.u32);
	// stw r8,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r8.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r10,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x8277a9e0
	if (!ctx.cr6.gt) goto loc_8277A9E0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8277A9E0:
	// bl 0x825fbdf0
	ctx.lr = 0x8277A9E4;
	sub_825FBDF0(ctx, base);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8277a9f4
	if (!ctx.cr6.eq) goto loc_8277A9F4;
	// stw r30,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
loc_8277A9F4:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addis r11,r11,-6184
	ctx.r11.s64 = ctx.r11.s64 + -405274624;
	// addic. r11,r11,-75
	ctx.xer.ca = ctx.r11.u32 > 74;
	ctx.r11.s64 = ctx.r11.s64 + -75;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277aa30
	if (ctx.cr0.eq) goto loc_8277AA30;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8277aa20
	if (ctx.cr6.eq) goto loc_8277AA20;
	// addis r11,r11,-504
	ctx.r11.s64 = ctx.r11.s64 + -33030144;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8277aa30
	if (ctx.cr0.eq) goto loc_8277AA30;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8277aa3c
	if (!ctx.cr6.eq) goto loc_8277AA3C;
loc_8277AA20:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r30,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// b 0x8277aa3c
	goto loc_8277AA3C;
loc_8277AA30:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r30,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
loc_8277AA3C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277F788) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8277F790;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-29652
	ctx.r10.s64 = ctx.r11.s64 + -29652;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// lis r6,27493
	ctx.r6.s64 = 1801781248;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// ori r6,r6,25971
	ctx.r6.u64 = ctx.r6.u64 | 25971;
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277f148
	ctx.lr = 0x8277F7DC;
	sub_8277F148(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8277f800
	if (ctx.cr6.lt) goto loc_8277F800;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277eeb0
	ctx.lr = 0x8277F800;
	sub_8277EEB0(ctx, base);
loc_8277F800:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827805E8) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8278061c
	if (ctx.cr6.eq) goto loc_8278061C;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8278061c
	if (ctx.cr6.eq) goto loc_8278061C;
	// bl 0x82656df0
	ctx.lr = 0x82780614;
	sub_82656DF0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8278061C:
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

DEFINE_REX_FUNC(sub_827818B8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r11,r3,248
	ctx.r11.s64 = ctx.r3.s64 + 248;
	// b 0x827818d8
	goto loc_827818D8;
loc_827818C4:
	// ld r8,-76(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + -76);
	// addi r9,r10,-92
	ctx.r9.s64 = ctx.r10.s64 + -92;
	// cmpld cr6,r8,r4
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, ctx.xer);
	// beq cr6,0x827818ec
	if (ctx.cr6.eq) goto loc_827818EC;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_827818D8:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x827818f8
	if (ctx.cr6.eq) goto loc_827818F8;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x827818c4
	if (!ctx.cr0.eq) goto loc_827818C4;
	// b 0x827818f8
	goto loc_827818F8;
loc_827818EC:
	// lwz r11,396(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827818fc
	if (!ctx.cr0.eq) goto loc_827818FC;
loc_827818F8:
	// li r9,0
	ctx.r9.s64 = 0;
loc_827818FC:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827836C0) {
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
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8278372c
	if (ctx.cr6.eq) goto loc_8278372C;
	// lwz r9,740(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 740);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,380
	ctx.r10.s64 = ctx.r3.s64 + 380;
	// rlwinm r4,r9,21,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x1;
loc_827836E8:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82783708
	if (!ctx.cr6.eq) goto loc_82783708;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x827836e8
	if (ctx.cr6.lt) goto loc_827836E8;
	// b 0x82783720
	goto loc_82783720;
loc_82783708:
	// addi r11,r11,95
	ctx.r11.s64 = ctx.r11.s64 + 95;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r11,r11,4,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// or r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 | ctx.r4.u64;
loc_82783720:
	// bl 0x82780f68
	ctx.lr = 0x82783724;
	sub_82780F68(ctx, base);
	// rlwinm r3,r3,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// b 0x82783730
	goto loc_82783730;
loc_8278372C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82783730:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82786750) {
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
	// lwz r11,740(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 740);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8278677c
	if (!ctx.cr0.eq) goto loc_8278677C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1314
	ctx.r3.u64 = ctx.r3.u64 | 1314;
	// b 0x827867c8
	goto loc_827867C8;
loc_8278677C:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82786794
	if (ctx.cr6.eq) goto loc_82786794;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1609
	ctx.r3.u64 = ctx.r3.u64 | 1609;
	// b 0x827867c8
	goto loc_827867C8;
loc_82786794:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827867bc
	if (ctx.cr6.eq) goto loc_827867BC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,95
	ctx.r4.s64 = 95;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82785238
	ctx.lr = 0x827867B4;
	sub_82785238(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827867c8
	if (ctx.cr0.lt) goto loc_827867C8;
loc_827867BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82786528
	ctx.lr = 0x827867C4;
	sub_82786528(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_827867C8:
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

DEFINE_REX_FUNC(sub_8278A7E8) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8278a8b0
	if (ctx.cr6.lt) goto loc_8278A8B0;
	// lwz r11,740(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 740);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8278a8c8
	if (!ctx.cr0.eq) goto loc_8278A8C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82781320
	ctx.lr = 0x8278A820;
	sub_82781320(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82786528
	ctx.lr = 0x8278A828;
	sub_82786528(ctx, base);
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// rlwinm. r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8278a848
	if (ctx.cr0.eq) goto loc_8278A848;
	// rlwinm r11,r11,0,24,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x8278b708
	ctx.lr = 0x8278A844;
	sub_8278B708(ctx, base);
	// b 0x8278a860
	goto loc_8278A860;
loc_8278A848:
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8278a86c
	if (ctx.cr0.eq) goto loc_8278A86C;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82786888
	ctx.lr = 0x8278A860;
	sub_82786888(ctx, base);
loc_8278A860:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8278a974
	if (ctx.cr0.lt) goto loc_8278A974;
	// b 0x8278a870
	goto loc_8278A870;
loc_8278A86C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8278A870:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8278a8a8
	if (ctx.cr6.lt) goto loc_8278A8A8;
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8278A8A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8278a980
	goto loc_8278A980;
loc_8278A8A8:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8278a8c8
	goto loc_8278A8C8;
loc_8278A8B0:
	// lis r11,-32747
	ctx.r11.s64 = -2146107392;
	// ori r11,r11,20998
	ctx.r11.u64 = ctx.r11.u64 | 20998;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8278a8c8
	if (!ctx.cr6.eq) goto loc_8278A8C8;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1245
	ctx.r30.u64 = ctx.r30.u64 | 1245;
loc_8278A8C8:
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// rlwinm r11,r11,0,24,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFCFF;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82756d30
	ctx.lr = 0x8278A8E8;
	sub_82756D30(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8278A920;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8278a958
	if (ctx.cr6.eq) goto loc_8278A958;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82785510
	ctx.lr = 0x8278A93C;
	sub_82785510(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8278a974
	if (ctx.cr0.lt) goto loc_8278A974;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827847a0
	ctx.lr = 0x8278A954;
	sub_827847A0(ctx, base);
	// b 0x8278a980
	goto loc_8278A980;
loc_8278A958:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x827847a0
	ctx.lr = 0x8278A960;
	sub_827847A0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278a618
	ctx.lr = 0x8278A96C;
	sub_8278A618(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8278a980
	if (!ctx.cr0.lt) goto loc_8278A980;
loc_8278A974:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82785f08
	ctx.lr = 0x8278A980;
	sub_82785F08(ctx, base);
loc_8278A980:
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

DEFINE_REX_FUNC(sub_82791818) {
	REX_FUNC_PROLOGUE();
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// b 0x827917b0
	sub_827917B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82791E88) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// b 0x82791af8
	sub_82791AF8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82792060) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r3,10048
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10048, ctx.xer);
	// beq cr6,0x827920c8
	if (ctx.cr6.eq) goto loc_827920C8;
	// cmpwi cr6,r3,10050
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10050, ctx.xer);
	// beq cr6,0x827920bc
	if (ctx.cr6.eq) goto loc_827920BC;
	// cmpwi cr6,r3,10054
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10054, ctx.xer);
	// beq cr6,0x827920b0
	if (ctx.cr6.eq) goto loc_827920B0;
	// cmpwi cr6,r3,10055
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10055, ctx.xer);
	// beq cr6,0x827920a4
	if (ctx.cr6.eq) goto loc_827920A4;
	// cmpwi cr6,r3,10065
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10065, ctx.xer);
	// beq cr6,0x827920b0
	if (ctx.cr6.eq) goto loc_827920B0;
	// cmpwi cr6,r3,10091
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10091, ctx.xer);
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// beq cr6,0x8279209c
	if (ctx.cr6.eq) goto loc_8279209C;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// blr
	return;
loc_8279209C:
	// ori r3,r3,4098
	ctx.r3.u64 = ctx.r3.u64 | 4098;
	// blr
	return;
loc_827920A4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// blr
	return;
loc_827920B0:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4116
	ctx.r3.u64 = ctx.r3.u64 | 4116;
	// blr
	return;
loc_827920BC:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4099
	ctx.r3.u64 = ctx.r3.u64 | 4099;
	// blr
	return;
loc_827920C8:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4100
	ctx.r3.u64 = ctx.r3.u64 | 4100;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82794CD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82794CE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,108
	ctx.r30.s64 = ctx.r3.s64 + 108;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x82872dfc
	ctx.lr = 0x82794D00;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792458
	ctx.lr = 0x82794D0C;
	sub_82792458(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82794d30
	if (!ctx.cr0.eq) goto loc_82794D30;
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r29,r29,4105
	ctx.r29.u64 = ctx.r29.u64 | 4105;
	// bl 0x82872dec
	ctx.lr = 0x82794D24;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x82794e0c
	goto loc_82794E0C;
loc_82794D30:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82794d64
	if (!ctx.cr6.eq) goto loc_82794D64;
	// lwz r31,188(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82794d8c
	if (ctx.cr6.eq) goto loc_82794D8C;
loc_82794D44:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82794d44
	if (!ctx.cr0.eq) goto loc_82794D44;
	// b 0x82794d8c
	goto loc_82794D8C;
loc_82794D64:
	// lwz r31,88(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82794d8c
	if (ctx.cr6.eq) goto loc_82794D8C;
loc_82794D70:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82794d70
	if (!ctx.cr0.eq) goto loc_82794D70;
loc_82794D8C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82872dec
	ctx.lr = 0x82794D94;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82794e00
	if (ctx.cr6.eq) goto loc_82794E00;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82794db8
	if (!ctx.cr6.lt) goto loc_82794DB8;
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// ori r29,r29,4097
	ctx.r29.u64 = ctx.r29.u64 | 4097;
	// b 0x82794dcc
	goto loc_82794DCC;
loc_82794DB8:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827567d0
	ctx.lr = 0x82794DC8;
	sub_827567D0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
loc_82794DCC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82794dcc
	if (!ctx.cr0.eq) goto loc_82794DCC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82794e08
	if (!ctx.cr6.eq) goto loc_82794E08;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8278e7e8
	ctx.lr = 0x82794DFC;
	sub_8278E7E8(ctx, base);
	// b 0x82794e08
	goto loc_82794E08;
loc_82794E00:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82794E08:
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
loc_82794E0C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279CD90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8279CD98;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwimi r11,r10,26,5,5
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x4000000) | (ctx.r11.u64 & 0xFFFFFFFFFBFFFFFF);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwimi r11,r10,26,2,2
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x20000000) | (ctx.r11.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r9,152(r3)
	REX_STORE_U32(ctx.r3.u32 + 152, ctx.r9.u32);
	// stw r8,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r8.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// bl 0x827a3980
	ctx.lr = 0x8279CDCC;
	sub_827A3980(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8279ce6c
	if (!ctx.cr0.eq) goto loc_8279CE6C;
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r28,r31,208
	ctx.r28.s64 = ctx.r31.s64 + 208;
	// b 0x8279ce24
	goto loc_8279CE24;
loc_8279CDE0:
	// addi r30,r29,-4
	ctx.r30.s64 = ctx.r29.s64 + -4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792e38
	ctx.lr = 0x8279CDF4;
	sub_82792E38(ctx, base);
	// lwz r11,284(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 284);
	// rlwinm. r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8279ce20
	if (ctx.cr0.eq) goto loc_8279CE20;
	// rlwinm r11,r11,0,21,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,288(r30)
	REX_STORE_U32(ctx.r30.u32 + 288, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792b10
	ctx.lr = 0x8279CE18;
	sub_82792B10(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8279ce6c
	if (!ctx.cr0.eq) goto loc_8279CE6C;
loc_8279CE20:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_8279CE24:
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8279ce38
	if (ctx.cr6.eq) goto loc_8279CE38;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// bne 0x8279cde0
	if (!ctx.cr0.eq) goto loc_8279CDE0;
loc_8279CE38:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// li r5,15000
	ctx.r5.s64 = 15000;
	// li r4,-1
	ctx.r4.s64 = -1;
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// addi r3,r31,356
	ctx.r3.s64 = ctx.r31.s64 + 356;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// bl 0x827a1618
	ctx.lr = 0x8279CE54;
	sub_827A1618(ctx, base);
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8279ce6c
	if (!ctx.cr6.gt) goto loc_8279CE6C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279c080
	ctx.lr = 0x8279CE6C;
	sub_8279C080(ctx, base);
loc_8279CE6C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A1410) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827A14B0) {
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
	// lwz r11,236(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 236);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 232);
	// bne cr6,0x827a14e4
	if (!ctx.cr6.eq) goto loc_827A14E4;
	// stw r11,236(r3)
	REX_STORE_U32(ctx.r3.u32 + 236, ctx.r11.u32);
	// b 0x827a151c
	goto loc_827A151C;
loc_827A14E4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,220
	ctx.r3.s64 = ctx.r11.s64 + 220;
	// bl 0x827a0dc0
	ctx.lr = 0x827A14F0;
	sub_827A0DC0(ctx, base);
	// lwz r3,232(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
loc_827A14F4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827a14f4
	if (!ctx.cr0.eq) goto loc_827A14F4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827a151c
	if (!ctx.cr6.eq) goto loc_827A151C;
	// bl 0x827a12d8
	ctx.lr = 0x827A151C;
	sub_827A12D8(ctx, base);
loc_827A151C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827a151c
	if (!ctx.cr0.eq) goto loc_827A151C;
	// stw r30,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r30.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r30,220
	ctx.r3.s64 = ctx.r30.s64 + 220;
	// bl 0x827a0ca8
	ctx.lr = 0x827A1548;
	sub_827A0CA8(ctx, base);
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

DEFINE_REX_FUNC(sub_827A5710) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827A5E10) {
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
	// bl 0x827a5da8
	ctx.lr = 0x827A5E28;
	sub_827A5DA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,261
	ctx.r3.s64 = 261;
	// bl 0x8278e7e8
	ctx.lr = 0x827A5E34;
	sub_8278E7E8(ctx, base);
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

DEFINE_REX_FUNC(sub_827A6DF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x827A6DF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,300(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// addi r10,r3,300
	ctx.r10.s64 = ctx.r3.s64 + 300;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x827a6e54
	if (ctx.cr6.eq) goto loc_827A6E54;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x827a6e24
	if (!ctx.cr6.eq) goto loc_827A6E24;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827a6e44
	goto loc_827A6E44;
loc_827A6E24:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_827A6E44:
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
loc_827A6E48:
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,388(r29)
	REX_STORE_U32(ctx.r29.u32 + 388, ctx.r11.u32);
	// b 0x827a6eb8
	goto loc_827A6EB8;
loc_827A6E54:
	// lwz r11,340(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 340);
	// addi r30,r29,340
	ctx.r30.s64 = ctx.r29.s64 + 340;
	// b 0x827a6eac
	goto loc_827A6EAC;
loc_827A6E60:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x827a6e74
	if (!ctx.cr6.eq) goto loc_827A6E74;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827a6e94
	goto loc_827A6E94;
loc_827A6E74:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_827A6E94:
	// addi r31,r11,-176
	ctx.r31.s64 = ctx.r11.s64 + -176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ae8b8
	ctx.lr = 0x827A6EA0;
	sub_827AE8B8(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827a6ec0
	if (!ctx.cr0.eq) goto loc_827A6EC0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_827A6EAC:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x827a6e60
	if (!ctx.cr6.eq) goto loc_827A6E60;
	// li r3,0
	ctx.r3.s64 = 0;
loc_827A6EB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
loc_827A6EC0:
	// stw r31,392(r29)
	REX_STORE_U32(ctx.r29.u32 + 392, ctx.r31.u32);
	// b 0x827a6e48
	goto loc_827A6E48;
}

DEFINE_REX_FUNC(sub_827AB2B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x827AB2B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x827a8800
	ctx.lr = 0x827AB2CC;
	sub_827A8800(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x827a8890
	ctx.lr = 0x827AB2DC;
	sub_827A8890(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x827ab304
	if (ctx.cr6.eq) goto loc_827AB304;
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x827ab2fc
	if (!ctx.cr6.eq) goto loc_827AB2FC;
	// stw r30,460(r31)
	REX_STORE_U32(ctx.r31.u32 + 460, ctx.r30.u32);
loc_827AB2FC:
	// lwz r8,448(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// b 0x827ab308
	goto loc_827AB308;
loc_827AB304:
	// lwz r8,452(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
loc_827AB308:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r31,968
	ctx.r10.s64 = ctx.r31.s64 + 968;
	// ld r6,1056(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 1056);
	// addi r9,r31,896
	ctx.r9.s64 = ctx.r31.s64 + 896;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// clrlwi r6,r6,16
	ctx.r6.u64 = ctx.r6.u32 & 0xFFFF;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r30,396(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827b1448
	ctx.lr = 0x827AB334;
	sub_827B1448(ctx, base);
	// lhz r10,1074(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 1074);
	// clrlwi r11,r27,16
	ctx.r11.u64 = ctx.r27.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827ab350
	if (ctx.cr6.lt) goto loc_827AB350;
	// lwz r11,1188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// b 0x827ab36c
	goto loc_827AB36C;
loc_827AB350:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x827ab370
	if (ctx.cr6.eq) goto loc_827AB370;
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x827ab370
	if (!ctx.cr6.eq) goto loc_827AB370;
	// lwz r11,1188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// rlwinm r11,r11,0,7,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFDFFFFFF;
loc_827AB36C:
	// stw r11,1188(r31)
	REX_STORE_U32(ctx.r31.u32 + 1188, ctx.r11.u32);
loc_827AB370:
	// lbz r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// addi r3,r31,304
	ctx.r3.s64 = ctx.r31.s64 + 304;
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,1184(r31)
	REX_STORE_U8(ctx.r31.u32 + 1184, ctx.r11.u8);
	// bl 0x827b2358
	ctx.lr = 0x827AB384;
	sub_827B2358(ctx, base);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
loc_827AB388:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827ab388
	if (!ctx.cr0.eq) goto loc_827AB388;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B4C80) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827B4C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756694
	ctx.lr = 0x827B4C90;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,48
	ctx.r30.s64 = ctx.r3.s64 + 48;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// mr r20,r9
	ctx.r20.u64 = ctx.r9.u64;
	// mr r19,r10
	ctx.r19.u64 = ctx.r10.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x827b4de4
	if (ctx.cr6.eq) goto loc_827B4DE4;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r10,r11,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r11.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_827B4CE4:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x827b4cfc
	if (ctx.cr6.eq) goto loc_827B4CFC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
	// bne 0x827b4d00
	if (!ctx.cr0.eq) goto loc_827B4D00;
loc_827B4CFC:
	// li r27,0
	ctx.r27.s64 = 0;
loc_827B4D00:
	// lbz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 72);
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// beq cr6,0x827b4d14
	if (ctx.cr6.eq) goto loc_827B4D14;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x827b4dd8
	if (!ctx.cr6.eq) goto loc_827B4DD8;
loc_827B4D14:
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827b4310
	ctx.lr = 0x827B4D34;
	sub_827B4310(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827b4dd8
	if (ctx.cr0.eq) goto loc_827B4DD8;
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x827b4dd8
	if (!ctx.cr0.eq) goto loc_827B4DD8;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x827b4dbc
	if (ctx.cr6.eq) goto loc_827B4DBC;
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827b4d60
	if (ctx.cr0.eq) goto loc_827B4D60;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827b7f40
	ctx.lr = 0x827B4D60;
	sub_827B7F40(ctx, base);
loc_827B4D60:
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// rlwinm. r11,r11,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827b4dbc
	if (ctx.cr0.eq) goto loc_827B4DBC;
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// addi r9,r31,172
	ctx.r9.s64 = ctx.r31.s64 + 172;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x827b4db0
	if (ctx.cr6.eq) goto loc_827B4DB0;
loc_827B4D7C:
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x827b4d9c
	if (!ctx.cr6.eq) goto loc_827B4D9C;
	// stw r27,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r27.u32);
	// lhz r10,76(r27)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r27.u32 + 76);
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// sth r10,76(r27)
	REX_STORE_U16(ctx.r27.u32 + 76, ctx.r10.u16);
loc_827B4D9C:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x827b4db0
	if (ctx.cr6.eq) goto loc_827B4DB0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x827b4d7c
	if (!ctx.cr0.eq) goto loc_827B4D7C;
loc_827B4DB0:
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// andi. r11,r11,65279
	ctx.r11.u64 = ctx.r11.u64 & 65279;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r11,76(r29)
	REX_STORE_U16(ctx.r29.u32 + 76, ctx.r11.u16);
loc_827B4DBC:
	// lis r4,-32646
	ctx.r4.s64 = -2139488256;
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r4,r4,4117
	ctx.r4.u64 = ctx.r4.u64 | 4117;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x827b71e0
	ctx.lr = 0x827B4DD8;
	sub_827B71E0(ctx, base);
loc_827B4DD8:
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x827b4ce4
	if (!ctx.cr6.eq) goto loc_827B4CE4;
loc_827B4DE4:
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// beq cr6,0x827b4e10
	if (ctx.cr6.eq) goto loc_827B4E10;
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_827B4E10:
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x827b4e24
	if (ctx.cr6.eq) goto loc_827B4E24;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r11.u32);
loc_827B4E24:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566e4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B8C08) {
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
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x827b8c6c
	if (ctx.cr6.lt) goto loc_827B8C6C;
	// beq cr6,0x827b8c48
	if (ctx.cr6.eq) goto loc_827B8C48;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// blt cr6,0x827b8c3c
	if (ctx.cr6.lt) goto loc_827B8C3C;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x827b8c74
	goto loc_827B8C74;
loc_827B8C3C:
	// addi r3,r3,232
	ctx.r3.s64 = ctx.r3.s64 + 232;
	// bl 0x82872dec
	ctx.lr = 0x827B8C44;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x827b8c74
	goto loc_827B8C74;
loc_827B8C48:
	// addi r3,r3,232
	ctx.r3.s64 = ctx.r3.s64 + 232;
	// bl 0x828731ac
	ctx.lr = 0x827B8C50;
	__imp__RtlTryEnterCriticalSection(ctx, base);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// ori r10,r10,16388
	ctx.r10.u64 = ctx.r10.u64 | 16388;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x827b8c74
	goto loc_827B8C74;
loc_827B8C6C:
	// addi r3,r3,232
	ctx.r3.s64 = ctx.r3.s64 + 232;
	// bl 0x82872dfc
	ctx.lr = 0x827B8C74;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_827B8C74:
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

DEFINE_REX_FUNC(sub_827C41B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x827C41B8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r8,r4,1
	ctx.r8.s64 = ctx.r4.s64 + 1;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// srawi. r11,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r31,r1,368
	ctx.r31.s64 = ctx.r1.s64 + 368;
	// li r9,0
	ctx.r9.s64 = 0;
	// ble 0x827c4208
	if (!ctx.cr0.gt) goto loc_827C4208;
	// addi r7,r3,-4
	ctx.r7.s64 = ctx.r3.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_827C41EC:
	// lfs f13,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfsu f0,8(r7)
	ea = 8 + ctx.r7.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r7.u32 = ea;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bdnz 0x827c41ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C41EC;
loc_827C4208:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// lfs f31,2524(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2524);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x827c4238
	if (ctx.cr6.eq) goto loc_827C4238;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stfs f31,0(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lfsx f0,r11,r3
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_827C4238:
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// subfic r11,r9,65
	ctx.xer.ca = ctx.r9.u32 <= 65;
	ctx.r11.u64 = static_cast<uint64_t>(65) - ctx.r9.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r11,-24504(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -24504);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x827C425C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-24504(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -24504);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x827C4274;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827c4ba8
	ctx.lr = 0x827C4284;
	sub_827C4BA8(ctx, base);
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,-20648(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24828(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24828);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fdivs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f13,7972(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7972);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x827c42d4
	if (!ctx.cr6.gt) goto loc_827C42D4;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x827c42e4
	goto loc_827C42E4;
loc_827C42D4:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_827C42E4:
	// addic. r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// ble 0x827c432c
	if (!ctx.cr0.gt) goto loc_827C432C;
	// addi r8,r29,-4
	ctx.r8.s64 = ctx.r29.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r10,16384
	ctx.r10.s64 = 16384;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_827C4300:
	// srawi r11,r10,15
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 15;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lfsx f0,r11,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfsx f13,r11,r5
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfsu f0,4(r8)
	ea = 4 + ctx.r8.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x827c4300
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C4300;
loc_827C432C:
	// mullw r11,r7,r9
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// addi r11,r11,16384
	ctx.r11.s64 = ctx.r11.s64 + 16384;
	// srawi r11,r11,15
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 15;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// blt cr6,0x827c4354
	if (ctx.cr6.lt) goto loc_827C4354;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x827c4378
	goto loc_827C4378;
loc_827C4354:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfsx f13,r11,r8
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfsx f0,r9,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r29.u32, temp.u32);
loc_827C4378:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827C9710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,22488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7528(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7528);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7456, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CB810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-6468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6464, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CF3A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4684, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D00A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-4308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4304(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4304, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D0C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,24168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3956, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D1FC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-3388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3384, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D3238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,24664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2944(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2944);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2836(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2836, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D3840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,24760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2700(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2700);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2652, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D4008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,24840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2476(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2476);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2416, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D5100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,25064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1956, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D54C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,25144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1900(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1900);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1844(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1844, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D6C30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-1168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1164, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D7600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,25712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-920(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -920);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -852, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D7B10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -704, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D8DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -140, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D9F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,26360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 364, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DB848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,26664
	ctx.r9.s64 = ctx.r11.s64 + 26664;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,26664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1104(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1104, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DC8B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,27088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1604, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DCD40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,27080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1632(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1632);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1740(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1740, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DD808) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,2056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2060(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2060, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DDC38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,27336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2076(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2076);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DEA78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,27612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2576, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DF328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,2832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2836(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2836, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E0328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,3308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3312, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E0C58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,3584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3588, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E1CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,28536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3968(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3968);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4088(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4088, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E3220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,4736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4740(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4740, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E46B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,29456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5288(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5288);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5372(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5372, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E5B28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,29648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5968, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E71D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,29912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6580(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6580);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6632, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E8298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,30040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7040(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7040);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7140(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7140, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E9960) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7808, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EAD08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,30504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8380, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EB150) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8504, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EC3C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9040, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827ED640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9580(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9580, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EDF78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9852, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EE770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9976);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10084(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10084, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EF970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31272
	ctx.r9.s64 = ctx.r11.s64 + 31272;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10608(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10608, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F12B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31528
	ctx.r9.s64 = ctx.r11.s64 + 31528;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11344, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F2A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,12028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12028);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12032(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12032, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F2B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12064, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F3A60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12396(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12396);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12500, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F40D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12688, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F57B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,13352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,13356(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13356, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F59F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,32248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13316(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13316);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13420, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F6428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,32392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13720(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13720, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F7A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,32656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14372, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F8CF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-32760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14788(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14788);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,14908(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14908, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FA0E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,15508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15508);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,15512(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15512, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FA4C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-32480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15628, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FB930) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,16224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16228(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16228, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FCBC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-32136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16644);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16764(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16764, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FCE58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-32072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16792(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16792);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16844, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FE010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17376, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FF688) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// lfs f0,-31448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31448);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-2512
	ctx.r11.s64 = ctx.r8.s64 + -2512;
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18024(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18024);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,18044(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 18044, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82801A88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-30952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10916(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10916);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,19060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19060, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82803128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-29624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19596(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19596);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19716, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82804A28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r11,r11,-26392
	ctx.r11.s64 = ctx.r11.s64 + -26392;
	// addi r9,r10,20384
	ctx.r9.s64 = ctx.r10.s64 + 20384;
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,52(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,20384(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20384, temp.u32);
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f12,8(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82806450) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-22980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22980);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21140, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82807550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,21604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21608(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21608, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828087B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-21496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22132, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280A240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-20168
	ctx.r9.s64 = ctx.r11.s64 + -20168;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-20168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22856, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280BB70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r11,r11,-18808
	ctx.r11.s64 = ctx.r11.s64 + -18808;
	// lfs f0,23532(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 23532);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280C1E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-18344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23672(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23672);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23732(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23732, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280CE80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// lfs f0,24052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24052);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-2512
	ctx.r11.s64 = ctx.r8.s64 + -2512;
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,24076(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 24076, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280ECB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,24892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24892);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24916(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 24916, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280FC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-16088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25260(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25260);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25356, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828117A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-15352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26312, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82812720) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,26800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26804, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82813210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-14264
	ctx.r9.s64 = ctx.r11.s64 + -14264;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-14264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27112(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27112, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828148D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-12608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-24000(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24000);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,27748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27748, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82815DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-10632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28200(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28200);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28288, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82817518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,28948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28952, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82817C28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-8360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29096(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29096);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29156(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82818CE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-8156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29640, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281A198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-7960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30200(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30200);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30248, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281B8D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30920, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281CE60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-7512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31488(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31488);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31552, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281DCF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,31868(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 31868);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31976(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31976, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281E908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,32324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32324);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32328(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32328, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281F338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32628, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82820760) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-6936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32384(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32384);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32320(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32320, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82821978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-31796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31792, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82822AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-6544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31296(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31296, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82823A58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-30840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30840);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30836(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30836, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82824658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-6296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30484(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30484, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82825D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29824, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82826EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-5912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29312, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82826F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-29404(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29404);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29300, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82828058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-5720
	ctx.r9.s64 = ctx.r11.s64 + -5720;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-5720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28796, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82829B90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-5400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28084);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27984(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27984, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282A208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-27900(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27900);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27796, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282B148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-27396(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27396);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27344, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282CBE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-26568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26564, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282DD60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-26044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26044);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26040, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282EA60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-4248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25708(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25708);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25660, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282F3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-4168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25488(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25488);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25388, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828309F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-24720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24716(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24716, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82830D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-24616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24612, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82832078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-24012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24012);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24008(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24008, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828323C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-23916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23916);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23912, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82832C98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-23652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23648, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82833140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-2952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23636(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23636);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23516(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23516, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82834748) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-22868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22864, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82835B98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22244, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82837640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-21444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82839098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-20672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20668(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20668, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283A080) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-20180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20176, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283B4C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19696);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19580, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283C2B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19280);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19164(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19164, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283D068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18888(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18888);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18768, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283D190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-18736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18732, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283ED70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17912, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283F400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17720(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17720, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828401E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-17316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17312, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82841400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16768(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16768, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82841480) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16752, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82842738) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16188, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82843BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,1624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15692(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15692);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15584, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82845A10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,2040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14688, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82845BC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,2040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14640, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82847198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-14008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14004, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82848378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13468, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82849988) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12820, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82849E10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-12696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12692, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284AC38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,3200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12272, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284BEA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-11736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11732, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284C5D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,3512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11520, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284D218) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,3660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11164, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284E318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-10660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10656, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284F888) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,4208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-10024(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10024, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284FD68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-9868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9864, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82850998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-9512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9508, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82850CD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-9408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9404(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9404, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82851C78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,4776
	ctx.r9.s64 = ctx.r11.s64 + 4776;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,4776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8944(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8944, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82851D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,4776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9040(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9040);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8924(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8924, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82853730) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-8160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-8156(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -8156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828542F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7808, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82855588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-7272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7268(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7268, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82856460) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-6832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6828(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6828, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828573D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,5952
	ctx.r9.s64 = ctx.r11.s64 + 5952;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,5952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6376(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6376, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828587A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,6192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5908);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5800, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82859710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5352, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285A5A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,6624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4968(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4968);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4920(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4920, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285B9D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,6864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4404(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4404);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4332(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4332, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285CE28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-3740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3736, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285DE10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,7448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3264, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285EE80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,7584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2900(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2900);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2784(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2784, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828602C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,7824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2304(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2304);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2192(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2192, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82861660) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-1608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1604, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82862770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1096);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-1092(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1092, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82862F38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,8624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-912(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -912);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -856, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82864310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,8864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-280(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -280, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82865700) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,9104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,316(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 316, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82866B10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,9360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,812(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 812);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,900(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 900, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82867F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,9616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1384(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1384);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1488(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1488, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82869330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,9872
	ctx.r9.s64 = ctx.r11.s64 + 9872;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,9872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2072, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286A6B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,10112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2532(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2532);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2640, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286B5B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,10456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3052);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3108(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3108, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286C880) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,3668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3668);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3672, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286D978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286EAE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4692, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286F9F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5128(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5128, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828709B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,11736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11736);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,5596(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 5596, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828713B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// addi r10,r10,-30032
	ctx.r10.s64 = ctx.r10.s64 + -30032;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r9,r9,6128
	ctx.r9.s64 = ctx.r9.s64 + 6128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vor128 v58,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmrghw128 v60,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vor128 v57,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vmrghw128 v63,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vmrghw128 v58,v58,v62
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrghw128 v57,v57,v61
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// vmrghw128 v62,v59,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v61,v59,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v63,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vmrghw128 v62,v62,v58
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vmrghw128 v61,v61,v57
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r9,r7
	ea = (ctx.r9.u32 + ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8289C2C0) {
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
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// lwz r8,196(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// subfic r9,r11,8
	ctx.xer.ca = ctx.r11.u32 <= 8;
	ctx.r9.u64 = static_cast<uint64_t>(8) - ctx.r11.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r8,r7,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// li r7,4
	ctx.r7.s64 = 4;
	// and r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 & ctx.r10.u64;
	// slw r7,r7,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r10.u8 & 0x3F));
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// lvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v1,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// slw r8,r9,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// bl 0x828986c0
	ctx.lr = 0x8289C310;
	sub_828986C0(ctx, base);
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

DEFINE_REX_FUNC(sub_828A8318) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x828A8320;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// lwz r11,24(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// subfic r27,r5,2
	ctx.xer.ca = ctx.r5.u32 <= 2;
	ctx.r27.u64 = static_cast<uint64_t>(2) - ctx.r5.u64;
	// lwz r4,620(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 620);
	// addi r5,r3,232
	ctx.r5.s64 = ctx.r3.s64 + 232;
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
	REX_FILL_BYTES(ea, 0, 128);
	// cmplwi cr6,r29,128
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 128, ctx.xer);
	// blt cr6,0x828a8384
	if (ctx.cr6.lt) goto loc_828A8384;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// bl 0x826f0bb0
	ctx.lr = 0x828A837C;
	sub_826F0BB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x828a83dc
	goto loc_828A83DC;
loc_828A8384:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x828a83d8
	if (!ctx.cr6.gt) goto loc_828A83D8;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_828A8390:
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
	// bdnz 0x828a8390
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828A8390;
loc_828A83D8:
	// stw r11,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r11.u32);
loc_828A83DC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r27,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 6) & 0xFFFFFFC0;
	// bne cr6,0x828a8448
	if (!ctx.cr6.eq) goto loc_828A8448;
	// lhz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// li r5,32
	ctx.r5.s64 = 32;
	// srawi r9,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 1;
	// li r4,48
	ctx.r4.s64 = 48;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// srawi r10,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 3;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v13,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
loc_828A8448:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x8288e4c8
	ctx.lr = 0x828A8454;
	sub_8288E4C8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828ADFD8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,2964(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2964);
	// lwz r10,2968(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 2968);
	// addi r11,r11,735
	ctx.r11.s64 = ctx.r11.s64 + 735;
	// lwz r9,2972(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 2972);
	// addi r8,r10,735
	ctx.r8.s64 = ctx.r10.s64 + 735;
	// lwz r10,2952(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 2952);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,2112(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2112);
	// addi r6,r9,735
	ctx.r6.s64 = ctx.r9.s64 + 735;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,732
	ctx.r9.s64 = ctx.r10.s64 + 732;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r7,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,266
	ctx.r11.s64 = ctx.r11.s64 + 266;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r7,2916(r3)
	REX_STORE_U32(ctx.r3.u32 + 2916, ctx.r7.u32);
	// lwzx r7,r5,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// stw r7,2920(r3)
	REX_STORE_U32(ctx.r3.u32 + 2920, ctx.r7.u32);
	// lwzx r5,r8,r3
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// stw r5,2924(r3)
	REX_STORE_U32(ctx.r3.u32 + 2924, ctx.r5.u32);
	// lwzx r11,r6,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// stw r11,2912(r3)
	REX_STORE_U32(ctx.r3.u32 + 2912, ctx.r11.u32);
	// stw r11,2908(r3)
	REX_STORE_U32(ctx.r3.u32 + 2908, ctx.r11.u32);
	// stw r11,2904(r3)
	REX_STORE_U32(ctx.r3.u32 + 2904, ctx.r11.u32);
	// lwz r10,2124(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 2124);
	// stw r10,2116(r3)
	REX_STORE_U32(ctx.r3.u32 + 2116, ctx.r10.u32);
	// lwzx r9,r9,r3
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// stw r9,2120(r3)
	REX_STORE_U32(ctx.r3.u32 + 2120, ctx.r9.u32);
	// b 0x826f4328
	sub_826F4328(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828AE198) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x828AE1A0;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r10,220(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r9,3744(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 3744);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// srawi r26,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r4.s32 >> 1;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// lhz r3,50(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r11,224(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 224);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r5,3748(r23)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r23.u32 + 3748);
	// rlwinm r28,r3,31,1,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,3752(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 3752);
	// lwz r3,268(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 268);
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// lbz r29,33(r31)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r31.u32 + 33);
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r28,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// bne cr6,0x828ae20c
	if (!ctx.cr6.eq) goto loc_828AE20C;
	// lwz r11,22492(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 22492);
	// stw r11,28(r27)
	REX_STORE_U32(ctx.r27.u32 + 28, ctx.r11.u32);
	// b 0x828ae21c
	goto loc_828AE21C;
loc_828AE20C:
	// rlwinm r11,r6,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r10,1480(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1480);
	// stw r10,28(r27)
	REX_STORE_U32(ctx.r27.u32 + 28, ctx.r10.u32);
loc_828AE21C:
	// mullw r11,r28,r7
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r7.s32);
	// lhz r9,74(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// lhz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rotlwi r9,r9,4
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// rotlwi r6,r6,3
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mullw r11,r6,r7
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r18,r9,r4
	ctx.r18.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r20,r11,r5
	ctx.r20.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r18,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
	// add r26,r10,r3
	ctx.r26.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r20,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x828ae500
	if (!ctx.cr6.lt) goto loc_828AE500;
	// clrlwi r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	// subf r10,r7,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r7.u64;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// li r21,0
	ctx.r21.s64 = 0;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r24,-32108
	ctx.r24.s64 = -2104229888;
	// li r19,1
	ctx.r19.s64 = 1;
	// lis r25,-32108
	ctx.r25.s64 = -2104229888;
	// b 0x828ae298
	goto loc_828AE298;
loc_828AE28C:
	// lwz r30,88(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r18,84(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_828AE298:
	// lwz r17,20920(r23)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r23.u32 + 20920);
	// mr r14,r21
	ctx.r14.u64 = ctx.r21.u64;
	// lwz r16,20924(r23)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r23.u32 + 20924);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lwz r15,20928(r23)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r23.u32 + 20928);
	// ble cr6,0x828ae4a4
	if (!ctx.cr6.gt) goto loc_828AE4A4;
	// subf r11,r20,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r20.u64;
	// mr r22,r21
	ctx.r22.u64 = ctx.r21.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_828AE2BC:
	// addi r11,r31,560
	ctx.r11.s64 = ctx.r31.s64 + 560;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
loc_828AE2CC:
	// srawi r11,r29,2
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 2;
	// lwz r9,28(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// lwzu r10,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// li r8,-128
	ctx.r8.s64 = -128;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// addi r3,r9,-128
	ctx.r3.s64 = ctx.r9.s64 + -128;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r27
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// dcbt r8,r3
	// stw r3,28(r27)
	REX_STORE_U32(ctx.r27.u32 + 28, ctx.r3.u32);
	// addi r5,r11,45
	ctx.r5.s64 = ctx.r11.s64 + 45;
	// lwz r8,392(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lwz r11,1384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1384);
	// rlwinm r4,r5,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-10400(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + -10400);
	// lwz r6,-10404(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + -10404);
	// lbz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + 4);
	// rotlwi r10,r10,6
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 6);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lhzx r8,r4,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r31.u32);
	// add r4,r30,r11
	ctx.r4.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bl 0x8273d300
	ctx.lr = 0x828AE328;
	sub_8273D300(ctx, base);
	// addi r30,r30,128
	ctx.r30.s64 = ctx.r30.s64 + 128;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r30,768
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 768, ctx.xer);
	// blt cr6,0x828ae2cc
	if (ctx.cr6.lt) goto loc_828AE2CC;
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x828ae43c
	if (ctx.cr6.eq) goto loc_828AE43C;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r11,r14,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r9,352(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// beq cr6,0x828ae3a8
	if (ctx.cr6.eq) goto loc_828AE3A8;
	// stwx r19,r9,r22
	REX_STORE_U32(ctx.r9.u32 + ctx.r22.u32, ctx.r19.u32);
	// lwz r8,348(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r19,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r19.u32);
	// lwz r5,348(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r19,r3,r5
	REX_STORE_U32(ctx.r3.u32 + ctx.r5.u32, ctx.r19.u32);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r19,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r19.u32);
	// lwz r9,348(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// stwx r19,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r19.u32);
	// b 0x828ae3ec
	goto loc_828AE3EC;
loc_828AE3A8:
	// stwx r21,r9,r22
	REX_STORE_U32(ctx.r9.u32 + ctx.r22.u32, ctx.r21.u32);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r8,348(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r21,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r21.u32);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r4,348(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r21,r3,r4
	REX_STORE_U32(ctx.r3.u32 + ctx.r4.u32, ctx.r21.u32);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r21,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r21.u32);
	// lwz r9,348(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// stwx r21,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r21.u32);
loc_828AE3EC:
	// lhz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r3,1384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1384);
	// lwz r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x828ae428
	if (!ctx.cr6.eq) goto loc_828AE428;
	// bl 0x828ae058
	ctx.lr = 0x828AE418;
	sub_828AE058(ctx, base);
	// addi r17,r17,32
	ctx.r17.s64 = ctx.r17.s64 + 32;
	// addi r16,r16,16
	ctx.r16.s64 = ctx.r16.s64 + 16;
	// addi r15,r15,16
	ctx.r15.s64 = ctx.r15.s64 + 16;
	// b 0x828ae474
	goto loc_828AE474;
loc_828AE428:
	// bl 0x828ae0a8
	ctx.lr = 0x828AE42C;
	sub_828AE0A8(ctx, base);
	// addi r17,r17,32
	ctx.r17.s64 = ctx.r17.s64 + 32;
	// addi r16,r16,16
	ctx.r16.s64 = ctx.r16.s64 + 16;
	// addi r15,r15,16
	ctx.r15.s64 = ctx.r15.s64 + 16;
	// b 0x828ae474
	goto loc_828AE474;
loc_828AE43C:
	// lhz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// lhz r8,76(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lhz r7,74(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// lwz r3,1384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1384);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// add r6,r11,r20
	ctx.r6.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bne cr6,0x828ae470
	if (!ctx.cr6.eq) goto loc_828AE470;
	// bl 0x828ae0f8
	ctx.lr = 0x828AE46C;
	sub_828AE0F8(ctx, base);
	// b 0x828ae474
	goto loc_828AE474;
loc_828AE470:
	// bl 0x828ae148
	ctx.lr = 0x828AE474;
	sub_828AE148(ctx, base);
loc_828AE474:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addi r18,r18,16
	ctx.r18.s64 = ctx.r18.s64 + 16;
	// addi r20,r20,8
	ctx.r20.s64 = ctx.r20.s64 + 8;
	// addi r26,r26,24
	ctx.r26.s64 = ctx.r26.s64 + 24;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// cmpw cr6,r14,r11
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x828ae2bc
	if (ctx.cr6.lt) goto loc_828AE2BC;
	// lwz r30,88(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rotlwi r28,r11,0
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r18,84(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_828AE4A4:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x828ae4d0
	if (ctx.cr6.eq) goto loc_828AE4D0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r9,20928(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + 20928);
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// lwz r8,20924(r23)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r23.u32 + 20924);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// lwz r7,20920(r23)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r23.u32 + 20920);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828b1c70
	ctx.lr = 0x828AE4D0;
	sub_828B1C70(ctx, base);
loc_828AE4D0:
	// lwz r11,232(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 232);
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,228(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 228);
	// add r8,r11,r20
	ctx.r8.u64 = ctx.r11.u64 + ctx.r20.u64;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r7,r18,r10
	ctx.r7.u64 = ctx.r18.u64 + ctx.r10.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// add r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// bne 0x828ae28c
	if (!ctx.cr0.eq) goto loc_828AE28C;
loc_828AE500:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

