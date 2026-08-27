#include "harmonyrecomp_funcs.123.h"

DEFINE_REX_FUNC(sub_82218240) {
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
	// bl 0x822181e8
	ctx.lr = 0x82218260;
	sub_822181E8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82218278
	if (ctx.cr0.eq) goto loc_82218278;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82218278
	if (ctx.cr6.eq) goto loc_82218278;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82218278;
	sub_825E0378(ctx, base);
loc_82218278:
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

DEFINE_REX_FUNC(sub_8221B030) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8221B038;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,732
	ctx.r11.s64 = ctx.r11.s64 + 732;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8221b07c
	goto loc_8221B07C;
loc_8221B058:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221b078
	if (ctx.cr6.eq) goto loc_8221B078;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221B078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221B078:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8221B07C:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8221b058
	if (!ctx.cr6.eq) goto loc_8221B058;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r29,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
	// beq cr6,0x8221b0c8
	if (ctx.cr6.eq) goto loc_8221B0C8;
loc_8221B0B0:
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x8221B0B8;
	sub_825E0378(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8221b0b0
	if (!ctx.cr6.eq) goto loc_8221B0B0;
loc_8221B0C8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// beq cr6,0x8221b104
	if (ctx.cr6.eq) goto loc_8221B104;
loc_8221B0EC:
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x8221B0F4;
	sub_825E0378(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8221b0ec
	if (!ctx.cr6.eq) goto loc_8221B0EC;
loc_8221B104:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221b114
	if (ctx.cr6.eq) goto loc_8221B114;
	// bl 0x825e0378
	ctx.lr = 0x8221B114;
	sub_825E0378(ctx, base);
loc_8221B114:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822233D8) {
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
	// bl 0x82223a50
	ctx.lr = 0x822233F0;
	sub_82223A50(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82223574
	if (ctx.cr0.eq) goto loc_82223574;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82223574
	if (ctx.cr6.eq) goto loc_82223574;
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
	// bne cr6,0x82223574
	if (!ctx.cr6.eq) goto loc_82223574;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82223574
	if (ctx.cr6.eq) goto loc_82223574;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82223574
	if (ctx.cr0.eq) goto loc_82223574;
	// lfs f0,2292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2296(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2296);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lfs f9,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822234e0
	if (ctx.cr6.lt) goto loc_822234E0;
	// bne cr6,0x8222356c
	if (!ctx.cr6.eq) goto loc_8222356C;
	// lfs f12,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// ld r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 24);
	// lfs f11,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f11.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// fmadds f12,f13,f13,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f13.f64, ctx.f12.f64)));
	// fsqrts f12,f12
	ctx.f12.f64 = double(float(sqrt(ctx.f12.f64)));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x82223574
	if (ctx.cr6.lt) goto loc_82223574;
	// lfs f10,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f7,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f7,f13,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f7.f64, ctx.f13.f64, ctx.f8.f64)));
	// fcmpu cr6,f8,f10
	ctx.cr6.compare(ctx.f8.f64, ctx.f10.f64);
	// blt cr6,0x82223574
	if (ctx.cr6.lt) goto loc_82223574;
	// fdivs f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// lfs f11,128(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82223560
	goto loc_82223560;
loc_822234E0:
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
	// fcmpu cr6,f9,f0
	ctx.cr6.compare(ctx.f9.f64, ctx.f0.f64);
	// blt cr6,0x822234fc
	if (ctx.cr6.lt) goto loc_822234FC;
	// li r11,1
	ctx.r11.s64 = 1;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_822234FC:
	// fdivs f1,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82223504;
	sub_822EA1A8(ctx, base);
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f8,116(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f8,f0
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// fmuls f7,f13,f9
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82223528;
	sub_822EA1A8(ctx, base);
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// lfs f13,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f1,f7,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f7.f64, ctx.f0.f64)));
	// fmr f1,f8
	ctx.f1.f64 = ctx.f8.f64;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x822ea1a8
	ctx.lr = 0x82223548;
	sub_822EA1A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// fmadds f0,f1,f7,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f7.f64, ctx.f0.f64)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
loc_82223560:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8222356C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8222356C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82223578
	goto loc_82223578;
loc_82223574:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82223578:
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

DEFINE_REX_FUNC(sub_82235910) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,67
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 67, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,135
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 135, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,167
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 167, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,131
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 131, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,163
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 163, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,247
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 247, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,231
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 231, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,215
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 215, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,199
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 199, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,243
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 243, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,227
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 227, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,211
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 211, ctx.xer);
	// beq cr6,0x82235980
	if (ctx.cr6.eq) goto loc_82235980;
	// cmplwi cr6,r11,195
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 195, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82235980:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223B460) {
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
	// lwz r6,4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,0(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x8223e398
	ctx.lr = 0x8223B488;
	sub_8223E398(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8223b498
	if (ctx.cr6.eq) goto loc_8223B498;
	// bl 0x825e0378
	ctx.lr = 0x8223B498;
	sub_825E0378(ctx, base);
loc_8223B498:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8223D7B8) {
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
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8223d820
	goto loc_8223D820;
loc_8223D7E0:
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8223d814
	if (!ctx.cr6.gt) goto loc_8223D814;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bl 0x82216520
	ctx.lr = 0x8223D800;
	sub_82216520(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,44
	ctx.r4.s64 = ctx.r31.s64 + 44;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825a1bd8
	ctx.lr = 0x8223D810;
	sub_825A1BD8(ctx, base);
	// b 0x8223d818
	goto loc_8223D818;
loc_8223D814:
	// bl 0x82216520
	ctx.lr = 0x8223D818;
	sub_82216520(ctx, base);
loc_8223D818:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8223D820:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8223d7e0
	if (!ctx.cr6.eq) goto loc_8223D7E0;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8223d878
	goto loc_8223D878;
loc_8223D838:
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8223d86c
	if (!ctx.cr6.gt) goto loc_8223D86C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bl 0x82216520
	ctx.lr = 0x8223D858;
	sub_82216520(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,56
	ctx.r4.s64 = ctx.r31.s64 + 56;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825a1bd8
	ctx.lr = 0x8223D868;
	sub_825A1BD8(ctx, base);
	// b 0x8223d870
	goto loc_8223D870;
loc_8223D86C:
	// bl 0x82216520
	ctx.lr = 0x8223D870;
	sub_82216520(ctx, base);
loc_8223D870:
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8223D878:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8223d838
	if (!ctx.cr6.eq) goto loc_8223D838;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x8223d8e8
	goto loc_8223D8E8;
loc_8223D890:
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8223d8d8
	if (!ctx.cr6.gt) goto loc_8223D8D8;
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8223d8b4
	if (ctx.cr6.eq) goto loc_8223D8B4;
	// bl 0x825e0378
	ctx.lr = 0x8223D8B4;
	sub_825E0378(ctx, base);
loc_8223D8B4:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bl 0x82216520
	ctx.lr = 0x8223D8C4;
	sub_82216520(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,104
	ctx.r4.s64 = ctx.r31.s64 + 104;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825a1bd8
	ctx.lr = 0x8223D8D4;
	sub_825A1BD8(ctx, base);
	// b 0x8223d8e0
	goto loc_8223D8E0;
loc_8223D8D8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x8223D8E0;
	sub_82216520(ctx, base);
loc_8223D8E0:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8223D8E8:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8223d890
	if (!ctx.cr6.eq) goto loc_8223D890;
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

DEFINE_REX_FUNC(sub_82249308) {
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
	// lbz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 68);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82249340
	if (ctx.cr0.eq) goto loc_82249340;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82249338
	if (ctx.cr6.eq) goto loc_82249338;
	// bl 0x8221cc98
	ctx.lr = 0x82249338;
	sub_8221CC98(ctx, base);
loc_82249338:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_82249340:
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

DEFINE_REX_FUNC(sub_82249A38) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stb r4,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r4.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82249F00) {
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
	// lbz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// std r4,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r4.u64);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// stw r9,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82249fcc
	if (ctx.cr0.eq) goto loc_82249FCC;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
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
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f13,188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82249fcc
	if (ctx.cr6.eq) goto loc_82249FCC;
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lwz r31,76(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r7,100(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r30,r1,228
	ctx.r30.s64 = ctx.r1.s64 + 228;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// bl 0x823c1be0
	ctx.lr = 0x82249FCC;
	sub_823C1BE0(ctx, base);
loc_82249FCC:
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

DEFINE_REX_FUNC(sub_822522E8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3032
	ctx.r30.s64 = ctx.r30.s64 + -3032;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225232c
	if (ctx.cr0.eq) goto loc_8225232C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,52
	ctx.r4.s64 = 52;
	// bl 0x8224f2d8
	ctx.lr = 0x82252324;
	sub_8224F2D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
loc_8225232C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// ori r9,r11,62632
	ctx.r9.u64 = ctx.r11.u64 | 62632;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3060
	ctx.r11.s64 = ctx.r11.s64 + -3060;
	// lfs f0,1536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1536);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82252360
	if (!ctx.cr6.lt) goto loc_82252360;
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// b 0x82252394
	goto loc_82252394;
loc_82252360:
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
	// addi r7,r7,9136
	ctx.r7.s64 = ctx.r7.s64 + 9136;
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
loc_82252394:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
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

DEFINE_REX_FUNC(sub_8225F128) {
	REX_FUNC_PROLOGUE();
	// addis r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 65536;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r5,-2920
	ctx.r5.s64 = ctx.r5.s64 + -2920;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// addi r8,r8,-2880
	ctx.r8.s64 = ctx.r8.s64 + -2880;
	// lwz r6,-12816(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
loc_8225F150:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8225f1a4
	if (ctx.cr6.eq) goto loc_8225F1A4;
	// lwz r10,172(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8225f1a4
	if (!ctx.cr6.eq) goto loc_8225F1A4;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8225f1a4
	if (ctx.cr6.eq) goto loc_8225F1A4;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8225f1a4
	if (!ctx.cr0.eq) goto loc_8225F1A4;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,304(r11)
	REX_STORE_U32(ctx.r11.u32 + 304, ctx.r10.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,308(r11)
	REX_STORE_U32(ctx.r11.u32 + 308, ctx.r10.u32);
	// stb r9,324(r11)
	REX_STORE_U8(ctx.r11.u32 + 324, ctx.r9.u8);
loc_8225F1A4:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8225f150
	if (ctx.cr6.lt) goto loc_8225F150;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82264338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82264340;
	__savegprlr_19(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// stfs f2,164(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r6,40
	ctx.r3.s64 = ctx.r6.s64 + 40;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f13,-1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lfs f0,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
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
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r28,8(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r27,12(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// lwz r23,4(r5)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r22,8(r5)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stw r10,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r26,0(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r25,4(r9)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r24,8(r9)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r5,12(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r9,52(r6)
	REX_STORE_U32(ctx.r6.u32 + 52, ctx.r9.u32);
	// lwz r21,0(r4)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r20,4(r4)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r19,8(r4)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r4,12(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stw r5,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r5.u32);
	// stw r28,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r28.u32);
	// stw r27,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r27.u32);
	// stw r26,40(r6)
	REX_STORE_U32(ctx.r6.u32 + 40, ctx.r26.u32);
	// stw r25,44(r6)
	REX_STORE_U32(ctx.r6.u32 + 44, ctx.r25.u32);
	// stw r24,48(r6)
	REX_STORE_U32(ctx.r6.u32 + 48, ctx.r24.u32);
	// stw r10,80(r6)
	REX_STORE_U32(ctx.r6.u32 + 80, ctx.r10.u32);
	// stw r23,84(r6)
	REX_STORE_U32(ctx.r6.u32 + 84, ctx.r23.u32);
	// stw r22,88(r6)
	REX_STORE_U32(ctx.r6.u32 + 88, ctx.r22.u32);
	// stw r21,120(r6)
	REX_STORE_U32(ctx.r6.u32 + 120, ctx.r21.u32);
	// stw r20,124(r6)
	REX_STORE_U32(ctx.r6.u32 + 124, ctx.r20.u32);
	// stw r19,128(r6)
	REX_STORE_U32(ctx.r6.u32 + 128, ctx.r19.u32);
	// stw r4,132(r6)
	REX_STORE_U32(ctx.r6.u32 + 132, ctx.r4.u32);
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stw r10,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r10.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r10,68(r6)
	REX_STORE_U32(ctx.r6.u32 + 68, ctx.r10.u32);
	// lwz r10,8(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r10,108(r6)
	REX_STORE_U32(ctx.r6.u32 + 108, ctx.r10.u32);
	// lwz r10,12(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// ld r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r5,136(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// ld r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stw r10,148(r6)
	REX_STORE_U32(ctx.r6.u32 + 148, ctx.r10.u32);
	// ld r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// std r9,32(r6)
	REX_STORE_U64(ctx.r6.u32 + 32, ctx.r9.u64);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// std r5,72(r6)
	REX_STORE_U64(ctx.r6.u32 + 72, ctx.r5.u64);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// std r7,112(r6)
	REX_STORE_U64(ctx.r6.u32 + 112, ctx.r7.u64);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// std r10,152(r6)
	REX_STORE_U64(ctx.r6.u32 + 152, ctx.r10.u64);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// addi r27,r1,224
	ctx.r27.s64 = ctx.r1.s64 + 224;
	// lwz r10,-12872(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + -12872);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8226452c
	if (ctx.cr6.eq) goto loc_8226452C;
	// lfs f12,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82264530
	goto loc_82264530;
loc_8226452C:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f0.f64;
loc_82264530:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// fdivs f10,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lwz r9,-15444(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + -15444);
	// vmulfp128 v7,v56,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// lis r6,0
	ctx.r6.s64 = 0;
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// vspltw128 v8,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// vmulfp128 v5,v55,v58
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmulfp128 v3,v54,v58
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// ori r10,r6,62572
	ctx.r10.u64 = ctx.r6.u64 | 62572;
	// lfs f12,24248(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 24248);
	ctx.f12.f64 = double(temp.f32);
	// vspltw128 v6,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// lfs f11,-5732(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -5732);
	ctx.f11.f64 = double(temp.f32);
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// stfs f12,412(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// vmaddfp v9,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lwzx r10,r30,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// vmaddfp v8,v8,v0,v7
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vmaddfp v7,v6,v0,v5
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// li r11,1
	ctx.r11.s64 = 1;
	// vmaddfp v0,v4,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vmaddfp v9,v2,v13,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stw r29,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r29.u32);
	// vmaddfp v8,v1,v13,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// stb r11,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r11.u8);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f11,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// lfs f9,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// vspltw128 v31,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v29,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// vmaddfp v6,v30,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r11,3596(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3596);
	// li r5,64
	ctx.r5.s64 = 64;
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v7,v31,v13,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// fmuls f13,f13,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fmsubs f13,f13,f12,f9
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f9.f64)));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fnmsubs f0,f0,f12,f11
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f11.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v29,v0,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v10,v10,v0,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v13,v11,v0,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// vmaddfp v0,v12,v0,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// stvx128 v10,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x822646B0;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x822646C0;
	sub_82459D08(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82295670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82295678;
	__savegprlr_29(ctx, base);
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f29.u64);
	// stfd f30,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// addi r11,r30,26028
	ctx.r11.s64 = ctx.r30.s64 + 26028;
	// addi r10,r29,14280
	ctx.r10.s64 = ctx.r29.s64 + 14280;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f2,-24416(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24416);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,1376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822956AC;
	sub_825A4A40(ctx, base);
	// lfs f0,14280(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 14280);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,26028(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 26028);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822956C4;
	sub_825A4A40(ctx, base);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r29,r30,-11140
	ctx.r29.s64 = ctx.r30.s64 + -11140;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,12748(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12748);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822956E4;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// li r4,-128
	ctx.r4.s64 = -128;
	// li r3,-208
	ctx.r3.s64 = -208;
	// bl 0x825a49b0
	ctx.lr = 0x822956F8;
	sub_825A49B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-11140(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -11140);
	ctx.f2.f64 = double(temp.f32);
	// std r31,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r31.u64);
	// lfs f1,28428(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28428);
	ctx.f1.f64 = double(temp.f32);
	// stw r3,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f29,112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8229571C;
	sub_825A4A40(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stfs f1,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82295740;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8229576c
	if (ctx.cr0.eq) goto loc_8229576C;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,24568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4956(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4956);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8221de30
	ctx.lr = 0x82295764;
	sub_8221DE30(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82295770
	goto loc_82295770;
loc_8229576C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82295770:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822957a8
	if (ctx.cr6.eq) goto loc_822957A8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82295784;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822957a8
	if (!ctx.cr6.eq) goto loc_822957A8;
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
	ctx.lr = 0x822957A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822957A8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

DEFINE_REX_FUNC(sub_8229D290) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8229D298;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x822a33c0
	ctx.lr = 0x8229D2AC;
	sub_822A33C0(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8229D2B0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822a3520
	ctx.lr = 0x8229D2C0;
	sub_822A3520(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// blt cr6,0x8229d2b0
	if (ctx.cr6.lt) goto loc_8229D2B0;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3156
	ctx.r29.s64 = ctx.r29.s64 + -3156;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8229d328
	if (ctx.cr6.lt) goto loc_8229D328;
	// bne cr6,0x8229d3d4
	if (!ctx.cr6.eq) goto loc_8229D3D4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3129
	ctx.r11.s64 = ctx.r11.s64 + -3129;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229d3d4
	if (ctx.cr0.eq) goto loc_8229D3D4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// ori r10,r10,62388
	ctx.r10.u64 = ctx.r10.u64 | 62388;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// lwzx r4,r31,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r4,10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 10, ctx.xer);
	// bge cr6,0x8229d3d4
	if (!ctx.cr6.lt) goto loc_8229D3D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8229d048
	ctx.lr = 0x8229D324;
	sub_8229D048(ctx, base);
	// b 0x8229d3d4
	goto loc_8229D3D4;
loc_8229D328:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63268
	ctx.r11.u64 = ctx.r11.u64 | 63268;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8229d3cc
	if (!ctx.cr0.eq) goto loc_8229D3CC;
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
	// lfs f1,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8229D360;
	sub_8224A2A0(ctx, base);
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r30,r31,244
	ctx.r30.s64 = ctx.r31.s64 + 244;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// ble cr6,0x8229d398
	if (!ctx.cr6.gt) goto loc_8229D398;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8229D398;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8229D398:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// ble cr6,0x8229d3cc
	if (!ctx.cr6.gt) goto loc_8229D3CC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,52(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8229D3CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8229D3CC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8229D3D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A6520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x822A6528;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af18
	ctx.lr = 0x822A6530;
	__savefpr_24(ctx, base);
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r25,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r25.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x822a6554
	if (!ctx.cr0.eq) goto loc_822A6554;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822a6b0c
	goto loc_822A6B0C;
loc_822A6554:
	// lwz r11,-4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r24,r27,16
	ctx.r24.s64 = ctx.r27.s64 + 16;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82322d08
	ctx.lr = 0x822A6570;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x822A6574;
	sub_82222370(ctx, base);
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f24,14376(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f24.f64 = double(temp.f32);
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f24
	ctx.cr6.compare(ctx.f0.f64, ctx.f24.f64);
	// blt cr6,0x822a6598
	if (ctx.cr6.lt) goto loc_822A6598;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822A6598:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822a6b08
	if (!ctx.cr0.eq) goto loc_822A6B08;
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// lfs f0,24(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// addic. r26,r25,-2
	ctx.xer.ca = ctx.r25.u32 > 1;
	ctx.r26.s64 = ctx.r25.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// fmuls f25,f0,f1
	ctx.f25.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// std r11,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r11.u64);
	// blt 0x822a6988
	if (ctx.cr0.lt) goto loc_822A6988;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f27,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f26.f64 = double(temp.f32);
loc_822A65C8:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822a6ec8
	ctx.lr = 0x822A65D4;
	sub_822A6EC8(ctx, base);
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f31,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,16(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x822a65f0
	if (ctx.cr6.lt) goto loc_822A65F0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822A65F0:
	// lfs f28,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f28.f64 = double(temp.f32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// fcmpu cr6,f28,f30
	ctx.cr6.compare(ctx.f28.f64, ctx.f30.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// bgt cr6,0x822a6608
	if (ctx.cr6.gt) goto loc_822A6608;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822A6608:
	// clrlwi. r28,r10,24
	ctx.r28.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x822a68dc
	if (ctx.cr0.eq) goto loc_822A68DC;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a68dc
	if (ctx.cr0.eq) goto loc_822A68DC;
	// addi r31,r30,8
	ctx.r31.s64 = ctx.r30.s64 + 8;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82322d08
	ctx.lr = 0x822A662C;
	sub_82322D08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x822A6638;
	sub_82322D08(ctx, base);
	// fsubs f0,f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f25.f64));
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f27,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f27.f64, -ctx.f0.f64)));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x822a6668
	if (ctx.cr6.lt) goto loc_822A6668;
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bgt cr6,0x822a6668
	if (ctx.cr6.gt) goto loc_822A6668;
	// fneg f29,f25
	ctx.f29.u64 = ctx.f25.u64 ^ 0x8000000000000000;
	// b 0x822a666c
	goto loc_822A666C;
loc_822A6668:
	// fsubs f29,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
loc_822A666C:
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// fneg f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f29.u64 ^ 0x8000000000000000;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
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
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x822A6690;
	sub_8221ADA0(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x822ea240
	ctx.lr = 0x822A66A0;
	sub_822EA240(ctx, base);
	// fadds f0,f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f25.f64));
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r11.u64);
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f27,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f27.f64, -ctx.f0.f64)));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x822a66d8
	if (ctx.cr6.lt) goto loc_822A66D8;
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bgt cr6,0x822a66d8
	if (ctx.cr6.gt) goto loc_822A66D8;
	// fmr f31,f25
	ctx.f31.f64 = ctx.f25.f64;
	// b 0x822a66dc
	goto loc_822A66DC;
loc_822A66D8:
	// fsubs f31,f28,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f28.f64 - ctx.f30.f64));
loc_822A66DC:
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f31.u64 ^ 0x8000000000000000;
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x822A6700;
	sub_8221ADA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x8273a030
	ctx.lr = 0x822A6710;
	sub_8273A030(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,520
	ctx.r3.s64 = ctx.r1.s64 + 520;
	// bl 0x822ea240
	ctx.lr = 0x822A6720;
	sub_822EA240(ctx, base);
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,304
	ctx.r11.s64 = ctx.r1.s64 + 304;
	// lfs f12,204(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// stfs f12,316(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f12,312(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// stfs f12,308(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f12,304(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// ld r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r6,r1,432
	ctx.r6.s64 = ctx.r1.s64 + 432;
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfs f11,200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f11,232(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f11,228(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f11,224(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,396(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f13,392(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// stfs f13,388(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f13,384(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lfs f10,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f12,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stfs f0,376(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,348(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f12,344(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f12,340(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,336(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f11,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stfs f10,268(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f10,264(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f10,260(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f10,256(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v13,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v10,v63,v61
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f12.f64 = double(temp.f32);
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v13,v11,v9,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x822a68c4
	if (!ctx.cr6.gt) goto loc_822A68C4;
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// ble cr6,0x822a6980
	if (!ctx.cr6.gt) goto loc_822A6980;
	// fadds f0,f30,f29
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f29.f64));
	// addi r5,r1,200
	ctx.r5.s64 = ctx.r1.s64 + 200;
	// addi r3,r1,504
	ctx.r3.s64 = ctx.r1.s64 + 504;
	// b 0x822a6950
	goto loc_822A6950;
loc_822A68C4:
	// lfs f13,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822a6980
	if (!ctx.cr6.gt) goto loc_822A6980;
	// fadds f0,f30,f31
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f31.f64));
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// b 0x822a694c
	goto loc_822A694C;
loc_822A68DC:
	// addi r31,r30,8
	ctx.r31.s64 = ctx.r30.s64 + 8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82322d08
	ctx.lr = 0x822A68F0;
	sub_82322D08(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x822a6900
	if (!ctx.cr6.eq) goto loc_822A6900;
	// fmr f31,f25
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f25.f64;
	// b 0x822a6904
	goto loc_822A6904;
loc_822A6900:
	// fneg f31,f25
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = ctx.f25.u64 ^ 0x8000000000000000;
loc_822A6904:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f31.u64 ^ 0x8000000000000000;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x822A6928;
	sub_8221ADA0(ctx, base);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,448
	ctx.r4.s64 = ctx.r1.s64 + 448;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x822ea240
	ctx.lr = 0x822A6938;
	sub_822EA240(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fadds f0,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f30.f64));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
loc_822A694C:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
loc_822A6950:
	// fmuls f13,f0,f26
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f27,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f27.f64, -ctx.f0.f64)));
	// stfs f0,16(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822A6970;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
loc_822A6980:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge 0x822a65c8
	if (!ctx.cr0.lt) goto loc_822A65C8;
loc_822A6988:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r31,1
	ctx.r31.s64 = 1;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// ld r11,2536(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2536);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// ble cr6,0x822a6ab8
	if (!ctx.cr6.gt) goto loc_822A6AB8;
loc_822A69A0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822a6ec8
	ctx.lr = 0x822A69AC;
	sub_822A6EC8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r31,-1
	ctx.r4.s64 = ctx.r31.s64 + -1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x822a6ec8
	ctx.lr = 0x822A69C0;
	sub_822A6EC8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
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
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x822A69F0;
	sub_8221ADA0(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,448
	ctx.r4.s64 = ctx.r1.s64 + 448;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x822ea240
	ctx.lr = 0x822A6A00;
	sub_822EA240(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f13,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,432
	ctx.r11.s64 = ctx.r1.s64 + 432;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r4,r30,8
	ctx.r4.s64 = ctx.r30.s64 + 8;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x822A6A9C;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r25
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r25.s32, ctx.xer);
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r11.u32);
	// blt cr6,0x822a69a0
	if (ctx.cr6.lt) goto loc_822A69A0;
loc_822A6AB8:
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82322d08
	ctx.lr = 0x822A6AC8;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x822A6ACC;
	sub_82222370(ctx, base);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,216
	ctx.r5.s64 = ctx.r1.s64 + 216;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82322d08
	ctx.lr = 0x822A6AE0;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x822A6AE4;
	sub_82222370(ctx, base);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f24
	ctx.cr6.compare(ctx.f0.f64, ctx.f24.f64);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x822a6b08
	if (ctx.cr6.lt) goto loc_822A6B08;
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fcmpu cr6,f0,f24
	ctx.cr6.compare(ctx.f0.f64, ctx.f24.f64);
	// bge cr6,0x822a6b0c
	if (!ctx.cr6.lt) goto loc_822A6B0C;
loc_822A6B08:
	// li r3,1
	ctx.r3.s64 = 1;
loc_822A6B0C:
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af64
	ctx.lr = 0x822A6B18;
	__restfpr_24(ctx, base);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D9B10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x822D9B18;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4124
	ctx.r4.s64 = ctx.r11.s64 + 4124;
	// bl 0x8222fa58
	ctx.lr = 0x822D9B2C;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// ori r7,r11,62372
	ctx.r7.u64 = ctx.r11.u64 | 62372;
	// li r9,16
	ctx.r9.s64 = 16;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// stwx r8,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r8.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// addi r6,r10,13024
	ctx.r6.s64 = ctx.r10.s64 + 13024;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// addi r9,r11,-44
	ctx.r9.s64 = ctx.r11.s64 + -44;
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
loc_822D9B6C:
	// stwu r8,44(r9)
	ea = 44 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// ld r7,3456(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r7,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r7.u64);
	// ld r7,3456(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r7,16(r10)
	REX_STORE_U64(ctx.r10.u32 + 16, ctx.r7.u64);
	// ld r7,3456(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// stfs f0,32(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32, temp.u32);
	// stfs f0,36(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// std r7,24(r10)
	REX_STORE_U64(ctx.r10.u32 + 24, ctx.r7.u64);
	// stfs f0,40(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// stbu r8,44(r10)
	ea = 44 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822d9b6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822D9B6C;
	// li r9,16
	ctx.r9.s64 = 16;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-2460
	ctx.r10.s64 = ctx.r10.s64 + -2460;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_822D9BAC:
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// ld r9,3456(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// stfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// std r9,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r9.u64);
	// stfsu f0,20(r10)
	ea = 20 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822d9bac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822D9BAC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ld r9,3456(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r10,r10,63400
	ctx.r10.u64 = ctx.r10.u64 | 63400;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r7,63440
	ctx.r7.u64 = ctx.r7.u64 | 63440;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stdx r9,r31,r10
	REX_STORE_U64(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u64);
	// ori r8,r8,63408
	ctx.r8.u64 = ctx.r8.u64 | 63408;
	// ori r7,r4,63456
	ctx.r7.u64 = ctx.r4.u64 | 63456;
	// lis r30,0
	ctx.r30.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// stw r7,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r7,r29,63468
	ctx.r7.u64 = ctx.r29.u64 | 63468;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r26,0
	ctx.r26.s64 = 0;
	// stw r7,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r7,r26,63480
	ctx.r7.u64 = ctx.r26.u64 | 63480;
	// lis r24,0
	ctx.r24.s64 = 0;
	// lis r23,0
	ctx.r23.s64 = 0;
	// stw r7,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// lis r28,0
	ctx.r28.s64 = 0;
	// ori r7,r23,63486
	ctx.r7.u64 = ctx.r23.u64 | 63486;
	// lis r21,0
	ctx.r21.s64 = 0;
	// lis r20,0
	ctx.r20.s64 = 0;
	// stw r7,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// lis r25,0
	ctx.r25.s64 = 0;
	// ori r7,r20,63492
	ctx.r7.u64 = ctx.r20.u64 | 63492;
	// lis r18,0
	ctx.r18.s64 = 0;
	// lis r17,0
	ctx.r17.s64 = 0;
	// stw r7,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// ld r9,3456(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// lis r22,0
	ctx.r22.s64 = 0;
	// stdx r9,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r9.u64);
	// ori r8,r5,63452
	ctx.r8.u64 = ctx.r5.u64 | 63452;
	// ori r9,r6,63448
	ctx.r9.u64 = ctx.r6.u64 | 63448;
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// ori r8,r30,63464
	ctx.r8.u64 = ctx.r30.u64 | 63464;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ori r9,r3,63460
	ctx.r9.u64 = ctx.r3.u64 | 63460;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// ori r8,r27,63476
	ctx.r8.u64 = ctx.r27.u64 | 63476;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// ori r9,r28,63472
	ctx.r9.u64 = ctx.r28.u64 | 63472;
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// ori r8,r24,63485
	ctx.r8.u64 = ctx.r24.u64 | 63485;
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// ori r9,r25,63484
	ctx.r9.u64 = ctx.r25.u64 | 63484;
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// ori r8,r21,63488
	ctx.r8.u64 = ctx.r21.u64 | 63488;
	// stw r9,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// ori r7,r17,63504
	ctx.r7.u64 = ctx.r17.u64 | 63504;
	// stw r8,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// ori r8,r18,63500
	ctx.r8.u64 = ctx.r18.u64 | 63500;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r7,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r7.u32);
	// ori r9,r22,63487
	ctx.r9.u64 = ctx.r22.u64 | 63487;
	// stw r8,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// lis r19,0
	ctx.r19.s64 = 0;
	// lis r16,0
	ctx.r16.s64 = 0;
	// stw r9,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// ori r9,r19,63496
	ctx.r9.u64 = ctx.r19.u64 | 63496;
	// ori r6,r16,63416
	ctx.r6.u64 = ctx.r16.u64 | 63416;
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// lis r15,0
	ctx.r15.s64 = 0;
	// ld r10,3456(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// lis r14,0
	ctx.r14.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r5,r15,63424
	ctx.r5.u64 = ctx.r15.u64 | 63424;
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// ori r3,r14,63432
	ctx.r3.u64 = ctx.r14.u64 | 63432;
	// stdx r10,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u64);
	// ori r9,r9,63508
	ctx.r9.u64 = ctx.r9.u64 | 63508;
	// lis r30,0
	ctx.r30.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// ori r15,r30,63512
	ctx.r15.u64 = ctx.r30.u64 | 63512;
	// lwz r30,120(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lis r18,0
	ctx.r18.s64 = 0;
	// lwz r16,112(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lis r29,0
	ctx.r29.s64 = 0;
	// ori r18,r18,63532
	ctx.r18.u64 = ctx.r18.u64 | 63532;
	// lwz r17,108(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// ori r29,r29,63520
	ctx.r29.u64 = ctx.r29.u64 | 63520;
	// lwz r14,116(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stdx r11,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u64);
	// ori r10,r10,63516
	ctx.r10.u64 = ctx.r10.u64 | 63516;
	// stw r30,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// lis r28,0
	ctx.r28.s64 = 0;
	// lwz r30,128(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lis r26,0
	ctx.r26.s64 = 0;
	// stw r18,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r18.u32);
	// lis r24,0
	ctx.r24.s64 = 0;
	// lwz r18,148(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lis r22,0
	ctx.r22.s64 = 0;
	// lwz r19,104(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lis r20,0
	ctx.r20.s64 = 0;
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// ori r28,r28,63524
	ctx.r28.u64 = ctx.r28.u64 | 63524;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// ori r26,r26,63525
	ctx.r26.u64 = ctx.r26.u64 | 63525;
	// lwz r30,132(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// ori r24,r24,63526
	ctx.r24.u64 = ctx.r24.u64 | 63526;
	// stw r30,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r29,124(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// ori r22,r22,63527
	ctx.r22.u64 = ctx.r22.u64 | 63527;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// ori r20,r20,63528
	ctx.r20.u64 = ctx.r20.u64 | 63528;
	// lwz r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stw r15,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r15.u32);
	// lwz r15,144(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r19,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r19.u32);
	// lwz r19,152(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r27,88(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r25,92(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// ld r11,2880(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 2880);
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r16,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r16.u32);
	// lwz r16,140(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stdx r11,r31,r3
	REX_STORE_U64(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u64);
	// ld r11,2880(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 2880);
	// stdx r11,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u64);
	// stwx r7,r31,r27
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, ctx.r7.u32);
	// lwz r9,156(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// stwx r7,r31,r25
	REX_STORE_U32(ctx.r31.u32 + ctx.r25.u32, ctx.r7.u32);
	// stfsx f0,r31,r17
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r17.u32, temp.u32);
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// stfsx f0,r31,r14
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r14.u32, temp.u32);
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// lwz r23,96(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stfsx f0,r31,r16
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r16.u32, temp.u32);
	// lwz r21,100(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfsx f0,r31,r18
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r18.u32, temp.u32);
	// stw r9,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stbx r30,r31,r15
	REX_STORE_U8(ctx.r31.u32 + ctx.r15.u32, ctx.r30.u8);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,156(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stfsx f0,r31,r23
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r23.u32, temp.u32);
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// stfsx f0,r31,r21
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r21.u32, temp.u32);
	// stb r9,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stbx r30,r31,r19
	REX_STORE_U8(ctx.r31.u32 + ctx.r19.u32, ctx.r30.u8);
	// stbx r30,r31,r28
	REX_STORE_U8(ctx.r31.u32 + ctx.r28.u32, ctx.r30.u8);
	// stbx r30,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r30.u8);
	// stbx r30,r31,r24
	REX_STORE_U8(ctx.r31.u32 + ctx.r24.u32, ctx.r30.u8);
	// stbx r30,r31,r22
	REX_STORE_U8(ctx.r31.u32 + ctx.r22.u32, ctx.r30.u8);
	// stwx r30,r31,r20
	REX_STORE_U32(ctx.r31.u32 + ctx.r20.u32, ctx.r30.u32);
	// lwz r8,152(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lwz r8,140(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lbz r8,81(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stbx r9,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u8);
	// bl 0x8247b940
	ctx.lr = 0x822D9EA8;
	sub_8247B940(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-2000
	ctx.r10.s64 = ctx.r10.s64 + -2000;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822D9EBC:
	// stwu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822d9ebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822D9EBC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FACA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822FACB0;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,13396
	ctx.r30.s64 = ctx.r30.s64 + 13396;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822facd4
	if (!ctx.cr6.eq) goto loc_822FACD4;
loc_822FACCC:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x822facf4
	goto loc_822FACF4;
loc_822FACD4:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822faccc
	if (!ctx.cr6.eq) goto loc_822FACCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232628
	ctx.lr = 0x822FACE8;
	sub_82232628(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_822FACF4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822fae28
	if (!ctx.cr0.eq) goto loc_822FAE28;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 60);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f12,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// addi r31,r1,96
	ctx.r31.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// stvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823ba820
	ctx.lr = 0x822FADF4;
	sub_823BA820(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822fae08
	if (!ctx.cr6.eq) goto loc_822FAE08;
	// bl 0x823bb888
	ctx.lr = 0x822FAE08;
	sub_823BB888(ctx, base);
loc_822FAE08:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822fae28
	if (!ctx.cr6.eq) goto loc_822FAE28;
	// lbz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822fae28
	if (ctx.cr0.eq) goto loc_822FAE28;
	// bl 0x823bba60
	ctx.lr = 0x822FAE28;
	sub_823BBA60(ctx, base);
loc_822FAE28:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823060E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823060F0;
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
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// lfs f1,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// lbz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8230614c
	if (ctx.cr0.eq) goto loc_8230614C;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82306138;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62496
	ctx.r11.u64 = ctx.r11.u64 | 62496;
	// stb r10,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r10.u8);
	// stbx r29,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u8);
loc_8230614C:
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
	// fadds f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f0,-25244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25244);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823061a0
	if (!ctx.cr6.gt) goto loc_823061A0;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// addi r11,r11,-3080
	ctx.r11.s64 = ctx.r11.s64 + -3080;
	// addi r9,r9,25000
	ctx.r9.s64 = ctx.r9.s64 + 25000;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x823061a0
	if (ctx.cr6.eq) goto loc_823061A0;
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// stfs f1,0(r10)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stb r29,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r29.u8);
	// addi r10,r9,25000
	ctx.r10.s64 = ctx.r9.s64 + 25000;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_823061A0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82309A30) {
	REX_FUNC_PROLOGUE();
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// addi r8,r8,-2984
	ctx.r8.s64 = ctx.r8.s64 + -2984;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
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
	// bne cr6,0x82309a84
	if (!ctx.cr6.eq) goto loc_82309A84;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309a84
	if (ctx.cr6.eq) goto loc_82309A84;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82309a84
	if (!ctx.cr0.eq) goto loc_82309A84;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r10.u8);
loc_82309A84:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8230B068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8230B070;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-3020
	ctx.r29.s64 = ctx.r29.s64 + -3020;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8230b0fc
	if (ctx.cr0.eq) goto loc_8230B0FC;
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r9,r9,-3160
	ctx.r9.s64 = ctx.r9.s64 + -3160;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r30,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r30.u32);
	// stw r30,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r30.u32);
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// stb r30,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r30.u8);
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
	// stb r28,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r28.u8);
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8230B0F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r30.u8);
loc_8230B0FC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// ori r11,r11,62432
	ctx.r11.u64 = ctx.r11.u64 | 62432;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x824281d8
	ctx.lr = 0x8230B110;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230b138
	if (ctx.cr0.eq) goto loc_8230B138;
	// bl 0x8242a5e0
	ctx.lr = 0x8230B11C;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8230b12c
	if (!ctx.cr0.eq) goto loc_8230B12C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8230b130
	goto loc_8230B130;
loc_8230B12C:
	// bl 0x8242aa28
	ctx.lr = 0x8230B130;
	sub_8242AA28(ctx, base);
loc_8230B130:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230b1b4
	if (ctx.cr0.eq) goto loc_8230B1B4;
loc_8230B138:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8230cf60
	ctx.lr = 0x8230B148;
	sub_8230CF60(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8230d140
	ctx.lr = 0x8230B158;
	sub_8230D140(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230b1b4
	if (ctx.cr0.eq) goto loc_8230B1B4;
	// bl 0x824281d8
	ctx.lr = 0x8230B164;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230b174
	if (ctx.cr0.eq) goto loc_8230B174;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234dc50
	ctx.lr = 0x8230B174;
	sub_8234DC50(ctx, base);
loc_8230B174:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32207
	ctx.r10.s64 = -2110717952;
	// addi r11,r11,-3024
	ctx.r11.s64 = ctx.r11.s64 + -3024;
	// addi r10,r10,-20776
	ctx.r10.s64 = ctx.r10.s64 + -20776;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8230b1b4
	if (ctx.cr6.eq) goto loc_8230B1B4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r28,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r28.u8);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32207
	ctx.r8.s64 = -2110717952;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// addi r8,r8,-20776
	ctx.r8.s64 = ctx.r8.s64 + -20776;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_8230B1B4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8230ce20
	ctx.lr = 0x8230B1BC;
	sub_8230CE20(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82312A28) {
	REX_FUNC_PROLOGUE();
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62896
	ctx.r11.u64 = ctx.r11.u64 | 62896;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82313DE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82313DF0;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4188
	ctx.r30.s64 = ctx.r11.s64 + 4188;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8222fa58
	ctx.lr = 0x82313E08;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r26,r11,62372
	ctx.r26.u64 = ctx.r11.u64 | 62372;
	// ori r11,r8,62376
	ctx.r11.u64 = ctx.r8.u64 | 62376;
	// ori r25,r10,62373
	ctx.r25.u64 = ctx.r10.u64 | 62373;
	// lfs f0,12468(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r9,r9,62374
	ctx.r9.u64 = ctx.r9.u64 | 62374;
	// ori r8,r7,62380
	ctx.r8.u64 = ctx.r7.u64 | 62380;
	// lis r27,-32226
	ctx.r27.s64 = -2111963136;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// ori r5,r5,62384
	ctx.r5.u64 = ctx.r5.u64 | 62384;
	// ori r4,r4,62392
	ctx.r4.u64 = ctx.r4.u64 | 62392;
	// ori r3,r3,62396
	ctx.r3.u64 = ctx.r3.u64 | 62396;
	// ori r29,r29,62400
	ctx.r29.u64 = ctx.r29.u64 | 62400;
	// ori r28,r28,62404
	ctx.r28.u64 = ctx.r28.u64 | 62404;
	// ori r6,r6,62412
	ctx.r6.u64 = ctx.r6.u64 | 62412;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r27,r27,15392
	ctx.r27.s64 = ctx.r27.s64 + 15392;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stbx r11,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r11.u8);
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// stbx r11,r31,r25
	REX_STORE_U8(ctx.r31.u32 + ctx.r25.u32, ctx.r11.u8);
	// addi r10,r10,-3084
	ctx.r10.s64 = ctx.r10.s64 + -3084;
	// stbx r11,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u8);
	// stbx r11,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u8);
	// ld r9,3456(r7)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r7.u32 + 3456);
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// stfsx f0,r31,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// stwx r11,r31,r4
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u32);
	// stwx r11,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u32);
	// stdx r9,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r9.u64);
	// stbx r11,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u8);
loc_82313EBC:
	// li r9,255
	ctx.r9.s64 = 255;
	// stw r9,-36(r10)
	REX_STORE_U32(ctx.r10.u32 + -36, ctx.r9.u32);
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82313ebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82313EBC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82313EDC;
	sub_8235EC48(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x82313EEC;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82313f00
	if (!ctx.cr6.lt) goto loc_82313F00;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82313F00:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82313f18
	if (ctx.cr6.eq) goto loc_82313F18;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x82313F18;
	sub_8246D8F0(ctx, base);
loc_82313F18:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82313F28;
	sub_8235EC48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8231EF38) {
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
	// bl 0x82230b40
	ctx.lr = 0x8231EF54;
	sub_82230B40(ctx, base);
	// lbz r11,544(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8231ef98
	if (ctx.cr0.eq) goto loc_8231EF98;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,-2860
	ctx.r30.s64 = ctx.r30.s64 + -2860;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x8231EF78;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8231ef98
	if (ctx.cr0.eq) goto loc_8231EF98;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231EF90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_8231EF98:
	// bl 0x824281d8
	ctx.lr = 0x8231EF9C;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231f05c
	if (ctx.cr0.eq) goto loc_8231F05C;
	// bl 0x8242a5e0
	ctx.lr = 0x8231EFA8;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8231efb8
	if (!ctx.cr0.eq) goto loc_8231EFB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8231efbc
	goto loc_8231EFBC;
loc_8231EFB8:
	// bl 0x8242aa28
	ctx.lr = 0x8231EFBC;
	sub_8242AA28(ctx, base);
loc_8231EFBC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231f06c
	if (ctx.cr0.eq) goto loc_8231F06C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823221d8
	ctx.lr = 0x8231EFCC;
	sub_823221D8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,-2812
	ctx.r11.s64 = ctx.r11.s64 + -2812;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8231f06c
	if (ctx.cr6.eq) goto loc_8231F06C;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// bl 0x82429a18
	ctx.lr = 0x8231EFEC;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r8,0
	ctx.r8.s64 = 0;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,62688
	ctx.r10.u64 = ctx.r10.u64 | 62688;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r8,62692
	ctx.r11.u64 = ctx.r8.u64 | 62692;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r4,r4,-2852
	ctx.r4.s64 = ctx.r4.s64 + -2852;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429960
	ctx.lr = 0x8231F038;
	sub_82429960(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// ori r11,r11,62704
	ctx.r11.u64 = ctx.r11.u64 | 62704;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r3,15
	ctx.r3.s64 = 15;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429ff8
	ctx.lr = 0x8231F058;
	sub_82429FF8(ctx, base);
	// b 0x8231f06c
	goto loc_8231F06C;
loc_8231F05C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// ori r11,r11,62724
	ctx.r11.u64 = ctx.r11.u64 | 62724;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
loc_8231F06C:
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

DEFINE_REX_FUNC(sub_8232AC88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8232AC90;
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
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
	// lwz r31,-13032(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
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
	// beq cr6,0x8232ad18
	if (ctx.cr6.eq) goto loc_8232AD18;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aefa8
	ctx.lr = 0x8232AD18;
	sub_823AEFA8(ctx, base);
loc_8232AD18:
	// clrlwi r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8232ad38
	if (ctx.cr6.eq) goto loc_8232AD38;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aefa8
	ctx.lr = 0x8232AD38;
	sub_823AEFA8(ctx, base);
loc_8232AD38:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8232ad50
	if (!ctx.cr6.eq) goto loc_8232AD50;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8232ade0
	goto loc_8232ADE0;
loc_8232AD50:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-28808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28808);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8232ad68
	if (ctx.cr6.lt) goto loc_8232AD68;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8232AD68:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232addc
	if (ctx.cr0.eq) goto loc_8232ADDC;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
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
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8232add0
	if (ctx.cr6.eq) goto loc_8232ADD0;
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
	// bl 0x823af5b0
	ctx.lr = 0x8232ADD0;
	sub_823AF5B0(ctx, base);
loc_8232ADD0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq 0x8232ade0
	if (ctx.cr0.eq) goto loc_8232ADE0;
loc_8232ADDC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8232ADE0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82335AF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82335B00;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// lis r11,-32205
	ctx.r11.s64 = -2110586880;
	// addi r29,r29,-3160
	ctx.r29.s64 = ctx.r29.s64 + -3160;
	// addi r11,r11,31712
	ctx.r11.s64 = ctx.r11.s64 + 31712;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82335b78
	if (ctx.cr6.eq) goto loc_82335B78;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r30,r30,-3132
	ctx.r30.s64 = ctx.r30.s64 + -3132;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82335b5c
	if (ctx.cr6.eq) goto loc_82335B5C;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x82335B44;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82335b5c
	if (ctx.cr0.eq) goto loc_82335B5C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x82335B5C;
	sub_82222BB0(ctx, base);
loc_82335B5C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32205
	ctx.r10.s64 = -2110586880;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// addi r10,r10,31712
	ctx.r10.s64 = ctx.r10.s64 + 31712;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
loc_82335B78:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82338838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// addi r9,r11,32364
	ctx.r9.s64 = ctx.r11.s64 + 32364;
	// lfs f12,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f12.f64 = double(temp.f32);
	// bne cr6,0x823388d4
	if (!ctx.cr6.eq) goto loc_823388D4;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,3040(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3040);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x82338890
	if (ctx.cr6.lt) goto loc_82338890;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82338890:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823388d4
	if (ctx.cr0.eq) goto loc_823388D4;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x823388cc
	if (ctx.cr6.gt) goto loc_823388CC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_823388CC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8233895c
	if (!ctx.cr0.eq) goto loc_8233895C;
loc_823388D4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x823389e0
	if (!ctx.cr6.eq) goto loc_823389E0;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
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
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x82338918
	if (ctx.cr6.gt) goto loc_82338918;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82338918:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823389e0
	if (ctx.cr0.eq) goto loc_823389E0;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82338954
	if (ctx.cr6.lt) goto loc_82338954;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82338954:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823389e0
	if (ctx.cr0.eq) goto loc_823389E0;
loc_8233895C:
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// lfs f13,3028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3028);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x82338998
	if (ctx.cr6.gt) goto loc_82338998;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82338998:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823389e0
	if (ctx.cr0.eq) goto loc_823389E0;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x823389d4
	if (ctx.cr6.lt) goto loc_823389D4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_823389D4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x823389e4
	if (!ctx.cr0.eq) goto loc_823389E4;
loc_823389E0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823389E4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82347238) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82347240;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3108
	ctx.r30.s64 = ctx.r30.s64 + -3108;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r11,r11,18776
	ctx.r11.s64 = ctx.r11.s64 + 18776;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82347278
	if (ctx.cr6.eq) goto loc_82347278;
	// bl 0x8221bd98
	ctx.lr = 0x82347274;
	sub_8221BD98(ctx, base);
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
loc_82347278:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232320
	ctx.lr = 0x82347280;
	sub_82232320(ctx, base);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3140
	ctx.r30.s64 = ctx.r30.s64 + -3140;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82524ba8
	ctx.lr = 0x82347290;
	sub_82524BA8(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823472a0
	if (ctx.cr6.eq) goto loc_823472A0;
	// bl 0x825e0378
	ctx.lr = 0x823472A0;
	sub_825E0378(ctx, base);
loc_823472A0:
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231c80
	ctx.lr = 0x823472AC;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r28,31
	ctx.r11.u64 = ctx.r28.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823472bc
	if (ctx.cr0.eq) goto loc_823472BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823472BC;
	sub_825E0378(ctx, base);
loc_823472BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8234BBE8) {
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
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r3,100
	ctx.r5.s64 = ctx.r3.s64 + 100;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8230d580
	ctx.lr = 0x8234BC6C;
	sub_8230D580(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x8234BC70;
	sub_82222370(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// lfs f0,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8234bcb0
	if (ctx.cr6.gt) goto loc_8234BCB0;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
loc_8234BCB0:
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

DEFINE_REX_FUNC(sub_82350488) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82350490;
	__savegprlr_26(ctx, base);
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f29.u64);
	// stfd f30,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r28,r3,100
	ctx.r28.s64 = ctx.r3.s64 + 100;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8230d580
	ctx.lr = 0x82350518;
	sub_8230D580(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f30,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f31.f64 = double(temp.f32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8231e0d8
	ctx.lr = 0x82350590;
	sub_8231E0D8(ctx, base);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r30,r31,168
	ctx.r30.s64 = ctx.r31.s64 + 168;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stw r9,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r9.u32);
	// beq cr6,0x823505dc
	if (ctx.cr6.eq) goto loc_823505DC;
loc_823505C4:
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x823505CC;
	sub_825E0378(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823505c4
	if (!ctx.cr6.eq) goto loc_823505C4;
loc_823505DC:
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82350ff8
	ctx.lr = 0x823505EC;
	sub_82350FF8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f30,204(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lis r7,-32242
	ctx.r7.s64 = -2113011712;
	// stfs f30,200(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// li r6,432
	ctx.r6.s64 = 432;
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r7,r7,31600
	ctx.r7.s64 = ctx.r7.s64 + 31600;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stfs f30,192(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// ld r27,16(r31)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// lwz r26,172(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// std r27,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r27.u64);
	// lfs f0,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r27,4(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,8(r27)
	REX_STORE_U64(ctx.r27.u32 + 8, ctx.r11.u64);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lvx128 v13,r7,r6
	ea = (ctx.r7.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addic. r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// lfd f0,136(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v8,v63,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v4,v0,v62
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v7,v63,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v6,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v3,v0,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v2,v12,v0,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v1,v10,v0,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v10,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vsel v4,v8,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vsel v8,v7,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vmaddfp v11,v0,v2,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v0,v1,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v6,v11,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v9,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vnmsubfp128 v10,v63,v9,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// li r11,0
	ctx.r11.s64 = 0;
	// vmaddfp v13,v11,v7,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v12,v12,v10,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsel v11,v13,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v62,v11
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vsel v13,v12,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v62,v61,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x82350938
	if (ctx.cr0.eq) goto loc_82350938;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
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
	// stfs f12,236(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f12,232(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f12,228(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f12,224(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f11,220(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f11,216(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f11,212(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f11,208(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
loc_8235079C:
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// clrldi r10,r29,32
	ctx.r10.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// std r10,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r10.u64);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// lfd f0,336(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 336);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,368(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x825a4a40
	ctx.lr = 0x82350820;
	sub_825A4A40(ctx, base);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// stfs f1,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// stfs f1,300(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f1,296(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f1,292(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// addi r7,r1,400
	ctx.r7.s64 = ctx.r1.s64 + 400;
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,400(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f0,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// ld r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82350888;
	sub_8255F918(ctx, base);
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82350900;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,432
	ctx.r5.s64 = ctx.r1.s64 + 432;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r27,0(r11)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// bl 0x82350ff8
	ctx.lr = 0x82350918;
	sub_82350FF8(ctx, base);
	// lwz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// std r27,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r27.u64);
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8235079c
	if (ctx.cr6.lt) goto loc_8235079C;
loc_82350938:
	// addi r5,r1,432
	ctx.r5.s64 = ctx.r1.s64 + 432;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82350ff8
	ctx.lr = 0x82350948;
	sub_82350FF8(ctx, base);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823509dc
	if (ctx.cr6.eq) goto loc_823509DC;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-10860
	ctx.r9.s64 = ctx.r11.s64 + -10860;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lis r29,-32115
	ctx.r29.s64 = -2104688640;
	// lfs f30,-10860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10860);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,4448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4448);
	ctx.f31.f64 = double(temp.f32);
	// lfs f29,236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 236);
	ctx.f29.f64 = double(temp.f32);
loc_82350990:
	// lfs f0,28112(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28112);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// bl 0x825a4a40
	ctx.lr = 0x823509A4;
	sub_825A4A40(ctx, base);
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x823509AC;
	sub_822EA1A8(ctx, base);
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,20(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// fadds f1,f9,f29
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f29.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823509C0;
	sub_822EA1A8(ctx, base);
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,24(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82350990
	if (!ctx.cr6.eq) goto loc_82350990;
loc_823509DC:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,304(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f13,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r9,20(r11)
	REX_STORE_U64(ctx.r11.u32 + 20, ctx.r9.u64);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// std r10,20(r11)
	REX_STORE_U64(ctx.r11.u32 + 20, ctx.r10.u64);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// lfd f29,-80(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237FFC8) {
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
	// lwz r10,276(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 276);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,24024
	ctx.r11.s64 = ctx.r11.s64 + 24024;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82380008
	if (ctx.cr6.eq) goto loc_82380008;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,276(r3)
	REX_STORE_U32(ctx.r3.u32 + 276, ctx.r11.u32);
	// stb r11,272(r3)
	REX_STORE_U8(ctx.r3.u32 + 272, ctx.r11.u8);
loc_82380008:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235f568
	ctx.lr = 0x82380010;
	sub_8235F568(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82380020
	if (ctx.cr0.eq) goto loc_82380020;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82380020;
	sub_825E0378(ctx, base);
loc_82380020:
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

DEFINE_REX_FUNC(sub_82381CD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 521, ctx.xer);
	// beq cr6,0x82381d10
	if (ctx.cr6.eq) goto loc_82381D10;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x82381cf4
	if (ctx.cr6.eq) goto loc_82381CF4;
	// b 0x8235f668
	sub_8235F668(ctx, base);
	return;
loc_82381CF4:
	// lbz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// lbz r10,304(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 304);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// b 0x82381d20
	goto loc_82381D20;
loc_82381D10:
	// lbz r10,304(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 304);
	// cntlzw r11,r10
	ctx.r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
loc_82381D20:
	// beq cr6,0x82381d28
	if (ctx.cr6.eq) goto loc_82381D28;
	// stb r11,305(r3)
	REX_STORE_U8(ctx.r3.u32 + 305, ctx.r11.u8);
loc_82381D28:
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82385790) {
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
	// bl 0x82386500
	ctx.lr = 0x823857A8;
	sub_82386500(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82386990
	ctx.lr = 0x823857B0;
	sub_82386990(ctx, base);
	// lwz r4,324(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823857d0
	if (ctx.cr6.eq) goto loc_823857D0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12824(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x823857C8;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
loc_823857D0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x823857D8;
	sub_8235FB40(ctx, base);
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

DEFINE_REX_FUNC(sub_82387088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r10,80
	ctx.r10.s64 = 80;
	// li r9,8
	ctx.r9.s64 = 8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// lvx128 v63,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v0,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lfs f11,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x823870d0
	if (ctx.cr6.gt) goto loc_823870D0;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x823870ec
	goto loc_823870EC;
loc_823870D0:
	// lfs f12,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x823870e4
	if (ctx.cr6.lt) goto loc_823870E4;
	// fmr f13,f11
	ctx.f13.f64 = ctx.f11.f64;
	// b 0x823870ec
	goto loc_823870EC;
loc_823870E4:
	// fdivs f13,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
loc_823870EC:
	// lwz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// fmuls f9,f13,f1
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// stfs f0,-68(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// std r10,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.r10.u64);
	// lfd f8,-96(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f10,f9,f13
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fctidz f12,f10
	ctx.f12.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f12,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f12.u64);
	// lbz r9,-89(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -89);
	// stb r9,-125(r1)
	REX_STORE_U8(ctx.r1.u32 + -125, ctx.r9.u8);
	// fcfid f12,f8
	ctx.f12.f64 = double(ctx.f8.s64);
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f13.u64);
	// lbz r9,-89(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -89);
	// stb r9,-128(r1)
	REX_STORE_U8(ctx.r1.u32 + -128, ctx.r9.u8);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// lfs f12,-30908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30908);
	ctx.f12.f64 = double(temp.f32);
	// stb r9,-127(r1)
	REX_STORE_U8(ctx.r1.u32 + -127, ctx.r9.u8);
	// stb r9,-126(r1)
	REX_STORE_U8(ctx.r1.u32 + -126, ctx.r9.u8);
loc_8238715C:
	// addi r11,r10,5
	ctx.r11.s64 = ctx.r10.s64 + 5;
	// lwz r9,-128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -128);
	// li r8,8
	ctx.r8.s64 = 8;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r7,0
	ctx.r7.s64 = 0;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lvsl v0,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// addi r6,r1,-64
	ctx.r6.s64 = ctx.r1.s64 + -64;
	// lvsl v7,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-80
	ctx.r31.s64 = ctx.r1.s64 + -80;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// mulli r11,r10,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-48(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f9.f64 = double(temp.f32);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// lfs f8,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f10,-64(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,-72(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f8,-76(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f9,-80(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// blt cr6,0x82387268
	if (ctx.cr6.lt) goto loc_82387268;
	// beq cr6,0x82387250
	if (ctx.cr6.eq) goto loc_82387250;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x82387234
	if (ctx.cr6.lt) goto loc_82387234;
	// bne cr6,0x8238727c
	if (!ctx.cr6.eq) goto loc_8238727C;
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f11,-116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -116, temp.u32);
	// fmuls f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f10,-120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -120, temp.u32);
	// ld r11,-120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// std r11,152(r4)
	REX_STORE_U64(ctx.r4.u32 + 152, ctx.r11.u64);
	// b 0x8238727c
	goto loc_8238727C;
loc_82387234:
	// fadds f10,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,-108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// fmuls f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f10,-112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// ld r11,-112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// std r11,112(r4)
	REX_STORE_U64(ctx.r4.u32 + 112, ctx.r11.u64);
	// b 0x8238727c
	goto loc_8238727C;
loc_82387250:
	// fmuls f10,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f10,-104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f0,-100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// ld r11,-104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// std r11,72(r4)
	REX_STORE_U64(ctx.r4.u32 + 72, ctx.r11.u64);
	// b 0x8238727c
	goto loc_8238727C;
loc_82387268:
	// fmuls f10,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f10,-96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f11,-92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// ld r11,-96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// std r11,32(r4)
	REX_STORE_U64(ctx.r4.u32 + 32, ctx.r11.u64);
loc_8238727C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x8238715c
	if (ctx.cr6.lt) goto loc_8238715C;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823971F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82397200;
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
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// blt cr6,0x823972c4
	if (ctx.cr6.lt) goto loc_823972C4;
	// beq cr6,0x8239729c
	if (ctx.cr6.eq) goto loc_8239729C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8239725c
	if (ctx.cr6.lt) goto loc_8239725C;
	// bne cr6,0x8239732c
	if (!ctx.cr6.eq) goto loc_8239732C;
	// lbz r11,249(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 249);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8239732c
	if (ctx.cr0.eq) goto loc_8239732C;
	// stfs f31,232(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// stb r29,248(r3)
	REX_STORE_U8(ctx.r3.u32 + 248, ctx.r29.u8);
	// stb r30,251(r3)
	REX_STORE_U8(ctx.r3.u32 + 251, ctx.r30.u8);
	// b 0x82397328
	goto loc_82397328;
loc_8239725C:
	// lfs f0,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lfs f13,244(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,232(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8239732c
	if (ctx.cr6.lt) goto loc_8239732C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stfs f31,232(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// stb r30,248(r31)
	REX_STORE_U8(ctx.r31.u32 + 248, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r29,251(r31)
	REX_STORE_U8(ctx.r31.u32 + 251, ctx.r29.u8);
	// addi r4,r31,236
	ctx.r4.s64 = ctx.r31.s64 + 236;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// li r3,246
	ctx.r3.s64 = 246;
	// bl 0x8257d438
	ctx.lr = 0x82397298;
	sub_8257D438(ctx, base);
	// b 0x8239732c
	goto loc_8239732C;
loc_8239729C:
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8239732c
	if (ctx.cr6.eq) goto loc_8239732C;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x8239732c
	if (!ctx.cr6.gt) goto loc_8239732C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f31,232(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// b 0x8239732c
	goto loc_8239732C;
loc_823972C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fd60
	ctx.lr = 0x823972CC;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8239732c
	if (!ctx.cr6.eq) goto loc_8239732C;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823972f4
	if (!ctx.cr0.eq) goto loc_823972F4;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x823972fc
	goto loc_823972FC;
loc_823972F4:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_823972FC:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stb r29,164(r11)
	REX_STORE_U8(ctx.r11.u32 + 164, ctx.r29.u8);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// lfs f0,11048(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11048);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82397328;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82397328:
	// stw r30,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r30.u32);
loc_8239732C:
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x823edfb8
	ctx.lr = 0x82397334;
	sub_823EDFB8(ctx, base);
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bgt cr6,0x82397344
	if (ctx.cr6.gt) goto loc_82397344;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82397344:
	// stb r11,250(r31)
	REX_STORE_U8(ctx.r31.u32 + 250, ctx.r11.u8);
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

DEFINE_REX_FUNC(sub_823A42F8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,236(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 236);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,236(r3)
	REX_STORE_U8(ctx.r3.u32 + 236, ctx.r11.u8);
	// stb r11,238(r3)
	REX_STORE_U8(ctx.r3.u32 + 238, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A4F60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823A4F68;
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
	// li r4,400
	ctx.r4.s64 = 400;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823A4F90;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a4fac
	if (ctx.cr0.eq) goto loc_823A4FAC;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823a4fb8
	ctx.lr = 0x823A4FA8;
	sub_823A4FB8(ctx, base);
	// b 0x823a4fb0
	goto loc_823A4FB0;
loc_823A4FAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823A4FB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A8368) {
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
	// addi r3,r3,372
	ctx.r3.s64 = ctx.r3.s64 + 372;
	// bl 0x8245d0d8
	ctx.lr = 0x823A8384;
	sub_8245D0D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x823A838C;
	sub_8235FB40(ctx, base);
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

DEFINE_REX_FUNC(sub_823AA078) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823AA080;
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
	// li r4,416
	ctx.r4.s64 = 416;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823AA0A8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823aa0c4
	if (ctx.cr0.eq) goto loc_823AA0C4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823aa0d0
	ctx.lr = 0x823AA0C0;
	sub_823AA0D0(ctx, base);
	// b 0x823aa0c8
	goto loc_823AA0C8;
loc_823AA0C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823AA0C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823ABFE8) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823ac064
	if (ctx.cr6.lt) goto loc_823AC064;
	// beq cr6,0x823ac030
	if (ctx.cr6.eq) goto loc_823AC030;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x823ac0e0
	if (!ctx.cr6.lt) goto loc_823AC0E0;
	// bl 0x823ad660
	ctx.lr = 0x823AC020;
	sub_823AD660(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823ac0f8
	ctx.lr = 0x823AC02C;
	sub_823AC0F8(ctx, base);
	// b 0x823ac0e0
	goto loc_823AC0E0;
loc_823AC030:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823AC044;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ac0e0
	if (!ctx.cr0.eq) goto loc_823AC0E0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x823ac0e0
	goto loc_823AC0E0;
loc_823AC064:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fd60
	ctx.lr = 0x823AC06C;
	sub_8235FD60(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823ac0e0
	if (!ctx.cr6.eq) goto loc_823AC0E0;
	// addi r3,r31,284
	ctx.r3.s64 = ctx.r31.s64 + 284;
	// bl 0x8245d130
	ctx.lr = 0x823AC080;
	sub_8245D130(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ac0e0
	if (!ctx.cr0.eq) goto loc_823AC0E0;
	// addi r3,r31,300
	ctx.r3.s64 = ctx.r31.s64 + 300;
	// bl 0x8245d130
	ctx.lr = 0x823AC090;
	sub_8245D130(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ac0e0
	if (!ctx.cr0.eq) goto loc_823AC0E0;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ac0b4
	if (!ctx.cr0.eq) goto loc_823AC0B4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823ac0bc
	goto loc_823AC0BC;
loc_823AC0B4:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_823AC0BC:
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823AC0D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
loc_823AC0E0:
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

DEFINE_REX_FUNC(sub_823B16C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823B16C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x823b2620
	ctx.lr = 0x823B16DC;
	sub_823B2620(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b15b8
	ctx.lr = 0x823B16E8;
	sub_823B15B8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// addi r10,r10,2668
	ctx.r10.s64 = ctx.r10.s64 + 2668;
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// beq 0x823b170c
	if (ctx.cr0.eq) goto loc_823B170C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823b1794
	goto loc_823B1794;
loc_823B170C:
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r28,8
	ctx.r29.s64 = ctx.r28.s64 + 8;
	// bl 0x825e34f0
	ctx.lr = 0x823B1728;
	sub_825E34F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825e3868
	ctx.lr = 0x823B1734;
	sub_825E3868(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b1744
	if (ctx.cr0.eq) goto loc_823B1744;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823b1794
	goto loc_823B1794;
loc_823B1744:
	// li r11,16
	ctx.r11.s64 = 16;
	// ld r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r28,r11
	ea = (ctx.r28.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// bl 0x825e34f0
	ctx.lr = 0x823B176C;
	sub_825E34F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825f2d18
	ctx.lr = 0x823B177C;
	sub_825F2D18(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825f2850
	ctx.lr = 0x823B1788;
	sub_825F2850(ctx, base);
	// vcmpgefp128. v63,v58,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v1.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
loc_823B1794:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B6540) {
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
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,17432
	ctx.r11.s64 = ctx.r11.s64 + 17432;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r31,r11,r4
	ctx.r31.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bl 0x82213210
	ctx.lr = 0x823B6568;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823b657c
	if (ctx.cr6.lt) goto loc_823B657C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823b6588
	goto loc_823B6588;
loc_823B657C:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_823B6588:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
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

DEFINE_REX_FUNC(sub_823B75D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823B75D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,8
	ctx.r29.s64 = ctx.r3.s64 + 8;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8259b6a0
	ctx.lr = 0x823B75EC;
	sub_8259B6A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x823b76bc
	if (!ctx.cr0.eq) goto loc_823B76BC;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,16384
	ctx.r11.s64 = 16384;
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823B7618;
	sub_825E02A0(ctx, base);
	// li r5,16384
	ctx.r5.s64 = 16384;
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8273a590
	ctx.lr = 0x823B762C;
	sub_8273A590(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r30,-4
	ctx.r31.s64 = ctx.r30.s64 + -4;
loc_823B7634:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b74f0
	ctx.lr = 0x823B7640;
	sub_823B74F0(ctx, base);
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,4096
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4096, ctx.xer);
	// stb r11,7(r31)
	REX_STORE_U8(ctx.r31.u32 + 7, ctx.r11.u8);
	// stb r10,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r10.u8);
	// stb r9,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// stbu r8,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r31.u32 = ea;
	// blt cr6,0x823b7634
	if (ctx.cr6.lt) goto loc_823B7634;
	// bl 0x825f9760
	ctx.lr = 0x823B7670;
	sub_825F9760(ctx, base);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825f9f68
	ctx.lr = 0x823B7684;
	sub_825F9F68(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8259c048
	ctx.lr = 0x823B7694;
	sub_8259C048(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f9cf8
	ctx.lr = 0x823B769C;
	sub_825F9CF8(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823b76ac
	if (ctx.cr6.eq) goto loc_823B76AC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x823B76AC;
	sub_825E0378(ctx, base);
loc_823B76AC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8259b6a0
	ctx.lr = 0x823B76B4;
	sub_8259B6A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x823b76c8
	goto loc_823B76C8;
loc_823B76BC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8259b620
	ctx.lr = 0x823B76C4;
	sub_8259B620(ctx, base);
	// bl 0x8259c198
	ctx.lr = 0x823B76C8;
	sub_8259C198(ctx, base);
loc_823B76C8:
	// stw r31,40(r28)
	REX_STORE_U32(ctx.r28.u32 + 40, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823BABD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823BABD8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x823bae18
	if (!ctx.cr6.eq) goto loc_823BAE18;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x823bae18
	if (ctx.cr6.lt) goto loc_823BAE18;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lbz r11,43(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 43);
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x823bae18
	if (!ctx.cr6.lt) goto loc_823BAE18;
	// lwz r10,156(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,204(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,144(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// addi r5,r9,-4080
	ctx.r5.s64 = ctx.r9.s64 + -4080;
	// lbz r11,3(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823bace8
	if (ctx.cr0.eq) goto loc_823BACE8;
	// lwa r11,36(r7)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r7.u32 + 36));
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwa r8,32(r7)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r7.u32 + 32));
	// lbz r10,2(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r3,40(r7)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r7.u32 + 40);
	// rlwinm r11,r10,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// addi r10,r9,12236
	ctx.r10.s64 = ctx.r9.s64 + 12236;
	// xor r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r3.u64;
	// lfs f0,12236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f6,236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 236);
	ctx.f6.f64 = double(temp.f32);
	// frsp f3,f12
	ctx.f3.f64 = double(float(ctx.f12.f64));
	// frsp f4,f13
	ctx.f4.f64 = double(float(ctx.f13.f64));
	// beq 0x823bac98
	if (ctx.cr0.eq) goto loc_823BAC98;
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// b 0x823bac9c
	goto loc_823BAC9C;
loc_823BAC98:
	// fmr f5,f0
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f0.f64;
loc_823BAC9C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823baca8
	if (!ctx.cr0.eq) goto loc_823BACA8;
	// fmr f6,f0
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f0.f64;
loc_823BACA8:
	// lhz r3,0(r6)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// bl 0x82301230
	ctx.lr = 0x823BACB0;
	sub_82301230(ctx, base);
	// lwz r11,24(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// lfs f0,140(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfs f12,56(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f8,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f9,f0,f13,f12
	ctx.f9.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// b 0x823badac
	goto loc_823BADAC;
loc_823BACE8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,64(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lbz r11,2(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lfs f0,60(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,16(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// rlwinm r30,r11,29,3,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lfs f13,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// xor r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r30.u64;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r30,r9,12236
	ctx.r30.s64 = ctx.r9.s64 + 12236;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f4,f0,f12
	ctx.f4.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fadds f3,f13,f0
	ctx.f3.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f0,12236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f6,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f6.f64 = double(temp.f32);
	// beq 0x823bad7c
	if (ctx.cr0.eq) goto loc_823BAD7C;
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// b 0x823bad80
	goto loc_823BAD80;
loc_823BAD7C:
	// fmr f5,f0
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f0.f64;
loc_823BAD80:
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823bad8c
	if (!ctx.cr0.eq) goto loc_823BAD8C;
	// fmr f6,f0
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f0.f64;
loc_823BAD8C:
	// lhz r10,16(r7)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r7.u32 + 16);
	// lhz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x82301230
	ctx.lr = 0x823BADA0;
	sub_82301230(ctx, base);
	// lfs f8,32(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,36(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// fmr f9,f1
	ctx.f9.f64 = ctx.f1.f64;
loc_823BADAC:
	// lfs f0,236(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x823BADB8;
	sub_822EA1A8(ctx, base);
	// lbz r11,2(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 2);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// fmuls f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// fmadds f0,f0,f5,f4
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f5.f64, ctx.f4.f64)));
	// stfs f0,0(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// bl 0x822ea1a8
	ctx.lr = 0x823BADE4;
	sub_822EA1A8(ctx, base);
	// lbz r11,2(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 2);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmuls f0,f0,f7
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
	// fmadds f0,f0,f6,f3
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f3.f64)));
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lbz r11,3(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 3);
	// stb r11,8(r4)
	REX_STORE_U8(ctx.r4.u32 + 8, ctx.r11.u8);
	// b 0x823bae1c
	goto loc_823BAE1C;
loc_823BAE18:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BAE1C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CF090) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823CF098;
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
	// bgt cr6,0x823cf12c
	if (ctx.cr6.gt) goto loc_823CF12C;
	// rlwinm r25,r6,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_823CF0C4:
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
	// bl 0x823cf748
	ctx.lr = 0x823CF100;
	sub_823CF748(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// beq cr6,0x823cf11c
	if (ctx.cr6.eq) goto loc_823CF11C;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x825e0378
	ctx.lr = 0x823CF11C;
	sub_825E0378(ctx, base);
loc_823CF11C:
	// subf r29,r24,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// cmpw cr6,r29,r24
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x823cf0c4
	if (!ctx.cr6.lt) goto loc_823CF0C4;
loc_823CF12C:
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
	// bgt cr6,0x823cf164
	if (ctx.cr6.gt) goto loc_823CF164;
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
	// bl 0x823ceb00
	ctx.lr = 0x823CF160;
	sub_823CEB00(ctx, base);
	// b 0x823cf18c
	goto loc_823CF18C;
loc_823CF164:
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
	// bl 0x823cf748
	ctx.lr = 0x823CF18C;
	sub_823CF748(ctx, base);
loc_823CF18C:
	// lwz r3,144(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf19c
	if (ctx.cr6.eq) goto loc_823CF19C;
	// bl 0x825e0378
	ctx.lr = 0x823CF19C;
	sub_825E0378(ctx, base);
loc_823CF19C:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf1ac
	if (ctx.cr6.eq) goto loc_823CF1AC;
	// bl 0x825e0378
	ctx.lr = 0x823CF1AC;
	sub_825E0378(ctx, base);
loc_823CF1AC:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D70A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823D70A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,488(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 488);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r28,476(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 476);
	// lwz r27,480(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 480);
	// bl 0x82213210
	ctx.lr = 0x823D70C0;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x823D70D0;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d7174
	if (ctx.cr0.eq) goto loc_823D7174;
	// lwz r11,476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,500(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 500);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r10,492(r31)
	REX_STORE_U8(ctx.r31.u32 + 492, ctx.r10.u8);
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r11,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x823D70F8;
	sub_82213210(ctx, base);
	// lwz r10,348(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lbz r11,4033(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,14332
	ctx.r9.s64 = ctx.r9.s64 + 14332;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// lwzx r29,r10,r9
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82213210
	ctx.lr = 0x823D7118;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// lwz r9,484(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 484);
	// mulli r10,r30,15
	ctx.r10.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(15));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r10,9528(r11)
	REX_STORE_U8(ctx.r11.u32 + 9528, ctx.r10.u8);
	// stb r9,472(r31)
	REX_STORE_U8(ctx.r31.u32 + 472, ctx.r9.u8);
	// lbz r4,492(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 492);
	// bl 0x823d6c50
	ctx.lr = 0x823D7148;
	sub_823D6C50(ctx, base);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// lwz r5,416(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x823d6098
	ctx.lr = 0x823D7164;
	sub_823D6098(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d5a38
	ctx.lr = 0x823D716C;
	sub_823D5A38(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x823d74e4
	goto loc_823D74E4;
loc_823D7174:
	// bl 0x82213210
	ctx.lr = 0x823D7178;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x823D7188;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d71d4
	if (ctx.cr0.eq) goto loc_823D71D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,492(r31)
	REX_STORE_U8(ctx.r31.u32 + 492, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,472(r31)
	REX_STORE_U8(ctx.r31.u32 + 472, ctx.r11.u8);
	// bl 0x823d6c50
	ctx.lr = 0x823D71A8;
	sub_823D6C50(ctx, base);
	// lwz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,416(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x823d6098
	ctx.lr = 0x823D71C4;
	sub_823D6098(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d5a38
	ctx.lr = 0x823D71CC;
	sub_823D5A38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d74e4
	goto loc_823D74E4;
loc_823D71D4:
	// bl 0x82213210
	ctx.lr = 0x823D71D8;
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
	ctx.lr = 0x823D71EC;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823d7200
	if (!ctx.cr0.eq) goto loc_823D7200;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d5f8
	ctx.lr = 0x823D7200;
	sub_8242D5F8(ctx, base);
loc_823D7200:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d72f4
	if (ctx.cr0.eq) goto loc_823D72F4;
	// bl 0x82213210
	ctx.lr = 0x823D720C;
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
	ctx.lr = 0x823D7220;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823d7234
	if (!ctx.cr0.eq) goto loc_823D7234;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d6e8
	ctx.lr = 0x823D7234;
	sub_8242D6E8(ctx, base);
loc_823D7234:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// lwz r10,476(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x823d72a0
	if (!ctx.cr6.eq) goto loc_823D72A0;
	// bl 0x82213210
	ctx.lr = 0x823D724C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8242d670
	ctx.lr = 0x823D7260;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823d7274
	if (!ctx.cr0.eq) goto loc_823D7274;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d670
	ctx.lr = 0x823D7274;
	sub_8242D670(ctx, base);
loc_823D7274:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// ble cr6,0x823d7298
	if (!ctx.cr6.gt) goto loc_823D7298;
	// addi r4,r29,-11
	ctx.r4.s64 = ctx.r29.s64 + -11;
loc_823D7290:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d74f0
	ctx.lr = 0x823D7298;
	sub_823D74F0(ctx, base);
loc_823D7298:
	// lwz r4,476(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// b 0x823d74d4
	goto loc_823D74D4;
loc_823D72A0:
	// lwz r11,480(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// addi r9,r11,3
	ctx.r9.s64 = ctx.r11.s64 + 3;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x823d72c4
	if (ctx.cr6.gt) goto loc_823D72C4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x823d72c4
	if (!ctx.cr6.gt) goto loc_823D72C4;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d74f0
	ctx.lr = 0x823D72C4;
	sub_823D74F0(ctx, base);
loc_823D72C4:
	// lwz r11,476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// lwz r10,328(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_823D72D8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d7298
	if (ctx.cr6.eq) goto loc_823D7298;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,14376(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// b 0x823d7298
	goto loc_823D7298;
loc_823D72F4:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7df8
	ctx.lr = 0x823D72FC;
	sub_823C7DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d738c
	if (ctx.cr0.eq) goto loc_823D738C;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7e90
	ctx.lr = 0x823D730C;
	sub_823C7E90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// lwz r10,476(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x823d7344
	if (!ctx.cr6.eq) goto loc_823D7344;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7d60
	ctx.lr = 0x823D732C;
	sub_823C7D60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// b 0x823d7290
	goto loc_823D7290;
loc_823D7344:
	// lwz r11,480(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// addi r9,r11,7
	ctx.r9.s64 = ctx.r11.s64 + 7;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x823d7374
	if (ctx.cr6.lt) goto loc_823D7374;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// ble cr6,0x823d7374
	if (!ctx.cr6.gt) goto loc_823D7374;
	// addi r10,r29,-11
	ctx.r10.s64 = ctx.r29.s64 + -11;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x823d7374
	if (!ctx.cr6.lt) goto loc_823D7374;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d74f0
	ctx.lr = 0x823D7374;
	sub_823D74F0(ctx, base);
loc_823D7374:
	// lwz r11,476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// lwz r10,328(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x823d72d8
	goto loc_823D72D8;
loc_823D738C:
	// bl 0x82213210
	ctx.lr = 0x823D7390;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x823D73A0;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d740c
	if (ctx.cr0.eq) goto loc_823D740C;
	// bl 0x82213210
	ctx.lr = 0x823D73AC;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x823D73BC;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// lwz r10,476(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// li r11,0
	ctx.r11.s64 = 0;
	// addic. r10,r10,-10
	ctx.xer.ca = ctx.r10.u32 > 9;
	ctx.r10.s64 = ctx.r10.s64 + -10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r10.u32);
	// bge 0x823d73dc
	if (!ctx.cr0.lt) goto loc_823D73DC;
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
loc_823D73DC:
	// lwz r10,480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// xoris r9,r11,32768
	ctx.r9.u64 = ctx.r11.u64 ^ 2147483648;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r10,-10
	ctx.r10.s64 = ctx.r10.s64 + -10;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addc r11,r11,r9
	ctx.xer.ca = ctx.r11.u32 + ctx.r9.u32 < ctx.r11.u32;
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 & ctx.r10.u64;
	// bl 0x823d74f0
	ctx.lr = 0x823D7400;
	sub_823D74F0(ctx, base);
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823d74a4
	goto loc_823D74A4;
loc_823D740C:
	// bl 0x82213210
	ctx.lr = 0x823D7410;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x823D7420;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// bl 0x82213210
	ctx.lr = 0x823D742C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x823D743C;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823d74e8
	if (ctx.cr0.eq) goto loc_823D74E8;
	// lwz r11,476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// addi r10,r29,-1
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x823d7460
	if (!ctx.cr6.gt) goto loc_823D7460;
	// stw r10,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r10.u32);
loc_823D7460:
	// addi r11,r29,-11
	ctx.r11.s64 = ctx.r29.s64 + -11;
	// lwz r9,480(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,10
	ctx.r9.s64 = ctx.r9.s64 + 10;
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// xoris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 ^ 2147483648;
	// addc r10,r8,r10
	ctx.xer.ca = ctx.r8.u32 + ctx.r10.u32 < ctx.r8.u32;
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x823d7490
	if (!ctx.cr6.lt) goto loc_823D7490;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_823D7490:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823d74f0
	ctx.lr = 0x823D749C;
	sub_823D74F0(ctx, base);
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_823D74A4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d74bc
	if (ctx.cr6.eq) goto loc_823D74BC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,14376(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
loc_823D74BC:
	// lwz r4,476(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 476);
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x823d74d4
	if (!ctx.cr6.eq) goto loc_823D74D4;
	// lwz r11,480(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x823d74e8
	if (ctx.cr6.eq) goto loc_823D74E8;
loc_823D74D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,480(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// bl 0x823d6098
	ctx.lr = 0x823D74E0;
	sub_823D6098(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_823D74E4:
	// bl 0x823c7bd8
	ctx.lr = 0x823D74E8;
	sub_823C7BD8(ctx, base);
loc_823D74E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F5C20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x823F5C28;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r11,32112
	ctx.r11.s64 = ctx.r11.s64 + 32112;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823f5cdc
	if (ctx.cr6.eq) goto loc_823F5CDC;
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f5c60
	if (ctx.cr6.eq) goto loc_823F5C60;
	// bl 0x823c74f0
	ctx.lr = 0x823F5C60;
	sub_823C74F0(ctx, base);
loc_823F5C60:
	// lwz r3,104(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// stw r28,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r28.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f5c74
	if (ctx.cr6.eq) goto loc_823F5C74;
	// bl 0x823f0868
	ctx.lr = 0x823F5C74;
	sub_823F0868(ctx, base);
loc_823F5C74:
	// stw r28,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f5c88
	if (ctx.cr6.eq) goto loc_823F5C88;
	// bl 0x823d1c58
	ctx.lr = 0x823F5C88;
	sub_823D1C58(ctx, base);
loc_823F5C88:
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f5c9c
	if (ctx.cr6.eq) goto loc_823F5C9C;
	// bl 0x823d1c58
	ctx.lr = 0x823F5C9C;
	sub_823D1C58(ctx, base);
loc_823F5C9C:
	// addi r30,r31,-4
	ctx.r30.s64 = ctx.r31.s64 + -4;
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// li r29,13
	ctx.r29.s64 = 13;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_823F5CAC:
	// lwz r11,-13064(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -13064);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823f5cc8
	if (ctx.cr6.eq) goto loc_823F5CC8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f5cc8
	if (ctx.cr6.eq) goto loc_823F5CC8;
	// bl 0x8235d960
	ctx.lr = 0x823F5CC8;
	sub_8235D960(ctx, base);
loc_823F5CC8:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// bne 0x823f5cac
	if (!ctx.cr0.eq) goto loc_823F5CAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823F5CDC;
	sub_825E0378(ctx, base);
loc_823F5CDC:
	// stw r28,156(r26)
	REX_STORE_U32(ctx.r26.u32 + 156, ctx.r28.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823c4360
	ctx.lr = 0x823F5CE8;
	sub_823C4360(ctx, base);
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823f5cf8
	if (ctx.cr0.eq) goto loc_823F5CF8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825e0378
	ctx.lr = 0x823F5CF8;
	sub_825E0378(ctx, base);
loc_823F5CF8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FA830) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x823FA838;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r3,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// bl 0x82213210
	ctx.lr = 0x823FA848;
	sub_82213210(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r29,19228(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// addi r15,r11,10464
	ctx.r15.s64 = ctx.r11.s64 + 10464;
	// lwz r18,80(r15)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r15.u32 + 80);
	// cmplwi r18,0
	ctx.cr0.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq 0x823fac0c
	if (ctx.cr0.eq) goto loc_823FAC0C;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// mr r20,r19
	ctx.r20.u64 = ctx.r19.u64;
	// stw r19,2356(r29)
	REX_STORE_U32(ctx.r29.u32 + 2356, ctx.r19.u32);
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
	// mr r24,r19
	ctx.r24.u64 = ctx.r19.u64;
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
	// beq cr6,0x823fac0c
	if (ctx.cr6.eq) goto loc_823FAC0C;
	// lis r10,2730
	ctx.r10.s64 = 178913280;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// ori r16,r10,43690
	ctx.r16.u64 = ctx.r10.u64 | 43690;
	// li r14,-1
	ctx.r14.s64 = -1;
	// ori r17,r9,33033
	ctx.r17.u64 = ctx.r9.u64 | 33033;
	// addi r22,r11,22072
	ctx.r22.s64 = ctx.r11.s64 + 22072;
loc_823FA8A0:
	// lwz r11,36(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 36);
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fa8f0
	if (ctx.cr0.eq) goto loc_823FA8F0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FA8C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r26
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x823fa8f0
	if (!ctx.cr6.gt) goto loc_823FA8F0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FA8E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x823fa8f4
	goto loc_823FA8F4;
loc_823FA8F0:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
loc_823FA8F4:
	// lbz r11,2354(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 2354);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823faa2c
	if (!ctx.cr0.eq) goto loc_823FAA2C;
	// beq cr6,0x823fa990
	if (ctx.cr6.eq) goto loc_823FA990;
	// cmplw cr6,r11,r16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r16.u32, ctx.xer);
	// mulli r4,r11,24
	ctx.r4.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// ble cr6,0x823fa91c
	if (!ctx.cr6.gt) goto loc_823FA91C;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
loc_823FA91C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823FA928;
	sub_825E02A0(ctx, base);
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// lwz r4,84(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mulli r5,r11,24
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// bl 0x8273a030
	ctx.lr = 0x823FA93C;
	sub_8273A030(ctx, base);
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fa980
	if (ctx.cr6.eq) goto loc_823FA980;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
loc_823FA950:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r17
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r17.u32, ctx.xer);
	// bne cr6,0x823fa968
	if (!ctx.cr6.eq) goto loc_823FA968;
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x823fa97c
	if (ctx.cr6.eq) goto loc_823FA97C;
loc_823FA968:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823fa950
	if (ctx.cr6.lt) goto loc_823FA950;
	// b 0x823fa980
	goto loc_823FA980;
loc_823FA97C:
	// li r25,1
	ctx.r25.s64 = 1;
loc_823FA980:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823fa990
	if (ctx.cr6.eq) goto loc_823FA990;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823FA990;
	sub_825E0378(ctx, base);
loc_823FA990:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a940
	ctx.lr = 0x823FA998;
	sub_8242A940(ctx, base);
	// cmplwi cr6,r3,500
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 500, ctx.xer);
	// bge cr6,0x823fa9c8
	if (!ctx.cr6.lt) goto loc_823FA9C8;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fa9c8
	if (ctx.cr6.eq) goto loc_823FA9C8;
	// lwz r11,68(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x823fa9c8
	if (ctx.cr6.eq) goto loc_823FA9C8;
	// lwz r10,72(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// add. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823fa9cc
	if (!ctx.cr0.eq) goto loc_823FA9CC;
loc_823FA9C8:
	// li r25,1
	ctx.r25.s64 = 1;
loc_823FA9CC:
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823fabbc
	if (!ctx.cr0.eq) goto loc_823FABBC;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a940
	ctx.lr = 0x823FA9DC;
	sub_8242A940(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x823fa9ec
	if (ctx.cr6.eq) goto loc_823FA9EC;
	// cmplw cr6,r24,r3
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x823fa9f8
	if (!ctx.cr6.lt) goto loc_823FA9F8;
loc_823FA9EC:
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r21,r26
	ctx.r21.u64 = ctx.r26.u64;
	// li r20,1
	ctx.r20.s64 = 1;
loc_823FA9F8:
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r11,r11,295
	ctx.r11.s64 = ctx.r11.s64 + 295;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r26,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r26.u32);
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r30,2364(r11)
	REX_STORE_U32(ctx.r11.u32 + 2364, ctx.r30.u32);
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2356(r29)
	REX_STORE_U32(ctx.r29.u32 + 2356, ctx.r11.u32);
	// b 0x823fabbc
	goto loc_823FABBC;
loc_823FAA2C:
	// beq cr6,0x823fabbc
	if (ctx.cr6.eq) goto loc_823FABBC;
	// cmplw cr6,r11,r16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r16.u32, ctx.xer);
	// mulli r4,r11,24
	ctx.r4.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// ble cr6,0x823faa40
	if (!ctx.cr6.gt) goto loc_823FAA40;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
loc_823FAA40:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823FAA4C;
	sub_825E02A0(ctx, base);
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// lwz r4,84(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mulli r5,r11,24
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// bl 0x8273a030
	ctx.lr = 0x823FAA60;
	sub_8273A030(ctx, base);
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823faaac
	if (ctx.cr6.eq) goto loc_823FAAAC;
	// lwz r9,88(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
loc_823FAA7C:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x823faa94
	if (!ctx.cr6.eq) goto loc_823FAA94;
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x823faaa8
	if (ctx.cr6.eq) goto loc_823FAAA8;
loc_823FAA94:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823faa7c
	if (ctx.cr6.lt) goto loc_823FAA7C;
	// b 0x823faaac
	goto loc_823FAAAC;
loc_823FAAA8:
	// li r28,1
	ctx.r28.s64 = 1;
loc_823FAAAC:
	// lwz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823faafc
	if (ctx.cr6.eq) goto loc_823FAAFC;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823FAAC0:
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// lwz r11,-16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -16);
	// ori r9,r9,33026
	ctx.r9.u64 = ctx.r9.u64 | 33026;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x823faaf0
	if (ctx.cr6.eq) goto loc_823FAAF0;
	// cmplw cr6,r11,r17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r17.u32, ctx.xer);
	// bne cr6,0x823faaf4
	if (!ctx.cr6.eq) goto loc_823FAAF4;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823faaf4
	if (!ctx.cr6.eq) goto loc_823FAAF4;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x823faaf4
	goto loc_823FAAF4;
loc_823FAAF0:
	// lwz r27,0(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_823FAAF4:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bdnz 0x823faac0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823FAAC0;
loc_823FAAFC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823fab0c
	if (ctx.cr6.eq) goto loc_823FAB0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823FAB0C;
	sub_825E0378(ctx, base);
loc_823FAB0C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a940
	ctx.lr = 0x823FAB14;
	sub_8242A940(ctx, base);
	// cmplwi cr6,r3,500
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 500, ctx.xer);
	// bge cr6,0x823fab44
	if (!ctx.cr6.lt) goto loc_823FAB44;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fab44
	if (ctx.cr6.eq) goto loc_823FAB44;
	// lwz r11,68(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x823fab44
	if (ctx.cr6.eq) goto loc_823FAB44;
	// lwz r10,72(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// add. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823fab48
	if (!ctx.cr0.eq) goto loc_823FAB48;
loc_823FAB44:
	// li r25,1
	ctx.r25.s64 = 1;
loc_823FAB48:
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823fabb8
	if (!ctx.cr0.eq) goto loc_823FABB8;
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fab64
	if (ctx.cr0.eq) goto loc_823FAB64;
	// bl 0x8242ad80
	ctx.lr = 0x823FAB5C;
	sub_8242AD80(ctx, base);
	// cmplw cr6,r27,r3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x823fabb8
	if (!ctx.cr6.eq) goto loc_823FABB8;
loc_823FAB64:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a940
	ctx.lr = 0x823FAB6C;
	sub_8242A940(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x823fab7c
	if (ctx.cr6.eq) goto loc_823FAB7C;
	// cmplw cr6,r24,r3
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x823fab88
	if (!ctx.cr6.lt) goto loc_823FAB88;
loc_823FAB7C:
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r20,1
	ctx.r20.s64 = 1;
	// mr r21,r26
	ctx.r21.u64 = ctx.r26.u64;
loc_823FAB88:
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r11,r11,295
	ctx.r11.s64 = ctx.r11.s64 + 295;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r26,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r26.u32);
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r30,2364(r11)
	REX_STORE_U32(ctx.r11.u32 + 2364, ctx.r30.u32);
	// lwz r11,2356(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2356);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2356(r29)
	REX_STORE_U32(ctx.r29.u32 + 2356, ctx.r11.u32);
loc_823FABB8:
	// lwz r28,260(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
loc_823FABBC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplw cr6,r26,r18
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r18.u32, ctx.xer);
	// blt cr6,0x823fa8a0
	if (ctx.cr6.lt) goto loc_823FA8A0;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x823fac0c
	if (ctx.cr6.eq) goto loc_823FAC0C;
	// lbz r11,229(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 229);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fabfc
	if (ctx.cr0.eq) goto loc_823FABFC;
	// clrlwi. r11,r20,24
	ctx.r11.u64 = ctx.r20.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fac0c
	if (ctx.cr0.eq) goto loc_823FAC0C;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x8242a1f0
	ctx.lr = 0x823FABEC;
	sub_8242A1F0(ctx, base);
	// stb r19,232(r29)
	REX_STORE_U8(ctx.r29.u32 + 232, ctx.r19.u8);
	// li r3,2
	ctx.r3.s64 = 2;
	// stb r19,231(r29)
	REX_STORE_U8(ctx.r29.u32 + 231, ctx.r19.u8);
	// b 0x823fac24
	goto loc_823FAC24;
loc_823FABFC:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// stb r11,17(r28)
	REX_STORE_U8(ctx.r28.u32 + 17, ctx.r11.u8);
	// b 0x823fac24
	goto loc_823FAC24;
loc_823FAC0C:
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// li r5,3
	ctx.r5.s64 = 3;
	// ori r4,r4,70
	ctx.r4.u64 = ctx.r4.u64 | 70;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823fac30
	ctx.lr = 0x823FAC20;
	sub_823FAC30(ctx, base);
	// li r3,5
	ctx.r3.s64 = 5;
loc_823FAC24:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241A4E8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r7,3652(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 3652);
	// lwz r6,3648(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 3648);
	// cmplwi cr6,r7,6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 6, ctx.xer);
	// blt cr6,0x8241a520
	if (ctx.cr6.lt) goto loc_8241A520;
	// addic r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// subfe r7,r11,r6
	temp.u8 = (~ctx.r11.u32 + ctx.r6.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r11.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8241A520:
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// lhz r31,2(r3)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// lhz r5,6(r3)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lhz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// lhz r9,10(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// lhz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// stb r4,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r4.u8);
	// blt cr6,0x8241a598
	if (ctx.cr6.lt) goto loc_8241A598;
	// beq cr6,0x8241a564
	if (ctx.cr6.eq) goto loc_8241A564;
	// cmplwi cr6,r7,6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 6, ctx.xer);
	// bge cr6,0x8241a5b4
	if (!ctx.cr6.lt) goto loc_8241A5B4;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r4,r7,-30812
	ctx.r4.s64 = ctx.r7.s64 + -30812;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// b 0x8241a5a8
	goto loc_8241A5A8;
loc_8241A564:
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x8241a588
	if (!ctx.cr6.eq) goto loc_8241A588;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r4,r7,-30784
	ctx.r4.s64 = ctx.r7.s64 + -30784;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// b 0x8241a5b0
	goto loc_8241A5B0;
loc_8241A588:
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r4,r7,-30812
	ctx.r4.s64 = ctx.r7.s64 + -30812;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// b 0x8241a5ac
	goto loc_8241A5AC;
loc_8241A598:
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r4,r6,-30844
	ctx.r4.s64 = ctx.r6.s64 + -30844;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_8241A5A8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
loc_8241A5AC:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
loc_8241A5B0:
	// bl 0x82738a28
	ctx.lr = 0x8241A5B4;
	sub_82738A28(ctx, base);
loc_8241A5B4:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8241A5BC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8241a5bc
	if (!ctx.cr6.eq) goto loc_8241A5BC;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bge cr6,0x8241a600
	if (!ctx.cr6.lt) goto loc_8241A600;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// subf r10,r10,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r10.u64;
loc_8241A5EC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x8241a5ec
	if (!ctx.cr0.eq) goto loc_8241A5EC;
loc_8241A600:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

DEFINE_REX_FUNC(sub_82426630) {
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
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x824266bc
	if (ctx.cr6.lt) goto loc_824266BC;
	// cmpwi cr6,r4,5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 5, ctx.xer);
	// bge cr6,0x824266bc
	if (!ctx.cr6.lt) goto loc_824266BC;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,68(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-22820
	ctx.r8.s64 = ctx.r11.s64 + -22820;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// addi r11,r11,-10552
	ctx.r11.s64 = ctx.r11.s64 + -10552;
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lis r5,-32228
	ctx.r5.s64 = -2112094208;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,-29492(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-11144(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -11144);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r9,r11
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r9,r8
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r6)
	REX_STORE_U64(ctx.r6.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x824266BC;
	sub_823C82A8(ctx, base);
loc_824266BC:
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// ori r11,r11,518
	ctx.r11.u64 = ctx.r11.u64 | 518;
	// ori r10,r10,519
	ctx.r10.u64 = ctx.r10.u64 | 519;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// rlwinm r6,r31,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ori r9,r9,521
	ctx.r9.u64 = ctx.r9.u64 | 521;
	// ori r11,r8,417
	ctx.r11.u64 = ctx.r8.u64 | 417;
	// ori r10,r7,526
	ctx.r10.u64 = ctx.r7.u64 | 526;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwzx r5,r6,r5
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// bl 0x823c7af0
	ctx.lr = 0x82426710;
	sub_823C7AF0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82426734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x823c8220
	ctx.lr = 0x8242673C;
	sub_823C8220(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
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

DEFINE_REX_FUNC(sub_8242EF20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8242EF28;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242f4f0
	if (ctx.cr6.eq) goto loc_8242F4F0;
	// bl 0x82430458
	ctx.lr = 0x8242EF48;
	sub_82430458(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f4f0
	if (!ctx.cr0.eq) goto loc_8242F4F0;
	// lbz r11,2321(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2321);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8242f4f0
	if (ctx.cr0.eq) goto loc_8242F4F0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242efa8
	if (ctx.cr6.eq) goto loc_8242EFA8;
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
	// beq cr6,0x8242ef98
	if (ctx.cr6.eq) goto loc_8242EF98;
	// lbz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 72);
	// b 0x8242ef9c
	goto loc_8242EF9C;
loc_8242EF98:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8242EF9C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242efa8
	if (!ctx.cr0.eq) goto loc_8242EFA8;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_8242EFA8:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f4f0
	if (!ctx.cr0.eq) goto loc_8242F4F0;
	// lwz r11,2964(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2964);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8258ab70
	ctx.lr = 0x8242EFC0;
	sub_8258AB70(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8242f0e8
	if (ctx.cr0.eq) goto loc_8242F0E8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lfs f0,2440(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2440);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,32384
	ctx.r11.s64 = ctx.r11.s64 + 32384;
	// lfs f13,2432(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2432);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r9,432
	ctx.r9.s64 = 432;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,2380(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 2380);
	// vrefp128 v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vcmpeqfp128 v10,v62,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// srawi r9,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 31;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subfc r8,r11,r6
	ctx.xer.ca = ctx.r6.u32 >= ctx.r11.u32;
	ctx.r8.u64 = ctx.r6.u64 - ctx.r11.u64;
	// vnmsubfp v6,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v7,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vcmpeqfp128 v9,v0,v63
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// vmaddfp v0,v0,v6,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v11,v10,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,2444(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2444);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// adde r29,r11,r9
	temp.u8 = (ctx.r11.u32 + ctx.r9.u32 < ctx.r11.u32) | (ctx.r11.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vnmsubfp v13,v8,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v0,v7,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vmulfp128 v63,v62,v13
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82432538
	ctx.lr = 0x8242F098;
	sub_82432538(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f1,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825925b8
	ctx.lr = 0x8242F0D4;
	sub_825925B8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lfs f2,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lfs f1,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82591f80
	ctx.lr = 0x8242F0E8;
	sub_82591F80(ctx, base);
loc_8242F0E8:
	// stw r26,2952(r31)
	REX_STORE_U32(ctx.r31.u32 + 2952, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243b398
	ctx.lr = 0x8242F0F4;
	sub_8243B398(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f154
	if (!ctx.cr0.eq) goto loc_8242F154;
	// lwz r11,2532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2532);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x8242F10C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8242f154
	if (ctx.cr0.eq) goto loc_8242F154;
	// lwz r11,2532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2532);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222e60
	ctx.lr = 0x8242F124;
	sub_82222E60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f154
	if (!ctx.cr0.eq) goto loc_8242F154;
	// lwz r11,2532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2532);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x8242F13C;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8242f154
	if (ctx.cr0.eq) goto loc_8242F154;
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8242f154
	if (!ctx.cr0.eq) goto loc_8242F154;
	// stb r28,74(r3)
	REX_STORE_U8(ctx.r3.u32 + 74, ctx.r28.u8);
loc_8242F154:
	// lwz r11,2380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2380);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x8242f4f0
	if (!ctx.cr6.lt) goto loc_8242F4F0;
	// lbz r10,2384(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 2384);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8242f178
	if (ctx.cr0.eq) goto loc_8242F178;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bge cr6,0x8242f178
	if (!ctx.cr6.lt) goto loc_8242F178;
	// stw r28,2380(r31)
	REX_STORE_U32(ctx.r31.u32 + 2380, ctx.r28.u32);
loc_8242F178:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8243b5d8
	ctx.lr = 0x8242F184;
	sub_8243B5D8(ctx, base);
	// li r27,6
	ctx.r27.s64 = 6;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lwz r30,2504(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 2504);
	// addi r29,r30,80
	ctx.r29.s64 = ctx.r30.s64 + 80;
loc_8242F194:
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8242f1f4
	if (ctx.cr6.eq) goto loc_8242F1F4;
	// lwz r11,-12816(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// lwz r7,104(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// rlwinm r9,r7,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r9,r9,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// bne cr6,0x8242f1c8
	if (!ctx.cr6.eq) goto loc_8242F1C8;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8242F1C8:
	// rlwinm r11,r8,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8242f1e4
	if (!ctx.cr6.eq) goto loc_8242F1E4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_8242F1E4:
	// lwz r6,2492(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 2492);
	// lwz r5,2488(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 2488);
	// lwz r4,2484(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 2484);
	// bl 0x82453140
	ctx.lr = 0x8242F1F4;
	sub_82453140(ctx, base);
loc_8242F1F4:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x8242f194
	if (!ctx.cr0.eq) goto loc_8242F194;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82430a88
	ctx.lr = 0x8242F20C;
	sub_82430A88(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2284(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2284, temp.u32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2288(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2288, temp.u32);
	// bl 0x827389e8
	ctx.lr = 0x8242F224;
	sub_827389E8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f1,2288(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2288);
	ctx.f1.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827389e8
	ctx.lr = 0x8242F23C;
	sub_827389E8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x8242f268
	if (ctx.cr6.eq) goto loc_8242F268;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ae198
	ctx.lr = 0x8242F268;
	sub_823AE198(ctx, base);
loc_8242F268:
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,436(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 436);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F284;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82435fc8
	ctx.lr = 0x8242F290;
	sub_82435FC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82431830
	ctx.lr = 0x8242F29C;
	sub_82431830(ctx, base);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F2B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8242f2c4
	if (ctx.cr0.eq) goto loc_8242F2C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82431c98
	ctx.lr = 0x8242F2C4;
	sub_82431C98(ctx, base);
loc_8242F2C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x82432478
	ctx.lr = 0x8242F2D0;
	sub_82432478(ctx, base);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lbz r4,112(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,388(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 388);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F2F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823bfa70
	ctx.lr = 0x8242F304;
	sub_823BFA70(ctx, base);
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F318;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r11,400(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 400);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F338;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	// bne 0x8242f364
	if (!ctx.cr0.eq) goto loc_8242F364;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F364;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8242F364:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824373c0
	ctx.lr = 0x8242F370;
	sub_824373C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824367d8
	ctx.lr = 0x8242F37C;
	sub_824367D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82431238
	ctx.lr = 0x8242F384;
	sub_82431238(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82437e90
	ctx.lr = 0x8242F38C;
	sub_82437E90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82437fa0
	ctx.lr = 0x8242F398;
	sub_82437FA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82438600
	ctx.lr = 0x8242F3A0;
	sub_82438600(ctx, base);
	// stw r26,2368(r31)
	REX_STORE_U32(ctx.r31.u32 + 2368, ctx.r26.u32);
	// stw r26,2372(r31)
	REX_STORE_U32(ctx.r31.u32 + 2372, ctx.r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F3C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	// bne 0x8242f3e8
	if (!ctx.cr0.eq) goto loc_8242F3E8;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F3E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8242F3E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82439e90
	ctx.lr = 0x8242F3F0;
	sub_82439E90(ctx, base);
	// lwz r11,2528(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2528);
	// lwz r30,8(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r29,12(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x8242f424
	goto loc_8242F424;
loc_8242F400:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242f420
	if (ctx.cr6.eq) goto loc_8242F420;
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
	ctx.lr = 0x8242F420;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8242F420:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_8242F424:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8242f400
	if (!ctx.cr6.eq) goto loc_8242F400;
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
	// bne 0x8242f450
	if (!ctx.cr0.eq) goto loc_8242F450;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82432638
	ctx.lr = 0x8242F448;
	sub_82432638(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82433778
	ctx.lr = 0x8242F450;
	sub_82433778(ctx, base);
loc_8242F450:
	// lfs f0,2432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2432);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,2440(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2440);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r7,-32228
	ctx.r7.s64 = -2112094208;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r9,32256
	ctx.r9.s64 = ctx.r9.s64 + 32256;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2444(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f0,620(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,2960(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2960, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f0,2956(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2956, temp.u32);
	// bl 0x82436ea0
	ctx.lr = 0x8242F4D8;
	sub_82436EA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82436fb0
	ctx.lr = 0x8242F4E0;
	sub_82436FB0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824371d0
	ctx.lr = 0x8242F4E8;
	sub_824371D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82437288
	ctx.lr = 0x8242F4F0;
	sub_82437288(ctx, base);
loc_8242F4F0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824646F8) {
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
	// lwz r31,64(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82464734
	goto loc_82464734;
loc_82464718:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82464728
	if (ctx.cr6.eq) goto loc_82464728;
	// bl 0x825e0378
	ctx.lr = 0x82464728;
	sub_825E0378(ctx, base);
loc_82464728:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
loc_82464734:
	// lwz r11,68(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82464718
	if (!ctx.cr6.eq) goto loc_82464718;
	// lwz r9,64(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r8,r30,60
	ctx.r8.s64 = ctx.r30.s64 + 60;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8246478c
	if (ctx.cr6.eq) goto loc_8246478C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82464788
	if (ctx.cr6.eq) goto loc_82464788;
loc_82464760:
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r7,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// stw r7,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82464760
	if (!ctx.cr6.eq) goto loc_82464760;
loc_82464788:
	// stw r9,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
loc_8246478C:
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

DEFINE_REX_FUNC(sub_8246AD20) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwa r10,12(r4)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r4.u32 + 12));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lwa r9,8(r4)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r4.u32 + 8));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwa r8,4(r4)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r4.u32 + 4));
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwa r10,0(r4)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r4.u32 + 0));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfd f9,112(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lfs f13,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r30,-13032(r6)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + -13032);
	// addi r7,r5,2688
	ctx.r7.s64 = ctx.r5.s64 + 2688;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// frsp f10,f9
	ctx.f10.f64 = double(float(ctx.f9.f64));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f10,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r7,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r7.u32);
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r9,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r9.u32);
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f12,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
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
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,172(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f11,164(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f11,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// ld r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r6,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r6.u64);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// beq cr6,0x8246af00
	if (ctx.cr6.eq) goto loc_8246AF00;
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
	// bl 0x823aefa8
	ctx.lr = 0x8246AEFC;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8246AF00:
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,81(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// beq cr6,0x8246af48
	if (ctx.cr6.eq) goto loc_8246AF48;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x823b0938
	ctx.lr = 0x8246AF44;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8246AF48:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

DEFINE_REX_FUNC(sub_824831C0) {
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
	// bl 0x82483218
	ctx.lr = 0x824831E0;
	sub_82483218(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824831f8
	if (ctx.cr0.eq) goto loc_824831F8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824831f8
	if (ctx.cr6.eq) goto loc_824831F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824831F8;
	sub_825E0378(ctx, base);
loc_824831F8:
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

DEFINE_REX_FUNC(sub_82487388) {
	REX_FUNC_PROLOGUE();
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// b 0x8246b058
	sub_8246B058(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824876A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824876A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824689b0
	ctx.lr = 0x824876CC;
	sub_824689B0(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r30.u32);
	// addi r10,r10,-24760
	ctx.r10.s64 = ctx.r10.s64 + -24760;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stw r11,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
	// stw r28,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r28.u32);
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r10,308(r31)
	REX_STORE_U64(ctx.r31.u32 + 308, ctx.r10.u64);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r10.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r10,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r10.u32);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r10,324(r31)
	REX_STORE_U64(ctx.r31.u32 + 324, ctx.r10.u64);
	// lwz r8,100(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// stb r11,380(r31)
	REX_STORE_U8(ctx.r31.u32 + 380, ctx.r11.u8);
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// stb r11,381(r31)
	REX_STORE_U8(ctx.r31.u32 + 381, ctx.r11.u8);
	// stfs f0,348(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// stfs f0,352(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// std r10,332(r31)
	REX_STORE_U64(ctx.r31.u32 + 332, ctx.r10.u64);
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// ori r11,r8,8192
	ctx.r11.u64 = ctx.r8.u64 | 8192;
	// stfs f0,360(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 360, temp.u32);
	// stfs f0,364(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 364, temp.u32);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248F4B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8248F4B8;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23704
	ctx.r4.s64 = ctx.r11.s64 + -23704;
	// bl 0x822167f8
	ctx.lr = 0x8248F4D4;
	sub_822167F8(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f31,18652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18652);
	ctx.f31.f64 = double(temp.f32);
loc_8248F4E4:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8248f4f8
	if (!ctx.cr6.lt) goto loc_8248F4F8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_8248F4F8:
	// clrlwi r5,r29,16
	ctx.r5.u64 = ctx.r29.u32 & 0xFFFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8248F504;
	sub_8246A2C0(ctx, base);
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248F520;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248F53C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// blt cr6,0x8248f4e4
	if (ctx.cr6.lt) goto loc_8248F4E4;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r6,4(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r5,88(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// bl 0x82517858
	ctx.lr = 0x8248F560;
	sub_82517858(ctx, base);
	// ori r11,r3,8
	ctx.r11.u64 = ctx.r3.u64 | 8;
	// li r4,5
	ctx.r4.s64 = 5;
	// lbz r6,80(r30)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r30.u32 + 80);
	// stw r11,100(r30)
	REX_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r5,88(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// bl 0x82517f98
	ctx.lr = 0x8248F57C;
	sub_82517F98(ctx, base);
	// stfs f1,196(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 196, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82518388
	ctx.lr = 0x8248F590;
	sub_82518388(ctx, base);
	// stfs f1,200(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 200, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8248F5A4;
	sub_8235EC48(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249B238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8249B240;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af20
	ctx.lr = 0x8249B248;
	__savefpr_26(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273b374
	ctx.lr = 0x8249B250;
	__savevmx_124(ctx, base);
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4068(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4068);
	// bl 0x8259be58
	ctx.lr = 0x8249B260;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8249b6e8
	if (ctx.cr0.eq) goto loc_8249B6E8;
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,400(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// addi r28,r11,14876
	ctx.r28.s64 = ctx.r11.s64 + 14876;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// fcfid f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(ctx.f12.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f31,-500(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -500);
	ctx.f31.f64 = double(temp.f32);
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lhz r30,86(r1)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r1.u32 + 86);
	// divwu. r27,r11,r30
	ctx.r27.u64 = uint32_t(ctx.r30.u32 ? ctx.r11.u32 / ctx.r30.u32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// twllei r30,0
	if (ctx.r30.s32 == 0 || ctx.r30.u32 < 0u) ppc_trap(ctx, base, 0);
	// beq 0x8249b6e8
	if (ctx.cr0.eq) goto loc_8249B6E8;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f13,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-31744
	ctx.r11.s64 = ctx.r11.s64 + -31744;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r31,312
	ctx.r4.s64 = ctx.r31.s64 + 312;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x8249B384;
	sub_82322D08(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8249b6e8
	if (ctx.cr6.eq) goto loc_8249B6E8;
	// clrldi r11,r27,32
	ctx.r11.u64 = ctx.r27.u64 & 0xFFFFFFFF;
	// vspltisw128 v127,-1
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// lfs f30,-2408(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2408);
	ctx.f30.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r11,-30592
	ctx.r11.s64 = ctx.r11.s64 + -30592;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f29,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// vslw128 v125,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r29,r31,4016
	ctx.r29.s64 = ctx.r31.s64 + 4016;
	// frsp f26,f0
	ctx.f26.f64 = double(float(ctx.f0.f64));
	// li r25,40
	ctx.r25.s64 = 40;
	// lvx128 v126,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f27,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f27.f64 = double(temp.f32);
	// lfs f28,13784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13784);
	ctx.f28.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v124,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249B404:
	// li r11,255
	ctx.r11.s64 = 255;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stfs f30,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// sth r11,404(r1)
	REX_STORE_U16(ctx.r1.u32 + 404, ctx.r11.u16);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8249B420;
	sub_825A4A40(ctx, base);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lfs f13,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r11,r26,32
	ctx.r11.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// std r11,352(r1)
	REX_STORE_U64(ctx.r1.u32 + 352, ctx.r11.u64);
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// vslw128 v62,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// fmuls f12,f1,f28
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// stfs f0,304(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// stfs f0,316(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// addi r4,r1,560
	ctx.r4.s64 = ctx.r1.s64 + 560;
	// stfs f0,312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// stfs f0,308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r30,r1,512
	ctx.r30.s64 = ctx.r1.s64 + 512;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r28,112(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// std r28,368(r1)
	REX_STORE_U64(ctx.r1.u32 + 368, ctx.r28.u64);
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v59,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,352(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 352);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
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
	// lfs f12,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f12,260(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f12,256(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,268(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// frsp f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// vmulfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v61,v125
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v125.u8)));
	// fdivs f12,f12,f26
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f12.f64 / ctx.f26.f64));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,560(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 560);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fmuls f0,f12,f27
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f27.f64));
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// fadds f0,f12,f31
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// stfs f12,204(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,332(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f13,328(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v126.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// lfs f0,448(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,544
	ctx.r6.s64 = ctx.r1.s64 + 544;
	// lfs f13,512(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 512);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// vmulfp128 v63,v63,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v126.f32)));
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// addi r5,r1,432
	ctx.r5.s64 = ctx.r1.s64 + 432;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,544(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// lfs f13,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f13.f64 = double(temp.f32);
	// ld r4,184(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// std r4,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r4.u64);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,432(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lfs f0,464(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// ld r10,176(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// std r10,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r10.u64);
	// bne cr6,0x8249b608
	if (!ctx.cr6.eq) goto loc_8249B608;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8249b614
	goto loc_8249B614;
loc_8249B608:
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r10,r10,r25
	ctx.r10.u64 = uint32_t((ctx.r25.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r25.s32 == -1)) ? ctx.r10.s32 / ctx.r25.s32 : 0);
loc_8249B614:
	// lwz r30,8(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r11,r11,r25
	ctx.r11.u64 = uint32_t((ctx.r25.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r25.s32 == -1)) ? ctx.r11.s32 / ctx.r25.s32 : 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8249b64c
	if (!ctx.cr6.lt) goto loc_8249B64C;
	// cmplwi r30,0
	ctx.cr0.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq 0x8249b640
	if (ctx.cr0.eq) goto loc_8249B640;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x8249B640;
	sub_8273A030(ctx, base);
loc_8249B640:
	// addi r11,r30,40
	ctx.r11.s64 = ctx.r30.s64 + 40;
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x8249b65c
	goto loc_8249B65C;
loc_8249B64C:
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8249d428
	ctx.lr = 0x8249B65C;
	sub_8249D428(ctx, base);
loc_8249B65C:
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,528
	ctx.r8.s64 = ctx.r1.s64 + 528;
	// lfs f13,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,496
	ctx.r9.s64 = ctx.r1.s64 + 496;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v124
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v124.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v124
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v124.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,496(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,528(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 528);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x8249B6D4;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// blt cr6,0x8249b404
	if (ctx.cr6.lt) goto loc_8249B404;
loc_8249B6E8:
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273b60c
	ctx.lr = 0x8249B6F4;
	__restvmx_124(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af6c
	ctx.lr = 0x8249B6FC;
	__restfpr_26(ctx, base);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824CF498) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824CF4A0;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824CF4C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824cf534
	if (!ctx.cr0.eq) goto loc_824CF534;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82468f80
	ctx.lr = 0x824CF4D4;
	sub_82468F80(ctx, base);
	// lwz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// lwz r10,140(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// addi r31,r30,136
	ctx.r31.s64 = ctx.r30.s64 + 136;
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824cf534
	if (ctx.cr0.eq) goto loc_824CF534;
	// addi r27,r30,44
	ctx.r27.s64 = ctx.r30.s64 + 44;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824CF4F8:
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824CF514;
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
	// blt cr6,0x824cf4f8
	if (ctx.cr6.lt) goto loc_824CF4F8;
loc_824CF534:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D31A0) {
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
	// addi r11,r11,-15544
	ctx.r11.s64 = ctx.r11.s64 + -15544;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824D31CC;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d31dc
	if (ctx.cr0.eq) goto loc_824D31DC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824D31DC;
	sub_825E0378(ctx, base);
loc_824D31DC:
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

DEFINE_REX_FUNC(sub_824D4260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824D4268;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r6,12
	ctx.r6.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// bl 0x824689b0
	ctx.lr = 0x824D4298;
	sub_824689B0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r29,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r29.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f31,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stb r28,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r28.u8);
	// addi r10,r10,-15016
	ctx.r10.s64 = ctx.r10.s64 + -15016;
	// clrlwi r29,r26,24
	ctx.r29.u64 = ctx.r26.u32 & 0xFF;
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi. r9,r27,24
	ctx.r9.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stb r30,292(r31)
	REX_STORE_U8(ctx.r31.u32 + 292, ctx.r30.u8);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stb r30,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r30.u8);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// stb r29,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r29.u8);
	// addi r3,r31,224
	ctx.r3.s64 = ctx.r31.s64 + 224;
	// beq 0x824d4314
	if (ctx.cr0.eq) goto loc_824D4314;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r4,r11,-15060
	ctx.r4.s64 = ctx.r11.s64 + -15060;
	// bl 0x82238f98
	ctx.lr = 0x824D42F8;
	sub_82238F98(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r28,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x824D430C;
	sub_8246C998(ctx, base);
	// stb r28,274(r31)
	REX_STORE_U8(ctx.r31.u32 + 274, ctx.r28.u8);
	// b 0x824d435c
	goto loc_824D435C;
loc_824D4314:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r4,r11,-16100
	ctx.r4.s64 = ctx.r11.s64 + -16100;
	// bl 0x82238f98
	ctx.lr = 0x824D4320;
	sub_82238F98(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r4,5
	ctx.r4.s64 = 5;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x824D4334;
	sub_8246C998(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-1784(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f0,f13,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// bl 0x8246ca70
	ctx.lr = 0x824D4354;
	sub_8246CA70(ctx, base);
	// li r11,1877
	ctx.r11.s64 = 1877;
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
loc_824D435C:
	// stb r29,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r29.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824DA4B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824DA4B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// clrlwi r26,r9,24
	ctx.r26.u64 = ctx.r9.u32 & 0xFF;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r4,r10,-25908
	ctx.r4.s64 = ctx.r10.s64 + -25908;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x824DA4F8;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r28,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r28.u32);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// stb r26,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r26.u8);
	// addic r8,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r8.s64 = ctx.r28.s64 + -1;
	// stb r27,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r27.u8);
	// addi r7,r10,-13928
	ctx.r7.s64 = ctx.r10.s64 + -13928;
	// subfe r10,r8,r28
	temp.u8 = (~ctx.r8.u32 + ctx.r28.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r28.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r8.u64 + ctx.r28.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lfs f0,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,300(r31)
	REX_STORE_U8(ctx.r31.u32 + 300, ctx.r10.u8);
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r9.u32);
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stw r9,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r9.u32);
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r8,100(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// rlwinm. r8,r8,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x824da758
	if (ctx.cr0.eq) goto loc_824DA758;
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x824da65c
	if (!ctx.cr6.eq) goto loc_824DA65C;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r9,32544
	ctx.r9.s64 = ctx.r9.s64 + 32544;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
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
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824da5ac
	if (ctx.cr0.eq) goto loc_824DA5AC;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// b 0x824da5b0
	goto loc_824DA5B0;
loc_824DA5AC:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f0.f64;
loc_824DA5B0:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-2184
	ctx.r11.s64 = ctx.r11.s64 + -2184;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,624(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
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
	// b 0x824da74c
	goto loc_824DA74C;
loc_824DA65C:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,32640
	ctx.r8.s64 = ctx.r8.s64 + 32640;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
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
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824da698
	if (ctx.cr0.eq) goto loc_824DA698;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// b 0x824da69c
	goto loc_824DA69C;
loc_824DA698:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f0.f64;
loc_824DA69C:
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f13,-2184(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2184);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,-30128(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_824DA74C:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// b 0x824da76c
	goto loc_824DA76C;
loc_824DA758:
	// stb r9,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r9.u8);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_824DA76C:
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,274(r31)
	REX_STORE_U8(ctx.r31.u32 + 274, ctx.r11.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F0298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x824F02A0;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r4,r11,-10620
	ctx.r4.s64 = ctx.r11.s64 + -10620;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// bl 0x824689b0
	ctx.lr = 0x824F02D8;
	sub_824689B0(ctx, base);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r11,20
	ctx.r11.s64 = 20;
	// addi r7,r8,12236
	ctx.r7.s64 = ctx.r8.s64 + 12236;
	// addi r9,r10,-10608
	ctx.r9.s64 = ctx.r10.s64 + -10608;
	// addi r10,r31,276
	ctx.r10.s64 = ctx.r31.s64 + 276;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,232(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
loc_824F0304:
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// ld r8,2880(r9)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// stfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// stfs f0,20(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// stb r11,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r11.u8);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// std r8,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r8.u64);
	// stfsu f0,32(r10)
	ea = 32 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x824f0304
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F0304;
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r10,r31,916
	ctx.r10.s64 = ctx.r31.s64 + 916;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_824F0334:
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// ld r8,2880(r9)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// stfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// stfs f0,20(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// stb r11,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r11.u8);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// std r8,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r8.u64);
	// stfsu f0,32(r10)
	ea = 32 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x824f0334
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F0334;
	// stw r11,1016(r31)
	REX_STORE_U32(ctx.r31.u32 + 1016, ctx.r11.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,1020(r31)
	REX_STORE_U32(ctx.r31.u32 + 1020, ctx.r8.u32);
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,4(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r6,1024(r31)
	REX_STORE_U32(ctx.r31.u32 + 1024, ctx.r6.u32);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r29,1028(r31)
	REX_STORE_U32(ctx.r31.u32 + 1028, ctx.r29.u32);
	// stfs f13,1032(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1032, temp.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1867
	ctx.r9.s64 = 1867;
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,1036(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 1036, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1040(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1040, temp.u32);
	// stfs f12,1044(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 1044, temp.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r8,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r8.u32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,4(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r8,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r8.u32);
	// stw r27,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r27.u32);
	// stw r6,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r6.u32);
	// stfs f0,1080(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1080, temp.u32);
	// stfs f0,1084(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1084, temp.u32);
	// stw r26,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r26.u32);
	// stfs f0,1088(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1088, temp.u32);
	// stw r11,1068(r31)
	REX_STORE_U32(ctx.r31.u32 + 1068, ctx.r11.u32);
	// stfs f0,1092(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1092, temp.u32);
	// stw r11,1072(r31)
	REX_STORE_U32(ctx.r31.u32 + 1072, ctx.r11.u32);
	// stfs f0,1100(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1100, temp.u32);
	// stw r11,1076(r31)
	REX_STORE_U32(ctx.r31.u32 + 1076, ctx.r11.u32);
	// stfs f0,1108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1108, temp.u32);
	// stb r11,1128(r31)
	REX_STORE_U8(ctx.r31.u32 + 1128, ctx.r11.u8);
	// stfs f0,1112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1112, temp.u32);
	// stb r11,1129(r31)
	REX_STORE_U8(ctx.r31.u32 + 1129, ctx.r11.u8);
	// stfs f0,1116(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1116, temp.u32);
	// stb r11,1136(r31)
	REX_STORE_U8(ctx.r31.u32 + 1136, ctx.r11.u8);
	// stfs f0,1120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1120, temp.u32);
	// stb r11,1137(r31)
	REX_STORE_U8(ctx.r31.u32 + 1137, ctx.r11.u8);
	// stfs f0,1124(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1124, temp.u32);
	// stw r25,1144(r31)
	REX_STORE_U32(ctx.r31.u32 + 1144, ctx.r25.u32);
	// stfs f13,1132(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1132, temp.u32);
	// stb r24,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r24.u8);
	// stfs f0,1140(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1140, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r9,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824FC570) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824FC578;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,12376
	ctx.r11.s64 = ctx.r11.s64 + 12376;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_824FC590:
	// clrlwi r5,r30,16
	ctx.r5.u64 = ctx.r30.u32 & 0xFFFF;
	// lwzu r4,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r4.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824FC5A0;
	sub_8246A2C0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// blt cr6,0x824fc590
	if (ctx.cr6.lt) goto loc_824FC590;
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x824fc5c8
	if (!ctx.cr6.lt) goto loc_824FC5C8;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,1608
	ctx.r11.s64 = ctx.r11.s64 + 1608;
	// lfs f0,-984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -984);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824fc604
	goto loc_824FC604;
loc_824FC5C8:
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// lwz r4,12384(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 12384);
	// blt cr6,0x824fc5e8
	if (ctx.cr6.lt) goto loc_824FC5E8;
	// addi r10,r11,-11
	ctx.r10.s64 = ctx.r11.s64 + -11;
loc_824FC5E8:
	// addi r11,r30,1608
	ctx.r11.s64 = ctx.r30.s64 + 1608;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,14120
	ctx.r11.s64 = ctx.r11.s64 + 14120;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8246a4b8
	ctx.lr = 0x824FC600;
	sub_8246A4B8(ctx, base);
	// lfs f0,1608(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
loc_824FC604:
	// stfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,-16844(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16844);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-16848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16848);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824FC624;
	sub_825A4A40(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f0,276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 276);
	ctx.f0.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f13,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// stfs f1,320(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x824fc650
	if (ctx.cr6.lt) goto loc_824FC650;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x824fc650
	if (!ctx.cr6.lt) goto loc_824FC650;
	// fneg f0,f1
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
loc_824FC650:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
	// stb r10,193(r31)
	REX_STORE_U8(ctx.r31.u32 + 193, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82503578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82503580;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af24
	ctx.lr = 0x82503588;
	__savefpr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825036e4
	if (!ctx.cr0.eq) goto loc_825036E4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,15656
	ctx.r9.s64 = ctx.r11.s64 + 15656;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// li r27,0
	ctx.r27.s64 = 0;
	// lfs f28,15656(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15656);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,-15720(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15720);
	ctx.f27.f64 = double(temp.f32);
	// lfs f29,-3188(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3188);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,-16652(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -16652);
	ctx.f30.f64 = double(temp.f32);
loc_825035C4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r28,412
	ctx.r29.s64 = ctx.r28.s64 + 412;
	// beq cr6,0x825035d4
	if (ctx.cr6.eq) goto loc_825035D4;
	// addi r29,r28,424
	ctx.r29.s64 = ctx.r28.s64 + 424;
loc_825035D4:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825036d8
	if (ctx.cr6.eq) goto loc_825036D8;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825036d0
	goto loc_825036D0;
loc_825035EC:
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f31,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f31.f64, ctx.f13.f64, -ctx.f0.f64)));
	// stfs f0,16(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82503690
	if (!ctx.cr6.lt) goto loc_82503690;
	// lfs f0,40(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f31,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f13.f64)));
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bgt cr6,0x8250367c
	if (ctx.cr6.gt) goto loc_8250367C;
	// lbz r11,289(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8250366c
	if (ctx.cr0.eq) goto loc_8250366C;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82503664
	if (ctx.cr6.eq) goto loc_82503664;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x825e0378
	ctx.lr = 0x82503658;
	sub_825E0378(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
loc_82503664:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x825036cc
	goto loc_825036CC;
loc_8250366C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82503298
	ctx.lr = 0x82503678;
	sub_82503298(ctx, base);
	// b 0x82503690
	goto loc_82503690;
loc_8250367C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f31,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_82503690:
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bge cr6,0x825036b8
	if (!ctx.cr6.lt) goto loc_825036B8;
	// lbz r11,289(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825036c8
	if (!ctx.cr0.eq) goto loc_825036C8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82503298
	ctx.lr = 0x825036B4;
	sub_82503298(ctx, base);
	// b 0x825036c8
	goto loc_825036C8;
loc_825036B8:
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f31,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f13.f64)));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
loc_825036C8:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_825036CC:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_825036D0:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825035ec
	if (!ctx.cr6.eq) goto loc_825035EC;
loc_825036D8:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// blt cr6,0x825035c4
	if (ctx.cr6.lt) goto loc_825035C4;
loc_825036E4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af70
	ctx.lr = 0x825036F0;
	__restfpr_27(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250CEC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8250CEC8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
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
	// bne 0x8250d6ec
	if (!ctx.cr0.eq) goto loc_8250D6EC;
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
	// lfs f0,11948(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11948);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8250cf08
	if (!ctx.cr6.gt) goto loc_8250CF08;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r11.u32);
loc_8250CF08:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r31,68
	ctx.r30.s64 = ctx.r31.s64 + 68;
	// addi r11,r11,32496
	ctx.r11.s64 = ctx.r11.s64 + 32496;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8231e0d8
	ctx.lr = 0x8250CF24;
	sub_8231E0D8(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r10.u64);
	// blt cr6,0x8250d49c
	if (ctx.cr6.lt) goto loc_8250D49C;
	// beq cr6,0x8250d0d8
	if (ctx.cr6.eq) goto loc_8250D0D8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8250d030
	if (ctx.cr6.lt) goto loc_8250D030;
	// bne cr6,0x8250d6ec
	if (!ctx.cr6.eq) goto loc_8250D6EC;
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
	// bge cr6,0x8250d098
	if (!ctx.cr6.lt) goto loc_8250D098;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r8,r10,-9856
	ctx.r8.s64 = ctx.r10.s64 + -9856;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lfs f12,-9856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,-22360(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -22360);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f11,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r11,119(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
loc_8250D014:
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8250D020;
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
	// b 0x8250d6ec
	goto loc_8250D6EC;
loc_8250D030:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f11,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,3188(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x8250d098
	if (!ctx.cr6.lt) goto loc_8250D098;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r8,r10,-9856
	ctx.r8.s64 = ctx.r10.s64 + -9856;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lfs f12,-9856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,-22360(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -22360);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f11,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r11,119(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// b 0x8250d014
	goto loc_8250D014;
loc_8250D098:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
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
	ctx.lr = 0x8250D0CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8250d6ec
	goto loc_8250D6EC;
loc_8250D0D8:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8250d1d8
	if (ctx.cr6.eq) goto loc_8250D1D8;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8250d1d8
	if (!ctx.cr6.eq) goto loc_8250D1D8;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8250d1d8
	if (ctx.cr6.eq) goto loc_8250D1D8;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82430a88
	ctx.lr = 0x8250D11C;
	sub_82430A88(ctx, base);
	// ld r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x8250D1D0;
	sub_8231E0D8(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// b 0x8250d1e4
	goto loc_8250D1E4;
loc_8250D1D8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x8250D1E4;
	sub_8231E0D8(ctx, base);
loc_8250D1E4:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// addi r11,r11,32256
	ctx.r11.s64 = ctx.r11.s64 + 32256;
	// lfs f0,-15028(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -15028);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v6,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-15024(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -15024);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v6
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
	// vsubfp128 v62,v0,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8250d2c4
	if (!ctx.cr6.gt) goto loc_8250D2C4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8250D2C4:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// clrlwi. r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// beq 0x8250d408
	if (ctx.cr0.eq) goto loc_8250D408;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v7,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vcmpeqfp128 v10,v0,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v8,v0,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v6,v13,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vnmsubfp v7,v12,v11,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v13,v13,v7,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vor128 v62,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v12,v62,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v13,v0,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsel v11,v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v12,v13,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8250d408
	if (!ctx.cr6.gt) goto loc_8250D408;
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stw r9,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r9.u32);
loc_8250D408:
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lfs f13,1060(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8250d464
	if (!ctx.cr6.gt) goto loc_8250D464;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// li r3,203
	ctx.r3.s64 = 203;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82240a58
	ctx.lr = 0x8250D464;
	sub_82240A58(ctx, base);
loc_8250D464:
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
	ctx.lr = 0x8250D480;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmadds f1,f0,f31,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f1.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8250D498;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8250d6ec
	goto loc_8250D6EC;
loc_8250D49C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8250d680
	if (!ctx.cr6.lt) goto loc_8250D680;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8231e0d8
	ctx.lr = 0x8250D4C0;
	sub_8231E0D8(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f31,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f0,-15028(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15028);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r29,r1,160
	ctx.r29.s64 = ctx.r1.s64 + 160;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,172(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
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
	ctx.lr = 0x8250D65C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmadds f1,f0,f31,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f1.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8250D674;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// b 0x8250d68c
	goto loc_8250D68C;
loc_8250D680:
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r10.u32);
loc_8250D68C:
	// stfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lfs f13,1060(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8250d6ec
	if (!ctx.cr6.gt) goto loc_8250D6EC;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// li r3,203
	ctx.r3.s64 = 203;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x8250D6EC;
	sub_82240A58(ctx, base);
loc_8250D6EC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82557FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82557FD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,316(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8255807c
	if (!ctx.cr6.eq) goto loc_8255807C;
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// lfs f13,296(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,-12
	ctx.r9.s64 = -12;
	// addi r10,r29,-2180
	ctx.r10.s64 = ctx.r29.s64 + -2180;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r8,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// lfs f0,-8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x82558034;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,-6
	ctx.r11.s64 = -6;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// li r10,6
	ctx.r10.s64 = 6;
	// lfs f0,-2180(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2180);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stw r30,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x8255807C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8255807C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255C948) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r4,r11,7948
	ctx.r4.s64 = ctx.r11.s64 + 7948;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x8255C970;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// bne 0x8255c980
	if (!ctx.cr0.eq) goto loc_8255C980;
	// stb r30,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r30.u8);
loc_8255C980:
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82517858
	ctx.lr = 0x8255C994;
	sub_82517858(ctx, base);
	// stw r3,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// lbz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r5,88(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82517f98
	ctx.lr = 0x8255C9AC;
	sub_82517F98(ctx, base);
	// stfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82518388
	ctx.lr = 0x8255C9C0;
	sub_82518388(ctx, base);
	// stfs f1,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 200, temp.u32);
	// stb r30,274(r31)
	REX_STORE_U8(ctx.r31.u32 + 274, ctx.r30.u8);
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

DEFINE_REX_FUNC(sub_825614D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825614E0;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x825614FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82561654
	if (!ctx.cr0.eq) goto loc_82561654;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561544;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lis r30,-32114
	ctx.r30.s64 = -2104623104;
	// lis r29,-32111
	ctx.r29.s64 = -2104426496;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f0,5560(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5560);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f13,-4592(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -4592);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x82561590;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,296(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825615AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lfs f0,5560(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4592(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -4592);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x825615F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,296(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256160C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561628;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82561640;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// stb r11,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x82561654;
	sub_8246C998(ctx, base);
loc_82561654:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256B280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8256B288;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,124(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r29,-32111
	ctx.r29.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,-8644(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2420(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2420);
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
	ctx.lr = 0x8256B2D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x8256B2F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x8256B310;
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
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// blt cr6,0x8256b340
	if (ctx.cr6.lt) goto loc_8256B340;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8256B340:
	// bctrl 
	ctx.lr = 0x8256B344;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,-8644(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f13,-2420(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2420);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x8256B384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256B3A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256B3BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
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
	// blt cr6,0x8256b3e4
	if (ctx.cr6.lt) goto loc_8256B3E4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8256B3E4:
	// bctrl 
	ctx.lr = 0x8256B3E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stb r10,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r10.u8);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// bl 0x82453a68
	ctx.lr = 0x8256B420;
	sub_82453A68(ctx, base);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82240a58
	ctx.lr = 0x8256B42C;
	sub_82240A58(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82575A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82575A10;
	__savegprlr_26(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82575b60
	if (ctx.cr6.eq) goto loc_82575B60;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82575b60
	if (ctx.cr6.eq) goto loc_82575B60;
	// lwz r6,8(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82575b60
	if (ctx.cr6.eq) goto loc_82575B60;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,4
	ctx.r10.s64 = 4;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// addi r11,r11,-16604
	ctx.r11.s64 = ctx.r11.s64 + -16604;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r7,r8,-16592
	ctx.r7.s64 = ctx.r8.s64 + -16592;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
loc_82575A64:
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// stw r28,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// stw r28,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r28.u32);
	// stw r28,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r28.u32);
	// stwu r28,20(r10)
	ea = 20 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82575a64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82575A64;
	// add r10,r9,r6
	ctx.r10.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// subf r3,r9,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r9.u64;
	// bl 0x825754c8
	ctx.lr = 0x82575A90;
	sub_825754C8(ctx, base);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r28,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// ori r3,r10,28544
	ctx.r3.u64 = ctx.r10.u64 | 28544;
	// stw r28,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r28.u32);
	// li r10,96
	ctx.r10.s64 = 96;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// bl 0x82575600
	ctx.lr = 0x82575AC4;
	sub_82575600(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// beq 0x82575b60
	if (ctx.cr0.eq) goto loc_82575B60;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_82575ADC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x82575adc
	if (!ctx.cr0.eq) goto loc_82575ADC;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r10,12636
	ctx.r10.s64 = ctx.r10.s64 + 12636;
loc_82575AFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82575afc
	if (!ctx.cr6.eq) goto loc_82575AFC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82575B10:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x82575b10
	if (!ctx.cr6.eq) goto loc_82575B10;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8263a9c0
	ctx.lr = 0x82575B48;
	sub_8263A9C0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82575b6c
	if (!ctx.cr6.eq) goto loc_82575B6C;
	// bl 0x82639f50
	ctx.lr = 0x82575B58;
	sub_82639F50(ctx, base);
loc_82575B58:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82575690
	ctx.lr = 0x82575B60;
	sub_82575690(ctx, base);
loc_82575B60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82575B64:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_82575B6C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8263abb8
	ctx.lr = 0x82575B78;
	sub_8263ABB8(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82575600
	ctx.lr = 0x82575B8C;
	sub_82575600(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne 0x82575ba4
	if (!ctx.cr0.eq) goto loc_82575BA4;
	// bl 0x8263a978
	ctx.lr = 0x82575BA0;
	sub_8263A978(ctx, base);
	// b 0x82575b58
	goto loc_82575B58;
loc_82575BA4:
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8263acb0
	ctx.lr = 0x82575BBC;
	sub_8263ACB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne 0x82575bd8
	if (!ctx.cr0.eq) goto loc_82575BD8;
	// bl 0x8263a978
	ctx.lr = 0x82575BCC;
	sub_8263A978(ctx, base);
loc_82575BCC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82575690
	ctx.lr = 0x82575BD4;
	sub_82575690(ctx, base);
	// b 0x82575b58
	goto loc_82575B58;
loc_82575BD8:
	// bl 0x8263a978
	ctx.lr = 0x82575BDC;
	sub_8263A978(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825b0238
	ctx.lr = 0x82575BE4;
	sub_825B0238(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82575bcc
	if (ctx.cr6.eq) goto loc_82575BCC;
	// lwz r3,0(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x825748e8
	ctx.lr = 0x82575BF4;
	sub_825748E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82575bcc
	if (ctx.cr0.eq) goto loc_82575BCC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// li r11,9
	ctx.r11.s64 = 9;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,-16508(r9)
	REX_STORE_U32(ctx.r9.u32 + -16508, ctx.r28.u32);
	// stfs f0,-556(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -556, temp.u32);
	// stw r11,-16512(r7)
	REX_STORE_U32(ctx.r7.u32 + -16512, ctx.r11.u32);
	// b 0x82575b64
	goto loc_82575B64;
}

DEFINE_REX_FUNC(sub_825816F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x825816F8;
	__savegprlr_20(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r26,12(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r31,r11,4472
	ctx.r31.s64 = ctx.r11.s64 + 4472;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// addi r30,r31,336
	ctx.r30.s64 = ctx.r31.s64 + 336;
	// li r20,1
	ctx.r20.s64 = 1;
loc_8258171C:
	// slw r11,r20,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r20.u32 << (ctx.r27.u8 & 0x3F));
	// and. r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 & ctx.r26.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8258174c
	if (ctx.cr0.eq) goto loc_8258174C;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// li r29,20
	ctx.r29.s64 = 20;
loc_82581730:
	// li r5,136
	ctx.r5.s64 = 136;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639688
	ctx.lr = 0x82581740;
	sub_82639688(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,136
	ctx.r28.s64 = ctx.r28.s64 + 136;
	// bne 0x82581730
	if (!ctx.cr0.eq) goto loc_82581730;
loc_8258174C:
	// addi r30,r30,2720
	ctx.r30.s64 = ctx.r30.s64 + 2720;
	// addi r11,r31,5776
	ctx.r11.s64 = ctx.r31.s64 + 5776;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8258171c
	if (ctx.cr6.lt) goto loc_8258171C;
	// bl 0x82213210
	ctx.lr = 0x82581764;
	sub_82213210(ctx, base);
	// lwz r23,4(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r23,254
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 254, ctx.xer);
	// bne cr6,0x825817a8
	if (!ctx.cr6.eq) goto loc_825817A8;
	// li r10,1253
	ctx.r10.s64 = 1253;
	// stw r21,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r21.u32);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stb r21,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r21.u8);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// addi r11,r22,4
	ctx.r11.s64 = ctx.r22.s64 + 4;
loc_8258178C:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r21,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8258178c
	if (!ctx.cr0.eq) goto loc_8258178C;
	// b 0x82581b9c
	goto loc_82581B9C;
loc_825817A8:
	// lwz r4,248(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x825817e4
	if (!ctx.cr6.eq) goto loc_825817E4;
	// li r11,21
	ctx.r11.s64 = 21;
	// stb r21,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r21.u8);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r11,r22,4
	ctx.r11.s64 = ctx.r22.s64 + 4;
loc_825817C8:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r21,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825817c8
	if (!ctx.cr0.eq) goto loc_825817C8;
	// b 0x82581b9c
	goto loc_82581B9C;
loc_825817E4:
	// lwz r3,5776(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r26,r11,13620
	ctx.r26.s64 = ctx.r11.s64 + 13620;
	// beq cr6,0x82581820
	if (ctx.cr6.eq) goto loc_82581820;
	// bl 0x825e0378
	ctx.lr = 0x825817FC;
	sub_825E0378(ctx, base);
	// stw r21,5776(r31)
	REX_STORE_U32(ctx.r31.u32 + 5776, ctx.r21.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// bl 0x82639d68
	ctx.lr = 0x82581810;
	sub_82639D68(ctx, base);
	// lwz r11,5776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82581b70
	if (!ctx.cr6.eq) goto loc_82581B70;
	// lwz r4,248(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
loc_82581820:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82639d80
	ctx.lr = 0x8258183C;
	sub_82639D80(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82581870
	if (ctx.cr0.eq) goto loc_82581870;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// addi r8,r22,4
	ctx.r8.s64 = ctx.r22.s64 + 4;
	// stb r21,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r21.u8);
loc_82581854:
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
	// stwcx. r21,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82581854
	if (!ctx.cr0.eq) goto loc_82581854;
	// b 0x82581b9c
	goto loc_82581B9C;
loc_82581870:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,308
	ctx.r4.s64 = 308;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82581888;
	sub_825E02A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r4,5776(r31)
	REX_STORE_U32(ctx.r31.u32 + 5776, ctx.r4.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,308
	ctx.r5.s64 = 308;
	// bl 0x8263a878
	ctx.lr = 0x825818A4;
	sub_8263A878(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x82581ab8
	if (!ctx.cr0.eq) goto loc_82581AB8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r24,r11,13540
	ctx.r24.s64 = ctx.r11.s64 + 13540;
loc_825818B4:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82581a90
	if (ctx.cr6.eq) goto loc_82581A90;
	// lwz r11,5776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,264
	ctx.r4.s64 = ctx.r11.s64 + 264;
	// bl 0x82238f48
	ctx.lr = 0x825818D0;
	sub_82238F48(ctx, base);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// bne cr6,0x82581a80
	if (!ctx.cr6.eq) goto loc_82581A80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82582cb8
	ctx.lr = 0x825818E4;
	sub_82582CB8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82581a80
	if (!ctx.cr0.eq) goto loc_82581A80;
	// lwz r9,120(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// bge cr6,0x82581904
	if (!ctx.cr6.lt) goto loc_82581904;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
loc_82581904:
	// lbz r10,6(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// cmplwi cr6,r10,48
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 48, ctx.xer);
	// bne cr6,0x82581924
	if (!ctx.cr6.eq) goto loc_82581924;
	// lwz r10,12(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 12);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82581924
	if (ctx.cr0.eq) goto loc_82581924;
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// b 0x8258194c
	goto loc_8258194C;
loc_82581924:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bge cr6,0x82581930
	if (!ctx.cr6.lt) goto loc_82581930;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
loc_82581930:
	// lbz r11,6(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r11,49
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 49, ctx.xer);
	// bne cr6,0x82581a80
	if (!ctx.cr6.eq) goto loc_82581A80;
	// lwz r11,12(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 12);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82581a80
	if (ctx.cr0.eq) goto loc_82581A80;
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
loc_8258194C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8235ec48
	ctx.lr = 0x8258195C;
	sub_8235EC48(ctx, base);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82239208
	ctx.lr = 0x82581970;
	sub_82239208(ctx, base);
	// lwz r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r3,148(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82581984
	if (!ctx.cr6.lt) goto loc_82581984;
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
loc_82581984:
	// bl 0x82739b38
	ctx.lr = 0x82581988;
	sub_82739B38(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8235ec48
	ctx.lr = 0x8258199C;
	sub_8235EC48(ctx, base);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// blt cr6,0x82581a80
	if (ctx.cr6.lt) goto loc_82581A80;
	// cmpwi cr6,r30,20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 20, ctx.xer);
	// bgt cr6,0x82581a80
	if (ctx.cr6.gt) goto loc_82581A80;
	// mulli r11,r28,100
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(100));
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82738a28
	ctx.lr = 0x825819C0;
	sub_82738A28(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,5776(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// bl 0x82639e18
	ctx.lr = 0x825819E4;
	sub_82639E18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82581a44
	if (!ctx.cr0.eq) goto loc_82581A44;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8263a9c0
	ctx.lr = 0x82581A0C;
	sub_8263A9C0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82581a44
	if (ctx.cr6.eq) goto loc_82581A44;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,124
	ctx.r6.s64 = ctx.r1.s64 + 124;
	// li r5,136
	ctx.r5.s64 = 136;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// bl 0x8263acb0
	ctx.lr = 0x82581A2C;
	sub_8263ACB0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82639838
	ctx.lr = 0x82581A38;
	sub_82639838(ctx, base);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x82581a44
	if (ctx.cr6.eq) goto loc_82581A44;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
loc_82581A44:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82581a54
	if (!ctx.cr0.eq) goto loc_82581A54;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8245d6b8
	ctx.lr = 0x82581A54;
	sub_8245D6B8(ctx, base);
loc_82581A54:
	// mulli r11,r28,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(20));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r10,r31,200
	ctx.r10.s64 = ctx.r31.s64 + 200;
	// mulli r11,r11,136
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(136));
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// li r5,136
	ctx.r5.s64 = 136;
	// bl 0x8273a030
	ctx.lr = 0x82581A74;
	sub_8273A030(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82639d68
	ctx.lr = 0x82581A80;
	sub_82639D68(ctx, base);
loc_82581A80:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x82581A90;
	sub_8235EC48(ctx, base);
loc_82581A90:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8263a258
	ctx.lr = 0x82581A98;
	sub_8263A258(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r4,5776(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// li r5,308
	ctx.r5.s64 = 308;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8263a878
	ctx.lr = 0x82581AB0;
	sub_8263A878(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x825818b4
	if (ctx.cr0.eq) goto loc_825818B4;
loc_82581AB8:
	// cmplwi cr6,r25,18
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 18, ctx.xer);
	// beq cr6,0x82581b68
	if (ctx.cr6.eq) goto loc_82581B68;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82581b68
	if (ctx.cr6.eq) goto loc_82581B68;
	// lwz r26,12(r22)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r22.u32 + 12);
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// addi r30,r31,336
	ctx.r30.s64 = ctx.r31.s64 + 336;
loc_82581AD8:
	// slw r11,r20,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r20.u32 << (ctx.r27.u8 & 0x3F));
	// and. r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 & ctx.r26.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82581b08
	if (ctx.cr0.eq) goto loc_82581B08;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// li r29,20
	ctx.r29.s64 = 20;
loc_82581AEC:
	// li r5,136
	ctx.r5.s64 = 136;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82639688
	ctx.lr = 0x82581AFC;
	sub_82639688(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,136
	ctx.r28.s64 = ctx.r28.s64 + 136;
	// bne 0x82581aec
	if (!ctx.cr0.eq) goto loc_82581AEC;
loc_82581B08:
	// addi r30,r30,2720
	ctx.r30.s64 = ctx.r30.s64 + 2720;
	// addi r11,r31,5776
	ctx.r11.s64 = ctx.r31.s64 + 5776;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82581ad8
	if (ctx.cr6.lt) goto loc_82581AD8;
	// lwz r3,5776(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 5776);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82581b2c
	if (ctx.cr6.eq) goto loc_82581B2C;
	// bl 0x825e0378
	ctx.lr = 0x82581B2C;
	sub_825E0378(ctx, base);
loc_82581B2C:
	// stw r21,5776(r31)
	REX_STORE_U32(ctx.r31.u32 + 5776, ctx.r21.u32);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82639838
	ctx.lr = 0x82581B3C;
	sub_82639838(ctx, base);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r25,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r25.u32);
	// addi r8,r22,4
	ctx.r8.s64 = ctx.r22.s64 + 4;
	// stb r21,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r21.u8);
loc_82581B4C:
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
	// stwcx. r21,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82581b4c
	if (!ctx.cr0.eq) goto loc_82581B4C;
	// b 0x82581b9c
	goto loc_82581B9C;
loc_82581B68:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82639838
	ctx.lr = 0x82581B70;
	sub_82639838(ctx, base);
loc_82581B70:
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r21,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r21.u32);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stb r21,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r21.u8);
	// addi r11,r22,4
	ctx.r11.s64 = ctx.r22.s64 + 4;
loc_82581B84:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r21,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r21.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82581b84
	if (!ctx.cr0.eq) goto loc_82581B84;
loc_82581B9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A25B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x825A25C0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,172(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 172);
	// rlwinm r11,r4,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFF0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// clrlwi r27,r4,16
	ctx.r27.u64 = ctx.r4.u32 & 0xFFFF;
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x825a25f4
	if (ctx.cr6.eq) goto loc_825A25F4;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// b 0x825a25f8
	goto loc_825A25F8;
loc_825A25F4:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_825A25F8:
	// lwz r10,200(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// addi r28,r30,192
	ctx.r28.s64 = ctx.r30.s64 + 192;
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r29,r28,4
	ctx.r29.s64 = ctx.r28.s64 + 4;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x825a2648
	goto loc_825A2648;
loc_825A2614:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x825a2628
	if (!ctx.cr6.lt) goto loc_825A2628;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x825a2648
	goto loc_825A2648;
loc_825A2628:
	// lbz r10,21(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 21);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x825a2640
	if (ctx.cr0.eq) goto loc_825A2640;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x825a2640
	if (!ctx.cr6.lt) goto loc_825A2640;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_825A2640:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_825A2648:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825a2614
	if (ctx.cr0.eq) goto loc_825A2614;
	// lbz r11,21(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a266c
	if (ctx.cr0.eq) goto loc_825A266C;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x825a2690
	goto loc_825A2690;
loc_825A266C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x825a2690
	goto loc_825A2690;
loc_825A2674:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x825a268c
	if (!ctx.cr6.lt) goto loc_825A268C;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x825a2690
	goto loc_825A2690;
loc_825A268C:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_825A2690:
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825a2674
	if (ctx.cr0.eq) goto loc_825A2674;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825a26cc
	if (ctx.cr6.eq) goto loc_825A26CC;
loc_825A26AC:
	// lwz r11,16(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x825a26cc
	if (ctx.cr6.eq) goto loc_825A26CC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x825A26C0;
	sub_82216520(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r5,r31
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x825a26ac
	if (!ctx.cr6.eq) goto loc_825A26AC;
loc_825A26CC:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825a26e4
	if (ctx.cr6.eq) goto loc_825A26E4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a1bd8
	ctx.lr = 0x825A26E4;
	sub_825A1BD8(ctx, base);
loc_825A26E4:
	// lbz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 76);
	// addi r29,r30,48
	ctx.r29.s64 = ctx.r30.s64 + 48;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a26fc
	if (ctx.cr0.eq) goto loc_825A26FC;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x825A26FC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_825A26FC:
	// lwz r3,216(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// b 0x825a2714
	goto loc_825A2714;
loc_825A2704:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x825a2724
	if (ctx.cr6.eq) goto loc_825A2724;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_825A2714:
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825a2704
	if (!ctx.cr6.eq) goto loc_825A2704;
	// b 0x825a2754
	goto loc_825A2754;
loc_825A2724:
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// addi r5,r3,4
	ctx.r5.s64 = ctx.r3.s64 + 4;
	// addi r31,r30,212
	ctx.r31.s64 = ctx.r30.s64 + 212;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x825a2748
	if (!ctx.cr0.gt) goto loc_825A2748;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x827388e8
	ctx.lr = 0x825A2748;
	sub_827388E8(ctx, base);
loc_825A2748:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_825A2754:
	// lbz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a2768
	if (ctx.cr0.eq) goto loc_825A2768;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x825A2768;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825A2768:
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// rlwinm r11,r27,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r30,136
	ctx.r29.s64 = ctx.r30.s64 + 136;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r27,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r25,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r25.u32);
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// lbz r9,164(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 164);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq 0x825a279c
	if (ctx.cr0.eq) goto loc_825A279C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x825A279C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_825A279C:
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// rlwinm r11,r26,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xFFFF0000;
	// stw r25,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// rlwinm r11,r11,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// or r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 188);
	// stw r31,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// stw r31,188(r30)
	REX_STORE_U32(ctx.r30.u32 + 188, ctx.r31.u32);
	// lbz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a27d8
	if (ctx.cr0.eq) goto loc_825A27D8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x825A27D8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825A27D8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B0A48) {
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
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// bne cr6,0x825b0a70
	if (!ctx.cr6.eq) goto loc_825B0A70;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x825b0ae8
	goto loc_825B0AE8;
loc_825B0A70:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825B0A84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825b0ae4
	if (!ctx.cr0.eq) goto loc_825B0AE4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0a9c
	if (ctx.cr0.eq) goto loc_825B0A9C;
	// li r31,1
	ctx.r31.s64 = 1;
loc_825B0A9C:
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0aa8
	if (ctx.cr0.eq) goto loc_825B0AA8;
	// ori r31,r31,2
	ctx.r31.u64 = ctx.r31.u64 | 2;
loc_825B0AA8:
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0ab4
	if (ctx.cr0.eq) goto loc_825B0AB4;
	// ori r31,r31,4
	ctx.r31.u64 = ctx.r31.u64 | 4;
loc_825B0AB4:
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0ac0
	if (ctx.cr0.eq) goto loc_825B0AC0;
	// ori r31,r31,8
	ctx.r31.u64 = ctx.r31.u64 | 8;
loc_825B0AC0:
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0acc
	if (ctx.cr0.eq) goto loc_825B0ACC;
	// ori r31,r31,16
	ctx.r31.u64 = ctx.r31.u64 | 16;
loc_825B0ACC:
	// rlwinm. r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825b0ad8
	if (ctx.cr0.eq) goto loc_825B0AD8;
	// ori r31,r31,32
	ctx.r31.u64 = ctx.r31.u64 | 32;
loc_825B0AD8:
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825b0ae4
	if (ctx.cr0.eq) goto loc_825B0AE4;
	// ori r31,r31,64
	ctx.r31.u64 = ctx.r31.u64 | 64;
loc_825B0AE4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825B0AE8:
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

DEFINE_REX_FUNC(sub_825B6450) {
	REX_FUNC_PROLOGUE();
	// lwz r11,324(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B6590) {
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
	// addi r8,r11,18208
	ctx.r8.s64 = ctx.r11.s64 + 18208;
	// addi r7,r10,18356
	ctx.r7.s64 = ctx.r10.s64 + 18356;
	// addi r6,r9,18364
	ctx.r6.s64 = ctx.r9.s64 + 18364;
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_825B65D0:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b6608
	if (ctx.cr6.eq) goto loc_825B6608;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,264
	ctx.r5.s64 = ctx.r31.s64 + 264;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B6600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b65d0
	if (ctx.cr6.eq) goto loc_825B65D0;
loc_825B6608:
	// lwz r3,324(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b6620
	if (ctx.cr6.eq) goto loc_825B6620;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,6
	ctx.r4.u64 = ctx.r4.u64 | 6;
	// bl 0x8263b710
	ctx.lr = 0x825B6620;
	sub_8263B710(ctx, base);
loc_825B6620:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c00d0
	ctx.lr = 0x825B6628;
	sub_825C00D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825b6620
	if (!ctx.cr6.eq) goto loc_825B6620;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r11,19768
	ctx.r7.s64 = ctx.r11.s64 + 19768;
	// addi r6,r8,18140
	ctx.r6.s64 = ctx.r8.s64 + 18140;
	// addi r5,r10,18356
	ctx.r5.s64 = ctx.r10.s64 + 18356;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r4,r9,19912
	ctx.r4.s64 = ctx.r9.s64 + 19912;
	// stw r6,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r6.u32);
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r6,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r6.u32);
	// bl 0x825c0488
	ctx.lr = 0x825B666C;
	sub_825C0488(ctx, base);
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

DEFINE_REX_FUNC(sub_825BBE78) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BBE94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825BCF20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x825BCF28;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r25,r11,204
	ctx.r25.s64 = ctx.r11.s64 + 204;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// bl 0x82855b44
	ctx.lr = 0x825BCF4C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,24(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x825b3350
	ctx.lr = 0x825BCF54;
	sub_825B3350(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825bd0ac
	if (ctx.cr6.lt) goto loc_825BD0AC;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bge cr6,0x825bcf74
	if (!ctx.cr6.lt) goto loc_825BCF74;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,87
	ctx.r28.u64 = ctx.r28.u64 | 87;
	// b 0x825bcfb0
	goto loc_825BCFB0;
loc_825BCF74:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x825bcf88
	if (!ctx.cr6.eq) goto loc_825BCF88;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,87
	ctx.r28.u64 = ctx.r28.u64 | 87;
	// b 0x825bcfb0
	goto loc_825BCFB0;
loc_825BCF88:
	// clrlwi r31,r29,16
	ctx.r31.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r31,65535
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 65535, ctx.xer);
	// beq cr6,0x825bcfa8
	if (ctx.cr6.eq) goto loc_825BCFA8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825bcab8
	ctx.lr = 0x825BCF9C;
	sub_825BCAB8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825bcfb0
	if (ctx.cr6.lt) goto loc_825BCFB0;
loc_825BCFA8:
	// lis r28,-30009
	ctx.r28.s64 = -1966669824;
	// ori r28,r28,12
	ctx.r28.u64 = ctx.r28.u64 | 12;
loc_825BCFB0:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x825bd0ac
	if (ctx.cr6.lt) goto loc_825BD0AC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BCFD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825bd01c
	if (ctx.cr6.eq) goto loc_825BD01C;
	// li r3,460
	ctx.r3.s64 = 460;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x8263b678
	ctx.lr = 0x825BCFF4;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825bd014
	if (ctx.cr6.eq) goto loc_825BD014;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// lwz r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x825c8fc8
	ctx.lr = 0x825BD010;
	sub_825C8FC8(ctx, base);
	// b 0x825bd078
	goto loc_825BD078;
loc_825BD014:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x825bd084
	goto loc_825BD084;
loc_825BD01C:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// li r3,368
	ctx.r3.s64 = 368;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825bd054
	if (ctx.cr6.eq) goto loc_825BD054;
	// ori r4,r4,32778
	ctx.r4.u64 = ctx.r4.u64 | 32778;
	// bl 0x8263b678
	ctx.lr = 0x825BD034;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825bd014
	if (ctx.cr6.eq) goto loc_825BD014;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// lwz r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x825bc840
	ctx.lr = 0x825BD050;
	sub_825BC840(ctx, base);
	// b 0x825bd078
	goto loc_825BD078;
loc_825BD054:
	// ori r4,r4,32777
	ctx.r4.u64 = ctx.r4.u64 | 32777;
	// bl 0x8263b678
	ctx.lr = 0x825BD05C;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825bd014
	if (ctx.cr6.eq) goto loc_825BD014;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// lwz r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x825bc738
	ctx.lr = 0x825BD078;
	sub_825BC738(ctx, base);
loc_825BD078:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825bd0c0
	if (!ctx.cr6.eq) goto loc_825BD0C0;
loc_825BD084:
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
loc_825BD08C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825bd0ac
	if (ctx.cr6.eq) goto loc_825BD0AC;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BD0AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825BD0AC:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b34
	ctx.lr = 0x825BD0B4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_825BD0C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BD0D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825bd08c
	if (ctx.cr6.lt) goto loc_825BD08C;
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x82855b34
	ctx.lr = 0x825BD114;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CAA08) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-24
	ctx.r3.s64 = ctx.r3.s64 + -24;
	// b 0x825c90c0
	sub_825C90C0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CAD20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825CAD28;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r4.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stw r30,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r30.u32);
	// addi r9,r10,20888
	ctx.r9.s64 = ctx.r10.s64 + 20888;
	// stw r30,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// addi r29,r31,72
	ctx.r29.s64 = ctx.r31.s64 + 72;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// sth r11,120(r31)
	REX_STORE_U16(ctx.r31.u32 + 120, ctx.r11.u16);
	// stw r6,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r6.u32);
	// bl 0x8273a590
	ctx.lr = 0x825CAD84;
	sub_8273A590(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r9,r31,12
	ctx.r9.s64 = ctx.r31.s64 + 12;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825CAD98:
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x825cad98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825CAD98;
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r29,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// stw r9,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CFE60) {
	REX_FUNC_PROLOGUE();
	// lwz r3,92(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825D0178) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825D0180;
	__savegprlr_24(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// sth r29,114(r1)
	REX_STORE_U16(ctx.r1.u32 + 114, ctx.r29.u16);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r11,r10,27,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFFFFFF;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x825d01bc
	if (ctx.cr6.gt) goto loc_825D01BC;
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// subf r26,r11,r4
	ctx.r26.u64 = ctx.r4.u64 - ctx.r11.u64;
	// b 0x825d01c4
	goto loc_825D01C4;
loc_825D01BC:
	// stw r4,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
loc_825D01C4:
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// li r25,1
	ctx.r25.s64 = 1;
loc_825D01CC:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x825d0368
	if (!ctx.cr6.eq) goto loc_825D0368;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x825d0368
	if (ctx.cr6.lt) goto loc_825D0368;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D01F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,114
	ctx.r4.s64 = ctx.r1.s64 + 114;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,120(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 120);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825D020C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825d0478
	if (ctx.cr6.lt) goto loc_825D0478;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r3,308(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 308);
	// bl 0x825bd740
	ctx.lr = 0x825D0234;
	sub_825BD740(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d0340
	if (ctx.cr6.eq) goto loc_825D0340;
	// lwz r11,256(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d0354
	if (ctx.cr6.eq) goto loc_825D0354;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lhz r5,114(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 114);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r4,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r4.u32);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// sth r5,164(r1)
	REX_STORE_U16(ctx.r1.u32 + 164, ctx.r5.u16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D0274;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,172
	ctx.r3.s64 = ctx.r1.s64 + 172;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x8273a030
	ctx.lr = 0x825D0284;
	sub_8273A030(ctx, base);
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r25,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r25.u32);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,9,9
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x825d02ac
	if (ctx.cr6.eq) goto loc_825D02AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x825c0e28
	ctx.lr = 0x825D02A8;
	sub_825C0E28(ctx, base);
	// b 0x825d02cc
	goto loc_825D02CC;
loc_825D02AC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D02C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x825c0da0
	ctx.lr = 0x825D02CC;
	sub_825C0DA0(ctx, base);
loc_825D02CC:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpw cr6,r3,r26
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r26.s32, ctx.xer);
	// bge cr6,0x825d01cc
	if (!ctx.cr6.lt) goto loc_825D01CC;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825d0338
	if (ctx.cr6.eq) goto loc_825D0338;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D0304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x825d0330
	if (ctx.cr6.eq) goto loc_825D0330;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D0324;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,68(r31)
	REX_STORE_U8(ctx.r31.u32 + 68, ctx.r9.u8);
loc_825D0330:
	// subf r26,r30,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r30.u64;
	// b 0x825d01cc
	goto loc_825D01CC;
loc_825D0338:
	// li r26,-1
	ctx.r26.s64 = -1;
	// b 0x825d01cc
	goto loc_825D01CC;
loc_825D0340:
	// lis r24,-30009
	ctx.r24.s64 = -1966669824;
	// ori r24,r24,19
	ctx.r24.u64 = ctx.r24.u64 | 19;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_825D0354:
	// lis r24,-30009
	ctx.r24.s64 = -1966669824;
	// ori r24,r24,22
	ctx.r24.u64 = ctx.r24.u64 | 22;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_825D0368:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x825d0478
	if (ctx.cr6.lt) goto loc_825D0478;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge cr6,0x825d038c
	if (!ctx.cr6.lt) goto loc_825D038C;
	// lis r24,-30009
	ctx.r24.s64 = -1966669824;
	// ori r24,r24,25
	ctx.r24.u64 = ctx.r24.u64 | 25;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_825D038C:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d03a8
	if (ctx.cr6.eq) goto loc_825D03A8;
	// lhz r11,5(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r29,r11,31
	ctx.r29.u64 = ctx.r11.u32 & 0x1;
loc_825D03A8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r30,0(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r27,r8,10,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825D03CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lhz r4,114(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 114);
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x825D0408;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825d0478
	if (ctx.cr6.lt) goto loc_825D0478;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r10,116(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D042C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825d0478
	if (ctx.cr6.eq) goto loc_825D0478;
	// lhz r10,5(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 5);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825d0478
	if (ctx.cr6.eq) goto loc_825D0478;
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lfs f2,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f1,64(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r8,5(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 5);
	// rlwinm r4,r8,31,30,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x3;
	// lwz r7,40(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825D0478;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D0478:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E8658) {
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
	// addi r11,r11,23528
	ctx.r11.s64 = ctx.r11.s64 + 23528;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x825e8684
	if (ctx.cr0.eq) goto loc_825E8684;
	// bl 0x825e0378
	ctx.lr = 0x825E8684;
	sub_825E0378(ctx, base);
loc_825E8684:
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

DEFINE_REX_FUNC(sub_825EA128) {
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
	// lis r31,-32111
	ctx.r31.s64 = -2104426496;
	// lwz r11,30144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 30144);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825ea168
	if (ctx.cr0.eq) goto loc_825EA168;
loc_825EA148:
	// lwz r10,128(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825ea160
	if (!ctx.cr6.eq) goto loc_825EA160;
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825ea148
	if (!ctx.cr6.eq) goto loc_825EA148;
loc_825EA160:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825ea21c
	if (!ctx.cr6.eq) goto loc_825EA21C;
loc_825EA168:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x825EA180;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825ea1f4
	if (ctx.cr0.eq) goto loc_825EA1F4;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r3,-16
	ctx.r10.s64 = ctx.r3.s64 + -16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825EA198:
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// stw r11,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// stw r11,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// stw r11,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r11.u32);
	// stw r11,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// stw r11,44(r10)
	REX_STORE_U32(ctx.r10.u32 + 44, ctx.r11.u32);
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// stwu r11,32(r10)
	ea = 32 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x825ea198
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825EA198;
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_825EA1C8:
	// addi r9,r10,32
	ctx.r9.s64 = ctx.r10.s64 + 32;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// bdnz 0x825ea1c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825EA1C8;
	// stw r3,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r3.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r11,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// stw r11,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r11.u32);
	// stw r11,132(r3)
	REX_STORE_U32(ctx.r3.u32 + 132, ctx.r11.u32);
	// stw r11,140(r3)
	REX_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// b 0x825ea1f8
	goto loc_825EA1F8;
loc_825EA1F4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825EA1F8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825ea248
	if (ctx.cr6.eq) goto loc_825EA248;
	// lwz r9,30144(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 30144);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,132(r10)
	REX_STORE_U32(ctx.r10.u32 + 132, ctx.r9.u32);
	// beq cr6,0x825ea218
	if (ctx.cr6.eq) goto loc_825EA218;
	// stw r10,136(r9)
	REX_STORE_U32(ctx.r9.u32 + 136, ctx.r10.u32);
loc_825EA218:
	// stw r10,30144(r31)
	REX_STORE_U32(ctx.r31.u32 + 30144, ctx.r10.u32);
loc_825EA21C:
	// lwz r3,128(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// stw r9,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r9.u32);
loc_825EA234:
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
loc_825EA248:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825ea234
	goto loc_825EA234;
}

DEFINE_REX_FUNC(sub_825F2260) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825F2268;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,0(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x825f2288
	if (!ctx.cr6.eq) goto loc_825F2288;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825f22d4
	goto loc_825F22D4;
loc_825F2288:
	// lbz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 68);
	// addi r30,r31,40
	ctx.r30.s64 = ctx.r31.s64 + 40;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825f22a0
	if (ctx.cr0.eq) goto loc_825F22A0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x825F22A0;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_825F22A0:
	// addi r7,r31,24
	ctx.r7.s64 = ctx.r31.s64 + 24;
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x825f2450
	ctx.lr = 0x825F22B8;
	sub_825F2450(ctx, base);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825f22d0
	if (ctx.cr0.eq) goto loc_825F22D0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x825F22D0;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825F22D0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825F22D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F4520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r11,4
	ctx.r11.s64 = 4;
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,0
	ctx.r10.s64 = 0;
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,8
	ctx.r9.s64 = 8;
	// lvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// vperm128 v59,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v58,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v6,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v57,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v56,r6,r8
	ea = (ctx.r6.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v54,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v59,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v58,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// li r11,1
	ctx.r11.s64 = 1;
	// vperm128 v52,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v55,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v53,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmulfp128 v3,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vperm128 v59,v60,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v2,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// vspltw128 v13,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vspltw128 v58,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0xFF));
	// vspltw128 v57,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0xFF));
	// vspltw128 v59,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vspltw128 v55,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0xFF));
	// vperm128 v54,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vmulfp128 v31,v57,v58
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vperm128 v53,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v52,v61,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v58,v60,v60,v7
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vmulfp128 v7,v55,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vperm128 v62,v62,v62,v6
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmaddfp v3,v13,v2,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vperm128 v59,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vspltw128 v4,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0xFF));
	// vspltw128 v8,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// vspltw128 v10,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v9,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vspltw128 v1,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0xFF));
	// vspltw128 v5,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0xFF));
	// vperm128 v62,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v63,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v61,v61,v61,v6
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v60,v60,v60,v6
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmaddfp v6,v1,v4,v31
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v8,v5,v8,v7
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v11,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vmaddfp v10,v9,v10,v3
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v0,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vmaddfp v12,v11,v12,v6
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v13,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vaddfp128 v61,v10,v56
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vaddfp128 v63,v12,v56
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vaddfp128 v62,v0,v56
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v56.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825f4634
	if (ctx.cr6.lt) goto loc_825F4634;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825F4634:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f4688
	if (ctx.cr0.eq) goto loc_825F4688;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825f4658
	if (ctx.cr6.lt) goto loc_825F4658;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825F4658:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f4688
	if (ctx.cr0.eq) goto loc_825F4688;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825f467c
	if (ctx.cr6.lt) goto loc_825F467C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825F467C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bnelr 
	if (!ctx.cr0.eq) return;
loc_825F4688:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8260DB50) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x8260c8a0
	ctx.lr = 0x8260DB70;
	sub_8260C8A0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r7,6(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// li r9,21
	ctx.r9.s64 = 21;
	// lhz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// li r8,8
	ctx.r8.s64 = 8;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// lwz r6,124(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// slw r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r7.u8 & 0x3F));
	// andc r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r10.u64;
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stw r10,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r10.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,444(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 444);
	// lwz r7,124(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 124);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// sth r8,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r8.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r9,444(r10)
	REX_STORE_U32(ctx.r10.u32 + 444, ctx.r9.u32);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8260dc14
	if (ctx.cr0.eq) goto loc_8260DC14;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r9,34
	ctx.r9.s64 = 34;
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r7,8(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,436
	ctx.r10.s64 = ctx.r11.s64 + 436;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 444);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// sth r8,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r8.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_8260DC14:
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

DEFINE_REX_FUNC(sub_82613230) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x82613238;
	__savegprlr_18(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// beq cr6,0x82613270
	if (ctx.cr6.eq) goto loc_82613270;
	// addi r11,r4,-22
	ctx.r11.s64 = ctx.r4.s64 + -22;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_82613264:
	// lbzu r10,32(r11)
	ea = 32 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// add r21,r10,r21
	ctx.r21.u64 = ctx.r10.u64 + ctx.r21.u64;
	// bdnz 0x82613264
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82613264;
loc_82613270:
	// clrlwi. r18,r6,24
	ctx.r18.u64 = ctx.r6.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq 0x8261327c
	if (ctx.cr0.eq) goto loc_8261327C;
	// addi r21,r21,3
	ctx.r21.s64 = ctx.r21.s64 + 3;
loc_8261327C:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82613740
	ctx.lr = 0x82613288;
	sub_82613740(ctx, base);
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r10,8(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// mulli r9,r11,136
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(136));
	// add r27,r9,r10
	ctx.r27.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// stw r11,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// stw r22,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r22.u32);
	// lwz r19,84(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// beq cr6,0x8261336c
	if (ctx.cr6.eq) goto loc_8261336C;
	// addi r31,r31,10
	ctx.r31.s64 = ctx.r31.s64 + 10;
	// addi r25,r27,68
	ctx.r25.s64 = ctx.r27.s64 + 68;
loc_826132C0:
	// lwz r11,2(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r11,-10
	ctx.r11.s64 = ctx.r11.s64 + -10;
	// beq 0x82613318
	if (ctx.cr0.eq) goto loc_82613318;
	// clrlwi r23,r30,16
	ctx.r23.u64 = ctx.r30.u32 & 0xFFFF;
	// addi r29,r11,-1
	ctx.r29.s64 = ctx.r11.s64 + -1;
loc_826132E4:
	// sth r23,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r23.u16);
	// lbz r11,2(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 2);
	// sth r11,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r11.u16);
	// lbz r4,3(r29)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r29.u32 + 3);
	// bl 0x82612f18
	ctx.lr = 0x826132F8;
	sub_82612F18(ctx, base);
	// lbzu r4,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r4.u64 = REX_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// bl 0x826130e8
	ctx.lr = 0x82613300;
	sub_826130E8(ctx, base);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stb r22,8(r3)
	REX_STORE_U8(ctx.r3.u32 + 8, ctx.r22.u8);
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826132e4
	if (ctx.cr6.lt) goto loc_826132E4;
loc_82613318:
	// lwz r11,16(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// slw r8,r10,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// addi r11,r11,-10
	ctx.r11.s64 = ctx.r11.s64 + -10;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r11,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// mulli r11,r11,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(20));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,-60(r25)
	REX_STORE_U32(ctx.r25.u32 + -60, ctx.r11.u32);
	// lbz r11,-1(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -1);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// stwu r11,4(r25)
	ea = 4 + ctx.r25.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r25.u32 = ea;
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// blt cr6,0x826132c0
	if (ctx.cr6.lt) goto loc_826132C0;
loc_8261336C:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x826133c8
	if (ctx.cr6.eq) goto loc_826133C8;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82613388:
	// lis r8,26
	ctx.r8.s64 = 1703936;
	// sth r9,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r9.u16);
	// li r5,15
	ctx.r5.s64 = 15;
	// stb r22,10(r11)
	REX_STORE_U8(ctx.r11.u32 + 10, ctx.r22.u8);
	// ori r8,r8,9126
	ctx.r8.u64 = ctx.r8.u64 | 9126;
	// stb r22,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r22.u8);
	// addi r7,r10,13
	ctx.r7.s64 = ctx.r10.s64 + 13;
	// sth r5,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r5.u16);
	// stw r8,6(r11)
	REX_STORE_U32(ctx.r11.u32 + 6, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r7,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x82613388
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82613388;
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r22,68(r27)
	REX_STORE_U32(ctx.r27.u32 + 68, ctx.r22.u32);
	// stw r11,132(r27)
	REX_STORE_U32(ctx.r27.u32 + 132, ctx.r11.u32);
loc_826133C8:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x8260ae20
	ctx.lr = 0x826133D4;
	sub_8260AE20(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x826133e8
	if (ctx.cr6.eq) goto loc_826133E8;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x825f8da0
	ctx.lr = 0x826133E8;
	sub_825F8DA0(ctx, base);
loc_826133E8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8261C910) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,29,0,2
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0xE0000000) | (ctx.r11.u64 & 0xFFFFFFFF1FFFFFFF);
	// stw r11,10548(r3)
	REX_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261D088) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// rlwinm r11,r11,0,8,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF0FFFFFF;
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

DEFINE_REX_FUNC(sub_8261D6C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r11,r4,20,9,11
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0x700000) | (ctx.r11.u64 & 0xFFFFFFFFFF8FFFFF);
	// stw r11,12028(r3)
	REX_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261E108) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,22,5,9
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 22) & 0x7C00000) | (ctx.r8.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826211B8) {
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
	// lbz r11,12363(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12363);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// add r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stb r11,12363(r3)
	REX_STORE_U8(ctx.r3.u32 + 12363, ctx.r11.u8);
	// stb r4,12298(r9)
	REX_STORE_U8(ctx.r9.u32 + 12298, ctx.r4.u8);
	// lwz r11,10932(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10932);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,10936(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 10936);
	// bne cr6,0x826212ec
	if (!ctx.cr6.eq) goto loc_826212EC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x826212ec
	if (!ctx.cr6.eq) goto loc_826212EC;
	// lbz r10,10940(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 10940);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm. r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,12892(r3)
	REX_STORE_U32(ctx.r3.u32 + 12892, ctx.r9.u32);
	// bne 0x826212d0
	if (!ctx.cr0.eq) goto loc_826212D0;
	// rlwinm. r11,r10,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826212d0
	if (!ctx.cr0.eq) goto loc_826212D0;
	// lbz r11,12363(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12363);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x826212d0
	if (!ctx.cr0.eq) goto loc_826212D0;
	// rlwinm. r11,r10,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82621234
	if (ctx.cr0.eq) goto loc_82621234;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x826212c4
	goto loc_826212C4;
loc_82621234:
	// rlwinm. r11,r10,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826212bc
	if (ctx.cr0.eq) goto loc_826212BC;
	// lwz r11,12616(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12616);
	// lwz r8,12904(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12904);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82621254
	if (ctx.cr6.eq) goto loc_82621254;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826212bc
	if (!ctx.cr6.eq) goto loc_826212BC;
loc_82621254:
	// lwz r11,12620(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12620);
	// lwz r8,12908(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12908);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8262126c
	if (ctx.cr6.eq) goto loc_8262126C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826212bc
	if (!ctx.cr6.eq) goto loc_826212BC;
loc_8262126C:
	// lwz r11,12624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12624);
	// lwz r8,12912(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12912);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82621284
	if (ctx.cr6.eq) goto loc_82621284;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826212bc
	if (!ctx.cr6.eq) goto loc_826212BC;
loc_82621284:
	// lwz r11,12628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12628);
	// lwz r8,12916(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12916);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8262129c
	if (ctx.cr6.eq) goto loc_8262129C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826212bc
	if (!ctx.cr6.eq) goto loc_826212BC;
loc_8262129C:
	// lwz r11,12632(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12632);
	// lwz r8,12920(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 12920);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826212b4
	if (ctx.cr6.eq) goto loc_826212B4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826212bc
	if (!ctx.cr6.eq) goto loc_826212BC;
loc_826212B4:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x826212c0
	goto loc_826212C0;
loc_826212BC:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_826212C0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_826212C4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x826212d4
	if (!ctx.cr0.eq) goto loc_826212D4;
loc_826212D0:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_826212D4:
	// rlwimi r10,r11,0,31,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// stw r9,12888(r31)
	REX_STORE_U32(ctx.r31.u32 + 12888, ctx.r9.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r10,10940(r31)
	REX_STORE_U8(ctx.r31.u32 + 10940, ctx.r10.u8);
	// stw r11,12884(r31)
	REX_STORE_U32(ctx.r31.u32 + 12884, ctx.r11.u32);
	// b 0x82621308
	goto loc_82621308;
loc_826212EC:
	// lbz r9,10940(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,12884(r31)
	REX_STORE_U32(ctx.r31.u32 + 12884, ctx.r11.u32);
	// rlwinm r11,r9,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,12892(r31)
	REX_STORE_U32(ctx.r31.u32 + 12892, ctx.r8.u32);
	// stw r10,12888(r31)
	REX_STORE_U32(ctx.r31.u32 + 12888, ctx.r10.u32);
	// stb r11,10940(r31)
	REX_STORE_U8(ctx.r31.u32 + 10940, ctx.r11.u8);
loc_82621308:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82621320
	if (!ctx.cr6.gt) goto loc_82621320;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826274c0
	ctx.lr = 0x82621320;
	sub_826274C0(ctx, base);
loc_82621320:
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r11,r11,24576
	ctx.r11.u64 = ctx.r11.u64 | 24576;
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12884(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12884);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,12888(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12888);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
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

DEFINE_REX_FUNC(sub_82632F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82632F78;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af14
	ctx.lr = 0x82632F80;
	__savefpr_23(ctx, base);
	// li r12,-144
	ctx.r12.s64 = -144;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f24,f1
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = ctx.f1.f64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// addi r11,r11,13600
	ctx.r11.s64 = ctx.r11.s64 + 13600;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// rlwinm r31,r4,4,0,27
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// lfs f25,-1132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1132);
	ctx.f25.f64 = double(temp.f32);
	// lfs f26,-1364(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1364);
	ctx.f26.f64 = double(temp.f32);
	// beq cr6,0x8263336c
	if (ctx.cr6.eq) goto loc_8263336C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82633264
	if (ctx.cr6.eq) goto loc_82633264;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x826331e8
	if (ctx.cr6.eq) goto loc_826331E8;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x82633188
	if (ctx.cr6.eq) goto loc_82633188;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x826330dc
	if (ctx.cr6.eq) goto loc_826330DC;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8263304c
	if (ctx.cr6.eq) goto loc_8263304C;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// bne cr6,0x8263304c
	if (!ctx.cr6.eq) goto loc_8263304C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8263300c
	if (ctx.cr6.eq) goto loc_8263300C;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r31,0
	ctx.cr0.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x8263300c
	if (ctx.cr0.eq) goto loc_8263300C;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_82633004:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82633004
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82633004;
loc_8263300C:
	// addi r11,r31,-16
	ctx.r11.s64 = ctx.r31.s64 + -16;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x826333c8
	if (!ctx.cr6.lt) goto loc_826333C8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf. r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lis r9,16256
	ctx.r9.s64 = 1065353216;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// beq 0x826333c8
	if (ctx.cr0.eq) goto loc_826333C8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82633040:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82633040
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82633040;
	// b 0x826333c8
	goto loc_826333C8;
loc_8263304C:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// rlwinm r11,r31,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x7FFFFFFF;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r6,r11,-16
	ctx.r6.s64 = ctx.r11.s64 + -16;
	// subfic r7,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r7.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
loc_8263306C:
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82633090
	if (ctx.cr6.lt) goto loc_82633090;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82633090
	if (!ctx.cr6.lt) goto loc_82633090;
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x826330b8
	goto loc_826330B8;
loc_82633090:
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x826330c8
	if (!ctx.cr6.lt) goto loc_826330C8;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826330c8
	if (ctx.cr6.lt) goto loc_826330C8;
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_826330B8:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// b 0x826330cc
	goto loc_826330CC;
loc_826330C8:
	// stfs f25,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
loc_826330CC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8263306c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8263306C;
	// b 0x826333c8
	goto loc_826333C8;
loc_826330DC:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// clrldi r10,r31,32
	ctx.r10.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f29,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// fdivs f28,f26,f31
	ctx.f28.f64 = double(float(ctx.f26.f64 / ctx.f31.f64));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r30,r28,-4
	ctx.r30.s64 = ctx.r28.s64 + -4;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f27,f13,f0
	ctx.f27.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82633110:
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// fmuls f31,f0,f24
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// fcmpu cr6,f31,f25
	ctx.cr6.compare(ctx.f31.f64, ctx.f25.f64);
	// bne cr6,0x8263313c
	if (!ctx.cr6.eq) goto loc_8263313C;
	// fmr f30,f26
	ctx.f30.f64 = ctx.f26.f64;
	// b 0x8263314c
	goto loc_8263314C;
loc_8263313C:
	// fmuls f30,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f31.f64 * ctx.f29.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82632478
	ctx.lr = 0x82633148;
	sub_82632478(ctx, base);
	// fdivs f30,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64 / ctx.f30.f64));
loc_8263314C:
	// fmuls f0,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 * ctx.f31.f64));
	// fcmpu cr6,f0,f25
	ctx.cr6.compare(ctx.f0.f64, ctx.f25.f64);
	// bne cr6,0x82633160
	if (!ctx.cr6.eq) goto loc_82633160;
	// fmr f0,f26
	ctx.f0.f64 = ctx.f26.f64;
	// b 0x82633170
	goto loc_82633170;
loc_82633160:
	// fmuls f31,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82632478
	ctx.lr = 0x8263316C;
	sub_82632478(ctx, base);
	// fdivs f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 / ctx.f31.f64));
loc_82633170:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// fmuls f0,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfsu f0,4(r30)
	ea = 4 + ctx.r30.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r30.u32 = ea;
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82633110
	if (ctx.cr6.lt) goto loc_82633110;
	// b 0x826333c8
	goto loc_826333C8;
loc_82633188:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// clrldi r10,r31,32
	ctx.r10.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 776);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_826331B4:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmuls f1,f0,f24
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// bl 0x82632d70
	ctx.lr = 0x826331D4;
	sub_82632D70(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stfsu f1,4(r29)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x826331b4
	if (ctx.cr6.lt) goto loc_826331B4;
	// b 0x826333c8
	goto loc_826333C8;
loc_826331E8:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// clrldi r10,r31,32
	ctx.r10.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 776);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fdivs f31,f26,f31
	ctx.f31.f64 = double(float(ctx.f26.f64 / ctx.f31.f64));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
	// lfs f29,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f29.f64 = double(temp.f32);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82633220:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f0,f0,f24
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// fmuls f0,f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// fneg f2,f0
	ctx.f2.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// bl 0x82632580
	ctx.lr = 0x82633250;
	sub_82632580(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stfsu f1,4(r29)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82633220
	if (ctx.cr6.lt) goto loc_82633220;
	// b 0x826333c8
	goto loc_826333C8;
loc_82633264:
	// clrldi r10,r31,32
	ctx.r10.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 776);
	ctx.f0.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x1)));
	// lfs f27,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// stfs f25,84(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fdivs f28,f26,f30
	ctx.f28.f64 = double(float(ctx.f26.f64 / ctx.f30.f64));
	// stfs f25,88(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
	// stfs f25,92(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vcsxwfp128 v127,v63,1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v127.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
loc_826332AC:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// vor128 v11,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// frsp f6,f0
	ctx.f6.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f6,f30
	ctx.f0.f64 = double(float(ctx.f6.f64 - ctx.f30.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// fnmsubs f0,f0,f0,f26
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f0.f64, -ctx.f26.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v0,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v63.f32))));
	// vmulfp128 v12,v0,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmulfp128 v13,v63,v127
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vcmpeqfp128 v62,v0,v0
	simde_mm_store_ps(ctx.v62.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp128 v11,v13,v12,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vcmpeqfp128 v61,v11,v11
	simde_mm_store_ps(ctx.v61.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v0,v63,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vxor128 v13,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vsel v13,v0,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x82632ba0
	ctx.lr = 0x8263331C;
	sub_82632BA0(ctx, base);
	// fmr f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82632ba0
	ctx.lr = 0x82633328;
	sub_82632BA0(ctx, base);
	// fsubs f0,f6,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f6.f64 - ctx.f30.f64));
	// fdivs f29,f5,f1
	ctx.f29.f64 = double(float(ctx.f5.f64 / ctx.f1.f64));
	// fmuls f0,f0,f24
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// fcmpu cr6,f0,f25
	ctx.cr6.compare(ctx.f0.f64, ctx.f25.f64);
	// bne cr6,0x82633344
	if (!ctx.cr6.eq) goto loc_82633344;
	// fmr f0,f26
	ctx.f0.f64 = ctx.f26.f64;
	// b 0x82633354
	goto loc_82633354;
loc_82633344:
	// fmuls f23,f0,f27
	ctx.fpscr.disableFlushMode();
	ctx.f23.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// fmr f1,f23
	ctx.f1.f64 = ctx.f23.f64;
	// bl 0x82632478
	ctx.lr = 0x82633350;
	sub_82632478(ctx, base);
	// fdivs f0,f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 / ctx.f23.f64));
loc_82633354:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// fmuls f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfsu f0,4(r29)
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x826332ac
	if (ctx.cr6.lt) goto loc_826332AC;
	// b 0x826333c8
	goto loc_826333C8;
loc_8263336C:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x826333c8
	if (ctx.cr6.eq) goto loc_826333C8;
	// clrldi r10,r31,32
	ctx.r10.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f0,776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 776);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82633398:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmuls f1,f0,f24
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// bl 0x82632e68
	ctx.lr = 0x826333B8;
	sub_82632E68(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stfsu f1,4(r29)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82633398
	if (ctx.cr6.lt) goto loc_82633398;
loc_826333C8:
	// stfs f25,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// li r9,16
	ctx.r9.s64 = 16;
loc_826333D4:
	// fmr f0,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f25.f64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82633410
	if (ctx.cr6.eq) goto loc_82633410;
	// addi r10,r11,-64
	ctx.r10.s64 = ctx.r11.s64 + -64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_826333E8:
	// lfsu f13,64(r10)
	ctx.fpscr.disableFlushMode();
	ea = 64 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bdnz 0x826333e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826333E8;
	// fdivs f0,f26,f0
	ctx.f0.f64 = double(float(ctx.f26.f64 / ctx.f0.f64));
	// addi r10,r11,-64
	ctx.r10.s64 = ctx.r11.s64 + -64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_82633400:
	// lfs f13,64(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfsu f13,64(r10)
	ea = 64 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82633400
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82633400;
loc_82633410:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x826333d4
	if (!ctx.cr0.eq) goto loc_826333D4;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-144
	ctx.r0.s64 = -144;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af60
	ctx.lr = 0x82633430;
	__restfpr_23(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265E810) {
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
	// lwz r10,128(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// bne cr6,0x8265e850
	if (!ctx.cr6.eq) goto loc_8265E850;
	// std r9,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r9.u64);
	// std r9,8(r4)
	REX_STORE_U64(ctx.r4.u32 + 8, ctx.r9.u64);
	// std r9,16(r4)
	REX_STORE_U64(ctx.r4.u32 + 16, ctx.r9.u64);
	// std r9,24(r4)
	REX_STORE_U64(ctx.r4.u32 + 24, ctx.r9.u64);
	// std r9,32(r4)
	REX_STORE_U64(ctx.r4.u32 + 32, ctx.r9.u64);
	// b 0x8265e928
	goto loc_8265E928;
loc_8265E850:
	// lwz r10,664(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 664);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8265e8f8
	if (!ctx.cr6.eq) goto loc_8265E8F8;
	// lwz r10,660(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// addi r6,r11,656
	ctx.r6.s64 = ctx.r11.s64 + 656;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// mulli r10,r10,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,576
	ctx.r8.s64 = ctx.r10.s64 + 576;
	// std r9,576(r10)
	REX_STORE_U64(ctx.r10.u32 + 576, ctx.r9.u64);
	// std r9,584(r10)
	REX_STORE_U64(ctx.r10.u32 + 584, ctx.r9.u64);
	// std r9,592(r10)
	REX_STORE_U64(ctx.r10.u32 + 592, ctx.r9.u64);
	// std r9,600(r10)
	REX_STORE_U64(ctx.r10.u32 + 600, ctx.r9.u64);
	// std r9,608(r10)
	REX_STORE_U64(ctx.r10.u32 + 608, ctx.r9.u64);
loc_8265E888:
	// lwz r10,660(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// mulli r10,r10,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// mulli r7,r8,40
	ctx.r7.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r8,r8,576
	ctx.r8.s64 = ctx.r8.s64 + 576;
	// addi r10,r10,576
	ctx.r10.s64 = ctx.r10.s64 + 576;
loc_8265E8A8:
	// mfmsr r4
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r4.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r5,0,r6
	ea = ctx.r6.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r5.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8265e8cc
	if (!ctx.cr6.eq) goto loc_8265E8CC;
	// stwcx. r10,0,r6
	ea = ctx.r6.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8265e8a8
	if (!ctx.cr0.eq) goto loc_8265E8A8;
	// b 0x8265e8d4
	goto loc_8265E8D4;
loc_8265E8CC:
	// stwcx. r5,0,r6
	ea = ctx.r6.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r5.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_8265E8D4:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwsync 
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8265e8ec
	if (!ctx.cr6.eq) goto loc_8265E8EC;
	// db16cyc 
	// b 0x8265e888
	goto loc_8265E888;
loc_8265E8EC:
	// lwz r10,660(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// stw r10,660(r11)
	REX_STORE_U32(ctx.r11.u32 + 660, ctx.r10.u32);
loc_8265E8F8:
	// lwz r8,660(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r7,r31,-8
	ctx.r7.s64 = ctx.r31.s64 + -8;
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r10,r10,568
	ctx.r10.s64 = ctx.r10.s64 + 568;
loc_8265E918:
	// ldu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r8,8(r7)
	ea = 8 + ctx.r7.u32;
	REX_STORE_U64(ea, ctx.r8.u64);
	ctx.r7.u32 = ea;
	// bdnz 0x8265e918
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8265E918;
	// stw r9,664(r11)
	REX_STORE_U32(ctx.r11.u32 + 664, ctx.r9.u32);
loc_8265E928:
	// mftb r10
	ctx.r10.u64 = REX_QUERY_TIMEBASE();
	// ld r8,672(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 672);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// subf r9,r8,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addi r3,r7,13120
	ctx.r3.s64 = ctx.r7.s64 + 13120;
	// std r9,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r9.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r10,672(r11)
	REX_STORE_U64(ctx.r11.u32 + 672, ctx.r10.u64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8265e2a8
	ctx.lr = 0x8265E958;
	sub_8265E2A8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8266CEE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x8266CEF0;
	__savegprlr_22(ctx, base);
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x8273af1c
	ctx.lr = 0x8266CEF8;
	__savefpr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8266c270
	ctx.lr = 0x8266CF08;
	sub_8266C270(ctx, base);
	// lwz r8,80(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r29,r11,24896
	ctx.r29.s64 = ctx.r11.s64 + 24896;
	// lfs f13,24244(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24244);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f25,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f25.f64 = double(temp.f32);
	// blt cr6,0x8266cf4c
	if (ctx.cr6.lt) goto loc_8266CF4C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,24192(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24192);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,24212(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24212);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8266cf70
	goto loc_8266CF70;
loc_8266CF4C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,8048(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8048);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f12,f0,f13,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f13,24192(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24212);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
loc_8266CF70:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8266cf7c
	if (!ctx.cr6.lt) goto loc_8266CF7C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8266CF7C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,8680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8680);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f31,f13,f12
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8266cf98
	if (!ctx.cr6.lt) goto loc_8266CF98;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// b 0x8266cfa4
	goto loc_8266CFA4;
loc_8266CF98:
	// fcmpu cr6,f31,f25
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f25.f64);
	// ble cr6,0x8266cfa4
	if (!ctx.cr6.gt) goto loc_8266CFA4;
	// fmr f31,f25
	ctx.f31.f64 = ctx.f25.f64;
loc_8266CFA4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,28196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28196);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82689b80
	ctx.lr = 0x8266CFC0;
	sub_82689B80(ctx, base);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r10,25092
	ctx.r8.u64 = ctx.r10.u64 | 25092;
	// ori r7,r9,25096
	ctx.r7.u64 = ctx.r9.u64 | 25096;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stwx r3,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// lfs f0,28216(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 28216);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f31,f0
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82689b80
	ctx.lr = 0x8266CFF8;
	sub_82689B80(ctx, base);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// ori r10,r5,33860
	ctx.r10.u64 = ctx.r5.u64 | 33860;
	// ori r9,r4,33864
	ctx.r9.u64 = ctx.r4.u64 | 33864;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// stwx r3,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r11,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.u64 = static_cast<uint64_t>(0) - ctx.r8.u64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r6,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwinm r11,r11,0,28,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// addi r11,r11,1020
	ctx.r11.s64 = ctx.r11.s64 + 1020;
	// clrldi r5,r11,32
	ctx.r5.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fctidz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82689b80
	ctx.lr = 0x8266D054;
	sub_82689B80(ctx, base);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// ori r9,r11,59428
	ctx.r9.u64 = ctx.r11.u64 | 59428;
	// ori r10,r4,63780
	ctx.r10.u64 = ctx.r4.u64 | 63780;
	// ori r6,r8,55560
	ctx.r6.u64 = ctx.r8.u64 | 55560;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lwzx r11,r31,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ori r5,r7,22692
	ctx.r5.u64 = ctx.r7.u64 | 22692;
	// lwzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lwzx r9,r31,r6
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// ori r6,r4,22304
	ctx.r6.u64 = ctx.r4.u64 | 22304;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lwzx r10,r31,r5
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ori r9,r7,41116
	ctx.r9.u64 = ctx.r7.u64 | 41116;
	// lis r5,3
	ctx.r5.s64 = 196608;
	// lwzx r8,r31,r6
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// ori r7,r4,20232
	ctx.r7.u64 = ctx.r4.u64 | 20232;
	// lis r28,2
	ctx.r28.s64 = 131072;
	// lis r27,2
	ctx.r27.s64 = 131072;
	// ori r6,r5,18768
	ctx.r6.u64 = ctx.r5.u64 | 18768;
	// stwx r3,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r5,r28,18572
	ctx.r5.u64 = ctx.r28.u64 | 18572;
	// lwzx r9,r31,r7
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// ori r4,r27,47344
	ctx.r4.u64 = ctx.r27.u64 | 47344;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r7,r31,r6
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// addi r3,r29,504
	ctx.r3.s64 = ctx.r29.s64 + 504;
	// addi r6,r29,632
	ctx.r6.s64 = ctx.r29.s64 + 632;
	// lwzx r10,r31,r5
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r8,r31,r4
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r5,72(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// ori r5,r4,10352
	ctx.r5.u64 = ctx.r4.u64 | 10352;
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lwz r7,8(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r9,r9,42952
	ctx.r9.u64 = ctx.r9.u64 | 42952;
	// lis r28,1
	ctx.r28.s64 = 65536;
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r11,r31,r5
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// ori r8,r28,40880
	ctx.r8.u64 = ctx.r28.u64 | 40880;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r9,r31,r9
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ori r5,r5,39096
	ctx.r5.u64 = ctx.r5.u64 | 39096;
	// lis r28,1
	ctx.r28.s64 = 65536;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r11,r31,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// ori r8,r28,38780
	ctx.r8.u64 = ctx.r28.u64 | 38780;
	// lis r28,3
	ctx.r28.s64 = 196608;
	// lwzx r9,r31,r5
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r5,r28,2364
	ctx.r5.u64 = ctx.r28.u64 | 2364;
	// lis r28,2
	ctx.r28.s64 = 131072;
	// lwzx r10,r31,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ori r8,r28,2136
	ctx.r8.u64 = ctx.r28.u64 | 2136;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f5,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// lwzx r9,r31,r5
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r28,-32256
	ctx.r28.s64 = -2113929216;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r10,r31,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f0,28124(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 28124);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r29,760
	ctx.r11.s64 = ctx.r29.s64 + 760;
	// lfd f31,8696(r28)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r28.u32 + 8696);
	// rlwinm r10,r4,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f29,r8,r3
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	ctx.f29.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// lfs f13,28120(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28120);
	ctx.f13.f64 = double(temp.f32);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// lfsx f28,r7,r6
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	ctx.f28.f64 = double(temp.f32);
	// lfsx f27,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fdivs f12,f5,f0
	ctx.f12.f64 = double(float(ctx.f5.f64 / ctx.f0.f64));
	// fdivs f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// bl 0x82738fd8
	ctx.lr = 0x8266D1D0;
	sub_82738FD8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r6,20(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r29,376
	ctx.r8.s64 = ctx.r29.s64 + 376;
	// lfs f0,7996(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 7996);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r29,888
	ctx.r7.s64 = ctx.r29.s64 + 888;
	// addi r6,r29,192
	ctx.r6.s64 = ctx.r29.s64 + 192;
	// lfs f13,28116(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24220(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24220);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r10,r29,632
	ctx.r10.s64 = ctx.r29.s64 + 632;
	// lfsx f9,r3,r8
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfsx f30,r3,r7
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f7,r3,r6
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	ctx.f7.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fsqrts f6,f8
	ctx.f6.f64 = double(float(sqrt(ctx.f8.f64)));
	// fnmsubs f5,f6,f13,f12
	ctx.f5.f64 = double(float(-std::fma(ctx.f6.f64, ctx.f13.f64, -ctx.f12.f64)));
	// lfs f0,28112(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 28112);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f10,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f11,f30,f0
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fmuls f13,f9,f5
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fmuls f12,f7,f5
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fmuls f26,f13,f0
	ctx.f26.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne cr6,0x8266d254
	if (!ctx.cr6.eq) goto loc_8266D254;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8266d280
	goto loc_8266D280;
loc_8266D254:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f0
	ctx.f9.f64 = double(ctx.f0.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lfs f0,28212(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28212);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fctidz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8266D280:
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// addi r11,r11,22960
	ctx.r11.s64 = ctx.r11.s64 + 22960;
	// ori r7,r8,8
	ctx.r7.u64 = ctx.r8.u64 | 8;
	// addis r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 131072;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwzx r5,r11,r7
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8266d2cc
	if (!ctx.cr6.eq) goto loc_8266D2CC;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r6,r8,12
	ctx.r6.u64 = ctx.r8.u64 | 12;
	// ori r5,r7,20
	ctx.r5.u64 = ctx.r7.u64 | 20;
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stwx r4,r11,r6
	REX_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r4.u32);
	// stfsx f25,r11,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, temp.u32);
	// b 0x8266d2dc
	goto loc_8266D2DC;
loc_8266D2CC:
	// lis r10,2
	ctx.r10.s64 = 131072;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r8,r10,12
	ctx.r8.u64 = ctx.r10.u64 | 12;
	// stwx r9,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u32);
loc_8266D2DC:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lfs f9,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// ori r9,r11,68
	ctx.r9.u64 = ctx.r11.u64 | 68;
	// lfs f8,20(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lis r8,5
	ctx.r8.s64 = 327680;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r11,r10,25104
	ctx.r11.u64 = ctx.r10.u64 | 25104;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// stfsx f10,r31,r9
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r10,r8,25108
	ctx.r10.u64 = ctx.r8.u64 | 25108;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// ori r9,r7,25112
	ctx.r9.u64 = ctx.r7.u64 | 25112;
	// addi r6,r29,3144
	ctx.r6.s64 = ctx.r29.s64 + 3144;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addis r8,r31,5
	ctx.r8.s64 = ctx.r31.s64 + 327680;
	// ori r7,r5,33872
	ctx.r7.u64 = ctx.r5.u64 | 33872;
	// ori r5,r4,33876
	ctx.r5.u64 = ctx.r4.u64 | 33876;
	// addis r25,r31,6
	ctx.r25.s64 = ctx.r31.s64 + 393216;
	// ori r4,r3,33880
	ctx.r4.u64 = ctx.r3.u64 | 33880;
	// addi r8,r8,25128
	ctx.r8.s64 = ctx.r8.s64 + 25128;
	// addis r24,r31,6
	ctx.r24.s64 = ctx.r31.s64 + 393216;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r28,5
	ctx.r28.s64 = 327680;
	// lis r27,5
	ctx.r27.s64 = 327680;
	// lis r26,5
	ctx.r26.s64 = 327680;
	// addi r25,r25,-31640
	ctx.r25.s64 = ctx.r25.s64 + -31640;
	// addi r24,r24,-30592
	ctx.r24.s64 = ctx.r24.s64 + -30592;
	// ori r3,r3,41124
	ctx.r3.u64 = ctx.r3.u64 | 41124;
	// ori r28,r28,41128
	ctx.r28.u64 = ctx.r28.u64 | 41128;
	// lwz r23,24(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// ori r27,r27,23032
	ctx.r27.u64 = ctx.r27.u64 | 23032;
	// ori r26,r26,23036
	ctx.r26.u64 = ctx.r26.u64 | 23036;
	// rlwinm r23,r23,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r22,-32256
	ctx.r22.s64 = -2113929216;
	// lfsx f10,r23,r6
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfsx f29,r31,r9
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// fneg f7,f10
	ctx.f7.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f9,r31,r10
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfs f10,524(r8)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r8.u32 + 524, temp.u32);
	// stfs f7,528(r8)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r8.u32 + 528, temp.u32);
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f8,r31,r5
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stfsx f11,r31,r4
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// stfs f10,1036(r25)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r25.u32 + 1036, temp.u32);
	// stfs f7,1040(r25)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r25.u32 + 1040, temp.u32);
	// stfs f10,2060(r24)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r24.u32 + 2060, temp.u32);
	// stfs f7,2064(r24)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r24.u32 + 2064, temp.u32);
	// stfsx f12,r31,r3
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f13,r31,r28
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// stfsx f28,r31,r27
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stfsx f27,r31,r26
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r26.u32, temp.u32);
	// lwz r11,68(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// lfs f29,24128(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 24128);
	ctx.f29.f64 = double(temp.f32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f6,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f2,f6,f29
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f29.f64));
	// bl 0x82738fd8
	ctx.lr = 0x8266D3D0;
	sub_82738FD8(ctx, base);
	// frsp f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// lis r10,1
	ctx.r10.s64 = 65536;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// ori r9,r10,59440
	ctx.r9.u64 = ctx.r10.u64 | 59440;
	// fmuls f4,f5,f30
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f30.f64));
	// stfsx f4,r31,r9
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lwz r8,68(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f3,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f29
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f29.f64));
	// bl 0x82738fd8
	ctx.lr = 0x8266D3FC;
	sub_82738FD8(ctx, base);
	// lis r7,3
	ctx.r7.s64 = 196608;
	// lfs f0,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addis r28,r31,5
	ctx.r28.s64 = ctx.r31.s64 + 327680;
	// frsp f2,f1
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// addis r4,r31,6
	ctx.r4.s64 = ctx.r31.s64 + 393216;
	// addi r28,r28,22992
	ctx.r28.s64 = ctx.r28.s64 + 22992;
	// ori r6,r7,18780
	ctx.r6.u64 = ctx.r7.u64 | 18780;
	// addi r5,r29,3144
	ctx.r5.s64 = ctx.r29.s64 + 3144;
	// addi r4,r4,-24396
	ctx.r4.s64 = ctx.r4.s64 + -24396;
	// fmuls f1,f2,f26
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f26.f64));
	// stfsx f1,r31,r6
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r11,r11,-22324
	ctx.r11.s64 = ctx.r11.s64 + -22324;
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r5
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f12,2060(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 2060, temp.u32);
	// stfs f11,2064(r4)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r4.u32 + 2064, temp.u32);
	// stfs f12,2060(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 2060, temp.u32);
	// stfs f11,2064(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 2064, temp.u32);
	// lwz r8,52(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f10,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,4(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// bl 0x8266bc18
	ctx.lr = 0x8266D46C;
	sub_8266BC18(ctx, base);
	// lwz r7,56(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,8(r28)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// bl 0x8266bc18
	ctx.lr = 0x8266D484;
	sub_8266BC18(ctx, base);
	// lwz r6,60(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f8,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,12(r28)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// bl 0x8266bc18
	ctx.lr = 0x8266D49C;
	sub_8266BC18(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x8273af68
	ctx.lr = 0x8266D4A8;
	__restfpr_25(ctx, base);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269C4D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8269C4E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r31,44(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// clrldi r29,r4,32
	ctx.r29.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_8269C4F8:
	// lwz r9,44(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r8,16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8269c524
	if (ctx.cr6.eq) goto loc_8269C524;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
loc_8269C524:
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// ld r9,40(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r29
	ctx.r11.u64 = ctx.r9.u64 + ctx.r29.u64;
	// cmpld cr6,r30,r11
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, ctx.r11.u64, ctx.xer);
	// bge cr6,0x8269c590
	if (!ctx.cr6.lt) goto loc_8269C590;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269C554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c590
	if (ctx.cr6.lt) goto loc_8269C590;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8269bcd8
	ctx.lr = 0x8269C568;
	sub_8269BCD8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c590
	if (ctx.cr6.lt) goto loc_8269C590;
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r9,116(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// ld r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
	// cmpld cr6,r30,r9
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, ctx.r9.u64, ctx.xer);
	// blt cr6,0x8269c4f8
	if (ctx.cr6.lt) goto loc_8269C4F8;
loc_8269C590:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269FC18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8269fc4c
	if (!ctx.cr6.eq) goto loc_8269FC4C;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269FC4C:
	// lwz r11,22260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22260);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8269fc74
	if (!ctx.cr6.eq) goto loc_8269FC74;
	// li r3,12
	ctx.r3.s64 = 12;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269FC74:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r10,22256(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22256);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// ori r8,r11,39848
	ctx.r8.u64 = ctx.r11.u64 | 39848;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r5,92
	ctx.r5.s64 = 92;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwzx r7,r31,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x8273a030
	ctx.lr = 0x8269FCA4;
	sub_8273A030(ctx, base);
	// lwz r6,22112(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 22112);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,22280(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 22280);
	// lwz r4,22284(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 22284);
	// addic r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// subfe r10,r11,r6
	temp.u8 = (~ctx.r11.u32 + ctx.r6.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r11.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r4,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x826ba6b8
	ctx.lr = 0x8269FCCC;
	sub_826BA6B8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826B7020) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826B7028;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// lwz r18,312(r3)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// li r5,256
	ctx.r5.s64 = 256;
	// lwz r17,316(r3)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,1760(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 1760);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// mr r23,r25
	ctx.r23.u64 = ctx.r25.u64;
	// lwz r8,16(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r7,20(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r24,0(r10)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r21,28(r10)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// addi r19,r11,1
	ctx.r19.s64 = ctx.r11.s64 + 1;
	// lwz r20,32(r10)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r15,24(r10)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r16,4(r10)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r25,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x8273a590
	ctx.lr = 0x826B7094;
	sub_8273A590(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r14,1
	ctx.r14.s64 = 1;
	// ori r26,r11,32768
	ctx.r26.u64 = ctx.r11.u64 | 32768;
loc_826B70A0:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lbz r4,8(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 8);
	// lwz r29,0(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// subfic r10,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// srd r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r29
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r29.u32);
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b7190
	if (ctx.cr6.lt) goto loc_826B7190;
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
	// bge cr6,0x826b7188
	if (!ctx.cr6.lt) goto loc_826B7188;
loc_826B70F0:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826b711c
	if (ctx.cr6.lt) goto loc_826B711C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x826B710C;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x826b70f0
	if (ctx.cr6.eq) goto loc_826B70F0;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b71c8
	goto loc_826B71C8;
loc_826B711C:
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
loc_826B7188:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b71c8
	goto loc_826B71C8;
loc_826B7190:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x826B7198;
	sub_826C8C48(ctx, base);
loc_826B7198:
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
	ctx.lr = 0x826B71B0;
	sub_826C8C48(ctx, base);
	// add r10,r30,r26
	ctx.r10.u64 = ctx.r30.u64 + ctx.r26.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b7198
	if (ctx.cr6.lt) goto loc_826B7198;
loc_826B71C8:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r31,r16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x826b723c
	if (ctx.cr6.eq) goto loc_826B723C;
	// cmplw cr6,r31,r19
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x826b71f4
	if (ctx.cr6.lt) goto loc_826B71F4;
	// mr r25,r14
	ctx.r25.u64 = ctx.r14.u64;
loc_826B71F4:
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// lbzx r28,r31,r20
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r20.u32);
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
	// bge 0x826b721c
	if (!ctx.cr0.lt) goto loc_826B721C;
	// bl 0x826c8b78
	ctx.lr = 0x826B721C;
	sub_826C8B78(ctx, base);
loc_826B721C:
	// lbzx r11,r31,r21
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r21.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826b7234
	if (ctx.cr6.eq) goto loc_826B7234;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// neg r31,r10
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// b 0x826b77f0
	goto loc_826B77F0;
loc_826B7234:
	// extsb r31,r11
	ctx.r31.s64 = ctx.r11.s8;
	// b 0x826b77f0
	goto loc_826B77F0;
loc_826B723C:
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
	// bge 0x826b7260
	if (!ctx.cr0.lt) goto loc_826B7260;
	// bl 0x826c8b78
	ctx.lr = 0x826B7260;
	sub_826C8B78(ctx, base);
loc_826B7260:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826b7420
	if (!ctx.cr6.eq) goto loc_826B7420;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// lbz r4,8(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 8);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subfic r10,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r29,0(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// srd r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r29
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r29.u32);
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b7364
	if (ctx.cr6.lt) goto loc_826B7364;
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
	// bge cr6,0x826b735c
	if (!ctx.cr6.lt) goto loc_826B735C;
loc_826B72C4:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826b72f0
	if (ctx.cr6.lt) goto loc_826B72F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x826B72E0;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x826b72c4
	if (ctx.cr6.eq) goto loc_826B72C4;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b739c
	goto loc_826B739C;
loc_826B72F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r6,r10,8,55
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r6,r10
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r4
	ctx.r7.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r6,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r3.u8 & 0x7F));
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r5,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r5.u64);
loc_826B735C:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b739c
	goto loc_826B739C;
loc_826B7364:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x826B736C;
	sub_826C8C48(ctx, base);
loc_826B736C:
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
	ctx.lr = 0x826B7384;
	sub_826C8C48(ctx, base);
	// add r10,r30,r26
	ctx.r10.u64 = ctx.r30.u64 + ctx.r26.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b736c
	if (ctx.cr6.lt) goto loc_826B736C;
loc_826B739C:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r11,r16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x826b78e4
	if (ctx.cr6.eq) goto loc_826B78E4;
	// lbzx r10,r11,r21
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r21.u32);
	// cmplw cr6,r11,r19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r19.u32, ctx.xer);
	// lbzx r28,r11,r20
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r20.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// blt cr6,0x826b73dc
	if (ctx.cr6.lt) goto loc_826B73DC;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r25,r14
	ctx.r25.u64 = ctx.r14.u64;
	// b 0x826b73e0
	goto loc_826B73E0;
loc_826B73DC:
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_826B73E0:
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
	// bge 0x826b7410
	if (!ctx.cr0.lt) goto loc_826B7410;
	// bl 0x826c8b78
	ctx.lr = 0x826B7410;
	sub_826C8B78(ctx, base);
loc_826B7410:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826b77f0
	if (ctx.cr6.eq) goto loc_826B77F0;
	// neg r31,r31
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// b 0x826b77f0
	goto loc_826B77F0;
loc_826B7420:
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
	// bge 0x826b7448
	if (!ctx.cr0.lt) goto loc_826B7448;
	// bl 0x826c8b78
	ctx.lr = 0x826B7448;
	sub_826C8B78(ctx, base);
loc_826B7448:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826b7608
	if (!ctx.cr6.eq) goto loc_826B7608;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// lbz r4,8(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 8);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subfic r10,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r29,0(r24)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// srd r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r29
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r29.u32);
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b754c
	if (ctx.cr6.lt) goto loc_826B754C;
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
	// bge cr6,0x826b7544
	if (!ctx.cr6.lt) goto loc_826B7544;
loc_826B74AC:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826b74d8
	if (ctx.cr6.lt) goto loc_826B74D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x826B74C8;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x826b74ac
	if (ctx.cr6.eq) goto loc_826B74AC;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b7584
	goto loc_826B7584;
loc_826B74D8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r6,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r3.u8 & 0x7F));
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r5,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r5.u64);
loc_826B7544:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x826b7584
	goto loc_826B7584;
loc_826B754C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x826B7554;
	sub_826C8C48(ctx, base);
loc_826B7554:
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
	ctx.lr = 0x826B756C;
	sub_826C8C48(ctx, base);
	// add r10,r30,r26
	ctx.r10.u64 = ctx.r30.u64 + ctx.r26.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826b7554
	if (ctx.cr6.lt) goto loc_826B7554;
loc_826B7584:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r11,r16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x826b78e4
	if (ctx.cr6.eq) goto loc_826B78E4;
	// lbzx r10,r11,r21
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r21.u32);
	// cmplw cr6,r11,r19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r19.u32, ctx.xer);
	// lbzx r11,r11,r20
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r20.u32);
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
	// blt cr6,0x826b75c4
	if (ctx.cr6.lt) goto loc_826B75C4;
	// lbzx r10,r31,r15
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r15.u32);
	// mr r25,r14
	ctx.r25.u64 = ctx.r14.u64;
	// b 0x826b75cc
	goto loc_826B75CC;
loc_826B75C4:
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lbzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
loc_826B75CC:
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
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
	// bge 0x826b75f8
	if (!ctx.cr0.lt) goto loc_826B75F8;
	// bl 0x826c8b78
	ctx.lr = 0x826B75F8;
	sub_826C8B78(ctx, base);
loc_826B75F8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826b77f0
	if (ctx.cr6.eq) goto loc_826B77F0;
	// neg r31,r31
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// b 0x826b77f0
	goto loc_826B77F0;
loc_826B7608:
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
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b7630
	if (!ctx.cr0.lt) goto loc_826B7630;
	// bl 0x826c8b78
	ctx.lr = 0x826B7630;
	sub_826C8B78(ctx, base);
loc_826B7630:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// li r30,6
	ctx.r30.s64 = 6;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bge cr6,0x826b76a8
	if (!ctx.cr6.lt) goto loc_826B76A8;
loc_826B7650:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b76a8
	if (ctx.cr6.eq) goto loc_826B76A8;
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
	// bge 0x826b7698
	if (!ctx.cr0.lt) goto loc_826B7698;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B7698;
	sub_826C8B78(ctx, base);
loc_826B7698:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826b7650
	if (ctx.cr6.gt) goto loc_826B7650;
loc_826B76A8:
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
	// bge 0x826b76e4
	if (!ctx.cr0.lt) goto loc_826B76E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B76E4;
	sub_826C8B78(ctx, base);
loc_826B76E4:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b770c
	if (!ctx.cr0.lt) goto loc_826B770C;
	// bl 0x826c8b78
	ctx.lr = 0x826B770C;
	sub_826C8B78(ctx, base);
loc_826B770C:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,12
	ctx.r30.s64 = 12;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bge cr6,0x826b7780
	if (!ctx.cr6.lt) goto loc_826B7780;
loc_826B7728:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b7780
	if (ctx.cr6.eq) goto loc_826B7780;
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
	// bge 0x826b7770
	if (!ctx.cr0.lt) goto loc_826B7770;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B7770;
	sub_826C8B78(ctx, base);
loc_826B7770:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826b7728
	if (ctx.cr6.gt) goto loc_826B7728;
loc_826B7780:
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
	// bge 0x826b77bc
	if (!ctx.cr0.lt) goto loc_826B77BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B77BC;
	sub_826C8B78(ctx, base);
loc_826B77BC:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,2047
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2047, ctx.xer);
	// ble cr6,0x826b77cc
	if (!ctx.cr6.gt) goto loc_826B77CC;
	// addi r31,r30,-4096
	ctx.r31.s64 = ctx.r30.s64 + -4096;
loc_826B77CC:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b77f0
	if (!ctx.cr0.lt) goto loc_826B77F0;
	// bl 0x826c8b78
	ctx.lr = 0x826B77F0;
	sub_826C8B78(ctx, base);
loc_826B77F0:
	// lwz r11,84(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826b78e4
	if (!ctx.cr6.eq) goto loc_826B78E4;
	// add r11,r28,r23
	ctx.r11.u64 = ctx.r28.u64 + ctx.r23.u64;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x826b78e4
	if (!ctx.cr6.lt) goto loc_826B78E4;
	// lwz r10,1828(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 1828);
	// lbzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826b7838
	if (ctx.cr6.eq) goto loc_826B7838;
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r7,r9,29
	ctx.r7.u64 = ctx.r9.u32 & 0x7;
	// slw r6,r14,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r7.u8 & 0x3F));
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_826B7838:
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 | ctx.r8.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bne cr6,0x826b786c
	if (!ctx.cr6.eq) goto loc_826B786C;
	// lbzx r10,r11,r22
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r22.u32);
	// lwz r8,1760(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// lwz r7,304(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 304);
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r7,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x826b78c0
	goto loc_826B78C0;
loc_826B786C:
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x826b788c
	if (!ctx.cr6.eq) goto loc_826B788C;
	// lbzx r10,r11,r22
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r22.u32);
	// lwz r8,1760(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// lwz r7,308(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 308);
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r7,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r7.u32);
	// b 0x826b78c0
	goto loc_826B78C0;
loc_826B788C:
	// lwz r7,1760(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x826b78ac
	if (!ctx.cr6.gt) goto loc_826B78AC;
	// lbzx r8,r11,r22
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r22.u32);
	// mullw r10,r31,r18
	ctx.r10.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r18.s32);
	// rotlwi r6,r8,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// add r5,r10,r17
	ctx.r5.u64 = ctx.r10.u64 + ctx.r17.u64;
	// b 0x826b78bc
	goto loc_826B78BC;
loc_826B78AC:
	// lbzx r10,r11,r22
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r22.u32);
	// mullw r8,r31,r18
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r18.s32);
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// subf r5,r17,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r17.u64;
loc_826B78BC:
	// stwx r5,r6,r7
	REX_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r5.u32);
loc_826B78C0:
	// addi r23,r11,1
	ctx.r23.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x826b70a0
	if (ctx.cr6.eq) goto loc_826B70A0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,1944(r27)
	REX_STORE_U32(ctx.r27.u32 + 1944, ctx.r9.u32);
	// stw r11,1940(r27)
	REX_STORE_U32(ctx.r27.u32 + 1940, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826B78E4:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826FFB08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x826FFB10;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFB44;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r30,r30,r29
	ctx.r30.u64 = ctx.r30.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r28,r28,r11
	ctx.r28.u64 = ctx.r28.u64 + ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFB60;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r30,r29
	ctx.r23.u64 = ctx.r30.u64 + ctx.r29.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r22,r28,r11
	ctx.r22.u64 = ctx.r28.u64 + ctx.r11.u64;
loc_826FFB7C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffb7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFB7C;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// lwz r30,276(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// add r20,r27,r10
	ctx.r20.u64 = ctx.r27.u64 + ctx.r10.u64;
	// add r21,r26,r30
	ctx.r21.u64 = ctx.r26.u64 + ctx.r30.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFBA8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffba8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFBA8;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// add r26,r24,r30
	ctx.r26.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFBD0;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r23,r29
	ctx.r28.u64 = ctx.r23.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r22,r11
	ctx.r27.u64 = ctx.r22.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFBEC;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r21,-1
	ctx.r10.s64 = ctx.r21.s64 + -1;
	// addi r9,r20,-1
	ctx.r9.s64 = ctx.r20.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFC08:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffc08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFC08;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r21,r30
	ctx.r24.u64 = ctx.r21.u64 + ctx.r30.u64;
	// add r23,r20,r10
	ctx.r23.u64 = ctx.r20.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFC30:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffc30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFC30;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFC58;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFC74;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFC90:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffc90
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFC90;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r23,r23,r10
	ctx.r23.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFCB8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffcb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFCB8;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFCE0;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFCFC;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFD18:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffd18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFD18;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r23,r23,r10
	ctx.r23.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFD40:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffd40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFD40;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFD68;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFD84;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFDA0:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffda0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFDA0;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r23,r23,r10
	ctx.r23.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFDC8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffdc8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFDC8;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFDF0;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFE0C;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFE28:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffe28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFE28;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r23,r23,r10
	ctx.r23.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFE50:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffe50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFE50;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFE78;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFE94;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
loc_826FFEB0:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffeb0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFEB0;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,22388(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// add r24,r24,r30
	ctx.r24.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r23,r23,r10
	ctx.r23.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// addi r9,r25,-1
	ctx.r9.s64 = ctx.r25.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFED8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826ffed8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFED8;
	// lwz r11,22392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r30,r26,r30
	ctx.r30.u64 = ctx.r26.u64 + ctx.r30.u64;
	// add r26,r11,r25
	ctx.r26.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFF00;
	sub_8273A030(ctx, base);
	// lwz r11,22384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// add r4,r28,r29
	ctx.r4.u64 = ctx.r28.u64 + ctx.r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r3,r27,r11
	ctx.r3.u64 = ctx.r27.u64 + ctx.r11.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FFF14;
	sub_8273A030(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r9,r23,-1
	ctx.r9.s64 = ctx.r23.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826FFF24:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826fff24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFF24;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826FFF40:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826fff40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FFF40;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82720850) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mr r12,r9
	ctx.r12.u64 = ctx.r9.u64;
	// lvx v8,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx v28,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	ctx.r11.s64 = 48;
	// vupkhsh v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16))));
	// rldicr r2,r7,32,31
	ctx.r2.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000;
	// vupklsh v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// li r6,80
	ctx.r6.s64 = 80;
	// vspltish v29,-1
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_set1_epi16(short(0xFFFF)));
	// lvx v9,r9,r5
	ea = (ctx.r9.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r2,r8,r2
	ctx.r2.u64 = ctx.r8.u64 + ctx.r2.u64;
	// lvx v18,r10,r5
	ea = (ctx.r10.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,96
	ctx.r8.s64 = 96;
	// lvx v19,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r12
	ctx.r5.u64 = ctx.r12.u64;
	// li r12,64
	ctx.r12.s64 = 64;
	// lvx v1,r9,r3
	ea = (ctx.r9.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx v2,r10,r3
	ea = (ctx.r10.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsh v11,v1
	simde_mm_store_si128((simde__m128i*)ctx.v11.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16))));
	// lvx v3,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsh v12,v2
	simde_mm_store_si128((simde__m128i*)ctx.v12.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// lvx v5,r6,r3
	ea = (ctx.r6.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsh v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// lvx v6,r8,r3
	ea = (ctx.r8.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsh v15,v5
	simde_mm_store_si128((simde__m128i*)ctx.v15.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16))));
	// lvx v4,r12,r3
	ea = (ctx.r12.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsh v16,v6
	simde_mm_store_si128((simde__m128i*)ctx.v16.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16))));
	// vupkhsh v14,v4
	simde_mm_store_si128((simde__m128i*)ctx.v14.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16))));
	// li r7,112
	ctx.r7.s64 = 112;
	// vcfsx v10,v10,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vupklsh v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v1.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vcfsx v11,v11,0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vupklsh v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcfsx v12,v12,0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// vupklsh v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcfsx v13,v13,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vupklsh v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcfsx v14,v14,0
	simde_mm_store_ps(ctx.v14.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v14.u32)));
	// lvx v7,r7,r3
	ea = (ctx.r7.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcfsx v15,v15,0
	simde_mm_store_ps(ctx.v15.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	// vupkhsh v17,v7
	simde_mm_store_si128((simde__m128i*)ctx.v17.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16))));
	// vcfsx v16,v16,0
	simde_mm_store_ps(ctx.v16.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v16.u32)));
	// vupklsh v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vupklsh v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vcfsx v0,v0,0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vupklsh v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vcfsx v1,v1,0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// vcfsx v17,v17,0
	simde_mm_store_ps(ctx.v17.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	// vspltish v30,0
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_set1_epi16(short(0x0)));
	// vcfsx v2,v2,0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vcfsx v3,v3,0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// vcfsx v4,v4,0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v4.u32)));
	// vcfsx v5,v5,0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v5.u32)));
	// vcfsx v6,v6,0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v6.u32)));
	// vcfsx v7,v7,0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v7.u32)));
	// vmulfp128 v10,v10,v9
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vmulfp128 v11,v11,v8
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v12,v12,v8
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v13,v13,v8
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v14,v14,v8
	simde_mm_store_ps(ctx.v14.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v14.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v15,v15,v8
	simde_mm_store_ps(ctx.v15.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v15.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v16,v16,v8
	simde_mm_store_ps(ctx.v16.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v16.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v17,v17,v8
	simde_mm_store_ps(ctx.v17.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v17.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v0,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v1,v1,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v2,v2,v8
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v3,v3,v8
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v4,v4,v8
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v5,v5,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v6,v6,v8
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v7,v7,v8
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vctsxs v10,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vctsxs v11,v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v11.f32)));
	// vctsxs v12,v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v12.f32)));
	// vctsxs v13,v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v13.f32)));
	// vctsxs v14,v14,0
	simde_mm_store_si128((simde__m128i*)ctx.v14.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v14.f32)));
	// vctsxs v15,v15,0
	simde_mm_store_si128((simde__m128i*)ctx.v15.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v15.f32)));
	// vctsxs v16,v16,0
	simde_mm_store_si128((simde__m128i*)ctx.v16.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v16.f32)));
	// vctsxs v3,v3,0
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v3.f32)));
	// vspltish v31,4
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_set1_epi16(short(0x4)));
	// vctsxs v4,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v4.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vctsxs v0,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v0.f32)));
	// vctsxs v1,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v1.f32)));
	// vctsxs v17,v17,0
	simde_mm_store_si128((simde__m128i*)ctx.v17.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v17.f32)));
	// vctsxs v7,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vctsxs v2,v2,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vctsxs v5,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vctsxs v6,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v6.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vpkswss v23,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s32), simde_mm_load_si128((simde__m128i*)ctx.v13.s32)));
	// vpkswss v24,v14,v4
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v4.s32), simde_mm_load_si128((simde__m128i*)ctx.v14.s32)));
	// vpkswss v20,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.s32), simde_mm_load_si128((simde__m128i*)ctx.v10.s32)));
	// vpkswss v21,v11,v1
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.s32), simde_mm_load_si128((simde__m128i*)ctx.v11.s32)));
	// vsrah v13,v23,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss v27,v17,v7
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.s32), simde_mm_load_si128((simde__m128i*)ctx.v17.s32)));
	// vsrah v14,v24,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss v22,v12,v2
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s32), simde_mm_load_si128((simde__m128i*)ctx.v12.s32)));
	// vsrah v10,v20,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss v25,v15,v5
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.s32), simde_mm_load_si128((simde__m128i*)ctx.v15.s32)));
	// vsrah v11,v21,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss v26,v16,v6
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.s32), simde_mm_load_si128((simde__m128i*)ctx.v16.s32)));
	// vcmpequh v4,v30,v24
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vsrah v17,v27,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v12,v22,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v15,v25,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v16,v26,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vspltish v29,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_set1_epi16(short(0x1)));
	// vcmpequh v3,v30,v23
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v23.u16)));
	// vsel v13,v18,v19,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vsel v14,v18,v19,v14
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vsel v10,v18,v19,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vcmpequh v0,v30,v20
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v20.u16)));
	// vsel v11,v18,v19,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vcmpequh v1,v30,v21
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v21.u16)));
	// vcmpequh v7,v30,v27
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v27.u16)));
	// vsel v17,v18,v19,v17
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vcmpequh v5,v30,v25
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vcmpequh v6,v30,v26
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vcmpequh v2,v30,v22
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v22.u16)));
	// vsel v12,v18,v19,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vsel v15,v18,v19,v15
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vsel v16,v18,v19,v16
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8))));
	// vsel v13,v13,v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v14,v14,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v10,v10,v30,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v11,v11,v30,v1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v17,v17,v30,v7
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v17.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v12,v12,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v15,v15,v30,v5
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vsel v16,v16,v30,v6
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v16.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8))));
	// vspltish v30,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_set1_epi16(short(0x2)));
	// vaddshs v2,v24,v14
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vaddshs v8,v23,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// vand v10,v10,v28
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vaddshs v5,v21,v11
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v6,v27,v17
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vslh v24,v2,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v1,v20,v10
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v4,v22,v12
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vslh v2,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v12,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v7,v25,v15
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v15.s16)));
	// vslh v25,v1,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v2,v2,v24
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vaddshs v3,v26,v16
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vslh v1,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v24,v12,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v26,v5,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v11,v5,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v1,v1,v25
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vsubuhm v9,v24,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vslh v10,v6,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v11,v26,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vslh v25,v6,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vor128 v14,v69,v69
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_load_si128((simde__m128i*)ctx.v69.u8));
	// vsubuhm v10,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vsubuhm v11,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vor128 v15,v72,v72
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_load_si128((simde__m128i*)ctx.v72.u8));
	// vaddshs v1,v1,v31
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vslh v27,v5,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v24,v6,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v9,v12,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v6,v6,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v5,v5,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v12,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vslh v26,v7,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v6,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vaddshs v5,v27,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vslh v27,v7,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v10,v10,v25
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vsubuhm v6,v6,v24
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vaddshs v5,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vslh v9,v12,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v24,v8,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v26,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vslh v25,v8,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v27,v8,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v24,v9,v24
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vaddshs v26,v9,v26
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vsubuhm v24,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vsubuhm v10,v10,v26
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vslh v26,v12,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v25,v7,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v11,v11,v24
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vslh v24,v7,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v9,v26,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vslh v26,v8,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v24,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vslh v25,v4,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v26,v9,v26
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vsubuhm v24,v9,v24
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vaddshs v9,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubuhm v26,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v27.u16)));
	// vsubuhm v1,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vor v2,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// vaddshs v5,v5,v24
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vaddshs v6,v6,v26
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vslh v24,v4,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v27,v2,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v26,v2,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v4,v4,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v24,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vslh v3,v3,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v26,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vsubuhm v3,v24,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vaddshs v4,v26,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v8,v9,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsubuhm v9,v9,v4
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vaddshs v4,v1,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubuhm v1,v1,v3
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vaddshs v24,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v27,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v25,v4,v10
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v26,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubuhm v29,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vsubuhm v28,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vsubuhm v30,v4,v10
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vsubuhm v31,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vsrah v24,v24,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v25,v25,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v26,v26,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v27,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v28,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v29,v29,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vmrglh v20,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vsrah v30,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vmrghh v16,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v16.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vsrah v31,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vmrghh v17,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vmrglh v21,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vmrghh v18,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v18.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vmrglh v22,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vmrghh v19,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmrglh v23,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmrghw v24,v16,v17
	simde_mm_store_si128((simde__m128i*)ctx.v24.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v17.u32), simde_mm_load_si128((simde__m128i*)ctx.v16.u32)));
	// vmrglw v25,v16,v17
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v17.u32), simde_mm_load_si128((simde__m128i*)ctx.v16.u32)));
	// vmrghw v28,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	// vmrglw v29,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	// vmrghw v26,v20,v21
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vmrglw v27,v20,v21
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vmrglw v31,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vperm v5,v24,v28,v15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// vmrghw v30,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vperm v8,v25,v29,v15
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// vperm v6,v27,v31,v15
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// vperm v3,v27,v31,v14
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)));
	// vspltish v27,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_set1_epi16(short(0x3)));
	// vperm v4,v25,v29,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)));
	// vaddshs v13,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vspltish v25,1
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_set1_epi16(short(0x1)));
	// vperm v7,v26,v30,v15
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// vperm v2,v26,v30,v14
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)));
	// vslh v10,v6,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vperm v1,v24,v28,v14
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)));
	// vspltish v26,2
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_set1_epi16(short(0x2)));
	// vslh v9,v13,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vspltish v17,8
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_set1_epi16(short(0x8)));
	// vslh v20,v6,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v19,v2,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vspltish v21,6
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_set1_epi16(short(0x6)));
	// vslh v18,v1,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v2,v2,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v1,v1,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v9,v9,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vslh v29,v17,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v2,v2,v19
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vaddshs v1,v1,v18
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vsubuhm v11,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vslh v18,v5,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v19,v5,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v10,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vslh v17,v6,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v5,v5,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v6,v6,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v9,v13,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v10,v10,v17
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vaddshs v5,v5,v19
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vsubuhm v11,v11,v18
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// vaddshs v12,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vslh v18,v7,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v17,v7,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v6,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vaddshs v5,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vslh v9,v12,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v17,v17,v18
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vslh v19,v8,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v6,v6,v20
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v20.u16)));
	// vslh v20,v8,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v17,v9,v17
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vsubuhm v19,v9,v19
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v19.u16)));
	// vslh v9,v12,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v1,v1,v29
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubuhm v10,v10,v17
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vsubuhm v19,v19,v20
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.u16), simde_mm_load_si128((simde__m128i*)ctx.v20.u16)));
	// vslh v17,v7,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubuhm v9,v9,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vslh v20,v8,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v11,v11,v19
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vaddshs v17,v17,v7
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vslh v19,v8,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v7,v3,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsrah v23,v12,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsubuhm v17,v9,v17
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vsubuhm v19,v9,v19
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v19.u16)));
	// vaddshs v9,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubuhm v1,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vaddshs v2,v3,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v5,v5,v17
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vaddshs v7,v7,v3
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubuhm v19,v19,v20
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.u16), simde_mm_load_si128((simde__m128i*)ctx.v20.u16)));
	// vslh v2,v2,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v17,v4,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v18,v4,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v6,v6,v19
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vsubuhm v7,v2,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vsubuhm v2,v2,v17
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vsrah v22,v13,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v5,v5,v23
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vaddshs v8,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v6,v6,v23
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vsubuhm v2,v2,v18
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// vsubuhm v2,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// rldicl r3,r2,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r2.u64, 32) & 0xFFFFFFFF;
	// vsubuhm v9,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// clrldi r2,r2,32
	ctx.r2.u64 = ctx.r2.u64 & 0xFFFFFFFF;
	// vadduhm v10,v10,v22
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v22.u16)));
	// vaddshs v11,v11,v22
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// vsubuhm v7,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vaddshs v1,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v24,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v27,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v15,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v26,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubuhm v28,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vsrah v24,v24,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsubuhm v29,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vsrah v15,v15,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsubuhm v30,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vsrah v26,v26,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx v24,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubuhm v31,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_sub_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vsrah v27,v27,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx v15,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v28,v28,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v29,v29,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx v26,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v30,v30,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v31,v31,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx v27,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v28,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v29,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v30,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v31,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lvx v14,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v24,v24,v14
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vaddshs v15,v15,v14
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vpkshus v24,v24,v24
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vaddshs v26,v26,v14
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// rldicr r5,r2,1,62
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r2.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// vaddshs v27,v27,v14
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// rldicr r7,r2,2,61
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r2.u64, 2) & 0xFFFFFFFFFFFFFFFC;
	// vaddshs v28,v28,v14
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// add r6,r5,r2
	ctx.r6.u64 = ctx.r5.u64 + ctx.r2.u64;
	// vpkshus v15,v15,v15
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v15.s16)));
	// vaddshs v29,v29,v14
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vpkshus v26,v26,v26
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vaddshs v30,v30,v14
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vpkshus v27,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vaddshs v31,v31,v14
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// stvewx v24,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v28,v28,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// stvewx v24,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v29,v29,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// add r8,r7,r2
	ctx.r8.u64 = ctx.r7.u64 + ctx.r2.u64;
	// vpkshus v30,v30,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// add r9,r7,r5
	ctx.r9.u64 = ctx.r7.u64 + ctx.r5.u64;
	// vpkshus v31,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// stvewx v15,r2,r3
	ea = (ctx.r2.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v15.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stvewx v15,r2,r4
	ea = (ctx.r2.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v15.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v26,r5,r3
	ea = (ctx.r5.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v26,r5,r4
	ea = (ctx.r5.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v27,r6,r3
	ea = (ctx.r6.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v27,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v28,r7,r3
	ea = (ctx.r7.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v28,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r8,r3
	ea = (ctx.r8.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r9,r3
	ea = (ctx.r9.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r10,r3
	ea = (ctx.r10.u32 + ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8277D4B0) {
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
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277d50c
	if (!ctx.cr0.eq) goto loc_8277D50C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// bl 0x82788ab8
	ctx.lr = 0x8277D4E4;
	sub_82788AB8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8277d50c
	if (ctx.cr0.lt) goto loc_8277D50C;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827364c8
	ctx.lr = 0x8277D4F4;
	sub_827364C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8277d50c
	if (ctx.cr0.eq) goto loc_8277D50C;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// beq cr6,0x8277d50c
	if (ctx.cr6.eq) goto loc_8277D50C;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827364a8
	ctx.lr = 0x8277D50C;
	sub_827364A8(ctx, base);
loc_8277D50C:
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// rlwinm. r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8277d554
	if (!ctx.cr0.eq) goto loc_8277D554;
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8277cf80
	ctx.lr = 0x8277D530;
	sub_8277CF80(ctx, base);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8277d554
	if (!ctx.cr6.eq) goto loc_8277D554;
	// lwz r10,100(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// rlwimi r10,r9,30,1,2
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x60000000) | (ctx.r10.u64 & 0xFFFFFFFF9FFFFFFF);
	// stw r10,100(r30)
	REX_STORE_U32(ctx.r30.u32 + 100, ctx.r10.u32);
loc_8277D554:
	// lbz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 288);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277d584
	if (!ctx.cr0.eq) goto loc_8277D584;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8277b568
	ctx.lr = 0x8277D56C;
	sub_8277B568(ctx, base);
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r5,r5,4114
	ctx.r5.u64 = ctx.r5.u64 | 4114;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8277ee40
	ctx.lr = 0x8277D584;
	sub_8277EE40(ctx, base);
loc_8277D584:
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8277d5cc
	if (ctx.cr0.eq) goto loc_8277D5CC;
	// bl 0x82788a80
	ctx.lr = 0x8277D594;
	sub_82788A80(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_8277D59C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277d59c
	if (!ctx.cr0.eq) goto loc_8277D59C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277d5cc
	if (!ctx.cr6.eq) goto loc_8277D5CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784b48
	ctx.lr = 0x8277D5CC;
	sub_82784B48(ctx, base);
loc_8277D5CC:
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

DEFINE_REX_FUNC(sub_827850E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827850E8;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,4(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r11,288(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827852d0
	if (!ctx.cr0.eq) goto loc_827852D0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82785120;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
loc_82785128:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82785128
	if (!ctx.cr0.eq) goto loc_82785128;
	// rlwinm. r24,r9,0,23,23
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq 0x82785168
	if (ctx.cr0.eq) goto loc_82785168;
loc_8278514C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8278514c
	if (!ctx.cr0.eq) goto loc_8278514C;
loc_82785168:
	// rlwinm. r25,r9,0,22,22
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x8278518c
	if (ctx.cr0.eq) goto loc_8278518C;
loc_82785170:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82785170
	if (!ctx.cr0.eq) goto loc_82785170;
loc_8278518C:
	// rlwinm. r27,r9,0,21,21
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x827851b0
	if (ctx.cr0.eq) goto loc_827851B0;
loc_82785194:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82785194
	if (!ctx.cr0.eq) goto loc_82785194;
loc_827851B0:
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r3,72(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r6,12(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82788a00
	ctx.lr = 0x827851CC;
	sub_82788A00(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x827852d8
	if (!ctx.cr0.lt) goto loc_827852D8;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82785214
	if (ctx.cr6.eq) goto loc_82785214;
loc_827851DC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827851dc
	if (!ctx.cr0.eq) goto loc_827851DC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82785214
	if (!ctx.cr6.eq) goto loc_82785214;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82785214;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82785214:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82785254
	if (ctx.cr6.eq) goto loc_82785254;
loc_8278521C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8278521c
	if (!ctx.cr0.eq) goto loc_8278521C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82785254
	if (!ctx.cr6.eq) goto loc_82785254;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82785254;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82785254:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82785294
	if (ctx.cr6.eq) goto loc_82785294;
loc_8278525C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8278525c
	if (!ctx.cr0.eq) goto loc_8278525C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82785294
	if (!ctx.cr6.eq) goto loc_82785294;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82785294;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82785294:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82785294
	if (!ctx.cr0.eq) goto loc_82785294;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827852d8
	if (!ctx.cr6.eq) goto loc_827852D8;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827852CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827852d8
	goto loc_827852D8;
loc_827852D0:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4113
	ctx.r31.u64 = ctx.r31.u64 | 4113;
loc_827852D8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82795700) {
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
	// rlwinm r11,r4,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82795724
	if (!ctx.cr6.eq) goto loc_82795724;
loc_8279571C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827957a0
	goto loc_827957A0;
loc_82795724:
	// rlwinm r11,r4,8,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0x7F;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bgt cr6,0x8279571c
	if (ctx.cr6.gt) goto loc_8279571C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// add r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 + ctx.r5.u64;
	// ori r8,r8,65534
	ctx.r8.u64 = ctx.r8.u64 | 65534;
	// clrlwi r10,r4,8
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFFFF;
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// lhz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8279571c
	if (!ctx.cr6.lt) goto loc_8279571C;
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82795778
	if (ctx.cr6.eq) goto loc_82795778;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8279576C:
	// lhzu r11,-2(r9)
	ea = -2 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bdnz 0x8279576c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8279576C;
loc_82795778:
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// or r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 | ctx.r11.u64;
	// bl 0x827956b0
	ctx.lr = 0x82795788;
	sub_827956B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8279571c
	if (ctx.cr0.eq) goto loc_8279571C;
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_827957A0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82799AB0) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r11,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r11.u16);
	// sth r11,6(r3)
	REX_STORE_U16(ctx.r3.u32 + 6, ctx.r11.u16);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x8273a590
	sub_8273A590(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279A3A8) {
	REX_FUNC_PROLOGUE();
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279A460) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lbz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8279a4a8
	if (ctx.cr0.eq) goto loc_8279A4A8;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r8,r3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8279a494
	if (!ctx.cr6.eq) goto loc_8279A494;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8279A494:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8279a4bc
	goto loc_8279A4BC;
loc_8279A4A8:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bne cr6,0x8279a4bc
	if (!ctx.cr6.eq) goto loc_8279A4BC;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8279A4BC:
	// stb r9,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r9.u8);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279D210) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8279D218;
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
	ctx.lr = 0x8279D238;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279ca18
	ctx.lr = 0x8279D244;
	sub_8279CA18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8279d258
	if (!ctx.cr0.eq) goto loc_8279D258;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x8279d268
	goto loc_8279D268;
loc_8279D258:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827a1380
	ctx.lr = 0x8279D264;
	sub_827A1380(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8279D268:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x8279D270;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279F7F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8279F7F8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// bl 0x8279ee58
	ctx.lr = 0x8279F804;
	sub_8279EE58(ctx, base);
	// lwz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8279f818
	if (!ctx.cr6.eq) goto loc_8279F818;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8279fa40
	goto loc_8279FA40;
loc_8279F818:
	// lwz r31,88(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 88);
	// addi r29,r26,88
	ctx.r29.s64 = ctx.r26.s64 + 88;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8279f8cc
	goto loc_8279F8CC;
loc_8279F828:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x8279f8d4
	if (ctx.cr6.eq) goto loc_8279F8D4;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279f860
	if (ctx.cr6.eq) goto loc_8279F860;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8279f854
	if (!ctx.cr6.eq) goto loc_8279F854;
	// stw r25,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r25.u32);
loc_8279F854:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
loc_8279F860:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8279f884
	if (!ctx.cr6.eq) goto loc_8279F884;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r25.u32);
loc_8279F884:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r26,80
	ctx.r30.s64 = ctx.r26.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// bl 0x82856164
	ctx.lr = 0x8279F898;
	__imp__KfAcquireSpinLock(ctx, base);
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// lwz r10,68(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 68);
	// addi r11,r26,64
	ctx.r11.s64 = ctx.r26.s64 + 64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8279f8b8
	if (ctx.cr6.eq) goto loc_8279F8B8;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// b 0x8279f8bc
	goto loc_8279F8BC;
loc_8279F8B8:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_8279F8BC:
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82856184
	ctx.lr = 0x8279F8C8;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_8279F8CC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8279f828
	if (!ctx.cr6.eq) goto loc_8279F828;
loc_8279F8D4:
	// lwz r31,72(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 72);
	// addi r27,r26,72
	ctx.r27.s64 = ctx.r26.s64 + 72;
	// b 0x8279f9d0
	goto loc_8279F9D0;
loc_8279F8E0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf. r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8279f9f4
	if (!ctx.cr0.eq) goto loc_8279F9F4;
	// addi r30,r26,80
	ctx.r30.s64 = ctx.r26.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82856164
	ctx.lr = 0x8279F900;
	__imp__KfAcquireSpinLock(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827a1f30
	ctx.lr = 0x8279F90C;
	sub_827A1F30(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8279f924
	if (!ctx.cr0.eq) goto loc_8279F924;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827a1f30
	ctx.lr = 0x8279F91C;
	sub_827A1F30(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// ble cr6,0x8279f9dc
	if (!ctx.cr6.gt) goto loc_8279F9DC;
loc_8279F924:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279f94c
	if (ctx.cr6.eq) goto loc_8279F94C;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8279f940
	if (!ctx.cr6.eq) goto loc_8279F940;
	// stw r25,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r25.u32);
loc_8279F940:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
loc_8279F94C:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82856184
	ctx.lr = 0x8279F958;
	__imp__KfReleaseSpinLock(ctx, base);
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279f970
	if (ctx.cr6.eq) goto loc_8279F970;
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// b 0x8279f974
	goto loc_8279F974;
loc_8279F970:
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
loc_8279F974:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addi r7,r26,96
	ctx.r7.s64 = ctx.r26.s64 + 96;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r6,r11,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x827a3008
	ctx.lr = 0x8279F998;
	sub_827A3008(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,12(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// bl 0x82856384
	ctx.lr = 0x8279F9C4;
	__imp__XamVoiceSubmitPacket(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8279f9ec
	if (ctx.cr0.lt) goto loc_8279F9EC;
	// lwz r31,0(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
loc_8279F9D0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8279f8e0
	if (!ctx.cr6.eq) goto loc_8279F8E0;
	// b 0x8279f9f4
	goto loc_8279F9F4;
loc_8279F9DC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82856184
	ctx.lr = 0x8279F9E8;
	__imp__KfReleaseSpinLock(ctx, base);
	// b 0x8279f9f4
	goto loc_8279F9F4;
loc_8279F9EC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
loc_8279F9F4:
	// lwz r3,8(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// bl 0x827a4858
	ctx.lr = 0x8279F9FC;
	sub_827A4858(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8279fa3c
	if (ctx.cr0.lt) goto loc_8279FA3C;
	// lwz r11,44(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8279fa3c
	if (!ctx.cr6.gt) goto loc_8279FA3C;
	// addi r30,r26,12
	ctx.r30.s64 = ctx.r26.s64 + 12;
loc_8279FA18:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8279FA2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,44(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8279fa18
	if (ctx.cr6.lt) goto loc_8279FA18;
loc_8279FA3C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8279FA40:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AE2C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE8B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9768(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0510) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f13,15656(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15656);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,3440(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 3440);
	// fsqrts f0,f0
	ctx.f0.f64 = double(float(sqrt(ctx.f0.f64)));
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0FA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B27B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3238) {
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
	// lfs f0,23496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7696);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7576(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4418) {
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
	// lfs f0,23720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7168);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7052(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5590) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6448) {
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
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6104(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6FB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7DC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9B28) {
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
	// lfs f0,24760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAAE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3580(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC8F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-3136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3136);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-3132(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -3132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,25624
	ctx.r9.s64 = ctx.r11.s64 + 25624;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,25848
	ctx.r9.s64 = ctx.r11.s64 + 25848;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF4F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,26096(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26096);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-1840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C03E0) {
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
	// lfs f0,26344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1384(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C15B0) {
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
	// lfs f0,26600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-860(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2B50) {
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
	// lfs f0,26920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3C78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,268(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4A88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,700(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5AF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,27736
	ctx.r9.s64 = ctx.r11.s64 + 27736;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,27736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6BD8) {
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
	// lfs f0,28120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1624(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1624);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1704(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7D10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2240(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8D98) {
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
	// lfs f0,28648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2620(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2620);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2720(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2720, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA0F8) {
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
	// lfs f0,28840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB478) {
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
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3756(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3756);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3876(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC6E8) {
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
	// lfs f0,29224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4312);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD898) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4932(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEB48) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5408(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5408);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5476(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFDD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5968(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5968);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6020(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0E98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2B00) {
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
	// lfs f0,30248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3DB0) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7808(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7808);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5020) {
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
	// lfs f0,30632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8420(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D62C8) {
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
	// lfs f0,30824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8916(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8916);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,9504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31228);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA2C0) {
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
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10828(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB518) {
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
	// lfs f0,31688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11316(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11316);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC7C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,11744(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11744);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD7B8) {
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
	// lfs f0,32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12396(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE9F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF9C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0A20) {
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
	// lfs f0,32504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13752(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13752);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13864(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2C50) {
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
	// lfs f0,14864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14864);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32420(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32420);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,14888(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 14888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5598) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16044);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-29308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-25900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9380) {
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
	// lfs f0,-24584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17696);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17816(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB648) {
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
	// lfs f0,-22536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18776(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC8E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19284);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDA18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEAE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF960) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21056(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1820) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F27D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21908);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F38A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-17176
	ctx.r11.s64 = ctx.r11.s64 + -17176;
	// lfs f0,22360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 22360);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F45D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22940(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5418) {
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
	// lfs f0,-16024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23228(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23228);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23340(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F66A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23908);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7510) {
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
	// lfs f0,-14040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24320(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8C30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-11944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24924(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9AB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,25332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25332);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,25336(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 25336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA698) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25628(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25628);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25676(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC7A8) {
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
	// lfs f0,-9432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26552(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26552);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDA30) {
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
	// lfs f0,-9240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27104(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27104);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27176(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FED20) {
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
	// lfs f0,-9048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27656);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27728(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800078) {
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
	// lfs f0,-8856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801368) {
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
	// lfs f0,-8664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28844(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,29392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29396(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803EC0) {
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
	// lfs f0,-8216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30112(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805250) {
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
	// lfs f0,-8024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30608(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30608);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-7832
	ctx.r9.s64 = ctx.r11.s64 + -7832;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31268(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807A70) {
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
	// lfs f0,-7640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31848(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809C08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32708(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280AAD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-32280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32276(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -32276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C3C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810230) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-29284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29284);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-29280(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -29280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812BD0) {
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
	// lfs f0,-5592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28584);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28476(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-5136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5136);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-27876(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828159C0) {
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
	// lfs f0,-4680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816CB8) {
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
	// lfs f0,-4384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26496(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3668);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-3516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3516);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24960(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24676(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BAE8) {
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
	// lfs f0,-3096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24260(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24260);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24152(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CD88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DB50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281EC90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-2280
	ctx.r9.s64 = ctx.r11.s64 + -2280;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-2280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FEA0) {
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
	// lfs f0,-2056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22204(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22204);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22136(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828222D8) {
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
	// lfs f12,-21176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21076(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828236A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828247E8) {
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
	// lfs f0,-1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20052);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825A50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-704(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2576);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-19412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826C68) {
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
	// lfs f0,-520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18996(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18996);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827FA8) {
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
	// lfs f0,-312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18420(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18420);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18320(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-17836(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17836);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-17300(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -17300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AC50) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17008(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282BFC8) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16528(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16528);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16424(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D4D0) {
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
	// lfs f0,712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15932(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15932);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15816(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E8F0) {
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
	// lfs f0,952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15220(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FD28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1228);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830AB8) {
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
	// lfs f0,1416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14216(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831EE8) {
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
	// lfs f0,1704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13616(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833380) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-13004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-13000(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -13000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833CF0) {
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
	// lfs f0,2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12820);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835180) {
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
	// lfs f0,2376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12224(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12224);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12108(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,2600
	ctx.r9.s64 = ctx.r11.s64 + 2600;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,2600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-11016(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -11016);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828388C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828396F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A7E8) {
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
	// lfs f13,-9680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9680);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9572(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B750) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C600) {
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
	// lfs f0,3776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D960) {
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
	// lfs f0,4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283ED30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-7600(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7600);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FE18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840F28) {
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
	// lfs f0,4688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6548(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828421B0) {
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
	// lfs f0,4912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6108(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6108);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843510) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,5144
	ctx.r9.s64 = ctx.r11.s64 + 5144;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,5144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844880) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828456D8) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4424(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,6272
	ctx.r9.s64 = ctx.r11.s64 + 6272;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A0A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2356(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2356);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284AFA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1812(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1812, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284BF00) {
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
	// lfs f0,6864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1432(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1432);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D2C8) {
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
	// lfs f0,7072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-872(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -872);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-788(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E658) {
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
	// lfs f0,7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-304(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -304);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-192(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FCC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,876(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851B60) {
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
	// lfs f0,8280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1280);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1392(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,1928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82871498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// vspltisb v31,0
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_set1_epi8(char(0x0)));
	// li r8,16
	ctx.r8.s64 = 16;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x82871550
	if (!ctx.cr6.eq) goto loc_82871550;
	// rlwinm r6,r4,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r12,r4,2,0,29
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,8
	ctx.r7.s64 = 8;
loc_828714B4:
	// add r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 + ctx.r6.u64;
	// add r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r11,r10,r4
	ctx.r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvlx v1,0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx v2,r3,r8
	temp.u32 = ctx.r3.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx v9,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx v10,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx v18,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx v19,r10,r8
	temp.u32 = ctx.r10.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx v23,0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx v24,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor v3,v1,v2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vor v11,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vor v20,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8)));
	// vor v25,v23,v24
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v24.u8)));
	// add r3,r3,r12
	ctx.r3.u64 = ctx.r3.u64 + ctx.r12.u64;
	// vmrghb v4,v31,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v5,v31,v3
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v12,v31,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v13,v31,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v21,v31,v20
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v22,v31,v20
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v26,v31,v25
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v27,v31,v25
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// addi r9,r5,48
	ctx.r9.s64 = ctx.r5.s64 + 48;
	// addi r10,r5,96
	ctx.r10.s64 = ctx.r5.s64 + 96;
	// addi r11,r5,144
	ctx.r11.s64 = ctx.r5.s64 + 144;
	// stvx v4,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v5,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r5,192
	ctx.r5.s64 = ctx.r5.s64 + 192;
	// stvx v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v13,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v21,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v22,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v26,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v27,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r7,r7,-4
	ctx.xer.ca = ctx.r7.u32 > 3;
	ctx.r7.s64 = ctx.r7.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x828714b4
	if (!ctx.cr0.eq) goto loc_828714B4;
	// blr 
	return;
loc_82871550:
	// li r9,2
	ctx.r9.s64 = 2;
	// subf r7,r7,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r7.u64;
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,32
	ctx.r9.s64 = 32;
	// add r11,r4,r4
	ctx.r11.u64 = ctx.r4.u64 + ctx.r4.u64;
	// lvsl v28,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
loc_82871568:
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvx128 v1,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r12,r5,48
	ctx.r12.s64 = ctx.r5.s64 + 48;
	// lvx128 v21,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v23,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm v7,v1,v2,v28
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vperm v8,v2,v3,v28
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vperm v26,v21,v22,v28
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vperm v27,v22,v23,v28
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vmrghb v5,v31,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v6,v31,v7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v8,v31,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v24,v31,v26
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrglb v25,v31,v26
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vmrghb v27,v31,v27
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// addic. r7,r7,-2
	ctx.xer.ca = ctx.r7.u32 > 1;
	ctx.r7.s64 = ctx.r7.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stvx v5,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v6,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v8,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r5,96
	ctx.r5.s64 = ctx.r5.s64 + 96;
	// stvx v24,r0,r12
	ea = (ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v25,r12,r8
	ea = (ctx.r12.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v27,r12,r9
	ea = (ctx.r12.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82871568
	if (!ctx.cr0.eq) goto loc_82871568;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828935C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x828935C8;
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
	// bl 0x82890bd8
	ctx.lr = 0x828935DC;
	sub_82890BD8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-13816(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13816);
	// bl 0x82893f28
	ctx.lr = 0x828935F0;
	sub_82893F28(ctx, base);
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// addi r29,r30,1408
	ctx.r29.s64 = ctx.r30.s64 + 1408;
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
	// bl 0x82891228
	ctx.lr = 0x82893614;
	sub_82891228(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828936d4
	if (!ctx.cr6.eq) goto loc_828936D4;
	// lhz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
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
	// bl 0x82890d98
	ctx.lr = 0x8289363C;
	sub_82890D98(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828936d4
	if (!ctx.cr6.eq) goto loc_828936D4;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x828936b4
	if (ctx.cr6.eq) goto loc_828936B4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,268(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// bl 0x82894c00
	ctx.lr = 0x8289365C;
	sub_82894C00(ctx, base);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r9,3752(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r8,3748(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r9,220(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x82894da8
	ctx.lr = 0x82893688;
	sub_82894DA8(ctx, base);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r9,3752(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,3748(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r9,220(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x82894da8
	ctx.lr = 0x828936B4;
	sub_82894DA8(ctx, base);
loc_828936B4:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,15560(r31)
	REX_STORE_U32(ctx.r31.u32 + 15560, ctx.r11.u32);
	// stw r11,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r11.u32);
	// bl 0x82894270
	ctx.lr = 0x828936D0;
	sub_82894270(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_828936D4:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82895578) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// srawi r8,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 16;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r5,r31,16
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r31.s32 >> 16;
	// clrlwi r6,r6,16
	ctx.r6.u64 = ctx.r6.u32 & 0xFFFF;
	// add r31,r9,r8
	ctx.r31.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpwi cr6,r7,-59
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -59, ctx.xer);
	// bge cr6,0x828955b8
	if (!ctx.cr6.lt) goto loc_828955B8;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r10,r11,-56
	ctx.r10.s64 = ctx.r11.s64 + -56;
	// b 0x828955d0
	goto loc_828955D0;
loc_828955B8:
	// cmpw cr6,r7,r6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x828955d4
	if (!ctx.cr6.gt) goto loc_828955D4;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r11,-3
	ctx.r10.s64 = ctx.r11.s64 + -3;
loc_828955D0:
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_828955D4:
	// cmpwi cr6,r31,-59
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -59, ctx.xer);
	// bge cr6,0x82895610
	if (!ctx.cr6.lt) goto loc_82895610;
	// rlwinm r11,r31,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r11,r9,30
	ctx.r11.u64 = ctx.r9.u32 & 0x3;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// beq cr6,0x82895600
	if (ctx.cr6.eq) goto loc_82895600;
	// addi r10,r11,-60
	ctx.r10.s64 = ctx.r11.s64 + -60;
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82895600:
	// addi r10,r11,-56
	ctx.r10.s64 = ctx.r11.s64 + -56;
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82895610:
	// cmpw cr6,r31,r5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x8289563c
	if (!ctx.cr6.gt) goto loc_8289563C;
	// rlwinm r11,r31,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r11,r9,30
	ctx.r11.u64 = ctx.r9.u32 & 0x3;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x82895638
	if (!ctx.cr6.eq) goto loc_82895638;
	// addi r10,r11,-3
	ctx.r10.s64 = ctx.r11.s64 + -3;
loc_82895638:
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_8289563C:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

