#include "harmonyrecomp_funcs.107.h"

DEFINE_REX_FUNC(sub_8222AE58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lfs f0,12252(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12252);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x825c09a8
	ctx.lr = 0x8222AE90;
	sub_825C09A8(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8222AEA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fsubs f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r3,24,9,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0x7FFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmsubs f1,f13,f0,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f12.f64)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-24(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8222D7B8) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r11,2940
	ctx.r4.s64 = ctx.r11.s64 + 2940;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x822334a8
	ctx.lr = 0x8222D7E0;
	sub_822334A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,2728
	ctx.r11.s64 = ctx.r11.s64 + 2728;
	// sth r10,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r10.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82233740
	ctx.lr = 0x8222D7FC;
	sub_82233740(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// li r5,537
	ctx.r5.s64 = 537;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r9,2800
	ctx.r11.s64 = ctx.r9.s64 + 2800;
	// li r9,531
	ctx.r9.s64 = 531;
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r4,543
	ctx.r4.s64 = 543;
	// li r3,549
	ctx.r3.s64 = 549;
	// lfs f13,-8400(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8400);
	ctx.f13.f64 = double(temp.f32);
	// li r11,555
	ctx.r11.s64 = 555;
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// li r9,579
	ctx.r9.s64 = 579;
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// li r5,573
	ctx.r5.s64 = 573;
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r4,567
	ctx.r4.s64 = 567;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// li r11,591
	ctx.r11.s64 = 591;
	// li r3,585
	ctx.r3.s64 = 585;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// stw r3,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lwz r10,7044(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 7044);
	// li r8,561
	ctx.r8.s64 = 561;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// stw r8,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// lwzx r11,r7,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// blt cr6,0x8222d8cc
	if (ctx.cr6.lt) goto loc_8222D8CC;
	// beq cr6,0x8222d8c8
	if (ctx.cr6.eq) goto loc_8222D8C8;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x8222d904
	if (ctx.cr6.lt) goto loc_8222D904;
	// beq cr6,0x8222d8fc
	if (ctx.cr6.eq) goto loc_8222D8FC;
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// blt cr6,0x8222d8f4
	if (ctx.cr6.lt) goto loc_8222D8F4;
	// beq cr6,0x8222d8ec
	if (ctx.cr6.eq) goto loc_8222D8EC;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lwz r10,7040(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 7040);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8222d8cc
	if (ctx.cr6.eq) goto loc_8222D8CC;
loc_8222D8C8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8222D8CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r11,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r11.u16);
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
loc_8222D8EC:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// b 0x8222d8cc
	goto loc_8222D8CC;
loc_8222D8F4:
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// b 0x8222d8cc
	goto loc_8222D8CC;
loc_8222D8FC:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x8222d8cc
	goto loc_8222D8CC;
loc_8222D904:
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// b 0x8222d8cc
	goto loc_8222D8CC;
}

