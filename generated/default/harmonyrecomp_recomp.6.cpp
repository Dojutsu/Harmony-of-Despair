#include "harmonyrecomp_funcs.6.h"

DEFINE_REX_FUNC(sub_822104C0) {
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
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-13088(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13088);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82210528
	if (!ctx.cr6.eq) goto loc_82210528;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r3,r11,-27168
	ctx.r3.s64 = ctx.r11.s64 + -27168;
	// bl 0x825a6d58
	ctx.lr = 0x822104F0;
	sub_825A6D58(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// addi r3,r30,-27240
	ctx.r3.s64 = ctx.r30.s64 + -27240;
	// bl 0x825a6d58
	ctx.lr = 0x822104FC;
	sub_825A6D58(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r11,r11,-492
	ctx.r11.s64 = ctx.r11.s64 + -492;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,-27240(r30)
	REX_STORE_U32(ctx.r30.u32 + -27240, ctx.r11.u32);
	// lwz r4,22072(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 22072);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82210524;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-13088(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13088);
loc_82210528:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-13088(r31)
	REX_STORE_U32(ctx.r31.u32 + -13088, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8221DA48) {
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
	ctx.lr = 0x8221DA60;
	sub_82223A50(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r10,-9856
	ctx.r8.s64 = ctx.r10.s64 + -9856;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r10,-4080
	ctx.r9.s64 = ctx.r10.s64 + -4080;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f9,-22360(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -22360);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,3420(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2140);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// addi r10,r10,18380
	ctx.r10.s64 = ctx.r10.s64 + 18380;
	// bge cr6,0x8221daa4
	if (!ctx.cr6.lt) goto loc_8221DAA4;
	// lfs f0,-27336(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27336);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// b 0x8221dae4
	goto loc_8221DAE4;
loc_8221DAA4:
	// lfs f13,-16844(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16844);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8221dac4
	if (!ctx.cr6.lt) goto loc_8221DAC4;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f0,-17756(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1084);
	ctx.f13.f64 = double(temp.f32);
loc_8221DABC:
	// fmadds f0,f11,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// b 0x8221dae4
	goto loc_8221DAE4;
loc_8221DAC4:
	// fcmpu cr6,f12,f8
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f8.f64);
	// bge cr6,0x8221dadc
	if (!ctx.cr6.lt) goto loc_8221DADC;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,-20272(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -20272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1088(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1088);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8221dabc
	goto loc_8221DABC;
loc_8221DADC:
	// fsubs f0,f12,f8
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fmadds f0,f0,f8,f9
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f9.f64)));
loc_8221DAE4:
	// stfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// lfd f0,1096(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 1096);
	// fabs f7,f0
	ctx.f7.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f0,-17764(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,112(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,1968(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1968);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f7,f10
	ctx.cr6.compare(ctx.f7.f64, ctx.f10.f64);
	// lfs f11,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// bge cr6,0x8221db1c
	if (!ctx.cr6.lt) goto loc_8221DB1C;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x8221db3c
	goto loc_8221DB3C;
loc_8221DB1C:
	// fmuls f0,f12,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8221db30
	if (!ctx.cr6.lt) goto loc_8221DB30;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8221db3c
	goto loc_8221DB3C;
loc_8221DB30:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8221db3c
	if (!ctx.cr6.gt) goto loc_8221DB3C;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_8221DB3C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f11,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221db5c
	if (ctx.cr6.eq) goto loc_8221DB5C;
	// stfs f11,40(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
loc_8221DB5C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// blt cr6,0x8221dbc4
	if (ctx.cr6.lt) goto loc_8221DBC4;
	// lfd f0,1104(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 1104);
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x8221db80
	if (!ctx.cr6.lt) goto loc_8221DB80;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x8221dba8
	goto loc_8221DBA8;
loc_8221DB80:
	// fsubs f10,f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f0,-20244(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -20244);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8221db9c
	if (!ctx.cr6.lt) goto loc_8221DB9C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8221dba8
	goto loc_8221DBA8;
loc_8221DB9C:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8221dba8
	if (!ctx.cr6.gt) goto loc_8221DBA8;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_8221DBA8:
	// lfs f13,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r11,87(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r11,87(r31)
	REX_STORE_U8(ctx.r31.u32 + 87, ctx.r11.u8);
loc_8221DBC4:
	// fcmpu cr6,f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x8221dbd4
	if (ctx.cr6.lt) goto loc_8221DBD4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221DBD4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
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

DEFINE_REX_FUNC(sub_8222EB00) {
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
	// bl 0x8222eb58
	ctx.lr = 0x8222EB20;
	sub_8222EB58(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222eb38
	if (ctx.cr0.eq) goto loc_8222EB38;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8222eb38
	if (ctx.cr6.eq) goto loc_8222EB38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8222EB38;
	sub_825E0378(ctx, base);
loc_8222EB38:
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

DEFINE_REX_FUNC(sub_822309C0) {
	REX_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r3,260
	ctx.r11.s64 = ctx.r3.s64 + 260;
	// stb r8,279(r3)
	REX_STORE_U8(ctx.r3.u32 + 279, ctx.r8.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,268(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// lwz r7,264(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// srawi. r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822309E8:
	// lwz r7,264(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwzx r7,r10,r7
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,76(r7)
	REX_STORE_U32(ctx.r7.u32 + 76, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r7,r6,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r6.u64;
	// srawi r7,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x822309e8
	if (ctx.cr6.lt) goto loc_822309E8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82233780) {
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
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822337d0
	if (ctx.cr6.eq) goto loc_822337D0;
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
	// bne cr6,0x822337d0
	if (!ctx.cr6.eq) goto loc_822337D0;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x822337e8
	if (!ctx.cr6.eq) goto loc_822337E8;
loc_822337D0:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r11,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
	// ld r11,2880(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// b 0x822338c0
	goto loc_822338C0;
loc_822337E8:
	// bl 0x824281d8
	ctx.lr = 0x822337EC;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822338c8
	if (!ctx.cr0.eq) goto loc_822338C8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430a88
	ctx.lr = 0x82233800;
	sub_82430A88(ctx, base);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,3456
	ctx.r4.s64 = ctx.r11.s64 + 3456;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8255f918
	ctx.lr = 0x82233814;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82233884
	if (ctx.cr6.eq) goto loc_82233884;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,648(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 648);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82233844;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82233884
	if (!ctx.cr0.eq) goto loc_82233884;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
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
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// b 0x822338b8
	goto loc_822338B8;
loc_82233884:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_822338B8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_822338C0:
	// std r11,104(r31)
	REX_STORE_U64(ctx.r31.u32 + 104, ctx.r11.u64);
	// b 0x822338ec
	goto loc_822338EC;
loc_822338C8:
	// bl 0x825e0d50
	ctx.lr = 0x822338CC;
	sub_825E0D50(ctx, base);
	// bl 0x82429a18
	ctx.lr = 0x822338D0;
	sub_82429A18(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x82429960
	ctx.lr = 0x822338D8;
	sub_82429960(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82429668
	ctx.lr = 0x822338E4;
	sub_82429668(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
loc_822338EC:
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

DEFINE_REX_FUNC(sub_82246C10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82246C18;
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
	// lwz r11,420(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 420);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82246C38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,56
	ctx.r11.s64 = 56;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82246d2c
	if (ctx.cr0.eq) goto loc_82246D2C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,420(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 420);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82246C64;
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
	// lwz r11,420(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 420);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82246C84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82246d2c
	if (ctx.cr6.eq) goto loc_82246D2C;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82246C94:
	// lwz r30,48(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82246d20
	if (ctx.cr6.eq) goto loc_82246D20;
	// lbz r11,53(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 53);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82246d20
	if (ctx.cr0.eq) goto loc_82246D20;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x82246CB8;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82246d20
	if (ctx.cr0.eq) goto loc_82246D20;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82246CCC;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82246d20
	if (ctx.cr0.eq) goto loc_82246D20;
	// lbz r11,54(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 54);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82246cf4
	if (!ctx.cr0.eq) goto loc_82246CF4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r29,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r29.u8);
	// stb r29,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r29.u8);
	// stb r11,54(r31)
	REX_STORE_U8(ctx.r31.u32 + 54, ctx.r11.u8);
	// b 0x82246d20
	goto loc_82246D20;
loc_82246CF4:
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82246d20
	if (!ctx.cr6.eq) goto loc_82246D20;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82246D0C;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r29,52(r31)
	REX_STORE_U8(ctx.r31.u32 + 52, ctx.r29.u8);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stb r29,53(r31)
	REX_STORE_U8(ctx.r31.u32 + 53, ctx.r29.u8);
	// stb r29,54(r31)
	REX_STORE_U8(ctx.r31.u32 + 54, ctx.r29.u8);
loc_82246D20:
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82246c94
	if (!ctx.cr6.eq) goto loc_82246C94;
loc_82246D2C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224D130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8224D138;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82230a18
	ctx.lr = 0x8224D144;
	sub_82230A18(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,26
	ctx.r10.s64 = 26;
	// ori r11,r11,62296
	ctx.r11.u64 = ctx.r11.u64 | 62296;
	// li r3,26
	ctx.r3.s64 = 26;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82575c28
	ctx.lr = 0x8224D15C;
	sub_82575C28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82232490
	ctx.lr = 0x8224D168;
	sub_82232490(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232b18
	ctx.lr = 0x8224D174;
	sub_82232B18(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r3,44(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8224D18C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8224d19c
	if (ctx.cr0.eq) goto loc_8224D19C;
	// bl 0x8222f700
	ctx.lr = 0x8224D198;
	sub_8222F700(ctx, base);
	// b 0x8224d1a0
	goto loc_8224D1A0;
loc_8224D19C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8224D1A0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r30,-3016
	ctx.r30.s64 = ctx.r30.s64 + -3016;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,5456
	ctx.r28.s64 = ctx.r11.s64 + 5456;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8224d1ec
	if (ctx.cr6.eq) goto loc_8224D1EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224D1D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224D1EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8224D1EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// li r4,72
	ctx.r4.s64 = 72;
	// bl 0x825e02a0
	ctx.lr = 0x8224D1FC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8224d20c
	if (ctx.cr0.eq) goto loc_8224D20C;
	// bl 0x8222f700
	ctx.lr = 0x8224D208;
	sub_8222F700(ctx, base);
	// b 0x8224d210
	goto loc_8224D210;
loc_8224D20C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8224D210:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r30,r30,-3012
	ctx.r30.s64 = ctx.r30.s64 + -3012;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8224d254
	if (ctx.cr6.eq) goto loc_8224D254;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224D23C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224D254;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8224D254:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// addi r10,r10,-3040
	ctx.r10.s64 = ctx.r10.s64 + -3040;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f0,12468(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// ori r4,r11,62328
	ctx.r4.u64 = ctx.r11.u64 | 62328;
	// ori r9,r9,62500
	ctx.r9.u64 = ctx.r9.u64 | 62500;
	// lis r3,-32219
	ctx.r3.s64 = -2111504384;
	// ori r8,r8,62476
	ctx.r8.u64 = ctx.r8.u64 | 62476;
	// ori r7,r7,62504
	ctx.r7.u64 = ctx.r7.u64 | 62504;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r6,r3,-2288
	ctx.r6.s64 = ctx.r3.s64 + -2288;
	// stwx r5,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r5.u32);
	// stbx r11,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u8);
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// stbx r11,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8225D990) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8225D998;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824281d8
	ctx.lr = 0x8225D9A4;
	sub_824281D8(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r30,r9,62392
	ctx.r30.u64 = ctx.r9.u64 | 62392;
	// ori r28,r8,62816
	ctx.r28.u64 = ctx.r8.u64 | 62816;
	// addi r29,r11,2880
	ctx.r29.s64 = ctx.r11.s64 + 2880;
	// beq 0x8225da1c
	if (ctx.cr0.eq) goto loc_8225DA1C;
	// bl 0x8242a5e0
	ctx.lr = 0x8225D9C8;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225d9d8
	if (!ctx.cr0.eq) goto loc_8225D9D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8225d9dc
	goto loc_8225D9DC;
loc_8225D9D8:
	// bl 0x8242aa28
	ctx.lr = 0x8225D9DC;
	sub_8242AA28(ctx, base);
loc_8225D9DC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225da1c
	if (!ctx.cr0.eq) goto loc_8225DA1C;
	// add r8,r31,r28
	ctx.r8.u64 = ctx.r31.u64 + ctx.r28.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8225f588
	ctx.lr = 0x8225D9F0;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8225da1c
	if (ctx.cr0.eq) goto loc_8225DA1C;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r9,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r11,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// stdx r11,r31,r30
	REX_STORE_U64(ctx.r31.u32 + ctx.r30.u32, ctx.r11.u64);
loc_8225DA1C:
	// bl 0x8242a5e0
	ctx.lr = 0x8225DA20;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225da30
	if (!ctx.cr0.eq) goto loc_8225DA30;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8225da34
	goto loc_8225DA34;
loc_8225DA30:
	// bl 0x8242aa28
	ctx.lr = 0x8225DA34;
	sub_8242AA28(ctx, base);
loc_8225DA34:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225dc34
	if (!ctx.cr0.eq) goto loc_8225DC34;
	// add r8,r31,r28
	ctx.r8.u64 = ctx.r31.u64 + ctx.r28.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8225f588
	ctx.lr = 0x8225DA48;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8225dc34
	if (ctx.cr0.eq) goto loc_8225DC34;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r31,r30
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r10,r10,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8225dae8
	if (ctx.cr0.eq) goto loc_8225DAE8;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// rlwinm. r10,r10,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne 0x8225daec
	if (!ctx.cr0.eq) goto loc_8225DAEC;
loc_8225DAE8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8225DAEC:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8225db94
	if (ctx.cr0.eq) goto loc_8225DB94;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
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
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
loc_8225DB94:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,12236
	ctx.r10.s64 = ctx.r10.s64 + 12236;
	// ori r9,r9,62576
	ctx.r9.u64 = ctx.r9.u64 | 62576;
	// lfs f13,232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f0,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8225dbb8
	if (!ctx.cr6.lt) goto loc_8225DBB8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8225DBB8:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8225dbc8
	if (!ctx.cr6.gt) goto loc_8225DBC8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8225DBC8:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f12,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
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
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
loc_8225DC34:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82280818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82280820;
	__savegprlr_20(ctx, base);
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f30.u64);
	// stfd f31,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r23,r3,1
	ctx.r23.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r23,r23,-3156
	ctx.r23.s64 = ctx.r23.s64 + -3156;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822816a8
	if (ctx.cr6.lt) goto loc_822816A8;
	// beq cr6,0x8228110c
	if (ctx.cr6.eq) goto loc_8228110C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82280ddc
	if (ctx.cr6.lt) goto loc_82280DDC;
	// beq cr6,0x82280898
	if (ctx.cr6.eq) goto loc_82280898;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82281724
	if (!ctx.cr6.lt) goto loc_82281724;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// ori r10,r10,62408
	ctx.r10.u64 = ctx.r10.u64 | 62408;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,14
	ctx.r4.s64 = 14;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r3,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// lfs f1,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8227e158
	ctx.lr = 0x82280884;
	sub_8227E158(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62430
	ctx.r11.u64 = ctx.r11.u64 | 62430;
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x82281724
	goto loc_82281724;
loc_82280898:
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r25,r25,-2996
	ctx.r25.s64 = ctx.r25.s64 + -2996;
	// addi r24,r11,12472
	ctx.r24.s64 = ctx.r11.s64 + 12472;
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lfs f30,-236(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -236);
	ctx.f30.f64 = double(temp.f32);
	// stfs f0,0(r25)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x822808c4
	if (!ctx.cr6.gt) goto loc_822808C4;
	// stfs f30,0(r25)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
loc_822808C4:
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r26,r26,-3048
	ctx.r26.s64 = ctx.r26.s64 + -3048;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// addi r27,r1,176
	ctx.r27.s64 = ctx.r1.s64 + 176;
	// lwz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r28,r1,272
	ctx.r28.s64 = ctx.r1.s64 + 272;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r7,204(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 204);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r22,60(r7)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// lwz r21,40(r7)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r7.u32 + 40);
	// lwz r30,64(r7)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lfs f0,4(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
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
	// lfs f0,8(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,8(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v60,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x822809A0;
	sub_82322D08(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x822809AC;
	sub_8231E0D8(ctx, base);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r27,r27,-3040
	ctx.r27.s64 = ctx.r27.s64 + -3040;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lwz r29,0(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82280bd4
	if (ctx.cr6.eq) goto loc_82280BD4;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f10,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,204(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f10,200(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r21,r1,192
	ctx.r21.s64 = ctx.r1.s64 + 192;
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r22,r9,-32640
	ctx.r22.s64 = ctx.r9.s64 + -32640;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r20,r1,192
	ctx.r20.s64 = ctx.r1.s64 + 192;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r28,r31,88
	ctx.r28.s64 = ctx.r31.s64 + 88;
	// lfs f0,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f11,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,224(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f11,232(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f11,228(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82280AA8;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x8255f918
	ctx.lr = 0x82280AB8;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r9,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,48(r29)
	REX_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// lfs f0,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82280B98;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,296
	ctx.r3.s64 = ctx.r1.s64 + 296;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82280BA8;
	sub_8255F918(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-3064
	ctx.r4.s64 = ctx.r4.s64 + -3064;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82322d08
	ctx.lr = 0x82280BBC;
	sub_82322D08(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x82280BC8;
	sub_8231E0D8(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r10,336(r11)
	REX_STORE_U64(ctx.r11.u32 + 336, ctx.r10.u64);
loc_82280BD4:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x82280be8
	if (ctx.cr6.gt) goto loc_82280BE8;
	// lwz r10,136(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
loc_82280BE8:
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm. r11,r11,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82280c04
	if (ctx.cr0.eq) goto loc_82280C04;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82280c08
	if (ctx.cr6.eq) goto loc_82280C08;
loc_82280C04:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82280C08:
	// lfs f31,-4(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -4);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82280c28
	if (ctx.cr0.eq) goto loc_82280C28;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82280c24
	if (ctx.cr6.eq) goto loc_82280C24;
	// bl 0x824c54a8
	ctx.lr = 0x82280C24;
	sub_824C54A8(ctx, base);
loc_82280C24:
	// stfs f31,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
loc_82280C28:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,-2992
	ctx.r30.s64 = ctx.r30.s64 + -2992;
	// ori r11,r11,62548
	ctx.r11.u64 = ctx.r11.u64 | 62548;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bge cr6,0x82280c50
	if (!ctx.cr6.lt) goto loc_82280C50;
	// lfsx f0,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82280c64
	if (ctx.cr6.gt) goto loc_82280C64;
loc_82280C50:
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// ble cr6,0x82280c6c
	if (!ctx.cr6.gt) goto loc_82280C6C;
	// lfsx f0,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82280c6c
	if (!ctx.cr6.lt) goto loc_82280C6C;
loc_82280C64:
	// stfs f31,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// b 0x82280d70
	goto loc_82280D70;
loc_82280C6C:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82280c84
	if (!ctx.cr6.eq) goto loc_82280C84;
	// lfs f0,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_82280C84:
	// lfs f12,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// fmuls f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r10,-2956
	ctx.r10.s64 = ctx.r10.s64 + -2956;
	// addi r8,r11,17984
	ctx.r8.s64 = ctx.r11.s64 + 17984;
	// li r9,10
	ctx.r9.s64 = 10;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,-12456(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -12456);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// divwu r9,r11,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r11.u32 / ctx.r9.u32 : 0);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// mulli r10,r9,10
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(10));
	// fnmsubs f0,f12,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82280d70
	if (!ctx.cr0.eq) goto loc_82280D70;
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r29,-2188
	ctx.r11.s64 = ctx.r29.s64 + -2188;
	// lfs f1,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82280CE4;
	sub_825A4A40(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,-2188(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2188);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// bl 0x8255f918
	ctx.lr = 0x82280D64;
	sub_8255F918(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82287640
	ctx.lr = 0x82280D70;
	sub_82287640(ctx, base);
loc_82280D70:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r7,0(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
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
	// lwz r11,72(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 72);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82281724
	if (ctx.cr0.eq) goto loc_82281724;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// b 0x82281724
	goto loc_82281724;
loc_82280DDC:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r27,r27,-2984
	ctx.r27.s64 = ctx.r27.s64 + -2984;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f0,17984(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17984);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r27)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82281724
	if (!ctx.cr6.gt) goto loc_82281724;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r29,r29,-3040
	ctx.r29.s64 = ctx.r29.s64 + -3040;
	// ori r30,r11,62488
	ctx.r30.u64 = ctx.r11.u64 | 62488;
	// lwz r28,0(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82280fcc
	if (ctx.cr6.eq) goto loc_82280FCC;
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// lwz r26,204(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,40(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 40);
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82280E90;
	sub_8255F918(ctx, base);
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82280EF8;
	sub_8255F918(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x82280F08;
	sub_82322D08(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-32640
	ctx.r10.s64 = ctx.r10.s64 + -32640;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82280F8C;
	sub_8255F918(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-3064
	ctx.r4.s64 = ctx.r4.s64 + -3064;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82322d08
	ctx.lr = 0x82280FA0;
	sub_82322D08(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x82280FAC;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// std r11,336(r28)
	REX_STORE_U64(ctx.r28.u32 + 336, ctx.r11.u64);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x824c53e8
	ctx.lr = 0x82280FCC;
	sub_824C53E8(ctx, base);
loc_82280FCC:
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// ori r9,r9,62430
	ctx.r9.u64 = ctx.r9.u64 | 62430;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r11,12472
	ctx.r10.s64 = ctx.r11.s64 + 12472;
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// stbx r8,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r8.u8);
	// lfs f12,-236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82280ffc
	if (!ctx.cr6.eq) goto loc_82280FFC;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_82280FFC:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lfs f13,-20368(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20368);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r8,32720
	ctx.r8.s64 = ctx.r8.s64 + 32720;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ori r5,r5,62540
	ctx.r5.u64 = ctx.r5.u64 | 62540;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r6,r6,62585
	ctx.r6.u64 = ctx.r6.u64 | 62585;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// ori r8,r8,62544
	ctx.r8.u64 = ctx.r8.u64 | 62544;
	// ori r9,r9,62548
	ctx.r9.u64 = ctx.r9.u64 | 62548;
	// lbzx r6,r31,r6
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r6.u32);
	// stfsx f13,r31,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stfsx f13,r31,r9
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// li r9,96
	ctx.r9.s64 = 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// addi r9,r11,68
	ctx.r9.s64 = ctx.r11.s64 + 68;
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// bne 0x822810d4
	if (!ctx.cr0.eq) goto loc_822810D4;
	// li r8,37
	ctx.r8.s64 = 37;
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r8,r8,4
	ctx.r8.u64 = ctx.r8.u64 | 4;
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// lwz r8,72(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r8,r8,0,31,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r8,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r8.u32);
	// b 0x822810f4
	goto loc_822810F4;
loc_822810D4:
	// li r8,48
	ctx.r8.s64 = 48;
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
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
loc_822810F4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r9,3
	ctx.r9.s64 = 3;
	// ori r11,r11,62580
	ctx.r11.u64 = ctx.r11.u64 | 62580;
	// stw r9,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r9.u32);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// b 0x82281724
	goto loc_82281724;
loc_8228110C:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r27,r27,-3048
	ctx.r27.s64 = ctx.r27.s64 + -3048;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82281724
	if (ctx.cr0.eq) goto loc_82281724;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// ori r10,r10,62585
	ctx.r10.u64 = ctx.r10.u64 | 62585;
	// lbzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// bne 0x82281160
	if (!ctx.cr0.eq) goto loc_82281160;
	// li r8,98
	ctx.r8.s64 = 98;
	// li r7,36
	ctx.r7.s64 = 36;
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// stw r7,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r7.u32);
	// b 0x82281170
	goto loc_82281170;
loc_82281160:
	// li r8,47
	ctx.r8.s64 = 47;
	// li r7,98
	ctx.r7.s64 = 98;
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// stw r7,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r7.u32);
loc_82281170:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// addi r30,r30,-3040
	ctx.r30.s64 = ctx.r30.s64 + -3040;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,31,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,12472
	ctx.r9.s64 = ctx.r11.s64 + 12472;
	// ori r10,r10,62552
	ctx.r10.u64 = ctx.r10.u64 | 62552;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// lfs f0,-4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82281724
	if (ctx.cr6.eq) goto loc_82281724;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r29,r31,88
	ctx.r29.s64 = ctx.r31.s64 + 88;
	// lwz r26,204(r10)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + 204);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,40(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// lwz r25,40(r26)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r26.u32 + 40);
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r24,r10,r11
	ctx.r24.u64 = ctx.r10.u64 & ctx.r11.u64;
	// lfs f0,8(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f13,4(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82281244;
	sub_8255F918(ctx, base);
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822812AC;
	sub_8255F918(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r24,280(r28)
	REX_STORE_U32(ctx.r28.u32 + 280, ctx.r24.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82322d08
	ctx.lr = 0x822812C0;
	sub_82322D08(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x822812CC;
	sub_8231E0D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,336(r10)
	REX_STORE_U64(ctx.r10.u32 + 336, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x822812EC;
	sub_82322D08(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x822812F8;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r25,r1,128
	ctx.r25.s64 = ctx.r1.s64 + 128;
	// lwz r11,204(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 204);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r24,64(r11)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// addi r28,r8,32688
	ctx.r28.s64 = ctx.r8.s64 + 32688;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lfs f0,8(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f13,4(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
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
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f10,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,92(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x822813E8;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x822813F8;
	sub_8255F918(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f11,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r9,32512
	ctx.r9.s64 = ctx.r9.s64 + 32512;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r8,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f10,92(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,312
	ctx.r3.s64 = ctx.r1.s64 + 312;
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r10,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r24)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,8(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
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
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822814E4;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x8255f918
	ctx.lr = 0x822814F4;
	sub_8255F918(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f11,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r10,r10,-30960
	ctx.r10.s64 = ctx.r10.s64 + -30960;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r7,348(r11)
	REX_STORE_U32(ctx.r11.u32 + 348, ctx.r7.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f10,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r10,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r10.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r9,352(r11)
	REX_STORE_U32(ctx.r11.u32 + 352, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r9.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,256
	ctx.r28.s64 = ctx.r1.s64 + 256;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmulfp128 v61,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// lfs f0,8(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,256(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82281650;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82281660;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x8255f918
	ctx.lr = 0x82281670;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r10,-3064
	ctx.r10.s64 = ctx.r10.s64 + -3064;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x824c5320
	ctx.lr = 0x82281694;
	sub_824C5320(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,316(r10)
	REX_STORE_U8(ctx.r10.u32 + 316, ctx.r11.u8);
	// stb r11,317(r10)
	REX_STORE_U8(ctx.r10.u32 + 317, ctx.r11.u8);
	// b 0x82281724
	goto loc_82281724;
loc_822816A8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62585
	ctx.r11.u64 = ctx.r11.u64 | 62585;
	// li r7,96
	ctx.r7.s64 = 96;
	// li r8,35
	ctx.r8.s64 = 35;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62488
	ctx.r11.u64 = ctx.r11.u64 | 62488;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// addi r9,r11,68
	ctx.r9.s64 = ctx.r11.s64 + 68;
	// stw r10,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// stb r10,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r10.u8);
	// stw r7,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r7.u32);
	// beq 0x822816ec
	if (ctx.cr0.eq) goto loc_822816EC;
	// li r8,46
	ctx.r8.s64 = 46;
loc_822816EC:
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,31,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// addi r3,r10,7216
	ctx.r3.s64 = ctx.r10.s64 + 7216;
	// bl 0x8257d4d8
	ctx.lr = 0x82281724;
	sub_8257D4D8(ctx, base);
loc_82281724:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823100F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823100F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,16218
	ctx.r11.s64 = ctx.r4.s64 + 16218;
	// addi r9,r4,7808
	ctx.r9.s64 = ctx.r4.s64 + 7808;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r4,7942
	ctx.r10.s64 = ctx.r4.s64 + 7942;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r7,r8,r3
	REX_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsx f13,r9,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// ori r6,r6,62460
	ctx.r6.u64 = ctx.r6.u64 | 62460;
	// lfsx f0,r10,r3
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f0.f64 = double(temp.f32);
	// ori r10,r8,63532
	ctx.r10.u64 = ctx.r8.u64 | 63532;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfsx f12,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfsx f11,r11,r6
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
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
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f1,15656(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 15656);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8230fd70
	ctx.lr = 0x823101E0;
	sub_8230FD70(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-3100
	ctx.r10.s64 = ctx.r10.s64 + -3100;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8231F7D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x8231F7E0;
	__savegprlr_16(ctx, base);
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8273af28
	ctx.lr = 0x8231F7E8;
	__savefpr_28(ctx, base);
	// li r12,-192
	ctx.r12.s64 = -192;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r24,r3,1
	ctx.r24.s64 = ctx.r3.s64 + 65536;
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// lwz r10,100(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r24,r24,-2956
	ctx.r24.s64 = ctx.r24.s64 + -2956;
	// lwz r9,264(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// stw r10,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r10.u32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231F82C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r22,r11,15088
	ctx.r22.s64 = ctx.r11.s64 + 15088;
	// addi r26,r26,-2904
	ctx.r26.s64 = ctx.r26.s64 + -2904;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lfs f0,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,-2616(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2616);
	ctx.f31.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bne 0x8231f854
	if (!ctx.cr0.eq) goto loc_8231F854;
	// stfs f31,0(r26)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
loc_8231F854:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8222ff78
	ctx.lr = 0x8231F868;
	sub_8222FF78(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f13,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r11,4440
	ctx.r27.s64 = ctx.r11.s64 + 4440;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-10852(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -10852);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// bl 0x8222ff78
	ctx.lr = 0x8231F8B8;
	sub_8222FF78(ctx, base);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,2
	ctx.r5.s64 = 2;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8225f630
	ctx.lr = 0x8231F91C;
	sub_8225F630(ctx, base);
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r20,0
	ctx.r20.s64 = 0;
	// lfs f29,-2620(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2620);
	ctx.f29.f64 = double(temp.f32);
	// addi r30,r31,244
	ctx.r30.s64 = ctx.r31.s64 + 244;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231f9e4
	if (ctx.cr0.eq) goto loc_8231F9E4;
loc_8231F940:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r29,r28,16
	ctx.r29.u64 = ctx.r28.u32 & 0xFFFF;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8231f980
	if (!ctx.cr6.lt) goto loc_8231F980;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231F980;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231F980:
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8231f9c8
	if (!ctx.cr6.lt) goto loc_8231F9C8;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8231f9c8
	if (!ctx.cr6.lt) goto loc_8231F9C8;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231F9C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231F9C8:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8231f940
	if (ctx.cr6.lt) goto loc_8231F940;
loc_8231F9E4:
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// li r19,1
	ctx.r19.s64 = 1;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r25,r31,260
	ctx.r25.s64 = ctx.r31.s64 + 260;
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8231faac
	if (!ctx.cr6.gt) goto loc_8231FAAC;
loc_8231FA08:
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// clrlwi r29,r28,16
	ctx.r29.u64 = ctx.r28.u32 & 0xFFFF;
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8231fa48
	if (!ctx.cr6.lt) goto loc_8231FA48;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FA48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FA48:
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8231fa90
	if (!ctx.cr6.lt) goto loc_8231FA90;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8231fa90
	if (!ctx.cr6.lt) goto loc_8231FA90;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FA90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FA90:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8231fa08
	if (ctx.cr6.lt) goto loc_8231FA08;
loc_8231FAAC:
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-2960
	ctx.r23.s64 = ctx.r23.s64 + -2960;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82321788
	if (ctx.cr6.lt) goto loc_82321788;
	// beq cr6,0x823210b0
	if (ctx.cr6.eq) goto loc_823210B0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82320aa8
	if (ctx.cr6.lt) goto loc_82320AA8;
	// beq cr6,0x823207f4
	if (ctx.cr6.eq) goto loc_823207F4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8231fe0c
	if (ctx.cr6.lt) goto loc_8231FE0C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// beq cr6,0x8231fb08
	if (ctx.cr6.eq) goto loc_8231FB08;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bne cr6,0x823217e8
	if (!ctx.cr6.eq) goto loc_823217E8;
	// stb r20,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r20.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FB04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8231FB08:
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r26,r26,-2924
	ctx.r26.s64 = ctx.r26.s64 + -2924;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8231fc5c
	if (ctx.cr6.lt) goto loc_8231FC5C;
	// bne cr6,0x823217e8
	if (!ctx.cr6.eq) goto loc_823217E8;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,-2832(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2832);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,-2904(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2904);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-2900
	ctx.r11.s64 = ctx.r11.s64 + -2900;
	// addi r9,r10,-7672
	ctx.r9.s64 = ctx.r10.s64 + -7672;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f0,-2184(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-7672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7672);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fsubs f31,f0,f11
	ctx.f31.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// fnmsubs f30,f11,f13,f12
	ctx.f30.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f13.f64, -ctx.f12.f64)));
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bge cr6,0x8231fb60
	if (!ctx.cr6.lt) goto loc_8231FB60;
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
loc_8231FB60:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// fctidz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f31.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lbz r10,151(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 151);
	// stb r10,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r10.u8);
	// li r30,255
	ctx.r30.s64 = 255;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// stb r30,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r30.u8);
	// stb r30,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r30.u8);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FB9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fctidz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f30.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lbz r11,151(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 151);
	// stb r11,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r11.u8);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// stb r30,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r30.u8);
	// stb r30,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r30.u8);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FBD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bgt cr6,0x823217e8
	if (ctx.cr6.gt) goto loc_823217E8;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x8231FBF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r20,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r20.u8);
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// stb r30,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r30.u8);
	// stb r30,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r30.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FC24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// stb r30,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r30.u8);
	// stb r30,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r30.u8);
	// stb r20,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r20.u8);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FC50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,7
	ctx.r11.s64 = 7;
loc_8231FC54:
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8231FC5C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// bl 0x8222ff78
	ctx.lr = 0x8231FC70;
	sub_8222FF78(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,16104
	ctx.r3.s64 = ctx.r11.s64 + 16104;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d4d8
	ctx.lr = 0x8231FC84;
	sub_8257D4D8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8222ff78
	ctx.lr = 0x8231FC98;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x8231FCB4;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// li r3,59
	ctx.r3.s64 = 59;
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x82240a58
	ctx.lr = 0x8231FCDC;
	sub_82240A58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// ori r10,r10,62624
	ctx.r10.u64 = ctx.r10.u64 | 62624;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f29,r31,r10
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// ld r11,2880(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// stfs f29,288(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231fd34
	if (ctx.cr0.eq) goto loc_8231FD34;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x8231FD34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FD34:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FD50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8231fd84
	if (!ctx.cr6.gt) goto loc_8231FD84;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x8231FD84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FD84:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8231fdf8
	if (!ctx.cr6.gt) goto loc_8231FDF8;
	// li r28,4
	ctx.r28.s64 = 4;
loc_8231FDA4:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8231fdd8
	if (!ctx.cr6.lt) goto loc_8231FDD8;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r28,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FDD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FDD8:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8231fda4
	if (ctx.cr6.lt) goto loc_8231FDA4;
loc_8231FDF8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r19,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r19.u32);
	// ori r11,r11,62636
	ctx.r11.u64 = ctx.r11.u64 | 62636;
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8231FE0C:
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addi r21,r21,-2924
	ctx.r21.s64 = ctx.r21.s64 + -2924;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823206e0
	if (ctx.cr6.lt) goto loc_823206E0;
	// beq cr6,0x82320584
	if (ctx.cr6.eq) goto loc_82320584;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8232047c
	if (ctx.cr6.lt) goto loc_8232047C;
	// beq cr6,0x823200c4
	if (ctx.cr6.eq) goto loc_823200C4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8231fef4
	if (ctx.cr6.lt) goto loc_8231FEF4;
	// bne cr6,0x823217e8
	if (!ctx.cr6.eq) goto loc_823217E8;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// ble cr6,0x8231fe70
	if (!ctx.cr6.gt) goto loc_8231FE70;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8231FE70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FE70:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823217e8
	if (!ctx.cr0.eq) goto loc_823217E8;
	// stw r19,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r19.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231feb8
	if (ctx.cr0.eq) goto loc_8231FEB8;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x8231FEB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FEB8:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8231feec
	if (!ctx.cr6.gt) goto loc_8231FEEC;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x8231FEEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231FEEC:
	// stw r20,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r20.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8231FEF4:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x8222ff78
	ctx.lr = 0x8231FF08;
	sub_8222FF78(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,-32400
	ctx.r11.s64 = ctx.r11.s64 + -32400;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x8231FF3C;
	sub_8222FF78(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v127
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8225f630
	ctx.lr = 0x8231FFBC;
	sub_8225F630(ctx, base);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,-2916
	ctx.r9.s64 = ctx.r9.s64 + -2916;
	// ori r11,r11,62652
	ctx.r11.u64 = ctx.r11.u64 | 62652;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bge cr6,0x82320000
	if (!ctx.cr6.lt) goto loc_82320000;
	// lwzx r8,r31,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82320000
	if (!ctx.cr6.eq) goto loc_82320000;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r8,r8,62646
	ctx.r8.u64 = ctx.r8.u64 | 62646;
	// lbzx r8,r31,r8
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r8.u32);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82320000
	if (ctx.cr0.eq) goto loc_82320000;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x8232005c
	goto loc_8232005C;
loc_82320000:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bge cr6,0x82320068
	if (!ctx.cr6.lt) goto loc_82320068;
	// lwzx r8,r31,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x82320030
	if (!ctx.cr6.eq) goto loc_82320030;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r8,r8,62647
	ctx.r8.u64 = ctx.r8.u64 | 62647;
	// lbzx r8,r31,r8
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r8.u32);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82320030
	if (ctx.cr0.eq) goto loc_82320030;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x8232005c
	goto loc_8232005C;
loc_82320030:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bge cr6,0x82320068
	if (!ctx.cr6.lt) goto loc_82320068;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82320068
	if (!ctx.cr6.eq) goto loc_82320068;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62648
	ctx.r11.u64 = ctx.r11.u64 | 62648;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82320068
	if (ctx.cr0.eq) goto loc_82320068;
	// li r10,4
	ctx.r10.s64 = 4;
loc_8232005C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62668
	ctx.r11.u64 = ctx.r11.u64 | 62668;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
loc_82320068:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,21588(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 21588);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-2920
	ctx.r11.s64 = ctx.r11.s64 + -2920;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823217e8
	if (!ctx.cr6.gt) goto loc_823217E8;
	// stfs f29,0(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stw r20,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r20.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r19,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r19.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x823200BC;
	sub_8224A2A0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x823206d8
	goto loc_823206D8;
loc_823200C4:
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r26,r26,-2860
	ctx.r26.s64 = ctx.r26.s64 + -2860;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x823200DC;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x823200f0
	if (!ctx.cr0.eq) goto loc_823200F0;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r20,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r20.u32);
	// b 0x8231fc54
	goto loc_8231FC54;
loc_823200F0:
	// lwz r11,1648(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823217e8
	if (ctx.cr6.eq) goto loc_823217E8;
	// bl 0x824281d8
	ctx.lr = 0x82320100;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r25,5
	ctx.r25.s64 = 5;
	// beq 0x8232025c
	if (ctx.cr0.eq) goto loc_8232025C;
	// bl 0x8242a5e0
	ctx.lr = 0x82320110;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82320120
	if (!ctx.cr0.eq) goto loc_82320120;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// b 0x82320124
	goto loc_82320124;
loc_82320120:
	// bl 0x8242aa28
	ctx.lr = 0x82320124;
	sub_8242AA28(ctx, base);
loc_82320124:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823201ec
	if (ctx.cr0.eq) goto loc_823201EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82321ef0
	ctx.lr = 0x82320134;
	sub_82321EF0(ctx, base);
	// lwz r10,1668(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1668);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x823202a8
	if (ctx.cr6.eq) goto loc_823202A8;
	// lwz r11,1648(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82320158
	if (ctx.cr6.eq) goto loc_82320158;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8232017c
	if (!ctx.cr6.eq) goto loc_8232017C;
loc_82320158:
	// lbz r9,1636(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 1636);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x82320178
	if (!ctx.cr0.eq) goto loc_82320178;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82320178
	if (!ctx.cr6.eq) goto loc_82320178;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82320178
	if (ctx.cr6.eq) goto loc_82320178;
	// stb r19,1636(r30)
	REX_STORE_U8(ctx.r30.u32 + 1636, ctx.r19.u8);
loc_82320178:
	// stw r29,1668(r30)
	REX_STORE_U32(ctx.r30.u32 + 1668, ctx.r29.u32);
loc_8232017C:
	// bl 0x82429a18
	ctx.lr = 0x82320180;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,62688
	ctx.r10.u64 = ctx.r10.u64 | 62688;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
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
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stbx r25,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r25.u8);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429960
	ctx.lr = 0x823201C8;
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
	ctx.lr = 0x823201E8;
	sub_82429FF8(ctx, base);
	// b 0x823202a8
	goto loc_823202A8;
loc_823201EC:
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addi r8,r8,-2822
	ctx.r8.s64 = ctx.r8.s64 + -2822;
	// lbz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823202a8
	if (ctx.cr0.eq) goto loc_823202A8;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r11,1648(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
	// addi r10,r10,-2820
	ctx.r10.s64 = ctx.r10.s64 + -2820;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x82320220
	if (ctx.cr6.eq) goto loc_82320220;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82320250
	if (!ctx.cr6.eq) goto loc_82320250;
loc_82320220:
	// lbz r7,1636(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 1636);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne 0x8232024c
	if (!ctx.cr0.eq) goto loc_8232024C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8232024c
	if (!ctx.cr6.eq) goto loc_8232024C;
	// lwz r11,1668(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1668);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8232024c
	if (ctx.cr6.eq) goto loc_8232024C;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8232024c
	if (ctx.cr6.eq) goto loc_8232024C;
	// stb r19,1636(r30)
	REX_STORE_U8(ctx.r30.u32 + 1636, ctx.r19.u8);
loc_8232024C:
	// stw r9,1668(r30)
	REX_STORE_U32(ctx.r30.u32 + 1668, ctx.r9.u32);
loc_82320250:
	// stb r20,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r20.u8);
	// stw r20,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r20.u32);
	// b 0x823202a8
	goto loc_823202A8;
loc_8232025C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82321ef0
	ctx.lr = 0x82320264;
	sub_82321EF0(ctx, base);
	// lwz r10,1668(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1668);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x823202a8
	if (ctx.cr6.eq) goto loc_823202A8;
	// lwz r11,1648(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82320284
	if (ctx.cr6.eq) goto loc_82320284;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823202a8
	if (!ctx.cr6.eq) goto loc_823202A8;
loc_82320284:
	// lbz r9,1636(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 1636);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823202a4
	if (!ctx.cr0.eq) goto loc_823202A4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823202a4
	if (!ctx.cr6.eq) goto loc_823202A4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823202a4
	if (ctx.cr6.eq) goto loc_823202A4;
	// stb r19,1636(r30)
	REX_STORE_U8(ctx.r30.u32 + 1636, ctx.r19.u8);
loc_823202A4:
	// stw r3,1668(r30)
	REX_STORE_U32(ctx.r30.u32 + 1668, ctx.r3.u32);
loc_823202A8:
	// bl 0x824281d8
	ctx.lr = 0x823202AC;
	sub_824281D8(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r28,r10,62713
	ctx.r28.u64 = ctx.r10.u64 | 62713;
	// ori r29,r9,62715
	ctx.r29.u64 = ctx.r9.u64 | 62715;
	// beq 0x82320358
	if (ctx.cr0.eq) goto loc_82320358;
	// bl 0x8242a5e0
	ctx.lr = 0x823202C8;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823202d8
	if (!ctx.cr0.eq) goto loc_823202D8;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// b 0x823202dc
	goto loc_823202DC;
loc_823202D8:
	// bl 0x8242aa28
	ctx.lr = 0x823202DC;
	sub_8242AA28(ctx, base);
loc_823202DC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320338
	if (ctx.cr0.eq) goto loc_82320338;
	// lwz r27,1648(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bne cr6,0x82320310
	if (!ctx.cr6.eq) goto loc_82320310;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82322c60
	ctx.lr = 0x823202FC;
	sub_82322C60(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62720
	ctx.r11.u64 = ctx.r11.u64 | 62720;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x82320364
	goto loc_82320364;
loc_82320310:
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// bne cr6,0x8232035c
	if (!ctx.cr6.eq) goto loc_8232035C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82322c60
	ctx.lr = 0x82320324;
	sub_82322C60(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62720
	ctx.r11.u64 = ctx.r11.u64 | 62720;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x8232035c
	goto loc_8232035C;
loc_82320338:
	// lbzx r11,r31,r28
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r28.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823217e8
	if (ctx.cr0.eq) goto loc_823217E8;
	// lbzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r29.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82320364
	if (!ctx.cr0.eq) goto loc_82320364;
	// li r27,3
	ctx.r27.s64 = 3;
	// b 0x8232035c
	goto loc_8232035C;
loc_82320358:
	// lwz r27,1648(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 1648);
loc_8232035C:
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bne cr6,0x823203bc
	if (!ctx.cr6.eq) goto loc_823203BC;
loc_82320364:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82320378;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stbx r20,r31,r28
	REX_STORE_U8(ctx.r31.u32 + ctx.r28.u32, ctx.r20.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stbx r20,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r20.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x8222ff78
	ctx.lr = 0x823203A4;
	sub_8222FF78(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,16088
	ctx.r3.s64 = ctx.r11.s64 + 16088;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d4d8
	ctx.lr = 0x823203B8;
	sub_8257D4D8(ctx, base);
	// b 0x823217e8
	goto loc_823217E8;
loc_823203BC:
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// bne cr6,0x823217e8
	if (!ctx.cr6.eq) goto loc_823217E8;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823203D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// ori r11,r10,62652
	ctx.r11.u64 = ctx.r10.u64 | 62652;
	// stbx r20,r31,r28
	REX_STORE_U8(ctx.r31.u32 + ctx.r28.u32, ctx.r20.u8);
	// stbx r20,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r20.u8);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82320408
	if (!ctx.cr6.eq) goto loc_82320408;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62646
	ctx.r10.u64 = ctx.r10.u64 | 62646;
	// stbx r20,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r20.u8);
loc_82320408:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8232041c
	if (!ctx.cr6.eq) goto loc_8232041C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62647
	ctx.r10.u64 = ctx.r10.u64 | 62647;
	// stbx r20,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r20.u8);
loc_8232041C:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82320430
	if (!ctx.cr6.eq) goto loc_82320430;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62648
	ctx.r11.u64 = ctx.r11.u64 | 62648;
	// stbx r20,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u8);
loc_82320430:
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// ori r9,r9,62616
	ctx.r9.u64 = ctx.r9.u64 | 62616;
	// ori r11,r11,62620
	ctx.r11.u64 = ctx.r11.u64 | 62620;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stfsx f29,r31,r9
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// stwx r20,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r19,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r19.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x82320474;
	sub_8224A2A0(ctx, base);
	// stw r25,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r25.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8232047C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,-15580(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -15580);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwa r10,20(r10)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r10.u32 + 20));
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lfd f13,144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823217e8
	if (!ctx.cr6.gt) goto loc_823217E8;
	// stw r20,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r20.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r10,r10,62616
	ctx.r10.u64 = ctx.r10.u64 | 62616;
	// ori r11,r11,62620
	ctx.r11.u64 = ctx.r11.u64 | 62620;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfsx f29,r31,r10
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// stwx r20,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u32);
	// bl 0x8222ff78
	ctx.lr = 0x823204D8;
	sub_8222FF78(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,-32400
	ctx.r11.s64 = ctx.r11.s64 + -32400;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x8232050C;
	sub_8222FF78(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vaddfp128 v63,v63,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82322458
	ctx.lr = 0x82320560;
	sub_82322458(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62712
	ctx.r11.u64 = ctx.r11.u64 | 62712;
	// ori r10,r10,62672
	ctx.r10.u64 = ctx.r10.u64 | 62672;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r9.u32);
	// stbx r20,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u8);
	// stbx r20,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r20.u8);
	// b 0x823217e8
	goto loc_823217E8;
loc_82320584:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-2864
	ctx.r29.s64 = ctx.r29.s64 + -2864;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82320634
	if (!ctx.cr0.eq) goto loc_82320634;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82321c30
	ctx.lr = 0x823205A0;
	sub_82321C30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320634
	if (ctx.cr0.eq) goto loc_82320634;
	// stb r19,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r19.u8);
	// bl 0x824281d8
	ctx.lr = 0x823205B0;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320634
	if (ctx.cr0.eq) goto loc_82320634;
	// bl 0x8242a5e0
	ctx.lr = 0x823205BC;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823205cc
	if (!ctx.cr0.eq) goto loc_823205CC;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// b 0x823205d0
	goto loc_823205D0;
loc_823205CC:
	// bl 0x8242aa28
	ctx.lr = 0x823205D0;
	sub_8242AA28(ctx, base);
loc_823205D0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320634
	if (ctx.cr0.eq) goto loc_82320634;
	// bl 0x82429a18
	ctx.lr = 0x823205DC;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,62688
	ctx.r10.u64 = ctx.r10.u64 | 62688;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r8,62692
	ctx.r11.u64 = ctx.r8.u64 | 62692;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r4,r4,-2852
	ctx.r4.s64 = ctx.r4.s64 + -2852;
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r3,15
	ctx.r3.s64 = 15;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429ff8
	ctx.lr = 0x82320630;
	sub_82429FF8(ctx, base);
	// b 0x823217f0
	goto loc_823217F0;
loc_82320634:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82320650
	if (ctx.cr0.eq) goto loc_82320650;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// b 0x823206d0
	goto loc_823206D0;
loc_82320650:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62724
	ctx.r11.u64 = ctx.r11.u64 | 62724;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823206d0
	if (!ctx.cr6.eq) goto loc_823206D0;
	// stw r19,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r19.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320698
	if (ctx.cr0.eq) goto loc_82320698;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320698;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320698:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x823206cc
	if (!ctx.cr6.gt) goto loc_823206CC;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x823206CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823206CC:
	// stw r20,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r20.u32);
loc_823206D0:
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_823206D8:
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_823206E0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// ld r11,2880(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// stfs f29,288(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232076c
	if (ctx.cr0.eq) goto loc_8232076C;
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
loc_82320718:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8232074c
	if (!ctx.cr6.lt) goto loc_8232074C;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232074C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8232074C:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82320718
	if (ctx.cr6.lt) goto loc_82320718;
loc_8232076C:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x823207a0
	if (!ctx.cr6.gt) goto loc_823207A0;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x823207A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823207A0:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x823207C0;
	sub_8224A2A0(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232918
	ctx.lr = 0x823207CC;
	sub_82232918(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// ori r10,r10,62628
	ctx.r10.u64 = ctx.r10.u64 | 62628;
	// ori r9,r9,62620
	ctx.r9.u64 = ctx.r9.u64 | 62620;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// stfsx f29,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stwx r20,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r20.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_823207F4:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r27,r27,-2924
	ctx.r27.s64 = ctx.r27.s64 + -2924;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823209a8
	if (ctx.cr6.lt) goto loc_823209A8;
	// beq cr6,0x82320964
	if (ctx.cr6.eq) goto loc_82320964;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8232089c
	if (ctx.cr6.lt) goto loc_8232089C;
	// bne cr6,0x823217e8
	if (!ctx.cr6.eq) goto loc_823217E8;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823217e8
	if (!ctx.cr0.eq) goto loc_823217E8;
	// stw r19,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r19.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320860
	if (ctx.cr0.eq) goto loc_82320860;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320860;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320860:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82320894
	if (!ctx.cr6.gt) goto loc_82320894;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x82320894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320894:
	// stw r20,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r20.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_8232089C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2891
	ctx.r30.s64 = ctx.r30.s64 + -2891;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r29,20(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bne 0x82320924
	if (!ctx.cr0.eq) goto loc_82320924;
	// cmpwi cr6,r29,20
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 20, ctx.xer);
	// ble cr6,0x82320924
	if (!ctx.cr6.gt) goto loc_82320924;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// bl 0x8222ff78
	ctx.lr = 0x823208DC;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,296
	ctx.r3.s64 = ctx.r1.s64 + 296;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x823208F8;
	sub_8222FF78(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,60
	ctx.r3.s64 = 60;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x82240a58
	ctx.lr = 0x82320920;
	sub_82240A58(ctx, base);
	// stb r19,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r19.u8);
loc_82320924:
	// cmpwi cr6,r29,60
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 60, ctx.xer);
	// ble cr6,0x823217e8
	if (!ctx.cr6.gt) goto loc_823217E8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r9,3
	ctx.r9.s64 = 3;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// ori r11,r11,62668
	ctx.r11.u64 = ctx.r11.u64 | 62668;
	// stw r9,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// stwx r19,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r19.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x82320960;
	sub_8224A2A0(ctx, base);
	// b 0x823217e8
	goto loc_823217E8;
loc_82320964:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823217e8
	if (!ctx.cr0.eq) goto loc_823217E8;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8224a2a0
	ctx.lr = 0x82320990;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,62645
	ctx.r11.u64 = ctx.r11.u64 | 62645;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stbx r20,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u8);
	// b 0x823217e8
	goto loc_823217E8;
loc_823209A8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// ld r11,2880(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// stfs f29,288(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320a34
	if (ctx.cr0.eq) goto loc_82320A34;
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
loc_823209E0:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82320a14
	if (!ctx.cr6.lt) goto loc_82320A14;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82320A14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320A14:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823209e0
	if (ctx.cr6.lt) goto loc_823209E0;
loc_82320A34:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82320a68
	if (!ctx.cr6.gt) goto loc_82320A68;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x82320A68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320A68:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232918
	ctx.lr = 0x82320A74;
	sub_82232918(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// ori r11,r11,62628
	ctx.r11.u64 = ctx.r11.u64 | 62628;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// stfsx f29,r31,r11
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x82320AA0;
	sub_8224A2A0(ctx, base);
	// stw r19,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r19.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_82320AA8:
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,-2924
	ctx.r28.s64 = ctx.r28.s64 + -2924;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82320e1c
	if (ctx.cr6.lt) goto loc_82320E1C;
	// beq cr6,0x82320b90
	if (ctx.cr6.eq) goto loc_82320B90;
	// lfs f12,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f12.f64 = double(temp.f32);
	// li r10,3
	ctx.r10.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82320ad8
	if (ctx.cr6.lt) goto loc_82320AD8;
	// beq cr6,0x82320b24
	if (ctx.cr6.eq) goto loc_82320B24;
	// b 0x8232105c
	goto loc_8232105C;
loc_82320AD8:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2908
	ctx.r11.s64 = ctx.r11.s64 + -2908;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82320af8
	if (!ctx.cr6.gt) goto loc_82320AF8;
	// lfs f13,-712(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -712);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x82320b08
	goto loc_82320B08;
loc_82320AF8:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82320b10
	if (!ctx.cr6.lt) goto loc_82320B10;
	// lfs f13,-712(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -712);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_82320B08:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82320b24
	goto loc_82320B24;
loc_82320B10:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f29,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82320B24:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2920
	ctx.r11.s64 = ctx.r11.s64 + -2920;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8232105c
	if (!ctx.cr6.gt) goto loc_8232105C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62646
	ctx.r11.u64 = ctx.r11.u64 | 62646;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82320b84
	if (!ctx.cr0.eq) goto loc_82320B84;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62647
	ctx.r11.u64 = ctx.r11.u64 | 62647;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82320b84
	if (!ctx.cr0.eq) goto loc_82320B84;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62648
	ctx.r11.u64 = ctx.r11.u64 | 62648;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82320b84
	if (!ctx.cr0.eq) goto loc_82320B84;
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// b 0x82320f24
	goto loc_82320F24;
loc_82320B84:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// b 0x82320f24
	goto loc_82320F24;
loc_82320B90:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// bl 0x8222ff78
	ctx.lr = 0x82320BA4;
	sub_8222FF78(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-2948
	ctx.r4.s64 = ctx.r4.s64 + -2948;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82322d08
	ctx.lr = 0x82320BB8;
	sub_82322D08(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2940
	ctx.r11.s64 = ctx.r11.s64 + -2940;
	// lfs f13,21588(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 21588);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-2908
	ctx.r10.s64 = ctx.r10.s64 + -2908;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bge cr6,0x82320bf8
	if (!ctx.cr6.lt) goto loc_82320BF8;
	// lfs f13,-6068(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -6068);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// b 0x82320bfc
	goto loc_82320BFC;
loc_82320BF8:
	// stfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_82320BFC:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r10,-2936
	ctx.r10.s64 = ctx.r10.s64 + -2936;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r5,-32736
	ctx.r5.s64 = ctx.r5.s64 + -32736;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r26,r1,96
	ctx.r26.s64 = ctx.r1.s64 + 96;
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r27,r1,80
	ctx.r27.s64 = ctx.r1.s64 + 80;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r9,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r9.u64);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
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
	// lvx128 v0,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v12,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fsqrts f13,f13
	ctx.f13.f64 = double(float(sqrt(ctx.f13.f64)));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82320d28
	if (!ctx.cr6.lt) goto loc_82320D28;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_82320D28:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lfs f13,-712(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -712);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r29,-2920
	ctx.r29.s64 = ctx.r29.s64 + -2920;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82320d98
	if (!ctx.cr6.gt) goto loc_82320D98;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82320d74
	if (!ctx.cr6.gt) goto loc_82320D74;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320D74:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x82320e0c
	if (!ctx.cr6.gt) goto loc_82320E0C;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82320df8
	goto loc_82320DF8;
loc_82320D98:
	// lfs f13,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82320e0c
	if (!ctx.cr6.gt) goto loc_82320E0C;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x82320dd8
	if (!ctx.cr6.gt) goto loc_82320DD8;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82320DD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320DD8:
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
	// ble cr6,0x82320e0c
	if (!ctx.cr6.gt) goto loc_82320E0C;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_82320DF8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82320E0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320E0C:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// b 0x8232105c
	goto loc_8232105C;
loc_82320E1C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,62592
	ctx.r11.u64 = ctx.r11.u64 | 62592;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// addi r9,r9,-32400
	ctx.r9.s64 = ctx.r9.s64 + -32400;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lfsx f0,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r29,r29,-2948
	ctx.r29.s64 = ctx.r29.s64 + -2948;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,-13032(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -13032);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82320ea0
	if (ctx.cr6.eq) goto loc_82320EA0;
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aebd8
	ctx.lr = 0x82320EA0;
	sub_823AEBD8(ctx, base);
loc_82320EA0:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82320f2c
	if (!ctx.cr6.lt) goto loc_82320F2C;
	// stw r19,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r19.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320ef0
	if (ctx.cr0.eq) goto loc_82320EF0;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320EF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320EF0:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r10,4(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82320f24
	if (!ctx.cr6.gt) goto loc_82320F24;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x82320F24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320F24:
	// stw r20,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r20.u32);
	// b 0x8232105c
	goto loc_8232105C;
loc_82320F2C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// ld r11,2880(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// stfs f29,288(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82320f78
	if (ctx.cr0.eq) goto loc_82320F78;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320F78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320F78:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82320fac
	if (!ctx.cr6.gt) goto loc_82320FAC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
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
	ctx.lr = 0x82320FAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82320FAC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f13,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,62628
	ctx.r11.u64 = ctx.r11.u64 | 62628;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r10,r10,62584
	ctx.r10.u64 = ctx.r10.u64 | 62584;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stfsx f29,r31,r11
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r7,32496
	ctx.r7.s64 = ctx.r7.s64 + 32496;
	// lfs f13,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// stw r19,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r19.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
loc_8232105C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2892
	ctx.r30.s64 = ctx.r30.s64 + -2892;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823217e8
	if (!ctx.cr0.eq) goto loc_823217E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// bl 0x8222ff78
	ctx.lr = 0x82321084;
	sub_8222FF78(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-2932
	ctx.r10.s64 = ctx.r10.s64 + -2932;
	// ori r11,r11,62640
	ctx.r11.u64 = ctx.r11.u64 | 62640;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfsx f29,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stb r19,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r19.u8);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_823210B0:
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lfs f0,-6000(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -6000);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r28,-2908
	ctx.r28.s64 = ctx.r28.s64 + -2908;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x823210cc
	if (!ctx.cr6.lt) goto loc_823210CC;
	// fmadds f0,f30,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, ctx.f13.f64)));
loc_823210CC:
	// stfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
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
	ctx.lr = 0x823210E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// addi r30,r11,-7672
	ctx.r30.s64 = ctx.r11.s64 + -7672;
	// bne cr6,0x823211b4
	if (!ctx.cr6.eq) goto loc_823211B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,312
	ctx.r3.s64 = ctx.r1.s64 + 312;
	// bl 0x8222ff78
	ctx.lr = 0x82321110;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// lfs f1,-27680(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,12620(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8223f160
	ctx.lr = 0x82321128;
	sub_8223F160(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321270
	if (ctx.cr0.eq) goto loc_82321270;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ori r9,r9,62584
	ctx.r9.u64 = ctx.r9.u64 | 62584;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r10,r10,-31664
	ctx.r10.s64 = ctx.r10.s64 + -31664;
	// lfsx f0,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ori r9,r9,62592
	ctx.r9.u64 = ctx.r9.u64 | 62592;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62588
	ctx.r10.u64 = ctx.r10.u64 | 62588;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// b 0x82321270
	goto loc_82321270;
loc_823211B4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82321270
	if (!ctx.cr6.eq) goto loc_82321270;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// bl 0x8222ff78
	ctx.lr = 0x823211D0;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,-27680(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,12620(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8223f160
	ctx.lr = 0x823211E8;
	sub_8223F160(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321270
	if (ctx.cr0.eq) goto loc_82321270;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// ori r9,r9,62584
	ctx.r9.u64 = ctx.r9.u64 | 62584;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-31664
	ctx.r10.s64 = ctx.r10.s64 + -31664;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfsx f0,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ori r6,r6,62588
	ctx.r6.u64 = ctx.r6.u64 | 62588;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ori r10,r10,62592
	ctx.r10.u64 = ctx.r10.u64 | 62592;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
loc_82321270:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lfs f31,-2952(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2952);
	ctx.f31.f64 = double(temp.f32);
	// addi r29,r29,-2870
	ctx.r29.s64 = ctx.r29.s64 + -2870;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823212c4
	if (!ctx.cr0.eq) goto loc_823212C4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x8222ff78
	ctx.lr = 0x8232129C;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,12620(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,-27680(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f4,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8223ef20
	ctx.lr = 0x823212B8;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823212c4
	if (ctx.cr0.eq) goto loc_823212C4;
	// stb r19,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r19.u8);
loc_823212C4:
	// lfs f2,-2852(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2852);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x823212D4;
	sub_825A4A40(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-2920
	ctx.r29.s64 = ctx.r29.s64 + -2920;
	// addi r25,r25,-2940
	ctx.r25.s64 = ctx.r25.s64 + -2940;
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738cc0
	ctx.lr = 0x823212F0;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r25)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x82321300;
	sub_82738BE0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f28,84(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ori r11,r11,62600
	ctx.r11.u64 = ctx.r11.u64 | 62600;
	// stfs f28,92(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f28,80(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r22,r1,80
	ctx.r22.s64 = ctx.r1.s64 + 80;
	// stfs f28,88(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r21,r1,80
	ctx.r21.s64 = ctx.r1.s64 + 80;
	// addi r17,r1,80
	ctx.r17.s64 = ctx.r1.s64 + 80;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f13,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r18,r1,128
	ctx.r18.s64 = ctx.r1.s64 + 128;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r16,r1,128
	ctx.r16.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// bl 0x8222ff78
	ctx.lr = 0x82321410;
	sub_8222FF78(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,80
	ctx.r4.s64 = ctx.r31.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82322d08
	ctx.lr = 0x82321420;
	sub_82322D08(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8231e0d8
	ctx.lr = 0x8232142C;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// ld r9,128(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// lfs f12,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r4,264(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r5,-29488
	ctx.r5.s64 = ctx.r5.s64 + -29488;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f12,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82321608
	if (!ctx.cr0.eq) goto loc_82321608;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8222ff78
	ctx.lr = 0x823215D8;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,12620(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,-27680(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f4,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8223ef20
	ctx.lr = 0x823215F4;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321608
	if (ctx.cr0.eq) goto loc_82321608;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232918
	ctx.lr = 0x82321608;
	sub_82232918(ctx, base);
loc_82321608:
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82321618;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
	// bl 0x824281d8
	ctx.lr = 0x82321630;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823216d0
	if (ctx.cr0.eq) goto loc_823216D0;
	// bl 0x8242a5e0
	ctx.lr = 0x8232163C;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8232164c
	if (!ctx.cr0.eq) goto loc_8232164C;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// b 0x82321650
	goto loc_82321650;
loc_8232164C:
	// bl 0x8242aa28
	ctx.lr = 0x82321650;
	sub_8242AA28(ctx, base);
loc_82321650:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321734
	if (ctx.cr0.eq) goto loc_82321734;
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bne cr6,0x82321734
	if (!ctx.cr6.eq) goto loc_82321734;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x8222ff78
	ctx.lr = 0x82321674;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lfs f1,-27680(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,12620(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8223f160
	ctx.lr = 0x8232168C;
	sub_8223F160(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321734
	if (ctx.cr0.eq) goto loc_82321734;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,62612
	ctx.r11.u64 = ctx.r11.u64 | 62612;
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r20,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u32);
	// bl 0x82321b38
	ctx.lr = 0x823216B0;
	sub_82321B38(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r11,r11,62652
	ctx.r11.u64 = ctx.r11.u64 | 62652;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82322bb8
	ctx.lr = 0x823216CC;
	sub_82322BB8(ctx, base);
	// b 0x82321734
	goto loc_82321734;
loc_823216D0:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bne cr6,0x82321734
	if (!ctx.cr6.eq) goto loc_82321734;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8222ff78
	ctx.lr = 0x823216EC;
	sub_8222FF78(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lfs f1,-27680(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -27680);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,12620(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12620);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12652(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 12652);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8223f160
	ctx.lr = 0x82321704;
	sub_8223F160(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82321734
	if (ctx.cr0.eq) goto loc_82321734;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,62612
	ctx.r11.u64 = ctx.r11.u64 | 62612;
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r20,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r20.u32);
	// bl 0x82321b38
	ctx.lr = 0x82321728;
	sub_82321B38(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62652
	ctx.r11.u64 = ctx.r11.u64 | 62652;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
loc_82321734:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2892
	ctx.r30.s64 = ctx.r30.s64 + -2892;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823217e8
	if (!ctx.cr0.eq) goto loc_823217E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8222ff78
	ctx.lr = 0x8232175C;
	sub_8222FF78(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-2932
	ctx.r11.s64 = ctx.r11.s64 + -2932;
	// ori r10,r10,62640
	ctx.r10.u64 = ctx.r10.u64 | 62640;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfsx f29,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stb r19,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r19.u8);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// b 0x823217e8
	goto loc_823217E8;
loc_82321788:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8222ff78
	ctx.lr = 0x8232179C;
	sub_8222FF78(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r9,r9,-4080
	ctx.r9.s64 = ctx.r9.s64 + -4080;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r8,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// ori r10,r10,62596
	ctx.r10.u64 = ctx.r10.u64 | 62596;
	// lfs f2,236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 236);
	ctx.f2.f64 = double(temp.f32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r19,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r19.u32);
	// stw r9,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stdx r11,r31,r10
	REX_STORE_U64(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u64);
	// bl 0x825a4a40
	ctx.lr = 0x823217DC;
	sub_825A4A40(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62616
	ctx.r11.u64 = ctx.r11.u64 | 62616;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
loc_823217E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823218c0
	ctx.lr = 0x823217F0;
	sub_823218C0(ctx, base);
loc_823217F0:
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// li r0,-192
	ctx.r0.s64 = -192;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8273af74
	ctx.lr = 0x82321804;
	__restfpr_28(ctx, base);
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82408348) {
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
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r10,336(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8240838c
	if (!ctx.cr6.eq) goto loc_8240838C;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f13,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15656);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x824083b0
	if (!ctx.cr6.lt) goto loc_824083B0;
loc_8240838C:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x824083b8
	if (!ctx.cr6.eq) goto loc_824083B8;
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
	// bgt cr6,0x824083b8
	if (ctx.cr6.gt) goto loc_824083B8;
loc_824083B0:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x824083bc
	goto loc_824083BC;
loc_824083B8:
	// li r11,1
	ctx.r11.s64 = 1;
loc_824083BC:
	// lbz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x824083e0
	if (ctx.cr0.eq) goto loc_824083E0;
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x824083e0
	if (!ctx.cr0.eq) goto loc_824083E0;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x824083e4
	if (!ctx.cr0.eq) goto loc_824083E4;
loc_824083E0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_824083E4:
	// lwz r3,340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// stb r11,333(r31)
	REX_STORE_U8(ctx.r31.u32 + 333, ctx.r11.u8);
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r11,332(r31)
	REX_STORE_U8(ctx.r31.u32 + 332, ctx.r11.u8);
	// beq cr6,0x82408404
	if (ctx.cr6.eq) goto loc_82408404;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c9570
	ctx.lr = 0x82408404;
	sub_823C9570(ctx, base);
loc_82408404:
	// lwz r3,372(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82408418
	if (ctx.cr6.eq) goto loc_82408418;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c7628
	ctx.lr = 0x82408418;
	sub_823C7628(ctx, base);
loc_82408418:
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

DEFINE_REX_FUNC(sub_82410830) {
	REX_FUNC_PROLOGUE();
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r10,77(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 77);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r4,72(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823c60b0
	sub_823C60B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82410D40) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x82410f90
	sub_82410F90(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82410E88) {
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
	// lwz r3,60(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// bl 0x82457b58
	ctx.lr = 0x82410EA8;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x82410EAC;
	sub_825FD7A0(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// bl 0x82411620
	ctx.lr = 0x82410EC0;
	sub_82411620(ctx, base);
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
	ctx.lr = 0x82410ED8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82410ee8
	if (ctx.cr0.eq) goto loc_82410EE8;
	// bl 0x823c8308
	ctx.lr = 0x82410EE4;
	sub_823C8308(ctx, base);
	// b 0x82410eec
	goto loc_82410EEC;
loc_82410EE8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82410EEC:
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x82410f58
	if (ctx.cr6.eq) goto loc_82410F58;
	// cmpwi cr6,r11,29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 29, ctx.xer);
	// beq cr6,0x82410f50
	if (ctx.cr6.eq) goto loc_82410F50;
	// cmpwi cr6,r11,53
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 53, ctx.xer);
	// beq cr6,0x82410f48
	if (ctx.cr6.eq) goto loc_82410F48;
	// cmpwi cr6,r11,55
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 55, ctx.xer);
	// beq cr6,0x82410f40
	if (ctx.cr6.eq) goto loc_82410F40;
	// addi r11,r11,-56
	ctx.r11.s64 = ctx.r11.s64 + -56;
	// li r10,2
	ctx.r10.s64 = 2;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82410f5c
	goto loc_82410F5C;
loc_82410F40:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82410f5c
	goto loc_82410F5C;
loc_82410F48:
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// b 0x82410f60
	goto loc_82410F60;
loc_82410F50:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82410f5c
	goto loc_82410F5C;
loc_82410F58:
	// li r11,3
	ctx.r11.s64 = 3;
loc_82410F5C:
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_82410F60:
	// lwz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82410f74
	if (ctx.cr6.eq) goto loc_82410F74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82411870
	ctx.lr = 0x82410F74;
	sub_82411870(ctx, base);
loc_82410F74:
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

DEFINE_REX_FUNC(sub_8241B0A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8241B0B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2800(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2800);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241b0d4
	if (ctx.cr6.eq) goto loc_8241B0D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241b140
	goto loc_8241B140;
loc_8241B0D4:
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
	ctx.lr = 0x8241B0EC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8241b0fc
	if (ctx.cr0.eq) goto loc_8241B0FC;
	// bl 0x823c9508
	ctx.lr = 0x8241B0F8;
	sub_823C9508(ctx, base);
	// b 0x8241b100
	goto loc_8241B100;
loc_8241B0FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8241B100:
	// stw r3,2800(r31)
	REX_STORE_U32(ctx.r31.u32 + 2800, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8241b134
	if (ctx.cr6.eq) goto loc_8241B134;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// lwz r11,2800(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2800);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// stw r29,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r29.u32);
	// stb r10,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r10.u8);
loc_8241B134:
	// lwz r11,2800(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2800);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8241B140:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82421688) {
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
	// addi r11,r11,-30624
	ctx.r11.s64 = ctx.r11.s64 + -30624;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x824216c8
	if (ctx.cr6.eq) goto loc_824216C8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8241b7d0
	ctx.lr = 0x824216C0;
	sub_8241B7D0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x824216C8;
	sub_825E0378(ctx, base);
loc_824216C8:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// bl 0x823c4360
	ctx.lr = 0x824216D8;
	sub_823C4360(ctx, base);
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

DEFINE_REX_FUNC(sub_82425B30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82425B38;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r11,r11,-30596
	ctx.r11.s64 = ctx.r11.s64 + -30596;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82425bc4
	if (ctx.cr6.eq) goto loc_82425BC4;
	// lwz r3,92(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82425b70
	if (ctx.cr6.eq) goto loc_82425B70;
	// bl 0x823c74f0
	ctx.lr = 0x82425B70;
	sub_823C74F0(ctx, base);
loc_82425B70:
	// stw r28,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82425b84
	if (ctx.cr6.eq) goto loc_82425B84;
	// bl 0x823d1c58
	ctx.lr = 0x82425B84;
	sub_823D1C58(ctx, base);
loc_82425B84:
	// addi r30,r31,-4
	ctx.r30.s64 = ctx.r31.s64 + -4;
	// stw r28,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r28.u32);
	// li r29,17
	ctx.r29.s64 = 17;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
loc_82425B94:
	// lwz r11,-13064(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -13064);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82425bb0
	if (ctx.cr6.eq) goto loc_82425BB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82425bb0
	if (ctx.cr6.eq) goto loc_82425BB0;
	// bl 0x8235d960
	ctx.lr = 0x82425BB0;
	sub_8235D960(ctx, base);
loc_82425BB0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// bne 0x82425b94
	if (!ctx.cr0.eq) goto loc_82425B94;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82425BC4;
	sub_825E0378(ctx, base);
loc_82425BC4:
	// stw r28,156(r27)
	REX_STORE_U32(ctx.r27.u32 + 156, ctx.r28.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823c4360
	ctx.lr = 0x82425BD0;
	sub_823C4360(ctx, base);
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82425be0
	if (ctx.cr0.eq) goto loc_82425BE0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x825e0378
	ctx.lr = 0x82425BE0;
	sub_825E0378(ctx, base);
loc_82425BE0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8242A790) {
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
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r11,10464
	ctx.r11.s64 = ctx.r11.s64 + 10464;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242a7f4
	if (ctx.cr6.eq) goto loc_8242A7F4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r11,124(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242A7D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8242a7f4
	if (ctx.cr0.eq) goto loc_8242A7F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242A7EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8242a7f8
	goto loc_8242A7F8;
loc_8242A7F4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8242A7F8:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8263a7b8
	ctx.lr = 0x8242A81C;
	sub_8263A7B8(ctx, base);
	// mr. r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8242a830
	if (!ctx.cr0.eq) goto loc_8242A830;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// b 0x8242a850
	goto loc_8242A850;
loc_8242A830:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8263a7b8
	ctx.lr = 0x8242A850;
	sub_8263A7B8(ctx, base);
loc_8242A850:
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

DEFINE_REX_FUNC(sub_82430A88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82430A90;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lfs f0,2260(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2260);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,32384
	ctx.r11.s64 = ctx.r11.s64 + 32384;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// lfs f13,2440(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2440);
	ctx.f13.f64 = double(temp.f32);
	// li r9,432
	ctx.r9.s64 = 432;
	// lfs f12,2432(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2432);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v4,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// vrefp v0,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v4.f32)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v12,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v10,v4,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lvx128 v2,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vor v11,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v4.u8));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vrefp v13,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v11.f32)));
	// stfs f12,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vcmpeqfp128 v6,v11,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v7,v0,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vnmsubfp v5,v4,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f12,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v8,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v1,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsel v31,v10,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vmaddfp v7,v0,v5,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// li r8,432
	ctx.r8.s64 = 432;
	// vcmpeqfp128 v5,v13,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vor v0,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vnmsubfp v12,v4,v7,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v30,v6,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmaddfp v12,v7,v12,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vsel v7,v12,v8,v31
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vmaddfp v12,v1,v7,v2
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lvx128 v8,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v12,v11,v13,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// lfs f13,2444(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2436(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2436);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,2264(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
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
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v13,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vaddfp128 v9,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vnmsubfp v8,v11,v12,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v10,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v12,v8,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsel v12,v13,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmaddfp v0,v9,v12,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v0,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 952);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82430C04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82430c24
	if (ctx.cr0.eq) goto loc_82430C24;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82435690
	ctx.lr = 0x82430C18;
	sub_82435690(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8254bb70
	ctx.lr = 0x82430C24;
	sub_8254BB70(ctx, base);
loc_82430C24:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82447BA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82447BB0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82447bdc
	if (!ctx.cr6.lt) goto loc_82447BDC;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447b38
	ctx.lr = 0x82447BDC;
	sub_82447B38(ctx, base);
loc_82447BDC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82447bf8
	if (!ctx.cr6.lt) goto loc_82447BF8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82447b38
	ctx.lr = 0x82447BF8;
	sub_82447B38(ctx, base);
loc_82447BF8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82447c14
	if (!ctx.cr6.lt) goto loc_82447C14;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447b38
	ctx.lr = 0x82447C14;
	sub_82447B38(ctx, base);
loc_82447C14:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244BE68) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x8244BE8C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244beac
	if (ctx.cr0.eq) goto loc_8244BEAC;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8244BEA4;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8244BEAC:
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

DEFINE_REX_FUNC(sub_8244D148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8244D150;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244d420
	if (ctx.cr6.eq) goto loc_8244D420;
	// lwz r11,40(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// lfs f0,76(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8244d188
	if (!ctx.cr6.eq) goto loc_8244D188;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f12,12472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
loc_8244D188:
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82430a10
	ctx.lr = 0x8244D1E0;
	sub_82430A10(ctx, base);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x8244D1F8;
	sub_8255F918(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lwz r9,2352(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 2352);
	// lbz r10,2364(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2364);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8244d240
	if (!ctx.cr6.eq) goto loc_8244D240;
	// beq 0x8244d22c
	if (ctx.cr0.eq) goto loc_8244D22C;
	// lbz r11,2365(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2365);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x8244d230
	if (ctx.cr0.eq) goto loc_8244D230;
loc_8244D22C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8244D230:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244d264
	if (ctx.cr0.eq) goto loc_8244D264;
	// lis r29,16384
	ctx.r29.s64 = 1073741824;
	// b 0x8244d26c
	goto loc_8244D26C;
loc_8244D240:
	// beq 0x8244d254
	if (ctx.cr0.eq) goto loc_8244D254;
	// lbz r11,2365(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2365);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x8244d258
	if (ctx.cr0.eq) goto loc_8244D258;
loc_8244D254:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8244D258:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r29,16384
	ctx.r29.s64 = 1073741824;
	// bne 0x8244d268
	if (!ctx.cr0.eq) goto loc_8244D268;
loc_8244D264:
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
loc_8244D268:
	// ori r29,r29,1
	ctx.r29.u64 = ctx.r29.u64 | 1;
loc_8244D26C:
	// lwz r3,64(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// bl 0x82453810
	ctx.lr = 0x8244D274;
	sub_82453810(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r31,r10,-24848
	ctx.r31.s64 = ctx.r10.s64 + -24848;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8244D290:
	// li r8,1
	ctx.r8.s64 = 1;
	// slw r8,r8,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// and. r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 & ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8244d2a8
	if (ctx.cr0.eq) goto loc_8244D2A8;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_8244D2A8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8244d290
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244D290;
	// lwz r4,64(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// or r23,r10,r29
	ctx.r23.u64 = ctx.r10.u64 | ctx.r29.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82439948
	ctx.lr = 0x8244D2C4;
	sub_82439948(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lfs f0,424(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 424);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// fmuls f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r9,r9,32384
	ctx.r9.s64 = ctx.r9.s64 + 32384;
	// lwz r10,68(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-32128
	ctx.r11.s64 = ctx.r11.s64 + -32128;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// li r24,0
	ctx.r24.s64 = 0;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ble cr6,0x8244d420
	if (!ctx.cr6.gt) goto loc_8244D420;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r31,r30,92
	ctx.r31.s64 = ctx.r30.s64 + 92;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// lis r26,-32114
	ctx.r26.s64 = -2104623104;
	// addi r25,r11,2668
	ctx.r25.s64 = ctx.r11.s64 + 2668;
	// addi r29,r10,2688
	ctx.r29.s64 = ctx.r10.s64 + 2688;
	// addi r28,r9,2880
	ctx.r28.s64 = ctx.r9.s64 + 2880;
loc_8244D35C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8255f918
	ctx.lr = 0x8244D36C;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// bl 0x8255f918
	ctx.lr = 0x8244D37C;
	sub_8255F918(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8255f918
	ctx.lr = 0x8244D38C;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x8255f918
	ctx.lr = 0x8244D39C;
	sub_8255F918(ctx, base);
	// lwz r11,-13032(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// ld r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// li r9,1
	ctx.r9.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r29,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r29.u32);
	// stw r9,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r9.u32);
	// std r10,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r10.u64);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// beq cr6,0x8244d3fc
	if (ctx.cr6.eq) goto loc_8244D3FC;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r8,148(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,-9016(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -9016);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r6,4(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x823b0938
	ctx.lr = 0x8244D3FC;
	sub_823B0938(ctx, base);
loc_8244D3FC:
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82433708
	ctx.lr = 0x8244D408;
	sub_82433708(ctx, base);
	// lwz r11,68(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r25,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r25.u32);
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8244d35c
	if (ctx.cr6.lt) goto loc_8244D35C;
loc_8244D420:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82465E08) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// beq cr6,0x82465f48
	if (ctx.cr6.eq) goto loc_82465F48;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x82465f48
	if (ctx.cr6.eq) goto loc_82465F48;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12972);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,832(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 832);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82465f48
	if (ctx.cr6.lt) goto loc_82465F48;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x82465f48
	if (!ctx.cr6.lt) goto loc_82465F48;
	// addi r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 + 100;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82465f48
	if (ctx.cr6.eq) goto loc_82465F48;
	// lwz r11,128(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x82465f1c
	if (ctx.cr6.eq) goto loc_82465F1C;
	// cmplwi cr6,r11,34
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 34, ctx.xer);
	// bne cr6,0x82465f48
	if (!ctx.cr6.eq) goto loc_82465F48;
	// bl 0x8242a5e0
	ctx.lr = 0x82465E80;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82465f48
	if (ctx.cr0.eq) goto loc_82465F48;
	// bl 0x82213210
	ctx.lr = 0x82465E8C;
	sub_82213210(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r11,4040(r3)
	REX_STORE_U8(ctx.r3.u32 + 4040, ctx.r11.u8);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x82213210
	ctx.lr = 0x82465EA0;
	sub_82213210(ctx, base);
	// lwz r30,19228(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// bl 0x8242a5e0
	ctx.lr = 0x82465EA8;
	sub_8242A5E0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ed598
	ctx.lr = 0x82465EB4;
	sub_823ED598(ctx, base);
	// addi r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 1;
	// bl 0x82213210
	ctx.lr = 0x82465EBC;
	sub_82213210(ctx, base);
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// stb r11,4033(r3)
	REX_STORE_U8(ctx.r3.u32 + 4033, ctx.r11.u8);
	// bl 0x82213210
	ctx.lr = 0x82465EC8;
	sub_82213210(ctx, base);
	// lbz r3,4033(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// bl 0x82443da0
	ctx.lr = 0x82465ED0;
	sub_82443DA0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x82465ED8;
	sub_82213210(ctx, base);
	// stb r30,4032(r3)
	REX_STORE_U8(ctx.r3.u32 + 4032, ctx.r30.u8);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,76
	ctx.r4.s64 = 76;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82465EF4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82465f08
	if (ctx.cr0.eq) goto loc_82465F08;
	// bl 0x824602d0
	ctx.lr = 0x82465F00;
	sub_824602D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82465f0c
	goto loc_82465F0C;
loc_82465F08:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82465F0C:
	// stw r4,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x825afa28
	ctx.lr = 0x82465F18;
	sub_825AFA28(ctx, base);
	// b 0x82465f48
	goto loc_82465F48;
loc_82465F1C:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r3,r11,10304
	ctx.r3.s64 = ctx.r11.s64 + 10304;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// lwz r11,10304(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 10304);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82465F3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,10
	ctx.r11.s64 = 10;
	// stb r30,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r30.u8);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82465F48:
	// li r3,1
	ctx.r3.s64 = 1;
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

DEFINE_REX_FUNC(sub_82470F10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82470F18;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r7,-1
	ctx.r10.s64 = ctx.r7.s64 + -1;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,67
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 67, ctx.xer);
	// and r25,r10,r9
	ctx.r25.u64 = ctx.r10.u64 & ctx.r9.u64;
	// bgt cr6,0x82471234
	if (ctx.cr6.gt) goto loc_82471234;
	// beq cr6,0x824711fc
	if (ctx.cr6.eq) goto loc_824711FC;
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// bgt cr6,0x824710b4
	if (ctx.cr6.gt) goto loc_824710B4;
	// beq cr6,0x8247107c
	if (ctx.cr6.eq) goto loc_8247107C;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82471054
	if (ctx.cr6.eq) goto loc_82471054;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x8247102c
	if (ctx.cr6.eq) goto loc_8247102C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x82470ff0
	if (ctx.cr6.eq) goto loc_82470FF0;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// beq cr6,0x82470fb4
	if (ctx.cr6.eq) goto loc_82470FB4;
	// cmpwi cr6,r11,17
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 17, ctx.xer);
	// bne cr6,0x824714f4
	if (!ctx.cr6.eq) goto loc_824714F4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825738f8
	ctx.lr = 0x82470FB0;
	sub_825738F8(ctx, base);
	// b 0x824714f4
	goto loc_824714F4;
loc_82470FB4:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// ld r28,0(r28)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,300
	ctx.r4.s64 = 300;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82470FD0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82563738
	ctx.lr = 0x82470FEC;
	sub_82563738(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82470FF0:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,340
	ctx.r4.s64 = 340;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471008;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// li r7,10
	ctx.r7.s64 = 10;
loc_82471014:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82568ee8
	ctx.lr = 0x82471028;
	sub_82568EE8(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_8247102C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,340
	ctx.r4.s64 = 340;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471044;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// li r7,7
	ctx.r7.s64 = 7;
	// b 0x82471014
	goto loc_82471014;
loc_82471054:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,340
	ctx.r4.s64 = 340;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8247106C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// li r7,6
	ctx.r7.s64 = 6;
	// b 0x82471014
	goto loc_82471014;
loc_8247107C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,332
	ctx.r4.s64 = 332;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471094;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82569980
	ctx.lr = 0x824710B0;
	sub_82569980(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824710B4:
	// cmpwi cr6,r11,29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 29, ctx.xer);
	// beq cr6,0x824711c4
	if (ctx.cr6.eq) goto loc_824711C4;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// beq cr6,0x8247118c
	if (ctx.cr6.eq) goto loc_8247118C;
	// cmpwi cr6,r11,34
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 34, ctx.xer);
	// beq cr6,0x82471150
	if (ctx.cr6.eq) goto loc_82471150;
	// cmpwi cr6,r11,57
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 57, ctx.xer);
	// beq cr6,0x82471118
	if (ctx.cr6.eq) goto loc_82471118;
	// cmpwi cr6,r11,66
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 66, ctx.xer);
	// bne cr6,0x824714f4
	if (!ctx.cr6.eq) goto loc_824714F4;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,316
	ctx.r4.s64 = 316;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824710F4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// li r7,66
	ctx.r7.s64 = 66;
loc_82471100:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82571368
	ctx.lr = 0x82471114;
	sub_82571368(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471118:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,368
	ctx.r4.s64 = 368;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471130;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82563e38
	ctx.lr = 0x8247114C;
	sub_82563E38(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471150:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,320
	ctx.r4.s64 = 320;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471168;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825726f8
	ctx.lr = 0x82471188;
	sub_825726F8(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_8247118C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,332
	ctx.r4.s64 = 332;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824711A4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8256fa40
	ctx.lr = 0x824711C0;
	sub_8256FA40(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824711C4:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,336
	ctx.r4.s64 = 336;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824711DC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825681f0
	ctx.lr = 0x824711F8;
	sub_825681F0(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824711FC:
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
	ctx.lr = 0x82471214;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82570cf0
	ctx.lr = 0x82471230;
	sub_82570CF0(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471234:
	// cmpwi cr6,r11,76
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 76, ctx.xer);
	// bgt cr6,0x824713a4
	if (ctx.cr6.gt) goto loc_824713A4;
	// beq cr6,0x82471370
	if (ctx.cr6.eq) goto loc_82471370;
	// cmpwi cr6,r11,68
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 68, ctx.xer);
	// beq cr6,0x82471338
	if (ctx.cr6.eq) goto loc_82471338;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// beq cr6,0x82471300
	if (ctx.cr6.eq) goto loc_82471300;
	// cmpwi cr6,r11,70
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 70, ctx.xer);
	// beq cr6,0x824712d8
	if (ctx.cr6.eq) goto loc_824712D8;
	// cmpwi cr6,r11,71
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 71, ctx.xer);
	// beq cr6,0x824712a0
	if (ctx.cr6.eq) goto loc_824712A0;
	// cmpwi cr6,r11,72
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 72, ctx.xer);
	// bne cr6,0x824714f4
	if (!ctx.cr6.eq) goto loc_824714F4;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,368
	ctx.r4.s64 = 368;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471280;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8256a8c8
	ctx.lr = 0x8247129C;
	sub_8256A8C8(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824712A0:
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
	ctx.lr = 0x824712B8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82573340
	ctx.lr = 0x824712D4;
	sub_82573340(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824712D8:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,316
	ctx.r4.s64 = 316;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824712F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// li r7,70
	ctx.r7.s64 = 70;
	// b 0x82471100
	goto loc_82471100;
loc_82471300:
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
	ctx.lr = 0x82471318;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82565510
	ctx.lr = 0x82471334;
	sub_82565510(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471338:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,316
	ctx.r4.s64 = 316;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471350;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8256e298
	ctx.lr = 0x8247136C;
	sub_8256E298(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471370:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,312
	ctx.r4.s64 = 312;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82471388;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8256cda8
	ctx.lr = 0x824713A0;
	sub_8256CDA8(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824713A4:
	// cmpwi cr6,r11,77
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 77, ctx.xer);
	// beq cr6,0x824714b0
	if (ctx.cr6.eq) goto loc_824714B0;
	// cmpwi cr6,r11,110
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 110, ctx.xer);
	// beq cr6,0x8247148c
	if (ctx.cr6.eq) goto loc_8247148C;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x82471454
	if (ctx.cr6.eq) goto loc_82471454;
	// cmpwi cr6,r11,133
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 133, ctx.xer);
	// beq cr6,0x82471410
	if (ctx.cr6.eq) goto loc_82471410;
	// cmpwi cr6,r11,134
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 134, ctx.xer);
	// bne cr6,0x824714f4
	if (!ctx.cr6.eq) goto loc_824714F4;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// ld r28,0(r28)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,924
	ctx.r4.s64 = 924;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824713E8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8251baa8
	ctx.lr = 0x8247140C;
	sub_8251BAA8(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471410:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// ld r28,0(r28)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,360
	ctx.r4.s64 = 360;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8247142C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8251ef60
	ctx.lr = 0x82471450;
	sub_8251EF60(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_82471454:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,340
	ctx.r4.s64 = 340;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8247146C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82566c70
	ctx.lr = 0x82471488;
	sub_82566C70(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_8247148C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82565d28
	ctx.lr = 0x824714AC;
	sub_82565D28(ctx, base);
	// b 0x824714f4
	goto loc_824714F4;
loc_824714B0:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,340
	ctx.r4.s64 = 340;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824714C8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824714e4
	if (ctx.cr0.eq) goto loc_824714E4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8256d808
	ctx.lr = 0x824714E0;
	sub_8256D808(ctx, base);
	// b 0x824714e8
	goto loc_824714E8;
loc_824714E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824714E8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824714f4
	if (ctx.cr6.eq) goto loc_824714F4;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_824714F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249DA78) {
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
	// addi r11,r11,-22448
	ctx.r11.s64 = ctx.r11.s64 + -22448;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x825a4750
	ctx.lr = 0x8249DAA0;
	sub_825A4750(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469ee8
	ctx.lr = 0x8249DAA8;
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

DEFINE_REX_FUNC(sub_8249EF10) {
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
	// lwz r11,296(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8249f018
	if (ctx.cr6.lt) goto loc_8249F018;
	// beq cr6,0x8249ef78
	if (ctx.cr6.eq) goto loc_8249EF78;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8249ef64
	if (ctx.cr6.eq) goto loc_8249EF64;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x8249ef58
	if (ctx.cr6.eq) goto loc_8249EF58;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x8249f290
	if (!ctx.cr6.eq) goto loc_8249F290;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x8249f290
	goto loc_8249F290;
loc_8249EF58:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// b 0x8249f290
	goto loc_8249F290;
loc_8249EF64:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r11,428(r31)
	REX_STORE_U8(ctx.r31.u32 + 428, ctx.r11.u8);
	// stw r10,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r10.u32);
	// b 0x8249f290
	goto loc_8249F290;
loc_8249EF78:
	// lfs f0,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fmadds f0,f13,f1,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, ctx.f0.f64)));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// lfs f13,288(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r31,44
	ctx.r4.s64 = ctx.r31.s64 + 44;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,292(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// bl 0x8249f540
	ctx.lr = 0x8249F014;
	sub_8249F540(ctx, base);
	// b 0x8249f290
	goto loc_8249F290;
loc_8249F018:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,2880
	ctx.r11.s64 = ctx.r11.s64 + 2880;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r10,r10,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8249f0b4
	if (ctx.cr0.eq) goto loc_8249F0B4;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,292(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8249f0b8
	if (!ctx.cr0.eq) goto loc_8249F0B8;
loc_8249F0B4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8249F0B8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249f170
	if (ctx.cr0.eq) goto loc_8249F170;
	// lwz r4,300(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x8249f108
	if (!ctx.cr6.eq) goto loc_8249F108;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r9,r9,32688
	ctx.r9.s64 = ctx.r9.s64 + 32688;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x8249f130
	goto loc_8249F130;
loc_8249F108:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_8249F130:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,288(r31)
	REX_STORE_U64(ctx.r31.u32 + 288, ctx.r11.u64);
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
	// bctrl 
	ctx.lr = 0x8249F150;
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
	ctx.lr = 0x8249F16C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8249f25c
	goto loc_8249F25C;
loc_8249F170:
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8249f1a8
	if (!ctx.cr6.eq) goto loc_8249F1A8;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,32608
	ctx.r10.s64 = ctx.r10.s64 + 32608;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8249f1bc
	goto loc_8249F1BC;
loc_8249F1A8:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249F1BC:
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x8249F1E0;
	sub_8231E0D8(ctx, base);
	// ld r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 288);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x825a4da8
	ctx.lr = 0x8249F200;
	sub_825A4DA8(ctx, base);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r4,300(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8249F224;
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
	ctx.lr = 0x8249F240;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	ctx.lr = 0x8249F25C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249F25C:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stw r9,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,30184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30184);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r8,-22308
	ctx.r3.s64 = ctx.r8.s64 + -22308;
	// lfs f13,17092(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17092);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r31,280
	ctx.r4.s64 = ctx.r31.s64 + 280;
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// bl 0x8257d4d8
	ctx.lr = 0x8249F290;
	sub_8257D4D8(ctx, base);
loc_8249F290:
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

DEFINE_REX_FUNC(sub_824BD430) {
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
	// std r4,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r4.u64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r11,32432
	ctx.r9.s64 = ctx.r11.s64 + 32432;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r11,4440
	ctx.r31.s64 = ctx.r11.s64 + 4440;
	// lfs f13,324(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,100
	ctx.r4.s64 = 100;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// lfs f0,-2832(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -2832);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// fctiwz f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x824BD4C4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824bd508
	if (ctx.cr0.eq) goto loc_824BD508;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// lfs f0,-10852(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -10852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r10,r9,-4080
	ctx.r10.s64 = ctx.r9.s64 + -4080;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f1,244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82218490
	ctx.lr = 0x824BD500;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824bd50c
	goto loc_824BD50C;
loc_824BD508:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824BD50C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824bd550
	if (ctx.cr6.eq) goto loc_824BD550;
	// lis r11,-32180
	ctx.r11.s64 = -2108948480;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-10904
	ctx.r11.s64 = ctx.r11.s64 + -10904;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x824BD52C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824bd550
	if (!ctx.cr6.eq) goto loc_824BD550;
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
	ctx.lr = 0x824BD550;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824BD550:
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

DEFINE_REX_FUNC(sub_824CCFC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824CCFC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r6,12
	ctx.r6.s64 = 12;
	// addi r4,r10,-16508
	ctx.r4.s64 = ctx.r10.s64 + -16508;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824689b0
	ctx.lr = 0x824CCFEC;
	sub_824689B0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r8,4
	ctx.r8.s64 = 4;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// addi r9,r11,-16496
	ctx.r9.s64 = ctx.r11.s64 + -16496;
	// addi r10,r31,280
	ctx.r10.s64 = ctx.r31.s64 + 280;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r9,r10,-68
	ctx.r9.s64 = ctx.r10.s64 + -68;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
loc_824CD020:
	// ld r7,3456(r10)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stdu r7,68(r9)
	ea = 68 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r7.u64);
	ctx.r9.u32 = ea;
	// ld r7,3456(r10)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r7,12(r11)
	REX_STORE_U64(ctx.r11.u32 + 12, ctx.r7.u64);
	// ld r7,3456(r10)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r7,20(r11)
	REX_STORE_U64(ctx.r11.u32 + 20, ctx.r7.u64);
	// ld r7,2880(r8)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r8.u32 + 2880);
	// stfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stw r30,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r30.u32);
	// stfs f0,48(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stb r30,56(r11)
	REX_STORE_U8(ctx.r11.u32 + 56, ctx.r30.u8);
	// stfs f0,52(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// stw r30,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r30.u32);
	// stfs f0,64(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// std r7,28(r11)
	REX_STORE_U64(ctx.r11.u32 + 28, ctx.r7.u64);
	// stbu r30,68(r11)
	ea = 68 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x824cd020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824CD020;
	// ld r11,2880(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 2880);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-24673
	ctx.r9.s64 = -1616969728;
	// addi r29,r10,-4080
	ctx.r29.s64 = ctx.r10.s64 + -4080;
	// ori r10,r9,65407
	ctx.r10.u64 = ctx.r9.u64 | 65407;
	// li r9,-1
	ctx.r9.s64 = -1;
	// std r11,552(r31)
	REX_STORE_U64(ctx.r31.u32 + 552, ctx.r11.u64);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r8,0(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r8.u32);
	// lfs f13,1532(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1532);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,4(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stfs f0,576(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 576, temp.u32);
	// stfs f0,580(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 580, temp.u32);
	// stw r30,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r30.u32);
	// stfs f0,584(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 584, temp.u32);
	// stw r30,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r30.u32);
	// stfs f0,588(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 588, temp.u32);
	// stb r30,616(r31)
	REX_STORE_U8(ctx.r31.u32 + 616, ctx.r30.u8);
	// stfs f0,592(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 592, temp.u32);
	// stw r8,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r8.u32);
	// stfs f0,596(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 596, temp.u32);
	// stw r10,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r10.u32);
	// stfs f0,600(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 600, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f0,604(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 604, temp.u32);
	// li r4,96
	ctx.r4.s64 = 96;
	// stfs f13,620(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 620, temp.u32);
	// stw r9,628(r31)
	REX_STORE_U32(ctx.r31.u32 + 628, ctx.r9.u32);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824CD0E8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824cd10c
	if (ctx.cr0.eq) goto loc_824CD10C;
	// lis r6,3855
	ctx.r6.s64 = 252641280;
	// lfs f2,244(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 244);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,624(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// lfs f1,576(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 576);
	ctx.f1.f64 = double(temp.f32);
	// ori r6,r6,65295
	ctx.r6.u64 = ctx.r6.u64 | 65295;
	// bl 0x82224fa0
	ctx.lr = 0x824CD108;
	sub_82224FA0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_824CD10C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824cd14c
	if (ctx.cr6.eq) goto loc_824CD14C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x824CD120;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,628(r31)
	REX_STORE_U32(ctx.r31.u32 + 628, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824cd14c
	if (!ctx.cr6.eq) goto loc_824CD14C;
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
	ctx.lr = 0x824CD14C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824CD14C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D5198) {
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
	// bl 0x824d51f0
	ctx.lr = 0x824D51B8;
	sub_824D51F0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d51d0
	if (ctx.cr0.eq) goto loc_824D51D0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824d51d0
	if (ctx.cr6.eq) goto loc_824D51D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824D51D0;
	sub_825E0378(ctx, base);
loc_824D51D0:
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

DEFINE_REX_FUNC(sub_824D6FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824D6FD0;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x824d7294
	if (!ctx.cr6.lt) goto loc_824D7294;
	// lwz r11,352(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 352);
	// addi r29,r3,344
	ctx.r29.s64 = ctx.r3.s64 + 344;
	// lwz r10,348(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 348);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d729c
	if (ctx.cr0.eq) goto loc_824D729C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r28,r11,12468
	ctx.r28.s64 = ctx.r11.s64 + 12468;
	// lwz r11,-12872(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// lfs f31,-232(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824d702c
	if (ctx.cr6.eq) goto loc_824D702C;
	// lfs f0,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824d7030
	goto loc_824D7030;
loc_824D702C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_824D7030:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// fdivs f0,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
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
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// lwz r11,-15444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// vpermwi128 v62,v63,234
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x15));
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x45));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// vpermwi128 v60,v63,174
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x51));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// vpermwi128 v63,v63,171
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x54));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f12,f0
	ctx.f30.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f29,f13,f0
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x825f8d38
	ctx.lr = 0x824D70B0;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x824d70e8
	if (ctx.cr0.eq) goto loc_824D70E8;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r29,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r29.s64 = ctx.r11.s32 >> 3;
	// bl 0x825f8b88
	ctx.lr = 0x824D70D0;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x824D70E4;
	sub_825F8BF8(ctx, base);
	// b 0x824d70ec
	goto loc_824D70EC;
loc_824D70E8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824D70EC:
	// lwz r10,348(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lwz r9,352(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 352);
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r8,r8,-31476
	ctx.r8.s64 = ctx.r8.s64 + -31476;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x824d71fc
	if (ctx.cr6.eq) goto loc_824D71FC;
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1908(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f30,f0
	ctx.f12.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f13.f64));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
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
loc_824D7144:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,256
	ctx.r5.s64 = 16777216;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r7,4(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r4,8(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r3,12(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r6,0(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// stw r3,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// lwz r7,328(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// stw r7,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bne cr6,0x824d7144
	if (!ctx.cr6.eq) goto loc_824D7144;
loc_824D71FC:
	// lwz r11,336(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 336);
	// lfs f12,22832(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 22832);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// stb r10,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r10.u8);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stb r9,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r9.u8);
	// li r5,64
	ctx.r5.s64 = 64;
	// lhz r10,6(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f13,-1720(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -1720);
	ctx.f13.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f0,-1704(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -1704);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmadds f0,f13,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f0.f64)));
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r11,3596(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 3596);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x824D7280;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x824D7290;
	sub_82459D08(ctx, base);
	// b 0x824d729c
	goto loc_824D729C;
loc_824D7294:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824693b8
	ctx.lr = 0x824D729C;
	sub_824693B8(ctx, base);
loc_824D729C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824EB668) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824EB670;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r3,92
	ctx.r30.s64 = ctx.r3.s64 + 92;
	// addi r11,r11,-11556
	ctx.r11.s64 = ctx.r11.s64 + -11556;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82249308
	ctx.lr = 0x824EB694;
	sub_82249308(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8222f978
	ctx.lr = 0x824EB69C;
	sub_8222F978(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// clrlwi. r10,r29,31
	ctx.r10.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,136
	ctx.r11.s64 = ctx.r11.s64 + 136;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq 0x824eb6b8
	if (ctx.cr0.eq) goto loc_824EB6B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824EB6B8;
	sub_825E0378(ctx, base);
loc_824EB6B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824ECF38) {
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
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,-11288
	ctx.r4.s64 = ctx.r11.s64 + -11288;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x824ECF5C;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824ecf6c
	if (!ctx.cr0.eq) goto loc_824ECF6C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_824ECF6C:
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

DEFINE_REX_FUNC(sub_824EE298) {
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
	// li r5,37
	ctx.r5.s64 = 37;
	// addi r30,r11,1340
	ctx.r30.s64 = ctx.r11.s64 + 1340;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824EE2C4;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824ee2d8
	if (!ctx.cr0.eq) goto loc_824EE2D8;
loc_824EE2CC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_824EE2D0:
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x824ee310
	goto loc_824EE310;
loc_824EE2D8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824EE2E8;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824ee2cc
	if (ctx.cr0.eq) goto loc_824EE2CC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,18
	ctx.r5.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x824EE300;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x824ee2d0
	if (ctx.cr0.eq) goto loc_824EE2D0;
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
loc_824EE310:
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

DEFINE_REX_FUNC(sub_824F1E90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824F1E98;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,132
	ctx.r4.s64 = 132;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824F1EBC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824f1ed0
	if (ctx.cr0.eq) goto loc_824F1ED0;
	// bl 0x824f2200
	ctx.lr = 0x824F1EC8;
	sub_824F2200(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824f1ed4
	goto loc_824F1ED4;
loc_824F1ED0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824F1ED4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f1fd0
	if (ctx.cr6.eq) goto loc_824F1FD0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,1056(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1056);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f13,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824f1ef8
	if (ctx.cr6.eq) goto loc_824F1EF8;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_824F1EF8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f12,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-20452(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -20452);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824F1FA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x824F1FAC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824f1fd0
	if (!ctx.cr6.eq) goto loc_824F1FD0;
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
	ctx.lr = 0x824F1FD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824F1FD0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824FAB88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824FAB90;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// clrlwi r26,r7,24
	ctx.r26.u64 = ctx.r7.u32 & 0xFF;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// addi r4,r10,-9604
	ctx.r4.s64 = ctx.r10.s64 + -9604;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// li r8,11
	ctx.r8.s64 = 11;
	// li r7,13
	ctx.r7.s64 = 13;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x824FABD0;
	sub_825190E8(ctx, base);
	// rlwinm r11,r28,31,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x7F;
	// extsw r10,r26
	ctx.r10.s64 = ctx.r26.s32;
	// stb r26,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r26.u8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r29,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r29.u32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stw r11,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// addi r7,r11,12472
	ctx.r7.s64 = ctx.r11.s64 + 12472;
	// lfs f0,12472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// lfs f13,-17296(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17296);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17300);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r6,-9592
	ctx.r10.s64 = ctx.r6.s64 + -9592;
	// lfs f11,112(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// subfe r11,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// fmadds f13,f10,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,-4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f12,f11,f9
	ctx.f12.f64 = double(float(ctx.f11.f64 / ctx.f9.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stb r11,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r11.u8);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stw r9,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r9.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f12,396(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stb r27,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r27.u8);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82505E20) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-7908
	ctx.r4.s64 = ctx.r11.s64 + -7908;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x82505E48;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82505e5c
	if (!ctx.cr0.eq) goto loc_82505E5C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r30)
	REX_STORE_U8(ctx.r30.u32 + 23, ctx.r11.u8);
	// b 0x82505ebc
	goto loc_82505EBC;
loc_82505E5C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r10,3204
	ctx.r3.s64 = ctx.r10.s64 + 3204;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82505E78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x82505E7C;
	sub_8245A220(ctx, base);
	// stw r3,324(r30)
	REX_STORE_U32(ctx.r30.u32 + 324, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x82505E8C;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82505eb4
	if (ctx.cr0.eq) goto loc_82505EB4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x82505E9C;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x82505EB0;
	sub_825F8BF8(ctx, base);
	// b 0x82505eb8
	goto loc_82505EB8;
loc_82505EB4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82505EB8:
	// stw r31,328(r30)
	REX_STORE_U32(ctx.r30.u32 + 328, ctx.r31.u32);
loc_82505EBC:
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

DEFINE_REX_FUNC(sub_8250A720) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8250A728;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,800
	ctx.r4.s64 = 800;
	// li r3,400
	ctx.r3.s64 = 400;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
	// bl 0x825a49b0
	ctx.lr = 0x8250A754;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f31,14280(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14280);
	ctx.f31.f64 = double(temp.f32);
	// li r4,5000
	ctx.r4.s64 = 5000;
	// li r3,3000
	ctx.r3.s64 = 3000;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// bl 0x825a49b0
	ctx.lr = 0x8250A788;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r4,8000
	ctx.r4.s64 = 8000;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// li r3,3000
	ctx.r3.s64 = 3000;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,124(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// bl 0x825a49b0
	ctx.lr = 0x8250A7B4;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r4,8
	ctx.r4.s64 = 8;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// li r3,4
	ctx.r3.s64 = 4;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,140(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 140, temp.u32);
	// bl 0x825a49b0
	ctx.lr = 0x8250A7E0;
	sub_825A49B0(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f13,-25252(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25252);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// beq cr6,0x8250a82c
	if (ctx.cr6.eq) goto loc_8250A82C;
	// stfs f0,40(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f13,44(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
loc_8250A82C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lfs f0,840(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 840);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8250A854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f1,-15608(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15608);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8250A870;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r30,152(r31)
	REX_STORE_U8(ctx.r31.u32 + 152, ctx.r30.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r10,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r10.u16);
	// beq cr6,0x8250a890
	if (ctx.cr6.eq) goto loc_8250A890;
	// sth r10,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r10.u16);
loc_8250A890:
	// addi r4,r31,108
	ctx.r4.s64 = ctx.r31.s64 + 108;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8231e0d8
	ctx.lr = 0x8250A89C;
	sub_8231E0D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,600
	ctx.r4.s64 = 600;
	// li r3,-600
	ctx.r3.s64 = -600;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bl 0x825a49b0
	ctx.lr = 0x8250A8C0;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r4,0
	ctx.r4.s64 = 0;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// li r3,-1700
	ctx.r3.s64 = -1700;
	// fmuls f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x825a49b0
	ctx.lr = 0x8250A8E8;
	sub_825A49B0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f30,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r7,24(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
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
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bctrl 
	ctx.lr = 0x8250A9F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lbz r11,98(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// lbz r9,97(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// lbz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// stb r9,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82520268) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lfs f0,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,292(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// lfs f0,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// lwz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,320(r3)
	REX_STORE_U32(ctx.r3.u32 + 320, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82521408) {
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
	// addi r10,r10,-3600
	ctx.r10.s64 = ctx.r10.s64 + -3600;
	// li r30,-1
	ctx.r30.s64 = -1;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8252144c
	if (ctx.cr6.eq) goto loc_8252144C;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82521448;
	sub_82222BB0(ctx, base);
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
loc_8252144C:
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82521468
	if (ctx.cr6.eq) goto loc_82521468;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82521464;
	sub_82222BB0(ctx, base);
	// stw r30,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r30.u32);
loc_82521468:
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82217698
	ctx.lr = 0x82521474;
	sub_82217698(ctx, base);
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82521484
	if (ctx.cr6.eq) goto loc_82521484;
	// bl 0x825e0378
	ctx.lr = 0x82521484;
	sub_825E0378(ctx, base);
loc_82521484:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,320
	ctx.r10.s64 = ctx.r31.s64 + 320;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lbz r9,348(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 348);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825214a8
	if (ctx.cr0.eq) goto loc_825214A8;
	// stb r11,28(r10)
	REX_STORE_U8(ctx.r10.u32 + 28, ctx.r11.u8);
loc_825214A8:
	// bl 0x825e04c0
	ctx.lr = 0x825214AC;
	sub_825E04C0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x825214C0;
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

DEFINE_REX_FUNC(sub_825278A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825278B0;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,292(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 292);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82527a3c
	if (ctx.cr6.lt) goto loc_82527A3C;
	// beq cr6,0x825278e8
	if (ctx.cr6.eq) goto loc_825278E8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82527ba0
	if (!ctx.cr6.lt) goto loc_82527BA0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x82527ba0
	goto loc_82527BA0;
loc_825278E8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r30,20(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r30,17
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 17, ctx.xer);
	// ble cr6,0x8252794c
	if (!ctx.cr6.gt) goto loc_8252794C;
	// lbz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 312);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8252793c
	if (!ctx.cr0.eq) goto loc_8252793C;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r3,112
	ctx.r3.s64 = 112;
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
	// bl 0x82240a58
	ctx.lr = 0x82527934;
	sub_82240A58(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,312(r31)
	REX_STORE_U8(ctx.r31.u32 + 312, ctx.r11.u8);
loc_8252793C:
	// cmplwi cr6,r30,27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 27, ctx.xer);
	// bgt cr6,0x82527954
	if (ctx.cr6.gt) goto loc_82527954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82527ef0
	ctx.lr = 0x8252794C;
	sub_82527EF0(ctx, base);
loc_8252794C:
	// cmplwi cr6,r30,27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 27, ctx.xer);
	// ble cr6,0x82527a24
	if (!ctx.cr6.gt) goto loc_82527A24;
loc_82527954:
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fadds f11,f31,f0
	ctx.f11.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f11,308(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r8,r10,8064
	ctx.r8.s64 = ctx.r10.s64 + 8064;
	// lfs f0,20068(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r29,0
	ctx.r29.s64 = 0;
	// lfs f12,8064(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8064);
	ctx.f12.f64 = double(temp.f32);
	// li r30,255
	ctx.r30.s64 = 255;
	// lfs f31,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lfs f13,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fsubs f0,f13,f11
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f30,f12,f11
	ctx.f30.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bgt cr6,0x825279b8
	if (ctx.cr6.gt) goto loc_825279B8;
	// stb r29,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r29.u8);
	// b 0x825279c8
	goto loc_825279C8;
loc_825279B8:
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r10,87(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
loc_825279C8:
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x825279DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bgt cr6,0x82527a00
	if (ctx.cr6.gt) goto loc_82527A00;
	// stb r29,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r29.u8);
	// b 0x82527a10
	goto loc_82527A10;
loc_82527A00:
	// fctidz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f30.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r10,87(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
loc_82527A10:
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82527A24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82527A24:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82527ba0
	if (!ctx.cr0.eq) goto loc_82527BA0;
	// b 0x82527b94
	goto loc_82527B94;
loc_82527A3C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r30,255
	ctx.r30.s64 = 255;
	// li r10,204
	ctx.r10.s64 = 204;
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82527A70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r10,136
	ctx.r10.s64 = 136;
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82527AA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f1,-12268(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12268);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82527AC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82527b14
	if (!ctx.cr6.eq) goto loc_82527B14;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r8,32544
	ctx.r8.s64 = ctx.r8.s64 + 32544;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r30,0
	ctx.r30.s64 = 0;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// b 0x82527b48
	goto loc_82527B48;
loc_82527B14:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,-31120
	ctx.r9.s64 = ctx.r9.s64 + -31120;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// li r30,2
	ctx.r30.s64 = 2;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_82527B48:
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82527B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82527B78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82527B94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82527B94:
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
loc_82527BA0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8253C7E0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1620
	ctx.r4.s64 = ctx.r11.s64 + 1620;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x8253C804;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8253c814
	if (!ctx.cr0.eq) goto loc_8253C814;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_8253C814:
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

DEFINE_REX_FUNC(sub_8253F7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8253F7B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r5.u64);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,9
	ctx.r7.s64 = 9;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8253F7E4;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// addi r9,r11,12472
	ctx.r9.s64 = ctx.r11.s64 + 12472;
	// stb r29,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r29.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r10,2120
	ctx.r11.s64 = ctx.r10.s64 + 2120;
	// stw r8,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r8.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lfs f0,-4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1904(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1904);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f13,320(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// bne cr6,0x8253f834
	if (!ctx.cr6.eq) goto loc_8253F834;
	// lfs f12,-236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8253f838
	goto loc_8253F838;
loc_8253F834:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_8253F838:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r5,100(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r8.u32);
	// lfs f0,196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r5,40
	ctx.r11.u64 = ctx.r5.u64 | 40;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f12,300(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// bl 0x82456128
	ctx.lr = 0x8253F8B4;
	sub_82456128(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8253f8c4
	if (ctx.cr0.eq) goto loc_8253F8C4;
	// lha r11,30(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 30));
	// b 0x8253f8c8
	goto loc_8253F8C8;
loc_8253F8C4:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8253F8C8:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lfs f0,2616(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2616);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stb r8,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r8.u8);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stb r10,276(r31)
	REX_STORE_U8(ctx.r31.u32 + 276, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82545958) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82545960;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,3520
	ctx.r11.s64 = ctx.r11.s64 + 3520;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r30,r3,316
	ctx.r30.s64 = ctx.r3.s64 + 316;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r29,2
	ctx.r29.s64 = 2;
loc_82545980:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x825459b8
	if (ctx.cr6.eq) goto loc_825459B8;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x82545998;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825459b0
	if (ctx.cr0.eq) goto loc_825459B0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x825459B0;
	sub_82222BB0(ctx, base);
loc_825459B0:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_825459B8:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82545980
	if (!ctx.cr0.eq) goto loc_82545980;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x825459CC;
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
	ctx.lr = 0x825459E0;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r28,31
	ctx.r11.u64 = ctx.r28.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825459f0
	if (ctx.cr0.eq) goto loc_825459F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825459F0;
	sub_825E0378(ctx, base);
loc_825459F0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254AD10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8254AD18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,4040
	ctx.r11.s64 = ctx.r11.s64 + 4040;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x8254AD34;
	sub_82469FB0(ctx, base);
	// lwz r3,332(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// addi r30,r31,328
	ctx.r30.s64 = ctx.r31.s64 + 328;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8254ad48
	if (ctx.cr6.eq) goto loc_8254AD48;
	// bl 0x825e0378
	ctx.lr = 0x8254AD48;
	sub_825E0378(ctx, base);
loc_8254AD48:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4968
	ctx.r10.s64 = ctx.r10.s64 + -4968;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82469ee8
	ctx.lr = 0x8254AD6C;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254ad7c
	if (ctx.cr0.eq) goto loc_8254AD7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8254AD7C;
	sub_825E0378(ctx, base);
loc_8254AD7C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254D6F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8254D6F8;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af08
	ctx.lr = 0x8254D700;
	__savefpr_20(ctx, base);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f20,f1
	ctx.fpscr.disableFlushMode();
	ctx.f20.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8254de84
	if (!ctx.cr0.eq) goto loc_8254DE84;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
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
	// bne cr6,0x8254d7fc
	if (!ctx.cr6.eq) goto loc_8254D7FC;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8254d7fc
	if (ctx.cr6.eq) goto loc_8254D7FC;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254d7fc
	if (ctx.cr0.eq) goto loc_8254D7FC;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// bl 0x82430a88
	ctx.lr = 0x8254D75C;
	sub_82430A88(ctx, base);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,308(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 308);
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
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f13,312(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r11,44(r30)
	REX_STORE_U64(ctx.r30.u32 + 44, ctx.r11.u64);
loc_8254D7FC:
	// lwz r11,332(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 332);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8254d908
	if (ctx.cr6.lt) goto loc_8254D908;
	// bne cr6,0x8254de70
	if (!ctx.cr6.eq) goto loc_8254DE70;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f12,292(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// addi r31,r11,12468
	ctx.r31.s64 = ctx.r11.s64 + 12468;
	// lfs f0,2408(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2408);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x8254d8c4
	if (!ctx.cr6.lt) goto loc_8254D8C4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-8956
	ctx.r11.s64 = ctx.r11.s64 + -8956;
	// lfs f13,10564(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10564);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f12,f13
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x8254d84c
	if (ctx.cr6.lt) goto loc_8254D84C;
	// lfs f0,-232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// ble cr6,0x8254d850
	if (!ctx.cr6.gt) goto loc_8254D850;
loc_8254D84C:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f0.f64;
loc_8254D850:
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8254de08
	if (ctx.cr6.eq) goto loc_8254DE08;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8254D868;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8254de00
	if (ctx.cr0.eq) goto loc_8254DE00;
	// lfs f0,-232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lfs f0,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// oris r11,r11,48059
	ctx.r11.u64 = ctx.r11.u64 | 3149594624;
	// ori r11,r11,65280
	ctx.r11.u64 = ctx.r11.u64 | 65280;
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// ld r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 44);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// b 0x8254ddec
	goto loc_8254DDEC;
loc_8254D8C4:
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8254d8fc
	if (ctx.cr6.eq) goto loc_8254D8FC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8254D8DC;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254d8f4
	if (ctx.cr0.eq) goto loc_8254D8F4;
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8254D8F4;
	sub_82222BB0(ctx, base);
loc_8254D8F4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,316(r30)
	REX_STORE_U32(ctx.r30.u32 + 316, ctx.r11.u32);
loc_8254D8FC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r30)
	REX_STORE_U8(ctx.r30.u32 + 23, ctx.r11.u8);
	// b 0x8254de70
	goto loc_8254DE70;
loc_8254D908:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,292(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// addi r18,r11,12468
	ctx.r18.s64 = ctx.r11.s64 + 12468;
	// lfs f0,2820(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 2820);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8254de18
	if (!ctx.cr6.lt) goto loc_8254DE18;
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8254d954
	if (!ctx.cr6.gt) goto loc_8254D954;
	// lwz r10,324(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8254d94c
	goto loc_8254D94C;
loc_8254D938:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f20
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f20.f64));
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,324(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
loc_8254D94C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8254d938
	if (!ctx.cr6.eq) goto loc_8254D938;
loc_8254D954:
	// lfs f0,300(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lis r28,-32227
	ctx.r28.s64 = -2112028672;
	// fadds f0,f0,f20
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f20.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f0,300(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 300, temp.u32);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r26,r11,-4080
	ctx.r26.s64 = ctx.r11.s64 + -4080;
	// lfs f13,20196(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20196);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8254dd80
	if (!ctx.cr6.gt) goto loc_8254DD80;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f24,0(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lis r7,-32228
	ctx.r7.s64 = -2112094208;
	// lfs f23,2568(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 2568);
	ctx.f23.f64 = double(temp.f32);
	// addi r23,r11,-24456
	ctx.r23.s64 = ctx.r11.s64 + -24456;
	// lfs f25,236(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 236);
	ctx.f25.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f22,224(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 224);
	ctx.f22.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lfs f26,-8956(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -8956);
	ctx.f26.f64 = double(temp.f32);
	// lfs f0,-6196(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -6196);
	ctx.f0.f64 = double(temp.f32);
	// addi r14,r30,320
	ctx.r14.s64 = ctx.r30.s64 + 320;
	// lfs f21,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f21.f64 = double(temp.f32);
	// li r22,0
	ctx.r22.s64 = 0;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r17,-32111
	ctx.r17.s64 = -2104426496;
	// lis r20,-32114
	ctx.r20.s64 = -2104623104;
	// lis r19,-32114
	ctx.r19.s64 = -2104623104;
	// addi r24,r11,-9856
	ctx.r24.s64 = ctx.r11.s64 + -9856;
	// addi r16,r10,112
	ctx.r16.s64 = ctx.r10.s64 + 112;
	// addi r15,r9,712
	ctx.r15.s64 = ctx.r9.s64 + 712;
	// addi r25,r8,22072
	ctx.r25.s64 = ctx.r8.s64 + 22072;
	// b 0x8254d9e4
	goto loc_8254D9E4;
loc_8254D9E0:
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8254D9E4:
	// lfs f0,300(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// li r21,4
	ctx.r21.s64 = 4;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,300(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 300, temp.u32);
	// b 0x8254d9fc
	goto loc_8254D9FC;
loc_8254D9F8:
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8254D9FC:
	// lfs f2,4176(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 4176);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// bl 0x825a4a40
	ctx.lr = 0x8254DA0C;
	sub_825A4A40(ctx, base);
	// lwz r11,304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 304);
	// lfs f0,4180(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 4180);
	ctx.f0.f64 = double(temp.f32);
	// fabs f12,f1
	ctx.f12.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lfs f13,2408(r18)
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 2408);
	ctx.f13.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// std r10,320(r1)
	REX_STORE_U64(ctx.r1.u32 + 320, ctx.r10.u64);
	// lfd f11,320(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 320);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// stw r11,304(r30)
	REX_STORE_U32(ctx.r30.u32 + 304, ctx.r11.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f30,f12,f13,f0
	ctx.f30.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// blt cr6,0x8254da4c
	if (ctx.cr6.lt) goto loc_8254DA4C;
	// stw r22,304(r30)
	REX_STORE_U32(ctx.r30.u32 + 304, ctx.r22.u32);
loc_8254DA4C:
	// ld r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 44);
	// lfs f2,-29068(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -29068);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x825a4a40
	ctx.lr = 0x8254DA64;
	sub_825A4A40(ctx, base);
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// fadds f1,f30,f25
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f25.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8254DA70;
	sub_822EA1A8(ctx, base);
	// fmuls f31,f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f27.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x8254DA7C;
	sub_822EA1A8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 48);
	// li r4,184
	ctx.r4.s64 = 184;
	// fmuls f30,f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64 * ctx.f27.f64));
	// bl 0x825e02a0
	ctx.lr = 0x8254DA90;
	sub_825E02A0(ctx, base);
	// lfs f29,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f28.f64 = double(temp.f32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8254db78
	if (ctx.cr0.eq) goto loc_8254DB78;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f30,216(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f30,212(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// stfs f30,208(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f30,220(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f28,268(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// stfs f28,264(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// stfs f31,300(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// stfs f28,260(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// stfs f28,256(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f31,296(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f31,292(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f31,288(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,180(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f28,176(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// ld r5,176(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// stfs f29,228(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f29,232(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f29,224(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f29,236(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lfd f0,128(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// frsp f13,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,1212(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 1212);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,-7636(r17)
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + -7636);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f12,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lwz r6,148(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x823501f8
	ctx.lr = 0x8254DB70;
	sub_823501F8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8254db7c
	goto loc_8254DB7C;
loc_8254DB78:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_8254DB7C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8254dc24
	if (ctx.cr6.eq) goto loc_8254DC24;
	// li r29,1
	ctx.r29.s64 = 1;
	// lfs f0,-6196(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -6196);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r29,144(r31)
	REX_STORE_U8(ctx.r31.u32 + 144, ctx.r29.u8);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254DBAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f23.f64;
	// bl 0x8234bbe8
	ctx.lr = 0x8254DBB8;
	sub_8234BBE8(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lfs f0,20196(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20196);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f27,f22
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f22.f64));
	// fmuls f12,f27,f21
	ctx.f12.f64 = double(float(ctx.f27.f64 * ctx.f21.f64));
	// stfs f24,116(r31)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// stfs f0,140(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 140, temp.u32);
	// stb r29,136(r31)
	REX_STORE_U8(ctx.r31.u32 + 136, ctx.r29.u8);
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// stb r22,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r22.u8);
	// stfs f12,124(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// stb r22,165(r31)
	REX_STORE_U8(ctx.r31.u32 + 165, ctx.r22.u8);
	// stb r29,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r29.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254dbf4
	if (ctx.cr6.eq) goto loc_8254DBF4;
	// stb r29,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r29.u8);
loc_8254DBF4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82222ad8
	ctx.lr = 0x8254DC00;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8254dc24
	if (!ctx.cr6.eq) goto loc_8254DC24;
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
	ctx.lr = 0x8254DC24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8254DC24:
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// stfs f29,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// stfs f29,240(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f30,276(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stfs f30,272(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f29,248(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r7,r1,336
	ctx.r7.s64 = ctx.r1.s64 + 336;
	// stfs f30,284(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// stfs f28,312(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// lwz r29,4(r14)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r14.u32 + 4);
	// stfs f28,308(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f28,304(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// li r4,20
	ctx.r4.s64 = 20;
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r3,44(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 44);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f29,244(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lwz r27,4(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stfs f30,280(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f28,316(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x8254DCC4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8254dcd0
	if (ctx.cr0.eq) goto loc_8254DCD0;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8254DCD0:
	// addic. r28,r31,4
	ctx.xer.ca = ctx.r31.u32 > 4294967291;
	ctx.r28.s64 = ctx.r31.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8254dcdc
	if (ctx.cr0.eq) goto loc_8254DCDC;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
loc_8254DCDC:
	// addic. r11,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r11.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254dcfc
	if (ctx.cr0.eq) goto loc_8254DCFC;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
loc_8254DCFC:
	// lis r11,5461
	ctx.r11.s64 = 357892096;
	// lwz r10,8(r14)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r14.u32 + 8);
	// ori r11,r11,21845
	ctx.r11.u64 = ctx.r11.u64 | 21845;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8254dd4c
	if (!ctx.cr6.lt) goto loc_8254DD4C;
	// mr r4,r15
	ctx.r4.u64 = ctx.r15.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x822167f8
	ctx.lr = 0x8254DD20;
	sub_822167F8(ctx, base);
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82216678
	ctx.lr = 0x8254DD2C;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8254DD30;
	sub_82216E60(ctx, base);
	// stw r16,432(r1)
	REX_STORE_U32(ctx.r1.u32 + 432, ctx.r16.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82216d98
	ctx.lr = 0x8254DD3C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x8235ec48
	ctx.lr = 0x8254DD4C;
	sub_8235EC48(ctx, base);
loc_8254DD4C:
	// lwz r11,8(r14)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r14.u32 + 8);
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r14)
	REX_STORE_U32(ctx.r14.u32 + 8, ctx.r11.u32);
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// bne 0x8254d9f8
	if (!ctx.cr0.eq) goto loc_8254D9F8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f0,300(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20196(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20196);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8254d9e0
	if (ctx.cr6.gt) goto loc_8254D9E0;
loc_8254DD80:
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// lfs f13,292(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1416(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 1416);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8254de08
	if (ctx.cr6.eq) goto loc_8254DE08;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8254DDA4;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8254de00
	if (ctx.cr0.eq) goto loc_8254DE00;
	// lfs f0,2292(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 2292);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,184
	ctx.r4.s64 = ctx.r1.s64 + 184;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// oris r11,r11,48059
	ctx.r11.u64 = ctx.r11.u64 | 3149594624;
	// ori r11,r11,65280
	ctx.r11.u64 = ctx.r11.u64 | 65280;
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// ld r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 44);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f0,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
loc_8254DDEC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254DDFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8254de08
	goto loc_8254DE08;
loc_8254DE00:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,316(r30)
	REX_STORE_U32(ctx.r30.u32 + 316, ctx.r11.u32);
loc_8254DE08:
	// lfs f0,292(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f20
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f20.f64));
	// stfs f0,292(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 292, temp.u32);
	// b 0x8254de70
	goto loc_8254DE70;
loc_8254DE18:
	// li r22,0
	ctx.r22.s64 = 0;
	// lfs f0,0(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,292(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 292, temp.u32);
	// stb r22,116(r30)
	REX_STORE_U8(ctx.r30.u32 + 116, ctx.r22.u8);
	// addi r31,r30,320
	ctx.r31.s64 = ctx.r30.s64 + 320;
	// stw r11,332(r30)
	REX_STORE_U32(ctx.r30.u32 + 332, ctx.r11.u32);
	// lwz r11,324(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,324(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,324(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 324);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r22,328(r30)
	REX_STORE_U32(ctx.r30.u32 + 328, ctx.r22.u32);
	// beq cr6,0x8254de70
	if (ctx.cr6.eq) goto loc_8254DE70;
loc_8254DE58:
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x8254DE60;
	sub_825E0378(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254de58
	if (!ctx.cr6.eq) goto loc_8254DE58;
loc_8254DE70:
	// lbz r11,289(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8254de84
	if (ctx.cr0.eq) goto loc_8254DE84;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r30)
	REX_STORE_U8(ctx.r30.u32 + 23, ctx.r11.u8);
loc_8254DE84:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af54
	ctx.lr = 0x8254DE90;
	__restfpr_20(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82586620) {
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
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r31,7608(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 7608);
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x82586648
	if (!ctx.cr6.eq) goto loc_82586648;
loc_82586640:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82586680
	goto loc_82586680;
loc_82586648:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8258aa88
	ctx.lr = 0x82586654;
	sub_8258AA88(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82586640
	if (ctx.cr0.eq) goto loc_82586640;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8258ab70
	ctx.lr = 0x82586668;
	sub_8258AB70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82586640
	if (ctx.cr0.eq) goto loc_82586640;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_82586680:
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

DEFINE_REX_FUNC(sub_82589B20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82589B28;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af10
	ctx.lr = 0x82589B30;
	__savefpr_22(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,10(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lhz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// fmr f28,f2
	ctx.f28.f64 = ctx.f2.f64;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f30,232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f5,f30
	ctx.cr6.compare(ctx.f5.f64, ctx.f30.f64);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// bge cr6,0x82589b88
	if (!ctx.cr6.lt) goto loc_82589B88;
	// fmr f5,f0
	ctx.f5.f64 = ctx.f0.f64;
loc_82589B88:
	// fcmpu cr6,f6,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f6.f64, ctx.f30.f64);
	// bge cr6,0x82589b94
	if (!ctx.cr6.lt) goto loc_82589B94;
	// fmr f6,f13
	ctx.f6.f64 = ctx.f13.f64;
loc_82589B94:
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// fadds f12,f3,f5
	ctx.f12.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// fdivs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fdivs f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 / ctx.f13.f64));
	// li r9,1
	ctx.r9.s64 = 1;
	// fadds f11,f4,f6
	ctx.f11.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// addi r8,r11,-10736
	ctx.r8.s64 = ctx.r11.s64 + -10736;
	// li r6,7
	ctx.r6.s64 = 7;
	// fadds f27,f29,f5
	ctx.f27.f64 = double(float(ctx.f29.f64 + ctx.f5.f64));
	// li r4,4
	ctx.r4.s64 = 4;
	// fadds f26,f28,f6
	ctx.f26.f64 = double(float(ctx.f28.f64 + ctx.f6.f64));
	// li r3,5
	ctx.r3.s64 = 5;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// fmuls f25,f0,f3
	ctx.f25.f64 = double(float(ctx.f0.f64 * ctx.f3.f64));
	// fmuls f24,f13,f4
	ctx.f24.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fmuls f23,f12,f0
	ctx.f23.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f22,f11,f13
	ctx.f22.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// bl 0x8222c8c0
	ctx.lr = 0x82589BE0;
	sub_8222C8C0(ctx, base);
	// stfs f28,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f29,112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f27,128(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f27,144(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f29,160(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r6,r3,40
	ctx.r6.s64 = ctx.r3.s64 + 40;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f28,132(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f26,148(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f26,164(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f25,80(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f24,84(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f23,88(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f24,92(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f25,96(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,12(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r23,0(r10)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r31,4(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r30,8(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f22,116(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r29,0(r8)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r28,4(r8)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r27,8(r8)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r26,0(r7)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r25,4(r7)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r24,8(r7)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,12(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// stw r23,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r23.u32);
	// stw r4,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r4.u32);
	// stw r31,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r31.u32);
	// stw r30,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stw r29,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r29.u32);
	// stw r28,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r28.u32);
	// stw r27,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r27.u32);
	// stw r26,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r26.u32);
	// stw r8,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r8.u32);
	// stw r25,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r25.u32);
	// stw r24,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r24.u32);
	// stw r7,132(r3)
	REX_STORE_U32(ctx.r3.u32 + 132, ctx.r7.u32);
	// stfs f23,112(r1)
	temp.f32 = float(ctx.f23.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r11,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,108(r3)
	REX_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stfs f22,100(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// ld r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r10.u64);
	// std r9,72(r3)
	REX_STORE_U64(ctx.r3.u32 + 72, ctx.r9.u64);
	// std r8,152(r3)
	REX_STORE_U64(ctx.r3.u32 + 152, ctx.r8.u64);
	// std r11,112(r3)
	REX_STORE_U64(ctx.r3.u32 + 112, ctx.r11.u64);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af5c
	ctx.lr = 0x82589D14;
	__restfpr_22(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82598010) {
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
	// lwz r3,44(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,48(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8259803C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82598060;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8259A2C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8259A2C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// addi r25,r3,4
	ctx.r25.s64 = ctx.r3.s64 + 4;
	// blt cr6,0x8259a2f4
	if (ctx.cr6.lt) goto loc_8259A2F4;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x8259a2f8
	goto loc_8259A2F8;
loc_8259A2F4:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A2F8:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r24,r10,31016
	ctx.r24.s64 = ctx.r10.s64 + 31016;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8259a330
	if (ctx.cr6.lt) goto loc_8259A330;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a318
	if (ctx.cr6.lt) goto loc_8259A318;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a31c
	goto loc_8259A31C;
loc_8259A318:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A31C:
	// lwz r10,20(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bgt cr6,0x8259a334
	if (ctx.cr6.gt) goto loc_8259A334;
loc_8259A330:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8259A334:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259a370
	if (ctx.cr0.eq) goto loc_8259A370;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a34c
	if (ctx.cr6.lt) goto loc_8259A34C;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a350
	goto loc_8259A350;
loc_8259A34C:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A350:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// subf r7,r11,r24
	ctx.r7.u64 = ctx.r24.u64 - ctx.r11.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8259af98
	ctx.lr = 0x8259A36C;
	sub_8259AF98(ctx, base);
	// b 0x8259a4e0
	goto loc_8259A4E0;
loc_8259A370:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x8259a380
	if (!ctx.cr6.lt) goto loc_8259A380;
	// bl 0x82738500
	ctx.lr = 0x8259A380;
	sub_82738500(ctx, base);
loc_8259A380:
	// lwz r10,20(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// subf r11,r31,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r31.u64;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8259a394
	if (!ctx.cr6.lt) goto loc_8259A394;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8259A394:
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// subfic r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 <= 4294967295;
	ctx.r10.u64 = static_cast<uint64_t>(-1) - ctx.r29.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8259a3a8
	if (ctx.cr6.gt) goto loc_8259A3A8;
	// bl 0x82738480
	ctx.lr = 0x8259A3A8;
	sub_82738480(ctx, base);
loc_8259A3A8:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// subf r27,r30,r11
	ctx.r27.u64 = ctx.r11.u64 - ctx.r30.u64;
	// bge cr6,0x8259a408
	if (!ctx.cr6.lt) goto loc_8259A408;
	// lwz r9,24(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a3d0
	if (ctx.cr6.lt) goto loc_8259A3D0;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a3d4
	goto loc_8259A3D4;
loc_8259A3D0:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_8259A3D4:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a3e4
	if (ctx.cr6.lt) goto loc_8259A3E4;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a3e8
	goto loc_8259A3E8;
loc_8259A3E4:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A3E8:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r9,r31,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r4,r29,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r29.u64;
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x827388e8
	ctx.lr = 0x8259A408;
	sub_827388E8(ctx, base);
loc_8259A408:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8259a418
	if (!ctx.cr6.eq) goto loc_8259A418;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8259a4dc
	if (ctx.cr6.eq) goto loc_8259A4DC;
loc_8259A418:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// add r26,r11,r29
	ctx.r26.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x8235f1d8
	ctx.lr = 0x8259A430;
	sub_8235F1D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259a4dc
	if (ctx.cr0.eq) goto loc_8259A4DC;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x8259a48c
	if (!ctx.cr6.lt) goto loc_8259A48C;
	// lwz r9,24(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a454
	if (ctx.cr6.lt) goto loc_8259A454;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a458
	goto loc_8259A458;
loc_8259A454:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_8259A458:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8259a468
	if (ctx.cr6.lt) goto loc_8259A468;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a46c
	goto loc_8259A46C;
loc_8259A468:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A46C:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r9,r31,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r4,r29,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r29.u64;
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x827388e8
	ctx.lr = 0x8259A48C;
	sub_827388E8(ctx, base);
loc_8259A48C:
	// lwz r10,24(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8259a4a0
	if (ctx.cr6.lt) goto loc_8259A4A0;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a4a4
	goto loc_8259A4A4;
loc_8259A4A0:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A4A4:
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// subf r4,r31,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r31.u64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82738810
	ctx.lr = 0x8259A4B8;
	sub_82738810(ctx, base);
	// lwz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// stw r26,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r26.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8259a4d0
	if (ctx.cr6.lt) goto loc_8259A4D0;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// b 0x8259a4d4
	goto loc_8259A4D4;
loc_8259A4D0:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8259A4D4:
	// li r10,0
	ctx.r10.s64 = 0;
	// stbx r10,r11,r26
	REX_STORE_U8(ctx.r11.u32 + ctx.r26.u32, ctx.r10.u8);
loc_8259A4DC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8259A4E0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A7F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// lwz r11,-12768(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12768);
	// bne cr6,0x825a7f90
	if (!ctx.cr6.eq) goto loc_825A7F90;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r10,r11,736
	ctx.r10.s64 = ctx.r11.s64 + 736;
loc_825A7F48:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r9,r8,45
	ctx.r9.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(45));
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mulli r8,r8,144
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(144));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,760(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 760);
	// lwzx r9,r9,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// and. r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x825a7f88
	if (!ctx.cr0.eq) goto loc_825A7F88;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// blt cr6,0x825a7f48
	if (ctx.cr6.lt) goto loc_825A7F48;
	// blr 
	return;
loc_825A7F88:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_825A7F90:
	// addi r10,r4,184
	ctx.r10.s64 = ctx.r4.s64 + 184;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mulli r10,r8,45
	ctx.r10.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(45));
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mulli r10,r8,144
	ctx.r10.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(144));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,760(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 760);
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
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

DEFINE_REX_FUNC(sub_825AD508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825AD510;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825ad5d4
	if (!ctx.cr6.eq) goto loc_825AD5D4;
	// lwz r31,12(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x825ad5d4
	if (!ctx.cr6.gt) goto loc_825AD5D4;
	// cmpwi r31,0
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt 0x825ad544
	if (ctx.cr0.gt) goto loc_825AD544;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x825ad580
	goto loc_825AD580;
loc_825AD544:
	// li r11,-1
	ctx.r11.s64 = -1;
	// twllei r31,0
	if (ctx.r31.s32 == 0 || ctx.r31.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r11,r31
	ctx.r11.u64 = uint32_t(ctx.r31.u32 ? ctx.r11.u32 / ctx.r31.u32 : 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x825ad580
	if (!ctx.cr6.lt) goto loc_825AD580;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 + 88;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82216e60
	ctx.lr = 0x825AD574;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_825AD580:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x825ad5b4
	if (!ctx.cr6.gt) goto loc_825AD5B4;
	// lis r30,-32115
	ctx.r30.s64 = -2104688640;
loc_825AD590:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,22072(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 22072);
	// rlwinm r4,r31,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x825e02a0
	ctx.lr = 0x825AD5A0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x825ad5b4
	if (!ctx.cr0.eq) goto loc_825AD5B4;
	// srawi r11,r31,1
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 1;
	// addze. r31,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r31.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt 0x825ad590
	if (ctx.cr0.gt) goto loc_825AD590;
loc_825AD5B4:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// stw r31,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
loc_825AD5D4:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B33D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825B33E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r11,17976
	ctx.r6.s64 = ctx.r11.s64 + 17976;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r4,r10,18000
	ctx.r4.s64 = ctx.r10.s64 + 18000;
	// addi r3,r9,18092
	ctx.r3.s64 = ctx.r9.s64 + 18092;
	// addi r11,r8,18120
	ctx.r11.s64 = ctx.r8.s64 + 18120;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// addi r29,r7,17996
	ctx.r29.s64 = ctx.r7.s64 + 17996;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// addi r10,r31,8
	ctx.r10.s64 = ctx.r31.s64 + 8;
	// stw r29,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// bl 0x82855c54
	ctx.lr = 0x825B3448;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r30,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r5,r10,18140
	ctx.r5.s64 = ctx.r10.s64 + 18140;
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// addi r10,r31,104
	ctx.r10.s64 = ctx.r31.s64 + 104;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r11,r31,116
	ctx.r11.s64 = ctx.r31.s64 + 116;
	// stw r5,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// addi r9,r31,136
	ctx.r9.s64 = ctx.r31.s64 + 136;
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// addi r8,r31,160
	ctx.r8.s64 = ctx.r31.s64 + 160;
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// addi r7,r31,172
	ctx.r7.s64 = ctx.r31.s64 + 172;
	// stw r10,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// addi r10,r31,148
	ctx.r10.s64 = ctx.r31.s64 + 148;
	// stw r5,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r5.u32);
	// addi r6,r31,200
	ctx.r6.s64 = ctx.r31.s64 + 200;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// addi r11,r31,188
	ctx.r11.s64 = ctx.r31.s64 + 188;
	// stw r5,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r5.u32);
	// addi r3,r6,4
	ctx.r3.s64 = ctx.r6.s64 + 4;
	// stw r30,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// stw r30,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r9,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// stw r5,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r5.u32);
	// stw r9,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r9.u32);
	// stw r10,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r10.u32);
	// stw r5,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r5.u32);
	// stw r10,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// stw r5,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r5.u32);
	// stw r8,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r8.u32);
	// stw r8,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r8.u32);
	// stw r5,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r5.u32);
	// stw r7,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r7.u32);
	// stw r7,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r7.u32);
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// stw r5,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r5.u32);
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// stw r29,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r29.u32);
	// bl 0x82855c54
	ctx.lr = 0x825B3500;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r3,-32156
	ctx.r3.s64 = -2107375616;
	// li r10,42
	ctx.r10.s64 = 42;
	// ori r9,r4,65535
	ctx.r9.u64 = ctx.r4.u64 | 65535;
	// lis r8,-32156
	ctx.r8.s64 = -2107375616;
	// stw r10,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r10.u32);
	// addi r29,r11,-12696
	ctx.r29.s64 = ctx.r11.s64 + -12696;
	// stw r9,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r9.u32);
	// addi r7,r3,-21328
	ctx.r7.s64 = ctx.r3.s64 + -21328;
	// addi r6,r8,-20944
	ctx.r6.s64 = ctx.r8.s64 + -20944;
	// stw r30,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r30.u32);
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
	// stw r7,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r7.u32);
	// stw r6,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r6.u32);
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r30,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// ld r11,-12696(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + -12696);
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bne cr6,0x825b3588
	if (!ctx.cr6.eq) goto loc_825B3588;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827484f0
	ctx.lr = 0x825B3558;
	sub_827484F0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r3,20344(r11)
	REX_STORE_U32(ctx.r11.u32 + 20344, ctx.r3.u32);
	// beq cr6,0x825b3588
	if (ctx.cr6.eq) goto loc_825B3588;
	// lfd f0,0(r29)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-4080
	ctx.r9.s64 = ctx.r11.s64 + -4080;
	// lfd f0,696(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 696);
	// fdiv f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 / ctx.f13.f64;
	// stfd f0,-12688(r10)
	REX_STORE_U64(ctx.r10.u32 + -12688, ctx.f0.u64);
loc_825B3588:
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// bl 0x825b8a68
	ctx.lr = 0x825B35AC;
	sub_825B8A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b35bc
	if (ctx.cr6.lt) goto loc_825B35BC;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_825B35BC:
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bge cr6,0x825b35d0
	if (!ctx.cr6.lt) goto loc_825B35D0;
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
loc_825B35D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BE978) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825be7f0
	sub_825BE7F0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BEAC8) {
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
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BEAE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,14(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 14);
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825beb08
	if (!ctx.cr6.eq) goto loc_825BEB08;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825beb0c
	if (!ctx.cr6.eq) goto loc_825BEB0C;
loc_825BEB08:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825BEB0C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C1740) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825C1748;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825C1784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r30,16
	ctx.r8.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplw cr6,r8,r3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x825c17a0
	if (ctx.cr6.lt) goto loc_825C17A0;
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_825C17A0:
	// lwz r4,276(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// stw r4,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825c1820
	ctx.lr = 0x825C17E0;
	sub_825C1820(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c1810
	if (ctx.cr6.lt) goto loc_825C1810;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C1808;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,292(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// stw r29,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
loc_825C1810:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C6F40) {
	REX_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// addi r3,r11,10
	ctx.r3.s64 = ctx.r11.s64 + 10;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C73D8) {
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
	// bl 0x825c7430
	ctx.lr = 0x825C73F8;
	sub_825C7430(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c7418
	if (ctx.cr6.eq) goto loc_825C7418;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32776
	ctx.r4.u64 = ctx.r4.u64 | 32776;
	// bl 0x8263b710
	ctx.lr = 0x825C7414;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825C7418:
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

DEFINE_REX_FUNC(sub_825C9BD8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,424(r3)
	REX_STORE_U32(ctx.r3.u32 + 424, ctx.r11.u32);
	// bl 0x825c8eb8
	ctx.lr = 0x825C9BF8;
	sub_825C8EB8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// stw r10,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_825CC3D0) {
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
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cc408
	if (ctx.cr6.eq) goto loc_825CC408;
	// bl 0x825cb258
	ctx.lr = 0x825CC3FC;
	sub_825CB258(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cc408
	if (ctx.cr6.eq) goto loc_825CC408;
	// li r30,1
	ctx.r30.s64 = 1;
loc_825CC408:
	// lwz r3,112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cc424
	if (ctx.cr6.eq) goto loc_825CC424;
	// bl 0x825cb258
	ctx.lr = 0x825CC418;
	sub_825CB258(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cc424
	if (ctx.cr6.eq) goto loc_825CC424;
	// li r30,1
	ctx.r30.s64 = 1;
loc_825CC424:
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cc450
	if (ctx.cr6.eq) goto loc_825CC450;
	// lbz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// beq cr6,0x825cc450
	if (ctx.cr6.eq) goto loc_825CC450;
	// bl 0x825cb258
	ctx.lr = 0x825CC444;
	sub_825CB258(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x825cc454
	if (!ctx.cr6.eq) goto loc_825CC454;
loc_825CC450:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_825CC454:
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

DEFINE_REX_FUNC(sub_825D0A48) {
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
	// bl 0x825b32d0
	ctx.lr = 0x825D0A64;
	sub_825B32D0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// subf r30,r10,r3
	ctx.r30.u64 = ctx.r3.u64 - ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,64(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825D0A80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,32(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825D0A94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// subf r3,r30,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r30.u64;
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

DEFINE_REX_FUNC(sub_825D4E40) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4efc
	if (ctx.cr6.eq) goto loc_825D4EFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r3,64
	ctx.r8.s64 = ctx.r3.s64 + 64;
loc_825D4E64:
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
	// bne 0x825d4e64
	if (!ctx.cr0.eq) goto loc_825D4E64;
	// lis r7,19558
	ctx.r7.s64 = 1281753088;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// ori r6,r7,20853
	ctx.r6.u64 = ctx.r7.u64 | 20853;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// bne cr6,0x825d4efc
	if (!ctx.cr6.eq) goto loc_825D4EFC;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4ea0
	if (ctx.cr6.eq) goto loc_825D4EA0;
	// bl 0x8263a978
	ctx.lr = 0x825D4EA0;
	sub_8263A978(ctx, base);
loc_825D4EA0:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d4eb0
	if (ctx.cr6.eq) goto loc_825D4EB0;
	// bl 0x8263a978
	ctx.lr = 0x825D4EB0;
	sub_8263A978(ctx, base);
loc_825D4EB0:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,40
	ctx.r4.s64 = ctx.r31.s64 + 40;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825d4350
	ctx.lr = 0x825D4EC8;
	sub_825D4350(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d4ef0
	if (ctx.cr6.eq) goto loc_825D4EF0;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825D4EEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825d4ef8
	goto loc_825D4EF8;
loc_825D4EF0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x825d4138
	ctx.lr = 0x825D4EF8;
	sub_825D4138(ctx, base);
loc_825D4EF8:
	// lwsync 
loc_825D4EFC:
	// li r3,1
	ctx.r3.s64 = 1;
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

DEFINE_REX_FUNC(sub_825E1700) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// addi r11,r11,3072
	ctx.r11.s64 = ctx.r11.s64 + 3072;
	// vor v11,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// vor128 v63,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// li r9,432
	ctx.r9.s64 = 432;
	// vslw128 v60,v61,v61
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// vslw128 v58,v61,v61
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v5,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v59,v61,v61
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vmsum4fp128 v0,v5,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v1.f32), 0xFF));
	// addi r11,r8,32256
	ctx.r11.s64 = ctx.r8.s64 + 32256;
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// vxor128 v10,v1,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r9,-31360
	ctx.r9.s64 = ctx.r9.s64 + -31360;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lvx128 v4,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r7,r7,-31552
	ctx.r7.s64 = ctx.r7.s64 + -31552;
	// addi r10,r10,-31568
	ctx.r10.s64 = ctx.r10.s64 + -31568;
	// addi r8,r8,-31520
	ctx.r8.s64 = ctx.r8.s64 + -31520;
	// addi r6,r6,-31536
	ctx.r6.s64 = ctx.r6.s64 + -31536;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lvx128 v28,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// lvx128 v27,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-31584
	ctx.r11.s64 = ctx.r11.s64 + -31584;
	// lvx128 v1,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lvx128 v31,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// addi r7,r4,-31600
	ctx.r7.s64 = ctx.r4.s64 + -31600;
	// vcmpgtfp128 v9,v62,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vxor128 v12,v0,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lvx128 v30,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r5,-31616
	ctx.r10.s64 = ctx.r5.s64 + -31616;
	// addi r5,r3,-31936
	ctx.r5.s64 = ctx.r3.s64 + -31936;
	// addi r11,r9,-31632
	ctx.r11.s64 = ctx.r9.s64 + -31632;
	// lvx128 v26,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v8,v0,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v25,v11,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vor128 v58,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vxor128 v59,v58,v59
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vcmpgtfp128 v3,v60,v58
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmaxfp128 v0,v58,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vsubfp128 v60,v13,v0
	simde_mm_store_ps(ctx.v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v0,v0
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vrsqrtefp128 v12,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v60.f32))));
	// vor128 v6,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// vmulfp128 v11,v60,v4
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vcmpeqfp128 v9,v60,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v7,v60,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v10,v12,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vor v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v2,v12,v62
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v4,v11,v10,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v4.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v10,v9,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8))));
	// vmaddfp v9,v31,v0,v1
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v12,v12,v4,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v9,v0,v30
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vsel v11,v12,v8,v10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vcmpeqfp128 v12,v11,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v11,v60,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vsel v10,v7,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v12,v11,v6,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v11,v27,v0,v28
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// lvx128 v10,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v27,v59,v59
	simde_mm_store_ps(ctx.v27.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lvx128 v6,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vmaddfp v28,v11,v0,v26
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v26.f32)));
	// vor v8,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vmaddfp v10,v28,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v9,v0,v29
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vspltisw128 v59,-5
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0xFFFFFFFB)));
	// vsubfp128 v57,v13,v63
	simde_mm_store_ps(ctx.v57.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmrghw128 v56,v13,v63
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// vspltisw128 v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_set1_epi32(int(0x1)));
	// vsrw128 v59,v61,v59
	ctx.v59.u32[0] = ctx.v61.u32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v59.u32[1] = ctx.v61.u32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v59.u32[2] = ctx.v61.u32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v59.u32[3] = ctx.v61.u32[3] >> (ctx.v59.u8[12] & 0x1F);
	// addi r11,r11,-31920
	ctx.r11.s64 = ctx.r11.s64 + -31920;
	// addi r10,r10,-31952
	ctx.r10.s64 = ctx.r10.s64 + -31952;
	// vspltisw128 v54,2
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_set1_epi32(int(0x2)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// vslw128 v61,v61,v61
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// vsraw128 v24,v58,v59
	ctx.v24.s32[0] = ctx.v58.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v24.s32[1] = ctx.v58.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v24.s32[2] = ctx.v58.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v24.s32[3] = ctx.v58.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lvx128 v7,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r9,-32016
	ctx.r10.s64 = ctx.r9.s64 + -32016;
	// addi r9,r8,-31984
	ctx.r9.s64 = ctx.r8.s64 + -31984;
	// vmaddfp v0,v0,v27,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v27.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// addi r8,r7,-31968
	ctx.r8.s64 = ctx.r7.s64 + -31968;
	// vmrghw128 v59,v56,v57
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// addi r11,r11,-32000
	ctx.r11.s64 = ctx.r11.s64 + -32000;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lvx128 v31,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r7,-32048
	ctx.r9.s64 = ctx.r7.s64 + -32048;
	// lvx128 v4,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-32032
	ctx.r10.s64 = ctx.r10.s64 + -32032;
	// lvx128 v2,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v58,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vnmsubfp v10,v12,v0,v6
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v9,v60,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vsel v0,v9,v10,v24
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmulfp128 v12,v59,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v12,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vrfin128 v10,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v63.f32), SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_NO_EXC));
	// vnmsubfp v12,v10,v8,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcfpsxws128 v63,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vnmsubfp v12,v10,v7,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vand128 v60,v63,v55
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// vand128 v63,v63,v54
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8)));
	// vcmpequw128 v9,v60,v62
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vmulfp128 v0,v12,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v8,v31,v0,v1
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v7,v2,v0,v4
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v10,v0,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v6,v8,v0,v29
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v8,v7,v0,v30
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v12,v6,v10,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v0,v8,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v10,v0,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vcmpequw128 v9,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vor128 v12,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// vor v0,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vxor128 v10,v10,v61
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vsel v9,v10,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vor128 v63,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vrefp128 v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v61.f32)));
	// vor128 v6,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vor128 v9,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vcmpeqfp128 v8,v61,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v4,v6,v0,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp128 v10,v0,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmaddfp v7,v0,v4,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v6,v8,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vnmsubfp v13,v9,v7,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v13,v7,v13,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vsel v10,v13,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v63,v10
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v13,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v0,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vsel v10,v11,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v13,v12,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v0,v25,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v25.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v1,v5,v13,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8260C7C0) {
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
	// lwz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8260c80c
	goto loc_8260C80C;
loc_8260C7DC:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,12(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8260c808
	if (ctx.cr6.eq) goto loc_8260C808;
	// lwz r7,4(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi. r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8260c808
	if (!ctx.cr0.eq) goto loc_8260C808;
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r9,r6,r7
	REX_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r9.u32);
loc_8260C808:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_8260C80C:
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8260c7dc
	if (!ctx.cr6.eq) goto loc_8260C7DC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r7,r9,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r9.u64;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// srawi r10,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bge cr6,0x8260c850
	if (!ctx.cr6.lt) goto loc_8260C850;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// subf r5,r10,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x8260ea08
	ctx.lr = 0x8260C84C;
	sub_8260EA08(ctx, base);
	// b 0x8260c890
	goto loc_8260C890;
loc_8260C850:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8260c890
	if (!ctx.cr6.lt) goto loc_8260C890;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8260c890
	if (ctx.cr6.eq) goto loc_8260C890;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8260c88c
	if (ctx.cr6.eq) goto loc_8260C88C;
loc_8260C874:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne cr6,0x8260c874
	if (!ctx.cr6.eq) goto loc_8260C874;
loc_8260C88C:
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8260C890:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82611668) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x826116a8
	if (!ctx.cr6.lt) goto loc_826116A8;
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x826116a8
	if (ctx.cr6.eq) goto loc_826116A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_826116A8:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x826116e8
	if (!ctx.cr6.lt) goto loc_826116E8;
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x826116e8
	if (ctx.cr6.eq) goto loc_826116E8;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_826116E8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826166B8) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,25912
	ctx.r11.s64 = ctx.r11.s64 + 25912;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq cr6,0x826166e8
	if (ctx.cr6.eq) goto loc_826166E8;
	// bl 0x825e0378
	ctx.lr = 0x826166E8;
	sub_825E0378(ctx, base);
loc_826166E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82615ed8
	ctx.lr = 0x826166F0;
	sub_82615ED8(ctx, base);
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

DEFINE_REX_FUNC(sub_82617780) {
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
	// bl 0x82617618
	ctx.lr = 0x8261779C;
	sub_82617618(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,36(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lwa r31,72(r11)
	ctx.r31.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 72));
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x826177CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// std r31,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r31.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fmadds f1,f13,f0,f31
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f31.f64)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C1C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12024);
	// clrlwi r3,r11,27
	ctx.r3.u64 = ctx.r11.u32 & 0x1F;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C4C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10556);
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C718) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C7F8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,24,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x7;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261C8D8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,23,6,8
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 23) & 0x3800000) | (ctx.r11.u64 & 0xFFFFFFFFFC7FFFFF);
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

DEFINE_REX_FUNC(sub_8261D010) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFFFF000;
	// rlwinm r11,r11,0,20,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
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

DEFINE_REX_FUNC(sub_8261D690) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261D7C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,5,26,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0x20) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r11,10560(r3)
	REX_STORE_U32(ctx.r3.u32 + 10560, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261EC90) {
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
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8262efe8
	ctx.lr = 0x8261ECB4;
	sub_8262EFE8(ctx, base);
	// addi r30,r31,15212
	ctx.r30.s64 = ctx.r31.s64 + 15212;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r8,r11,1536
	ctx.r8.s64 = ctx.r11.s64 + 1536;
loc_8261ECC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8261ece4
	if (!ctx.cr0.eq) goto loc_8261ECE4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8261ecc4
	if (!ctx.cr6.eq) goto loc_8261ECC4;
loc_8261ECE4:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8261ed44
	if (ctx.cr0.eq) goto loc_8261ED44;
	// bl 0x82855964
	ctx.lr = 0x8261ECF0;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8261ed28
	if (ctx.cr6.eq) goto loc_8261ED28;
	// lwz r3,24164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24164);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8261ed1c
	if (ctx.cr6.eq) goto loc_8261ED1C;
	// lwz r11,24168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24168);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8261ed1c
	if (!ctx.cr0.eq) goto loc_8261ED1C;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263a4c0
	ctx.lr = 0x8261ED1C;
	sub_8263A4C0(ctx, base);
loc_8261ED1C:
	// lwz r11,24168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24168);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,24168(r31)
	REX_STORE_U32(ctx.r31.u32 + 24168, ctx.r11.u32);
loc_8261ED28:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x8261ED38;
	sub_8273A030(ctx, base);
	// lwz r11,16916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16916);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,16916(r31)
	REX_STORE_U32(ctx.r31.u32 + 16916, ctx.r11.u32);
loc_8261ED44:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
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

DEFINE_REX_FUNC(sub_826280C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x826280C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82855964
	ctx.lr = 0x826280D4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x826280e8
	if (!ctx.cr6.eq) goto loc_826280E8;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2256);
	// b 0x826280f0
	goto loc_826280F0;
loc_826280E8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2252);
loc_826280F0:
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r31,16920
	ctx.r26.s64 = ctx.r31.s64 + 16920;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82856164
	ctx.lr = 0x82628100;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r10,16772(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16772);
	// lwz r11,21764(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21764);
	// rlwinm r29,r30,24,28,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r27,r30,24
	ctx.r27.u64 = ctx.r30.u32 & 0xFF;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// stw r10,16772(r31)
	REX_STORE_U32(ctx.r31.u32 + 16772, ctx.r10.u32);
	// rlwinm r30,r30,0,0,19
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFF000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// bne cr6,0x82628130
	if (!ctx.cr6.eq) goto loc_82628130;
	// li r28,60
	ctx.r28.s64 = 60;
loc_82628130:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// lwz r10,16760(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16760);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// subf r24,r10,r11
	ctx.r24.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x82855f54
	ctx.lr = 0x82628144;
	__imp__KeQueryPerformanceFrequency(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// mulli r10,r24,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(100));
	// divwu r11,r11,r28
	ctx.r11.u64 = uint32_t(ctx.r28.u32 ? ctx.r11.u32 / ctx.r28.u32 : 0);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r10,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r7,100
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 100, ctx.xer);
	// ble cr6,0x8262816c
	if (!ctx.cr6.gt) goto loc_8262816C;
	// li r7,100
	ctx.r7.s64 = 100;
loc_8262816C:
	// lwz r8,16764(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16764);
	// lwz r10,16756(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16756);
	// add r11,r8,r29
	ctx.r11.u64 = ctx.r8.u64 + ctx.r29.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82628198
	if (ctx.cr6.gt) goto loc_82628198;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82628198
	if (ctx.cr6.eq) goto loc_82628198;
	// cmplw cr6,r7,r27
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r27.u32, ctx.xer);
	// ble cr6,0x82628198
	if (!ctx.cr6.gt) goto loc_82628198;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82628198:
	// lwz r9,16748(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16748);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826281d8
	if (ctx.cr6.eq) goto loc_826281D8;
	// lwz r6,16772(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 16772);
	// addic r5,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r5.s64 = ctx.r30.s64 + -1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subfe r11,r5,r30
	temp.u8 = (~ctx.r5.u32 + ctx.r30.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x826281D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_826281D8:
	// lwz r10,16756(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16756);
	// stw r11,16764(r31)
	REX_STORE_U32(ctx.r31.u32 + 16764, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8262821c
	if (ctx.cr6.eq) goto loc_8262821C;
	// lwz r10,16772(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16772);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8262821c
	if (ctx.cr6.eq) goto loc_8262821C;
	// lwz r10,16912(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16912);
	// rlwinm r10,r10,3,25,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x78;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r9,r10,16780
	ctx.r9.s64 = ctx.r10.s64 + 16780;
	// stw r11,16784(r10)
	REX_STORE_U32(ctx.r10.u32 + 16784, ctx.r11.u32);
	// stw r30,16780(r10)
	REX_STORE_U32(ctx.r10.u32 + 16780, ctx.r30.u32);
	// lwz r11,16912(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16912);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16912(r31)
	REX_STORE_U32(ctx.r31.u32 + 16912, ctx.r11.u32);
	// b 0x82628258
	goto loc_82628258;
loc_8262821C:
	// lwz r11,16776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16776);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16776(r31)
	REX_STORE_U32(ctx.r31.u32 + 16776, ctx.r11.u32);
	// beq cr6,0x82628244
	if (ctx.cr6.eq) goto loc_82628244;
	// lis r11,32712
	ctx.r11.s64 = 2143813632;
	// stw r30,24848(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 24848, ctx.r30.u32);
	// eieio 
	// sync 
	// b 0x82628250
	goto loc_82628250;
loc_82628244:
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82628250:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// stw r11,23588(r31)
	REX_STORE_U32(ctx.r31.u32 + 23588, ctx.r11.u32);
loc_82628258:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82856184
	ctx.lr = 0x82628264;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82637EC0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,10943(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 10943);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stb r11,10943(r3)
	REX_STORE_U8(ctx.r3.u32 + 10943, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82638530) {
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
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplwi cr6,r4,18
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 18, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bgt cr6,0x82638a08
	if (ctx.cr6.gt) goto loc_82638A08;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// rlwinm r0,r31,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-4784
	ctx.r12.s64 = ctx.r12.s64 + -4784;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32156
	ctx.r12.s64 = -2107375616;
	// addi r12,r12,-31348
	ctx.r12.s64 = ctx.r12.s64 + -31348;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r31.u32) {
	case 0:
		goto loc_8263858C;
	case 1:
		goto loc_826385AC;
	case 2:
		goto loc_826385D8;
	case 3:
		goto loc_826385F0;
	case 4:
		goto loc_82638658;
	case 5:
		goto loc_82638680;
	case 6:
		goto loc_826386D8;
	case 7:
		goto loc_82638778;
	case 8:
		goto loc_826387FC;
	case 9:
		goto loc_82638860;
	case 10:
		goto loc_826388C0;
	case 11:
		goto loc_826388F4;
	case 12:
		goto loc_82638938;
	case 13:
		goto loc_82638964;
	case 14:
		goto loc_8263898C;
	case 15:
		goto loc_826389B4;
	case 16:
		goto loc_826389E8;
	case 17:
		goto loc_82638768;
	case 18:
		goto loc_82638778;
	case 19:
		goto loc_8263858C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8263858C:
	// lwz r11,21784(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21784);
	// lfs f0,21800(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 21800);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x82638a0c
	goto loc_82638A0C;
loc_826385AC:
	// lwz r11,21784(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21784);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f0,21796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 21796);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// b 0x82638a0c
	goto loc_82638A0C;
loc_826385D8:
	// lwz r11,16768(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16768);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
loc_826385E4:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// b 0x82638a0c
	goto loc_82638A0C;
loc_826385F0:
	// lwz r11,21824(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21824);
	// lwz r9,21784(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21784);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
loc_82638614:
	// frsp f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r11,r8,12236
	ctx.r11.s64 = ctx.r8.s64 + 12236;
	// lfs f12,232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
loc_82638628:
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f0,17092(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17092);
	ctx.f0.f64 = double(temp.f32);
loc_82638630:
	// fmuls f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82638644
	if (!ctx.cr6.lt) goto loc_82638644;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x82638650
	goto loc_82638650;
loc_82638644:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x82638650
	if (ctx.cr6.gt) goto loc_82638650;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_82638650:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// b 0x82638a0c
	goto loc_82638A0C;
loc_82638658:
	// lwz r9,21828(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21828);
	// lwz r11,21784(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21784);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// b 0x82638614
	goto loc_82638614;
loc_82638680:
	// lwz r11,21784(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21784);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lwz r9,21828(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21828);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// lwz r7,21824(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 21824);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,17092(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17092);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r8,12236
	ctx.r10.s64 = ctx.r8.s64 + 12236;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f12,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 / ctx.f13.f64));
	// b 0x82638630
	goto loc_82638630;
loc_826386D8:
	// lwz r11,21832(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21832);
	// lwz r8,10896(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 10896);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// clrlwi r9,r11,29
	ctx.r9.u64 = ctx.r11.u32 & 0x7;
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// clrlwi r10,r7,29
	ctx.r10.u64 = ctx.r7.u32 & 0x7;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwbrx r31,r7,r8
	ctx.r31.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32));
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// lwbrx r30,r10,r8
	ctx.r30.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32));
	// lwbrx r10,r9,r8
	ctx.r10.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32));
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// stw r11,21832(r3)
	REX_STORE_U32(ctx.r3.u32 + 21832, ctx.r11.u32);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// cmpldi cr6,r30,0
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpld cr6,r10,r30
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r30.u64, ctx.xer);
	// rldicr r11,r11,32,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bgt cr6,0x8263874c
	if (ctx.cr6.gt) goto loc_8263874C;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8263874C:
	// cmpld cr6,r31,r10
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, ctx.r10.u64, ctx.xer);
	// bgt cr6,0x82638758
	if (ctx.cr6.gt) goto loc_82638758;
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_82638758:
	// subf r3,r10,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r10.u64;
	// bl 0x8273acd0
	ctx.lr = 0x82638760;
	sub_8273ACD0(ctx, base);
	// subf r3,r30,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r30.u64;
	// b 0x82638838
	goto loc_82638838;
loc_82638768:
	// lwz r11,23560(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 23560);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x826385e4
	goto loc_826385E4;
loc_82638778:
	// bl 0x82637ed0
	ctx.lr = 0x8263877C;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,-14156
	ctx.r7.s64 = ctx.r11.s64 + -14156;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// lwz r9,-14156(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -14156);
	// ld r11,588(r7)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r7.u32 + 588);
	// ld r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r7.u32 + 4);
	// ld r8,596(r7)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r7.u32 + 596);
	// ld r7,12(r7)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r7.u32 + 12);
	// subf r31,r11,r10
	ctx.r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// subf r3,r8,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r8.u64;
	// bne cr6,0x826387c4
	if (!ctx.cr6.eq) goto loc_826387C4;
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
loc_826387C4:
	// cmpldi cr6,r3,0
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// bl 0x8273acd0
	ctx.lr = 0x826387D0;
	sub_8273ACD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8273acd0
	ctx.lr = 0x826387DC;
	sub_8273ACD0(ctx, base);
	// fdiv f11,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f31.f64 / ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r9,r11,12236
	ctx.r9.s64 = ctx.r11.s64 + 12236;
	// lfs f13,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// b 0x82638628
	goto loc_82638628;
loc_826387FC:
	// bl 0x82637ed0
	ctx.lr = 0x82638800;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r11,r11,-14156
	ctx.r11.s64 = ctx.r11.s64 + -14156;
	// ld r10,708(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 708);
	// ld r9,124(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 124);
	// subf r31,r10,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// ld r10,716(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 716);
	// ld r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 132);
loc_8263882C:
	// subf r3,r10,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x8273acd0
	ctx.lr = 0x82638834;
	sub_8273ACD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82638838:
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8273acd0
	ctx.lr = 0x82638840;
	sub_8273ACD0(ctx, base);
	// fdiv f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64 / ctx.f1.f64;
loc_82638844:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// frsp f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r10,r10,12236
	ctx.r10.s64 = ctx.r10.s64 + 12236;
	// lfs f0,17092(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82638630
	goto loc_82638630;
loc_82638860:
	// bl 0x82637ed0
	ctx.lr = 0x82638864;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r31,r11,-14156
	ctx.r31.s64 = ctx.r11.s64 + -14156;
	// ld r11,708(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 708);
	// ld r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 124);
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpldi cr6,r3,0
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// bl 0x8273acd0
	ctx.lr = 0x8263888C;
	sub_8273ACD0(ctx, base);
	// ld r11,716(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 716);
	// ld r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 132);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x8273acd0
	ctx.lr = 0x826388A0;
	sub_8273ACD0(ctx, base);
	// ld r11,724(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 724);
	// ld r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 140);
	// fsub f30,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f31.f64 - ctx.f1.f64;
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x8273acd0
	ctx.lr = 0x826388B4;
	sub_8273ACD0(ctx, base);
	// fsub f13,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f30.f64 - ctx.f1.f64;
	// fdiv f13,f13,f31
	ctx.f13.f64 = ctx.f13.f64 / ctx.f31.f64;
	// b 0x82638844
	goto loc_82638844;
loc_826388C0:
	// bl 0x82637ed0
	ctx.lr = 0x826388C4;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r11,r11,-14156
	ctx.r11.s64 = ctx.r11.s64 + -14156;
	// ld r10,708(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 708);
	// ld r9,124(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 124);
	// subf r31,r10,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// beq cr6,0x82638a08
	if (ctx.cr6.eq) goto loc_82638A08;
	// ld r10,724(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 724);
	// ld r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 140);
	// b 0x8263882c
	goto loc_8263882C;
loc_826388F4:
	// bl 0x82637ed0
	ctx.lr = 0x826388F8;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,1028(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 1028);
	// ld r10,444(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 444);
	// ld r9,1020(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 1020);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ld r11,588(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 588);
	// ld r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r8,436(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 436);
	// subf r9,r9,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r9.u64;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
loc_8263892C:
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_82638930:
	// bl 0x82638008
	ctx.lr = 0x82638934;
	sub_82638008(ctx, base);
	// b 0x82638a0c
	goto loc_82638A0C;
loc_82638938:
	// bl 0x82637ed0
	ctx.lr = 0x8263893C;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,588(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 588);
	// ld r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r9,1036(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 1036);
	// ld r8,452(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 452);
loc_8263895C:
	// subf r3,r9,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x8263892c
	goto loc_8263892C;
loc_82638964:
	// bl 0x82637ed0
	ctx.lr = 0x82638968;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,588(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 588);
	// ld r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r9,820(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 820);
	// ld r8,236(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 236);
	// b 0x8263895c
	goto loc_8263895C;
loc_8263898C:
	// bl 0x82637ed0
	ctx.lr = 0x82638990;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,588(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 588);
	// ld r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r9,676(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 676);
	// ld r8,92(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 92);
	// b 0x8263895c
	goto loc_8263895C;
loc_826389B4:
	// bl 0x82637ed0
	ctx.lr = 0x826389B8;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,1044(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 1044);
	// ld r10,460(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 460);
loc_826389D0:
	// ld r9,588(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 588);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ld r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// rldicr r3,r11,1,62
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// subf r4,r9,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x82638930
	goto loc_82638930;
loc_826389E8:
	// bl 0x82637ed0
	ctx.lr = 0x826389EC;
	sub_82637ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82638a08
	if (ctx.cr0.eq) goto loc_82638A08;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r11,-14156
	ctx.r8.s64 = ctx.r11.s64 + -14156;
	// ld r11,1052(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 1052);
	// ld r10,468(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 468);
	// b 0x826389d0
	goto loc_826389D0;
loc_82638A08:
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
loc_82638A0C:
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

DEFINE_REX_FUNC(sub_8265EA80) {
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
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
loc_8265EA90:
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
	// bne 0x8265ea90
	if (!ctx.cr0.eq) goto loc_8265EA90;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8265eac4
	if (!ctx.cr6.eq) goto loc_8265EAC4;
	// li r11,15
	ctx.r11.s64 = 15;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x8264cf40
	ctx.lr = 0x8265EAC4;
	sub_8264CF40(ctx, base);
loc_8265EAC4:
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

DEFINE_REX_FUNC(sub_82660730) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82660738;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// lwz r8,212(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// bl 0x82685b20
	ctx.lr = 0x82660774;
	sub_82685B20(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x826607b8
	if (ctx.cr0.lt) goto loc_826607B8;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r8,244(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r7,220(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,236(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// bl 0x82660650
	ctx.lr = 0x8266079C;
	sub_82660650(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x826607b8
	if (ctx.cr0.lt) goto loc_826607B8;
	// lwz r4,228(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82684620
	ctx.lr = 0x826607B0;
	sub_82684620(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_826607B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82662910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82662918;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af1c
	ctx.lr = 0x82662920;
	__savefpr_25(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r15,r3,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r20,r6
	ctx.r20.u64 = ctx.r6.u64;
	// mr r17,r7
	ctx.r17.u64 = ctx.r7.u64;
	// li r14,0
	ctx.r14.s64 = 0;
	// li r22,0
	ctx.r22.s64 = 0;
	// li r19,0
	ctx.r19.s64 = 0;
	// bl 0x8263b678
	ctx.lr = 0x82662954;
	sub_8263B678(ctx, base);
	// mr. r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq 0x82662988
	if (ctx.cr0.eq) goto loc_82662988;
	// rlwinm r31,r18,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8263b678
	ctx.lr = 0x8266296C;
	sub_8263B678(ctx, base);
	// mr. r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq 0x82662988
	if (ctx.cr0.eq) goto loc_82662988;
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8263b678
	ctx.lr = 0x82662980;
	sub_8263B678(ctx, base);
	// mr. r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// bne 0x82662994
	if (!ctx.cr0.eq) goto loc_82662994;
loc_82662988:
	// lis r14,-32761
	ctx.r14.s64 = -2147024896;
	// ori r14,r14,14
	ctx.r14.u64 = ctx.r14.u64 | 14;
	// b 0x82662dcc
	goto loc_82662DCC;
loc_82662994:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x826629b4
	if (!ctx.cr6.gt) goto loc_826629B4;
	// addi r11,r16,-4
	ctx.r11.s64 = ctx.r16.s64 + -4;
	// mtctr r23
	ctx.ctr.u64 = ctx.r23.u64;
loc_826629A8:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826629a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826629A8;
loc_826629B4:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// ble cr6,0x826629d4
	if (!ctx.cr6.gt) goto loc_826629D4;
	// addi r11,r22,-4
	ctx.r11.s64 = ctx.r22.s64 + -4;
	// mtctr r18
	ctx.ctr.u64 = ctx.r18.u64;
loc_826629C8:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826629c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826629C8;
loc_826629D4:
	// addi r8,r23,-1
	ctx.r8.s64 = ctx.r23.s64 + -1;
loc_826629D8:
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x82662a2c
	if (!ctx.cr6.gt) goto loc_82662A2C;
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// subf r9,r30,r16
	ctx.r9.u64 = ctx.r16.u64 - ctx.r30.u64;
loc_826629F4:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82662a20
	if (!ctx.cr6.gt) goto loc_82662A20;
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r5,r9,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// stwx r6,r9,r11
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r6.u32);
loc_82662A20:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826629f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826629F4;
loc_82662A2C:
	// clrlwi. r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826629d8
	if (!ctx.cr0.eq) goto loc_826629D8;
	// addi r8,r18,-1
	ctx.r8.s64 = ctx.r18.s64 + -1;
loc_82662A38:
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x82662a8c
	if (!ctx.cr6.gt) goto loc_82662A8C;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r11,r20,4
	ctx.r11.s64 = ctx.r20.s64 + 4;
	// subf r9,r20,r22
	ctx.r9.u64 = ctx.r22.u64 - ctx.r20.u64;
loc_82662A54:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82662a80
	if (!ctx.cr6.gt) goto loc_82662A80;
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwzx r6,r9,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// stwx r5,r9,r11
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r5.u32);
loc_82662A80:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82662a54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82662A54;
loc_82662A8C:
	// clrlwi. r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82662a38
	if (!ctx.cr0.eq) goto loc_82662A38;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r24,r18
	ctx.r24.u64 = ctx.r18.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// lfs f29,2524(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f29.f64 = double(temp.f32);
	// ble cr6,0x82662ad8
	if (!ctx.cr6.gt) goto loc_82662AD8;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82662AB4:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82662ad4
	if (!ctx.cr6.lt) goto loc_82662AD4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// blt cr6,0x82662ab4
	if (ctx.cr6.lt) goto loc_82662AB4;
	// b 0x82662ad8
	goto loc_82662AD8;
loc_82662AD4:
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
loc_82662AD8:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// ble cr6,0x82662b0c
	if (!ctx.cr6.gt) goto loc_82662B0C;
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_82662AE8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82662b08
	if (!ctx.cr6.lt) goto loc_82662B08;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r18.s32, ctx.xer);
	// blt cr6,0x82662ae8
	if (ctx.cr6.lt) goto loc_82662AE8;
	// b 0x82662b0c
	goto loc_82662B0C;
loc_82662B08:
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
loc_82662B0C:
	// subf r26,r24,r18
	ctx.r26.u64 = ctx.r18.u64 - ctx.r24.u64;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// ble cr6,0x82662b5c
	if (!ctx.cr6.gt) goto loc_82662B5C;
	// mr r9,r19
	ctx.r9.u64 = ctx.r19.u64;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
loc_82662B24:
	// stfs f29,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x82662b4c
	if (!ctx.cr6.gt) goto loc_82662B4C;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi r23,0
	ctx.cr0.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq 0x82662b4c
	if (ctx.cr0.eq) goto loc_82662B4C;
	// mtctr r23
	ctx.ctr.u64 = ctx.r23.u64;
loc_82662B44:
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82662b44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82662B44;
loc_82662B4C:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r11,r15,r11
	ctx.r11.u64 = ctx.r15.u64 + ctx.r11.u64;
	// bne 0x82662b24
	if (!ctx.cr0.eq) goto loc_82662B24;
loc_82662B5C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x82662dcc
	if (!ctx.cr6.gt) goto loc_82662DCC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// cmpw cr6,r6,r23
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r23.s32, ctx.xer);
	// lfs f25,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f25.f64 = double(temp.f32);
	// bge cr6,0x82662d24
	if (!ctx.cr6.lt) goto loc_82662D24;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// add r29,r11,r16
	ctx.r29.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// subf r25,r16,r30
	ctx.r25.u64 = ctx.r30.u64 - ctx.r16.u64;
	// lfs f26,-8900(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8900);
	ctx.f26.f64 = double(temp.f32);
	// lfd f28,8008(r11)
	ctx.f28.u64 = REX_LOAD_U64(ctx.r11.u32 + 8008);
	// lfs f27,7988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7988);
	ctx.f27.f64 = double(temp.f32);
loc_82662B9C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// cmpw cr6,r24,r18
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r18.s32, ctx.xer);
	// bge cr6,0x82662bd0
	if (!ctx.cr6.lt) goto loc_82662BD0;
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r25,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// add r10,r10,r20
	ctx.r10.u64 = ctx.r10.u64 + ctx.r20.u64;
loc_82662BB4:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82662bd0
	if (!ctx.cr6.gt) goto loc_82662BD0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r18.s32, ctx.xer);
	// blt cr6,0x82662bb4
	if (ctx.cr6.lt) goto loc_82662BB4;
loc_82662BD0:
	// subf r11,r24,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r24.u64;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// divw r9,r11,r26
	ctx.r9.u64 = uint32_t((ctx.r26.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r11.s32 / ctx.r26.s32 : 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r9,r9,r26
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r26.s32);
	// divw r8,r10,r26
	ctx.r8.u64 = uint32_t((ctx.r26.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r10.s32 / ctx.r26.s32 : 0);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// mullw r9,r8,r26
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r26.s32);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// add r28,r11,r24
	ctx.r28.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r27,r10,r24
	ctx.r27.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r27,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r30,r20
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r20.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r20
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r20.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmuls f1,f31,f27
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f27.f64));
	// bl 0x827389e8
	ctx.lr = 0x82662C18;
	sub_827389E8(ctx, base);
	// lfsx f0,r25,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfsx f12,r31,r20
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r20.u32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f30,f0,f12
	ctx.f30.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fnmsubs f31,f13,f26,f31
	ctx.f31.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f26.f64, -ctx.f31.f64)));
	// fmuls f1,f30,f27
	ctx.f1.f64 = double(float(ctx.f30.f64 * ctx.f27.f64));
	// bl 0x827389e8
	ctx.lr = 0x82662C34;
	sub_827389E8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// cmpw cr6,r27,r28
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r28.s32, ctx.xer);
	// fnmsubs f0,f0,f26,f30
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f26.f64, -ctx.f30.f64)));
	// bne cr6,0x82662c70
	if (!ctx.cr6.eq) goto loc_82662C70;
	// lwzx r10,r31,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r22.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mullw r10,r10,r23
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r23.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f25,r11,r17
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r17.u32, temp.u32);
	// lwzx r11,r31,r22
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r22.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r19
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f25
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f25.f64));
	// b 0x82662d10
	goto loc_82662D10;
loc_82662C70:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x82662e04
	if (ctx.cr6.eq) goto loc_82662E04;
	// fdivs f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 / ctx.f31.f64));
	// fmul f1,f30,f28
	ctx.f1.f64 = ctx.f30.f64 * ctx.f28.f64;
	// bl 0x82738cc0
	ctx.lr = 0x82662C84;
	sub_82738CC0(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bge cr6,0x82662c94
	if (!ctx.cr6.lt) goto loc_82662C94;
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
loc_82662C94:
	// fmul f1,f30,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64 * ctx.f28.f64;
	// bl 0x82738be0
	ctx.lr = 0x82662C9C;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82662cac
	if (!ctx.cr6.lt) goto loc_82662CAC;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
loc_82662CAC:
	// cmpwi cr6,r18,1
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 1, ctx.xer);
	// bne cr6,0x82662cbc
	if (!ctx.cr6.eq) goto loc_82662CBC;
	// fmr f0,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f25.f64;
	// fmr f31,f25
	ctx.f31.f64 = ctx.f25.f64;
loc_82662CBC:
	// lwzx r10,r31,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r22.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mullw r10,r10,r23
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r23.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f31,r11,r17
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r17.u32, temp.u32);
	// lwzx r10,r30,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// mullw r10,r23,r10
	ctx.r10.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r10.s32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r11,r17
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r17.u32, temp.u32);
	// lwzx r11,r31,r22
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r22.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r19
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfsx f13,r11,r19
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r19.u32, temp.u32);
	// lwzx r11,r30,r22
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r19
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_82662D10:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// stfsx f0,r11,r19
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r19.u32, temp.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r21,r23
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r23.s32, ctx.xer);
	// blt cr6,0x82662b9c
	if (ctx.cr6.lt) goto loc_82662B9C;
loc_82662D24:
	// fmr f10,f29
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f29.f64;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// ble cr6,0x82662dcc
	if (!ctx.cr6.gt) goto loc_82662DCC;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// mtctr r18
	ctx.ctr.u64 = ctx.r18.u64;
loc_82662D38:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x82662d48
	if (!ctx.cr6.gt) goto loc_82662D48;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
loc_82662D48:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82662d38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82662D38;
	// fcmpu cr6,f10,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f29.f64);
	// beq cr6,0x82662dcc
	if (ctx.cr6.eq) goto loc_82662DCC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// lfs f11,8000(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8000);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,7996(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 7996);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7992(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 7992);
	ctx.f13.f64 = double(temp.f32);
loc_82662D78:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x82662dc0
	if (!ctx.cr6.gt) goto loc_82662DC0;
	// fdivs f0,f25,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f25.f64 / ctx.f10.f64));
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// mtctr r23
	ctx.ctr.u64 = ctx.r23.u64;
loc_82662D8C:
	// lfs f9,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f9,f0,f9
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fmadds f9,f9,f13,f12
	ctx.f9.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f12.f64)));
	// fctiwz f9,f9
	ctx.f9.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwa r8,84(r1)
	ctx.r8.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fmuls f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfsu f9,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82662d8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82662D8C;
loc_82662DC0:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r11,r15,r11
	ctx.r11.u64 = ctx.r15.u64 + ctx.r11.u64;
	// bne 0x82662d78
	if (!ctx.cr0.eq) goto loc_82662D78;
loc_82662DCC:
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x8263b710
	ctx.lr = 0x82662DD8;
	sub_8263B710(ctx, base);
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8263b710
	ctx.lr = 0x82662DE4;
	sub_8263B710(ctx, base);
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x8263b710
	ctx.lr = 0x82662DF0;
	sub_8263B710(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af68
	ctx.lr = 0x82662E00;
	__restfpr_25(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_82662E04:
	// lis r14,-32761
	ctx.r14.s64 = -2147024896;
	// ori r14,r14,87
	ctx.r14.u64 = ctx.r14.u64 | 87;
	// b 0x82662dcc
	goto loc_82662DCC;
}

DEFINE_REX_FUNC(sub_826961A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x826961A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// addi r28,r4,76
	ctx.r28.s64 = ctx.r4.s64 + 76;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82696214
	if (ctx.cr6.eq) goto loc_82696214;
	// lhz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82696204
	if (ctx.cr6.eq) goto loc_82696204;
	// li r31,0
	ctx.r31.s64 = 0;
loc_826961D4:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,224(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 224);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x8268f838
	ctx.lr = 0x826961F0;
	sub_8268F838(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lhz r10,72(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 72);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826961d4
	if (ctx.cr6.lt) goto loc_826961D4;
loc_82696204:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,224(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 224);
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x8268f838
	ctx.lr = 0x82696214;
	sub_8268F838(ctx, base);
loc_82696214:
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// addi r28,r30,80
	ctx.r28.s64 = ctx.r30.s64 + 80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82696274
	if (ctx.cr6.eq) goto loc_82696274;
	// lhz r11,74(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 74);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82696264
	if (ctx.cr6.eq) goto loc_82696264;
	// li r31,0
	ctx.r31.s64 = 0;
loc_82696234:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mulli r11,r31,28
	ctx.r11.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(28));
	// lwz r3,224(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 224);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r11,24
	ctx.r5.s64 = ctx.r11.s64 + 24;
	// bl 0x8268f838
	ctx.lr = 0x82696250;
	sub_8268F838(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lhz r10,74(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 74);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82696234
	if (ctx.cr6.lt) goto loc_82696234;
loc_82696264:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,224(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 224);
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x8268f838
	ctx.lr = 0x82696274;
	sub_8268F838(ctx, base);
loc_82696274:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269AF00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8269AF08;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r27,44(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// bl 0x8269a118
	ctx.lr = 0x8269AF38;
	sub_8269A118(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269af5c
	if (!ctx.cr6.eq) goto loc_8269AF5C;
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// ori r3,r3,9
	ctx.r3.u64 = ctx.r3.u64 | 9;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8269AF5C:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8269af94
	if (!ctx.cr6.gt) goto loc_8269AF94;
	// lis r11,80
	ctx.r11.s64 = 5242880;
	// ori r29,r11,1
	ctx.r29.u64 = ctx.r11.u64 | 1;
loc_8269AF70:
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269acb8
	ctx.lr = 0x8269AF84;
	sub_8269ACB8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// cmpw cr6,r3,r29
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r29.s32, ctx.xer);
	// bne cr6,0x8269af70
	if (!ctx.cr6.eq) goto loc_8269AF70;
loc_8269AF94:
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// ld r4,16(r30)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r30.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269a798
	ctx.lr = 0x8269AFA8;
	sub_8269A798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269afdc
	if (!ctx.cr6.eq) goto loc_8269AFDC;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269be98
	ctx.lr = 0x8269AFD4;
	sub_8269BE98(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
loc_8269AFDC:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269b008
	if (!ctx.cr6.eq) goto loc_8269B008;
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// ori r3,r3,8
	ctx.r3.u64 = ctx.r3.u64 | 8;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8269B008:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82699f48
	ctx.lr = 0x8269B014;
	sub_82699F48(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// lwz r31,44(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8269b044
	if (!ctx.cr6.eq) goto loc_8269B044;
	// std r28,48(r27)
	REX_STORE_U64(ctx.r27.u32 + 48, ctx.r28.u64);
	// stw r28,56(r27)
	REX_STORE_U32(ctx.r27.u32 + 56, ctx.r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8269B044:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269b0f8
	if (ctx.cr6.eq) goto loc_8269B0F8;
loc_8269B050:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r30,8(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8269b0e8
	if (!ctx.cr6.eq) goto loc_8269B0E8;
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8269B078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// lwz r10,148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8269b09c
	if (!ctx.cr6.eq) goto loc_8269B09C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8269B09C:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8269b0b8
	if (ctx.cr6.eq) goto loc_8269B0B8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8269B0B8:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8269b0d0
	if (ctx.cr6.eq) goto loc_8269B0D0;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
loc_8269B0D0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r4,29
	ctx.r4.s64 = 29;
	// bl 0x8268f838
	ctx.lr = 0x8269B0E0;
	sub_8268F838(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
loc_8269B0E8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8269b050
	if (!ctx.cr6.eq) goto loc_8269B050;
loc_8269B0F8:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269b108
	if (ctx.cr6.lt) goto loc_8269B108;
	// std r28,48(r27)
	REX_STORE_U64(ctx.r27.u32 + 48, ctx.r28.u64);
	// stw r28,56(r27)
	REX_STORE_U32(ctx.r27.u32 + 56, ctx.r28.u32);
loc_8269B108:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826BA728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826BA730;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,22524(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 22524);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826ba778
	if (ctx.cr6.eq) goto loc_826BA778;
	// lwz r11,22516(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 22516);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,15232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 15232);
	// beq cr6,0x826ba76c
	if (ctx.cr6.eq) goto loc_826BA76C;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826ba778
	if (!ctx.cr6.eq) goto loc_826BA778;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,15232(r3)
	REX_STORE_U32(ctx.r3.u32 + 15232, ctx.r11.u32);
	// b 0x826ba774
	goto loc_826BA774;
loc_826BA76C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826ba778
	if (ctx.cr6.eq) goto loc_826BA778;
loc_826BA774:
	// stw r30,22524(r31)
	REX_STORE_U32(ctx.r31.u32 + 22524, ctx.r30.u32);
loc_826BA778:
	// lwz r10,15232(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15232);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x826ba7dc
	if (ctx.cr6.eq) goto loc_826BA7DC;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826ba798
	if (ctx.cr6.eq) goto loc_826BA798;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x826ba7dc
	if (!ctx.cr6.eq) goto loc_826BA7DC;
loc_826BA798:
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,15232(r31)
	REX_STORE_U32(ctx.r31.u32 + 15232, ctx.r11.u32);
	// bne cr6,0x826ba7dc
	if (!ctx.cr6.eq) goto loc_826BA7DC;
	// addi r4,r31,3720
	ctx.r4.s64 = ctx.r31.s64 + 3720;
	// lwz r29,3720(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3720);
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,15236(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15236);
	// bl 0x8270a668
	ctx.lr = 0x826BA7BC;
	sub_8270A668(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,15236(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15236);
	// bl 0x8270a6b8
	ctx.lr = 0x826BA7C8;
	sub_8270A6B8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826ba7dc
	if (ctx.cr6.eq) goto loc_826BA7DC;
	// li r3,-100
	ctx.r3.s64 = -100;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_826BA7DC:
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826ba7f4
	if (ctx.cr6.eq) goto loc_826BA7F4;
	// lwz r10,22516(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22516);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826ba80c
	if (ctx.cr6.eq) goto loc_826BA80C;
loc_826BA7F4:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,22516(r31)
	REX_STORE_U32(ctx.r31.u32 + 22516, ctx.r30.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,15232(r31)
	REX_STORE_U32(ctx.r31.u32 + 15232, ctx.r10.u32);
	// bne cr6,0x826ba80c
	if (!ctx.cr6.eq) goto loc_826BA80C;
	// stw r10,22520(r31)
	REX_STORE_U32(ctx.r31.u32 + 22520, ctx.r10.u32);
loc_826BA80C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C3FC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x826C3FD0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,276(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826c405c
	if (!ctx.cr6.gt) goto loc_826C405C;
	// lwz r31,260(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// subf r27,r6,r11
	ctx.r27.u64 = ctx.r11.u64 - ctx.r6.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
loc_826C4008:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c402c
	if (!ctx.cr6.gt) goto loc_826C402C;
	// subf r11,r31,r27
	ctx.r11.u64 = ctx.r27.u64 - ctx.r31.u64;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
loc_826C4020:
	// lbzux r9,r11,r31
	ea = ctx.r11.u32 + ctx.r31.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826c4020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C4020;
loc_826C402C:
	// bl 0x826c3b50
	ctx.lr = 0x826C4030;
	sub_826C3B50(ctx, base);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c4050
	if (!ctx.cr6.gt) goto loc_826C4050;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// subf r10,r31,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r31.u64;
loc_826C4044:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stbux r9,r10,r31
	ea = ctx.r10.u32 + ctx.r31.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826c4044
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C4044;
loc_826C4050:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// bne 0x826c4008
	if (!ctx.cr0.eq) goto loc_826C4008;
loc_826C405C:
	// lwz r26,244(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// lwz r31,268(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r4,252(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 252);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x826c4130
	if (!ctx.cr6.gt) goto loc_826C4130;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// subf r28,r29,r25
	ctx.r28.u64 = ctx.r25.u64 - ctx.r29.u64;
loc_826C4078:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c409c
	if (!ctx.cr6.gt) goto loc_826C409C;
	// subf r11,r31,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r31.u64;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
loc_826C4090:
	// lbzux r9,r11,r31
	ea = ctx.r11.u32 + ctx.r31.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826c4090
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C4090;
loc_826C409C:
	// bl 0x826c3b50
	ctx.lr = 0x826C40A0;
	sub_826C3B50(ctx, base);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c40c0
	if (!ctx.cr6.gt) goto loc_826C40C0;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// subf r10,r31,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r31.u64;
loc_826C40B4:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stbux r9,r10,r31
	ea = ctx.r10.u32 + ctx.r31.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826c40b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C40B4;
loc_826C40C0:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x826c4078
	if (!ctx.cr0.eq) goto loc_826C4078;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x826c4130
	if (!ctx.cr6.gt) goto loc_826C4130;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// subf r29,r30,r24
	ctx.r29.u64 = ctx.r24.u64 - ctx.r30.u64;
loc_826C40DC:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c4100
	if (!ctx.cr6.gt) goto loc_826C4100;
	// subf r11,r31,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r31.u64;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_826C40F4:
	// lbzux r9,r11,r31
	ea = ctx.r11.u32 + ctx.r31.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826c40f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C40F4;
loc_826C4100:
	// bl 0x826c3b50
	ctx.lr = 0x826C4104;
	sub_826C3B50(ctx, base);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826c4124
	if (!ctx.cr6.gt) goto loc_826C4124;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// subf r10,r31,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r31.u64;
loc_826C4118:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stbux r9,r10,r31
	ea = ctx.r10.u32 + ctx.r31.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826c4118
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826C4118;
loc_826C4124:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x826c40dc
	if (!ctx.cr0.eq) goto loc_826C40DC;
loc_826C4130:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CE990) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826cea48
	if (ctx.cr6.eq) goto loc_826CEA48;
	// lwz r3,20(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826ce9c8
	if (ctx.cr6.eq) goto loc_826CE9C8;
	// bl 0x826bedc8
	ctx.lr = 0x826CE9C4;
	sub_826BEDC8(ctx, base);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_826CE9C8:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826ce9dc
	if (ctx.cr6.eq) goto loc_826CE9DC;
	// bl 0x826bedc8
	ctx.lr = 0x826CE9D8;
	sub_826BEDC8(ctx, base);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
loc_826CE9DC:
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826ce9f0
	if (ctx.cr6.eq) goto loc_826CE9F0;
	// bl 0x826bedc8
	ctx.lr = 0x826CE9EC;
	sub_826BEDC8(ctx, base);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
loc_826CE9F0:
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826cea04
	if (ctx.cr6.eq) goto loc_826CEA04;
	// bl 0x826bedc8
	ctx.lr = 0x826CEA00;
	sub_826BEDC8(ctx, base);
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
loc_826CEA04:
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826cea18
	if (ctx.cr6.eq) goto loc_826CEA18;
	// bl 0x826bedc8
	ctx.lr = 0x826CEA14;
	sub_826BEDC8(ctx, base);
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
loc_826CEA18:
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826cea2c
	if (ctx.cr6.eq) goto loc_826CEA2C;
	// bl 0x826bedc8
	ctx.lr = 0x826CEA28;
	sub_826BEDC8(ctx, base);
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
loc_826CEA2C:
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826cea40
	if (ctx.cr6.eq) goto loc_826CEA40;
	// bl 0x826bedc8
	ctx.lr = 0x826CEA3C;
	sub_826BEDC8(ctx, base);
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
loc_826CEA40:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bedc8
	ctx.lr = 0x826CEA48;
	sub_826BEDC8(ctx, base);
loc_826CEA48:
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

DEFINE_REX_FUNC(sub_826DA640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826DA648;
	__savegprlr_29(ctx, base);
	// addi r11,r4,96
	ctx.r11.s64 = ctx.r4.s64 + 96;
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// vspltisw128 v62,11
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0xB)));
	// li r6,48
	ctx.r6.s64 = 48;
	// vupkhsb128 v61,v63,v96
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v63.s16))));
	// li r7,80
	ctx.r7.s64 = 80;
	// vupklsb128 v60,v63,v96
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.s16)));
	// li r8,64
	ctx.r8.s64 = 64;
	// vspltisw128 v59,3
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0x3)));
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lvx128 v41,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v12,v61,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v61.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v57,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupklsb128 v56,v58,v96
	simde_mm_store_si128((simde__m128i*)ctx.v56.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.s16)));
	// vupklsb128 v55,v57,v96
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.s16)));
	// lvx128 v54,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsb128 v53,v58,v96
	simde_mm_store_si128((simde__m128i*)ctx.v53.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v58.s16), simde_mm_load_si128((simde__m128i*)ctx.v58.s16))));
	// lvx128 v52,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsb128 v51,v57,v96
	simde_mm_store_si128((simde__m128i*)ctx.v51.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v57.s16), simde_mm_load_si128((simde__m128i*)ctx.v57.s16))));
	// addi r5,r9,14640
	ctx.r5.s64 = ctx.r9.s64 + 14640;
	// vcsxwfp128 v13,v56,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// li r9,-32
	ctx.r9.s64 = -32;
	// vcsxwfp128 v9,v55,0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vupkhsb128 v50,v52,v96
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v52.s16), simde_mm_load_si128((simde__m128i*)ctx.v52.s16))));
	// vcsxwfp128 v8,v53,0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vupkhsb128 v49,v54,v96
	simde_mm_store_si128((simde__m128i*)ctx.v49.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v54.s16), simde_mm_load_si128((simde__m128i*)ctx.v54.s16))));
	// vcsxwfp128 v7,v51,0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v51.u32)));
	// lvx128 v48,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsb128 v47,v48,v96
	simde_mm_store_si128((simde__m128i*)ctx.v47.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v48.s16), simde_mm_load_si128((simde__m128i*)ctx.v48.s16))));
	// li r31,64
	ctx.r31.s64 = 64;
	// vcsxwfp128 v1,v50,0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v50.u32)));
	// lvx128 v0,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcsxwfp128 v31,v49,0
	simde_mm_store_ps(ctx.v31.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v49.u32)));
	// vaddsws v5,v12,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vupklsb128 v46,v54,v96
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.s16)));
	// li r9,32
	ctx.r9.s64 = 32;
	// vslw128 v10,v47,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v47.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vupklsb128 v45,v52,v96
	simde_mm_store_si128((simde__m128i*)ctx.v45.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.s16)));
	// lvx128 v12,r5,r31
	ea = (ctx.r5.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v11,v60,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_sllv_epi32(a, shift));
	}
	// li r30,80
	ctx.r30.s64 = 80;
	// vupklsb128 v44,v48,v96
	simde_mm_store_si128((simde__m128i*)ctx.v44.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v48.s16)));
	// vcsxwfp128 v3,v46,0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v46.u32)));
	// li r29,96
	ctx.r29.s64 = 96;
	// vsubsws v30,v5,v10
	temp.s64 = int64_t(ctx.v5.s32[0]) - int64_t(ctx.v10.s32[0]);
	ctx.v30.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v5.s32[1]) - int64_t(ctx.v10.s32[1]);
	ctx.v30.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v5.s32[2]) - int64_t(ctx.v10.s32[2]);
	ctx.v30.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v5.s32[3]) - int64_t(ctx.v10.s32[3]);
	ctx.v30.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vcsxwfp128 v2,v45,0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v45.u32)));
	// vaddfp128 v43,v13,v9
	simde_mm_store_ps(ctx.v43.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vaddsws v27,v5,v10
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// li r31,32
	ctx.r31.s64 = 32;
	// lvx128 v40,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v42,v8,v7
	simde_mm_store_ps(ctx.v42.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vaddsws v4,v11,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// lvx128 v11,r5,r30
	ea = (ctx.r5.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v6,v44,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v44.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v10,r5,r29
	ea = (ctx.r5.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupklsb128 v38,v40,v96
	simde_mm_store_si128((simde__m128i*)ctx.v38.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.s16)));
	// vaddfp128 v39,v1,v31
	simde_mm_store_ps(ctx.v39.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v31.f32)));
	// vupklsb128 v37,v41,v96
	simde_mm_store_si128((simde__m128i*)ctx.v37.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.s16)));
	// vupkhsb128 v63,v41,v96
	simde_mm_store_si128((simde__m128i*)ctx.v63.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v41.s16), simde_mm_load_si128((simde__m128i*)ctx.v41.s16))));
	// li r4,112
	ctx.r4.s64 = 112;
	// vspltisw128 v36,8
	simde_mm_store_si128((simde__m128i*)ctx.v36.u32, simde_mm_set1_epi32(int(0x8)));
	// vaddsws v19,v4,v6
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vspltisw128 v35,14
	simde_mm_store_si128((simde__m128i*)ctx.v35.u32, simde_mm_set1_epi32(int(0xE)));
	// li r11,128
	ctx.r11.s64 = 128;
	// vspltisw128 v34,2
	simde_mm_store_si128((simde__m128i*)ctx.v34.u32, simde_mm_set1_epi32(int(0x2)));
	// vcsxwfp128 v23,v38,0
	simde_mm_store_ps(ctx.v23.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v38.u32)));
	// vspltisw128 v33,4
	simde_mm_store_si128((simde__m128i*)ctx.v33.u32, simde_mm_set1_epi32(int(0x4)));
	// vcsxwfp128 v24,v37,0
	simde_mm_store_ps(ctx.v24.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v37.u32)));
	// vaddfp128 v32,v2,v3
	simde_mm_store_ps(ctx.v32.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vupkhsb128 v62,v40,v96
	simde_mm_store_si128((simde__m128i*)ctx.v62.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v40.s16), simde_mm_load_si128((simde__m128i*)ctx.v40.s16))));
	// vmulfp128 v5,v12,v43
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v43.f32)));
	// vcsxwfp128 v22,v63,0
	simde_mm_store_ps(ctx.v22.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vmulfp128 v29,v12,v42
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v42.f32)));
	// vmaddfp v28,v11,v13,v5
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v5,v10,v9,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lvx128 v9,r5,r31
	ea = (ctx.r5.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v26,v11,v8,v29
	simde_mm_store_ps(ctx.v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v25,v10,v7,v29
	simde_mm_store_ps(ctx.v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmulfp128 v13,v9,v39
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v39.f32)));
	// vcsxwfp128 v21,v62,0
	simde_mm_store_ps(ctx.v21.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// lvx128 v7,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v29,v9,v32
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v32.f32)));
	// lvx128 v8,r5,r4
	ea = (ctx.r5.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v18,v7,v31,v13
	simde_mm_store_ps(ctx.v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v31.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// li r4,48
	ctx.r4.s64 = 48;
	// vmaddfp v1,v8,v1,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsubsws v20,v4,v6
	temp.s64 = int64_t(ctx.v4.s32[0]) - int64_t(ctx.v6.s32[0]);
	ctx.v20.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v4.s32[1]) - int64_t(ctx.v6.s32[1]);
	ctx.v20.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v4.s32[2]) - int64_t(ctx.v6.s32[2]);
	ctx.v20.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v4.s32[3]) - int64_t(ctx.v6.s32[3]);
	ctx.v20.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddfp128 v61,v23,v24
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v23.f32), simde_mm_load_ps(ctx.v24.f32)));
	// vor v31,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_load_si128((simde__m128i*)ctx.v27.u8));
	// vctsxs v26,v26,0
	simde_mm_store_si128((simde__m128i*)ctx.v26.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v26.f32)));
	// li r11,144
	ctx.r11.s64 = 144;
	// vctsxs v25,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v25.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v25.f32)));
	// li r31,160
	ctx.r31.s64 = 160;
	// lvx128 v6,r5,r4
	ea = (ctx.r5.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vctsxs v27,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v27.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v5.f32)));
	// vctsxs v28,v28,0
	simde_mm_store_si128((simde__m128i*)ctx.v28.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v28.f32)));
	// addi r4,r1,-48
	ctx.r4.s64 = ctx.r1.s64 + -48;
	// lvx128 v5,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-64
	ctx.r11.s64 = ctx.r1.s64 + -64;
	// lvx128 v4,r5,r31
	ea = (ctx.r5.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v57,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v5.u8));
	// vaddfp128 v60,v21,v22
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v21.f32), simde_mm_load_ps(ctx.v22.f32)));
	// vor128 v58,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v4.u8));
	// vmaddfp v17,v8,v2,v29
	simde_mm_store_ps(ctx.v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v16,v7,v3,v29
	simde_mm_store_ps(ctx.v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vor v29,v19,v19
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_load_si128((simde__m128i*)ctx.v19.u8));
	// vctsxs v2,v18,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v18.f32)));
	// vctsxs v13,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v1.f32)));
	// vmulfp128 v19,v6,v61
	simde_mm_store_ps(ctx.v19.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmulfp128 v18,v6,v60
	simde_mm_store_ps(ctx.v18.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vctsxs v3,v17,0
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v17.f32)));
	// vctsxs v1,v16,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v16.f32)));
	// vsubsws v17,v25,v2
	temp.s64 = int64_t(ctx.v25.s32[0]) - int64_t(ctx.v2.s32[0]);
	ctx.v17.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[1]) - int64_t(ctx.v2.s32[1]);
	ctx.v17.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[2]) - int64_t(ctx.v2.s32[2]);
	ctx.v17.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[3]) - int64_t(ctx.v2.s32[3]);
	ctx.v17.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v16,v26,v13
	temp.s64 = int64_t(ctx.v26.s32[0]) - int64_t(ctx.v13.s32[0]);
	ctx.v16.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v26.s32[1]) - int64_t(ctx.v13.s32[1]);
	ctx.v16.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v26.s32[2]) - int64_t(ctx.v13.s32[2]);
	ctx.v16.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v26.s32[3]) - int64_t(ctx.v13.s32[3]);
	ctx.v16.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmaddfp v24,v5,v24,v19
	simde_mm_store_ps(ctx.v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v24.f32)), simde_mm_load_ps(ctx.v19.f32)));
	// vaddsws v15,v26,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmaddfp v23,v4,v23,v19
	simde_mm_store_ps(ctx.v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v23.f32)), simde_mm_load_ps(ctx.v19.f32)));
	// vor v13,v16,v16
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v16.u8));
	// vmaddfp v22,v5,v22,v18
	simde_mm_store_ps(ctx.v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v22.f32)), simde_mm_load_ps(ctx.v18.f32)));
	// vsubsws v14,v28,v3
	temp.s64 = int64_t(ctx.v28.s32[0]) - int64_t(ctx.v3.s32[0]);
	ctx.v14.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v28.s32[1]) - int64_t(ctx.v3.s32[1]);
	ctx.v14.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v28.s32[2]) - int64_t(ctx.v3.s32[2]);
	ctx.v14.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v28.s32[3]) - int64_t(ctx.v3.s32[3]);
	ctx.v14.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmaddfp v21,v4,v21,v18
	simde_mm_store_ps(ctx.v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v21.f32)), simde_mm_load_ps(ctx.v18.f32)));
	// vsubsws v19,v27,v1
	temp.s64 = int64_t(ctx.v27.s32[0]) - int64_t(ctx.v1.s32[0]);
	ctx.v19.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[1]) - int64_t(ctx.v1.s32[1]);
	ctx.v19.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[2]) - int64_t(ctx.v1.s32[2]);
	ctx.v19.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[3]) - int64_t(ctx.v1.s32[3]);
	ctx.v19.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v26,v28,v3
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v28,v25,v2
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v2,v17,v17
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v17.u8));
	// vctsxs v24,v24,0
	simde_mm_store_si128((simde__m128i*)ctx.v24.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v24.f32)));
	// vaddsws v27,v27,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vctsxs v23,v23,0
	simde_mm_store_si128((simde__m128i*)ctx.v23.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v23.f32)));
	// vor v1,v19,v19
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v19.u8));
	// vor v3,v14,v14
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v14.u8));
	// vaddsws v17,v13,v2
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v13,v13,v2
	temp.s64 = int64_t(ctx.v13.s32[0]) - int64_t(ctx.v2.s32[0]);
	ctx.v13.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[1]) - int64_t(ctx.v2.s32[1]);
	ctx.v13.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[2]) - int64_t(ctx.v2.s32[2]);
	ctx.v13.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[3]) - int64_t(ctx.v2.s32[3]);
	ctx.v13.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vor v25,v15,v15
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_load_si128((simde__m128i*)ctx.v15.u8));
	// vaddsws v18,v3,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vctsxs v22,v22,0
	simde_mm_store_si128((simde__m128i*)ctx.v22.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v22.f32)));
	// vsubsws v3,v3,v1
	temp.s64 = int64_t(ctx.v3.s32[0]) - int64_t(ctx.v1.s32[0]);
	ctx.v3.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[1]) - int64_t(ctx.v1.s32[1]);
	ctx.v3.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[2]) - int64_t(ctx.v1.s32[2]);
	ctx.v3.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[3]) - int64_t(ctx.v1.s32[3]);
	ctx.v3.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vctsxs v21,v21,0
	simde_mm_store_si128((simde__m128i*)ctx.v21.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v21.f32)));
	// vor v1,v17,v17
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v17.u8));
	// vslw128 v15,v13,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vor v2,v18,v18
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v18.u8));
	// vslw128 v16,v13,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v19,v1,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v18,v1,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v14,v2,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v17,v2,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stvx128 v19,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddsws v4,v20,v24
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// stvx128 v18,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubsws v18,v20,v24
	temp.s64 = int64_t(ctx.v20.s32[0]) - int64_t(ctx.v24.s32[0]);
	ctx.v18.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v20.s32[1]) - int64_t(ctx.v24.s32[1]);
	ctx.v18.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v20.s32[2]) - int64_t(ctx.v24.s32[2]);
	ctx.v18.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v20.s32[3]) - int64_t(ctx.v24.s32[3]);
	ctx.v18.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v5,v30,v22
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v19,v30,v22
	temp.s64 = int64_t(ctx.v30.s32[0]) - int64_t(ctx.v22.s32[0]);
	ctx.v19.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v30.s32[1]) - int64_t(ctx.v22.s32[1]);
	ctx.v19.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v30.s32[2]) - int64_t(ctx.v22.s32[2]);
	ctx.v19.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v30.s32[3]) - int64_t(ctx.v22.s32[3]);
	ctx.v19.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v30,v17,v14
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// lvx128 v14,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddsws v20,v17,v14
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v16,v15,v16
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v24,v31,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v14,v3,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v15,v3,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vsubsws v31,v31,v21
	temp.s64 = int64_t(ctx.v31.s32[0]) - int64_t(ctx.v21.s32[0]);
	ctx.v31.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[1]) - int64_t(ctx.v21.s32[1]);
	ctx.v31.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[2]) - int64_t(ctx.v21.s32[2]);
	ctx.v31.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[3]) - int64_t(ctx.v21.s32[3]);
	ctx.v31.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v14,v15,v14
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// li r4,-16
	ctx.r4.s64 = -16;
	// vaddsws v21,v2,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v2,v16,v16
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v16.u8));
	// vaddsws v17,v1,v20
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v1,v14,v14
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v14.u8));
	// vslw128 v20,v20,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v16,v30,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v13,v13,v2
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v15,v2,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v2,v3,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v3,v1,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v30,v17,v20
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v14,v21,v16
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v1,v13,v15
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v20,v2,v3
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v16,v30,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v21,v14,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v17,v1,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v15,v20,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v3,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v5.u8));
	// vsraw128 v1,v21,v36
	ctx.v1.s32[0] = ctx.v21.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v1.s32[1] = ctx.v21.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v1.s32[2] = ctx.v21.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v1.s32[3] = ctx.v21.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v30,v16,v36
	ctx.v30.s32[0] = ctx.v16.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v30.s32[1] = ctx.v16.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v30.s32[2] = ctx.v16.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v30.s32[3] = ctx.v16.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v21,v17,v36
	ctx.v21.s32[0] = ctx.v17.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v21.s32[1] = ctx.v17.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v21.s32[2] = ctx.v17.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v21.s32[3] = ctx.v17.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vaddsws v22,v29,v23
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v13,v29,v23
	temp.s64 = int64_t(ctx.v29.s32[0]) - int64_t(ctx.v23.s32[0]);
	ctx.v13.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v29.s32[1]) - int64_t(ctx.v23.s32[1]);
	ctx.v13.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v29.s32[2]) - int64_t(ctx.v23.s32[2]);
	ctx.v13.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v29.s32[3]) - int64_t(ctx.v23.s32[3]);
	ctx.v13.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsraw128 v29,v15,v36
	ctx.v29.s32[0] = ctx.v15.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v29.s32[1] = ctx.v15.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v29.s32[2] = ctx.v15.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v29.s32[3] = ctx.v15.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vaddsws v23,v3,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v20,v31,v28
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v16,v3,v30
	temp.s64 = int64_t(ctx.v3.s32[0]) - int64_t(ctx.v30.s32[0]);
	ctx.v16.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[1]) - int64_t(ctx.v30.s32[1]);
	ctx.v16.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[2]) - int64_t(ctx.v30.s32[2]);
	ctx.v16.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[3]) - int64_t(ctx.v30.s32[3]);
	ctx.v16.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// lvx128 v3,r5,r4
	ea = (ctx.r5.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubsws v15,v31,v28
	temp.s64 = int64_t(ctx.v31.s32[0]) - int64_t(ctx.v28.s32[0]);
	ctx.v15.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[1]) - int64_t(ctx.v28.s32[1]);
	ctx.v15.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[2]) - int64_t(ctx.v28.s32[2]);
	ctx.v15.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v31.s32[3]) - int64_t(ctx.v28.s32[3]);
	ctx.v15.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v30,v19,v21
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v2,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v4.u8));
	// vaddsws v31,v24,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v21,v19,v21
	temp.s64 = int64_t(ctx.v19.s32[0]) - int64_t(ctx.v21.s32[0]);
	ctx.v21.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v19.s32[1]) - int64_t(ctx.v21.s32[1]);
	ctx.v21.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v19.s32[2]) - int64_t(ctx.v21.s32[2]);
	ctx.v21.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v19.s32[3]) - int64_t(ctx.v21.s32[3]);
	ctx.v21.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsraw128 v54,v20,v36
	ctx.v54.s32[0] = ctx.v20.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v54.s32[1] = ctx.v20.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v54.s32[2] = ctx.v20.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v54.s32[3] = ctx.v20.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v55,v23,v36
	ctx.v55.s32[0] = ctx.v23.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v55.s32[1] = ctx.v23.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v55.s32[2] = ctx.v23.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v55.s32[3] = ctx.v23.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v56,v31,v36
	ctx.v56.s32[0] = ctx.v31.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v56.s32[1] = ctx.v31.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v56.s32[2] = ctx.v31.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v56.s32[3] = ctx.v31.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v53,v30,v36
	ctx.v53.s32[0] = ctx.v30.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v53.s32[1] = ctx.v30.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v53.s32[2] = ctx.v30.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v53.s32[3] = ctx.v30.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vaddsws v14,v2,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v17,v13,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmrghw128 v49,v55,v54
	simde_mm_store_si128((simde__m128i*)ctx.v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vaddsws v19,v18,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmrglw128 v45,v55,v54
	simde_mm_store_si128((simde__m128i*)ctx.v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vsubsws v25,v24,v25
	temp.s64 = int64_t(ctx.v24.s32[0]) - int64_t(ctx.v25.s32[0]);
	ctx.v25.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v24.s32[1]) - int64_t(ctx.v25.s32[1]);
	ctx.v25.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v24.s32[2]) - int64_t(ctx.v25.s32[2]);
	ctx.v25.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v24.s32[3]) - int64_t(ctx.v25.s32[3]);
	ctx.v25.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmrghw128 v47,v56,v53
	simde_mm_store_si128((simde__m128i*)ctx.v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vaddsws v28,v22,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmrglw128 v43,v56,v53
	simde_mm_store_si128((simde__m128i*)ctx.v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vsraw128 v46,v21,v36
	ctx.v46.s32[0] = ctx.v21.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v46.s32[1] = ctx.v21.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v46.s32[2] = ctx.v21.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v46.s32[3] = ctx.v21.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v48,v19,v36
	ctx.v48.s32[0] = ctx.v19.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v48.s32[1] = ctx.v19.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v48.s32[2] = ctx.v19.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v48.s32[3] = ctx.v19.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsubsws v24,v2,v1
	temp.s64 = int64_t(ctx.v2.s32[0]) - int64_t(ctx.v1.s32[0]);
	ctx.v24.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v2.s32[1]) - int64_t(ctx.v1.s32[1]);
	ctx.v24.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v2.s32[2]) - int64_t(ctx.v1.s32[2]);
	ctx.v24.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v2.s32[3]) - int64_t(ctx.v1.s32[3]);
	ctx.v24.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmrghw128 v38,v47,v49
	simde_mm_store_si128((simde__m128i*)ctx.v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.u32), simde_mm_load_si128((simde__m128i*)ctx.v47.u32)));
	// vsraw128 v52,v28,v36
	ctx.v52.s32[0] = ctx.v28.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v52.s32[1] = ctx.v28.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v52.s32[2] = ctx.v28.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v52.s32[3] = ctx.v28.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vmrglw128 v37,v47,v49
	simde_mm_store_si128((simde__m128i*)ctx.v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.u32), simde_mm_load_si128((simde__m128i*)ctx.v47.u32)));
	// vsubsws v23,v13,v27
	temp.s64 = int64_t(ctx.v13.s32[0]) - int64_t(ctx.v27.s32[0]);
	ctx.v23.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[1]) - int64_t(ctx.v27.s32[1]);
	ctx.v23.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[2]) - int64_t(ctx.v27.s32[2]);
	ctx.v23.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[3]) - int64_t(ctx.v27.s32[3]);
	ctx.v23.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmrghw128 v60,v43,v45
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v45.u32), simde_mm_load_si128((simde__m128i*)ctx.v43.u32)));
	// vsubsws v20,v22,v26
	temp.s64 = int64_t(ctx.v22.s32[0]) - int64_t(ctx.v26.s32[0]);
	ctx.v20.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v22.s32[1]) - int64_t(ctx.v26.s32[1]);
	ctx.v20.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v22.s32[2]) - int64_t(ctx.v26.s32[2]);
	ctx.v20.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v22.s32[3]) - int64_t(ctx.v26.s32[3]);
	ctx.v20.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// lvx128 v13,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsraw128 v51,v14,v36
	ctx.v51.s32[0] = ctx.v14.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v51.s32[1] = ctx.v14.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v51.s32[2] = ctx.v14.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v51.s32[3] = ctx.v14.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v50,v17,v36
	ctx.v50.s32[0] = ctx.v17.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v50.s32[1] = ctx.v17.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v50.s32[2] = ctx.v17.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v50.s32[3] = ctx.v17.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vmrglw128 v39,v52,v48
	simde_mm_store_si128((simde__m128i*)ctx.v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v48.u32), simde_mm_load_si128((simde__m128i*)ctx.v52.u32)));
	// vsraw128 v44,v16,v36
	ctx.v44.s32[0] = ctx.v16.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v44.s32[1] = ctx.v16.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v44.s32[2] = ctx.v16.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v44.s32[3] = ctx.v16.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vcsxwfp128 v2,v37,0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v37.u32)));
	// vsraw128 v42,v15,v36
	ctx.v42.s32[0] = ctx.v15.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v42.s32[1] = ctx.v15.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v42.s32[2] = ctx.v15.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v42.s32[3] = ctx.v15.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vmrghw128 v48,v52,v48
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v48.u32), simde_mm_load_si128((simde__m128i*)ctx.v52.u32)));
	// vsraw128 v40,v25,v36
	ctx.v40.s32[0] = ctx.v25.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v40.s32[1] = ctx.v25.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v40.s32[2] = ctx.v25.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v40.s32[3] = ctx.v25.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsubsws v21,v18,v29
	temp.s64 = int64_t(ctx.v18.s32[0]) - int64_t(ctx.v29.s32[0]);
	ctx.v21.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v18.s32[1]) - int64_t(ctx.v29.s32[1]);
	ctx.v21.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v18.s32[2]) - int64_t(ctx.v29.s32[2]);
	ctx.v21.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v18.s32[3]) - int64_t(ctx.v29.s32[3]);
	ctx.v21.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vmrglw128 v41,v51,v50
	simde_mm_store_si128((simde__m128i*)ctx.v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.u32), simde_mm_load_si128((simde__m128i*)ctx.v51.u32)));
	// vsraw128 v54,v20,v36
	ctx.v54.s32[0] = ctx.v20.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v54.s32[1] = ctx.v20.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v54.s32[2] = ctx.v20.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v54.s32[3] = ctx.v20.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vcsxwfp128 v20,v60,0
	simde_mm_store_ps(ctx.v20.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vmrghw128 v32,v42,v44
	simde_mm_store_si128((simde__m128i*)ctx.v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v44.u32), simde_mm_load_si128((simde__m128i*)ctx.v42.u32)));
	// vsraw128 v63,v24,v36
	ctx.v63.s32[0] = ctx.v24.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v63.s32[1] = ctx.v24.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v63.s32[2] = ctx.v24.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v63.s32[3] = ctx.v24.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vmrghw128 v62,v46,v40
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), simde_mm_load_si128((simde__m128i*)ctx.v46.u32)));
	// vsraw128 v61,v23,v36
	ctx.v61.s32[0] = ctx.v23.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v61.s32[1] = ctx.v23.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v61.s32[2] = ctx.v23.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v61.s32[3] = ctx.v23.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v56,v21,v36
	ctx.v56.s32[0] = ctx.v21.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v56.s32[1] = ctx.v21.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v56.s32[2] = ctx.v21.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v56.s32[3] = ctx.v21.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vmrglw128 v55,v39,v41
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.u32), simde_mm_load_si128((simde__m128i*)ctx.v39.u32)));
	// vslw128 v19,v38,v36
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v38.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v36.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vmrglw128 v53,v32,v62
	simde_mm_store_si128((simde__m128i*)ctx.v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v32.u32)));
	// vmrglw128 v49,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrglw128 v47,v56,v54
	simde_mm_store_si128((simde__m128i*)ctx.v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vmrghw128 v38,v51,v50
	simde_mm_store_si128((simde__m128i*)ctx.v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.u32), simde_mm_load_si128((simde__m128i*)ctx.v51.u32)));
	// vcsxwfp128 v31,v55,0
	simde_mm_store_ps(ctx.v31.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vcsxwfp128 v1,v53,0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vmrglw128 v37,v42,v44
	simde_mm_store_si128((simde__m128i*)ctx.v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v44.u32), simde_mm_load_si128((simde__m128i*)ctx.v42.u32)));
	// vmrghw128 v53,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vaddsws v27,v19,v3
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmrglw128 v60,v46,v40
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), simde_mm_load_si128((simde__m128i*)ctx.v46.u32)));
	// vmrghw128 v52,v56,v54
	simde_mm_store_si128((simde__m128i*)ctx.v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vmrglw128 v55,v49,v47
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v47.u32), simde_mm_load_si128((simde__m128i*)ctx.v49.u32)));
	// vmrglw128 v51,v43,v45
	simde_mm_store_si128((simde__m128i*)ctx.v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v45.u32), simde_mm_load_si128((simde__m128i*)ctx.v43.u32)));
	// vmrglw128 v50,v48,v38
	simde_mm_store_si128((simde__m128i*)ctx.v50.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v38.u32), simde_mm_load_si128((simde__m128i*)ctx.v48.u32)));
	// vmrglw128 v46,v37,v60
	simde_mm_store_si128((simde__m128i*)ctx.v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v37.u32)));
	// vcsxwfp128 v29,v55,0
	simde_mm_store_ps(ctx.v29.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vmrglw128 v45,v53,v52
	simde_mm_store_si128((simde__m128i*)ctx.v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vcsxwfp128 v26,v51,0
	simde_mm_store_ps(ctx.v26.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v51.u32)));
	// vmrghw128 v44,v39,v41
	simde_mm_store_si128((simde__m128i*)ctx.v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.u32), simde_mm_load_si128((simde__m128i*)ctx.v39.u32)));
	// vcsxwfp128 v30,v50,0
	simde_mm_store_ps(ctx.v30.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v50.u32)));
	// vmrghw128 v41,v32,v62
	simde_mm_store_si128((simde__m128i*)ctx.v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v32.u32)));
	// vcsxwfp128 v24,v46,0
	simde_mm_store_ps(ctx.v24.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v46.u32)));
	// vmrghw128 v43,v37,v60
	simde_mm_store_si128((simde__m128i*)ctx.v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v37.u32)));
	// vcsxwfp128 v28,v45,0
	simde_mm_store_ps(ctx.v28.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v45.u32)));
	// vmrghw128 v42,v49,v47
	simde_mm_store_si128((simde__m128i*)ctx.v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v47.u32), simde_mm_load_si128((simde__m128i*)ctx.v49.u32)));
	// vcsxwfp128 v23,v44,0
	simde_mm_store_ps(ctx.v23.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v44.u32)));
	// vmrghw128 v40,v53,v52
	simde_mm_store_si128((simde__m128i*)ctx.v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vslw128 v16,v41,v36
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v41.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v36.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddfp v18,v2,v31
	simde_mm_store_ps(ctx.v18.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v31.f32)));
	// vcsxwfp128 v19,v43,0
	simde_mm_store_ps(ctx.v19.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v43.u32)));
	// vmrghw128 v39,v48,v38
	simde_mm_store_si128((simde__m128i*)ctx.v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v38.u32), simde_mm_load_si128((simde__m128i*)ctx.v48.u32)));
	// vcsxwfp128 v21,v42,0
	simde_mm_store_ps(ctx.v21.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v42.u32)));
	// vslw128 v22,v40,v36
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v40.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v36.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v3,v16,v3
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v25,v39,v36
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v39.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v36.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddfp v17,v1,v29
	simde_mm_store_ps(ctx.v17.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v29.f32)));
	// vaddfp v16,v30,v26
	simde_mm_store_ps(ctx.v16.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v26.f32)));
	// vsubsws v4,v3,v22
	temp.s64 = int64_t(ctx.v3.s32[0]) - int64_t(ctx.v22.s32[0]);
	ctx.v4.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[1]) - int64_t(ctx.v22.s32[1]);
	ctx.v4.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[2]) - int64_t(ctx.v22.s32[2]);
	ctx.v4.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[3]) - int64_t(ctx.v22.s32[3]);
	ctx.v4.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v3,v3,v22
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddfp v14,v28,v24
	simde_mm_store_ps(ctx.v14.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v24.f32)));
	// vsubsws v5,v27,v25
	temp.s64 = int64_t(ctx.v27.s32[0]) - int64_t(ctx.v25.s32[0]);
	ctx.v5.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[1]) - int64_t(ctx.v25.s32[1]);
	ctx.v5.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[2]) - int64_t(ctx.v25.s32[2]);
	ctx.v5.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[3]) - int64_t(ctx.v25.s32[3]);
	ctx.v5.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddfp v15,v20,v23
	simde_mm_store_ps(ctx.v15.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v20.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vaddsws v25,v27,v25
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vmaddfp v18,v12,v18,v13
	simde_mm_store_ps(ctx.v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v18.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vaddfp128 v63,v19,v21
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v19.f32), simde_mm_load_ps(ctx.v21.f32)));
	// vor v27,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_load_si128((simde__m128i*)ctx.v5.u8));
	// vor128 v5,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// vmaddfp v17,v12,v17,v13
	simde_mm_store_ps(ctx.v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v17.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor v12,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v4.u8));
	// vor128 v4,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vmaddfp v22,v9,v16,v13
	simde_mm_store_ps(ctx.v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v16.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v9,v9,v14,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v14.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v16,v6,v15,v13
	simde_mm_store_ps(ctx.v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v15.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp128 v13,v6,v63,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v63.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v6,v11,v2,v18
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v18.f32)));
	// vmaddfp v2,v10,v31,v18
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v31.f32)), simde_mm_load_ps(ctx.v18.f32)));
	// vmaddfp v11,v11,v1,v17
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v17.f32)));
	// vmaddfp v10,v10,v29,v17
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v29.f32)), simde_mm_load_ps(ctx.v17.f32)));
	// vmaddfp v1,v8,v30,v22
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v30.f32)), simde_mm_load_ps(ctx.v22.f32)));
	// vmaddfp v31,v7,v26,v22
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v26.f32)), simde_mm_load_ps(ctx.v22.f32)));
	// vmaddfp v8,v8,v28,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v9,v7,v24,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v24.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v7,v5,v23,v16
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v23.f32)), simde_mm_load_ps(ctx.v16.f32)));
	// vcfpsxws128 v38,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v38.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v6,v5,v21,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v21.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vcfpsxws128 v32,v2,0
	simde_mm_store_si128((simde__m128i*)ctx.v32.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vcfpsxws128 v37,v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v37.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v11.f32)));
	// vcfpsxws128 v63,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v10.f32)));
	// vcfpsxws128 v62,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v2,v4,v20,v16
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v20.f32)), simde_mm_load_ps(ctx.v16.f32)));
	// vcfpsxws128 v60,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v8.f32)));
	// vcfpsxws128 v58,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v4,v4,v19,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v19.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vcfpsxws128 v57,v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v7.f32)));
	// vcfpsxws128 v61,v31,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v31.f32)));
	// vsraw128 v13,v38,v59
	ctx.v13.s32[0] = ctx.v38.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v13.s32[1] = ctx.v38.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v13.s32[2] = ctx.v38.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v13.s32[3] = ctx.v38.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vcfpsxws128 v56,v6,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v6.f32)));
	// vsraw128 v11,v32,v59
	ctx.v11.s32[0] = ctx.v32.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v11.s32[1] = ctx.v32.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v11.s32[2] = ctx.v32.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v11.s32[3] = ctx.v32.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vsraw128 v10,v37,v59
	ctx.v10.s32[0] = ctx.v37.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v10.s32[1] = ctx.v37.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v10.s32[2] = ctx.v37.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v10.s32[3] = ctx.v37.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vsraw128 v9,v63,v59
	ctx.v9.s32[0] = ctx.v63.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v9.s32[1] = ctx.v63.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v9.s32[2] = ctx.v63.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v9.s32[3] = ctx.v63.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vsraw128 v8,v62,v59
	ctx.v8.s32[0] = ctx.v62.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v8.s32[1] = ctx.v62.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v8.s32[2] = ctx.v62.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v8.s32[3] = ctx.v62.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vcfpsxws128 v55,v2,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vsraw128 v7,v58,v59
	ctx.v7.s32[0] = ctx.v58.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v7.s32[1] = ctx.v58.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v7.s32[2] = ctx.v58.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v7.s32[3] = ctx.v58.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vsubsws v6,v13,v8
	temp.s64 = int64_t(ctx.v13.s32[0]) - int64_t(ctx.v8.s32[0]);
	ctx.v6.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[1]) - int64_t(ctx.v8.s32[1]);
	ctx.v6.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[2]) - int64_t(ctx.v8.s32[2]);
	ctx.v6.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[3]) - int64_t(ctx.v8.s32[3]);
	ctx.v6.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v5,v13,v8
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vcfpsxws128 v54,v4,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v4.f32)));
	// vsraw128 v13,v61,v59
	ctx.v13.s32[0] = ctx.v61.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v13.s32[1] = ctx.v61.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v13.s32[2] = ctx.v61.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v13.s32[3] = ctx.v61.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// li r11,96
	ctx.r11.s64 = 96;
	// vsraw128 v8,v60,v59
	ctx.v8.s32[0] = ctx.v60.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v8.s32[1] = ctx.v60.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v8.s32[2] = ctx.v60.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v8.s32[3] = ctx.v60.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// li r5,112
	ctx.r5.s64 = 112;
	// vsubsws v15,v9,v7
	temp.s64 = int64_t(ctx.v9.s32[0]) - int64_t(ctx.v7.s32[0]);
	ctx.v15.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[1]) - int64_t(ctx.v7.s32[1]);
	ctx.v15.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[2]) - int64_t(ctx.v7.s32[2]);
	ctx.v15.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[3]) - int64_t(ctx.v7.s32[3]);
	ctx.v15.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v7,v9,v7
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v14,v11,v13
	temp.s64 = int64_t(ctx.v11.s32[0]) - int64_t(ctx.v13.s32[0]);
	ctx.v14.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[1]) - int64_t(ctx.v13.s32[1]);
	ctx.v14.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[2]) - int64_t(ctx.v13.s32[2]);
	ctx.v14.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[3]) - int64_t(ctx.v13.s32[3]);
	ctx.v14.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v2,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v13,v10,v8
	temp.s64 = int64_t(ctx.v10.s32[0]) - int64_t(ctx.v8.s32[0]);
	ctx.v13.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[1]) - int64_t(ctx.v8.s32[1]);
	ctx.v13.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[2]) - int64_t(ctx.v8.s32[2]);
	ctx.v13.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[3]) - int64_t(ctx.v8.s32[3]);
	ctx.v13.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v4,v10,v8
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v8,v15,v15
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v15.u8));
	// vor v11,v14,v14
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v14.u8));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vsraw128 v10,v56,v59
	ctx.v10.s32[0] = ctx.v56.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v10.s32[1] = ctx.v56.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v10.s32[2] = ctx.v56.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v10.s32[3] = ctx.v56.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vsraw128 v13,v57,v59
	ctx.v13.s32[0] = ctx.v57.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v13.s32[1] = ctx.v57.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v13.s32[2] = ctx.v57.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v13.s32[3] = ctx.v57.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vaddsws v30,v6,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v31,v9,v8
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v11,v6,v11
	temp.s64 = int64_t(ctx.v6.s32[0]) - int64_t(ctx.v11.s32[0]);
	ctx.v11.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[1]) - int64_t(ctx.v11.s32[1]);
	ctx.v11.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[2]) - int64_t(ctx.v11.s32[2]);
	ctx.v11.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[3]) - int64_t(ctx.v11.s32[3]);
	ctx.v11.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v6,v12,v10
	temp.s64 = int64_t(ctx.v12.s32[0]) - int64_t(ctx.v10.s32[0]);
	ctx.v6.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[1]) - int64_t(ctx.v10.s32[1]);
	ctx.v6.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[2]) - int64_t(ctx.v10.s32[2]);
	ctx.v6.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[3]) - int64_t(ctx.v10.s32[3]);
	ctx.v6.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v29,v12,v10
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v12,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v31.u8));
	// vsubsws v1,v27,v13
	temp.s64 = int64_t(ctx.v27.s32[0]) - int64_t(ctx.v13.s32[0]);
	ctx.v1.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[1]) - int64_t(ctx.v13.s32[1]);
	ctx.v1.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[2]) - int64_t(ctx.v13.s32[2]);
	ctx.v1.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v27.s32[3]) - int64_t(ctx.v13.s32[3]);
	ctx.v1.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vaddsws v28,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v13,v30,v30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v30.u8));
	// vslw128 v24,v12,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v23,v12,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vsubsws v10,v9,v8
	temp.s64 = int64_t(ctx.v9.s32[0]) - int64_t(ctx.v8.s32[0]);
	ctx.v10.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[1]) - int64_t(ctx.v8.s32[1]);
	ctx.v10.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[2]) - int64_t(ctx.v8.s32[2]);
	ctx.v10.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[3]) - int64_t(ctx.v8.s32[3]);
	ctx.v10.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vslw128 v26,v13,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v22,v13,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v27,v11,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v21,v11,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v8,v23,v24
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v9,v22,v26
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v20,v10,v33
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v33.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v19,v10,v34
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v34.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v18,v21,v27
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v30,v12,v8
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v31,v13,v9
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v17,v9,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v12,v19,v20
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vor v9,v18,v18
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v18.u8));
	// vslw128 v16,v8,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v15,v31,v17
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v10,v10,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v14,v12,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v11,v11,v9
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vslw128 v12,v9,v59
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v59.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vaddsws v9,v30,v16
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsraw128 v13,v55,v59
	ctx.v13.s32[0] = ctx.v55.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v13.s32[1] = ctx.v55.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v13.s32[2] = ctx.v55.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v13.s32[3] = ctx.v55.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vaddsws v8,v10,v14
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v31,v11,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsraw128 v12,v54,v59
	ctx.v12.s32[0] = ctx.v54.s32[0] >> (ctx.v59.u8[0] & 0x1F);
	ctx.v12.s32[1] = ctx.v54.s32[1] >> (ctx.v59.u8[4] & 0x1F);
	ctx.v12.s32[2] = ctx.v54.s32[2] >> (ctx.v59.u8[8] & 0x1F);
	ctx.v12.s32[3] = ctx.v54.s32[3] >> (ctx.v59.u8[12] & 0x1F);
	// vaddsws v26,v9,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v23,v8,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v27,v15,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v10,v3,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v24,v31,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v11,v25,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsubsws v0,v25,v13
	temp.s64 = int64_t(ctx.v25.s32[0]) - int64_t(ctx.v13.s32[0]);
	ctx.v0.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[1]) - int64_t(ctx.v13.s32[1]);
	ctx.v0.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[2]) - int64_t(ctx.v13.s32[2]);
	ctx.v0.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v25.s32[3]) - int64_t(ctx.v13.s32[3]);
	ctx.v0.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v13,v3,v12
	temp.s64 = int64_t(ctx.v3.s32[0]) - int64_t(ctx.v12.s32[0]);
	ctx.v13.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[1]) - int64_t(ctx.v12.s32[1]);
	ctx.v13.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[2]) - int64_t(ctx.v12.s32[2]);
	ctx.v13.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v3.s32[3]) - int64_t(ctx.v12.s32[3]);
	ctx.v13.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsraw128 v31,v24,v36
	ctx.v31.s32[0] = ctx.v24.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v31.s32[1] = ctx.v24.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v31.s32[2] = ctx.v24.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v31.s32[3] = ctx.v24.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v30,v23,v36
	ctx.v30.s32[0] = ctx.v23.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v30.s32[1] = ctx.v23.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v30.s32[2] = ctx.v23.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v30.s32[3] = ctx.v23.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vor v12,v28,v28
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v28.u8));
	// vor v9,v29,v29
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v29.u8));
	// vsraw128 v8,v27,v36
	ctx.v8.s32[0] = ctx.v27.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v8.s32[1] = ctx.v27.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v8.s32[2] = ctx.v27.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v8.s32[3] = ctx.v27.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vsraw128 v3,v26,v36
	ctx.v3.s32[0] = ctx.v26.s32[0] >> (ctx.v36.u8[0] & 0x1F);
	ctx.v3.s32[1] = ctx.v26.s32[1] >> (ctx.v36.u8[4] & 0x1F);
	ctx.v3.s32[2] = ctx.v26.s32[2] >> (ctx.v36.u8[8] & 0x1F);
	ctx.v3.s32[3] = ctx.v26.s32[3] >> (ctx.v36.u8[12] & 0x1F);
	// vaddsws v22,v10,v4
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v21,v11,v5
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v20,v12,v8
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v19,v9,v3
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v18,v1,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vaddsws v17,v6,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vsraw128 v53,v22,v35
	ctx.v53.s32[0] = ctx.v22.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v53.s32[1] = ctx.v22.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v53.s32[2] = ctx.v22.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v53.s32[3] = ctx.v22.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v52,v21,v35
	ctx.v52.s32[0] = ctx.v21.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v52.s32[1] = ctx.v21.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v52.s32[2] = ctx.v21.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v52.s32[3] = ctx.v21.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v51,v19,v35
	ctx.v51.s32[0] = ctx.v19.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v51.s32[1] = ctx.v19.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v51.s32[2] = ctx.v19.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v51.s32[3] = ctx.v19.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v50,v20,v35
	ctx.v50.s32[0] = ctx.v20.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v50.s32[1] = ctx.v20.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v50.s32[2] = ctx.v20.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v50.s32[3] = ctx.v20.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v49,v17,v35
	ctx.v49.s32[0] = ctx.v17.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v49.s32[1] = ctx.v17.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v49.s32[2] = ctx.v17.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v49.s32[3] = ctx.v17.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v48,v18,v35
	ctx.v48.s32[0] = ctx.v18.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v48.s32[1] = ctx.v18.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v48.s32[2] = ctx.v18.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v48.s32[3] = ctx.v18.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vpkswss128 v47,v52,v53
	simde_mm_store_si128((simde__m128i*)ctx.v47.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.s32), simde_mm_load_si128((simde__m128i*)ctx.v52.s32)));
	// vaddsws v16,v13,v7
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// vpkswss128 v46,v50,v51
	simde_mm_store_si128((simde__m128i*)ctx.v46.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.s32), simde_mm_load_si128((simde__m128i*)ctx.v50.s32)));
	// vsubsws v14,v13,v7
	temp.s64 = int64_t(ctx.v13.s32[0]) - int64_t(ctx.v7.s32[0]);
	ctx.v14.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[1]) - int64_t(ctx.v7.s32[1]);
	ctx.v14.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[2]) - int64_t(ctx.v7.s32[2]);
	ctx.v14.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v13.s32[3]) - int64_t(ctx.v7.s32[3]);
	ctx.v14.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vpkswss128 v45,v48,v49
	simde_mm_store_si128((simde__m128i*)ctx.v45.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.s32), simde_mm_load_si128((simde__m128i*)ctx.v48.s32)));
	// vaddsws v15,v0,v2
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i sum = simde_mm_add_epi32(a, b);
		simde__m128i overflow = simde_mm_and_si128(simde_mm_xor_si128(a, sum), simde_mm_xor_si128(b, sum));
		simde__m128i sat_val = simde_mm_xor_si128(simde_mm_srai_epi32(a, 31), simde_mm_set1_epi32(0x7FFFFFFF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_castps_si128(simde_mm_blendv_ps(simde_mm_castsi128_ps(sum), simde_mm_castsi128_ps(sat_val), simde_mm_castsi128_ps(overflow))));
	}
	// stvx128 v47,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubsws v13,v6,v30
	temp.s64 = int64_t(ctx.v6.s32[0]) - int64_t(ctx.v30.s32[0]);
	ctx.v13.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[1]) - int64_t(ctx.v30.s32[1]);
	ctx.v13.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[2]) - int64_t(ctx.v30.s32[2]);
	ctx.v13.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v6.s32[3]) - int64_t(ctx.v30.s32[3]);
	ctx.v13.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v0,v0,v2
	temp.s64 = int64_t(ctx.v0.s32[0]) - int64_t(ctx.v2.s32[0]);
	ctx.v0.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v0.s32[1]) - int64_t(ctx.v2.s32[1]);
	ctx.v0.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v0.s32[2]) - int64_t(ctx.v2.s32[2]);
	ctx.v0.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v0.s32[3]) - int64_t(ctx.v2.s32[3]);
	ctx.v0.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v7,v1,v31
	temp.s64 = int64_t(ctx.v1.s32[0]) - int64_t(ctx.v31.s32[0]);
	ctx.v7.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v1.s32[1]) - int64_t(ctx.v31.s32[1]);
	ctx.v7.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v1.s32[2]) - int64_t(ctx.v31.s32[2]);
	ctx.v7.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v1.s32[3]) - int64_t(ctx.v31.s32[3]);
	ctx.v7.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v6,v9,v3
	temp.s64 = int64_t(ctx.v9.s32[0]) - int64_t(ctx.v3.s32[0]);
	ctx.v6.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[1]) - int64_t(ctx.v3.s32[1]);
	ctx.v6.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[2]) - int64_t(ctx.v3.s32[2]);
	ctx.v6.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v9.s32[3]) - int64_t(ctx.v3.s32[3]);
	ctx.v6.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsubsws v3,v12,v8
	temp.s64 = int64_t(ctx.v12.s32[0]) - int64_t(ctx.v8.s32[0]);
	ctx.v3.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[1]) - int64_t(ctx.v8.s32[1]);
	ctx.v3.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[2]) - int64_t(ctx.v8.s32[2]);
	ctx.v3.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v12.s32[3]) - int64_t(ctx.v8.s32[3]);
	ctx.v3.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// stvx128 v46,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubsws v2,v10,v4
	temp.s64 = int64_t(ctx.v10.s32[0]) - int64_t(ctx.v4.s32[0]);
	ctx.v2.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[1]) - int64_t(ctx.v4.s32[1]);
	ctx.v2.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[2]) - int64_t(ctx.v4.s32[2]);
	ctx.v2.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v10.s32[3]) - int64_t(ctx.v4.s32[3]);
	ctx.v2.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// stvx128 v45,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubsws v1,v11,v5
	temp.s64 = int64_t(ctx.v11.s32[0]) - int64_t(ctx.v5.s32[0]);
	ctx.v1.s32[0] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[1]) - int64_t(ctx.v5.s32[1]);
	ctx.v1.s32[1] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[2]) - int64_t(ctx.v5.s32[2]);
	ctx.v1.s32[2] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	temp.s64 = int64_t(ctx.v11.s32[3]) - int64_t(ctx.v5.s32[3]);
	ctx.v1.s32[3] = temp.s64 > INT_MAX ? INT_MAX : temp.s64 < INT_MIN ? INT_MIN : temp.s64;
	// vsraw128 v44,v16,v35
	ctx.v44.s32[0] = ctx.v16.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v44.s32[1] = ctx.v16.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v44.s32[2] = ctx.v16.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v44.s32[3] = ctx.v16.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v43,v15,v35
	ctx.v43.s32[0] = ctx.v15.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v43.s32[1] = ctx.v15.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v43.s32[2] = ctx.v15.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v43.s32[3] = ctx.v15.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v42,v14,v35
	ctx.v42.s32[0] = ctx.v14.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v42.s32[1] = ctx.v14.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v42.s32[2] = ctx.v14.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v42.s32[3] = ctx.v14.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v41,v0,v35
	ctx.v41.s32[0] = ctx.v0.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v41.s32[1] = ctx.v0.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v41.s32[2] = ctx.v0.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v41.s32[3] = ctx.v0.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v40,v13,v35
	ctx.v40.s32[0] = ctx.v13.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v40.s32[1] = ctx.v13.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v40.s32[2] = ctx.v13.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v40.s32[3] = ctx.v13.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v39,v7,v35
	ctx.v39.s32[0] = ctx.v7.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v39.s32[1] = ctx.v7.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v39.s32[2] = ctx.v7.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v39.s32[3] = ctx.v7.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vpkswss128 v38,v43,v44
	simde_mm_store_si128((simde__m128i*)ctx.v38.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v44.s32), simde_mm_load_si128((simde__m128i*)ctx.v43.s32)));
	// vsraw128 v37,v6,v35
	ctx.v37.s32[0] = ctx.v6.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v37.s32[1] = ctx.v6.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v37.s32[2] = ctx.v6.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v37.s32[3] = ctx.v6.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v36,v3,v35
	ctx.v36.s32[0] = ctx.v3.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v36.s32[1] = ctx.v3.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v36.s32[2] = ctx.v3.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v36.s32[3] = ctx.v3.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vpkswss128 v34,v41,v42
	simde_mm_store_si128((simde__m128i*)ctx.v34.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v42.s32), simde_mm_load_si128((simde__m128i*)ctx.v41.s32)));
	// vsraw128 v33,v2,v35
	ctx.v33.s32[0] = ctx.v2.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v33.s32[1] = ctx.v2.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v33.s32[2] = ctx.v2.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v33.s32[3] = ctx.v2.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vsraw128 v32,v1,v35
	ctx.v32.s32[0] = ctx.v1.s32[0] >> (ctx.v35.u8[0] & 0x1F);
	ctx.v32.s32[1] = ctx.v1.s32[1] >> (ctx.v35.u8[4] & 0x1F);
	ctx.v32.s32[2] = ctx.v1.s32[2] >> (ctx.v35.u8[8] & 0x1F);
	ctx.v32.s32[3] = ctx.v1.s32[3] >> (ctx.v35.u8[12] & 0x1F);
	// vpkswss128 v63,v39,v40
	simde_mm_store_si128((simde__m128i*)ctx.v63.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.s32), simde_mm_load_si128((simde__m128i*)ctx.v39.s32)));
	// vpkswss128 v62,v36,v37
	simde_mm_store_si128((simde__m128i*)ctx.v62.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v37.s32), simde_mm_load_si128((simde__m128i*)ctx.v36.s32)));
	// stvx128 v38,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkswss128 v61,v32,v33
	simde_mm_store_si128((simde__m128i*)ctx.v61.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v33.s32), simde_mm_load_si128((simde__m128i*)ctx.v32.s32)));
	// stvx128 v34,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r5
	ea = (ctx.r3.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82789D78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82789D80;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x82775990
	ctx.lr = 0x82789D9C;
	sub_82775990(ctx, base);
	// addi r28,r31,172
	ctx.r28.s64 = ctx.r31.s64 + 172;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x82789DA8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,168(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// addi r11,r30,168
	ctx.r11.s64 = ctx.r30.s64 + 168;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82789dec
	if (ctx.cr6.eq) goto loc_82789DEC;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// bl 0x8278f860
	ctx.lr = 0x82789DE4;
	sub_8278F860(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82789df8
	goto loc_82789DF8;
loc_82789DEC:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r31,1
	ctx.r31.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82789DF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x82789E00;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278C398) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8278C3A0;
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
	// beq 0x8278c490
	if (ctx.cr0.eq) goto loc_8278C490;
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
	// beq 0x8278c480
	if (ctx.cr0.eq) goto loc_8278C480;
	// addi r29,r4,66
	ctx.r29.s64 = ctx.r4.s64 + 66;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8278C3E8:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// rlwinm. r27,r11,0,27,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// beq 0x8278c410
	if (ctx.cr0.eq) goto loc_8278C410;
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
	// b 0x8278c424
	goto loc_8278C424;
loc_8278C410:
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
loc_8278C424:
	// bgt cr6,0x8278c438
	if (ctx.cr6.gt) goto loc_8278C438;
	// rlwinm. r11,r5,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8278c438
	if (!ctx.cr0.eq) goto loc_8278C438;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8278C438:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// bdnz 0x8278c3e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8278C3E8;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8278c480
	if (!ctx.cr6.eq) goto loc_8278C480;
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
	// beq cr6,0x8278c500
	if (ctx.cr6.eq) goto loc_8278C500;
	// lwz r11,672(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 672);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,672(r28)
	REX_STORE_U32(ctx.r28.u32 + 672, ctx.r11.u32);
	// b 0x8278c500
	goto loc_8278C500;
loc_8278C480:
	// ld r11,816(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 816);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// b 0x8278c494
	goto loc_8278C494;
loc_8278C490:
	// lhz r8,12(r5)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r5.u32 + 12);
loc_8278C494:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8278c160
	ctx.lr = 0x8278C49C;
	sub_8278C160(ctx, base);
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
	// blt cr6,0x8278c4bc
	if (ctx.cr6.lt) goto loc_8278C4BC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8278c500
	goto loc_8278C500;
loc_8278C4BC:
	// lwz r10,1188(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 1188);
	// rlwinm. r9,r10,0,13,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8278c4dc
	if (ctx.cr0.eq) goto loc_8278C4DC;
	// lhz r9,1094(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + 1094);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x8278c4e8
	if (ctx.cr6.lt) goto loc_8278C4E8;
loc_8278C4DC:
	// oris r11,r10,4
	ctx.r11.u64 = ctx.r10.u64 | 262144;
	// sth r8,1094(r28)
	REX_STORE_U16(ctx.r28.u32 + 1094, ctx.r8.u16);
	// stw r11,1188(r28)
	REX_STORE_U32(ctx.r28.u32 + 1188, ctx.r11.u32);
loc_8278C4E8:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8278c4fc
	if (ctx.cr6.eq) goto loc_8278C4FC;
	// lwz r11,672(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 672);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,672(r28)
	REX_STORE_U32(ctx.r28.u32 + 672, ctx.r11.u32);
loc_8278C4FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8278C500:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82795830) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82795838;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82772048
	ctx.lr = 0x82795850;
	sub_82772048(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82795860
	if (!ctx.cr0.eq) goto loc_82795860;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827958b4
	goto loc_827958B4;
loc_82795860:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a030
	ctx.lr = 0x82795874;
	sub_8273A030(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8279588c
	if (ctx.cr6.eq) goto loc_8279588C;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82772060
	ctx.lr = 0x8279588C;
	sub_82772060(ctx, base);
loc_8279588C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r10.u64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a590
	ctx.lr = 0x827958A8;
	sub_8273A590(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
loc_827958B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82798508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82798510;
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
	// beq cr6,0x82798664
	if (ctx.cr6.eq) goto loc_82798664;
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
loc_82798564:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8279857c
	if (ctx.cr6.eq) goto loc_8279857C;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
	// bne 0x82798580
	if (!ctx.cr0.eq) goto loc_82798580;
loc_8279857C:
	// li r27,0
	ctx.r27.s64 = 0;
loc_82798580:
	// lbz r11,72(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 72);
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// beq cr6,0x82798594
	if (ctx.cr6.eq) goto loc_82798594;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82798658
	if (!ctx.cr6.eq) goto loc_82798658;
loc_82798594:
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
	// bl 0x82797b88
	ctx.lr = 0x827985B4;
	sub_82797B88(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82798658
	if (ctx.cr0.eq) goto loc_82798658;
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82798658
	if (!ctx.cr0.eq) goto loc_82798658;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8279863c
	if (ctx.cr6.eq) goto loc_8279863C;
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827985e0
	if (ctx.cr0.eq) goto loc_827985E0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8279b7b0
	ctx.lr = 0x827985E0;
	sub_8279B7B0(ctx, base);
loc_827985E0:
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// rlwinm. r11,r11,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279863c
	if (ctx.cr0.eq) goto loc_8279863C;
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// addi r9,r31,172
	ctx.r9.s64 = ctx.r31.s64 + 172;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82798630
	if (ctx.cr6.eq) goto loc_82798630;
loc_827985FC:
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8279861c
	if (!ctx.cr6.eq) goto loc_8279861C;
	// stw r27,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r27.u32);
	// lhz r10,76(r27)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r27.u32 + 76);
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// sth r10,76(r27)
	REX_STORE_U16(ctx.r27.u32 + 76, ctx.r10.u16);
loc_8279861C:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82798630
	if (ctx.cr6.eq) goto loc_82798630;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x827985fc
	if (!ctx.cr0.eq) goto loc_827985FC;
loc_82798630:
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// andi. r11,r11,65279
	ctx.r11.u64 = ctx.r11.u64 & 65279;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r11,76(r29)
	REX_STORE_U16(ctx.r29.u32 + 76, ctx.r11.u16);
loc_8279863C:
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
	// bl 0x8279aa50
	ctx.lr = 0x82798658;
	sub_8279AA50(ctx, base);
loc_82798658:
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x82798564
	if (!ctx.cr6.eq) goto loc_82798564;
loc_82798664:
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
	// beq cr6,0x82798690
	if (ctx.cr6.eq) goto loc_82798690;
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_82798690:
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x827986a4
	if (ctx.cr6.eq) goto loc_827986A4;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r11.u32);
loc_827986A4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A5630) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x827a5658
	if (!ctx.cr6.eq) goto loc_827A5658;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827a5760
	goto loc_827A5760;
loc_827A5658:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// lwz r11,-27584(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -27584);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27580(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27580);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27576);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27572(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27572);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27568(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27568);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27564(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27564);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a575c
	if (ctx.cr6.eq) goto loc_827A575C;
	// lwz r11,-27584(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -27584);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A56D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827a56e4
	if (!ctx.cr0.eq) goto loc_827A56E4;
loc_827A56DC:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x827a5760
	goto loc_827A5760;
loc_827A56E4:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// stb r9,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r9.u8);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bl 0x827a6770
	ctx.lr = 0x827A5704;
	sub_827A6770(ctx, base);
	// clrlwi. r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827a5718
	if (ctx.cr0.eq) goto loc_827A5718;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827a5570
	ctx.lr = 0x827A5714;
	sub_827A5570(ctx, base);
	// b 0x827a56dc
	goto loc_827A56DC;
loc_827A5718:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// addi r30,r10,-27624
	ctx.r30.s64 = ctx.r10.s64 + -27624;
	// ori r11,r11,51712
	ctx.r11.u64 = ctx.r11.u64 | 51712;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// std r31,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r31.u64);
	// std r31,8(r30)
	REX_STORE_U64(ctx.r30.u32 + 8, ctx.r31.u64);
	// std r31,16(r30)
	REX_STORE_U64(ctx.r30.u32 + 16, ctx.r31.u64);
	// std r31,24(r30)
	REX_STORE_U64(ctx.r30.u32 + 24, ctx.r31.u64);
	// std r31,32(r30)
	REX_STORE_U64(ctx.r30.u32 + 32, ctx.r31.u64);
	// std r11,-27624(r10)
	REX_STORE_U64(ctx.r10.u32 + -27624, ctx.r11.u64);
	// bl 0x827484f0
	ctx.lr = 0x827A574C;
	sub_827484F0(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// b 0x827a5760
	goto loc_827A5760;
loc_827A575C:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_827A5760:
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

DEFINE_REX_FUNC(sub_827ACF80) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10600);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD928) {
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
	// lfs f0,22248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE0E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
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
	// stfs f0,-10016(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE650) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AEEA8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9704(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9704);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9588(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFB98) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1348) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1FF0) {
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
	// lfs f0,23288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8236);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8120(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7700(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3C00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7292);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7288(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B42B8) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7180(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7180);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B54D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,24072
	ctx.r9.s64 = ctx.r11.s64 + 24072;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6156(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B72F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,24248
	ctx.r9.s64 = ctx.r11.s64 + 24248;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8758) {
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
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5088(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5088, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9700) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4632(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA8C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4104(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDF78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-2476(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BED38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2072(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BFC58) {
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
	// lfs f13,-1724(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1724);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1B78) {
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
	// lfs f0,26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2C78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3BB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27244);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,244(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C49E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,680(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5A40) {
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
	// lfs f0,27736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1088(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1088);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6B70) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1624(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1624);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8D20) {
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
	// lfs f0,28648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2596(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2596);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2708(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA060) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3148(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3148);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3268(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,29032
	ctx.r9.s64 = ctx.r11.s64 + 29032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC758) {
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
	// lfs f0,29224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4312);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD8C0) {
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
	// lfs f0,29416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEAF8) {
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
	// lfs f0,29608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5408(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5408);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5468(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFD88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0E78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1BD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2AC0) {
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
	// lfs f0,30248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3D38) {
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
	// lfs f12,7808(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7808);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4FB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D60A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7D18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,9724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9724);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9728(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 9728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D86C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9488) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,10796(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10796);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC1E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD208) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF3C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13164);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14088(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14088, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E21B8) {
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
	// lfs f0,14564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14564);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32568);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,14588(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 14588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3BE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4BC8) {
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
	// lfs f0,-32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15664);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6098) {
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
	// lfs f0,-30648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16384(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7288) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-28568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16884(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8260) {
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
	// lfs f0,-26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9738) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-24008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17908(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA520) {
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
	// lfs f0,18272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -23624);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,18288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB970) {
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
	// lfs f12,18756(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18756);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18864(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECE30) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19280);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19980(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEF90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-19900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19900);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20348(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EFBA8) {
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
	// lfs f0,-19592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20684(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0DE0) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,21188
	ctx.r6.s64 = ctx.r8.s64 + 21188;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,21188(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21188);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,21188(r8)
	REX_STORE_U32(ctx.r8.u32 + 21188, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,21188(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21188);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,21188(r8)
	REX_STORE_U32(ctx.r8.u32 + 21188, ctx.r11.u32);
	// stb r9,21188(r8)
	REX_STORE_U8(ctx.r8.u32 + 21188, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2570) {
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
	// lfs f0,-18016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18016);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21828(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21828);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,21848(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 21848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4020) {
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
	// lfs f0,22560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22560);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16808(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16808);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,22584(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 22584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5D68) {
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
	// lfs f0,-15896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7178) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8160) {
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
	// lfs f0,-13736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24508(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24508);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA4B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB268) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26016(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC1A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-9496
	ctx.r9.s64 = ctx.r11.s64 + -9496;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,26932(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26932);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF268) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27884(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828020E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,29236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29240(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802A88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828038E8) {
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
	// lfs f0,-8280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29872(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29872);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29940(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804C90) {
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
	// lfs f0,-8088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30424(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30424);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30512(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-7896
	ctx.r9.s64 = ctx.r11.s64 + -7896;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31084(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828073F8) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828087A8) {
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
	// lfs f0,-7512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A988) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B8D0) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CBE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-6744
	ctx.r9.s64 = ctx.r11.s64 + -6744;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DF20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280EFE0) {
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
	// lfs f0,-6304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30308(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30308);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828102B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29688(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828110C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-5848
	ctx.r9.s64 = ctx.r11.s64 + -5848;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-5848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812580) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28072(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815890) {
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
	// lfs f0,-4680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816B70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818A40) {
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
	// lfs f0,-3816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25656);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25600(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819D88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-3512
	ctx.r9.s64 = ctx.r11.s64 + -3512;
	// lfs f0,-3512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25028(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -25028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281ACD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-24672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24672);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BD08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24088(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24088, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CE08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23580(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DC38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23196(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -23196);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281ED58) {
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
	// lfs f0,-2280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FF08) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22204(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22204);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828212B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822348) {
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
	// lfs f0,-1640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828236E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20476(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824838) {
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
	// lfs f0,-1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20052);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -752);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,-19404(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -19404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828267D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19016(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-18640(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18640);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828284B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-18176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-18172(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -18172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828F88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A148) {
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
	// lfs f0,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17332(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B388) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C470) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D6E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,952
	ctx.r9.s64 = ctx.r11.s64 + 952;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15260(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FAD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,1160
	ctx.r9.s64 = ctx.r11.s64 + 1160;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,1412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1412);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-14124(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -14124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828326B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828336C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834630) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12444(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828356D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-11952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11952);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-11948(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837120) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828382D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839110) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10240(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839F80) {
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
	// lfs f12,-9880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9880);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9816(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B348) {
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
	// lfs f0,3552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9312);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C778) {
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
	// lfs f0,3776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DB78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,4016
	ctx.r9.s64 = ctx.r11.s64 + 4016;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EF98) {
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
	// lfs f13,-7588(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7588);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FE78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7036);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7032(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842CF0) {
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
	// lfs f0,5072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5672(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5096(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846000) {
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
	// lfs f0,5744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4152(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828483E8) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3160);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3088(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3088, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849888) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,6416
	ctx.r9.s64 = ctx.r11.s64 + 6416;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2488(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284AD38) {
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
	// lfs f0,6640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1984(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1984);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C1D8) {
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
	// lfs f0,6864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1396(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1396);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D560) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-716(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F7E0) {
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
	// lfs f0,7720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,340(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850A90) {
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
	// lfs f0,8136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 856);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1476(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853EF0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// addi r3,r9,21872
	ctx.r3.s64 = ctx.r9.s64 + 21872;
	// stw r10,2500(r11)
	REX_STORE_U32(ctx.r11.u32 + 2500, ctx.r10.u32);
	// b 0x827387e8
	sub_827387E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8285558C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8285BAD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x8285BAD8;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,29(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 29);
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lbz r24,34(r3)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r3.u32 + 34);
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lbz r16,5(r4)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r4.u32 + 5);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r21,r17
	ctx.r21.u64 = ctx.r17.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// rlwinm r20,r10,12,30,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8285bb14
	if (ctx.cr6.eq) goto loc_8285BB14;
	// rlwinm r24,r10,8,29,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x7;
loc_8285BB14:
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r18,r17
	ctx.r18.u64 = ctx.r17.u64;
	// ori r22,r11,32768
	ctx.r22.u64 = ctx.r11.u64 | 32768;
loc_8285BB20:
	// clrlwi r11,r16,31
	ctx.r11.u64 = ctx.r16.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8285bf3c
	if (ctx.cr6.eq) goto loc_8285BF3C;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8285bc90
	if (ctx.cr6.eq) goto loc_8285BC90;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x8285bc90
	if (!ctx.cr6.eq) goto loc_8285BC90;
	// lwz r10,608(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 608);
	// lwz r31,0(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lbz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subfic r9,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// srd r7,r11,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r8.u8 & 0x7F));
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r6,r29
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r29.u32);
	// extsh r30,r5
	ctx.r30.s64 = ctx.r5.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285bc38
	if (ctx.cr6.lt) goto loc_8285BC38;
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
	// bge cr6,0x8285bc30
	if (!ctx.cr6.lt) goto loc_8285BC30;
loc_8285BB98:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8285bbc4
	if (ctx.cr6.lt) goto loc_8285BBC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x8285BBB4;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8285bb98
	if (ctx.cr6.eq) goto loc_8285BB98;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285bc70
	goto loc_8285BC70;
loc_8285BBC4:
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
loc_8285BC30:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285bc70
	goto loc_8285BC70;
loc_8285BC38:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x8285BC40;
	sub_826C8C48(ctx, base);
loc_8285BC40:
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
	ctx.lr = 0x8285BC58;
	sub_826C8C48(ctx, base);
	// add r10,r30,r22
	ctx.r10.u64 = ctx.r30.u64 + ctx.r22.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285bc40
	if (ctx.cr6.lt) goto loc_8285BC40;
loc_8285BC70:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8285be24
	if (!ctx.cr6.eq) goto loc_8285BE24;
	// add r11,r30,r25
	ctx.r11.u64 = ctx.r30.u64 + ctx.r25.u64;
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// lbz r24,684(r11)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 684);
	// lbz r20,692(r10)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r10.u32 + 692);
loc_8285BC90:
	// add r11,r18,r19
	ctx.r11.u64 = ctx.r18.u64 + ctx.r19.u64;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// stb r24,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r24.u8);
	// bne cr6,0x8285bce4
	if (!ctx.cr6.eq) goto loc_8285BCE4;
	// lwz r31,20(r23)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r23.u32 + 20);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r4,404(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 404);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lbz r5,160(r25)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r25.u32 + 160);
	// bl 0x8286daf8
	ctx.lr = 0x8285BCB8;
	sub_8286DAF8(ctx, base);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// lwz r10,24(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 24);
	// ori r21,r21,1
	ctx.r21.u64 = ctx.r21.u64 | 1;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// stw r8,20(r23)
	REX_STORE_U32(ctx.r23.u32 + 20, ctx.r8.u32);
	// stb r3,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// lwz r11,24(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,24(r23)
	REX_STORE_U32(ctx.r23.u32 + 24, ctx.r7.u32);
	// b 0x8285bf44
	goto loc_8285BF44;
loc_8285BCE4:
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// bne cr6,0x8285be30
	if (!ctx.cr6.eq) goto loc_8285BE30;
	// lwz r31,0(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,612(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 612);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285bdd4
	if (ctx.cr6.lt) goto loc_8285BDD4;
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
	// bge cr6,0x8285bdcc
	if (!ctx.cr6.lt) goto loc_8285BDCC;
loc_8285BD34:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8285bd60
	if (ctx.cr6.lt) goto loc_8285BD60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x8285BD50;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8285bd34
	if (ctx.cr6.eq) goto loc_8285BD34;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285be10
	goto loc_8285BE10;
loc_8285BD60:
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
loc_8285BDCC:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285be10
	goto loc_8285BE10;
loc_8285BDD4:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x8285BDE0;
	sub_826C8C48(ctx, base);
loc_8285BDE0:
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
	ctx.lr = 0x8285BDF8;
	sub_826C8C48(ctx, base);
	// add r10,r30,r22
	ctx.r10.u64 = ctx.r30.u64 + ctx.r22.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285bde0
	if (ctx.cr6.lt) goto loc_8285BDE0;
loc_8285BE10:
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8285beb4
	if (ctx.cr6.eq) goto loc_8285BEB4;
loc_8285BE24:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_8285BE30:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x8285beb0
	if (!ctx.cr6.eq) goto loc_8285BEB0;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8285beb0
	if (!ctx.cr6.eq) goto loc_8285BEB0;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
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
	// bge 0x8285be70
	if (!ctx.cr0.lt) goto loc_8285BE70;
	// bl 0x826c8b78
	ctx.lr = 0x8285BE70;
	sub_826C8B78(ctx, base);
loc_8285BE70:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x8285bea8
	if (!ctx.cr6.eq) goto loc_8285BEA8;
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
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
	// bge 0x8285bea0
	if (!ctx.cr0.lt) goto loc_8285BEA0;
	// bl 0x826c8b78
	ctx.lr = 0x8285BEA0;
	sub_826C8B78(ctx, base);
loc_8285BEA0:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// b 0x8285beb4
	goto loc_8285BEB4;
loc_8285BEA8:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8285beb4
	goto loc_8285BEB4;
loc_8285BEB0:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_8285BEB4:
	// rlwinm r10,r24,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r28,404(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 404);
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lwz r27,24(r23)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r23.u32 + 24);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lwz r30,20(r23)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r23.u32 + 20);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// add r6,r24,r25
	ctx.r6.u64 = ctx.r24.u64 + ctx.r25.u64;
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lbz r29,320(r9)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r9.u32 + 320);
	// mr r31,r17
	ctx.r31.u64 = ctx.r17.u64;
	// or r21,r5,r21
	ctx.r21.u64 = ctx.r5.u64 | ctx.r21.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lbz r26,160(r6)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r6.u32 + 160);
	// ble cr6,0x8285bf1c
	if (!ctx.cr6.gt) goto loc_8285BF1C;
loc_8285BEF0:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8286daf8
	ctx.lr = 0x8285BF04;
	sub_8286DAF8(ctx, base);
	// stbx r3,r31,r27
	REX_STORE_U8(ctx.r31.u32 + ctx.r27.u32, ctx.r3.u8);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x8285bef0
	if (ctx.cr6.lt) goto loc_8285BEF0;
loc_8285BF1C:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8285be24
	if (ctx.cr6.eq) goto loc_8285BE24;
	// lwz r11,24(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 24);
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// stw r30,20(r23)
	REX_STORE_U32(ctx.r23.u32 + 20, ctx.r30.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r11,24(r23)
	REX_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x8285bf44
	goto loc_8285BF44;
loc_8285BF3C:
	// add r11,r18,r19
	ctx.r11.u64 = ctx.r18.u64 + ctx.r19.u64;
	// stb r17,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r17.u8);
loc_8285BF44:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// rlwinm r16,r16,31,1,31
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 31) & 0x7FFFFFFF;
	// rldicr r21,r21,8,55
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r21.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmplwi cr6,r18,6
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 6, ctx.xer);
	// blt cr6,0x8285bb20
	if (ctx.cr6.lt) goto loc_8285BB20;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// rldicl r10,r21,56,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u64, 56) & 0xFFFFFFFFFFFFFF;
	// lbz r9,4(r19)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r19.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r8,r11,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// lbz r7,5(r19)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r19.u32 + 5);
	// lwz r6,4(r23)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// rlwinm r5,r8,0,24,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xC0;
	// lwz r4,1312(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 1312);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// rldimi r5,r9,8,0
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00) | (ctx.r5.u64 & 0xFF);
	// or r9,r5,r7
	ctx.r9.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rldicr r8,r9,48,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 48) & 0xFFFF000000000000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stdx r7,r11,r4
	REX_STORE_U64(ctx.r11.u32 + ctx.r4.u32, ctx.r7.u64);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828ABEF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x828ABF00;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r28,r3,22640
	ctx.r28.s64 = ctx.r3.s64 + 22640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-13816(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13816);
	// bl 0x82893f28
	ctx.lr = 0x828ABF1C;
	sub_82893F28(ctx, base);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// addi r30,r31,15952
	ctx.r30.s64 = ctx.r31.s64 + 15952;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828ac800
	ctx.lr = 0x828ABF34;
	sub_828AC800(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828abff8
	if (!ctx.cr6.eq) goto loc_828ABFF8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828ac400
	ctx.lr = 0x828ABF4C;
	sub_828AC400(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828abff8
	if (!ctx.cr6.eq) goto loc_828ABFF8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828ab1a0
	ctx.lr = 0x828ABF64;
	sub_828AB1A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828abff8
	if (!ctx.cr6.eq) goto loc_828ABFF8;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x828abfd0
	if (ctx.cr6.eq) goto loc_828ABFD0;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x828abf94
	if (!ctx.cr6.eq) goto loc_828ABF94;
	// bl 0x828ab0c0
	ctx.lr = 0x828ABF90;
	sub_828AB0C0(ctx, base);
	// b 0x828abf98
	goto loc_828ABF98;
loc_828ABF94:
	// bl 0x828ab000
	ctx.lr = 0x828ABF98;
	sub_828AB000(ctx, base);
loc_828ABF98:
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// bl 0x826d5568
	ctx.lr = 0x828ABFD0;
	sub_826D5568(ctx, base);
loc_828ABFD0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82894270
	ctx.lr = 0x828ABFDC;
	sub_82894270(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r10.u32);
	// stw r11,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
	// stw r11,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
loc_828ABFF8:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