DEFINE_REX_FUNC(sub_822337D8) {
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
	// ld r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,60(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// beq cr6,0x82233830
	if (ctx.cr6.eq) goto loc_82233830;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r8,84(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// lbz r7,90(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 90);
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lhz r4,96(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 96);
	// bl 0x823d2648
	ctx.lr = 0x82233830;
	sub_823D2648(ctx, base);
loc_82233830:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82235780) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,14392
	ctx.r10.s64 = ctx.r10.s64 + 14392;
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f13,-1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f10,-2140(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2140);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f12,-12(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f10,-4(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lfs f11,-172(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -172);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r9,12(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// lfs f12,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f8,f0,f12
	ctx.f8.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fabs f8,f8
	ctx.f8.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// lfs f9,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f8,f11
	ctx.cr6.compare(ctx.f8.f64, ctx.f11.f64);
	// blt cr6,0x8223581c
	if (ctx.cr6.lt) goto loc_8223581C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8223581C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223582c
	if (ctx.cr0.eq) goto loc_8223582C;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82235854
	goto loc_82235854;
loc_8223582C:
	// fsubs f11,f9,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fdivs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82235848
	if (!ctx.cr6.lt) goto loc_82235848;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82235854
	goto loc_82235854;
loc_82235848:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x82235854
	if (!ctx.cr6.gt) goto loc_82235854;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_82235854:
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r1,-20
	ctx.r9.s64 = ctx.r1.s64 + -20;
	// addi r11,r3,20
	ctx.r11.s64 = ctx.r3.s64 + 20;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82235864:
	// lfs f12,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12);
	ctx.f12.f64 = double(temp.f32);
	// lfsu f13,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmadds f13,f13,f0,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfsu f13,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82235864
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82235864;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-8(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f11,-12(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,-8400(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8400);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f13.u64);
	// fctidz f13,f12
	ctx.f13.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f13.u64);
	// lbz r9,-17(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -17);
	// fctidz f13,f11
	ctx.f13.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f0.u64);
	// lbz r7,-17(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -17);
	// stfd f13,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lbz r11,-25(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + -25);
	// stb r11,-30(r1)
	REX_STORE_U8(ctx.r1.u32 + -30, ctx.r11.u8);
	// lbz r8,-9(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -9);
	// stb r7,-32(r1)
	REX_STORE_U8(ctx.r1.u32 + -32, ctx.r7.u8);
	// stb r9,-29(r1)
	REX_STORE_U8(ctx.r1.u32 + -29, ctx.r9.u8);
	// stb r8,-31(r1)
	REX_STORE_U8(ctx.r1.u32 + -31, ctx.r8.u8);
	// lwz r11,-32(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82242490) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82242498;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r27,r3,260
	ctx.r27.s64 = ctx.r3.s64 + 260;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224251c
	if (ctx.cr0.eq) goto loc_8224251C;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
loc_822424C4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8225bf20
	ctx.lr = 0x822424D0;
	sub_8225BF20(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822424f4
	if (ctx.cr6.eq) goto loc_822424F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822424F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822424F4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwx r26,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r26.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x822424c4
	if (ctx.cr6.lt) goto loc_822424C4;
loc_8224251C:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// addi r28,r31,244
	ctx.r28.s64 = ctx.r31.s64 + 244;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82242594
	if (ctx.cr0.eq) goto loc_82242594;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
loc_8224253C:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8225bf20
	ctx.lr = 0x82242548;
	sub_8225BF20(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224256c
	if (ctx.cr6.eq) goto loc_8224256C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8224256C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8224256C:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwx r26,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r26.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8224253c
	if (ctx.cr6.lt) goto loc_8224253C;
loc_82242594:
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r5,8(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x822425c4
	if (ctx.cr6.eq) goto loc_822425C4;
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
	// ble 0x822425c0
	if (!ctx.cr0.gt) goto loc_822425C0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x822425C0;
	sub_82755080(ctx, base);
loc_822425C0:
	// stw r31,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r31.u32);
loc_822425C4:
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r5,8(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x822425f4
	if (ctx.cr6.eq) goto loc_822425F4;
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
	// ble 0x822425f0
	if (!ctx.cr0.gt) goto loc_822425F0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x822425F0;
	sub_82755080(ctx, base);
loc_822425F0:
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
loc_822425F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822504D8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x822285a8
	ctx.lr = 0x822504F8;
	sub_822285A8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f31,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82250600
	if (ctx.cr6.eq) goto loc_82250600;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82250600
	if (!ctx.cr6.eq) goto loc_82250600;
	// lfs f12,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82250538
	if (!ctx.cr6.lt) goto loc_82250538;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// b 0x8225053c
	goto loc_8225053C;
loc_82250538:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8225053C:
	// lbz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 92);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82250578
	if (ctx.cr0.eq) goto loc_82250578;
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82250578
	if (!ctx.cr0.eq) goto loc_82250578;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f13,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82250578;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82250578:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x822505b4
	if (ctx.cr6.eq) goto loc_822505B4;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x82250590;
	sub_82232BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822505b4
	if (ctx.cr0.eq) goto loc_822505B4;
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82235518
	ctx.lr = 0x822505B0;
	sub_82235518(ctx, base);
	// b 0x822505b8
	goto loc_822505B8;
loc_822505B4:
	// li r30,0
	ctx.r30.s64 = 0;
loc_822505B8:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82250600
	if (!ctx.cr0.eq) goto loc_82250600;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822505E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82250600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82250600:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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

DEFINE_REX_FUNC(sub_8225C5C0) {
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
	// lhz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x823d1660
	ctx.lr = 0x8225C5D8;
	sub_823D1660(ctx, base);
	// lhz r3,41(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 41);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8225D170) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f1,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f1,32(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8225D988) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8225D990;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lbz r10,279(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 279);
	// lis r9,0
	ctx.r9.s64 = 0;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// lis r8,0
	ctx.r8.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r30,r9,62381
	ctx.r30.u64 = ctx.r9.u64 | 62381;
	// lfs f31,12252(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f31.f64 = double(temp.f32);
	// li r28,1
	ctx.r28.s64 = 1;
	// ori r29,r8,62384
	ctx.r29.u64 = ctx.r8.u64 | 62384;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8225da54
	if (ctx.cr0.eq) goto loc_8225DA54;
	// lbzx r10,r3,r30
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r30.u32);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8225da54
	if (!ctx.cr0.eq) goto loc_8225DA54;
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// bl 0x8243f6d0
	ctx.lr = 0x8225D9E4;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8225da50
	if (ctx.cr0.eq) goto loc_8225DA50;
	// bl 0x82441b00
	ctx.lr = 0x8225D9F0;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225da00
	if (!ctx.cr0.eq) goto loc_8225DA00;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8225da04
	goto loc_8225DA04;
loc_8225DA00:
	// bl 0x82441f48
	ctx.lr = 0x8225DA04;
	sub_82441F48(ctx, base);
loc_8225DA04:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8225dad4
	if (ctx.cr0.eq) goto loc_8225DAD4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,62408
	ctx.r11.u64 = ctx.r11.u64 | 62408;
	// addi r30,r30,-3132
	ctx.r30.s64 = ctx.r30.s64 + -3132;
	// stbx r28,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u8);
	// bl 0x82440f20
	ctx.lr = 0x8225DA24;
	sub_82440F20(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r3,10
	ctx.r3.s64 = 10;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f0,20084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20084);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,0,r30
	REX_STORE_U32(ctx.r30.u32, ctx.f0.u32);
	// bl 0x82441518
	ctx.lr = 0x8225DA4C;
	sub_82441518(ctx, base);
	// b 0x8225dad4
	goto loc_8225DAD4;
loc_8225DA50:
	// stfsx f31,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
loc_8225DA54:
	// lbzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r30.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225dad4
	if (ctx.cr0.eq) goto loc_8225DAD4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3156
	ctx.r11.s64 = ctx.r11.s64 + -3156;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8225dad4
	if (!ctx.cr0.eq) goto loc_8225DAD4;
	// lfsx f0,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x8225dad4
	if (!ctx.cr6.gt) goto loc_8225DAD4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// ori r10,r10,62392
	ctx.r10.u64 = ctx.r10.u64 | 62392;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwzx r9,r31,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8225dad4
	if (!ctx.cr6.eq) goto loc_8225DAD4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8225dad4
	if (ctx.cr6.eq) goto loc_8225DAD4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8225DAD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8225DAD4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822663C8) {
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
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// ld r9,88(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 88);
	// rlwinm r10,r4,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFF0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x82266484
	if (!ctx.cr6.eq) goto loc_82266484;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82266484
	if (ctx.cr6.eq) goto loc_82266484;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82448730
	ctx.lr = 0x82266418;
	sub_82448730(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ori r9,r9,62480
	ctx.r9.u64 = ctx.r9.u64 | 62480;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f13,12484(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfsx f0,r31,r9
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82266488
	if (!ctx.cr6.gt) goto loc_82266488;
loc_82266484:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82266488:
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

DEFINE_REX_FUNC(sub_82273C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82273C50;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r25,r3,1
	ctx.r25.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r25,r25,-3160
	ctx.r25.s64 = ctx.r25.s64 + -3160;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8227421c
	if (ctx.cr6.lt) goto loc_8227421C;
	// beq cr6,0x82273e20
	if (ctx.cr6.eq) goto loc_82273E20;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82273d30
	if (ctx.cr6.lt) goto loc_82273D30;
	// bne cr6,0x8227455c
	if (!ctx.cr6.eq) goto loc_8227455C;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r11,r11,-2852
	ctx.r11.s64 = ctx.r11.s64 + -2852;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82273C98:
	// stb r27,-56(r11)
	REX_STORE_U8(ctx.r11.u32 + -56, ctx.r27.u8);
	// stbu r27,56(r11)
	ea = 56 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r27.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x82273c98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82273C98;
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r31,r31,-3156
	ctx.r31.s64 = ctx.r31.s64 + -3156;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82273cfc
	if (!ctx.cr6.eq) goto loc_82273CFC;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c08c8
	ctx.lr = 0x82273CC8;
	sub_825C08C8(ctx, base);
	// li r11,10
	ctx.r11.s64 = 10;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,10
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(10));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82273ce8
	if (!ctx.cr6.lt) goto loc_82273CE8;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82273cf8
	goto loc_82273CF8;
loc_82273CE8:
	// li r10,6
	ctx.r10.s64 = 6;
	// subfc r11,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
loc_82273CF8:
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82273CFC:
	// lbz r9,466(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 466);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82273d20
	if (ctx.cr0.eq) goto loc_82273D20;
	// lwzx r9,r29,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// beq cr6,0x82273d28
	if (ctx.cr6.eq) goto loc_82273D28;
loc_82273D20:
	// stw r27,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r27.u32);
	// stwx r10,r29,r11
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, ctx.r10.u32);
loc_82273D28:
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// b 0x8227455c
	goto loc_8227455C;
loc_82273D30:
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// li r30,255
	ctx.r30.s64 = 255;
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// lfs f0,-17652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17652);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// addi r11,r11,-2864
	ctx.r11.s64 = ctx.r11.s64 + -2864;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
loc_82273D68:
	// lbz r9,55(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 55);
	// lbz r10,59(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 59);
	// std r9,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r9.u64);
	// lfd f12,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lhz r8,118(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 118);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lhz r7,118(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 118);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// and r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	// stb r10,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r10.u8);
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r9,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// stwu r10,56(r11)
	ea = 56 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82273d68
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82273D68;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62727
	ctx.r11.u64 = ctx.r11.u64 | 62727;
	// lbzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8227455c
	if (!ctx.cr0.eq) goto loc_8227455C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62783
	ctx.r11.u64 = ctx.r11.u64 | 62783;
	// lbzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8227455c
	if (!ctx.cr0.eq) goto loc_8227455C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// b 0x8227455c
	goto loc_8227455C;
loc_82273E20:
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-3088
	ctx.r11.s64 = ctx.r11.s64 + -3088;
	// addi r28,r10,14392
	ctx.r28.s64 = ctx.r10.s64 + 14392;
	// addis r27,r29,1
	ctx.r27.s64 = ctx.r29.s64 + 65536;
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r27,r27,-3100
	ctx.r27.s64 = ctx.r27.s64 + -3100;
	// lha r10,0(r11)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// addi r31,r31,-3096
	ctx.r31.s64 = ctx.r31.s64 + -3096;
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f11,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f13,712(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 712);
	ctx.f13.f64 = double(temp.f32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f12,0(r27)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// li r30,255
	ctx.r30.s64 = 255;
	// fmadds f13,f12,f13,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f11.f64)));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lhz r10,134(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 134);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// ble cr6,0x82273e98
	if (!ctx.cr6.gt) goto loc_82273E98;
	// sth r30,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r30.u16);
loc_82273E98:
	// lfs f13,-2140(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82273eb0
	if (!ctx.cr6.gt) goto loc_82273EB0;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r30,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r30.u16);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
loc_82273EB0:
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lwz r10,264(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bctrl
	ctx.lr = 0x82273EE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,500(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82274010
	if (!ctx.cr6.lt) goto loc_82274010;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r28,r8,62604
	ctx.r28.u64 = ctx.r8.u64 | 62604;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f8,7600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7600);
	ctx.f8.f64 = double(temp.f32);
	// addi r10,r10,-28872
	ctx.r10.s64 = ctx.r10.s64 + -28872;
	// lfs f9,-2040(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2040);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r11,-2040
	ctx.r11.s64 = ctx.r11.s64 + -2040;
	// lfs f11,17672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17672);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
loc_82273F3C:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r30,1118
	ctx.r11.s64 = ctx.r30.s64 + 1118;
	// fmuls f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// mulli r11,r11,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(56));
	// stfsx f0,r11,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, temp.u32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x82273f5c
	if (!ctx.cr6.gt) goto loc_82273F5C;
	// stfsx f11,r11,r29
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, temp.u32);
loc_82273F5C:
	// lfsx f0,r11,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mulli r11,r30,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(56));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// add r31,r11,r29
	ctx.r31.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r4,-2948
	ctx.r4.s64 = ctx.r4.s64 + -2948;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x824d3cb8
	ctx.lr = 0x82273FA8;
	sub_824D3CB8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r11,-2940
	ctx.r11.s64 = ctx.r11.s64 + -2940;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// bne cr6,0x82273fe8
	if (!ctx.cr6.eq) goto loc_82273FE8;
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// stfsx f0,r29,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r28.u32, temp.u32);
	// add r11,r29,r28
	ctx.r11.u64 = ctx.r29.u64 + ctx.r28.u64;
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82274000
	if (!ctx.cr6.lt) goto loc_82274000;
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82274000
	goto loc_82274000;
loc_82273FE8:
	// fmuls f0,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfsx f0,r31,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// add r11,r31,r28
	ctx.r11.u64 = ctx.r31.u64 + ctx.r28.u64;
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x82274000
	if (!ctx.cr6.gt) goto loc_82274000;
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82274000:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// blt cr6,0x82273f3c
	if (ctx.cr6.lt) goto loc_82273F3C;
	// b 0x8227455c
	goto loc_8227455C;
loc_82274010:
	// lfs f13,-1208(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1208);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822741d8
	if (!ctx.cr6.lt) goto loc_822741D8;
	// addis r9,r29,1
	ctx.r9.s64 = ctx.r29.s64 + 65536;
	// addi r9,r9,-3086
	ctx.r9.s64 = ctx.r9.s64 + -3086;
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82274084
	if (!ctx.cr0.eq) goto loc_82274084;
	// li r11,2
	ctx.r11.s64 = 2;
	// addis r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 65536;
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r10,r10,-2852
	ctx.r10.s64 = ctx.r10.s64 + -2852;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82274044:
	// stbu r24,56(r10)
	ea = 56 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r24.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82274044
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82274044;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stb r24,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r24.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,-1908(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// addi r9,r11,-2040
	ctx.r9.s64 = ctx.r11.s64 + -2040;
	// ori r10,r10,62716
	ctx.r10.u64 = ctx.r10.u64 | 62716;
	// ori r8,r8,62772
	ctx.r8.u64 = ctx.r8.u64 | 62772;
	// lfs f13,-2040(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2040);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r29,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r10.u32, temp.u32);
	// stfsx f13,r29,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r8.u32, temp.u32);
	// b 0x8227455c
	goto loc_8227455C;
loc_82274084:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// li r29,2
	ctx.r29.s64 = 2;
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// addi r31,r31,-2924
	ctx.r31.s64 = ctx.r31.s64 + -2924;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f11,-17652(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17652);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,-28872
	ctx.r11.s64 = ctx.r11.s64 + -28872;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f31,f11
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f11.f64));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f9,17672(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17672);
	ctx.f9.f64 = double(temp.f32);
loc_822740DC:
	// lbz r10,3(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r11,7(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 7);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f0,128(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fsubs f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fsubs f0,f13,f10
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lhz r10,110(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r8,102(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r9,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// and r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 & ctx.r8.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x82274174
	if (!ctx.cr6.gt) goto loc_82274174;
	// stfs f9,108(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
loc_82274174:
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x824d3cb8
	ctx.lr = 0x822741B4;
	sub_824D3CB8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r31,96
	ctx.r11.s64 = ctx.r31.s64 + 96;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bne 0x822740dc
	if (!ctx.cr0.eq) goto loc_822740DC;
	// b 0x8227455c
	goto loc_8227455C;
loc_822741D8:
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// addi r11,r11,-2792
	ctx.r11.s64 = ctx.r11.s64 + -2792;
	// lfs f0,-28872(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f0,-1908(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822741F8:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x82274210
	if (!ctx.cr6.lt) goto loc_82274210;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82274210:
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bdnz 0x822741f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822741F8;
	// b 0x8227455c
	goto loc_8227455C;
loc_8227421C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r26,r11,14392
	ctx.r26.s64 = ctx.r11.s64 + 14392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,-1908(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8225cec0
	ctx.lr = 0x82274248;
	sub_8225CEC0(ctx, base);
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r31,r29,260
	ctx.r31.s64 = ctx.r29.s64 + 260;
	// stw r24,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r24.u32);
	// lwz r11,264(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// lwz r10,268(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 268);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82274284
	if (ctx.cr0.eq) goto loc_82274284;
	// lwz r11,264(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
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
	ctx.lr = 0x82274284;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82274284:
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// ori r11,r11,62444
	ctx.r11.u64 = ctx.r11.u64 | 62444;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfsx f31,r29,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, temp.u32);
	// addi r25,r29,88
	ctx.r25.s64 = ctx.r29.s64 + 88;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// lfs f13,96(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f0,88(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82274314
	if (ctx.cr6.gt) goto loc_82274314;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82274314:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// beq 0x82274358
	if (ctx.cr0.eq) goto loc_82274358;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8227434c
	if (ctx.cr0.eq) goto loc_8227434C;
	// lwz r11,264(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
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
	ctx.lr = 0x8227434C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227434C:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r9,r9,-30032
	ctx.r9.s64 = ctx.r9.s64 + -30032;
	// b 0x82274384
	goto loc_82274384;
loc_82274358:
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8227437c
	if (ctx.cr0.eq) goto loc_8227437C;
	// lwz r11,264(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8227437C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227437C:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r9,r9,-30128
	ctx.r9.s64 = ctx.r9.s64 + -30128;
loc_82274384:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f11,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stb r27,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r27.u8);
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// stb r27,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r27.u8);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stb r27,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r27.u8);
	// li r30,255
	ctx.r30.s64 = 255;
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r28,2
	ctx.r28.s64 = 2;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,-2856
	ctx.r31.s64 = ctx.r31.s64 + -2856;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,128
	ctx.r11.s64 = 128;
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// stb r30,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// stb r30,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r30.u8);
	// stb r30,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r30.u8);
	// stb r30,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r30.u8);
	// stb r30,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r30.u8);
	// stb r30,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r30.u8);
	// stb r30,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r30.u8);
	// stb r30,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r30.u8);
	// stb r30,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r30.u8);
	// stb r30,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r30.u8);
	// stb r30,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r30.u8);
	// stb r30,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r30.u8);
	// stb r30,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r30.u8);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r30.u8);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stb r11,107(r1)
	REX_STORE_U8(ctx.r1.u32 + 107, ctx.r11.u8);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stb r30,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r30.u8);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r30.u8);
	// ld r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r10,120(r29)
	REX_STORE_U64(ctx.r29.u32 + 120, ctx.r10.u64);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r10,r10,-28240
	ctx.r10.s64 = ctx.r10.s64 + -28240;
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stb r27,123(r1)
	REX_STORE_U8(ctx.r1.u32 + 123, ctx.r27.u8);
	// stb r30,120(r1)
	REX_STORE_U8(ctx.r1.u32 + 120, ctx.r30.u8);
	// stb r30,121(r1)
	REX_STORE_U8(ctx.r1.u32 + 121, ctx.r30.u8);
	// stb r30,122(r1)
	REX_STORE_U8(ctx.r1.u32 + 122, ctx.r30.u8);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_82274484:
	// stfs f31,-76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + -76, temp.u32);
	// stb r24,-52(r31)
	REX_STORE_U8(ctx.r31.u32 + -52, ctx.r24.u8);
	// stfs f31,-72(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + -72, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f31,-48(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + -48, temp.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824d3cb8
	ctx.lr = 0x822744A4;
	sub_824D3CB8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stw r7,-92(r31)
	REX_STORE_U32(ctx.r31.u32 + -92, ctx.r7.u32);
	// lwz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r5,104(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r30,120(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f31,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stfs f31,40(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stw r11,-68(r31)
	REX_STORE_U32(ctx.r31.u32 + -68, ctx.r11.u32);
	// stfs f11,64(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stw r10,-64(r31)
	REX_STORE_U32(ctx.r31.u32 + -64, ctx.r10.u32);
	// stw r9,-60(r31)
	REX_STORE_U32(ctx.r31.u32 + -60, ctx.r9.u32);
	// stw r8,-56(r31)
	REX_STORE_U32(ctx.r31.u32 + -56, ctx.r8.u32);
	// stw r7,-88(r31)
	REX_STORE_U32(ctx.r31.u32 + -88, ctx.r7.u32);
	// stb r27,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r27.u8);
	// stw r6,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stw r5,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r5.u32);
	// stw r4,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r4.u32);
	// ld r7,-92(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + -92);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// std r7,20(r31)
	REX_STORE_U64(ctx.r31.u32 + 20, ctx.r7.u64);
	// std r7,-84(r31)
	REX_STORE_U64(ctx.r31.u32 + -84, ctx.r7.u64);
	// std r7,28(r31)
	REX_STORE_U64(ctx.r31.u32 + 28, ctx.r7.u64);
	// stwu r30,56(r31)
	ea = 56 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r31.u32 = ea;
	// bne 0x82274484
	if (!ctx.cr0.eq) goto loc_82274484;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62440
	ctx.r11.u64 = ctx.r11.u64 | 62440;
	// ori r10,r10,62436
	ctx.r10.u64 = ctx.r10.u64 | 62436;
	// ori r9,r9,62450
	ctx.r9.u64 = ctx.r9.u64 | 62450;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfsx f31,r29,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, temp.u32);
	// addi r3,r8,8432
	ctx.r3.s64 = ctx.r8.s64 + 8432;
	// stfsx f31,r29,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r29.u32 + ctx.r10.u32, temp.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stbx r27,r29,r9
	REX_STORE_U8(ctx.r29.u32 + ctx.r9.u32, ctx.r27.u8);
	// bl 0x825993b0
	ctx.lr = 0x8227455C;
	sub_825993B0(ctx, base);
loc_8227455C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822CB278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// addi r10,r10,-3124
	ctx.r10.s64 = ctx.r10.s64 + -3124;
	// addi r8,r11,12484
	ctx.r8.s64 = ctx.r11.s64 + 12484;
	// addi r9,r9,-3116
	ctx.r9.s64 = ctx.r9.s64 + -3116;
	// lfs f13,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r11,r7,62416
	ctx.r11.u64 = ctx.r7.u64 | 62416;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,1908(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfsx f13,r3,r11
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r11.u32, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_822CBC18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756698
	ctx.lr = 0x822CBC20;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r3,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,5720
	ctx.r4.s64 = ctx.r11.s64 + 5720;
	// bl 0x8223fbb0
	ctx.lr = 0x822CBC38;
	sub_8223FBB0(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r8,r8,12064
	ctx.r8.s64 = ctx.r8.s64 + 12064;
	// addi r9,r9,12252
	ctx.r9.s64 = ctx.r9.s64 + 12252;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lfs f0,232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
loc_822CBC6C:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// sth r10,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r10.u16);
	// sth r10,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r10.u16);
	// stfsu f0,12(r11)
	ctx.fpscr.disableFlushMode();
	ea = 12 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822cbc6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822CBC6C;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// ori r7,r11,62460
	ctx.r7.u64 = ctx.r11.u64 | 62460;
	// lis r28,0
	ctx.r28.s64 = 0;
	// ld r11,6272(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 6272);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r3,r3,62496
	ctx.r3.u64 = ctx.r3.u64 | 62496;
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r25,0
	ctx.r25.s64 = 0;
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stdx r11,r31,r7
	REX_STORE_U64(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u64);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r11,r11,62500
	ctx.r11.u64 = ctx.r11.u64 | 62500;
	// ori r7,r7,62504
	ctx.r7.u64 = ctx.r7.u64 | 62504;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// ori r11,r29,62512
	ctx.r11.u64 = ctx.r29.u64 | 62512;
	// stw r7,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// ori r7,r28,62513
	ctx.r7.u64 = ctx.r28.u64 | 62513;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// ori r9,r9,62468
	ctx.r9.u64 = ctx.r9.u64 | 62468;
	// ld r11,6272(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 6272);
	// ori r3,r26,62516
	ctx.r3.u64 = ctx.r26.u64 | 62516;
	// stdx r11,r31,r9
	REX_STORE_U64(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u64);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// ori r7,r25,62520
	ctx.r7.u64 = ctx.r25.u64 | 62520;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ori r4,r4,62488
	ctx.r4.u64 = ctx.r4.u64 | 62488;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lis r30,0
	ctx.r30.s64 = 0;
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// lis r27,0
	ctx.r27.s64 = 0;
	// ori r4,r30,62508
	ctx.r4.u64 = ctx.r30.u64 | 62508;
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// ori r4,r27,62514
	ctx.r4.u64 = ctx.r27.u64 | 62514;
	// lis r6,-32109
	ctx.r6.s64 = -2104295424;
	// lis r24,0
	ctx.r24.s64 = 0;
	// stw r4,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lis r23,0
	ctx.r23.s64 = 0;
	// ori r5,r5,62480
	ctx.r5.u64 = ctx.r5.u64 | 62480;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r8,r24,62524
	ctx.r8.u64 = ctx.r24.u64 | 62524;
	// ori r4,r23,62528
	ctx.r4.u64 = ctx.r23.u64 | 62528;
	// ori r23,r11,62544
	ctx.r23.u64 = ctx.r11.u64 | 62544;
	// ld r11,6848(r6)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r6.u32 + 6848);
	// lis r3,0
	ctx.r3.s64 = 0;
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stdx r11,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u64);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ld r11,6848(r6)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r6.u32 + 6848);
	// lis r4,0
	ctx.r4.s64 = 0;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lis r30,0
	ctx.r30.s64 = 0;
	// lwz r11,260(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// lis r29,0
	ctx.r29.s64 = 0;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r28,0
	ctx.r28.s64 = 0;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r25,0
	ctx.r25.s64 = 0;
	// ori r24,r3,62532
	ctx.r24.u64 = ctx.r3.u64 | 62532;
	// ori r7,r7,62536
	ctx.r7.u64 = ctx.r7.u64 | 62536;
	// ori r8,r8,62540
	ctx.r8.u64 = ctx.r8.u64 | 62540;
	// ori r9,r9,62548
	ctx.r9.u64 = ctx.r9.u64 | 62548;
	// ori r4,r4,62552
	ctx.r4.u64 = ctx.r4.u64 | 62552;
	// ori r30,r30,62556
	ctx.r30.u64 = ctx.r30.u64 | 62556;
	// ori r29,r29,62560
	ctx.r29.u64 = ctx.r29.u64 | 62560;
	// ori r28,r28,62564
	ctx.r28.u64 = ctx.r28.u64 | 62564;
	// ori r27,r27,62568
	ctx.r27.u64 = ctx.r27.u64 | 62568;
	// ori r26,r26,62569
	ctx.r26.u64 = ctx.r26.u64 | 62569;
	// ori r25,r25,62572
	ctx.r25.u64 = ctx.r25.u64 | 62572;
	// li r22,1
	ctx.r22.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfsx f0,r11,r24
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r24.u32, temp.u32);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r21,92(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stfsx f0,r11,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r6.u32, temp.u32);
	// lwz r24,100(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfsx f0,r11,r7
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r7.u32, temp.u32);
	// stfsx f0,r11,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, temp.u32);
	// lwz r31,88(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stfsx f0,r11,r23
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r23.u32, temp.u32);
	// lwz r20,96(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stfsx f0,r11,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, temp.u32);
	// lwz r6,104(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stfsx f0,r11,r21
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r21.u32, temp.u32);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stfsx f0,r11,r24
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r24.u32, temp.u32);
	// lwz r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// ld r21,128(r1)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stfsx f13,r11,r9
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stfsx f0,r11,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, temp.u32);
	// lwz r24,120(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stfsx f0,r11,r30
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, temp.u32);
	// lwz r23,124(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// stfsx f0,r11,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, temp.u32);
	// stfsx f0,r11,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r28.u32, temp.u32);
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// stwx r10,r11,r20
	REX_STORE_U32(ctx.r11.u32 + ctx.r20.u32, ctx.r10.u32);
	// stbx r10,r11,r6
	REX_STORE_U8(ctx.r11.u32 + ctx.r6.u32, ctx.r10.u8);
	// stwx r10,r11,r5
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r10.u32);
	// stdx r21,r11,r7
	REX_STORE_U64(ctx.r11.u32 + ctx.r7.u32, ctx.r21.u64);
	// stbx r10,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r10.u8);
	// stbx r10,r11,r24
	REX_STORE_U8(ctx.r11.u32 + ctx.r24.u32, ctx.r10.u8);
	// stbx r10,r11,r23
	REX_STORE_U8(ctx.r11.u32 + ctx.r23.u32, ctx.r10.u8);
	// stbx r22,r11,r27
	REX_STORE_U8(ctx.r11.u32 + ctx.r27.u32, ctx.r22.u8);
	// stbx r10,r11,r26
	REX_STORE_U8(ctx.r11.u32 + ctx.r26.u32, ctx.r10.u8);
	// stwx r10,r11,r25
	REX_STORE_U32(ctx.r11.u32 + ctx.r25.u32, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x827566e8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822DAB78) {
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
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,62440
	ctx.r4.u64 = ctx.r4.u64 | 62440;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x822DABA0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822dabb0
	if (ctx.cr0.eq) goto loc_822DABB0;
	// bl 0x822da850
	ctx.lr = 0x822DABAC;
	sub_822DA850(ctx, base);
	// b 0x822dabb4
	goto loc_822DABB4;
loc_822DABB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DABB4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_822DB568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x822DB570;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-3156
	ctx.r29.s64 = ctx.r29.s64 + -3156;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822db7a0
	if (ctx.cr6.lt) goto loc_822DB7A0;
	// beq cr6,0x822db620
	if (ctx.cr6.eq) goto loc_822DB620;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x822db7e8
	if (!ctx.cr6.lt) goto loc_822DB7E8;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822db7e8
	if (!ctx.cr0.eq) goto loc_822DB7E8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62385
	ctx.r11.u64 = ctx.r11.u64 | 62385;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822db5e0
	if (ctx.cr0.eq) goto loc_822DB5E0;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822db7e8
	if (!ctx.cr6.eq) goto loc_822DB7E8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x822db618
	goto loc_822DB618;
loc_822DB5E0:
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,-10
	ctx.r3.s64 = -10;
	// bl 0x825c08c8
	ctx.lr = 0x822DB5F0;
	sub_825C08C8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// rlwinm r9,r3,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// addic r10,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// li r8,2
	ctx.r8.s64 = 2;
	// subfze r10,r9
	temp.u8 = ~ctx.r9.u32 + ctx.xer.ca < ~ctx.r9.u32;
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// bne cr6,0x822db7e8
	if (!ctx.cr6.eq) goto loc_822DB7E8;
loc_822DB618:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x822db7e8
	goto loc_822DB7E8;
loc_822DB620:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3136
	ctx.r30.s64 = ctx.r30.s64 + -3136;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x822db704
	if (!ctx.cr6.eq) goto loc_822DB704;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822db704
	if (ctx.cr6.eq) goto loc_822DB704;
	// lbz r11,404(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 404);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822db7e8
	if (ctx.cr0.eq) goto loc_822DB7E8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r9,3
	ctx.r9.s64 = 3;
	// ori r11,r11,62388
	ctx.r11.u64 = ctx.r11.u64 | 62388;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f1,12484(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x822DB698;
	sub_8225CEC0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82487e28
	ctx.lr = 0x822DB6A8;
	sub_82487E28(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x822400e0
	ctx.lr = 0x822DB6C4;
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
	ctx.lr = 0x822DB6E0;
	sub_822400E0(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x822db794
	goto loc_822DB794;
loc_822DB704:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r9,3
	ctx.r9.s64 = 3;
	// ori r11,r11,62388
	ctx.r11.u64 = ctx.r11.u64 | 62388;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f1,12484(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x822DB738;
	sub_8225CEC0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x822400e0
	ctx.lr = 0x822DB758;
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
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x822DB774;
	sub_822400E0(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_822DB794:
	// li r3,197
	ctx.r3.s64 = 197;
	// bl 0x82250ad8
	ctx.lr = 0x822DB79C;
	sub_82250AD8(ctx, base);
	// b 0x822db7e8
	goto loc_822DB7E8;
loc_822DB7A0:
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
	ctx.lr = 0x822DB7B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822db7e8
	if (ctx.cr0.eq) goto loc_822DB7E8;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x823d4098
	ctx.lr = 0x822DB7C8;
	sub_823D4098(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 21, ctx.xer);
	// bne cr6,0x822db7e8
	if (!ctx.cr6.eq) goto loc_822DB7E8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// ori r10,r10,62404
	ctx.r10.u64 = ctx.r10.u64 | 62404;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// stbx r11,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u8);
loc_822DB7E8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822E7C28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x822E7C30;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,6040
	ctx.r4.s64 = ctx.r11.s64 + 6040;
	// bl 0x8223fbb0
	ctx.lr = 0x822E7C44;
	sub_8223FBB0(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,14496
	ctx.r10.s64 = ctx.r10.s64 + 14496;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// ori r10,r9,62372
	ctx.r10.u64 = ctx.r9.u64 | 62372;
	// lis r7,0
	ctx.r7.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r8,r8,62384
	ctx.r8.u64 = ctx.r8.u64 | 62384;
	// ori r7,r7,62444
	ctx.r7.u64 = ctx.r7.u64 | 62444;
	// stwx r11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r10,r10,62376
	ctx.r10.u64 = ctx.r10.u64 | 62376;
	// stwx r11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// stbx r11,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u8);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stbx r11,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u8);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r30,0
	ctx.r30.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lis r26,-32240
	ctx.r26.s64 = -2112880640;
	// ori r10,r4,62436
	ctx.r10.u64 = ctx.r4.u64 | 62436;
	// ori r6,r6,62388
	ctx.r6.u64 = ctx.r6.u64 | 62388;
	// ori r5,r5,62428
	ctx.r5.u64 = ctx.r5.u64 | 62428;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r4,r3,62424
	ctx.r4.u64 = ctx.r3.u64 | 62424;
	// lfs f0,12484(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// ori r8,r30,62432
	ctx.r8.u64 = ctx.r30.u64 | 62432;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r25,-32227
	ctx.r25.s64 = -2112028672;
	// stwx r11,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u32);
	// ori r7,r29,62420
	ctx.r7.u64 = ctx.r29.u64 | 62420;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// ori r9,r9,62380
	ctx.r9.u64 = ctx.r9.u64 | 62380;
	// lis r28,0
	ctx.r28.s64 = 0;
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// lis r27,0
	ctx.r27.s64 = 0;
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// lfs f13,25808(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 25808);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfsx f13,r31,r7
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stwx r3,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r4,r28,62408
	ctx.r4.u64 = ctx.r28.u64 | 62408;
	// ori r8,r27,62412
	ctx.r8.u64 = ctx.r27.u64 | 62412;
	// lis r7,-32109
	ctx.r7.s64 = -2104295424;
	// ori r9,r10,62457
	ctx.r9.u64 = ctx.r10.u64 | 62457;
	// ori r6,r6,62448
	ctx.r6.u64 = ctx.r6.u64 | 62448;
	// ori r5,r5,62456
	ctx.r5.u64 = ctx.r5.u64 | 62456;
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ld r10,6848(r7)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r7.u32 + 6848);
	// stbx r11,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u8);
	// stdx r10,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r10.u64);
	// stbx r11,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u8);
	// bl 0x82507790
	ctx.lr = 0x822E7D34;
	sub_82507790(ctx, base);
	// bl 0x82506150
	ctx.lr = 0x822E7D38;
	sub_82506150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822ED0B0) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r10,r10,63524
	ctx.r10.u64 = ctx.r10.u64 | 63524;
	// bne 0x822ed0d0
	if (!ctx.cr0.eq) goto loc_822ED0D0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stbx r9,r3,r10
	REX_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r9.u8);
	// b 0x822ed0d4
	goto loc_822ED0D4;
loc_822ED0D0:
	// stbx r11,r3,r10
	REX_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r11.u8);
loc_822ED0D4:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62372
	ctx.r10.u64 = ctx.r10.u64 | 62372;
	// stwx r11,r3,r10
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_822F1128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756688
	ctx.lr = 0x822F1130;
	__savegprlr_16(ctx, base);
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8275769c
	ctx.lr = 0x822F1138;
	__savefpr_17(ctx, base);
	// li r12,-272
	ctx.r12.s64 = -272;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-1312(r1)
	ea = -1312 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmr f17,f1
	ctx.fpscr.disableFlushMode();
	ctx.f17.f64 = ctx.f1.f64;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// ori r11,r11,63486
	ctx.r11.u64 = ctx.r11.u64 | 63486;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822f184c
	if (ctx.cr0.eq) goto loc_822F184C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// ori r24,r11,62376
	ctx.r24.u64 = ctx.r11.u64 | 62376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// add r31,r4,r24
	ctx.r31.u64 = ctx.r4.u64 + ctx.r24.u64;
	// bl 0x822400e0
	ctx.lr = 0x822F1180;
	sub_822400E0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// fadds f0,f0,f17
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f17.f64));
	// addi r5,r10,4672
	ctx.r5.s64 = ctx.r10.s64 + 4672;
	// addi r7,r9,-2512
	ctx.r7.s64 = ctx.r9.s64 + -2512;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lis r6,-32227
	ctx.r6.s64 = -2112028672;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f19,4672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4672);
	ctx.f19.f64 = double(temp.f32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r11,14296
	ctx.r8.s64 = ctx.r11.s64 + 14296;
	// lfs f24,14296(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14296);
	ctx.f24.f64 = double(temp.f32);
	// addis r22,r26,1
	ctx.r22.s64 = ctx.r26.s64 + 65536;
	// lfs f23,1268(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 1268);
	ctx.f23.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f26,-25824(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -25824);
	ctx.f26.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f28,-11000(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -11000);
	ctx.f28.f64 = double(temp.f32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f25,948(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 948);
	ctx.f25.f64 = double(temp.f32);
	// lfs f27,96(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 96);
	ctx.f27.f64 = double(temp.f32);
	// li r27,1
	ctx.r27.s64 = 1;
	// lfs f18,236(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 236);
	ctx.f18.f64 = double(temp.f32);
	// addi r22,r22,-2049
	ctx.r22.s64 = ctx.r22.s64 + -2049;
	// lfs f22,-2044(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -2044);
	ctx.f22.f64 = double(temp.f32);
	// lis r20,-32109
	ctx.r20.s64 = -2104295424;
	// lfs f21,-1808(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -1808);
	ctx.f21.f64 = double(temp.f32);
	// addi r21,r11,-28288
	ctx.r21.s64 = ctx.r11.s64 + -28288;
	// lfs f20,808(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 808);
	ctx.f20.f64 = double(temp.f32);
	// addi r25,r10,-30000
	ctx.r25.s64 = ctx.r10.s64 + -30000;
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// addi r23,r9,-28304
	ctx.r23.s64 = ctx.r9.s64 + -28304;
loc_822F120C:
	// mulli r11,r27,44
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(44));
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addis r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 65536;
	// add r31,r11,r24
	ctx.r31.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r28,r28,-3204
	ctx.r28.s64 = ctx.r28.s64 + -3204;
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// addi r30,r28,4
	ctx.r30.s64 = ctx.r28.s64 + 4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82340028
	ctx.lr = 0x822F1238;
	sub_82340028(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,848
	ctx.r3.s64 = ctx.r1.s64 + 848;
	// bl 0x82454930
	ctx.lr = 0x822F1244;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lbz r10,0(r22)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r22.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bne 0x822f1268
	if (!ctx.cr0.eq) goto loc_822F1268;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x822f183c
	goto loc_822F183C;
loc_822F1268:
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,688
	ctx.r10.s64 = ctx.r1.s64 + 688;
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r8,r1,944
	ctx.r8.s64 = ctx.r1.s64 + 944;
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,600
	ctx.r3.s64 = ctx.r1.s64 + 600;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,432(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// stfs f13,444(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// stfs f13,440(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f13,436(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,688(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,944(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 944);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x822F12E4;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bl 0x824f19d0
	ctx.lr = 0x822F1304;
	sub_824F19D0(ctx, base);
	// addi r11,r1,720
	ctx.r11.s64 = ctx.r1.s64 + 720;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,720(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 720);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,28(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// bl 0x82340028
	ctx.lr = 0x822F1320;
	sub_82340028(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82454930
	ctx.lr = 0x822F132C;
	sub_82454930(ctx, base);
	// subfic r11,r27,10
	ctx.xer.ca = ctx.r27.u32 <= 10;
	ctx.r11.u64 = static_cast<uint64_t>(10) - ctx.r27.u64;
	// addi r8,r1,880
	ctx.r8.s64 = ctx.r1.s64 + 880;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// std r11,592(r1)
	REX_STORE_U64(ctx.r1.u32 + 592, ctx.r11.u64);
	// lfd f0,592(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 592);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,752
	ctx.r11.s64 = ctx.r1.s64 + 752;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// fdivs f0,f28,f0
	ctx.f0.f64 = double(float(ctx.f28.f64 / ctx.f0.f64));
	// fadds f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82454930
	ctx.lr = 0x822F138C;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f31,880(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 880);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,752(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 752);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f10,f26
	ctx.cr6.compare(ctx.f10.f64, ctx.f26.f64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bgt cr6,0x822f1430
	if (ctx.cr6.gt) goto loc_822F1430;
	// fcmpu cr6,f10,f23
	ctx.cr6.compare(ctx.f10.f64, ctx.f23.f64);
	// ble cr6,0x822f1430
	if (!ctx.cr6.gt) goto loc_822F1430;
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,560
	ctx.r10.s64 = ctx.r1.s64 + 560;
	// fmuls f13,f10,f25
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f25.f64));
	// stfs f13,564(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// addi r9,r1,1008
	ctx.r9.s64 = ctx.r1.s64 + 1008;
	// stfs f13,560(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// stfs f13,572(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// addi r7,r1,784
	ctx.r7.s64 = ctx.r1.s64 + 784;
	// stfs f13,568(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,476(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stfs f13,472(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// stfs f13,468(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stfs f13,464(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1008(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,784(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 784);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// b 0x822f158c
	goto loc_822F158C;
loc_822F1430:
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,368(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// stfs f13,380(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// stfs f0,364(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// ori r10,r10,63496
	ctx.r10.u64 = ctx.r10.u64 | 63496;
	// stfs f0,360(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r7,r1,816
	ctx.r7.s64 = ctx.r1.s64 + 816;
	// stfs f0,352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stfs f0,356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// stfs f13,376(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// lfsx f0,r26,r10
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// stfs f0,388(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// stfs f0,384(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r30,r1,336
	ctx.r30.s64 = ctx.r1.s64 + 336;
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// addi r19,r1,304
	ctx.r19.s64 = ctx.r1.s64 + 304;
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r18,r1,224
	ctx.r18.s64 = ctx.r1.s64 + 224;
	// stfs f13,372(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// addi r17,r1,704
	ctx.r17.s64 = ctx.r1.s64 + 704;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r16,r1,672
	ctx.r16.s64 = ctx.r1.s64 + 672;
	// lvx128 v61,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,400(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stfs f31,412(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f31,408(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f31,404(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f30,236(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r11,r1,912
	ctx.r11.s64 = ctx.r1.s64 + 912;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f30,228(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f30,224(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,912(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 912);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f0,816(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,280(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,608(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 608);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f0,312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f0,308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f0,304(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// lfs f0,640(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 640);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,672(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,704(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 704);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
loc_822F158C:
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// fmr f29,f22
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f22.f64;
	// lwz r11,264(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F15AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822f15b8
	if (!ctx.cr0.eq) goto loc_822F15B8;
	// fmr f29,f21
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f21.f64;
loc_822F15B8:
	// lfs f0,36(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f18
	ctx.cr6.compare(ctx.f0.f64, ctx.f18.f64);
	// ble cr6,0x822f15d0
	if (!ctx.cr6.gt) goto loc_822F15D0;
	// lfs f0,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f17,f20,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f17.f64, ctx.f20.f64, ctx.f0.f64)));
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
loc_822F15D0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f1,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v127,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r11,63527
	ctx.r11.u64 = ctx.r11.u64 | 63527;
	// lbzx r11,r26,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822f163c
	if (ctx.cr0.eq) goto loc_822F163C;
	// bl 0x82755380
	ctx.lr = 0x822F15F0;
	sub_82755380(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,736
	ctx.r11.s64 = ctx.r1.s64 + 736;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,768
	ctx.r9.s64 = ctx.r1.s64 + 768;
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,736(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 736);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f0,f0,f24
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,768(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ld r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// b 0x822f16ec
	goto loc_822F16EC;
loc_822F163C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r11,r26,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// bne cr6,0x822f16a0
	if (!ctx.cr6.eq) goto loc_822F16A0;
	// bl 0x82755380
	ctx.lr = 0x822F1654;
	sub_82755380(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,800
	ctx.r11.s64 = ctx.r1.s64 + 800;
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// addi r9,r1,832
	ctx.r9.s64 = ctx.r1.s64 + 832;
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f0,f0,f24
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
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
	// lfs f0,800(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,832(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 832);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// b 0x822f16ec
	goto loc_822F16EC;
loc_822F16A0:
	// bl 0x82755380
	ctx.lr = 0x822F16A4;
	sub_82755380(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// addi r11,r1,864
	ctx.r11.s64 = ctx.r1.s64 + 864;
	// addi r9,r1,896
	ctx.r9.s64 = ctx.r1.s64 + 896;
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,864(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 864);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f0,f0,f19
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f19.f64));
	// stfs f0,456(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f0,448(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// stfs f0,452(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f0,460(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,896(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 896);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
loc_822F16EC:
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x822f1700
	if (!ctx.cr6.eq) goto loc_822F1700;
	// ld r11,6272(r20)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r20.u32 + 6272);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
loc_822F1700:
	// addi r11,r1,512
	ctx.r11.s64 = ctx.r1.s64 + 512;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// stfs f13,492(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f13,488(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r9,r1,544
	ctx.r9.s64 = ctx.r1.s64 + 544;
	// stfs f13,484(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f13,480(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// addi r31,r1,208
	ctx.r31.s64 = ctx.r1.s64 + 208;
	// stfs f30,524(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// addi r6,r1,960
	ctx.r6.s64 = ctx.r1.s64 + 960;
	// stfs f30,520(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// addi r7,r1,928
	ctx.r7.s64 = ctx.r1.s64 + 928;
	// stfs f30,516(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// addi r30,r1,576
	ctx.r30.s64 = ctx.r1.s64 + 576;
	// stfs f30,512(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// addi r19,r1,496
	ctx.r19.s64 = ctx.r1.s64 + 496;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r1,528
	ctx.r28.s64 = ctx.r1.s64 + 528;
	// stfs f0,556(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// addi r18,r1,992
	ctx.r18.s64 = ctx.r1.s64 + 992;
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// addi r17,r1,1024
	ctx.r17.s64 = ctx.r1.s64 + 1024;
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f31,196(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r3,r1,976
	ctx.r3.s64 = ctx.r1.s64 + 976;
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lfs f11,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,212(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f31,200(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f31,192(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f11,220(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f11,216(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f11,208(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lfs f12,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,588(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f12,584(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f12,580(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f12,576(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,928(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 928);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,536(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// stfs f0,540(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// stfs f0,532(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f0,528(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// lfs f0,960(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 960);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,504(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f0,508(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f0,496(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,992(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 992);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f13,1024(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1024);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x822F1830;
	sub_824D3CB8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_822F183C:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// cmpwi cr6,r27,10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 10, ctx.xer);
	// blt cr6,0x822f120c
	if (ctx.cr6.lt) goto loc_822F120C;
loc_822F184C:
	// addi r1,r1,1312
	ctx.r1.s64 = ctx.r1.s64 + 1312;
	// li r0,-272
	ctx.r0.s64 = -272;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x827576e8
	ctx.lr = 0x822F1860;
	__restfpr_17(ctx, base);
	// b 0x827566d8
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82302190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x82302198;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,278(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 278);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823023e8
	if (ctx.cr0.eq) goto loc_823023E8;
	// bl 0x82242798
	ctx.lr = 0x823021B8;
	sub_82242798(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823023e8
	if (!ctx.cr0.eq) goto loc_823023E8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// lwzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823023e8
	if (ctx.cr6.eq) goto loc_823023E8;
	// lbz r11,466(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 466);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r21,r10,62636
	ctx.r21.u64 = ctx.r10.u64 | 62636;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823023cc
	if (!ctx.cr0.eq) goto loc_823023CC;
	// addis r23,r30,1
	ctx.r23.s64 = ctx.r30.s64 + 65536;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r23,r23,-3056
	ctx.r23.s64 = ctx.r23.s64 + -3056;
	// stb r11,545(r30)
	REX_STORE_U8(ctx.r30.u32 + 545, ctx.r11.u8);
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r22,-32110
	ctx.r22.s64 = -2104360960;
	// lbz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8230224c
	if (!ctx.cr0.eq) goto loc_8230224C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62488
	ctx.r11.u64 = ctx.r11.u64 | 62488;
	// lwzx r4,r30,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8230224c
	if (ctx.cr6.eq) goto loc_8230224C;
	// lwz r11,-9960(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -9960);
	// stw r31,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stb r31,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r31.u8);
	// stb r31,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r31.u8);
	// beq cr6,0x8230224c
	if (ctx.cr6.eq) goto loc_8230224C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c4e00
	ctx.lr = 0x8230224C;
	sub_823C4E00(ctx, base);
loc_8230224C:
	// lbz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 0);
	// mr r25,r31
	ctx.r25.u64 = ctx.r31.u64;
	// lis r24,16384
	ctx.r24.s64 = 1073741824;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82302320
	if (ctx.cr0.eq) goto loc_82302320;
	// add r29,r30,r21
	ctx.r29.u64 = ctx.r30.u64 + ctx.r21.u64;
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
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
	// beq 0x82302320
	if (ctx.cr0.eq) goto loc_82302320;
	// addis r26,r30,1
	ctx.r26.s64 = ctx.r30.s64 + 65536;
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// addi r26,r26,-2896
	ctx.r26.s64 = ctx.r26.s64 + -2896;
loc_82302288:
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwzx r11,r10,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x823022f8
	if (ctx.cr6.eq) goto loc_823022F8;
	// lwz r11,468(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 468);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stb r31,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r31.u8);
	// stb r31,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r31.u8);
	// beq cr6,0x823022c0
	if (ctx.cr6.eq) goto loc_823022C0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_823022C0:
	// lwz r11,-9960(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -9960);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r4,r10,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stb r31,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r31.u8);
	// stb r31,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r31.u8);
	// beq cr6,0x823022f0
	if (ctx.cr6.eq) goto loc_823022F0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c4e00
	ctx.lr = 0x823022F0;
	sub_823C4E00(ctx, base);
loc_823022F0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8230231c
	if (!ctx.cr0.eq) goto loc_8230231C;
loc_823022F8:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82302288
	if (ctx.cr6.lt) goto loc_82302288;
	// b 0x82302320
	goto loc_82302320;
loc_8230231C:
	// li r25,1
	ctx.r25.s64 = 1;
loc_82302320:
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82302380
	if (!ctx.cr0.eq) goto loc_82302380;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62484
	ctx.r11.u64 = ctx.r11.u64 | 62484;
	// lwzx r4,r30,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82302380
	if (ctx.cr6.eq) goto loc_82302380;
	// lwz r11,-9960(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -9960);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// stb r31,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r31.u8);
	// stb r31,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r31.u8);
	// beq cr6,0x82302370
	if (ctx.cr6.eq) goto loc_82302370;
	// lis r5,16384
	ctx.r5.s64 = 1073741824;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ori r5,r5,3
	ctx.r5.u64 = ctx.r5.u64 | 3;
	// bl 0x823c4e00
	ctx.lr = 0x82302370;
	sub_823C4E00(ctx, base);
loc_82302370:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,0(r23)
	REX_STORE_U8(ctx.r23.u32 + 0, ctx.r11.u8);
loc_82302380:
	// lwz r4,452(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 452);
	// stb r31,545(r30)
	REX_STORE_U8(ctx.r30.u32 + 545, ctx.r31.u8);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823023cc
	if (ctx.cr6.eq) goto loc_823023CC;
	// lwz r11,468(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 468);
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x823023a4
	if (ctx.cr6.eq) goto loc_823023A4;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_823023A4:
	// lwz r11,-9960(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -9960);
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stw r31,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// stb r31,140(r1)
	REX_STORE_U8(ctx.r1.u32 + 140, ctx.r31.u8);
	// stb r31,141(r1)
	REX_STORE_U8(ctx.r1.u32 + 141, ctx.r31.u8);
	// beq cr6,0x823023cc
	if (ctx.cr6.eq) goto loc_823023CC;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823c4e00
	ctx.lr = 0x823023CC;
	sub_823C4E00(ctx, base);
loc_823023CC:
	// add r3,r30,r21
	ctx.r3.u64 = ctx.r30.u64 + ctx.r21.u64;
	// bl 0x82523e48
	ctx.lr = 0x823023D4;
	sub_82523E48(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// stw r11,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r11.u32);
	// bl 0x822417e0
	ctx.lr = 0x823023E8;
	sub_822417E0(ctx, base);
loc_823023E8:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82342D28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82342D30;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,10276
	ctx.r30.s64 = ctx.r30.s64 + 10276;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r11,r11,19424
	ctx.r11.s64 = ctx.r11.s64 + 19424;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82342d6c
	if (ctx.cr6.eq) goto loc_82342D6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82591ab8
	ctx.lr = 0x82342D64;
	sub_82591AB8(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82342D6C:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r11,r11,10268
	ctx.r11.u64 = ctx.r11.u64 | 10268;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82342d8c
	if (ctx.cr6.eq) goto loc_82342D8C;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822329c8
	ctx.lr = 0x82342D8C;
	sub_822329C8(ctx, base);
loc_82342D8C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,10380
	ctx.r11.s64 = ctx.r11.s64 + 10380;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82342da8
	if (ctx.cr0.eq) goto loc_82342DA8;
	// stb r30,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r30.u8);
loc_82342DA8:
	// bl 0x825fc6d0
	ctx.lr = 0x82342DAC;
	sub_825FC6D0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,10340
	ctx.r11.s64 = ctx.r11.s64 + 10340;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82342dc4
	if (ctx.cr0.eq) goto loc_82342DC4;
	// stb r30,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r30.u8);
loc_82342DC4:
	// bl 0x825fc6d0
	ctx.lr = 0x82342DC8;
	sub_825FC6D0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,10304
	ctx.r11.s64 = ctx.r11.s64 + 10304;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82342de0
	if (ctx.cr0.eq) goto loc_82342DE0;
	// stb r30,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r30.u8);
loc_82342DE0:
	// bl 0x825fc6d0
	ctx.lr = 0x82342DE4;
	sub_825FC6D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82241df0
	ctx.lr = 0x82342DEC;
	sub_82241DF0(ctx, base);
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82342dfc
	if (ctx.cr0.eq) goto loc_82342DFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82342DFC;
	sub_825FC588(ctx, base);
loc_82342DFC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823484A8) {
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
	// bl 0x82247990
	ctx.lr = 0x823484C4;
	sub_82247990(ctx, base);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3132
	ctx.r30.s64 = ctx.r30.s64 + -3132;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x823484fc
	if (ctx.cr6.eq) goto loc_823484FC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ab0
	ctx.lr = 0x823484E4;
	sub_82232AB0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823484fc
	if (ctx.cr0.eq) goto loc_823484FC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x822329c8
	ctx.lr = 0x823484FC;
	sub_822329C8(ctx, base);
loc_823484FC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// lis r9,-32203
	ctx.r9.s64 = -2110455808;
	// ori r10,r10,62380
	ctx.r10.u64 = ctx.r10.u64 | 62380;
	// addi r9,r9,-23008
	ctx.r9.s64 = ctx.r9.s64 + -23008;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
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

DEFINE_REX_FUNC(sub_8234B138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// addi r9,r11,-31940
	ctx.r9.s64 = ctx.r11.s64 + -31940;
	// bne cr6,0x8234b190
	if (!ctx.cr6.eq) goto loc_8234B190;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3064(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8234b188
	if (ctx.cr6.lt) goto loc_8234B188;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234B188:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8234b1dc
	if (!ctx.cr0.eq) goto loc_8234B1DC;
loc_8234B190:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8234b268
	if (!ctx.cr6.eq) goto loc_8234B268;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8234b1d4
	if (ctx.cr6.gt) goto loc_8234B1D4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234B1D4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8234b268
	if (ctx.cr0.eq) goto loc_8234B268;
loc_8234B1DC:
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
	// lfs f13,3052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3052);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x8234b218
	if (ctx.cr6.gt) goto loc_8234B218;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234B218:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8234b268
	if (ctx.cr0.eq) goto loc_8234B268;
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
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lfs f0,12484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8234b25c
	if (ctx.cr6.lt) goto loc_8234B25C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234B25C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8234b26c
	if (!ctx.cr0.eq) goto loc_8234B26C;
loc_8234B268:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234B26C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82354198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823541A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r29,-1
	ctx.r29.s64 = -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r29.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x823541CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,-14512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14512);
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
	// bge cr6,0x82354384
	if (!ctx.cr6.lt) goto loc_82354384;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822400e0
	ctx.lr = 0x82354204;
	sub_822400E0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-30192
	ctx.r10.s64 = ctx.r10.s64 + -30192;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r5,-32110
	ctx.r5.s64 = -2104360960;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r30,4288
	ctx.r27.s64 = ctx.r30.s64 + 4288;
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lwz r30,-9960(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -9960);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r28,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r27,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r27.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// beq cr6,0x82354330
	if (ctx.cr6.eq) goto loc_82354330;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823c3150
	ctx.lr = 0x8235432C;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82354330:
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f1,520(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8235437c
	if (ctx.cr6.eq) goto loc_8235437C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// addi r10,r11,6272
	ctx.r10.s64 = ctx.r11.s64 + 6272;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823c4c40
	ctx.lr = 0x82354378;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8235437C:
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// b 0x8235438c
	goto loc_8235438C;
loc_82354384:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82245af8
	ctx.lr = 0x8235438C;
	sub_82245AF8(ctx, base);
loc_8235438C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82364338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// ld r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 88);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// addi r6,r1,-32
	ctx.r6.s64 = ctx.r1.s64 + -32;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r11.u64);
	// lfs f0,-32(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f0.f64 = double(temp.f32);
	// std r11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r11.u64);
	// lfs f13,-28(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r7,-29056
	ctx.r7.s64 = ctx.r7.s64 + -29056;
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r11,62328
	ctx.r11.u64 = ctx.r11.u64 | 62328;
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// beqlr
	if (ctx.cr0.eq) return;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ld r10,-32(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ori r11,r11,62332
	ctx.r11.u64 = ctx.r11.u64 | 62332;
	// stdx r10,r3,r11
	REX_STORE_U64(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u64);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8236B2E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8236B2E8;
	__savegprlr_25(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-2512
	ctx.r9.s64 = ctx.r11.s64 + -2512;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// lfs f10,144(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// li r29,18
	ctx.r29.s64 = 18;
	// lfs f9,140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 140);
	ctx.f9.f64 = double(temp.f32);
	// ori r27,r10,64132
	ctx.r27.u64 = ctx.r10.u64 | 64132;
	// ori r28,r8,64136
	ctx.r28.u64 = ctx.r8.u64 | 64136;
	// addi r26,r11,-30000
	ctx.r26.s64 = ctx.r11.s64 + -30000;
loc_8236B320:
	// rlwinm r11,r29,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r4,r30,r27
	ctx.r4.u64 = ctx.r30.u64 + ctx.r27.u64;
	// bl 0x8236b8f0
	ctx.lr = 0x8236B330;
	sub_8236B8F0(ctx, base);
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236b348
	if (ctx.cr0.eq) goto loc_8236B348;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 & ctx.r25.u64;
loc_8236B348:
	// cmplwi cr6,r29,18
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 18, ctx.xer);
	// bne cr6,0x8236b3c4
	if (!ctx.cr6.eq) goto loc_8236B3C4;
	// addi r11,r31,576
	ctx.r11.s64 = ctx.r31.s64 + 576;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfsx f0,r11,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ori r8,r8,63840
	ctx.r8.u64 = ctx.r8.u64 | 63840;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ori r7,r7,64024
	ctx.r7.u64 = ctx.r7.u64 | 64024;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ori r6,r6,63888
	ctx.r6.u64 = ctx.r6.u64 | 63888;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r11,r27
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrghw128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vmrghw128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// stvx128 v63,r31,r8
	ea = (ctx.r31.u32 + ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r31,r7
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// b 0x8236b5c4
	goto loc_8236B5C4;
loc_8236B3C4:
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r11,r29,780
	ctx.r11.s64 = ctx.r29.s64 + 780;
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// mulli r11,r11,80
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(80));
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lfsx f0,r30,r28
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v63,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v0,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// vperm128 v61,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r7,0
	ctx.r7.s64 = 0;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// mulli r11,r29,80
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(80));
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v0,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsl v7,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v59,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v63,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r9,r29,781
	ctx.r9.s64 = ctx.r29.s64 + 781;
	// lis r7,0
	ctx.r7.s64 = 0;
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// ori r11,r7,62496
	ctx.r11.u64 = ctx.r7.u64 | 62496;
	// mulli r10,r9,80
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(80));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsubfp128 v58,v58,v61
	simde_mm_store_ps(ctx.v58.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v61,r10,r31
	ea = (ctx.r10.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r30,r11
	ea = (ctx.r30.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v55,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v56,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// vperm128 v61,v61,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// vperm128 v62,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// vmrghw128 v63,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// vspltw128 v56,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// ori r10,r10,62416
	ctx.r10.u64 = ctx.r10.u64 | 62416;
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v55,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vmrghw128 v58,v58,v60
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vaddfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v56,v55,v56
	simde_mm_store_ps(ctx.v56.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vmrghw128 v63,v58,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vperm128 v61,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v60,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// stvx128 v63,r30,r10
	ea = (ctx.r30.u32 + ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stvx128 v56,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// vaddfp128 v61,v59,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vaddfp128 v60,v57,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,148(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f12,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r4,r31,120
	ctx.r4.s64 = ctx.r31.s64 + 120;
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,272(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,304(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r11.u64);
	// bl 0x825c0d50
	ctx.lr = 0x8236B598;
	sub_825C0D50(ctx, base);
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62448
	ctx.r10.u64 = ctx.r10.u64 | 62448;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f9
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f10,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f10.f64, -ctx.f0.f64)));
	// stfsx f0,r30,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, temp.u32);
loc_8236B5C4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x8236b320
	if (!ctx.cr0.lt) goto loc_8236B320;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82389308) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82389310;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x827576c8
	ctx.lr = 0x82389318;
	__savefpr_28(ctx, base);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,517
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 517, ctx.xer);
	// beq cr6,0x823895fc
	if (ctx.cr6.eq) goto loc_823895FC;
	// cmplwi cr6,r11,528
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 528, ctx.xer);
	// beq cr6,0x82389340
	if (ctx.cr6.eq) goto loc_82389340;
	// bl 0x82372518
	ctx.lr = 0x8238933C;
	sub_82372518(ctx, base);
	// b 0x82389864
	goto loc_82389864;
loc_82389340:
	// lwz r11,260(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 260);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82389864
	if (ctx.cr6.eq) goto loc_82389864;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// addi r8,r10,12484
	ctx.r8.s64 = ctx.r10.s64 + 12484;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r9,-32113
	ctx.r9.s64 = -2104557568;
	// addi r30,r24,244
	ctx.r30.s64 = ctx.r24.s64 + 244;
	// lfs f29,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// addi r29,r4,20
	ctx.r29.s64 = ctx.r4.s64 + 20;
	// lfs f28,-232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -232);
	ctx.f28.f64 = double(temp.f32);
	// addi r27,r11,-27984
	ctx.r27.s64 = ctx.r11.s64 + -27984;
	// addi r26,r10,-29632
	ctx.r26.s64 = ctx.r10.s64 + -29632;
	// addi r28,r9,22392
	ctx.r28.s64 = ctx.r9.s64 + 22392;
loc_82389380:
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r9,248(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 248);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lhz r31,80(r1)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// b 0x823893bc
	goto loc_823893BC;
loc_823893A0:
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r8,r31
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x823893b4
	if (!ctx.cr6.lt) goto loc_823893B4;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x823893bc
	goto loc_823893BC;
loc_823893B4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_823893BC:
	// lbz r8,21(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x823893a0
	if (ctx.cr0.eq) goto loc_823893A0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823893ec
	if (ctx.cr6.eq) goto loc_823893EC;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823893ec
	if (ctx.cr6.lt) goto loc_823893EC;
	// addi r11,r1,148
	ctx.r11.s64 = ctx.r1.s64 + 148;
	// b 0x823893f4
	goto loc_823893F4;
loc_823893EC:
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
loc_823893F4:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823895ec
	if (!ctx.cr6.eq) goto loc_823895EC;
	// lbz r11,82(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x8238941c
	if (!ctx.cr6.eq) goto loc_8238941C;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x82389420
	goto loc_82389420;
loc_8238941C:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
loc_82389420:
	// rlwinm r9,r10,31,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7;
	// rlwinm r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// std r9,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r9.u64);
	// lfd f13,264(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne cr6,0x8238944c
	if (!ctx.cr6.eq) goto loc_8238944C;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x82389450
	goto loc_82389450;
loc_8238944C:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
loc_82389450:
	// rlwinm r11,r11,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// lfd f13,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r4,8
	ctx.r4.s64 = 8;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x825fc4b0
	ctx.lr = 0x82389478;
	sub_825FC4B0(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x823894d4
	if (ctx.cr0.eq) goto loc_823894D4;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f30,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f30,200(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// stfs f30,192(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// stfs f31,236(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,232(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f31,224(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f13,0(r4)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// b 0x823894d8
	goto loc_823894D8;
loc_823894D4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_823894D8:
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82454930
	ctx.lr = 0x823894E0;
	sub_82454930(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r11,83(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// bne 0x82389568
	if (!ctx.cr0.eq) goto loc_82389568;
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lfs f13,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ld r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// b 0x823895d0
	goto loc_823895D0;
loc_82389568:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,272(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
loc_823895D0:
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r4,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82378958
	ctx.lr = 0x823895EC;
	sub_82378958(ctx, base);
loc_823895EC:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x82389380
	if (!ctx.cr0.eq) goto loc_82389380;
	// b 0x82389864
	goto loc_82389864;
loc_823895FC:
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82389864
	if (ctx.cr6.eq) goto loc_82389864;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-9744(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9744);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82389640
	if (!ctx.cr6.eq) goto loc_82389640;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82389640
	if (ctx.cr6.eq) goto loc_82389640;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82389644
	if (!ctx.cr0.eq) goto loc_82389644;
loc_82389640:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82389644:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82389864
	if (ctx.cr6.eq) goto loc_82389864;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,20(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r8,-30528
	ctx.r8.s64 = ctx.r8.s64 + -30528;
	// lfs f0,24(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r4,20
	ctx.r4.s64 = ctx.r4.s64 + 20;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v6,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v0,v13
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
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82454930
	ctx.lr = 0x823896F8;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,17508(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 17508);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f12,12484(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12484);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f0.u64);
	// lbz r11,127(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 127);
	// rlwinm r8,r11,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// li r11,1
	ctx.r11.s64 = 1;
	// bge cr6,0x82389760
	if (!ctx.cr6.lt) goto loc_82389760;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82389760:
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// fabs f11,f0
	ctx.f11.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f0.u64);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,127(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 127);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// rlwinm r9,r11,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// li r11,1
	ctx.r11.s64 = 1;
	// bge cr6,0x823897bc
	if (!ctx.cr6.lt) goto loc_823897BC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_823897BC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lfs f13,272(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r9,1,24,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFE;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r7,r7,-2512
	ctx.r7.s64 = ctx.r7.s64 + -2512;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// rlwinm r11,r11,3,24,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xF8;
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// lfs f0,2092(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2092);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// rlwinm r11,r11,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// li r11,0
	ctx.r11.s64 = 0;
	// ble cr6,0x82389804
	if (!ctx.cr6.gt) goto loc_82389804;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82389804:
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// addi r3,r24,228
	ctx.r3.s64 = ctx.r24.s64 + 228;
	// lwz r11,232(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82389820
	if (!ctx.cr6.eq) goto loc_82389820;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8238982c
	goto loc_8238982C;
loc_82389820:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8238982C:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8238985c
	if (!ctx.cr6.lt) goto loc_8238985C;
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq 0x82389850
	if (ctx.cr0.eq) goto loc_82389850;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_82389850:
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82389864
	goto loc_82389864;
loc_8238985C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82389960
	ctx.lr = 0x82389864;
	sub_82389960(ctx, base);
loc_82389864:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x82757714
	ctx.lr = 0x82389870;
	__restfpr_28(ctx, base);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B51E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x823B51F0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 204);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r25,r3,176
	ctx.r25.s64 = ctx.r3.s64 + 176;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823b5210
	if (ctx.cr0.eq) goto loc_823B5210;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82872dfc
	ctx.lr = 0x823B5210;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823B5210:
	// lwz r30,212(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// lwz r26,216(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 216);
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x823b5284
	if (ctx.cr6.eq) goto loc_823B5284;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// addi r29,r10,22424
	ctx.r29.s64 = ctx.r10.s64 + 22424;
	// addi r27,r11,22392
	ctx.r27.s64 = ctx.r11.s64 + 22392;
loc_823B5230:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x825fc4b0
	ctx.lr = 0x823B5244;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823b5270
	if (ctx.cr0.eq) goto loc_823B5270;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// li r11,521
	ctx.r11.s64 = 521;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// b 0x823b5274
	goto loc_823B5274;
loc_823B5270:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B5274:
	// bl 0x825becc0
	ctx.lr = 0x823B5278;
	sub_825BECC0(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823b5230
	if (!ctx.cr6.eq) goto loc_823B5230;
loc_823B5284:
	// lbz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823b5298
	if (ctx.cr0.eq) goto loc_823B5298;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82872dec
	ctx.lr = 0x823B5298;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_823B5298:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823BBCF8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 521, ctx.xer);
	// beq cr6,0x823bbd2c
	if (ctx.cr6.eq) goto loc_823BBD2C;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x823bbd14
	if (ctx.cr6.eq) goto loc_823BBD14;
	// b 0x82372518
	sub_82372518(ctx, base);
	return;
loc_823BBD14:
	// lbz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr
	if (ctx.cr0.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,260(r3)
	REX_STORE_U8(ctx.r3.u32 + 260, ctx.r11.u8);
	// blr
	return;
loc_823BBD2C:
	// lwz r10,268(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,264(r3)
	REX_STORE_U32(ctx.r3.u32 + 264, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_823BD258) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x823BD260;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r3,292
	ctx.r30.s64 = ctx.r3.s64 + 292;
	// addi r11,r11,32704
	ctx.r11.s64 = ctx.r11.s64 + 32704;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82476198
	ctx.lr = 0x823BD280;
	sub_82476198(ctx, base);
	// addi r29,r31,308
	ctx.r29.s64 = ctx.r31.s64 + 308;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82476198
	ctx.lr = 0x823BD28C;
	sub_82476198(ctx, base);
	// lwz r3,328(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bd29c
	if (ctx.cr6.eq) goto loc_823BD29C;
	// bl 0x8222bcc8
	ctx.lr = 0x823BD29C;
	sub_8222BCC8(ctx, base);
loc_823BD29C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r28,r11,-25044
	ctx.r28.s64 = ctx.r11.s64 + -25044;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// bl 0x82476198
	ctx.lr = 0x823BD2B0;
	sub_82476198(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82476198
	ctx.lr = 0x823BD2BC;
	sub_82476198(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82372418
	ctx.lr = 0x823BD2C4;
	sub_82372418(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C1678) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8243f6d0
	ctx.lr = 0x823C1698;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823c170c
	if (ctx.cr0.eq) goto loc_823C170C;
	// bl 0x82441b00
	ctx.lr = 0x823C16A4;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823c16b4
	if (!ctx.cr0.eq) goto loc_823C16B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823c16b8
	goto loc_823C16B8;
loc_823C16B4:
	// bl 0x82441f48
	ctx.lr = 0x823C16B8;
	sub_82441F48(ctx, base);
loc_823C16B8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823c170c
	if (ctx.cr0.eq) goto loc_823C170C;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r8,537
	ctx.r8.s64 = 537;
	// addi r9,r9,22424
	ctx.r9.s64 = ctx.r9.s64 + 22424;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r11,-9988(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9988);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// beq cr6,0x823c170c
	if (ctx.cr6.eq) goto loc_823C170C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377978
	ctx.lr = 0x823C170C;
	sub_82377978(ctx, base);
loc_823C170C:
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

DEFINE_REX_FUNC(sub_823C4300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x823C4308;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,92(r1)
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lwz r31,-9960(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823c3150
	ctx.lr = 0x823C43A0;
	sub_823C3150(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r10,r3,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// addi r30,r11,16
	ctx.r30.s64 = ctx.r11.s64 + 16;
	// lwz r31,20(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x823c43f4
	goto loc_823C43F4;
loc_823C43BC:
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm. r10,r11,0,0,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x823c43ec
	if (!ctx.cr0.eq) goto loc_823C43EC;
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823c43ec
	if (ctx.cr0.eq) goto loc_823C43EC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c4410
	ctx.lr = 0x823C43E4;
	sub_823C4410(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823c4408
	if (!ctx.cr0.eq) goto loc_823C4408;
loc_823C43EC:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_823C43F4:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823c43bc
	if (!ctx.cr6.eq) goto loc_823C43BC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823C4400:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
loc_823C4408:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x823c4400
	goto loc_823C4400;
}

DEFINE_REX_FUNC(sub_823CB090) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823CB098;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x823cb1f8
	ctx.lr = 0x823CB0A8;
	sub_823CB1F8(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// addi r31,r28,4
	ctx.r31.s64 = ctx.r28.s64 + 4;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lbz r11,25(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 25);
	// b 0x823cb0e8
	goto loc_823CB0E8;
loc_823CB0C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x823ce178
	ctx.lr = 0x823CB0CC;
	sub_823CE178(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq cr6,0x823cb0e0
	if (ctx.cr6.eq) goto loc_823CB0E0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x823CB0E0;
	sub_825FC588(ctx, base);
loc_823CB0E0:
	// lbz r11,25(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 25);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_823CB0E8:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cb0c0
	if (ctx.cr0.eq) goto loc_823CB0C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cb120
	if (ctx.cr6.eq) goto loc_823CB120;
	// bl 0x823cb1a8
	ctx.lr = 0x823CB120;
	sub_823CB1A8(ctx, base);
loc_823CB120:
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lbz r11,25(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 25);
	// b 0x823cb160
	goto loc_823CB160;
loc_823CB138:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x823ce178
	ctx.lr = 0x823CB144;
	sub_823CE178(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq cr6,0x823cb158
	if (ctx.cr6.eq) goto loc_823CB158;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x823CB158;
	sub_825FC588(ctx, base);
loc_823CB158:
	// lbz r11,25(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 25);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_823CB160:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cb138
	if (ctx.cr0.eq) goto loc_823CB138;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cb194
	if (ctx.cr6.eq) goto loc_823CB194;
	// bl 0x825fc588
	ctx.lr = 0x823CB194;
	sub_825FC588(ctx, base);
loc_823CB194:
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CE860) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r11,18524
	ctx.r11.s64 = ctx.r11.s64 + 18524;
loc_823CE86C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq 0x823ce890
	if (ctx.cr0.eq) goto loc_823CE890;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x823ce86c
	if (ctx.cr6.eq) goto loc_823CE86C;
loc_823CE890:
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_823CF848) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x823CF850;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,196(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 196);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cf958
	if (ctx.cr6.eq) goto loc_823CF958;
	// addi r30,r3,168
	ctx.r30.s64 = ctx.r3.s64 + 168;
loc_823CF86C:
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cf88c
	if (ctx.cr6.eq) goto loc_823CF88C;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823cf890
	goto loc_823CF890;
loc_823CF88C:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_823CF890:
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x823cf8b8
	if (ctx.cr6.gt) goto loc_823CF8B8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cf8ac
	if (ctx.cr6.eq) goto loc_823CF8AC;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823cf8b0
	goto loc_823CF8B0;
loc_823CF8AC:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_823CF8B0:
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
loc_823CF8B8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cf8c8
	if (ctx.cr6.eq) goto loc_823CF8C8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823cf8cc
	goto loc_823CF8CC;
loc_823CF8C8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_823CF8CC:
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwzx r31,r11,r9
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf8f0
	if (ctx.cr6.eq) goto loc_823CF8F0;
	// bl 0x82222a60
	ctx.lr = 0x823CF8F0;
	sub_82222A60(ctx, base);
loc_823CF8F0:
	// rotlwi r3,r27,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r27.u32, 0);
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf904
	if (ctx.cr6.eq) goto loc_823CF904;
	// bl 0x82222a60
	ctx.lr = 0x823CF904;
	sub_82222A60(ctx, base);
loc_823CF904:
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x823CF910;
	sub_825FC588(ctx, base);
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823cf94c
	if (ctx.cr6.eq) goto loc_823CF94C;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x823cf93c
	if (ctx.cr6.gt) goto loc_823CF93C;
	// stw r27,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r27.u32);
loc_823CF93C:
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// bne 0x823cf94c
	if (!ctx.cr0.eq) goto loc_823CF94C;
	// stw r27,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r27.u32);
loc_823CF94C:
	// lwz r11,196(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823cf86c
	if (!ctx.cr6.eq) goto loc_823CF86C;
loc_823CF958:
	// lwz r31,204(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 204);
	// lwz r29,208(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// b 0x823cf9b0
	goto loc_823CF9B0;
loc_823CF964:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf978
	if (ctx.cr6.eq) goto loc_823CF978;
	// bl 0x82222a60
	ctx.lr = 0x823CF978;
	sub_82222A60(ctx, base);
loc_823CF978:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r27.u32);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823cf9a8
	if (ctx.cr6.eq) goto loc_823CF9A8;
	// lwz r3,24(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cf99c
	if (ctx.cr6.eq) goto loc_823CF99C;
	// bl 0x82222a60
	ctx.lr = 0x823CF99C;
	sub_82222A60(ctx, base);
loc_823CF99C:
	// stw r27,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r27.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x823CF9A8;
	sub_825FC588(ctx, base);
loc_823CF9A8:
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_823CF9B0:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x823cf964
	if (!ctx.cr6.eq) goto loc_823CF964;
	// lwz r3,204(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 204);
	// addi r30,r28,200
	ctx.r30.s64 = ctx.r28.s64 + 200;
	// lwz r5,208(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x823cf9ec
	if (ctx.cr6.eq) goto loc_823CF9EC;
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
	// ble 0x823cf9e8
	if (!ctx.cr0.gt) goto loc_823CF9E8;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x823CF9E8;
	sub_82755080(ctx, base);
loc_823CF9E8:
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
loc_823CF9EC:
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823cfa0c
	if (ctx.cr6.eq) goto loc_823CFA0C;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r3,-9752(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -9752);
	// bl 0x825b5760
	ctx.lr = 0x823CFA04;
	sub_825B5760(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_823CFA0C:
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cfa1c
	if (ctx.cr6.eq) goto loc_823CFA1C;
	// bl 0x825fc588
	ctx.lr = 0x823CFA1C;
	sub_825FC588(ctx, base);
loc_823CFA1C:
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823DDC08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x823DDC10;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r3,32(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823ddc30
	if (ctx.cr6.eq) goto loc_823DDC30;
	// bl 0x823d2520
	ctx.lr = 0x823DDC30;
	sub_823D2520(ctx, base);
loc_823DDC30:
	// addi r31,r29,36
	ctx.r31.s64 = ctx.r29.s64 + 36;
	// li r30,4
	ctx.r30.s64 = 4;
loc_823DDC38:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823ddc48
	if (ctx.cr6.eq) goto loc_823DDC48;
	// bl 0x823d2520
	ctx.lr = 0x823DDC48;
	sub_823D2520(ctx, base);
loc_823DDC48:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x823ddc38
	if (!ctx.cr0.eq) goto loc_823DDC38;
	// lfs f0,28(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,28(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 28, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E0DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x823E0DE0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subf r28,r3,r4
	ctx.r28.u64 = ctx.r4.u64 - ctx.r3.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// srawi r30,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r28.s32 >> 2;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// ble cr6,0x823e0f30
	if (!ctx.cr6.gt) goto loc_823E0F30;
loc_823E0E08:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x823e0e98
	if (!ctx.cr6.gt) goto loc_823E0E98;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e11a8
	ctx.lr = 0x823E0E24;
	sub_823E11A8(ctx, base);
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// subf r11,r30,r27
	ctx.r11.u64 = ctx.r27.u64 - ctx.r30.u64;
	// subf r10,r31,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r31.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x823e0e74
	if (!ctx.cr6.lt) goto loc_823E0E74;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823e0dd8
	ctx.lr = 0x823E0E6C;
	sub_823E0DD8(ctx, base);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x823e0e84
	goto loc_823E0E84;
loc_823E0E74:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823e0dd8
	ctx.lr = 0x823E0E80;
	sub_823E0DD8(ctx, base);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
loc_823E0E84:
	// subf r28,r31,r27
	ctx.r28.u64 = ctx.r27.u64 - ctx.r31.u64;
	// srawi r30,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r28.s32 >> 2;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// bgt cr6,0x823e0e08
	if (ctx.cr6.gt) goto loc_823E0E08;
loc_823E0E98:
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x823e0f30
	if (!ctx.cr6.gt) goto loc_823E0F30;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x823e0fc8
	if (!ctx.cr6.gt) goto loc_823E0FC8;
	// srawi r11,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 1;
	// addze. r29,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r29.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble 0x823e0ee0
	if (!ctx.cr0.gt) goto loc_823E0EE0;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r11,r31
	ctx.r26.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_823E0EBC:
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwzu r6,-4(r26)
	ea = -4 + ctx.r26.u32;
	ctx.r6.u64 = REX_LOAD_U32(ea);
	ctx.r26.u32 = ea;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823e3180
	ctx.lr = 0x823E0ED8;
	sub_823E3180(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bgt cr6,0x823e0ebc
	if (ctx.cr6.gt) goto loc_823E0EBC;
loc_823E0EE0:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x823e0fc8
	if (!ctx.cr6.gt) goto loc_823E0FC8;
	// addi r29,r27,-4
	ctx.r29.s64 = ctx.r27.s64 + -4;
	// subfic r27,r31,4
	ctx.xer.ca = ctx.r31.u32 <= 4;
	ctx.r27.u64 = static_cast<uint64_t>(4) - ctx.r31.u64;
	// subf r28,r31,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r31.u64;
loc_823E0EF4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r5,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r28.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// bl 0x823e3180
	ctx.lr = 0x823E0F14;
	sub_823E3180(ctx, base);
	// addi r29,r29,-4
	ctx.r29.s64 = ctx.r29.s64 + -4;
	// addi r28,r28,-4
	ctx.r28.s64 = ctx.r28.s64 + -4;
	// add r11,r27,r29
	ctx.r11.u64 = ctx.r27.u64 + ctx.r29.u64;
	// srawi r30,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r11.s32 >> 2;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bgt cr6,0x823e0ef4
	if (ctx.cr6.gt) goto loc_823E0EF4;
	// b 0x823e0fc8
	goto loc_823E0FC8;
loc_823E0F30:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x823e0fc8
	if (!ctx.cr6.gt) goto loc_823E0FC8;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x823e0fc8
	if (ctx.cr6.eq) goto loc_823E0FC8;
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// b 0x823e0fc0
	goto loc_823E0FC0;
loc_823E0F48:
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823e09c0
	ctx.lr = 0x823E0F5C;
	sub_823E09C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e0f8c
	if (ctx.cr0.eq) goto loc_823E0F8C;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x823e0f84
	if (ctx.cr6.eq) goto loc_823E0F84;
	// li r10,4
	ctx.r10.s64 = 4;
loc_823E0F74:
	// lwzu r9,-4(r11)
	ea = -4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// stwx r9,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u32);
	// bne cr6,0x823e0f74
	if (!ctx.cr6.eq) goto loc_823E0F74;
loc_823E0F84:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// b 0x823e0fbc
	goto loc_823E0FBC;
loc_823E0F8C:
	// lwz r4,-4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// addi r29,r30,-4
	ctx.r29.s64 = ctx.r30.s64 + -4;
	// b 0x823e0fa8
	goto loc_823E0FA8;
loc_823E0F98:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// lwzu r4,-4(r29)
	ea = -4 + ctx.r29.u32;
	ctx.r4.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
loc_823E0FA8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823e09c0
	ctx.lr = 0x823E0FB0;
	sub_823E09C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823e0f98
	if (!ctx.cr0.eq) goto loc_823E0F98;
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
loc_823E0FBC:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_823E0FC0:
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x823e0f48
	if (!ctx.cr6.eq) goto loc_823E0F48;
loc_823E0FC8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F12D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756694
	ctx.lr = 0x823F12D8;
	__savegprlr_19(ctx, base);
	// stfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f29.u64);
	// stfd f30,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f30.u64);
	// stfd f31,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,43
	ctx.r10.s64 = 43;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823F12F8:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,288(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 288);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823f12f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F12F8;
	// lbz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 288);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823f1828
	if (ctx.cr0.eq) goto loc_823F1828;
	// lbz r11,291(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 291);
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823f1340
	if (ctx.cr0.eq) goto loc_823F1340;
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823f1338
	if (ctx.cr6.eq) goto loc_823F1338;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823f1340
	if (!ctx.cr6.eq) goto loc_823F1340;
loc_823F1338:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x823f1344
	goto loc_823F1344;
loc_823F1340:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_823F1344:
	// lwz r9,160(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// clrlwi. r22,r11,24
	ctx.r22.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r20,r10,3268
	ctx.r20.s64 = ctx.r10.s64 + 3268;
	// stb r11,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r11.u8);
	// beq 0x823f13c4
	if (ctx.cr0.eq) goto loc_823F13C4;
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823f137c
	if (ctx.cr6.eq) goto loc_823F137C;
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// lwz r10,304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// beq cr6,0x823f1380
	if (ctx.cr6.eq) goto loc_823F1380;
loc_823F137C:
	// li r11,1
	ctx.r11.s64 = 1;
loc_823F1380:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r10,r20,8560
	ctx.r10.s64 = ctx.r20.s64 + 8560;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// rlwinm r11,r11,29,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x4;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823dc188
	ctx.lr = 0x823F13A0;
	sub_823DC188(ctx, base);
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
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
	ctx.lr = 0x823F13C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823F13C4:
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r26,r11,12488
	ctx.r26.s64 = ctx.r11.s64 + 12488;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwz r11,-9900(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -9900);
	// li r24,-1
	ctx.r24.s64 = -1;
	// addi r28,r10,-23924
	ctx.r28.s64 = ctx.r10.s64 + -23924;
	// addi r21,r9,808
	ctx.r21.s64 = ctx.r9.s64 + 808;
	// lfs f29,-4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -4);
	ctx.f29.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r27,428(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x823f1500
	if (ctx.cr6.eq) goto loc_823F1500;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f12,-76(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -76);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// addi r11,r11,-26392
	ctx.r11.s64 = ctx.r11.s64 + -26392;
	// lfs f0,-2848(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -2848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,22540(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 22540);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// lfs f10,-4(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// lfs f9,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,15132(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 15132);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,328(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 328);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,332(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 332);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fsubs f4,f6,f11
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// lfs f7,336(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 336);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,340(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 340);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f3,f7,f12
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fsubs f2,f6,f11
	ctx.f2.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// lfs f7,320(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 320);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,324(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 324);
	ctx.f6.f64 = double(temp.f32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// fsubs f12,f7,f12
	ctx.f12.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f31,18280(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 18280);
	ctx.f31.f64 = double(temp.f32);
	// fsubs f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// stfs f29,144(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r23,r11,-7664
	ctx.r23.s64 = ctx.r11.s64 + -7664;
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_823F14B0:
	// cmplwi cr6,r25,2
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 2, ctx.xer);
	// blt cr6,0x823f14c0
	if (ctx.cr6.lt) goto loc_823F14C0;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x823f14ec
	if (ctx.cr6.eq) goto loc_823F14EC;
loc_823F14C0:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r5,240(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// addi r8,r30,8
	ctx.r8.s64 = ctx.r30.s64 + 8;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823da2d0
	ctx.lr = 0x823F14EC;
	sub_823DA2D0(ctx, base);
loc_823F14EC:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// cmplwi cr6,r25,3
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 3, ctx.xer);
	// blt cr6,0x823f14b0
	if (ctx.cr6.lt) goto loc_823F14B0;
loc_823F1500:
	// lfs f30,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f31,-236(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -236);
	ctx.f31.f64 = double(temp.f32);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// li r4,155
	ctx.r4.s64 = 155;
	// lfs f3,15132(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 15132);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,13008(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 13008);
	ctx.f2.f64 = double(temp.f32);
	// lwz r3,172(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r6,240(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// fmr f4,f30
	ctx.f4.f64 = ctx.f30.f64;
	// stb r19,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r19.u8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823dae00
	ctx.lr = 0x823F1534;
	sub_823DAE00(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f3,15132(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 15132);
	ctx.f3.f64 = double(temp.f32);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// lwz r6,240(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// li r4,156
	ctx.r4.s64 = 156;
	// lwz r3,172(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// stb r19,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r19.u8);
	// fmr f4,f30
	ctx.f4.f64 = ctx.f30.f64;
	// lfs f2,-26408(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26408);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823dae00
	ctx.lr = 0x823F1564;
	sub_823DAE00(ctx, base);
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x823dcbc0
	ctx.lr = 0x823F156C;
	sub_823DCBC0(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x823f1580
	if (ctx.cr6.eq) goto loc_823F1580;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x823f1588
	if (!ctx.cr6.eq) goto loc_823F1588;
loc_823F1580:
	// lwz r3,216(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// bl 0x823dcbc0
	ctx.lr = 0x823F1588;
	sub_823DCBC0(ctx, base);
loc_823F1588:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x823f159c
	if (!ctx.cr6.eq) goto loc_823F159C;
	// lwz r3,224(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// bl 0x823dcbc0
	ctx.lr = 0x823F159C;
	sub_823DCBC0(ctx, base);
loc_823F159C:
	// addi r29,r31,172
	ctx.r29.s64 = ctx.r31.s64 + 172;
	// li r30,3
	ctx.r30.s64 = 3;
loc_823F15A4:
	// lwzu r11,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823dfdd0
	ctx.lr = 0x823F15B0;
	sub_823DFDD0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x823f15a4
	if (!ctx.cr0.eq) goto loc_823F15A4;
	// lbz r11,291(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 291);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823f15d4
	if (ctx.cr0.eq) goto loc_823F15D4;
	// lwz r10,280(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bgt cr6,0x823f15d8
	if (ctx.cr6.gt) goto loc_823F15D8;
loc_823F15D4:
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_823F15D8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823f1600
	if (ctx.cr6.eq) goto loc_823F1600;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// ble cr6,0x823f1600
	if (!ctx.cr6.gt) goto loc_823F1600;
	// lwz r9,280(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x823f1604
	if (ctx.cr6.lt) goto loc_823F1604;
loc_823F1600:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_823F1604:
	// lwz r9,204(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stb r10,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// stb r11,9(r9)
	REX_STORE_U8(ctx.r9.u32 + 9, ctx.r11.u8);
	// lbz r11,291(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 291);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823f162c
	if (ctx.cr0.eq) goto loc_823F162C;
	// lwz r10,284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bgt cr6,0x823f1630
	if (ctx.cr6.gt) goto loc_823F1630;
loc_823F162C:
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_823F1630:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823f1658
	if (ctx.cr6.eq) goto loc_823F1658;
	// lwz r11,272(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// ble cr6,0x823f1658
	if (!ctx.cr6.gt) goto loc_823F1658;
	// lwz r9,284(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x823f165c
	if (ctx.cr6.lt) goto loc_823F165C;
loc_823F1658:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_823F165C:
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r29,r31,184
	ctx.r29.s64 = ctx.r31.s64 + 184;
	// li r30,6
	ctx.r30.s64 = 6;
	// stb r10,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// stb r11,9(r9)
	REX_STORE_U8(ctx.r9.u32 + 9, ctx.r11.u8);
loc_823F1670:
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x823dbae8
	ctx.lr = 0x823F1678;
	sub_823DBAE8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x823f1670
	if (!ctx.cr0.eq) goto loc_823F1670;
	// lbz r11,291(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 291);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823f16a4
	if (ctx.cr0.eq) goto loc_823F16A4;
	// addi r29,r31,228
	ctx.r29.s64 = ctx.r31.s64 + 228;
	// li r30,2
	ctx.r30.s64 = 2;
loc_823F1694:
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x823dfa40
	ctx.lr = 0x823F169C;
	sub_823DFA40(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x823f1694
	if (!ctx.cr0.eq) goto loc_823F1694;
loc_823F16A4:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lfs f1,1000(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 1000);
	ctx.f1.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r7,240(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r8,20360(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 20360);
	// bl 0x824714e0
	ctx.lr = 0x823F16C8;
	sub_824714E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f17c0
	if (ctx.cr0.eq) goto loc_823F17C0;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lfs f0,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r9,-2512
	ctx.r9.s64 = ctx.r9.s64 + -2512;
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r10,20384
	ctx.r10.s64 = ctx.r10.s64 + 20384;
	// li r7,3
	ctx.r7.s64 = 3;
	// lfs f12,3440(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3440);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,2976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2976);
	ctx.f13.f64 = double(temp.f32);
loc_823F1704:
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// mr r8,r19
	ctx.r8.u64 = ctx.r19.u64;
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// fadds f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_823F1720:
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// std r6,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r6.u64);
	// lfd f11,192(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// fadds f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r28,0(r5)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r27,4(r5)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r25,8(r5)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r30,0(r6)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r29,4(r6)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r26,8(r6)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r5,12(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r6,12(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// stw r25,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r25.u32);
	// stw r30,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r30.u32);
	// stw r29,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r29.u32);
	// stw r26,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r26.u32);
	// stw r5,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// stw r6,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r6.u32);
	// bne 0x823f1720
	if (!ctx.cr0.eq) goto loc_823F1720;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x823f1704
	if (!ctx.cr0.eq) goto loc_823F1704;
	// li r11,12
	ctx.r11.s64 = 12;
	// addi r10,r3,-12
	ctx.r10.s64 = ctx.r3.s64 + -12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823F17B4:
	// li r11,255
	ctx.r11.s64 = 255;
	// stwu r11,40(r10)
	ea = 40 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823f17b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F17B4;
loc_823F17C0:
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r10,r20,8288
	ctx.r10.s64 = ctx.r20.s64 + 8288;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823F17D4:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lwz r8,252(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwzx r9,r9,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r8,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r8.u8);
	// bdnz 0x823f17d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F17D4;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
loc_823F1828:
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x827566e4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241AC70) {
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
	// bl 0x82371af8
	ctx.lr = 0x8241AC94;
	sub_82371AF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// bl 0x82371af8
	ctx.lr = 0x8241ACA4;
	sub_82371AF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,100
	ctx.r3.s64 = ctx.r31.s64 + 100;
	// bl 0x82371af8
	ctx.lr = 0x8241ACB4;
	sub_82371AF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,72
	ctx.r3.s64 = ctx.r31.s64 + 72;
	// bl 0x82371af8
	ctx.lr = 0x8241ACC4;
	sub_82371AF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// bl 0x82371af8
	ctx.lr = 0x8241ACD4;
	sub_82371AF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x82371af8
	ctx.lr = 0x8241ACE4;
	sub_82371AF8(ctx, base);
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

DEFINE_REX_FUNC(sub_8241D310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8241D318;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8241d488
	if (ctx.cr6.lt) goto loc_8241D488;
	// beq cr6,0x8241d454
	if (ctx.cr6.eq) goto loc_8241D454;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8241d654
	if (!ctx.cr6.lt) goto loc_8241D654;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// li r29,2
	ctx.r29.s64 = 2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241d38c
	if (ctx.cr6.eq) goto loc_8241D38C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x8241d3d8
	if (ctx.cr6.eq) goto loc_8241D3D8;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x8241d654
	if (!ctx.cr6.eq) goto loc_8241D654;
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// lwz r31,-9896(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + -9896);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8241d4b8
	if (ctx.cr6.eq) goto loc_8241D4B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241a680
	ctx.lr = 0x8241D378;
	sub_8241A680(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x8241D380;
	sub_825FC588(ctx, base);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,-9896(r30)
	REX_STORE_U32(ctx.r30.u32 + -9896, ctx.r27.u32);
	// b 0x8241d4b8
	goto loc_8241D4B8;
loc_8241D38C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r10,5763
	ctx.r10.s64 = 5763;
	// li r31,5
	ctx.r31.s64 = 5;
	// li r9,4000
	ctx.r9.s64 = 4000;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// lwz r11,-9900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9900);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r29,1312(r11)
	REX_STORE_U32(ctx.r11.u32 + 1312, ctx.r29.u32);
	// stw r9,1336(r11)
	REX_STORE_U32(ctx.r11.u32 + 1336, ctx.r9.u32);
	// std r10,1316(r11)
	REX_STORE_U64(ctx.r11.u32 + 1316, ctx.r10.u64);
	// bl 0x82223348
	ctx.lr = 0x8241D3C0;
	sub_82223348(ctx, base);
	// lbz r11,4041(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4041);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8241d3d4
	if (ctx.cr6.gt) goto loc_8241D3D4;
	// lfs f1,-6328(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -6328);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a2398
	ctx.lr = 0x8241D3D4;
	sub_825A2398(ctx, base);
loc_8241D3D4:
	// stw r31,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r31.u32);
loc_8241D3D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c01b8
	ctx.lr = 0x8241D3E0;
	sub_825C01B8(ctx, base);
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f0,-6328(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -6328);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,4(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8241d654
	if (!ctx.cr6.gt) goto loc_8241D654;
	// bl 0x82223348
	ctx.lr = 0x8241D3FC;
	sub_82223348(ctx, base);
	// stw r27,4016(r3)
	REX_STORE_U32(ctx.r3.u32 + 4016, ctx.r27.u32);
	// bl 0x82223348
	ctx.lr = 0x8241D404;
	sub_82223348(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,4020(r3)
	REX_STORE_U32(ctx.r3.u32 + 4020, ctx.r11.u32);
	// lwz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// stb r10,153(r11)
	REX_STORE_U8(ctx.r11.u32 + 153, ctx.r10.u8);
	// bl 0x82223348
	ctx.lr = 0x8241D41C;
	sub_82223348(ctx, base);
	// lbz r11,4041(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4041);
	// lwz r10,12(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8241d438
	if (ctx.cr6.gt) goto loc_8241D438;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// b 0x8241d440
	goto loc_8241D440;
loc_8241D438:
	// li r11,40
	ctx.r11.s64 = 40;
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
loc_8241D440:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D454:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x8241d654
	if (!ctx.cr6.eq) goto loc_8241D654;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c01b8
	ctx.lr = 0x8241D468;
	sub_825C01B8(ctx, base);
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f13,4(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// lfs f0,12252(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12252);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8241d654
	if (!ctx.cr6.gt) goto loc_8241D654;
	// b 0x8241d4b8
	goto loc_8241D4B8;
loc_8241D488:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8241d648
	if (ctx.cr6.lt) goto loc_8241D648;
	// beq cr6,0x8241d630
	if (ctx.cr6.eq) goto loc_8241D630;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8241d5dc
	if (ctx.cr6.lt) goto loc_8241D5DC;
	// beq cr6,0x8241d518
	if (ctx.cr6.eq) goto loc_8241D518;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8241d50c
	if (ctx.cr6.lt) goto loc_8241D50C;
	// beq cr6,0x8241d4c0
	if (ctx.cr6.eq) goto loc_8241D4C0;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x8241d654
	if (!ctx.cr6.lt) goto loc_8241D654;
loc_8241D4B8:
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x8241d654
	goto loc_8241D654;
loc_8241D4C0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8241d4ec
	if (!ctx.cr6.lt) goto loc_8241D4EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c01b8
	ctx.lr = 0x8241D4DC;
	sub_825C01B8(ctx, base);
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,4(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// b 0x8241d654
	goto loc_8241D654;
loc_8241D4EC:
	// bl 0x8241d728
	ctx.lr = 0x8241D4F0;
	sub_8241D728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241d654
	if (!ctx.cr0.eq) goto loc_8241D654;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82419f08
	ctx.lr = 0x8241D500;
	sub_82419F08(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D50C:
	// bl 0x8241d660
	ctx.lr = 0x8241D510;
	sub_8241D660(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D518:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r6,-9896(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -9896);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8241d530
	if (!ctx.cr6.eq) goto loc_8241D530;
loc_8241D528:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8241d5b0
	goto loc_8241D5B0;
loc_8241D530:
	// lwz r11,28(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 28);
	// lwz r10,24(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8241d5ac
	if (ctx.cr0.eq) goto loc_8241D5AC;
	// lwz r7,28(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 28);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8241d5ac
	if (ctx.cr6.eq) goto loc_8241D5AC;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r8,-9752(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -9752);
loc_8241D55C:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x8241d5a0
	if (ctx.cr6.eq) goto loc_8241D5A0;
	// lwz r11,8(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// mulli r10,r10,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(52));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8241d594
	if (ctx.cr6.eq) goto loc_8241D594;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8241d594
	if (ctx.cr6.eq) goto loc_8241D594;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8241d598
	if (!ctx.cr6.eq) goto loc_8241D598;
loc_8241D594:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8241D598:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241d528
	if (!ctx.cr0.eq) goto loc_8241D528;
loc_8241D5A0:
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8241d55c
	if (!ctx.cr6.eq) goto loc_8241D55C;
loc_8241D5AC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8241D5B0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241d654
	if (!ctx.cr0.eq) goto loc_8241D654;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// beq cr6,0x8241d5c8
	if (ctx.cr6.eq) goto loc_8241D5C8;
	// lbz r11,16(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 16);
loc_8241D5C8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241d5d4
	if (!ctx.cr0.eq) goto loc_8241D5D4;
	// bl 0x8241a9f8
	ctx.lr = 0x8241D5D4;
	sub_8241A9F8(ctx, base);
loc_8241D5D4:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D5DC:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9896);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8241d624
	if (!ctx.cr6.eq) goto loc_8241D624;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x8241D604;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8241d614
	if (ctx.cr0.eq) goto loc_8241D614;
	// bl 0x8241a598
	ctx.lr = 0x8241D610;
	sub_8241A598(ctx, base);
	// b 0x8241d618
	goto loc_8241D618;
loc_8241D614:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8241D618:
	// stw r3,-9896(r31)
	REX_STORE_U32(ctx.r31.u32 + -9896, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8241d628
	if (ctx.cr6.eq) goto loc_8241D628;
loc_8241D624:
	// bl 0x8241a798
	ctx.lr = 0x8241D628;
	sub_8241A798(ctx, base);
loc_8241D628:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D630:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82591cb8
	ctx.lr = 0x8241D638;
	sub_82591CB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241d654
	if (!ctx.cr0.eq) goto loc_8241D654;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x8241d650
	goto loc_8241D650;
loc_8241D648:
	// bl 0x82591b58
	ctx.lr = 0x8241D64C;
	sub_82591B58(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_8241D650:
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_8241D654:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243C398) {
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
	// bl 0x8243c050
	ctx.lr = 0x8243C3BC;
	sub_8243C050(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,396(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x8243b110
	ctx.lr = 0x8243C3C8;
	sub_8243B110(ctx, base);
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
	// beq 0x8243c3ec
	if (ctx.cr0.eq) goto loc_8243C3EC;
	// lwz r11,492(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// b 0x8243c3f4
	goto loc_8243C3F4;
loc_8243C3EC:
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
loc_8243C3F4:
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
	// bl 0x8243ad20
	ctx.lr = 0x8243C420;
	sub_8243AD20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243a600
	ctx.lr = 0x8243C428;
	sub_8243A600(ctx, base);
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

DEFINE_REX_FUNC(sub_82441280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82441288;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,-9892(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + -9892);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x824412BC;
	sub_825FC4B0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244138c
	if (ctx.cr6.eq) goto loc_8244138C;
	// stfs f31,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82441314
	if (ctx.cr6.eq) goto loc_82441314;
	// addi r9,r31,148
	ctx.r9.s64 = ctx.r31.s64 + 148;
loc_824412F8:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82441398
	if (ctx.cr6.eq) goto loc_82441398;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,112
	ctx.r9.s64 = ctx.r9.s64 + 112;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824412f8
	if (ctx.cr6.lt) goto loc_824412F8;
loc_82441314:
	// lbz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 52);
	// addi r30,r31,24
	ctx.r30.s64 = ctx.r31.s64 + 24;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8244132c
	if (ctx.cr0.eq) goto loc_8244132C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82872dfc
	ctx.lr = 0x8244132C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8244132C:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bge cr6,0x82441378
	if (!ctx.cr6.lt) goto loc_82441378;
	// mulli r11,r11,112
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(112));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r29,148(r11)
	REX_STORE_U32(ctx.r11.u32 + 148, ctx.r29.u32);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// mulli r11,r11,112
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(112));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f31,152(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 152, temp.u32);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// mulli r11,r11,112
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(112));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r11,192
	ctx.r3.s64 = ctx.r11.s64 + 192;
	// bl 0x82393c08
	ctx.lr = 0x8244136C;
	sub_82393C08(ctx, base);
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
loc_82441378:
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8244138c
	if (ctx.cr0.eq) goto loc_8244138C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82441388:
	// bl 0x82872dec
	ctx.lr = 0x8244138C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8244138C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
loc_82441398:
	// lwz r11,-9892(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9892);
	// mulli r29,r10,112
	ctx.r29.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(112));
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r3,r11,160
	ctx.r3.s64 = ctx.r11.s64 + 160;
	// lbz r11,188(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 188);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824413b8
	if (ctx.cr0.eq) goto loc_824413B8;
	// bl 0x82872dfc
	ctx.lr = 0x824413B8;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_824413B8:
	// add r30,r29,r31
	ctx.r30.u64 = ctx.r29.u64 + ctx.r31.u64;
	// lfs f0,152(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x824413cc
	if (!ctx.cr6.lt) goto loc_824413CC;
	// stfs f31,152(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 152, temp.u32);
loc_824413CC:
	// addi r31,r30,192
	ctx.r31.s64 = ctx.r30.s64 + 192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82393c08
	ctx.lr = 0x824413DC;
	sub_82393C08(ctx, base);
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// ble cr6,0x82441450
	if (!ctx.cr6.gt) goto loc_82441450;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82441470
	ctx.lr = 0x824413F4;
	sub_82441470(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82441404
	if (ctx.cr6.eq) goto loc_82441404;
	// bl 0x825fc588
	ctx.lr = 0x82441404;
	sub_825FC588(ctx, base);
loc_82441404:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82441470
	ctx.lr = 0x82441410;
	sub_82441470(ctx, base);
	// stw r27,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82441450
	if (ctx.cr6.eq) goto loc_82441450;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82441440
	if (ctx.cr6.gt) goto loc_82441440;
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
loc_82441440:
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bne 0x82441450
	if (!ctx.cr0.eq) goto loc_82441450;
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
loc_82441450:
	// lwz r11,-9892(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9892);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r3,r11,160
	ctx.r3.s64 = ctx.r11.s64 + 160;
	// lbz r11,188(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 188);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8244138c
	if (ctx.cr0.eq) goto loc_8244138C;
	// b 0x82441388
	goto loc_82441388;
}

DEFINE_REX_FUNC(sub_82450C88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82450C90;
	__savegprlr_26(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450CAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82450f98
	if (!ctx.cr0.eq) goto loc_82450F98;
	// lwz r3,2340(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450CC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82450f98
	if (!ctx.cr0.eq) goto loc_82450F98;
	// lwz r3,2340(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,352(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 352);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450CE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82450f98
	if (ctx.cr0.eq) goto loc_82450F98;
	// lwz r3,2340(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1084(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1084);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450D00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,2364(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82450d18
	if (ctx.cr0.eq) goto loc_82450D18;
	// lwz r9,2368(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 2368);
	// lwz r11,2372(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2372);
	// b 0x82450d20
	goto loc_82450D20;
loc_82450D18:
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_82450D20:
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82450f98
	if (ctx.cr0.eq) goto loc_82450F98;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r8,5
	ctx.r8.s64 = 5;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r6,9
	ctx.r6.s64 = 9;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// li r4,10
	ctx.r4.s64 = 10;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// li r27,6
	ctx.r27.s64 = 6;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
loc_82450D90:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// and. r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 & ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82450db0
	if (!ctx.cr0.eq) goto loc_82450DB0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82450ddc
	if (!ctx.cr6.eq) goto loc_82450DDC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82450ddc
	if (!ctx.cr6.eq) goto loc_82450DDC;
loc_82450DB0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x82450dc8
	if (!ctx.cr6.eq) goto loc_82450DC8;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82450ddc
	goto loc_82450DDC;
loc_82450DC8:
	// lwz r6,2504(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 2504);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r6
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82450df0
	if (!ctx.cr6.eq) goto loc_82450DF0;
loc_82450DDC:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x82450d90
	if (ctx.cr6.lt) goto loc_82450D90;
	// b 0x82450dfc
	goto loc_82450DFC;
loc_82450DF0:
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwzx r27,r11,r10
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_82450DFC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82450e5c
	if (!ctx.cr6.eq) goto loc_82450E5C;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_82450E14:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82450e38
	if (ctx.cr6.eq) goto loc_82450E38;
	// lwz r8,2504(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 2504);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82450e38
	if (ctx.cr6.eq) goto loc_82450E38;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82450E38:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82450e14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82450E14;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82450f98
	if (!ctx.cr6.eq) goto loc_82450F98;
	// lwz r11,2504(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2504);
	// li r27,2
	ctx.r27.s64 = 2;
	// lwz r31,32(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82450f98
	if (ctx.cr6.eq) goto loc_82450F98;
loc_82450E5C:
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r10,18552
	ctx.r7.s64 = ctx.r10.s64 + 18552;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_82450E6C:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82450e8c
	if (ctx.cr6.lt) goto loc_82450E8C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82450e6c
	if (ctx.cr6.lt) goto loc_82450E6C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82450E8C:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r7,104
	ctx.r10.s64 = ctx.r7.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r28,r11,r10
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823c8be8
	ctx.lr = 0x82450EA0;
	sub_823C8BE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_82450EAC:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82450ecc
	if (ctx.cr6.lt) goto loc_82450ECC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82450eac
	if (ctx.cr6.lt) goto loc_82450EAC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82450ECC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823ca298
	ctx.lr = 0x82450ED8;
	sub_823CA298(ctx, base);
	// lwz r11,2340(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,144(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450EF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x82450f98
	if (ctx.cr6.lt) goto loc_82450F98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca4e0
	ctx.lr = 0x82450F18;
	sub_823CA4E0(ctx, base);
	// lwz r11,2340(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// li r9,13
	ctx.r9.s64 = 13;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,448(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 448);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450F48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82450f98
	if (ctx.cr0.eq) goto loc_82450F98;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82451610
	ctx.lr = 0x82450F58;
	sub_82451610(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r27,2736(r26)
	REX_STORE_U32(ctx.r26.u32 + 2736, ctx.r27.u32);
	// neg r11,r29
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r29.u64);
	// stw r10,2728(r26)
	REX_STORE_U32(ctx.r26.u32 + 2728, ctx.r10.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r3,2340(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 2340);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// lwz r11,148(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82450F90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82450f9c
	goto loc_82450F9C;
loc_82450F98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82450F9C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82465190) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824652a8
	if (ctx.cr6.eq) goto loc_824652A8;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824651CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82465290
	if (!ctx.cr0.eq) goto loc_82465290;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824651EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82465290
	if (!ctx.cr0.eq) goto loc_82465290;
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824652a8
	if (ctx.cr6.eq) goto loc_824652A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82465210;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824652a8
	if (!ctx.cr0.eq) goto loc_824652A8;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824652a8
	if (ctx.cr6.eq) goto loc_824652A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824648f8
	ctx.lr = 0x82465230;
	sub_824648F8(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1064(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1064);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8246524C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82465290
	if (ctx.cr0.eq) goto loc_82465290;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824652a8
	if (!ctx.cr6.eq) goto loc_824652A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824656d8
	ctx.lr = 0x82465268;
	sub_824656D8(ctx, base);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82465280;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,60(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// b 0x824652a8
	goto loc_824652A8;
loc_82465290:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824652A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824652A8:
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

DEFINE_REX_FUNC(sub_8246CCF8) {
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
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9868(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246cd4c
	if (!ctx.cr6.eq) goto loc_8246CD4C;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,92
	ctx.r4.s64 = 92;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x8246CD30;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8246cd44
	if (ctx.cr0.eq) goto loc_8246CD44;
	// bl 0x8246bb68
	ctx.lr = 0x8246CD3C;
	sub_8246BB68(ctx, base);
	// stw r3,-9868(r31)
	REX_STORE_U32(ctx.r31.u32 + -9868, ctx.r3.u32);
	// b 0x8246cd4c
	goto loc_8246CD4C;
loc_8246CD44:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-9868(r31)
	REX_STORE_U32(ctx.r31.u32 + -9868, ctx.r11.u32);
loc_8246CD4C:
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

DEFINE_REX_FUNC(sub_8246E7A0) {
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
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,-9848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e7e0
	if (ctx.cr6.eq) goto loc_8246E7E0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246e7e0
	if (ctx.cr6.eq) goto loc_8246E7E0;
	// li r6,58
	ctx.r6.s64 = 58;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8246d8e8
	ctx.lr = 0x8246E7DC;
	sub_8246D8E8(ctx, base);
	// b 0x8246e7e4
	goto loc_8246E7E4;
loc_8246E7E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246E7E4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246e7f4
	if (ctx.cr6.eq) goto loc_8246E7F4;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x8246e7f8
	goto loc_8246E7F8;
loc_8246E7F4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8246E7F8:
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82470C18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,-25540
	ctx.r5.s64 = ctx.r11.s64 + -25540;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827552a8
	ctx.lr = 0x82470C3C;
	sub_827552A8(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82470C44:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82470c44
	if (!ctx.cr6.eq) goto loc_82470C44;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r10,-12436(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -12436);
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x82470C74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82475C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82475C20;
	__savegprlr_24(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r9,44(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r24,-9796(r10)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r10.u32 + -9796);
	// ble cr6,0x82475c68
	if (!ctx.cr6.gt) goto loc_82475C68;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_82475C4C:
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82619bf0
	ctx.lr = 0x82475C54;
	sub_82619BF0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwu r3,8(r29)
	ea = 8 + ctx.r29.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r29.u32 = ea;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82475c4c
	if (ctx.cr6.lt) goto loc_82475C4C;
loc_82475C68:
	// lwz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82475ce0
	if (!ctx.cr6.gt) goto loc_82475CE0;
loc_82475C7C:
	// li r8,8
	ctx.r8.s64 = 8;
	// lwz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// addi r10,r11,160
	ctx.r10.s64 = ctx.r11.s64 + 160;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82475C94:
	// li r8,1
	ctx.r8.s64 = 1;
	// slw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// and. r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82475cbc
	if (ctx.cr0.eq) goto loc_82475CBC;
	// lhz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// lwz r8,96(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// rotlwi r6,r6,3
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_82475CBC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bdnz 0x82475c94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82475C94;
	// lwz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,320
	ctx.r11.s64 = ctx.r11.s64 + 320;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82475c7c
	if (ctx.cr6.lt) goto loc_82475C7C;
loc_82475CE0:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x826151c0
	ctx.lr = 0x82475CEC;
	sub_826151C0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82475d04
	if (ctx.cr0.eq) goto loc_82475D04;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82620f18
	ctx.lr = 0x82475CFC;
	sub_82620F18(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82475d08
	goto loc_82475D08;
loc_82475D04:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82475D08:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82475d18
	if (!ctx.cr6.eq) goto loc_82475D18;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82475e68
	goto loc_82475E68;
loc_82475D18:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82475d7c
	if (!ctx.cr6.gt) goto loc_82475D7C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r26,-32110
	ctx.r26.s64 = -2104360960;
	// addi r27,r11,-25416
	ctx.r27.s64 = ctx.r11.s64 + -25416;
loc_82475D3C:
	// lwz r11,-12436(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -12436);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82475D50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r30,r29,r11
	ctx.r30.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r11,r30,16
	ctx.r11.s64 = ctx.r30.s64 + 16;
	// bl 0x824732e0
	ctx.lr = 0x82475D60;
	sub_824732E0(ctx, base);
	// stw r3,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// addi r29,r29,320
	ctx.r29.s64 = ctx.r29.s64 + 320;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82475d3c
	if (ctx.cr6.lt) goto loc_82475D3C;
loc_82475D7C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
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
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827567d0
	ctx.lr = 0x82475DC4;
	sub_827567D0(ctx, base);
	// mulli r11,r25,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r25.u64 * static_cast<uint64_t>(20));
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82475df4
	if (!ctx.cr6.eq) goto loc_82475DF4;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82475e00
	goto loc_82475E00;
loc_82475DF4:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_82475E00:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r9,r11,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82475e64
	if (!ctx.cr6.lt) goto loc_82475E64;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,16(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,36(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// bne cr6,0x82475e38
	if (!ctx.cr6.eq) goto loc_82475E38;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82475e44
	goto loc_82475E44;
loc_82475E38:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_82475E44:
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82475e5c
	if (!ctx.cr6.lt) goto loc_82475E5C;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82475e64
	goto loc_82475E64;
loc_82475E5C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8261bff8
	ctx.lr = 0x82475E64;
	sub_8261BFF8(ctx, base);
loc_82475E64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82475E68:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248AF98) {
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
	// cmplwi cr6,r3,22
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 22, ctx.xer);
	// bgt cr6,0x8248b144
	if (ctx.cr6.gt) goto loc_8248B144;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-3936
	ctx.r12.s64 = ctx.r12.s64 + -3936;
	// lbzx r0,r12,r3
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r3.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32183
	ctx.r12.s64 = -2109145088;
	// nop
	// addi r12,r12,-20524
	ctx.r12.s64 = ctx.r12.s64 + -20524;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r3.u32) {
	case 0:
		goto loc_8248B088;
	case 1:
		goto loc_8248AFD4;
	case 2:
		goto loc_8248B0FC;
	case 3:
		goto loc_8248AFDC;
	case 4:
		goto loc_8248AFE4;
	case 5:
		goto loc_8248AFEC;
	case 6:
		goto loc_8248B090;
	case 7:
		goto loc_8248AFF4;
	case 8:
		goto loc_8248B098;
	case 9:
		goto loc_8248AFFC;
	case 10:
		goto loc_8248B004;
	case 11:
		goto loc_8248B020;
	case 12:
		goto loc_8248B03C;
	case 13:
		goto loc_8248B044;
	case 14:
		goto loc_8248B104;
	case 15:
		goto loc_8248B04C;
	case 16:
		goto loc_8248B054;
	case 17:
		goto loc_8248B05C;
	case 18:
		goto loc_8248B064;
	case 19:
		goto loc_8248B10C;
	case 20:
		goto loc_8248B114;
	case 21:
		goto loc_8248B11C;
	case 22:
		goto loc_8248B06C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8248AFD4:
	// bl 0x8257c688
	ctx.lr = 0x8248AFD8;
	sub_8257C688(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248AFDC:
	// bl 0x8257e198
	ctx.lr = 0x8248AFE0;
	sub_8257E198(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248AFE4:
	// bl 0x8249a3e8
	ctx.lr = 0x8248AFE8;
	sub_8249A3E8(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248AFEC:
	// bl 0x824aaf60
	ctx.lr = 0x8248AFF0;
	sub_824AAF60(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248AFF4:
	// bl 0x824cfb08
	ctx.lr = 0x8248AFF8;
	sub_824CFB08(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248AFFC:
	// bl 0x824f62a8
	ctx.lr = 0x8248B000;
	sub_824F62A8(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B004:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248b13c
	if (ctx.cr6.eq) goto loc_8248B13C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-10760
	ctx.r3.s64 = ctx.r11.s64 + -10760;
	// b 0x8248b134
	goto loc_8248B134;
loc_8248B020:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248b13c
	if (ctx.cr6.eq) goto loc_8248B13C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-17024
	ctx.r3.s64 = ctx.r11.s64 + -17024;
	// b 0x8248b134
	goto loc_8248B134;
loc_8248B03C:
	// bl 0x825034c0
	ctx.lr = 0x8248B040;
	sub_825034C0(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B044:
	// bl 0x824fd3e8
	ctx.lr = 0x8248B048;
	sub_824FD3E8(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B04C:
	// bl 0x824dab40
	ctx.lr = 0x8248B050;
	sub_824DAB40(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B054:
	// bl 0x824f0dd0
	ctx.lr = 0x8248B058;
	sub_824F0DD0(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B05C:
	// bl 0x825018c0
	ctx.lr = 0x8248B060;
	sub_825018C0(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B064:
	// bl 0x824d8480
	ctx.lr = 0x8248B068;
	sub_824D8480(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B06C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248b13c
	if (ctx.cr6.eq) goto loc_8248B13C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r3,r11,26528
	ctx.r3.s64 = ctx.r11.s64 + 26528;
	// b 0x8248b134
	goto loc_8248B134;
loc_8248B088:
	// bl 0x824c8520
	ctx.lr = 0x8248B08C;
	sub_824C8520(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B090:
	// bl 0x8250bfc0
	ctx.lr = 0x8248B094;
	sub_8250BFC0(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B098:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8248B0A8;
	sub_82371AF8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,5796
	ctx.r4.s64 = ctx.r11.s64 + 5796;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82484c30
	ctx.lr = 0x8248B0BC;
	sub_82484C30(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8248b0d0
	if (!ctx.cr6.lt) goto loc_8248B0D0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_8248B0D0:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248b0e8
	if (ctx.cr6.eq) goto loc_8248B0E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x8248B0E8;
	sub_82486F58(ctx, base);
loc_8248B0E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8248B0F8;
	sub_82371AF8(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B0FC:
	// bl 0x82506150
	ctx.lr = 0x8248B100;
	sub_82506150(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B104:
	// bl 0x824d6b70
	ctx.lr = 0x8248B108;
	sub_824D6B70(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B10C:
	// bl 0x824bea70
	ctx.lr = 0x8248B110;
	sub_824BEA70(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B114:
	// bl 0x82507790
	ctx.lr = 0x8248B118;
	sub_82507790(ctx, base);
	// b 0x8248b13c
	goto loc_8248B13C;
loc_8248B11C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9788(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248b13c
	if (ctx.cr6.eq) goto loc_8248B13C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-17568
	ctx.r3.s64 = ctx.r11.s64 + -17568;
loc_8248B134:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x8248B13C;
	sub_82486F58(ctx, base);
loc_8248B13C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8248b148
	goto loc_8248B148;
loc_8248B144:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8248B148:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82497F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82497F70;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,356(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 356);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824986ec
	if (ctx.cr6.lt) goto loc_824986EC;
	// beq cr6,0x82498668
	if (ctx.cr6.eq) goto loc_82498668;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x824982ec
	if (ctx.cr6.lt) goto loc_824982EC;
	// beq cr6,0x82498174
	if (ctx.cr6.eq) goto loc_82498174;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82497fb4
	if (ctx.cr6.lt) goto loc_82497FB4;
	// bne cr6,0x824988bc
	if (!ctx.cr6.eq) goto loc_824988BC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x824988bc
	goto loc_824988BC;
loc_82497FB4:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// li r28,0
	ctx.r28.s64 = 0;
	// stb r28,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r28.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82497fec
	if (!ctx.cr6.eq) goto loc_82497FEC;
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82497fec
	if (ctx.cr6.eq) goto loc_82497FEC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x82497FE0;
	sub_82232BA0(ctx, base);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// stb r28,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r28.u8);
	// stb r28,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r28.u8);
loc_82497FEC:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,-30232
	ctx.r10.s64 = ctx.r10.s64 + -30232;
	// addi r30,r11,-2512
	ctx.r30.s64 = ctx.r11.s64 + -2512;
	// lfs f13,2696(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2696);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82498018
	if (!ctx.cr6.lt) goto loc_82498018;
	// lfs f13,736(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 736);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f31,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f31.f64, ctx.f13.f64, -ctx.f0.f64)));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_82498018:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r11,14296
	ctx.r10.s64 = ctx.r11.s64 + 14296;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// lfs f12,-1812(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1812);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82498064
	if (ctx.cr6.lt) goto loc_82498064;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82498064:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82498084
	if (ctx.cr0.eq) goto loc_82498084;
	// lfs f0,-1808(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1808);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82498088
	goto loc_82498088;
loc_82498084:
	// lfs f0,-2044(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2044);
	ctx.f0.f64 = double(temp.f32);
loc_82498088:
	// fmuls f11,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfs f10,388(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,1168(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1168);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f13,-4416(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4416);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x824980b4
	if (ctx.cr6.lt) goto loc_824980B4;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x824980c0
	goto loc_824980C0;
loc_824980B4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824980c4
	if (!ctx.cr6.lt) goto loc_824980C4;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_824980C0:
	// stfs f0,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
loc_824980C4:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lfs f1,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824980E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lfs f12,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f31,f12
	ctx.f12.f64 = double(float(ctx.f31.f64 + ctx.f12.f64));
	// stfs f12,380(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// lfs f13,412(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,844(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 844);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r30,r10,-256
	ctx.xer.ca = ctx.r10.u32 <= 4294967040;
	ctx.r30.u64 = static_cast<uint64_t>(-256) - ctx.r10.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bctrl
	ctx.lr = 0x8249812C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,27980
	ctx.r11.s64 = ctx.r11.s64 + 27980;
	// lfs f0,-7176(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7176);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8249814c
	if (!ctx.cr6.gt) goto loc_8249814C;
	// li r30,-256
	ctx.r30.s64 = -256;
	// stb r26,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r26.u8);
loc_8249814C:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82498170;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824988bc
	goto loc_824988BC;
loc_82498174:
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824982bc
	if (ctx.cr6.lt) goto loc_824982BC;
	// bne cr6,0x824988bc
	if (!ctx.cr6.eq) goto loc_824988BC;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lfs f0,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
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
	ctx.lr = 0x824981A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// stb r10,262(r31)
	REX_STORE_U8(ctx.r31.u32 + 262, ctx.r10.u8);
	// lfs f0,2396(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2396);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lfs f0,388(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subfic r11,r10,255
	ctx.xer.ca = ctx.r10.u32 <= 255;
	ctx.r11.u64 = static_cast<uint64_t>(255) - ctx.r10.u64;
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// beq cr6,0x8249822c
	if (ctx.cr6.eq) goto loc_8249822C;
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8249822C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249822C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,14296
	ctx.r11.s64 = ctx.r11.s64 + 14296;
	// lfs f0,808(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 808);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x82498250
	if (ctx.cr6.gt) goto loc_82498250;
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// blt cr6,0x82498258
	if (ctx.cr6.lt) goto loc_82498258;
loc_82498250:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
loc_82498258:
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,27980(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27980);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// b 0x824988bc
	goto loc_824988BC;
loc_824982BC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,14296
	ctx.r11.s64 = ctx.r11.s64 + 14296;
	// addi r10,r10,-30232
	ctx.r10.s64 = ctx.r10.s64 + -30232;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 596);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,18404(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18404);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x824982DC;
	sub_825C0958(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f1,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// b 0x824988bc
	goto loc_824988BC;
loc_824982EC:
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lfs f0,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f0.f64 = double(temp.f32);
	// stb r26,347(r31)
	REX_STORE_U8(ctx.r31.u32 + 347, ctx.r26.u8);
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
	ctx.lr = 0x82498314;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lwz r9,412(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bne cr6,0x82498378
	if (!ctx.cr6.eq) goto loc_82498378;
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82498378
	if (ctx.cr6.eq) goto loc_82498378;
	// lwz r10,400(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82498378
	if (!ctx.cr6.eq) goto loc_82498378;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x82498364;
	sub_82232BA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82498378;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82498378:
	// addi r29,r31,68
	ctx.r29.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82454930
	ctx.lr = 0x82498388;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f0,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f13,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// addi r9,r9,-30000
	ctx.r9.s64 = ctx.r9.s64 + -30000;
	// lwz r10,400(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r11,14296
	ctx.r30.s64 = ctx.r11.s64 + 14296;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r11.u64);
	// beq cr6,0x82498568
	if (ctx.cr6.eq) goto loc_82498568;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,-1812(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1812);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82498468
	if (ctx.cr6.lt) goto loc_82498468;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82498468:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249847c
	if (ctx.cr0.eq) goto loc_8249847C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-30232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30232);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82498488
	goto loc_82498488;
loc_8249847C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82498568
	if (ctx.cr6.eq) goto loc_82498568;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
loc_82498488:
	// stfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82498568
	if (ctx.cr6.eq) goto loc_82498568;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// stb r28,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r28.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r28,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r28.u8);
	// bne cr6,0x824984f4
	if (!ctx.cr6.eq) goto loc_824984F4;
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x824984f4
	if (ctx.cr6.eq) goto loc_824984F4;
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x824984f4
	if (!ctx.cr6.eq) goto loc_824984F4;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ba0
	ctx.lr = 0x824984CC;
	sub_82232BA0(ctx, base);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r28,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r28.u8);
	// stb r28,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r28.u8);
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x822329c8
	ctx.lr = 0x824984E8;
	sub_822329C8(ctx, base);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_824984F4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// stb r26,262(r31)
	REX_STORE_U8(ctx.r31.u32 + 262, ctx.r26.u8);
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f0,2396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2396);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subfic r11,r10,255
	ctx.xer.ca = ctx.r10.u32 <= 255;
	ctx.r11.u64 = static_cast<uint64_t>(255) - ctx.r10.u64;
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// beq cr6,0x82498568
	if (ctx.cr6.eq) goto loc_82498568;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl
	ctx.lr = 0x82498568;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82498568:
	// lfs f13,808(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82498584
	if (ctx.cr6.gt) goto loc_82498584;
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// blt cr6,0x8249858c
	if (ctx.cr6.lt) goto loc_8249858C;
loc_82498584:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
loc_8249858C:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f13,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r10,-30304
	ctx.r10.s64 = ctx.r10.s64 + -30304;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f13,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// addi r6,r6,-30256
	ctx.r6.s64 = ctx.r6.s64 + -30256;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// b 0x824988bc
	goto loc_824988BC;
loc_82498668:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lfs f0,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
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
	ctx.lr = 0x82498688;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,409(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 409);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824986cc
	if (ctx.cr0.eq) goto loc_824986CC;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r3,87
	ctx.r3.s64 = 87;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x824986C4;
	sub_82250AD8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r11.u8);
loc_824986CC:
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x824988bc
	if (!ctx.cr6.gt) goto loc_824988BC;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// stw r10,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r10.u32);
	// b 0x824988bc
	goto loc_824988BC;
loc_824986EC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,364(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// lwz r9,368(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r29,r11,14296
	ctx.r29.s64 = ctx.r11.s64 + 14296;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// li r27,2
	ctx.r27.s64 = 2;
	// stb r26,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r26.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r26,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r26.u8);
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r9,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// lfs f31,-1812(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1812);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,380(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// bne cr6,0x82498878
	if (!ctx.cr6.eq) goto loc_82498878;
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r4,116
	ctx.r4.s64 = 116;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x82498750;
	sub_825FC4B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824987a8
	if (ctx.cr0.eq) goto loc_824987A8;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82498770;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,-11096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11096);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822509c0
	ctx.lr = 0x82498784;
	sub_822509C0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,6748
	ctx.r11.s64 = ctx.r11.s64 + 6748;
	// addi r10,r10,6808
	ctx.r10.s64 = ctx.r10.s64 + 6808;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r10,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// sth r28,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r28.u16);
	// b 0x824987b0
	goto loc_824987B0;
loc_824987A8:
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_824987B0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82498878
	if (ctx.cr6.eq) goto loc_82498878;
	// lis r11,0
	ctx.r11.s64 = 0;
	// sth r28,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r28.u16);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// ori r11,r11,65408
	ctx.r11.u64 = ctx.r11.u64 | 65408;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r11.u32);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824987E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// lfs f3,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-2044(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2044);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82233d28
	ctx.lr = 0x824987F4;
	sub_82233D28(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8249882c
	if (ctx.cr6.gt) goto loc_8249882C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8249882C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249883c
	if (ctx.cr0.eq) goto loc_8249883C;
	// stb r27,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r27.u8);
	// b 0x82498840
	goto loc_82498840;
loc_8249883C:
	// stb r28,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r28.u8);
loc_82498840:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x822328e8
	ctx.lr = 0x8249884C;
	sub_822328E8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82498878
	if (!ctx.cr6.eq) goto loc_82498878;
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
	ctx.lr = 0x82498878;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82498878:
	// lbz r11,409(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 409);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824988b8
	if (ctx.cr0.eq) goto loc_824988B8;
	// stb r26,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r26.u8);
	// li r3,87
	ctx.r3.s64 = 87;
	// stw r27,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r27.u32);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x824988B4;
	sub_82250AD8(ctx, base);
	// b 0x824988bc
	goto loc_824988BC;
loc_824988B8:
	// stw r26,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r26.u32);
loc_824988BC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F14C0) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-12160
	ctx.r11.s64 = ctx.r11.s64 + -12160;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x825c0668
	ctx.lr = 0x824F14E8;
	sub_825C0668(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2312
	ctx.r11.s64 = ctx.r11.s64 + -2312;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82483320
	ctx.lr = 0x824F14FC;
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

DEFINE_REX_FUNC(sub_824F45B0) {
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
	// lwz r11,408(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 408);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,-11776
	ctx.r10.s64 = ctx.r10.s64 + -11776;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ab0
	ctx.lr = 0x824F45E0;
	sub_82232AB0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f4600
	if (ctx.cr0.eq) goto loc_824F4600;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82232ba0
	ctx.lr = 0x824F45F8;
	sub_82232BA0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,65(r3)
	REX_STORE_U8(ctx.r3.u32 + 65, ctx.r11.u8);
loc_824F4600:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82483410
	ctx.lr = 0x824F4608;
	sub_82483410(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825c0668
	ctx.lr = 0x824F4610;
	sub_825C0668(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2312
	ctx.r11.s64 = ctx.r11.s64 + -2312;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82483320
	ctx.lr = 0x824F4624;
	sub_82483320(ctx, base);
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

DEFINE_REX_FUNC(sub_824F7588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr
	if (!ctx.cr0.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,380(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,12488
	ctx.r11.s64 = ctx.r11.s64 + 12488;
	// lfs f13,2616(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2616);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x824f75bc
	if (!ctx.cr6.lt) goto loc_824F75BC;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,-1404(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1404);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f1,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,380(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 380, temp.u32);
loc_824F75BC:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x824f75d4
	if (!ctx.cr6.gt) goto loc_824F75D4;
	// lfs f13,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// b 0x824f75d8
	goto loc_824F75D8;
loc_824F75D4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_824F75D8:
	// lfs f11,380(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 380);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// ble cr6,0x824f7610
	if (!ctx.cr6.gt) goto loc_824F7610;
	// addi r11,r11,-14136
	ctx.r11.s64 = ctx.r11.s64 + -14136;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lfs f12,-20004(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f1,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f12.f64, ctx.f0.f64)));
	// lfs f13,-17656(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17656);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824f762c
	if (!ctx.cr6.gt) goto loc_824F762C;
	// b 0x824f7628
	goto loc_824F7628;
loc_824F7610:
	// addi r10,r11,-14136
	ctx.r10.s64 = ctx.r11.s64 + -14136;
	// lfs f13,-14136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14136);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20004(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20004);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f1,f12,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f1.f64, ctx.f12.f64, -ctx.f0.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x824f762c
	if (!ctx.cr6.lt) goto loc_824F762C;
loc_824F7628:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_824F762C:
	// stfs f0,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_824FB318) {
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
	// bl 0x824fb370
	ctx.lr = 0x824FB338;
	sub_824FB370(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824fb350
	if (ctx.cr0.eq) goto loc_824FB350;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824fb350
	if (ctx.cr6.eq) goto loc_824FB350;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x824FB350;
	sub_825FC588(ctx, base);
loc_824FB350:
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

DEFINE_REX_FUNC(sub_824FC738) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824FC740;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,392(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 392);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824fc864
	if (ctx.cr0.eq) goto loc_824FC864;
	// ld r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f13,396(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 396);
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
	// lfs f12,400(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 400);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x82454930
	ctx.lr = 0x824FC814;
	sub_82454930(ctx, base);
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
	// stw r11,404(r29)
	REX_STORE_U32(ctx.r29.u32 + 404, ctx.r11.u32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// stw r11,408(r29)
	REX_STORE_U32(ctx.r29.u32 + 408, ctx.r11.u32);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x824FC860;
	sub_82250AD8(ctx, base);
	// stb r31,392(r29)
	REX_STORE_U8(ctx.r29.u32 + 392, ctx.r31.u8);
loc_824FC864:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,404(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 404);
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
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,408(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,-28688
	ctx.r10.s64 = ctx.r10.s64 + -28688;
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v62,v60,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x8232e528
	ctx.lr = 0x824FC950;
	sub_8232E528(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r11,-30528
	ctx.r11.s64 = ctx.r11.s64 + -30528;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lvx128 v6,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lfs f13,27980(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27980);
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
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824fcb50
	if (!ctx.cr6.gt) goto loc_824FCB50;
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
	// addi r10,r10,31616
	ctx.r10.s64 = ctx.r10.s64 + 31616;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// addi r10,r10,-27984
	ctx.r10.s64 = ctx.r10.s64 + -27984;
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v60
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_824FCB50:
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x8232e528
	ctx.lr = 0x824FCBE8;
	sub_8232E528(ctx, base);
	// lwz r11,216(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 216);
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
	ctx.lr = 0x824FCC18;
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8232e528
	ctx.lr = 0x824FCCA0;
	sub_8232E528(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8232e528
	ctx.lr = 0x824FCD2C;
	sub_8232E528(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// std r30,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r30.u64);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r9,4288
	ctx.r9.s64 = ctx.r9.s64 + 4288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r8.u32);
	// lwz r30,-9960(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// stw r9,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// std r10,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r10.u64);
	// beq cr6,0x824fcd88
	if (ctx.cr6.eq) goto loc_824FCD88;
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
	// bl 0x823c3150
	ctx.lr = 0x824FCD88;
	sub_823C3150(ctx, base);
loc_824FCD88:
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
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
	// ld r11,6272(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 6272);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,12484(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
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
	// beq cr6,0x824fce08
	if (ctx.cr6.eq) goto loc_824FCE08;
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
	// bl 0x823c5098
	ctx.lr = 0x824FCE08;
	sub_823C5098(ctx, base);
loc_824FCE08:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824fcfd8
	if (ctx.cr0.eq) goto loc_824FCFD8;
	// bl 0x8243f6d0
	ctx.lr = 0x824FCE14;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// beq 0x824fcf10
	if (ctx.cr0.eq) goto loc_824FCF10;
	// bl 0x82440e68
	ctx.lr = 0x824FCE28;
	sub_82440E68(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82441b00
	ctx.lr = 0x824FCE30;
	sub_82441B00(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824fcfd8
	if (!ctx.cr6.eq) goto loc_824FCFD8;
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x8245cd58
	ctx.lr = 0x824FCE4C;
	sub_8245CD58(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824fcfd8
	if (ctx.cr0.eq) goto loc_824FCFD8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82451df8
	ctx.lr = 0x824FCE5C;
	sub_82451DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lbz r11,2364(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824fce84
	if (!ctx.cr6.eq) goto loc_824FCE84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824fce98
	goto loc_824FCE98;
loc_824FCE84:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,584(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCE98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824FCE98:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCEB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCED0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r9,164(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 164);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824fcfd8
	if (!ctx.cr6.eq) goto loc_824FCFD8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824fcfd8
	if (ctx.cr6.eq) goto loc_824FCFD8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// b 0x824fcfd4
	goto loc_824FCFD4;
loc_824FCF10:
	// bl 0x8245cd58
	ctx.lr = 0x824FCF14;
	sub_8245CD58(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824fcfd8
	if (ctx.cr0.eq) goto loc_824FCFD8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82451df8
	ctx.lr = 0x824FCF24;
	sub_82451DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lbz r11,2364(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824fcf4c
	if (!ctx.cr6.eq) goto loc_824FCF4C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824fcf60
	goto loc_824FCF60;
loc_824FCF4C:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,584(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCF60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824FCF60:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCF7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824FCF98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824fcfd8
	if (!ctx.cr0.eq) goto loc_824FCFD8;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r9,164(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 164);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824fcfd8
	if (!ctx.cr6.eq) goto loc_824FCFD8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824fcfd8
	if (ctx.cr6.eq) goto loc_824FCFD8;
	// li r4,0
	ctx.r4.s64 = 0;
loc_824FCFD4:
	// bl 0x82262dc0
	ctx.lr = 0x824FCFD8;
	sub_82262DC0(ctx, base);
loc_824FCFD8:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254EC18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x8254EC20;
	__savegprlr_26(ctx, base);
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f29.u64);
	// stfd f30,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r10,1472
	ctx.r4.s64 = ctx.r10.s64 + 1472;
	// li r8,7
	ctx.r8.s64 = 7;
	// li r7,5
	ctx.r7.s64 = 5;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x8254EC60;
	sub_82534A18(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r30,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r30.u8);
	// addi r11,r11,2192
	ctx.r11.s64 = ctx.r11.s64 + 2192;
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r11,r31,376
	ctx.r11.s64 = ctx.r31.s64 + 376;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8254EC80:
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r10.u32);
	// stwu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8254ec80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8254EC80;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r26,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r26.u32);
	// addi r30,r31,412
	ctx.r30.s64 = ctx.r31.s64 + 412;
	// addi r29,r11,12252
	ctx.r29.s64 = ctx.r11.s64 + 12252;
	// li r27,2
	ctx.r27.s64 = 2;
	// lfs f29,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f29.f64 = double(temp.f32);
	// stfs f29,368(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// lfs f31,3052(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3052);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lfs f30,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_8254ECC4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c08c8
	ctx.lr = 0x8254ECD4;
	sub_825C08C8(ctx, base);
	// stw r3,-20(r30)
	REX_STORE_U32(ctx.r30.u32 + -20, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825c0958
	ctx.lr = 0x8254ECE8;
	sub_825C0958(ctx, base);
	// stfs f1,-12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + -12, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,1364(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1364);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x8254ECFC;
	sub_825C0958(ctx, base);
	// stfs f1,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + -4, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825c0958
	ctx.lr = 0x8254ED10;
	sub_825C0958(ctx, base);
	// stfsu f1,4(r30)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r30.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r30.u32 = ea;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8254ecc4
	if (!ctx.cr0.eq) goto loc_8254ECC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r26,347(r31)
	REX_STORE_U8(ctx.r31.u32 + 347, ctx.r26.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-80(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82554F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82554F08;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x82757b14
	ctx.lr = 0x82554F10;
	__savevmx_124(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
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
	ctx.lr = 0x82554F28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82555118
	if (!ctx.cr0.eq) goto loc_82555118;
	// lwz r11,492(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82555118
	if (!ctx.cr6.eq) goto loc_82555118;
	// lis r26,-32110
	ctx.r26.s64 = -2104360960;
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r3,-9960(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + -9960);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82554f78
	if (ctx.cr6.eq) goto loc_82554F78;
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
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c3150
	ctx.lr = 0x82554F74;
	sub_823C3150(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_82554F78:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,-30336
	ctx.r11.s64 = ctx.r11.s64 + -30336;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r10,4288
	ctx.r29.s64 = ctx.r10.s64 + 4288;
	// addi r27,r9,6272
	ctx.r27.s64 = ctx.r9.s64 + 6272;
	// lvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// vor128 v126,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// vor128 v125,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// addi r28,r11,4268
	ctx.r28.s64 = ctx.r11.s64 + 4268;
	// vor128 v124,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
loc_82554FAC:
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82554FCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r30,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// addi r5,r11,404
	ctx.r5.s64 = ctx.r11.s64 + 404;
	// bl 0x8232e528
	ctx.lr = 0x82554FE4;
	sub_8232E528(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lwz r11,-9960(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -9960);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r29,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r29.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r24,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r24.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v60,v124
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v124.f32)));
	// vsubfp128 v61,v61,v127
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v125
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v125.f32)));
	// lfs f0,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// vsubfp128 v63,v63,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v126.f32)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r10.u64);
	// std r11,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r11.u64);
	// beq cr6,0x82555104
	if (ctx.cr6.eq) goto loc_82555104;
	// lfs f0,272(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,159(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lfs f1,276(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823c4c40
	ctx.lr = 0x82555104;
	sub_823C4C40(ctx, base);
loc_82555104:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// stw r28,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r28.u32);
	// clrlwi r30,r11,24
	ctx.r30.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r30,6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 6, ctx.xer);
	// blt cr6,0x82554fac
	if (ctx.cr6.lt) goto loc_82554FAC;
loc_82555118:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x82757dac
	ctx.lr = 0x82555124;
	__restvmx_124(ctx, base);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825668F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x825668F8;
	__savegprlr_26(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
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
	ctx.lr = 0x82566910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82566c08
	if (!ctx.cr0.eq) goto loc_82566C08;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12484
	ctx.r11.s64 = ctx.r11.s64 + 12484;
	// lwz r10,-9800(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9800);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f0,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x8256693c
	if (ctx.cr6.eq) goto loc_8256693C;
	// lfs f13,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82566940
	goto loc_82566940;
loc_8256693C:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f0.f64;
loc_82566940:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// fdivs f11,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f12,1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1908);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r10,-12360(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12360);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r11,-12372(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -12372);
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
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f10,44(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// lwz r29,408(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// lfs f9,48(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// lwz r9,412(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 412);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v7,v56,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v4,v55,v58
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v8,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// stvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v6,v57,v58
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v30,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v2,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfd f8,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// vspltw128 v9,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// lfd f7,96(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vmaddfp v1,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddfp v31,v8,v0,v7
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v7,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vmaddfp v4,v3,v0,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v0,v5,v0,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// frsp f8,f8
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// frsp f7,f7
	ctx.f7.f64 = double(float(ctx.f7.f64));
	// vmaddfp v1,v30,v13,v1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v2,v2,v13,v31
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v7,v7,v13,v4
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// fmuls f8,f8,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f11,f7,f11
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// vmaddfp v8,v8,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fnmsubs f10,f8,f12,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f12.f64, -ctx.f10.f64)));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmsubs f12,f11,f12,f9
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f12.f64, -ctx.f9.f64)));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v9,v0,v1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v10,v10,v0,v2
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v13,v11,v0,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v0,v12,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stvx128 v9,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82566c08
	if (ctx.cr6.eq) goto loc_82566C08;
	// stfs f13,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r27,-32109
	ctx.r27.s64 = -2104295424;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r26,-32109
	ctx.r26.s64 = -2104295424;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
loc_82566ABC:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x826151c0
	ctx.lr = 0x82566AC8;
	sub_826151C0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82566af0
	if (ctx.cr0.eq) goto loc_82566AF0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82615010
	ctx.lr = 0x82566AD8;
	sub_82615010(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82615080
	ctx.lr = 0x82566AEC;
	sub_82615080(ctx, base);
	// b 0x82566af4
	goto loc_82566AF4;
loc_82566AF0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82566AF4:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,396(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,392(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r11,40
	ctx.r10.s64 = ctx.r11.s64 + 40;
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r6,12(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// lwz r8,400(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// stw r8,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r8.u32);
loc_82566B3C:
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// bne 0x82566b3c
	if (!ctx.cr0.eq) goto loc_82566B3C;
	// lwz r11,388(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 388);
	// lfs f0,-7164(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4928(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -4928);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r11,7008(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 7008);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x827567d0
	ctx.lr = 0x82566BEC;
	sub_827567D0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82472dc8
	ctx.lr = 0x82566BFC;
	sub_82472DC8(ctx, base);
	// lwz r11,412(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 412);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82566abc
	if (!ctx.cr6.eq) goto loc_82566ABC;
loc_82566C08:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82580C98) {
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
	// addi r4,r11,12088
	ctx.r4.s64 = ctx.r11.s64 + 12088;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82483720
	ctx.lr = 0x82580CBC;
	sub_82483720(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82580cd0
	if (!ctx.cr0.eq) goto loc_82580CD0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82580cdc
	goto loc_82580CDC;
loc_82580CD0:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
loc_82580CDC:
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

DEFINE_REX_FUNC(sub_82583438) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x82583440;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,29
	ctx.r7.s64 = 29;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x82583474;
	sub_82534A18(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r9,r11,-30000
	ctx.r9.s64 = ctx.r11.s64 + -30000;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r11,12252
	ctx.r29.s64 = ctx.r11.s64 + 12252;
	// addi r11,r5,12576
	ctx.r11.s64 = ctx.r5.s64 + 12576;
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stfs f11,384(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// lfs f0,232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,396(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stfs f12,392(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stb r30,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r30.u8);
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stfs f0,404(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 404, temp.u32);
	// bl 0x825c0558
	ctx.lr = 0x825834F4;
	sub_825C0558(ctx, base);
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// lwz r11,-9744(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9744);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825c07c8
	ctx.lr = 0x82583510;
	sub_825C07C8(ctx, base);
	// addic r11,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// subfe r11,r11,r28
	temp.u8 = (~ctx.r11.u32 + ctx.r28.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r28.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r28.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f13,376(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// clrlwi. r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r11,372(r31)
	REX_STORE_U8(ctx.r31.u32 + 372, ctx.r11.u8);
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwimi r11,r10,0,30,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r28,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r28.u32);
	// ori r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 | 32;
	// stb r28,380(r31)
	REX_STORE_U8(ctx.r31.u32 + 380, ctx.r28.u8);
	// rlwimi r11,r10,0,26,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// beq 0x82583560
	if (ctx.cr0.eq) goto loc_82583560;
	// lfs f31,236(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 236);
	ctx.f31.f64 = double(temp.f32);
	// b 0x82583564
	goto loc_82583564;
loc_82583560:
	// lfs f31,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
loc_82583564:
	// lwz r11,-9744(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9744);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// lwz r9,164(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
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
	// bne cr6,0x82583674
	if (!ctx.cr6.eq) goto loc_82583674;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82583674
	if (ctx.cr6.eq) goto loc_82583674;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82583674
	if (ctx.cr0.eq) goto loc_82583674;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825835d0
	if (ctx.cr6.eq) goto loc_825835D0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825835C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x825835d0
	if (!ctx.cr6.eq) goto loc_825835D0;
	// li r27,1
	ctx.r27.s64 = 1;
loc_825835D0:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,992(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 992);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825835EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bne cr6,0x82583628
	if (!ctx.cr6.eq) goto loc_82583628;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82583628:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82583674
	if (ctx.cr0.eq) goto loc_82583674;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bne cr6,0x82583668
	if (!ctx.cr6.eq) goto loc_82583668;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82583668:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82583674
	if (ctx.cr0.eq) goto loc_82583674;
	// li r26,1
	ctx.r26.s64 = 1;
loc_82583674:
	// lfs f0,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82583748
	if (!ctx.cr0.eq) goto loc_82583748;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-27824
	ctx.r11.s64 = ctx.r11.s64 + -27824;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f0,17704(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17704);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmuls f11,f31,f0
	ctx.f11.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f11,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82583804
	goto loc_82583804;
loc_82583748:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r6,-27824
	ctx.r6.s64 = ctx.r6.s64 + -27824;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82583804:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// clrlwi. r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8258382c
	if (!ctx.cr0.eq) goto loc_8258382C;
	// stfs f13,400(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// b 0x82583838
	goto loc_82583838;
loc_8258382C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,9164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9164);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
loc_82583838:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r28,347(r31)
	REX_STORE_U8(ctx.r31.u32 + 347, ctx.r28.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A79A0) {
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
	// bl 0x825a79f8
	ctx.lr = 0x825A79C0;
	sub_825A79F8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a79d8
	if (ctx.cr0.eq) goto loc_825A79D8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825a79d8
	if (ctx.cr6.eq) goto loc_825A79D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x825A79D8;
	sub_825FC588(ctx, base);
loc_825A79D8:
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

DEFINE_REX_FUNC(sub_825A88A0) {
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
	// lbz r11,648(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 648);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825a88dc
	if (!ctx.cr0.eq) goto loc_825A88DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825A88D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,648(r31)
	REX_STORE_U8(ctx.r31.u32 + 648, ctx.r11.u8);
	// b 0x825a8920
	goto loc_825A8920;
loc_825A88DC:
	// lbz r11,649(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 649);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825a88f0
	if (!ctx.cr0.eq) goto loc_825A88F0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,649(r31)
	REX_STORE_U8(ctx.r31.u32 + 649, ctx.r11.u8);
loc_825A88F0:
	// lbz r11,649(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 649);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a8920
	if (ctx.cr0.eq) goto loc_825A8920;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x825a8920
	if (!ctx.cr6.gt) goto loc_825A8920;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825A8920;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A8920:
	// lbz r3,650(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 650);
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

DEFINE_REX_FUNC(sub_825AE848) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x825ada70
	ctx.lr = 0x825AE85C;
	sub_825ADA70(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825B0918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x825B0920;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r31,r3,12
	ctx.r31.s64 = ctx.r3.s64 + 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,16(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825b098c
	if (ctx.cr0.eq) goto loc_825B098C;
	// li r30,0
	ctx.r30.s64 = 0;
loc_825B094C:
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825B0964;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825b098c
	if (!ctx.cr0.eq) goto loc_825B098C;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825b094c
	if (ctx.cr6.lt) goto loc_825B094C;
loc_825B098C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825b099c
	if (ctx.cr0.eq) goto loc_825B099C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x825b09b8
	goto loc_825B09B8;
loc_825B099C:
	// lwz r11,312(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 312);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b09ac
	if (ctx.cr6.eq) goto loc_825B09AC;
	// bl 0x82591728
	ctx.lr = 0x825B09AC;
	sub_82591728(ctx, base);
loc_825B09AC:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_825B09B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B5EF8) {
	REX_FUNC_PROLOGUE();
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825b5f2c
	if (ctx.cr6.eq) goto loc_825B5F2C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_825B5F2C:
	// addi r11,r4,16
	ctx.r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825b5f4c
	if (ctx.cr6.eq) goto loc_825B5F4C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_825B5F4C:
	// addi r11,r4,20
	ctx.r11.s64 = ctx.r4.s64 + 20;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825b5f6c
	if (ctx.cr6.eq) goto loc_825B5F6C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_825B5F6C:
	// addi r11,r4,24
	ctx.r11.s64 = ctx.r4.s64 + 24;
	// addi r10,r3,24
	ctx.r10.s64 = ctx.r3.s64 + 24;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825b5f8c
	if (ctx.cr6.eq) goto loc_825B5F8C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_825B5F8C:
	// addi r11,r4,28
	ctx.r11.s64 = ctx.r4.s64 + 28;
	// addi r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 + 28;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825BA000) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r8,r11,13756
	ctx.r8.s64 = ctx.r11.s64 + 13756;
	// addi r11,r8,-12
	ctx.r11.s64 = ctx.r8.s64 + -12;
loc_825BA010:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// beq 0x825ba034
	if (ctx.cr0.eq) goto loc_825BA034;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ba010
	if (ctx.cr6.eq) goto loc_825BA010;
loc_825BA034:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x825ba044
	if (!ctx.cr0.eq) goto loc_825BA044;
loc_825BA03C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr
	return;
loc_825BA044:
	// addi r11,r8,-8
	ctx.r11.s64 = ctx.r8.s64 + -8;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_825BA04C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// beq 0x825ba070
	if (ctx.cr0.eq) goto loc_825BA070;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ba04c
	if (ctx.cr6.eq) goto loc_825BA04C;
loc_825BA070:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x825ba03c
	if (ctx.cr0.eq) goto loc_825BA03C;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_825BA080:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq 0x825ba0a4
	if (ctx.cr0.eq) goto loc_825BA0A4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ba080
	if (ctx.cr6.eq) goto loc_825BA080;
loc_825BA0A4:
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825BED60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x825BED68;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825beedc
	if (ctx.cr0.eq) goto loc_825BEEDC;
	// lwz r10,200(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x825bee14
	goto loc_825BEE14;
loc_825BEDA8:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bne cr6,0x825bedc0
	if (!ctx.cr6.eq) goto loc_825BEDC0;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x825bedcc
	goto loc_825BEDCC;
loc_825BEDC0:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// subf r11,r28,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r28.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_825BEDCC:
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x825bedec
	if (!ctx.cr6.lt) goto loc_825BEDEC;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// b 0x825bee04
	goto loc_825BEE04;
loc_825BEDEC:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825c9368
	ctx.lr = 0x825BEDFC;
	sub_825C9368(ctx, base);
	// lwz r27,104(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_825BEE04:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825b65c0
	ctx.lr = 0x825BEE0C;
	sub_825B65C0(ctx, base);
	// lwz r10,200(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_825BEE14:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825beda8
	if (!ctx.cr6.eq) goto loc_825BEDA8;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x825beec8
	if (ctx.cr6.eq) goto loc_825BEEC8;
loc_825BEE28:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825beebc
	if (!ctx.cr6.eq) goto loc_825BEEBC;
	// lwz r3,4(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825beebc
	if (ctx.cr6.eq) goto loc_825BEEBC;
	// rlwinm r11,r11,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
loc_825BEE5C:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825bee5c
	if (!ctx.cr0.eq) goto loc_825BEE5C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825BEE8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,2(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 2);
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// rotlwi r11,r11,4
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 4);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
loc_825BEEA0:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825beea0
	if (!ctx.cr0.eq) goto loc_825BEEA0;
loc_825BEEBC:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x825bee28
	if (!ctx.cr6.eq) goto loc_825BEE28;
loc_825BEEC8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x825bef70
	if (ctx.cr6.eq) goto loc_825BEF70;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825fc588
	ctx.lr = 0x825BEED8;
	sub_825FC588(ctx, base);
	// b 0x825bef70
	goto loc_825BEF70;
loc_825BEEDC:
	// lwz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825bef70
	if (!ctx.cr6.eq) goto loc_825BEF70;
	// lwz r3,4(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825bef70
	if (ctx.cr6.eq) goto loc_825BEF70;
	// rlwinm r11,r11,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
loc_825BEF10:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825bef10
	if (!ctx.cr0.eq) goto loc_825BEF10;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825BEF40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,14(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 14);
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// rotlwi r11,r11,4
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 4);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
loc_825BEF54:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825bef54
	if (!ctx.cr0.eq) goto loc_825BEF54;
loc_825BEF70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D2190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x825D2198;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r27,r3,204
	ctx.r27.s64 = ctx.r3.s64 + 204;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x82872dfc
	ctx.lr = 0x825D21B4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// addi r29,r31,188
	ctx.r29.s64 = ctx.r31.s64 + 188;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x825d2224
	if (ctx.cr6.eq) goto loc_825D2224;
loc_825D21C4:
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825d21e0
	if (ctx.cr6.eq) goto loc_825D21E0;
	// lwz r10,308(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 308);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825d2218
	if (!ctx.cr6.eq) goto loc_825D2218;
loc_825D21E0:
	// clrlwi r10,r28,16
	ctx.r10.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x825d21f8
	if (ctx.cr6.eq) goto loc_825D21F8;
	// lhz r9,316(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 316);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825d2218
	if (!ctx.cr6.eq) goto loc_825D2218;
loc_825D21F8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d2218
	if (ctx.cr6.eq) goto loc_825D2218;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl
	ctx.lr = 0x825D2218;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D2218:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x825d21c4
	if (!ctx.cr6.eq) goto loc_825D21C4;
loc_825D2224:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82872dec
	ctx.lr = 0x825D222C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D5D68) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// b 0x825d2b98
	sub_825D2B98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D5E50) {
	REX_FUNC_PROLOGUE();
	// lwz r3,348(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 348);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825D60E0) {
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
	// bl 0x825d6138
	ctx.lr = 0x825D6100;
	sub_825D6138(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d6120
	if (ctx.cr6.eq) goto loc_825D6120;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32869
	ctx.r4.u64 = ctx.r4.u64 | 32869;
	// bl 0x82657b88
	ctx.lr = 0x825D611C;
	sub_82657B88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825D6120:
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

DEFINE_REX_FUNC(sub_825D7F30) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D7F54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_825D8C40) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// b 0x825d2b98
	sub_825D2B98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D93A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x825D93B0;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r23,r11,204
	ctx.r23.s64 = ctx.r11.s64 + 204;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// bl 0x82872dfc
	ctx.lr = 0x825D93D8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x825cf548
	ctx.lr = 0x825D93E0;
	sub_825CF548(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825d940c
	if (ctx.cr6.lt) goto loc_825D940C;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge cr6,0x825d9400
	if (!ctx.cr6.lt) goto loc_825D9400;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,87
	ctx.r30.u64 = ctx.r30.u64 | 87;
	// b 0x825d940c
	goto loc_825D940C;
loc_825D9400:
	// clrlwi r28,r29,16
	ctx.r28.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r28,65535
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 65535, ctx.xer);
	// beq cr6,0x825d9424
	if (ctx.cr6.eq) goto loc_825D9424;
loc_825D940C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r28,r29,16
	ctx.r28.u64 = ctx.r29.u32 & 0xFFFF;
	// bl 0x825d8d40
	ctx.lr = 0x825D9418;
	sub_825D8D40(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825d942c
	if (ctx.cr6.lt) goto loc_825D942C;
loc_825D9424:
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,12
	ctx.r30.u64 = ctx.r30.u64 | 12;
loc_825D942C:
	// cntlzw r11,r24
	ctx.r11.u64 = ctx.r24.u32 == 0 ? 32 : __builtin_clz(ctx.r24.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// rlwinm r27,r11,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blt cr6,0x825d94dc
	if (ctx.cr6.lt) goto loc_825D94DC;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x825d947c
	if (ctx.cr6.eq) goto loc_825D947C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D945C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r8,r9,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x825d9478
	if (ctx.cr6.eq) goto loc_825D9478;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,6
	ctx.r30.u64 = ctx.r30.u64 | 6;
	// b 0x825d94dc
	goto loc_825D94DC;
loc_825D9478:
	// li r30,0
	ctx.r30.s64 = 0;
loc_825D947C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D9494;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x825d94dc
	if (ctx.cr6.eq) goto loc_825D94DC;
	// lbz r11,9(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// beq cr6,0x825d94dc
	if (ctx.cr6.eq) goto loc_825D94DC;
	// lwz r10,252(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x825d94dc
	if (ctx.cr6.lt) goto loc_825D94DC;
	// lbz r11,14(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 14);
	// rlwinm r10,r11,0,26,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x38;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825d94dc
	if (!ctx.cr6.eq) goto loc_825D94DC;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,8
	ctx.r30.u64 = ctx.r30.u64 | 8;
loc_825D94DC:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// blt cr6,0x825d9580
	if (ctx.cr6.lt) goto loc_825D9580;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D9510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825d9564
	if (ctx.cr6.lt) goto loc_825D9564;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D9534;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825d9564
	if (ctx.cr6.lt) goto loc_825D9564;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x825d9580
	if (ctx.cr6.eq) goto loc_825D9580;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// bl 0x82872dec
	ctx.lr = 0x825D9558;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_825D9564:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d9580
	if (ctx.cr6.eq) goto loc_825D9580;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825D9580;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D9580:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82872dec
	ctx.lr = 0x825D9588;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E6DA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// ori r6,r10,65535
	ctx.r6.u64 = ctx.r10.u64 | 65535;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825e6e58
	if (ctx.cr6.eq) goto loc_825E6E58;
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825e6e50
	if (!ctx.cr6.eq) goto loc_825E6E50;
	// lwz r10,312(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r30,40(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r3,r9,16
	ctx.r3.u64 = ctx.r9.u32 & 0xFFFF;
loc_825E6DEC:
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x825e6e58
	if (!ctx.cr6.lt) goto loc_825E6E58;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,6
	ctx.r10.s64 = 6;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r8,r1,-33
	ctx.r8.s64 = ctx.r1.s64 + -33;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r9,7
	ctx.r10.s64 = ctx.r9.s64 + 7;
loc_825E6E18:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r9,1(r8)
	ea = 1 + ctx.r8.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x825e6e18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825E6E18;
	// lwz r10,-32(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -32);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825e6e38
	if (!ctx.cr6.eq) goto loc_825E6E38;
	// lbz r31,-27(r1)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r1.u32 + -27);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_825E6E38:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x825e6dec
	if (ctx.cr6.eq) goto loc_825E6DEC;
	// b 0x825e6e58
	goto loc_825E6E58;
loc_825E6E50:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r31,255
	ctx.r31.s64 = 255;
loc_825E6E58:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// sth r6,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r6.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r31,2(r4)
	REX_STORE_U8(ctx.r4.u32 + 2, ctx.r31.u8);
	// stw r10,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r10.u32);
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825EDFC0) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,20844
	ctx.r9.s64 = ctx.r11.s64 + 20844;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x825edffc
	if (ctx.cr6.eq) goto loc_825EDFFC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x82657b88
	ctx.lr = 0x825EDFF8;
	sub_82657B88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825EDFFC:
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

DEFINE_REX_FUNC(sub_825F45E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x825F45F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f50fc
	if (ctx.cr6.eq) goto loc_825F50FC;
	// lwz r31,28(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825f50fc
	if (ctx.cr6.eq) goto loc_825F50FC;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f50f0
	if (ctx.cr6.eq) goto loc_825F50F0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f4630
	if (!ctx.cr6.eq) goto loc_825F4630;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f50f0
	if (!ctx.cr6.eq) goto loc_825F50F0;
loc_825F4630:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f4650
	if (!ctx.cr6.eq) goto loc_825F4650;
loc_825F463C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r3,-5
	ctx.r3.s64 = -5;
	// addi r11,r11,25316
	ctx.r11.s64 = ctx.r11.s64 + 25316;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// b 0x825f5100
	goto loc_825F5100;
loc_825F4650:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r27,113
	ctx.r27.s64 = 113;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r7,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// cmpwi cr6,r11,42
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 42, ctx.xer);
	// bne cr6,0x825f4aa0
	if (!ctx.cr6.eq) goto loc_825F4AA0;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x825f496c
	if (!ctx.cr6.eq) goto loc_825F496C;
	// stw r28,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r28.u32);
	// li r11,31
	ctx.r11.s64 = 31;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r9,139
	ctx.r9.s64 = 139;
	// lwz r6,8(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,8
	ctx.r8.s64 = 8;
	// stbx r11,r10,r6
	REX_STORE_U8(ctx.r10.u32 + ctx.r6.u32, ctx.r11.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r8,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// bne cr6,0x825f47a0
	if (!ctx.cr6.eq) goto loc_825F47A0;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stbx r28,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r28.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r28,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u8);
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9, ctx.xer);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bne cr6,0x825f4750
	if (!ctx.cr6.eq) goto loc_825F4750;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x825f476c
	goto loc_825F476C;
loc_825F4750:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bge cr6,0x825f4768
	if (!ctx.cr6.lt) goto loc_825F4768;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// bge cr6,0x825f476c
	if (!ctx.cr6.lt) goto loc_825F476C;
loc_825F4768:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_825F476C:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,11
	ctx.r8.s64 = 11;
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r8,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x825f4aa0
	goto loc_825F4AA0;
loc_825F47A0:
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// li r6,16
	ctx.r6.s64 = 16;
	// lwz r5,44(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// li r4,2
	ctx.r4.s64 = 2;
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// lwz r3,28(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r29,16(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r26,0(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r11,r5,0
	ctx.xer.ca = ctx.r5.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r5.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// and r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 & ctx.r6.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r6.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// subfe r6,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r4,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r4.u64 = static_cast<uint64_t>(0) - ctx.r29.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// and r11,r6,r8
	ctx.r11.u64 = ctx.r6.u64 & ctx.r8.u64;
	// subfe r8,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// and r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 & ctx.r7.u64;
	// addic r8,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r8.s64 = ctx.r26.s64 + -1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subfe r11,r8,r26
	temp.u8 = (~ctx.r8.u32 + ctx.r26.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r26.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r8.u64 + ctx.r26.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stbx r11,r10,r5
	REX_STORE_U8(ctx.r10.u32 + ctx.r5.u32, ctx.r11.u8);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r10,6(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r10,5(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9, ctx.xer);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bne cr6,0x825f489c
	if (!ctx.cr6.eq) goto loc_825F489C;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x825f48b8
	goto loc_825F48B8;
loc_825F489C:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bge cr6,0x825f48b4
	if (!ctx.cr6.lt) goto loc_825F48B4;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// bge cr6,0x825f48b8
	if (!ctx.cr6.lt) goto loc_825F48B8;
loc_825F48B4:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_825F48B8:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r5,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825f492c
	if (ctx.cr6.eq) goto loc_825F492C;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stbx r11,r5,r10
	REX_STORE_U8(ctx.r5.u32 + ctx.r10.u32, ctx.r11.u8);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,22(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 22);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r5,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
loc_825F492C:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825f495c
	if (ctx.cr6.eq) goto loc_825F495C;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x825f4954
	if (!ctx.cr6.eq) goto loc_825F4954;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4958
	goto loc_825F4958;
loc_825F4954:
	// bl 0x825f6f10
	ctx.lr = 0x825F4958;
	sub_825F6F10(ctx, base);
loc_825F4958:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F495C:
	// li r11,69
	ctx.r11.s64 = 69;
	// stw r28,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x825f4aa0
	goto loc_825F4AA0;
loc_825F496C:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// rlwinm r11,r11,12,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFFFF000;
	// addi r10,r11,2048
	ctx.r10.s64 = ctx.r11.s64 + 2048;
	// bge cr6,0x825f49bc
	if (!ctx.cr6.lt) goto loc_825F49BC;
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x825f49bc
	if (ctx.cr6.lt) goto loc_825F49BC;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x825f49a4
	if (!ctx.cr6.lt) goto loc_825F49A4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x825f49c0
	goto loc_825F49C0;
loc_825F49A4:
	// addi r11,r11,-6
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x825f49c0
	goto loc_825F49C0;
loc_825F49BC:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_825F49C0:
	// lwz r9,108(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825f49d8
	if (ctx.cr6.eq) goto loc_825F49D8;
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
loc_825F49D8:
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// divwu r10,r11,r10
	ctx.r10.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// mulli r10,r10,31
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(31));
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r11,r11,31
	ctx.r11.s64 = ctx.r11.s64 + 31;
	// rlwinm r10,r11,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stbx r10,r9,r8
	REX_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r7,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r7.u8);
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// beq cr6,0x825f4a98
	if (ctx.cr6.eq) goto loc_825F4A98;
	// lhz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 48);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r8,r10,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// stbx r8,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r8.u8);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lhz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 50);
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// stbx r8,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_825F4A98:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r11.u32);
loc_825F4AA0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// bne cr6,0x825f4bd4
	if (!ctx.cr6.eq) goto loc_825F4BD4;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825f4bcc
	if (ctx.cr6.eq) goto loc_825F4BCC;
	// lhz r10,22(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 22);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// b 0x825f4b68
	goto loc_825F4B68;
loc_825F4AC8:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825f4b30
	if (!ctx.cr6.eq) goto loc_825F4B30;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,44(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825f4b14
	if (ctx.cr6.eq) goto loc_825F4B14;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4b14
	if (!ctx.cr6.gt) goto loc_825F4B14;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4b0c
	if (!ctx.cr0.eq) goto loc_825F4B0C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4b10
	goto loc_825F4B10;
loc_825F4B0C:
	// bl 0x825f6f10
	ctx.lr = 0x825F4B10;
	sub_825F6F10(ctx, base);
loc_825F4B10:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4B14:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4B1C;
	sub_825F4528(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825f4b74
	if (ctx.cr6.eq) goto loc_825F4B74;
loc_825F4B30:
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,8(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,16(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lbzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// stbx r9,r7,r10
	REX_STORE_U8(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lhz r10,22(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 22);
loc_825F4B68:
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825f4ac8
	if (ctx.cr6.lt) goto loc_825F4AC8;
loc_825F4B74:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,44(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825f4bb4
	if (ctx.cr6.eq) goto loc_825F4BB4;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4bb4
	if (!ctx.cr6.gt) goto loc_825F4BB4;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4bac
	if (!ctx.cr0.eq) goto loc_825F4BAC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4bb0
	goto loc_825F4BB0;
loc_825F4BAC:
	// bl 0x825f6f10
	ctx.lr = 0x825F4BB0;
	sub_825F6F10(ctx, base);
loc_825F4BB0:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4BB4:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825f4bd4
	if (!ctx.cr6.eq) goto loc_825F4BD4;
	// stw r28,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
loc_825F4BCC:
	// li r11,73
	ctx.r11.s64 = 73;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_825F4BD4:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,73
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 73, ctx.xer);
	// bne cr6,0x825f4cec
	if (!ctx.cr6.eq) goto loc_825F4CEC;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f4ce4
	if (ctx.cr6.eq) goto loc_825F4CE4;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
loc_825F4BF4:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825f4c5c
	if (!ctx.cr6.eq) goto loc_825F4C5C;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,44(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825f4c40
	if (ctx.cr6.eq) goto loc_825F4C40;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4c40
	if (!ctx.cr6.gt) goto loc_825F4C40;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4c38
	if (!ctx.cr0.eq) goto loc_825F4C38;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4c3c
	goto loc_825F4C3C;
loc_825F4C38:
	// bl 0x825f6f10
	ctx.lr = 0x825F4C3C;
	sub_825F6F10(ctx, base);
loc_825F4C3C:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4C40:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4C48;
	sub_825F4528(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825f4c94
	if (ctx.cr6.eq) goto loc_825F4C94;
loc_825F4C5C:
	// lwz r8,28(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,8(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r8,28(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// lbzx r29,r8,r9
	ctx.r29.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// cmpwi r29,0
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stbx r29,r7,r10
	REX_STORE_U8(ctx.r7.u32 + ctx.r10.u32, ctx.r29.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// bne 0x825f4bf4
	if (!ctx.cr0.eq) goto loc_825F4BF4;
	// b 0x825f4c98
	goto loc_825F4C98;
loc_825F4C94:
	// li r29,1
	ctx.r29.s64 = 1;
loc_825F4C98:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,44(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825f4cd8
	if (ctx.cr6.eq) goto loc_825F4CD8;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4cd8
	if (!ctx.cr6.gt) goto loc_825F4CD8;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4cd0
	if (!ctx.cr0.eq) goto loc_825F4CD0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4cd4
	goto loc_825F4CD4;
loc_825F4CD0:
	// bl 0x825f6f10
	ctx.lr = 0x825F4CD4;
	sub_825F6F10(ctx, base);
loc_825F4CD4:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4CD8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x825f4cec
	if (!ctx.cr6.eq) goto loc_825F4CEC;
	// stw r28,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
loc_825F4CE4:
	// li r11,91
	ctx.r11.s64 = 91;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_825F4CEC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,91
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 91, ctx.xer);
	// bne cr6,0x825f4e00
	if (!ctx.cr6.eq) goto loc_825F4E00;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f4df8
	if (ctx.cr6.eq) goto loc_825F4DF8;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
loc_825F4D0C:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825f4d74
	if (!ctx.cr6.eq) goto loc_825F4D74;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,44(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825f4d58
	if (ctx.cr6.eq) goto loc_825F4D58;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4d58
	if (!ctx.cr6.gt) goto loc_825F4D58;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4d50
	if (!ctx.cr0.eq) goto loc_825F4D50;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4d54
	goto loc_825F4D54;
loc_825F4D50:
	// bl 0x825f6f10
	ctx.lr = 0x825F4D54;
	sub_825F6F10(ctx, base);
loc_825F4D54:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4D58:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4D60;
	sub_825F4528(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825f4dac
	if (ctx.cr6.eq) goto loc_825F4DAC;
loc_825F4D74:
	// lwz r8,28(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,8(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r8,36(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// lbzx r29,r8,r9
	ctx.r29.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// cmpwi r29,0
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stbx r29,r7,r10
	REX_STORE_U8(ctx.r7.u32 + ctx.r10.u32, ctx.r29.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// bne 0x825f4d0c
	if (!ctx.cr0.eq) goto loc_825F4D0C;
	// b 0x825f4db0
	goto loc_825F4DB0;
loc_825F4DAC:
	// li r29,1
	ctx.r29.s64 = 1;
loc_825F4DB0:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,44(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825f4df0
	if (ctx.cr6.eq) goto loc_825F4DF0;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825f4df0
	if (!ctx.cr6.gt) goto loc_825F4DF0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r5,r11,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r11.u64;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// add. r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x825f4de8
	if (!ctx.cr0.eq) goto loc_825F4DE8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825f4dec
	goto loc_825F4DEC;
loc_825F4DE8:
	// bl 0x825f6f10
	ctx.lr = 0x825F4DEC;
	sub_825F6F10(ctx, base);
loc_825F4DEC:
	// stw r3,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r3.u32);
loc_825F4DF0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x825f4e00
	if (!ctx.cr6.eq) goto loc_825F4E00;
loc_825F4DF8:
	// li r11,103
	ctx.r11.s64 = 103;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_825F4E00:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,103
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 103, ctx.xer);
	// bne cr6,0x825f4e84
	if (!ctx.cr6.eq) goto loc_825F4E84;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825f4e80
	if (ctx.cr6.eq) goto loc_825F4E80;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x825f4e38
	if (!ctx.cr6.gt) goto loc_825F4E38;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4E38;
	sub_825F4528(ctx, base);
loc_825F4E38:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x825f4e84
	if (ctx.cr6.gt) goto loc_825F4E84;
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 50);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r28,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r28.u32);
loc_825F4E80:
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
loc_825F4E84:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f4eb4
	if (ctx.cr6.eq) goto loc_825F4EB4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4E98;
	sub_825F4528(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f4eb4
	if (!ctx.cr6.eq) goto loc_825F4EB4;
loc_825F4EA4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// b 0x825f5100
	goto loc_825F5100;
loc_825F4EB4:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,666
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 666, ctx.xer);
	// bne cr6,0x825f4ecc
	if (!ctx.cr6.eq) goto loc_825F4ECC;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825f463c
	if (!ctx.cr6.eq) goto loc_825F463C;
loc_825F4ECC:
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825f4eec
	if (!ctx.cr6.eq) goto loc_825F4EEC;
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825f4eec
	if (!ctx.cr6.eq) goto loc_825F4EEC;
	// cmpwi cr6,r11,666
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 666, ctx.xer);
	// beq cr6,0x825f4f6c
	if (ctx.cr6.eq) goto loc_825F4F6C;
loc_825F4EEC:
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r11,r11,-22208
	ctx.r11.s64 = ctx.r11.s64 + -22208;
	// mulli r10,r10,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(12));
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825F4F14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x825f4f24
	if (ctx.cr6.eq) goto loc_825F4F24;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x825f4f2c
	if (!ctx.cr6.eq) goto loc_825F4F2C;
loc_825F4F24:
	// li r11,666
	ctx.r11.s64 = 666;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_825F4F2C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825f50d4
	if (ctx.cr6.eq) goto loc_825F50D4;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x825f50d4
	if (ctx.cr6.eq) goto loc_825F50D4;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x825f4f6c
	if (!ctx.cr6.eq) goto loc_825F4F6C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8ad0
	ctx.lr = 0x825F4F58;
	sub_825F8AD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f4528
	ctx.lr = 0x825F4F60;
	sub_825F4528(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f4ea4
	if (ctx.cr6.eq) goto loc_825F4EA4;
loc_825F4F6C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x825f4f80
	if (ctx.cr6.gt) goto loc_825F4F80;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x825f5100
	goto loc_825F5100;
loc_825F4F80:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bne cr6,0x825f5044
	if (!ctx.cr6.eq) goto loc_825F5044;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// stbx r11,r10,r9
	REX_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 50);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,49(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 49);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,48(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 48);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,10(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 10);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,9(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 9);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 8);
	// stbx r9,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// b 0x825f509c
	goto loc_825F509C;
loc_825F5044:
	// lhz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 48);
	// rlwinm r8,r11,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stbx r8,r10,r9
	REX_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r7,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r7.u8);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lhz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 50);
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// stbx r8,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
loc_825F509C:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x825f4528
	ctx.lr = 0x825F50B0;
	sub_825F4528(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x825f50c4
	if (!ctx.cr6.gt) goto loc_825F50C4;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_825F50C4:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x825f5100
	goto loc_825F5100;
loc_825F50D4:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f50e8
	if (!ctx.cr6.eq) goto loc_825F50E8;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_825F50E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825f5100
	goto loc_825F5100;
loc_825F50F0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,25364
	ctx.r11.s64 = ctx.r11.s64 + 25364;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
loc_825F50FC:
	// li r3,-2
	ctx.r3.s64 = -2;
loc_825F5100:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82649E68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 8);
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x82649f60
	if (ctx.cr6.eq) goto loc_82649F60;
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm. r11,r9,0,13,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82649f60
	if (!ctx.cr0.eq) goto loc_82649F60;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82649ea0
	if (ctx.cr6.eq) goto loc_82649EA0;
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82649f60
	if (!ctx.cr0.eq) goto loc_82649F60;
loc_82649EA0:
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r6,r9,27,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1F;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,20(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm. r10,r8,27,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1F;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// beq 0x82649f24
	if (ctx.cr0.eq) goto loc_82649F24;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
loc_82649EE0:
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// b 0x82649f00
	goto loc_82649F00;
loc_82649EEC:
	// lbz r30,3(r11)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82649f08
	if (!ctx.cr6.lt) goto loc_82649F08;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82649F00:
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82649eec
	if (ctx.cr6.lt) goto loc_82649EEC;
loc_82649F08:
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x82649ee0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82649EE0;
loc_82649F24:
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x82649f48
	if (!ctx.cr6.lt) goto loc_82649F48;
	// subf. r11,r5,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x82649f48
	if (ctx.cr0.eq) goto loc_82649F48;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82649F40:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82649f40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82649F40;
loc_82649F48:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// rlwimi r10,r11,0,13,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FFFF) | (ctx.r10.u64 & 0xFFFFFFFFFFF80000);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
loc_82649F60:
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826524F8) {
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
	// lwz r4,21888(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 21888);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x826448b0
	ctx.lr = 0x82652514;
	sub_826448B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,21904(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 21904);
	// lwz r5,21896(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 21896);
	// lwz r4,21892(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 21892);
	// bl 0x82650180
	ctx.lr = 0x82652528;
	sub_82650180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,21908(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 21908);
	// lwz r4,21888(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 21888);
	// bl 0x82644958
	ctx.lr = 0x82652538;
	sub_82644958(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643938
	ctx.lr = 0x82652540;
	sub_82643938(ctx, base);
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

DEFINE_REX_FUNC(sub_82655CB0) {
	REX_FUNC_PROLOGUE();
	// b 0x82656df0
	sub_82656DF0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82655DC8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// stw r5,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// ori r4,r4,7
	ctx.r4.u64 = ctx.r4.u64 | 7;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x828729bc
	ctx.lr = 0x82655E10;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82655e20
	if (!ctx.cr0.lt) goto loc_82655E20;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x82655e44
	goto loc_82655E44;
loc_82655E20:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82655e40
	if (!ctx.cr6.eq) goto loc_82655E40;
	// bl 0x82658140
	ctx.lr = 0x82655E2C;
	sub_82658140(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// li r10,1627
	ctx.r10.s64 = 1627;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82655e44
	goto loc_82655E44;
loc_82655E40:
	// li r3,997
	ctx.r3.s64 = 997;
loc_82655E44:
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

DEFINE_REX_FUNC(sub_82657AA8) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82659dd8
	sub_82659DD8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82657BE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82657BF0;
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
	// bl 0x82756d30
	ctx.lr = 0x82657C18;
	sub_82756D30(ctx, base);
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
	// bl 0x82872ccc
	ctx.lr = 0x82657C38;
	__imp__NtCreateEvent(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82657c98
	if (ctx.cr0.lt) goto loc_82657C98;
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
	// bl 0x82872b6c
	ctx.lr = 0x82657C74;
	__imp__XamShowMessageBoxUIEx(ctx, base);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82657c90
	if (!ctx.cr6.eq) goto loc_82657C90;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826562f8
	ctx.lr = 0x82657C90;
	sub_826562F8(ctx, base);
loc_82657C90:
	// lwz r3,124(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x82872d9c
	ctx.lr = 0x82657C98;
	__imp__NtClose(ctx, base);
loc_82657C98:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265D608) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32108
	ctx.r11.s64 = -2104229888;
	// lwz r3,-26816(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -26816);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8265DEA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8265DEA8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// li r3,4
	ctx.r3.s64 = 4;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x82657af0
	ctx.lr = 0x8265DEC4;
	sub_82657AF0(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8265dedc
	if (!ctx.cr0.eq) goto loc_8265DEDC;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8265df68
	goto loc_8265DF68;
loc_8265DEDC:
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82657af0
	ctx.lr = 0x8265DEE8;
	sub_82657AF0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8265df0c
	if (!ctx.cr6.eq) goto loc_8265DF0C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8265df54
	goto loc_8265DF54;
loc_8265DF0C:
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8265dd88
	ctx.lr = 0x8265DF20;
	sub_8265DD88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8265df3c
	if (ctx.cr0.lt) goto loc_8265DF3C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// b 0x8265df4c
	goto loc_8265DF4C;
loc_8265DF3C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82657b88
	ctx.lr = 0x8265DF4C;
	sub_82657B88(ctx, base);
loc_8265DF4C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8265df78
	if (!ctx.cr6.lt) goto loc_8265DF78;
loc_8265DF54:
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82657b88
	ctx.lr = 0x8265DF60;
	sub_82657B88(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8265df78
	if (!ctx.cr6.lt) goto loc_8265DF78;
loc_8265DF68:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8265DF78:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82661A18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82661A20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,16192
	ctx.r30.s64 = ctx.r11.s64 + 16192;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8265e418
	ctx.lr = 0x82661A38;
	sub_8265E418(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82661a4c
	if (!ctx.cr6.eq) goto loc_82661A4C;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x82661a88
	goto loc_82661A88;
loc_82661A4C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,60
	ctx.r4.s64 = 60;
	// bl 0x8265e530
	ctx.lr = 0x82661A64;
	sub_8265E530(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82661a74
	if (ctx.cr0.eq) goto loc_82661A74;
	// bl 0x8266e160
	ctx.lr = 0x82661A70;
	sub_8266E160(ctx, base);
	// b 0x82661a78
	goto loc_82661A78;
loc_82661A74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82661A78:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82661a9c
	if (ctx.cr6.eq) goto loc_82661A9C;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_82661A88:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8265e4b0
	ctx.lr = 0x82661A90;
	sub_8265E4B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
loc_82661A9C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82661a88
	goto loc_82661A88;
}

DEFINE_REX_FUNC(sub_82665A38) {
	REX_FUNC_PROLOGUE();
	// rlwinm r11,r5,11,0,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 11) & 0xFFFFF800;
	// add r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lbz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,11,0,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0xFFFFF800;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// b 0x82665a6c
	goto loc_82665A6C;
loc_82665A58:
	// lbz r9,3(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r9,r9,11,0,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0xFFFFF800;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_82665A6C:
	// addi r7,r10,2048
	ctx.r7.s64 = ctx.r10.s64 + 2048;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82665a58
	if (!ctx.cr6.gt) goto loc_82665A58;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82665a88
	if (!ctx.cr0.eq) goto loc_82665A88;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
loc_82665A88:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// rlwinm r7,r10,8,22,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x300;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// rlwinm r7,r5,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r7,r9,32
	ctx.r7.s64 = ctx.r9.s64 + 32;
	// beq 0x82665b10
	if (ctx.cr0.eq) goto loc_82665B10;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82665AC4:
	// rlwinm r10,r7,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r9,r7,29
	ctx.r9.u64 = ctx.r7.u32 & 0x7;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// lbzx r5,r10,r11
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// bge cr6,0x82665ae8
	if (!ctx.cr6.lt) goto loc_82665AE8;
	// lbzx r10,r8,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subfic r9,r9,1
	ctx.xer.ca = ctx.r9.u32 <= 1;
	ctx.r9.u64 = static_cast<uint64_t>(1) - ctx.r9.u64;
	// b 0x82665afc
	goto loc_82665AFC;
loc_82665AE8:
	// lbzx r4,r8,r10
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subfic r9,r9,9
	ctx.xer.ca = ctx.r9.u32 <= 9;
	ctx.r9.u64 = static_cast<uint64_t>(9) - ctx.r9.u64;
	// lbzx r10,r6,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
loc_82665AFC:
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// srw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// bdnz 0x82665ac4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82665AC4;
loc_82665B10:
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8266B1C8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-36
	ctx.r3.s64 = ctx.r3.s64 + -36;
	// b 0x8266bd90
	sub_8266BD90(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266B6B8) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r11,7692
	ctx.r11.s64 = ctx.r11.s64 + 7692;
	// addi r10,r10,7672
	ctx.r10.s64 = ctx.r10.s64 + 7672;
	// addi r9,r9,7652
	ctx.r9.s64 = ctx.r9.s64 + 7652;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// bl 0x8266b268
	ctx.lr = 0x8266B6F4;
	sub_8266B268(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267e7e8
	ctx.lr = 0x8266B6FC;
	sub_8267E7E8(ctx, base);
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

DEFINE_REX_FUNC(sub_8266E1E0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-32
	ctx.r3.s64 = ctx.r3.s64 + -32;
	// b 0x8266de08
	sub_8266DE08(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266EB68) {
	REX_FUNC_PROLOGUE();
	// b 0x8266b1e0
	sub_8266B1E0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266EC88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756694
	ctx.lr = 0x8266EC90;
	__savegprlr_19(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8266ecbc
	if (ctx.cr6.eq) goto loc_8266ECBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8266ee8c
	goto loc_8266EE8C;
loc_8266ECBC:
	// bl 0x826878d0
	ctx.lr = 0x8266ECC0;
	sub_826878D0(ctx, base);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8266ecdc
	if (ctx.cr6.eq) goto loc_8266ECDC;
	// cmplwi cr6,r28,20000
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 20000, ctx.xer);
	// blt cr6,0x8266ecdc
	if (ctx.cr6.lt) goto loc_8266ECDC;
	// cmplwi cr6,r28,48000
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 48000, ctx.xer);
	// ble cr6,0x8266ece8
	if (!ctx.cr6.gt) goto loc_8266ECE8;
loc_8266ECDC:
	// lis r27,-30569
	ctx.r27.s64 = -2003369984;
	// ori r27,r27,1
	ctx.r27.u64 = ctx.r27.u64 | 1;
	// b 0x8266ee88
	goto loc_8266EE88;
loc_8266ECE8:
	// lwz r3,216(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// bl 0x826881d8
	ctx.lr = 0x8266ECF0;
	sub_826881D8(ctx, base);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,16192
	ctx.r3.s64 = ctx.r10.s64 + 16192;
	// ori r5,r5,11
	ctx.r5.u64 = ctx.r5.u64 | 11;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266ED1C;
	sub_8265E530(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// bne 0x8266ed30
	if (!ctx.cr0.eq) goto loc_8266ED30;
	// lis r27,-32761
	ctx.r27.s64 = -2147024896;
	// ori r27,r27,14
	ctx.r27.u64 = ctx.r27.u64 | 14;
loc_8266ED30:
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r11,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// blt cr6,0x8266ee88
	if (ctx.cr6.lt) goto loc_8266EE88;
	// lwz r4,216(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// bl 0x8268f800
	ctx.lr = 0x8266ED48;
	sub_8268F800(ctx, base);
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// bl 0x8268a528
	ctx.lr = 0x8266ED68;
	sub_8268A528(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r11,8
	ctx.r11.s64 = 8;
	// lfs f0,2524(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r25,80(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f11,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f11.f64 = double(temp.f32);
	// li r7,6
	ctx.r7.s64 = 6;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r23,80(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f13,2520(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2520);
	ctx.f13.f64 = double(temp.f32);
	// li r8,27
	ctx.r8.s64 = 27;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r21,80(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f12,8276(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8276);
	ctx.f12.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r31,44
	ctx.r30.s64 = ctx.r31.s64 + 44;
	// lwz r19,80(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r30,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r30.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r6,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r6.u32);
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r7,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stw r19,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r19.u32);
	// stw r28,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r28.u32);
	// stw r26,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r26.u32);
	// stw r25,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r25.u32);
	// stw r24,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r24.u32);
	// stw r23,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r23.u32);
	// stw r22,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r22.u32);
	// stw r21,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r21.u32);
	// stw r20,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r20.u32);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// bl 0x8268a548
	ctx.lr = 0x8266EE5C;
	sub_8268A548(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,200(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// bl 0x8266e978
	ctx.lr = 0x8266EE68;
	sub_8266E978(ctx, base);
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// bl 0x827567d0
	ctx.lr = 0x8266EE78;
	sub_827567D0(ctx, base);
	// addi r3,r31,148
	ctx.r3.s64 = ctx.r31.s64 + 148;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x8266EE88;
	sub_827567D0(ctx, base);
loc_8266EE88:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8266EE8C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x827566e4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826803B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r6,8(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,12(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,32(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x82680440
	if (!ctx.cr6.eq) goto loc_82680440;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r9,r11,72
	ctx.r9.s64 = ctx.r11.s64 + 72;
	// li r8,48
	ctx.r8.s64 = 48;
loc_826803EC:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// dcbt r10,r8
	// dcbt r0,r9
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82680420
	if (ctx.cr6.eq) goto loc_82680420;
	// lfs f11,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f0,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f11.f64)));
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f9,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f9.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f8,f12,f13,f9
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f9.f64)));
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82680430
	goto loc_82680430;
loc_82680420:
	// fmuls f11,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfsu f10,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
loc_82680430:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r11,72
	ctx.r9.s64 = ctx.r11.s64 + 72;
	// bdnz 0x826803ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826803EC;
	// blr
	return;
loc_82680440:
	// lfs f11,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lfs f10,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r9,r11,72
	ctx.r9.s64 = ctx.r11.s64 + 72;
	// li r8,48
	ctx.r8.s64 = 48;
loc_8268045C:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// dcbt r10,r8
	// dcbt r0,r9
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82680490
	if (ctx.cr6.eq) goto loc_82680490;
	// lfs f9,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f12,f0,f9
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f9.f64)));
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f7,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f7.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f6,f12,f13,f7
	ctx.f6.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f7.f64)));
	// stfs f6,0(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x826804a0
	goto loc_826804A0;
loc_82680490:
	// fmuls f9,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f8,f12,f13
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfsu f8,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
loc_826804A0:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fadds f0,f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// fadds f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// addi r9,r11,72
	ctx.r9.s64 = ctx.r11.s64 + 72;
	// bdnz 0x8268045c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268045C;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826916C0) {
	REX_FUNC_PROLOGUE();
	// rlwinm r11,r3,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r9,-14(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + -14);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lhz r10,-16(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + -16);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// stb r9,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r9.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826927A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x826927B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x826aaa00
	ctx.lr = 0x826927BC;
	sub_826AAA00(ctx, base);
	// addi r30,r31,24
	ctx.r30.s64 = ctx.r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826aae50
	ctx.lr = 0x826927C8;
	sub_826AAE50(ctx, base);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826aae50
	ctx.lr = 0x826927D4;
	sub_826AAE50(ctx, base);
	// addi r28,r31,64
	ctx.r28.s64 = ctx.r31.s64 + 64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826aae50
	ctx.lr = 0x826927E0;
	sub_826AAE50(ctx, base);
	// addi r27,r31,84
	ctx.r27.s64 = ctx.r31.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826aae50
	ctx.lr = 0x826927EC;
	sub_826AAE50(ctx, base);
	// lwz r3,148(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82692804
	if (ctx.cr6.eq) goto loc_82692804;
	// bl 0x8268faa0
	ctx.lr = 0x82692800;
	sub_8268FAA0(ctx, base);
	// stw r26,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r26.u32);
loc_82692804:
	// lwz r3,160(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82692818
	if (ctx.cr6.eq) goto loc_82692818;
	// bl 0x8268faa0
	ctx.lr = 0x82692814;
	sub_8268FAA0(ctx, base);
	// stw r26,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r26.u32);
loc_82692818:
	// li r5,168
	ctx.r5.s64 = 168;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756d30
	ctx.lr = 0x82692828;
	sub_82756D30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826aa9e0
	ctx.lr = 0x82692830;
	sub_826AA9E0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826aae30
	ctx.lr = 0x82692838;
	sub_826AAE30(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826aae30
	ctx.lr = 0x82692840;
	sub_826AAE30(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826aae30
	ctx.lr = 0x82692848;
	sub_826AAE30(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826aae30
	ctx.lr = 0x82692850;
	sub_826AAE30(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82695300) {
	REX_FUNC_PROLOGUE();
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lhz r11,34(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 34);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mulli r6,r4,28
	ctx.r6.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(28));
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82695320:
	// lwz r9,320(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 320);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,1776
	ctx.r11.s64 = ctx.r11.s64 + 1776;
	// lwz r9,424(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 424);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// lwz r5,12(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// sth r7,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// sth r7,0(r5)
	REX_STORE_U16(ctx.r5.u32 + 0, ctx.r7.u16);
	// lhz r4,34(r8)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r8.u32 + 34);
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x82695320
	if (ctx.cr6.lt) goto loc_82695320;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8269A088) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// std r4,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// beq cr6,0x8269a124
	if (ctx.cr6.eq) goto loc_8269A124;
	// cmpwi cr6,r5,2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 2, ctx.xer);
	// beq cr6,0x8269a0e8
	if (ctx.cr6.eq) goto loc_8269A0E8;
	// cmpwi cr6,r5,3
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 3, ctx.xer);
	// beq cr6,0x8269a0d0
	if (ctx.cr6.eq) goto loc_8269A0D0;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x8269a128
	goto loc_8269A128;
loc_8269A0D0:
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r10,32660
	ctx.r3.s64 = ctx.r10.s64 + 32660;
	// rlwinm r4,r11,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// bl 0x8269a008
	ctx.lr = 0x8269A0E4;
	sub_8269A008(ctx, base);
	// b 0x8269a128
	goto loc_8269A128;
loc_8269A0E8:
	// subfic r11,r6,24
	ctx.xer.ca = ctx.r6.u32 <= 24;
	ctx.r11.u64 = static_cast<uint64_t>(24) - ctx.r6.u64;
	// lwz r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8269a10c
	if (ctx.cr6.lt) goto loc_8269A10C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// slw r4,r10,r11
	ctx.r4.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r3,r9,32660
	ctx.r3.s64 = ctx.r9.s64 + 32660;
	// bl 0x8269a008
	ctx.lr = 0x8269A108;
	sub_8269A008(ctx, base);
	// b 0x8269a128
	goto loc_8269A128;
loc_8269A10C:
	// neg r9,r11
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// sraw r4,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r4.s64 = ctx.r10.s32 >> temp.u32;
	// addi r3,r8,32660
	ctx.r3.s64 = ctx.r8.s64 + 32660;
	// bl 0x8269a008
	ctx.lr = 0x8269A120;
	sub_8269A008(ctx, base);
	// b 0x8269a128
	goto loc_8269A128;
loc_8269A124:
	// lwz r3,136(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
loc_8269A128:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8269a134
	if (ctx.cr6.eq) goto loc_8269A134;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
loc_8269A134:
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

DEFINE_REX_FUNC(sub_826A0250) {
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
	// bl 0x826ab590
	ctx.lr = 0x826A0268;
	sub_826AB590(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4804
	ctx.r10.s64 = ctx.r10.s64 + -4804;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_826A0C40) {
	REX_FUNC_PROLOGUE();
	// lwz r11,184(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a0c54
	if (ctx.cr6.eq) goto loc_826A0C54;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,192(r3)
	REX_STORE_U32(ctx.r3.u32 + 192, ctx.r11.u32);
loc_826A0C54:
	// lwz r3,264(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_826A19C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x826A19C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x826ab590
	ctx.lr = 0x826A19DC;
	sub_826AB590(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r29,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r29.u32);
	// addi r11,r11,-4752
	ctx.r11.s64 = ctx.r11.s64 + -4752;
	// stw r30,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// addi r3,r31,132
	ctx.r3.s64 = ctx.r31.s64 + 132;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r30,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// bl 0x826a0e88
	ctx.lr = 0x826A1A00;
	sub_826A0E88(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r31,208
	ctx.r11.s64 = ctx.r31.s64 + 208;
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r30,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// std r30,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r30.u64);
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
	// stw r10,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r10.u32);
	// stw r30,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r10,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r10.u32);
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// std r30,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r30.u64);
	// std r30,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r30.u64);
	// std r30,224(r31)
	REX_STORE_U64(ctx.r31.u32 + 224, ctx.r30.u64);
	// std r30,232(r31)
	REX_STORE_U64(ctx.r31.u32 + 232, ctx.r30.u64);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826AA9E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826AA9F0:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826aa9f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826AA9F0;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826AAF98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x826AAFA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826aafe0
	if (ctx.cr6.lt) goto loc_826AAFE0;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// add r28,r11,r5
	ctx.r28.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x826aafe4
	goto loc_826AAFE4;
loc_826AAFE0:
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
loc_826AAFE4:
	// subf r11,r28,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r28.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r27,r28,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x827567d0
	ctx.lr = 0x826AB000;
	sub_827567D0(ctx, base);
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r6,r29
	ctx.r11.u64 = ctx.r6.u64 + ctx.r29.u64;
	// subf. r8,r9,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// ble 0x826ab050
	if (!ctx.cr0.gt) goto loc_826AB050;
loc_826AB01C:
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r8,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r5,16(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subf r4,r5,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r5.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x826ab01c
	if (ctx.cr6.lt) goto loc_826AB01C;
loc_826AB050:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r9,r10,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r10.u64;
	// rlwinm r10,r9,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// and r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 & ctx.r9.u64;
	// subf r9,r4,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r4.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// blt cr6,0x826ab0e4
	if (ctx.cr6.lt) goto loc_826AB0E4;
	// addi r8,r9,-4
	ctx.r8.s64 = ctx.r9.s64 + -4;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826AB098:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f11,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfs f8,-8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfs f6,-8(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// lfs f5,-12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12);
	ctx.f5.f64 = double(temp.f32);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// lfs f4,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f3,-12(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + -12, temp.u32);
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// bdnz 0x826ab098
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826AB098;
loc_826AB0E4:
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x826ab110
	if (!ctx.cr6.lt) goto loc_826AB110;
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826AB0FC:
	// lfsu f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	ea = -4 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfsu f12,-4(r11)
	ea = -4 + ctx.r11.u32;
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826ab0fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826AB0FC;
loc_826AB110:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826ab134
	if (ctx.cr6.lt) goto loc_826AB134;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x827567d0
	ctx.lr = 0x826AB12C;
	sub_827567D0(ctx, base);
	// stw r28,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// b 0x826ab174
	goto loc_826AB174;
loc_826AB134:
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// add r4,r3,r6
	ctx.r4.u64 = ctx.r3.u64 + ctx.r6.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x827574a0
	ctx.lr = 0x826AB144;
	sub_827574A0(ctx, base);
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r8,r30,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x827567d0
	ctx.lr = 0x826AB164;
	sub_827567D0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subf r11,r30,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r30.u64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
loc_826AB174:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x826ab184
	if (ctx.cr6.eq) goto loc_826AB184;
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
loc_826AB184:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826B8320) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826b8388
	if (ctx.cr6.eq) goto loc_826B8388;
loc_826B8340:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 8);
	// cmpld cr6,r11,r4
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r4.u64, ctx.xer);
	// bgt cr6,0x826b8368
	if (ctx.cr6.gt) goto loc_826B8368;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpld cr6,r4,r10
	ctx.cr6.compare<uint64_t>(ctx.r4.u64, ctx.r10.u64, ctx.xer);
	// blt cr6,0x826b837c
	if (ctx.cr6.lt) goto loc_826B837C;
	// cmpld cr6,r11,r4
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r4.u64, ctx.xer);
	// blt cr6,0x826b8388
	if (ctx.cr6.lt) goto loc_826B8388;
loc_826B8368:
	// lwz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826b8340
	if (!ctx.cr6.eq) goto loc_826B8340;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr
	return;
loc_826B837C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
loc_826B8388:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826B9890) {
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
	// lwz r31,44(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x826b9178
	ctx.lr = 0x826B98B0;
	sub_826B9178(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b98fc
	if (ctx.cr6.lt) goto loc_826B98FC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b9440
	ctx.lr = 0x826B98C0;
	sub_826B9440(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b98fc
	if (ctx.cr6.lt) goto loc_826B98FC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// std r11,56(r31)
	REX_STORE_U64(ctx.r31.u32 + 56, ctx.r11.u64);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// std r11,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r11.u64);
	// std r11,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r11.u64);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// std r11,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r11.u64);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_826B98FC:
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

DEFINE_REX_FUNC(sub_826BC5A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x826BC5A8;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,40256
	ctx.r3.u64 = ctx.r3.u64 | 40256;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// mr r24,r28
	ctx.r24.u64 = ctx.r28.u64;
	// bl 0x826db230
	ctx.lr = 0x826BC5EC;
	sub_826DB230(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826bc610
	if (!ctx.cr6.eq) goto loc_826BC610;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_826BC610:
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,40256
	ctx.r5.u64 = ctx.r5.u64 | 40256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756d30
	ctx.lr = 0x826BC624;
	sub_82756D30(ctx, base);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x826db230
	ctx.lr = 0x826BC63C;
	sub_826DB230(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// bne cr6,0x826bc65c
	if (!ctx.cr6.eq) goto loc_826BC65C;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_826BC65C:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x826e4970
	ctx.lr = 0x826BC664;
	sub_826E4970(ctx, base);
	// lis r11,22358
	ctx.r11.s64 = 1465253888;
	// lwz r9,284(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// ori r10,r11,17201
	ctx.r10.u64 = ctx.r11.u64 | 17201;
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x826bc70c
	if (!ctx.cr6.eq) goto loc_826BC70C;
	// lis r30,22349
	ctx.r30.s64 = 1464664064;
	// li r24,1
	ctx.r24.s64 = 1;
	// ori r30,r30,22081
	ctx.r30.u64 = ctx.r30.u64 | 22081;
loc_826BC688:
	// lwz r7,292(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lwz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stw r9,20636(r31)
	REX_STORE_U32(ctx.r31.u32 + 20636, ctx.r9.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r11,20632(r31)
	REX_STORE_U32(ctx.r31.u32 + 20632, ctx.r11.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// stw r7,15268(r31)
	REX_STORE_U32(ctx.r31.u32 + 15268, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,40(r6)
	REX_STORE_U32(ctx.r6.u32 + 40, ctx.r31.u32);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// stw r26,22340(r31)
	REX_STORE_U32(ctx.r31.u32 + 22340, ctx.r26.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stw r25,22344(r31)
	REX_STORE_U32(ctx.r31.u32 + 22344, ctx.r25.u32);
	// stw r28,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// bl 0x826bba98
	ctx.lr = 0x826BC6D4;
	sub_826BBA98(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x826bc6e8
	if (ctx.cr6.eq) goto loc_826BC6E8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,22408(r31)
	REX_STORE_U32(ctx.r31.u32 + 22408, ctx.r11.u32);
loc_826BC6E8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826bc6f8
	if (!ctx.cr6.eq) goto loc_826BC6F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bbbf0
	ctx.lr = 0x826BC6F8;
	sub_826BBBF0(ctx, base);
loc_826BC6F8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_826BC70C:
	// lis r10,22349
	ctx.r10.s64 = 1464664064;
	// ori r8,r10,22067
	ctx.r8.u64 = ctx.r10.u64 | 22067;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x826bc74c
	if (ctx.cr6.eq) goto loc_826BC74C;
	// lis r10,30573
	ctx.r10.s64 = 2003632128;
	// ori r8,r10,30259
	ctx.r8.u64 = ctx.r10.u64 | 30259;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x826bc74c
	if (ctx.cr6.eq) goto loc_826BC74C;
	// lis r10,22349
	ctx.r10.s64 = 1464664064;
	// ori r8,r10,22096
	ctx.r8.u64 = ctx.r10.u64 | 22096;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x826bc74c
	if (ctx.cr6.eq) goto loc_826BC74C;
	// lis r10,30573
	ctx.r10.s64 = 2003632128;
	// ori r8,r10,30320
	ctx.r8.u64 = ctx.r10.u64 | 30320;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x826bc688
	if (!ctx.cr6.eq) goto loc_826BC688;
loc_826BC74C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826bc688
	if (ctx.cr6.eq) goto loc_826BC688;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826bc688
	if (ctx.cr6.eq) goto loc_826BC688;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stw r8,3948(r31)
	REX_STORE_U32(ctx.r31.u32 + 3948, ctx.r8.u32);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,3960(r31)
	REX_STORE_U32(ctx.r31.u32 + 3960, ctx.r8.u32);
	// lbz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r5,r6,28,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0x1;
	// stw r5,3964(r31)
	REX_STORE_U32(ctx.r31.u32 + 3964, ctx.r5.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r5,15332(r31)
	REX_STORE_U32(ctx.r31.u32 + 15332, ctx.r5.u32);
	// beq cr6,0x826bc688
	if (ctx.cr6.eq) goto loc_826BC688;
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826E0A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x826E0A10;
	__savegprlr_24(ctx, base);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x826e0ae0
	if (!ctx.cr6.gt) goto loc_826E0AE0;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r7,-2
	ctx.r31.s64 = ctx.r7.s64 + -2;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r31,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r27,r11,r28
	ctx.r27.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r26,r7,-1
	ctx.r26.s64 = ctx.r7.s64 + -1;
	// mullw r24,r6,r3
	ctx.r24.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r3.s32);
loc_826E0A40:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x826e0a70
	if (!ctx.cr6.gt) goto loc_826E0A70;
	// addi r31,r7,-1
	ctx.r31.s64 = ctx.r7.s64 + -1;
	// addi r11,r28,-8
	ctx.r11.s64 = ctx.r28.s64 + -8;
	// rlwinm r31,r31,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_826E0A60:
	// lbzx r31,r3,r30
	ctx.r31.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r30.u32);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// stwu r31,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0a60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0A60;
loc_826E0A70:
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// ble cr6,0x826e0aa4
	if (!ctx.cr6.gt) goto loc_826E0AA4;
	// addi r3,r26,-2
	ctx.r3.s64 = ctx.r26.s64 + -2;
	// addi r11,r28,-4
	ctx.r11.s64 = ctx.r28.s64 + -4;
	// rlwinm r3,r3,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_826E0A8C:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r31,12(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r3,r31,r3
	ctx.r3.u64 = ctx.r31.u64 + ctx.r3.u64;
	// srawi r3,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 1;
	// stwu r3,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0a8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0A8C;
loc_826E0AA4:
	// lwzx r3,r25,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + ctx.r28.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r3,-4(r27)
	REX_STORE_U32(ctx.r27.u32 + -4, ctx.r3.u32);
	// ble cr6,0x826e0ad0
	if (!ctx.cr6.gt) goto loc_826E0AD0;
	// addi r3,r28,-4
	ctx.r3.s64 = ctx.r28.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826E0AC0:
	// lwzu r31,4(r3)
	ea = 4 + ctx.r3.u32;
	ctx.r31.u64 = REX_LOAD_U32(ea);
	ctx.r3.u32 = ea;
	// stbx r31,r11,r30
	REX_STORE_U8(ctx.r11.u32 + ctx.r30.u32, ctx.r31.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826e0ac0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0AC0;
loc_826E0AD0:
	// add r29,r29,r6
	ctx.r29.u64 = ctx.r29.u64 + ctx.r6.u64;
	// add r30,r24,r30
	ctx.r30.u64 = ctx.r24.u64 + ctx.r30.u64;
	// cmpw cr6,r29,r8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826e0a40
	if (ctx.cr6.lt) goto loc_826E0A40;
loc_826E0AE0:
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826e0ba8
	if (!ctx.cr6.gt) goto loc_826E0BA8;
	// addi r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -2;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r8,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r28
	ctx.r31.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r30,r9,-1
	ctx.r30.s64 = ctx.r9.s64 + -1;
	// mullw r27,r6,r26
	ctx.r27.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
loc_826E0B08:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826e0b38
	if (!ctx.cr6.gt) goto loc_826E0B38;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r11,r28,-8
	ctx.r11.s64 = ctx.r28.s64 + -8;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826E0B28:
	// lbzx r7,r8,r4
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r4.u32);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stwu r7,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0b28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0B28;
loc_826E0B38:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x826e0b6c
	if (!ctx.cr6.gt) goto loc_826E0B6C;
	// addi r8,r30,-2
	ctx.r8.s64 = ctx.r30.s64 + -2;
	// addi r11,r28,-4
	ctx.r11.s64 = ctx.r28.s64 + -4;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826E0B54:
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// stwu r8,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0b54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0B54;
loc_826E0B6C:
	// lwzx r8,r29,r28
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r28.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r8,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r8.u32);
	// ble cr6,0x826e0b98
	if (!ctx.cr6.gt) goto loc_826E0B98;
	// addi r8,r28,-4
	ctx.r8.s64 = ctx.r28.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826E0B88:
	// lwzu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stbx r7,r11,r4
	REX_STORE_U8(ctx.r11.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826e0b88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0B88;
loc_826E0B98:
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// add r4,r27,r4
	ctx.r4.u64 = ctx.r27.u64 + ctx.r4.u64;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826e0b08
	if (ctx.cr6.lt) goto loc_826E0B08;
loc_826E0BA8:
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826e0c6c
	if (!ctx.cr6.gt) goto loc_826E0C6C;
	// addi r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -2;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r8,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r31,r9,-1
	ctx.r31.s64 = ctx.r9.s64 + -1;
	// mullw r29,r6,r26
	ctx.r29.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
loc_826E0BCC:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826e0bfc
	if (!ctx.cr6.gt) goto loc_826E0BFC;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r11,r28,-8
	ctx.r11.s64 = ctx.r28.s64 + -8;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_826E0BEC:
	// lbzx r7,r8,r5
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r5.u32);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stwu r7,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0bec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0BEC;
loc_826E0BFC:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// ble cr6,0x826e0c30
	if (!ctx.cr6.gt) goto loc_826E0C30;
	// addi r8,r31,-2
	ctx.r8.s64 = ctx.r31.s64 + -2;
	// addi r11,r28,-4
	ctx.r11.s64 = ctx.r28.s64 + -4;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826E0C18:
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// stwu r8,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826e0c18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0C18;
loc_826E0C30:
	// lwzx r8,r30,r28
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r8,-4(r3)
	REX_STORE_U32(ctx.r3.u32 + -4, ctx.r8.u32);
	// ble cr6,0x826e0c5c
	if (!ctx.cr6.gt) goto loc_826E0C5C;
	// addi r8,r28,-4
	ctx.r8.s64 = ctx.r28.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826E0C4C:
	// lwzu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stbx r7,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826e0c4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E0C4C;
loc_826E0C5C:
	// add r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 + ctx.r6.u64;
	// add r5,r29,r5
	ctx.r5.u64 = ctx.r29.u64 + ctx.r5.u64;
	// cmpw cr6,r4,r10
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826e0bcc
	if (ctx.cr6.lt) goto loc_826E0BCC;
loc_826E0C6C:
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826F8178) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x826F8180;
	__savegprlr_27(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,3380(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3380);
	// lwz r9,188(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 188);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r8,200(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// lwz r3,140(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// divwu r9,r9,r10
	ctx.r9.u64 = uint32_t(ctx.r10.u32 ? ctx.r9.u32 / ctx.r10.u32 : 0);
	// divwu r8,r8,r10
	ctx.r8.u64 = uint32_t(ctx.r10.u32 ? ctx.r8.u32 / ctx.r10.u32 : 0);
	// lwz r31,136(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// divwu r4,r3,r10
	ctx.r4.u64 = uint32_t(ctx.r10.u32 ? ctx.r3.u32 / ctx.r10.u32 : 0);
	// lwz r7,220(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 220);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// lwz r6,224(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 224);
	// divwu r30,r31,r10
	ctx.r30.u64 = uint32_t(ctx.r10.u32 ? ctx.r31.u32 / ctx.r10.u32 : 0);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r5,3844(r11)
	REX_STORE_U32(ctx.r11.u32 + 3844, ctx.r5.u32);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r9,3848(r11)
	REX_STORE_U32(ctx.r11.u32 + 3848, ctx.r9.u32);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r5,3852(r11)
	REX_STORE_U32(ctx.r11.u32 + 3852, ctx.r5.u32);
	// stw r8,3856(r11)
	REX_STORE_U32(ctx.r11.u32 + 3856, ctx.r8.u32);
	// stw r4,3836(r11)
	REX_STORE_U32(ctx.r11.u32 + 3836, ctx.r4.u32);
	// stw r30,3840(r11)
	REX_STORE_U32(ctx.r11.u32 + 3840, ctx.r30.u32);
	// stw r7,3860(r11)
	REX_STORE_U32(ctx.r11.u32 + 3860, ctx.r7.u32);
	// stw r6,3864(r11)
	REX_STORE_U32(ctx.r11.u32 + 3864, ctx.r6.u32);
	// blt cr6,0x826f826c
	if (ctx.cr6.lt) goto loc_826F826C;
	// lwz r5,204(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// rlwinm r29,r9,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r28,208(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 208);
	// rlwinm r27,r8,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r5,r5,r9
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r9,3880(r11)
	REX_STORE_U32(ctx.r11.u32 + 3880, ctx.r9.u32);
	// stw r8,3888(r11)
	REX_STORE_U32(ctx.r11.u32 + 3888, ctx.r8.u32);
	// stw r29,3884(r11)
	REX_STORE_U32(ctx.r11.u32 + 3884, ctx.r29.u32);
	// stw r27,3892(r11)
	REX_STORE_U32(ctx.r11.u32 + 3892, ctx.r27.u32);
	// stw r4,3868(r11)
	REX_STORE_U32(ctx.r11.u32 + 3868, ctx.r4.u32);
	// mullw r9,r28,r8
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// add r8,r5,r7
	ctx.r8.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stw r8,3896(r11)
	REX_STORE_U32(ctx.r11.u32 + 3896, ctx.r8.u32);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// stw r7,3900(r11)
	REX_STORE_U32(ctx.r11.u32 + 3900, ctx.r7.u32);
	// bne cr6,0x826f8244
	if (!ctx.cr6.eq) goto loc_826F8244;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r30,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,3872(r11)
	REX_STORE_U32(ctx.r11.u32 + 3872, ctx.r10.u32);
	// stw r9,3876(r11)
	REX_STORE_U32(ctx.r11.u32 + 3876, ctx.r9.u32);
	// b 0x826f824c
	goto loc_826F824C;
loc_826F8244:
	// stw r3,3872(r11)
	REX_STORE_U32(ctx.r11.u32 + 3872, ctx.r3.u32);
	// stw r31,3876(r11)
	REX_STORE_U32(ctx.r11.u32 + 3876, ctx.r31.u32);
loc_826F824C:
	// lwz r10,204(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// lwz r9,208(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 208);
	// mullw r8,r10,r4
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// mullw r7,r9,r4
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r5,r7,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r6,15200(r11)
	REX_STORE_U32(ctx.r11.u32 + 15200, ctx.r6.u32);
	// stw r5,15204(r11)
	REX_STORE_U32(ctx.r11.u32 + 15204, ctx.r5.u32);
loc_826F826C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827016A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x827016B0;
	__savegprlr_28(ctx, base);
	// lwz r11,284(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82701d74
	if (ctx.cr6.eq) goto loc_82701D74;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82701d74
	if (ctx.cr6.eq) goto loc_82701D74;
	// lwz r11,3988(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3988);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82701d74
	if (ctx.cr6.eq) goto loc_82701D74;
	// lwz r10,4000(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4000);
	// lwz r11,3756(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3756);
	// lwz r5,3760(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 3760);
	// cmpwi cr6,r10,31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 31, ctx.xer);
	// lwz r4,3764(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 3764);
	// lwz r8,204(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r7,212(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 212);
	// ble cr6,0x827016f8
	if (!ctx.cr6.gt) goto loc_827016F8;
	// addi r10,r10,-64
	ctx.r10.s64 = ctx.r10.s64 + -64;
	// stw r10,4000(r3)
	REX_STORE_U32(ctx.r3.u32 + 4000, ctx.r10.u32);
loc_827016F8:
	// lwz r10,3996(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3996);
	// lwz r9,4000(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4000);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82701718
	if (!ctx.cr6.eq) goto loc_82701718;
	// rlwinm r6,r9,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// li r10,-64
	ctx.r10.s64 = -64;
	// subfic r9,r6,16320
	ctx.xer.ca = ctx.r6.u32 <= 16320;
	ctx.r9.u64 = static_cast<uint64_t>(16320) - ctx.r6.u64;
	// b 0x82701720
	goto loc_82701720;
loc_82701718:
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
loc_82701720:
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// vspltish v11,6
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_set1_epi16(short(0x6)));
	// std r10,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r10.u64);
	// lfd f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// std r9,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r9.u64);
	// lfd f13,-64(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r29,r10,16432
	ctx.r29.s64 = ctx.r10.s64 + 16432;
	// addi r6,r1,-64
	ctx.r6.s64 = ctx.r1.s64 + -64;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,-64(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f10,-60(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f10,-56(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f10,-52(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v12,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f9,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f9,-60(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f9,-56(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f9,-52(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// dcbt r0,r11
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r11
	// li r9,256
	ctx.r9.s64 = 256;
	// dcbt r9,r11
	// li r6,384
	ctx.r6.s64 = 384;
	// dcbt r6,r11
	// li r10,512
	ctx.r10.s64 = 512;
	// dcbt r10,r11
	// li r9,640
	ctx.r9.s64 = 640;
	// dcbt r9,r11
	// li r6,768
	ctx.r6.s64 = 768;
	// dcbt r6,r11
	// li r10,896
	ctx.r10.s64 = 896;
	// dcbt r10,r11
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// mullw r8,r7,r8
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// srawi. r10,r8,7
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 7;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r6,16
	ctx.r6.s64 = 16;
	// beq 0x82701b28
	if (ctx.cr0.eq) goto loc_82701B28;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r31,32
	ctx.r31.s64 = 32;
	// li r30,48
	ctx.r30.s64 = 48;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r10,112
	ctx.r10.s64 = 112;
loc_827017F8:
	// lvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v8,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v9,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglb v7,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v10,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglb v6,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v5,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v4,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v9,r11,r30
	ea = (ctx.r11.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglh v31,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// lvx128 v3,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglh v30,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// lvx128 v2,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghh v28,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// lvx128 v1,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghh v27,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v23,v31,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v23.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)));
	// vmrghh v22,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v29,v30,0
	simde_mm_store_ps(ctx.v29.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v30.u32)));
	// vmrglh v26,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v24,v28,0
	simde_mm_store_ps(ctx.v24.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)));
	// vmrglh v21,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v25,v27,0
	simde_mm_store_ps(ctx.v25.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v27.u32)));
	// vmrghb v8,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcfsx v27,v22,0
	simde_mm_store_ps(ctx.v27.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vmrglb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcfsx v26,v26,0
	simde_mm_store_ps(ctx.v26.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v26.u32)));
	// vmrghh v20,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v28,v21,0
	simde_mm_store_ps(ctx.v28.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// vmrghb v7,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglh v17,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v19,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v16,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v16.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghh v18,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v18.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v22,v13,v23,v12
	simde_mm_store_ps(ctx.v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v23.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghb v6,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmaddfp v23,v13,v29,v12
	simde_mm_store_ps(ctx.v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v29.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmaddfp v24,v13,v24,v12
	simde_mm_store_ps(ctx.v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v24.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglh v15,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v15.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v25,v13,v25,v12
	simde_mm_store_ps(ctx.v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v25.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghh v14,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v14.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v27,v13,v27,v12
	simde_mm_store_ps(ctx.v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v27.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglh v10,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v26,v13,v26,v12
	simde_mm_store_ps(ctx.v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v26.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghb v31,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmaddfp v28,v13,v28,v12
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghb v30,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v29,v0,v1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcfsx v4,v14,0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v14.u32)));
	// vmrglh v9,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v8,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v5,v10,0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmrglb v3,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v2,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcfpsxws128 v61,v22,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v22.f32)));
	// vmrglb v1,v0,v1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcfpsxws128 v60,v23,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v23.f32)));
	// vmrghh v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfpsxws128 v59,v24,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v24.f32)));
	// vmrglh v22,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfpsxws128 v58,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v25.f32)));
	// vmrghh v21,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v23,v20,0
	simde_mm_store_ps(ctx.v23.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vcfsx v24,v19,0
	simde_mm_store_ps(ctx.v24.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v19.u32)));
	// vcfpsxws128 v57,v26,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v26.f32)));
	// vcfpsxws128 v56,v27,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v27.f32)));
	// vcfsx v26,v17,0
	simde_mm_store_ps(ctx.v26.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	// vcfsx v27,v16,0
	simde_mm_store_ps(ctx.v27.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v16.u32)));
	// vcfsx v25,v18,0
	simde_mm_store_ps(ctx.v25.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	// vcfpsxws128 v55,v28,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v28.f32)));
	// vcfsx v28,v15,0
	simde_mm_store_ps(ctx.v28.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	// vpkswss128 v20,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.s32), simde_mm_load_si128((simde__m128i*)ctx.v59.s32)));
	// vpkswss128 v19,v58,v61
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.s32), simde_mm_load_si128((simde__m128i*)ctx.v58.s32)));
	// vsrah v17,v20,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v16,v19,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v18,v56,v57
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.s32), simde_mm_load_si128((simde__m128i*)ctx.v56.s32)));
	// vpkshus128 v54,v16,v17
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vsrah v15,v18,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v54,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcfsx v6,v7,0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v7.u32)));
	// vmrglh v14,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v14.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v7,v9,0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v9.u32)));
	// vmrglh v19,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v8,v8,0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v8.u32)));
	// vmrghh v18,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v18.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v9,v22,0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vmrglh v2,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcfsx v10,v21,0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// vmrghh v16,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v16.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v23,v13,v23,v12
	simde_mm_store_ps(ctx.v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v23.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghh v20,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v28,v13,v28,v12
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglh v17,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v4,v13,v4,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglh v30,v0,v1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v5,v13,v5,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghh v22,v0,v1
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v24,v13,v24,v12
	simde_mm_store_ps(ctx.v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v24.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrglh v21,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v25,v13,v25,v12
	simde_mm_store_ps(ctx.v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v25.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghh v1,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v26,v13,v26,v12
	simde_mm_store_ps(ctx.v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v26.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghh v3,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmaddfp v6,v13,v6,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// li r28,1024
	ctx.r28.s64 = 1024;
	// vmaddfp v7,v13,v7,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v8,v13,v8,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v13,v9,v12
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v10,v13,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v27,v13,v27,v12
	simde_mm_store_ps(ctx.v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v27.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vcfpsxws128 v50,v23,0
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v23.f32)));
	// vcfpsxws128 v53,v28,0
	simde_mm_store_si128((simde__m128i*)ctx.v53.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v28.f32)));
	// vcfpsxws128 v52,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v52.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vcfpsxws128 v51,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v51.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vcfpsxws128 v49,v24,0
	simde_mm_store_si128((simde__m128i*)ctx.v49.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v24.f32)));
	// vcfpsxws128 v48,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v48.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v25.f32)));
	// vcfpsxws128 v47,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v47.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vcfpsxws128 v46,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vcfpsxws128 v45,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v45.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v8.f32)));
	// vcfpsxws128 v44,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v44.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v9.f32)));
	// vcfpsxws128 v43,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v43.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vcfpsxws128 v42,v26,0
	simde_mm_store_si128((simde__m128i*)ctx.v42.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v26.f32)));
	// vcfpsxws128 v41,v27,0
	simde_mm_store_si128((simde__m128i*)ctx.v41.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v27.f32)));
	// vpkswss128 v27,v50,v55
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.s32), simde_mm_load_si128((simde__m128i*)ctx.v50.s32)));
	// vcfsx v10,v14,0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v14.u32)));
	// vcfsx v31,v2,0
	simde_mm_store_ps(ctx.v31.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vpkswss128 v29,v52,v53
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.s32), simde_mm_load_si128((simde__m128i*)ctx.v52.s32)));
	// vcfsx v2,v20,0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vsrah v23,v27,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfsx v4,v18,0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	// vcfsx v6,v16,0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v16.u32)));
	// vpkswss128 v26,v48,v49
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.s32), simde_mm_load_si128((simde__m128i*)ctx.v48.s32)));
	// vpkswss128 v24,v47,v51
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.s32), simde_mm_load_si128((simde__m128i*)ctx.v47.s32)));
	// vcfsx v28,v3,0
	simde_mm_store_ps(ctx.v28.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// vsrah v25,v29,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfsx v3,v19,0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v19.u32)));
	// vpkswss128 v20,v45,v46
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v46.s32), simde_mm_load_si128((simde__m128i*)ctx.v45.s32)));
	// vcfsx v5,v17,0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	// vpkshus128 v40,v23,v15
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vsrah v19,v26,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v18,v43,v44
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v44.s32), simde_mm_load_si128((simde__m128i*)ctx.v43.s32)));
	// vsrah v17,v24,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfsx v7,v30,0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v30.u32)));
	// vpkswss128 v16,v41,v42
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v42.s32), simde_mm_load_si128((simde__m128i*)ctx.v41.s32)));
	// vsrah v15,v20,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vmaddfp v10,v13,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsrah v14,v18,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v39,v17,v25
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vcfsx v8,v22,0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vsrah v29,v16,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfsx v9,v21,0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// stvx128 v40,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v38,v14,v15
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vmaddfp v30,v13,v28,v12
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vpkshus128 v37,v29,v19
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// stvx128 v39,r11,r30
	ea = (ctx.r11.u32 + ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcfpsxws128 v36,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v36.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v38,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcfsx v10,v1,0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// stvx128 v37,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v31,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v31.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v2,v13,v2,v12
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v3,v13,v3,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v4,v13,v4,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v5,v13,v5,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v6,v13,v6,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v7,v13,v7,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v8,v13,v8,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v13,v9,v12
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v10,v13,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vcfpsxws128 v35,v30,0
	simde_mm_store_si128((simde__m128i*)ctx.v35.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v30.f32)));
	// vcfpsxws128 v34,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v34.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v1.f32)));
	// vcfpsxws128 v33,v2,0
	simde_mm_store_si128((simde__m128i*)ctx.v33.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vcfpsxws128 v32,v3,0
	simde_mm_store_si128((simde__m128i*)ctx.v32.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v3.f32)));
	// vcfpsxws128 v63,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vcfpsxws128 v62,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vcfpsxws128 v61,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vcfpsxws128 v60,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vcfpsxws128 v59,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v8.f32)));
	// vcfpsxws128 v58,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v9.f32)));
	// vcfpsxws128 v57,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vpkswss128 v28,v35,v36
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v36.s32), simde_mm_load_si128((simde__m128i*)ctx.v35.s32)));
	// vpkswss128 v27,v33,v34
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v34.s32), simde_mm_load_si128((simde__m128i*)ctx.v33.s32)));
	// vsrah v26,v28,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v25,v63,v32
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v32.s32), simde_mm_load_si128((simde__m128i*)ctx.v63.s32)));
	// vpkswss128 v24,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.s32), simde_mm_load_si128((simde__m128i*)ctx.v61.s32)));
	// vsrah v23,v27,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v22,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.s32), simde_mm_load_si128((simde__m128i*)ctx.v59.s32)));
	// vsrah v21,v25,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v20,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.s32), simde_mm_load_si128((simde__m128i*)ctx.v57.s32)));
	// vsrah v19,v24,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v56,v23,v26
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vsrah v18,v22,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v17,v20,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v55,v19,v21
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vpkshus128 v54,v17,v18
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// stvx128 v56,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r28,r11
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x827017f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827017F8;
loc_82701B28:
	// dcbt r0,r5
	// dcbt r0,r4
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r5
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r4
	// li r9,256
	ctx.r9.s64 = 256;
	// dcbt r9,r5
	// li r8,256
	ctx.r8.s64 = 256;
	// dcbt r8,r4
	// li r7,384
	ctx.r7.s64 = 384;
	// dcbt r7,r5
	// li r11,384
	ctx.r11.s64 = 384;
	// dcbt r11,r4
	// lwz r10,216(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// lwz r9,208(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// srawi. r11,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 5;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82701d74
	if (ctx.cr0.eq) goto loc_82701D74;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v63,r29,r11
	ea = (ctx.r29.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82701B88:
	// lvx128 v10,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,512
	ctx.r11.s64 = 512;
	// lvx128 v9,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v8,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v7,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v10,r5,r6
	ea = (ctx.r5.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v5,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v9,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglh v4,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v3,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v2,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v1,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v31,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcsxwfp128 v53,v4,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v53.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v4.u32)));
	// vmrghh v30,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcsxwfp128 v52,v3,0
	simde_mm_store_ps(ctx.v52.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// vmrglh v29,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcsxwfp128 v51,v2,0
	simde_mm_store_ps(ctx.v51.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vmrghh v28,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vcsxwfp128 v50,v1,0
	simde_mm_store_ps(ctx.v50.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// vcsxwfp128 v49,v31,0
	simde_mm_store_ps(ctx.v49.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)));
	// vmrglb v4,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcsxwfp128 v48,v30,0
	simde_mm_store_ps(ctx.v48.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v30.u32)));
	// vmrghb v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcsxwfp128 v47,v29,0
	simde_mm_store_ps(ctx.v47.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v29.u32)));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vcsxwfp128 v46,v28,0
	simde_mm_store_ps(ctx.v46.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)));
	// vmrglb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglh v27,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v26,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v25,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v24,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vsubfp128 v30,v53,v63
	simde_mm_store_ps(ctx.v30.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmrglh v23,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vsubfp128 v31,v52,v63
	simde_mm_store_ps(ctx.v31.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmrghh v22,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vsubfp128 v1,v51,v63
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v51.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmrglh v21,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vsubfp128 v2,v50,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmrghh v20,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vsubfp128 v3,v49,v63
	simde_mm_store_ps(ctx.v3.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v49.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v4,v48,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v5,v47,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v47.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v6,v46,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v46.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcsxwfp128 v45,v27,0
	simde_mm_store_ps(ctx.v45.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v27.u32)));
	// vcsxwfp128 v44,v26,0
	simde_mm_store_ps(ctx.v44.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v26.u32)));
	// vcsxwfp128 v43,v25,0
	simde_mm_store_ps(ctx.v43.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v25.u32)));
	// vcsxwfp128 v42,v24,0
	simde_mm_store_ps(ctx.v42.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v24.u32)));
	// vmaddfp v30,v13,v30,v12
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v30.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v31,v13,v31,v12
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v31.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v1,v13,v1,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v2,v13,v2,v12
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v3,v13,v3,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v4,v13,v4,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v5,v13,v5,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v6,v13,v6,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsubfp128 v7,v45,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v45.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcfpsxws128 v41,v30,0
	simde_mm_store_si128((simde__m128i*)ctx.v41.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v30.f32)));
	// vcfpsxws128 v40,v31,0
	simde_mm_store_si128((simde__m128i*)ctx.v40.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v31.f32)));
	// vcfpsxws128 v39,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v39.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v1.f32)));
	// vcfpsxws128 v38,v2,0
	simde_mm_store_si128((simde__m128i*)ctx.v38.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vcfpsxws128 v37,v3,0
	simde_mm_store_si128((simde__m128i*)ctx.v37.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v3.f32)));
	// vcfpsxws128 v36,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v36.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vcfpsxws128 v35,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v35.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vcfpsxws128 v34,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v34.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v7,v13,v7,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vpkswss128 v19,v39,v40
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.s32), simde_mm_load_si128((simde__m128i*)ctx.v39.s32)));
	// vpkswss128 v18,v38,v41
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.s32), simde_mm_load_si128((simde__m128i*)ctx.v38.s32)));
	// vpkswss128 v17,v36,v37
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v37.s32), simde_mm_load_si128((simde__m128i*)ctx.v36.s32)));
	// vsrah v16,v19,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v15,v34,v35
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v35.s32), simde_mm_load_si128((simde__m128i*)ctx.v34.s32)));
	// vsrah v14,v18,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfpsxws128 v33,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v33.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vsrah v10,v17,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsubfp128 v7,v44,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v44.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsrah v9,v15,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v32,v14,v16
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vpkshus128 v62,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// stvx128 v32,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcsxwfp128 v61,v23,0
	simde_mm_store_ps(ctx.v61.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v23.u32)));
	// vcsxwfp128 v60,v22,0
	simde_mm_store_ps(ctx.v60.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vcsxwfp128 v59,v21,0
	simde_mm_store_ps(ctx.v59.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// vcsxwfp128 v58,v20,0
	simde_mm_store_ps(ctx.v58.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v20.u32)));
	// vmaddfp v4,v13,v7,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsubfp128 v5,v43,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v6,v42,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v42.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v7,v61,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v8,v60,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v9,v59,v63
	simde_mm_store_ps(ctx.v9.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsubfp128 v10,v58,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcfpsxws128 v57,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v5,v13,v5,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v6,v13,v6,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v7,v13,v7,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v8,v13,v8,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v13,v9,v12
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v10,v13,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vpkswss128 v4,v57,v33
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v33.s32), simde_mm_load_si128((simde__m128i*)ctx.v57.s32)));
	// vcfpsxws128 v56,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vcfpsxws128 v55,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vsrah v3,v4,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vcfpsxws128 v54,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vcfpsxws128 v53,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v53.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v8.f32)));
	// vcfpsxws128 v52,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v52.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v9.f32)));
	// vcfpsxws128 v51,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v51.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vpkswss128 v2,v55,v56
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.s32), simde_mm_load_si128((simde__m128i*)ctx.v55.s32)));
	// vsrah v1,v2,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkswss128 v31,v53,v54
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.s32), simde_mm_load_si128((simde__m128i*)ctx.v53.s32)));
	// vpkshus128 v50,v1,v3
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vpkswss128 v30,v51,v52
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.s32), simde_mm_load_si128((simde__m128i*)ctx.v51.s32)));
	// vsrah v29,v31,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v28,v30,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v50,r5,r6
	ea = (ctx.r5.u32 + ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v49,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// stvx128 v49,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r11,r5
	// li r10,512
	ctx.r10.s64 = 512;
	// dcbt r10,r4
	// addi r5,r5,32
	ctx.r5.s64 = ctx.r5.s64 + 32;
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// bdnz 0x82701b88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82701B88;
loc_82701D74:
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(__restvmx_16) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx v16,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr
	return;
}

DEFINE_REX_FUNC(__restvmx_95) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v95.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v96.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v97.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v98.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v99.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v100.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v101.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v102.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v103.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v104.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8275D078) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8275d0b0
	if (ctx.cr6.eq) goto loc_8275D0B0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82761b48
	ctx.lr = 0x8275D0A4;
	sub_82761B48(ctx, base);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// b 0x8275d0c0
	goto loc_8275D0C0;
loc_8275D0B0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82761bf0
	ctx.lr = 0x8275D0B8;
	sub_82761BF0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8275D0C0:
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

DEFINE_REX_FUNC(sub_8275FAA0) {
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
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8275de18
	ctx.lr = 0x8275FAB4;
	sub_8275DE18(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82760568) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82760570;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// bl 0x82757228
	ctx.lr = 0x82760590;
	sub_82757228(ctx, base);
	// lwz r25,124(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// bl 0x82757228
	ctx.lr = 0x82760598;
	sub_82757228(ctx, base);
	// lwz r24,128(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// bl 0x82757228
	ctx.lr = 0x827605A0;
	sub_82757228(ctx, base);
	// stw r30,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r30.u32);
	// bl 0x82757228
	ctx.lr = 0x827605A8;
	sub_82757228(ctx, base);
	// li r11,-2
	ctx.r11.s64 = -2;
	// stw r28,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r28.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// bl 0x82762240
	ctx.lr = 0x827605D8;
	sub_82762240(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82759f98
	ctx.lr = 0x827605E4;
	sub_82759F98(ctx, base);
	// bl 0x82757228
	ctx.lr = 0x827605E8;
	sub_82757228(ctx, base);
	// stw r25,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r25.u32);
	// bl 0x82757228
	ctx.lr = 0x827605F0;
	sub_82757228(ctx, base);
	// stw r24,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r24.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82760620
	if (ctx.cr6.eq) goto loc_82760620;
	// bl 0x82759f40
	ctx.lr = 0x82760604;
	sub_82759F40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82760620
	if (ctx.cr0.eq) goto loc_82760620;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827604c0
	ctx.lr = 0x82760618;
	sub_827604C0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82760620:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82766BA0) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8263faa8
	ctx.lr = 0x82766BC0;
	sub_8263FAA8(ctx, base);
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// bgt cr6,0x82766c0c
	if (ctx.cr6.gt) goto loc_82766C0C;
	// beq cr6,0x82766bfc
	if (ctx.cr6.eq) goto loc_82766BFC;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82766be8
	if (ctx.cr6.eq) goto loc_82766BE8;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82766c50
	if (ctx.cr6.eq) goto loc_82766C50;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x82766c2c
	if (ctx.cr6.eq) goto loc_82766C2C;
	// b 0x82766c5c
	goto loc_82766C5C;
loc_82766BE8:
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r11,r10,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwimi r11,r10,0,30,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x82766c58
	goto loc_82766C58;
loc_82766BFC:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// b 0x82766c5c
	goto loc_82766C5C;
loc_82766C0C:
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// beq cr6,0x82766c50
	if (ctx.cr6.eq) goto loc_82766C50;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// beq cr6,0x82766c50
	if (ctx.cr6.eq) goto loc_82766C50;
	// cmpwi cr6,r3,16
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 16, ctx.xer);
	// ble cr6,0x82766c5c
	if (!ctx.cr6.gt) goto loc_82766C5C;
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
	// bgt cr6,0x82766c5c
	if (ctx.cr6.gt) goto loc_82766C5C;
loc_82766C2C:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,0,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFF000;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 & ctx.r30.u64;
	// bl 0x82766b38
	ctx.lr = 0x82766C4C;
	sub_82766B38(ctx, base);
	// b 0x82766c5c
	goto loc_82766C5C;
loc_82766C50:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
loc_82766C58:
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_82766C5C:
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

DEFINE_REX_FUNC(sub_827721B8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x825fbdf0
	ctx.lr = 0x827721DC;
	sub_825FBDF0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// bne cr6,0x827721f4
	if (!ctx.cr6.eq) goto loc_827721F4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82772318
	goto loc_82772318;
loc_827721F4:
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x827722d0
	if (ctx.cr6.eq) goto loc_827722D0;
	// li r9,256
	ctx.r9.s64 = 256;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lfs f0,-30560(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30560);
	ctx.f0.f64 = double(temp.f32);
loc_82772218:
	// lwz r9,80(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// lwz r8,56(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lbzx r9,r9,r11
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f13,r10,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
	// lwz r9,80(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r8,56(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lwz r8,80(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r8,2(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,8(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lwz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r8,80(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r8,3(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r8,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,12(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// bdnz 0x82772218
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82772218;
	// b 0x82772314
	goto loc_82772314;
loc_827722D0:
	// li r10,256
	ctx.r10.s64 = 256;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,5864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
loc_827722E0:
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,8(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x827722e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827722E0;
loc_82772314:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82772318:
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

DEFINE_REX_FUNC(sub_8277B290) {
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
	// lwz r10,64(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// li r6,1
	ctx.r6.s64 = 1;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8277ad78
	ctx.lr = 0x8277B2C4;
	sub_8277AD78(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8277b324
	if (ctx.cr0.lt) goto loc_8277B324;
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r9,104(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lwz r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// rlwinm r5,r9,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x827567d0
	ctx.lr = 0x8277B2F4;
	sub_827567D0(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8277b30c
	if (ctx.cr6.eq) goto loc_8277B30C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82772418
	ctx.lr = 0x8277B30C;
	sub_82772418(ctx, base);
loc_8277B30C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8277b324
	if (ctx.cr6.eq) goto loc_8277B324;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827727e0
	ctx.lr = 0x8277B324;
	sub_827727E0(ctx, base);
loc_8277B324:
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

DEFINE_REX_FUNC(sub_8277F0B0) {
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
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-29652
	ctx.r9.s64 = ctx.r11.s64 + -29652;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8277f0f0
	if (ctx.cr6.eq) goto loc_8277F0F0;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-24784
	ctx.r3.s64 = ctx.r11.s64 + -24784;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82780cc8
	ctx.lr = 0x8277F0F0;
	sub_82780CC8(ctx, base);
loc_8277F0F0:
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

DEFINE_REX_FUNC(sub_82780B60) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x82765a58
	ctx.lr = 0x82780B7C;
	sub_82765A58(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82780bac
	if (!ctx.cr6.eq) goto loc_82780BAC;
	// bl 0x826563c8
	ctx.lr = 0x82780B88;
	sub_826563C8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82780bb0
	if (!ctx.cr6.gt) goto loc_82780BB0;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
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
loc_82780BAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82780BB0:
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

DEFINE_REX_FUNC(sub_82781FE0) {
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
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// lis r10,-519
	ctx.r10.s64 = -34013184;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// stw r5,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// stw r6,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// ori r10,r10,65530
	ctx.r10.u64 = ctx.r10.u64 | 65530;
	// ori r9,r9,3
	ctx.r9.u64 = ctx.r9.u64 | 3;
	// lwz r3,400(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 400);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r8,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// li r4,1000
	ctx.r4.s64 = 1000;
	// stw r7,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r6,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r6.u32);
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// lis r31,256
	ctx.r31.s64 = 16777216;
	// stw r4,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// bl 0x8278e670
	ctx.lr = 0x82782074;
	sub_8278E670(ctx, base);
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

DEFINE_REX_FUNC(sub_82785348) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82785350;
	__savegprlr_27(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,420(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 420);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82785370
	if (ctx.cr6.eq) goto loc_82785370;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r11,r11,2,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x82785374
	goto loc_82785374;
loc_82785370:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82785374:
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// li r30,0
	ctx.r30.s64 = 0;
	// subfe r27,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r27.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,380
	ctx.r31.s64 = ctx.r28.s64 + 380;
loc_82785388:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827853c4
	if (ctx.cr6.eq) goto loc_827853C4;
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r11,r11,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827853c4
	if (!ctx.cr0.eq) goto loc_827853C4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827849c8
	ctx.lr = 0x827853B0;
	sub_827849C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwimi r10,r27,24,7,7
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 24) & 0x1000000) | (ctx.r10.u64 & 0xFFFFFFFFFEFFFFFF);
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// b 0x827853d4
	goto loc_827853D4;
loc_827853C4:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82756d30
	ctx.lr = 0x827853D4;
	sub_82756D30(ctx, base);
loc_827853D4:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,42
	ctx.r29.s64 = ctx.r29.s64 + 42;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82785388
	if (ctx.cr6.lt) goto loc_82785388;
	// lwz r11,400(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82785468
	if (ctx.cr6.eq) goto loc_82785468;
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82785408
	if (!ctx.cr6.eq) goto loc_82785408;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8278540c
	goto loc_8278540C;
loc_82785408:
	// bl 0x82750e38
	ctx.lr = 0x8278540C;
	sub_82750E38(ctx, base);
loc_8278540C:
	// lwz r11,420(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 420);
	// rlwinm r10,r3,2,24,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// stb r10,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82785428
	if (ctx.cr6.eq) goto loc_82785428;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x8278542c
	goto loc_8278542C;
loc_82785428:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8278542C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r11,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r11.u8);
	// beq cr6,0x8278544c
	if (ctx.cr6.eq) goto loc_8278544C;
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stb r11,248(r1)
	REX_STORE_U8(ctx.r1.u32 + 248, ctx.r11.u8);
loc_8278544C:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// li r5,169
	ctx.r5.s64 = 169;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8278e6d0
	ctx.lr = 0x82785460;
	sub_8278E6D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8278546c
	if (ctx.cr0.lt) goto loc_8278546C;
loc_82785468:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8278546C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278D490) {
	REX_FUNC_PROLOGUE();
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lwz r5,4(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82655dc0
	sub_82655DC0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278D508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x8278D510;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8278d5ac
	if (ctx.cr6.eq) goto loc_8278D5AC;
	// cmplwi cr6,r5,256
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 256, ctx.xer);
	// bgt cr6,0x8278d5ac
	if (ctx.cr6.gt) goto loc_8278D5AC;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8278d544
	if (ctx.cr6.eq) goto loc_8278D544;
	// addi r28,r5,1
	ctx.r28.s64 = ctx.r5.s64 + 1;
loc_8278D544:
	// rlwinm r4,r28,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x8278e7d0
	ctx.lr = 0x8278D550;
	sub_8278E7D0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8278d564
	if (!ctx.cr0.eq) goto loc_8278D564;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8278d5b4
	goto loc_8278D5B4;
loc_8278D564:
	// rlwinm r30,r30,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827567d0
	ctx.lr = 0x8278D578;
	sub_827567D0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8278d594
	if (ctx.cr6.eq) goto loc_8278D594;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// stwx r10,r30,r31
	REX_STORE_U32(ctx.r30.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8278D594:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8278d4b8
	ctx.lr = 0x8278D59C;
	sub_8278D4B8(ctx, base);
	// stw r31,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r31.u32);
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8278d5b4
	goto loc_8278D5B4;
loc_8278D5AC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
loc_8278D5B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278FBF8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,344
	ctx.r3.s64 = ctx.r3.s64 + 344;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8278FC68) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// b 0x82782d30
	sub_82782D30(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278FF00) {
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
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8278ff48
	if (ctx.cr0.eq) goto loc_8278FF48;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,24(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,424
	ctx.r11.s64 = ctx.r11.s64 + 424;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8278ff84
	if (ctx.cr6.eq) goto loc_8278FF84;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8278FF44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8278ff88
	goto loc_8278FF88;
loc_8278FF48:
	// lwz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8278ff94
	if (ctx.cr6.eq) goto loc_8278FF94;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// ld r4,16(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// addi r11,r11,424
	ctx.r11.s64 = ctx.r11.s64 + 424;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8278ff84
	if (ctx.cr6.eq) goto loc_8278FF84;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8278FF80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8278ff88
	goto loc_8278FF88;
loc_8278FF84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8278FF88:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r3,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x8278ff98
	goto loc_8278FF98;
loc_8278FF94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8278FF98:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827944A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x827944A8;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// lwz r31,160(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// rlwinm r10,r11,0,25,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF87F;
	// li r22,0
	ctx.r22.s64 = 0;
	// bl 0x827a2978
	ctx.lr = 0x827944EC;
	sub_827A2978(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x82794500
	if (!ctx.cr0.eq) goto loc_82794500;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82794704
	goto loc_82794704;
loc_82794500:
	// addi r21,r30,108
	ctx.r21.s64 = ctx.r30.s64 + 108;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82872dfc
	ctx.lr = 0x8279450C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x82794728
	if (!ctx.cr6.lt) goto loc_82794728;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x827946b8
	if (ctx.cr6.eq) goto loc_827946B8;
loc_82794524:
	// rlwinm r9,r24,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
	// rlwinm r11,r10,7,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r10,r10,14,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x7F;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82794630
	if (!ctx.cr6.eq) goto loc_82794630;
	// lwzx r10,r9,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
	// rlwinm. r10,r10,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82794710
	if (!ctx.cr0.eq) goto loc_82794710;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x8279471c
	if (!ctx.cr6.eq) goto loc_8279471C;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// clrlwi r10,r10,15
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFF;
	// li r22,1
	ctx.r22.s64 = 1;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x82794710
	if (!ctx.cr6.lt) goto loc_82794710;
	// addi r9,r11,82
	ctx.r9.s64 = ctx.r11.s64 + 82;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r30.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82794710
	if (!ctx.cr6.lt) goto loc_82794710;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82794594
	if (!ctx.cr6.eq) goto loc_82794594;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
loc_82794594:
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82794710
	if (ctx.cr6.eq) goto loc_82794710;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// subfic r8,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r8.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// addi r29,r30,208
	ctx.r29.s64 = ctx.r30.s64 + 208;
	// rlwinm r8,r8,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// or r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 | ctx.r10.u64;
	// beq cr6,0x827946ac
	if (ctx.cr6.eq) goto loc_827946AC;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x827946ac
	if (ctx.cr0.eq) goto loc_827946AC;
loc_827945D0:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r4,r28,-4
	ctx.r4.s64 = ctx.r28.s64 + -4;
	// lwz r11,284(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 284);
	// subf r9,r10,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r10.u64;
	// rlwinm. r8,r11,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r28,r9,r10
	ctx.r28.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bne 0x82794624
	if (!ctx.cr0.eq) goto loc_82794624;
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82794624
	if (!ctx.cr0.eq) goto loc_82794624;
	// lwz r11,232(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82794624
	if (!ctx.cr6.eq) goto loc_82794624;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827938a8
	ctx.lr = 0x8279461C;
	sub_827938A8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82794730
	if (ctx.cr0.lt) goto loc_82794730;
loc_82794624:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x827945d0
	if (!ctx.cr6.eq) goto loc_827945D0;
	// b 0x827946ac
	goto loc_827946AC;
loc_82794630:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x8279471c
	if (!ctx.cr6.eq) goto loc_8279471C;
	// lwz r8,176(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 176);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82794710
	if (!ctx.cr6.eq) goto loc_82794710;
	// addi r11,r30,400
	ctx.r11.s64 = ctx.r30.s64 + 400;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82794710
	if (ctx.cr6.eq) goto loc_82794710;
	// lwz r11,288(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82794728
	if (!ctx.cr0.eq) goto loc_82794728;
	// lwz r10,64(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 64);
	// lwz r11,172(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// lwzx r9,r9,r26
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// clrlwi r10,r9,14
	ctx.r10.u64 = ctx.r9.u32 & 0x3FFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r9,r10,21
	ctx.r9.u64 = ctx.r10.u32 & 0x7FF;
	// rlwinm r10,r10,13,1,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7F000000;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// or r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 | ctx.r9.u64;
	// bne 0x82794694
	if (!ctx.cr0.eq) goto loc_82794694;
	// oris r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 2147483648;
loc_82794694:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827938a8
	ctx.lr = 0x827946A4;
	sub_827938A8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82794730
	if (ctx.cr0.lt) goto loc_82794730;
loc_827946AC:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x82794524
	if (ctx.cr6.lt) goto loc_82794524;
loc_827946B8:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x82872dec
	ctx.lr = 0x827946C4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r11,r25,4
	ctx.r11.s64 = ctx.r25.s64 + 4;
loc_827946C8:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
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
	// bne 0x827946c8
	if (!ctx.cr0.eq) goto loc_827946C8;
loc_827946E4:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82794704
	if (!ctx.cr6.eq) goto loc_82794704;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82794704;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82794704:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
loc_82794710:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x82794730
	goto loc_82794730;
loc_8279471C:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x82794730
	goto loc_82794730;
loc_82794728:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4112
	ctx.r31.u64 = ctx.r31.u64 | 4112;
loc_82794730:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82872dec
	ctx.lr = 0x82794738;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r11,r25,4
	ctx.r11.s64 = ctx.r25.s64 + 4;
loc_8279473C:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
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
	// bne 0x8279473c
	if (!ctx.cr0.eq) goto loc_8279473C;
	// b 0x827946e4
	goto loc_827946E4;
}

DEFINE_REX_FUNC(sub_827A8B28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x827A8B30;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,14(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 14);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827a8c20
	if (ctx.cr0.eq) goto loc_827A8C20;
	// lhz r10,12(r5)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r11,828(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 828);
	// li r9,-1
	ctx.r9.s64 = -1;
	// rlwinm r31,r10,24,8,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// clrlwi r30,r10,24
	ctx.r30.u64 = ctx.r10.u32 & 0xFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x827a8c10
	if (ctx.cr0.eq) goto loc_827A8C10;
	// addi r29,r4,66
	ctx.r29.s64 = ctx.r4.s64 + 66;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_827A8B78:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// rlwinm. r27,r11,0,27,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// beq 0x827a8ba0
	if (ctx.cr0.eq) goto loc_827A8BA0;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r27,r31,24
	ctx.r27.u64 = ctx.r31.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r7,r27
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r27.u32, ctx.xer);
	// b 0x827a8bb4
	goto loc_827A8BB4;
loc_827A8BA0:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r27,r30,24
	ctx.r27.u64 = ctx.r30.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r8,r27
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r27.u32, ctx.xer);
loc_827A8BB4:
	// bgt cr6,0x827a8bc8
	if (ctx.cr6.gt) goto loc_827A8BC8;
	// rlwinm. r11,r5,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827a8bc8
	if (!ctx.cr0.eq) goto loc_827A8BC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_827A8BC8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// bdnz 0x827a8b78
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A8B78;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827a8c10
	if (!ctx.cr6.eq) goto loc_827A8C10;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stb r10,18(r11)
	REX_STORE_U8(ctx.r11.u32 + 18, ctx.r10.u8);
	// beq cr6,0x827a8c90
	if (ctx.cr6.eq) goto loc_827A8C90;
	// lwz r11,672(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 672);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,672(r28)
	REX_STORE_U32(ctx.r28.u32 + 672, ctx.r11.u32);
	// b 0x827a8c90
	goto loc_827A8C90;
loc_827A8C10:
	// ld r11,816(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 816);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// b 0x827a8c24
	goto loc_827A8C24;
loc_827A8C20:
	// lhz r8,12(r5)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r5.u32 + 12);
loc_827A8C24:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827a88f0
	ctx.lr = 0x827A8C2C;
	sub_827A88F0(ctx, base);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,32768
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32768, ctx.xer);
	// blt cr6,0x827a8c4c
	if (ctx.cr6.lt) goto loc_827A8C4C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827a8c90
	goto loc_827A8C90;
loc_827A8C4C:
	// lwz r10,1188(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 1188);
	// rlwinm. r9,r10,0,13,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x827a8c6c
	if (ctx.cr0.eq) goto loc_827A8C6C;
	// lhz r9,1094(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + 1094);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x827a8c78
	if (ctx.cr6.lt) goto loc_827A8C78;
loc_827A8C6C:
	// oris r11,r10,4
	ctx.r11.u64 = ctx.r10.u64 | 262144;
	// sth r8,1094(r28)
	REX_STORE_U16(ctx.r28.u32 + 1094, ctx.r8.u16);
	// stw r11,1188(r28)
	REX_STORE_U32(ctx.r28.u32 + 1188, ctx.r11.u32);
loc_827A8C78:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x827a8c8c
	if (ctx.cr6.eq) goto loc_827A8C8C;
	// lwz r11,672(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 672);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,672(r28)
	REX_STORE_U32(ctx.r28.u32 + 672, ctx.r11.u32);
loc_827A8C8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827A8C90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B3710) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x827B3718;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lwz r29,12(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// rlwinm r11,r29,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// lwz r10,20(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x827b3778
	if (!ctx.cr6.lt) goto loc_827B3778;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
loc_827B3778:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// bl 0x82764fd0
	ctx.lr = 0x827B3784;
	sub_82764FD0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// addi r28,r10,-28456
	ctx.r28.s64 = ctx.r10.s64 + -28456;
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// clrldi r5,r29,32
	ctx.r5.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// stw r30,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// bl 0x827b25b0
	ctx.lr = 0x827B37CC;
	sub_827B25B0(ctx, base);
	// addi r4,r28,28
	ctx.r4.s64 = ctx.r28.s64 + 28;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,144
	ctx.r3.s64 = ctx.r31.s64 + 144;
	// bl 0x827b25b0
	ctx.lr = 0x827B37E0;
	sub_827B25B0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B53F0) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827B9CF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x827B9D00;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r26,r3,232
	ctx.r26.s64 = ctx.r3.s64 + 232;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// bl 0x82872dfc
	ctx.lr = 0x827B9D28;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827b91a8
	ctx.lr = 0x827B9D34;
	sub_827B91A8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x827b9d48
	if (!ctx.cr0.eq) goto loc_827B9D48;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x827b9d60
	goto loc_827B9D60;
loc_827B9D48:
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827bd200
	ctx.lr = 0x827B9D5C;
	sub_827BD200(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_827B9D60:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82872dec
	ctx.lr = 0x827B9D68;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827BE1D0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// stw r10,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827BE6E0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,259
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 259, ctx.xer);
	// bne cr6,0x827be6fc
	if (!ctx.cr6.eq) goto loc_827BE6FC;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_827BE6FC:
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// addi r11,r8,8
	ctx.r11.s64 = ctx.r8.s64 + 8;
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x827be738
	if (!ctx.cr6.eq) goto loc_827BE738;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827be738
	if (ctx.cr6.eq) goto loc_827BE738;
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x827be72c
	if (!ctx.cr6.eq) goto loc_827BE72C;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_827BE72C:
	// lwz r7,4(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
loc_827BE738:
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827be750
	if (ctx.cr6.eq) goto loc_827BE750;
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// b 0x827be754
	goto loc_827BE754;
loc_827BE750:
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_827BE754:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r4,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827C4DF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// addi r10,r4,-4
	ctx.r10.s64 = ctx.r4.s64 + -4;
	// addi r9,r6,-4
	ctx.r9.s64 = ctx.r6.s64 + -4;
loc_827C4E10:
	// lfsu f0,4(r11)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfsu f0,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// fmadds f0,f0,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsu f0,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x827c4e10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C4E10;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827C6FA0) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x827c7004
	if (ctx.cr6.eq) goto loc_827C7004;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r11,-24512(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -24512);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x827C6FE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x827c6ff0
	if (!ctx.cr0.eq) goto loc_827C6FF0;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x827c7000
	goto loc_827C7000;
loc_827C6FF0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lfs f0,2516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2516);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
loc_827C7000:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_827C7004:
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

DEFINE_REX_FUNC(sub_827C9458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7532);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7528, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827C9C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7288, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CA150) {
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
	// lfs f0,22584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7152(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7152, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CA8D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,22744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6932, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CAEA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-6752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6748, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CB6B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,22984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6608);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6504, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CBF60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6248(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6248, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CCDC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-5828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5824, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CD270) {
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
	// lfs f0,23384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5680, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CD998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-5468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5464, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CE840) {
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
	// lfs f0,23656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5140);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5028(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5028, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827CFA70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4484, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D06F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-4124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4120, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D14B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-3720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3716(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3716, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D1E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// addi r9,r9,-29072
	ctx.r9.s64 = ctx.r9.s64 + -29072;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r8,-3428
	ctx.r11.s64 = ctx.r8.s64 + -3428;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f13,-3428(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + -3428, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D24F8) {
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
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3344(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3344);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3232, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D3A80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,24760
	ctx.r9.s64 = ctx.r11.s64 + 24760;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,24760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2588(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2588, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D5008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r9,r11,25064
	ctx.r9.s64 = ctx.r11.s64 + 25064;
	// lfs f0,25064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1984(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1984, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D5998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,25256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1704, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D6330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,-1428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1428);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-1424(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1424, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D6D50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-1132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1128(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1128, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D7CE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -644, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D8F50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-92(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -92, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DA2A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 472, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DB328) {
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
	// lfs f0,26600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,952(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 952, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DC7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,1524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1524);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1568(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1568, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DD480) {
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
	// lfs f0,27240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1880);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1960, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DE3E8) {
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
	// lfs f0,27448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2380, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DEC78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,2636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2640, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DFEE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,3184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3184);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3188(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3188, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E0A58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,3520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3524, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E26A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,28720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4372, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E34F0) {
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
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4708(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4708);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4820(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4820, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E4E88) {
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
	// lfs f0,29528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5600(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5600, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E5938) {
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
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5840(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5840);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5912, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E62B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,29788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E7320) {
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
	// lfs f0,29912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6668(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6668, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E8A68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7368, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E8B28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,7388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7392, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E9B78) {
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
	// lfs f0,30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7756(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7756);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7868, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EB3A8) {
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
	// lfs f0,30568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8572, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827ECAA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,9240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9244(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9244, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EDC00) {
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
	// lfs f0,30952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9632);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9748(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9748, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EF1F0) {
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
	// lfs f0,31208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10332(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10332);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10392(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10392, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EF218) {
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
	// lfs f0,31208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10332(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10332);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10396(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10396, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F0D50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,11080(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11080);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11188, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F1CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31676);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11644, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F2A10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,12024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12028, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F3108) {
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
	// lfs f0,31848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12232, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F4660) {
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
	// lfs f0,32056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12852, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F59C8) {
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
	// lfs f0,32248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13316(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13316);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13416, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F5E18) {
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
	// lfs f0,32328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13464(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13464);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13544, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F75A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,32608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14232(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14232, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F88B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,14780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14784(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14784, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F9B30) {
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
	// lfs f0,-32632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15348(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15348, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FB408) {
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
	// lfs f0,-32360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16076(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16076, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FCC50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,16776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16780(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16780, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FDE50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17320, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FE110) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17408, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FF430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17976(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17976, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FF4F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18000, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82800B40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,-31104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31104);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,18632(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18632, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828015E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,18928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18932, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828028A0) {
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
	// lfs f0,-30136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19456, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82804128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,20144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-27528(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27528);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,20160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20160, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828043B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,20208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20212, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82805610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r9,r11,-24872
	ctx.r9.s64 = ctx.r11.s64 + -24872;
	// lfs f0,-24872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20732(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20732, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828068B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,21248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21252, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82807AC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,21760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21764, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82808B10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,22220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22224, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82809E58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,22748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22752, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280B0F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23260(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23260, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280B690) {
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
	// lfs f0,-19208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23272(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23272);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23416, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280C450) {
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
	// lfs f12,23684(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23684);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23800(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23800, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280DE48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-17020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24508, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280F138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-16712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25044, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280F258) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-16700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25080, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82810560) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-15872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25608(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25608, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82811E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,26492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26496, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82812680) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,26780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26784(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26784, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82813068) {
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
	// lfs f0,-14264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27000(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27000);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27064, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828146F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,27672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12680);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,27688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27688, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82815398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,28000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28004, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828163C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-9236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3228(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3228);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28460, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828175F8) {
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
	// lfs f0,-8440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28908);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28976(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28976, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82819378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,29828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29832, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82819FD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-7948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30192, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281A788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30420, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281BA58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30968, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281CFC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,31588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31588);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,31592(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 31592, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281DB00) {
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
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31856);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31920(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31920, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281F448) {
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
	// lfs f0,-7128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32600);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32660, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82820BD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-32196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32192, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82821B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-6744
	ctx.r9.s64 = ctx.r11.s64 + -6744;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31740(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31740, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82822E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r9,r11,-6552
	ctx.r9.s64 = ctx.r11.s64 + -6552;
	// lfs f0,-6552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31180(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -31180, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82824008) {
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
	// lfs f0,-6360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30728(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30728);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30668(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30668, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82825398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-30104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30104);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30100(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30100, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828254A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-6168
	ctx.r9.s64 = ctx.r11.s64 + -6168;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-6168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30068(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30068, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82826338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29648, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828273E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-29164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29164);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-29160(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -29160, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82827FE0) {
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
	// lfs f0,-5720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28888(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28888);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28808, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82829B18) {
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
	// lfs f0,-5400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28108(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28108);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27996, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282B0C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-27364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27364);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27360, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282CB40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-4696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26584(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26584, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282DCA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-26068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26064, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282F2C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-4168
	ctx.r9.s64 = ctx.r11.s64 + -4168;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-4168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25416, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82830950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-24740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24736, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82830F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-24552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24548, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82831D58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-24104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24100(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24100, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82831EC0) {
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
	// lfs f0,-3208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24056, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82832D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-23632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23628, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82833A78) {
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
	// lfs f0,-2800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23296(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23296);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23240, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82834C48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-2360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22704, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82835228) {
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
	// lfs f0,-2216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22516(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22516, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82836D48) {
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
	// lfs f0,-1816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21716, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828386B0) {
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
	// lfs f0,-1336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20952(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20952, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283A330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-20100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20100);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-20096(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -20096, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283AC00) {
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
	// lfs f0,-616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19916(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19916);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19832, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283C290) {
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
	// lfs f0,-280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19280);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19168(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19168, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283C9A0) {
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
	// lfs f0,-200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18964, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283D6D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-18576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18576);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-18572(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -18572, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283E7A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-18084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18080, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283FB88) {
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
	// lfs f0,520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17500, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828414A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16748, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82842160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16376, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82842898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16144, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82843D40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-15540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15536, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82845598) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,1936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1936);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-14828(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -14828, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82845FA8) {
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
	// lfs f0,2112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30976(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30976);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14524(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14524, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82847928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13780(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13780, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82848BC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-13224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13220, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284A098) {
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
	// lfs f0,3016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12688(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12616(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12616, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284B7B8) {
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
	// lfs f0,3256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11936, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284BD20) {
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
	// lfs f0,3328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11896(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11896);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11776(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11776, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284D170) {
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
	// lfs f0,3568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11304(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11304);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11184(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284EA68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-10444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284FE90) {
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
	// lfs f0,4376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9904(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9904);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9832, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284FFA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-9804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9804);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-9800(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9800, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82851860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9068, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82852D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82853F80) {
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
	// lfs f0,5192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8036(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8036);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7916(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7916, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82855790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-7256(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7256);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7204, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82856668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-6776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6776);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-6772(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -6772, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82857038) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6484, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82857FF0) {
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
	// lfs f0,6112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6024(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6024, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82859368) {
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
	// lfs f0,6368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5456, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285A6C8) {
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
	// lfs f0,6624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4968(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4968);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4888(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4888, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285BB80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,6864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-4392(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4392);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4284, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285CAF8) {
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
	// lfs f0,7104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3932(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3932);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3828(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3828, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285E000) {
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
	// lfs f0,7424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3292(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3292);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3208(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3208, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285F348) {
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
	// lfs f0,7664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2728(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2728);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2644, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828606D0) {
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
	// lfs f0,7912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2072, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82861A10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,8232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1604(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1604);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1500, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82862960) {
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
	// lfs f0,8472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1036, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82863F70) {
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
	// lfs f0,8784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-500(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -500);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -388, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82865268) {
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
	// lfs f0,9024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 180, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828665E0) {
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
	// lfs f0,9264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,748(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 748, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828679A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1220(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1220);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1324(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1324, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82868898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1760, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82869700) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286A898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
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
	// stfs f0,2692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2692, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286B680) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,3124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3128(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3128, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286C0B0) {
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
	// lfs f0,10568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3320(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3320);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3432(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3432, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286D518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,11020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4044, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286E590) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,4540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4540);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4544(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4544, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286EF90) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,4824
	ctx.r6.s64 = ctx.r8.s64 + 4824;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,4824(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4824);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,4824(r8)
	REX_STORE_U32(ctx.r8.u32 + 4824, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,4824(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4824);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,4824(r8)
	REX_STORE_U32(ctx.r8.u32 + 4824, ctx.r11.u32);
	// stb r9,4824(r8)
	REX_STORE_U8(ctx.r8.u32 + 4824, ctx.r9.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82870818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5548, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82871E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r11,r11,-30032
	ctx.r11.s64 = ctx.r11.s64 + -30032;
	// addi r10,r10,6800
	ctx.r10.s64 = ctx.r10.s64 + 6800;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v58,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// vmrghw128 v62,v60,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vor128 v59,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// vmrghw128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vor128 v57,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vmrghw128 v60,v58,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrghw128 v61,v59,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vor128 v62,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vmrghw128 v58,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// vmrghw128 v59,v62,v59
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vmrghw128 v62,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// stvx128 v63,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v58,v59
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// stvx128 v62,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8289C240) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8289C248;
	__savegprlr_28(ctx, base);
	// stwu r1,-912(r1)
	ea = -912 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,996(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 996);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cntlzw r6,r11
	ctx.r6.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r11,r6,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// li r8,4
	ctx.r8.s64 = 4;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// slw r29,r8,r10
	ctx.r29.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// slw r28,r7,r9
	ctx.r28.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// subfic r10,r5,8
	ctx.xer.ca = ctx.r5.u32 <= 8;
	ctx.r10.u64 = static_cast<uint64_t>(8) - ctx.r5.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x82891318
	ctx.lr = 0x8289C294;
	sub_82891318(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vsplth v1,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// bl 0x82898bb0
	ctx.lr = 0x8289C2B8;
	sub_82898BB0(ctx, base);
	// addi r1,r1,912
	ctx.r1.s64 = ctx.r1.s64 + 912;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828A8E70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x828A8E78;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// lbz r25,668(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 668);
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// addi r26,r3,232
	ctx.r26.s64 = ctx.r3.s64 + 232;
	// lwz r10,24(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r4,632(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 632);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x828a8ef0
	if (ctx.cr6.lt) goto loc_828A8EF0;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x826f0bb0
	ctx.lr = 0x828A8EE8;
	sub_826F0BB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x828a8f48
	goto loc_828A8F48;
loc_828A8EF0:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x828a8f44
	if (!ctx.cr6.gt) goto loc_828A8F44;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_828A8EFC:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x828a8efc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828A8EFC;
loc_828A8F44:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_828A8F48:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x828a8fb4
	if (!ctx.cr6.eq) goto loc_828A8FB4;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r10,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rldicr r10,r3,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// std r9,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r9.u64);
	// std r9,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r9.u64);
	// std r9,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r9.u64);
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// b 0x828a8fd0
	goto loc_828A8FD0;
loc_828A8FB4:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x8288e730
	ctx.lr = 0x828A8FD0;
	sub_8288E730(ctx, base);
loc_828A8FD0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r25,r25,30,26,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x828a902c
	if (ctx.cr6.lt) goto loc_828A902C;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826f0bb0
	ctx.lr = 0x828A9024;
	sub_826F0BB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x828a9084
	goto loc_828A9084;
loc_828A902C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x828a9080
	if (!ctx.cr6.gt) goto loc_828A9080;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_828A9038:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x828a9038
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828A9038;
loc_828A9080:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_828A9084:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x828a90f0
	if (!ctx.cr6.eq) goto loc_828A90F0;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r10,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rldicr r10,r3,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// std r9,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r9.u64);
	// std r9,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r9.u64);
	// std r9,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r9.u64);
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// b 0x828a910c
	goto loc_828A910C;
loc_828A90F0:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x8288e730
	ctx.lr = 0x828A910C;
	sub_8288E730(ctx, base);
loc_828A910C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r9,r25,30,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r9,30
	ctx.r27.u64 = ctx.r9.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x828a9168
	if (ctx.cr6.lt) goto loc_828A9168;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826f0bb0
	ctx.lr = 0x828A9160;
	sub_826F0BB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x828a91c0
	goto loc_828A91C0;
loc_828A9168:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x828a91bc
	if (!ctx.cr6.gt) goto loc_828A91BC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_828A9174:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r29,r3,r26
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x828a9174
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828A9174;
loc_828A91BC:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_828A91C0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// bne cr6,0x828a9230
	if (!ctx.cr6.eq) goto loc_828A9230;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r10,r24
	ctx.r11.u64 = ctx.r10.u64 + ctx.r24.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// srawi r10,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
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
	// std r10,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r10.u64);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// std r10,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r10.u64);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_828A9230:
	// rlwinm r11,r27,2,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x8288e730
	ctx.lr = 0x828A9248;
	sub_8288E730(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

