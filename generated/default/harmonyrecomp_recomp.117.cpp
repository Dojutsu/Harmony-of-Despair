#include "harmonyrecomp_funcs.117.h"

DEFINE_REX_FUNC(sub_82217838) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,16(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r5,12(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r3,20(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825d5ec0
	ctx.lr = 0x8221786C;
	sub_825D5EC0(ctx, base);
	// addic r10,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bl 0x82639838
	ctx.lr = 0x82217890;
	sub_82639838(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r10,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r10.u8);
	// bl 0x82639f58
	ctx.lr = 0x822178A8;
	sub_82639F58(ctx, base);
}

DEFINE_REX_FUNC(sub_8221D5B8) {
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
	// addi r11,r11,984
	ctx.r11.s64 = ctx.r11.s64 + 984;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x822239a8
	ctx.lr = 0x8221D5E4;
	sub_822239A8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221d5f4
	if (ctx.cr0.eq) goto loc_8221D5F4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8221D5F4;
	sub_825E0378(ctx, base);
loc_8221D5F4:
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

DEFINE_REX_FUNC(sub_8221FE70) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221ffe8
	if (ctx.cr6.eq) goto loc_8221FFE8;
	// li r9,5
	ctx.r9.s64 = 5;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,56
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 56, ctx.xer);
	// addi r30,r10,14376
	ctx.r30.s64 = ctx.r10.s64 + 14376;
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f31,-1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// lfs f0,22840(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// beq cr6,0x8221fec8
	if (ctx.cr6.eq) goto loc_8221FEC8;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
loc_8221FEC8:
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x823bee38
	ctx.lr = 0x8221FEDC;
	sub_823BEE38(ctx, base);
	// stfs f1,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fmr f0,f1
	ctx.f0.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8221FEF4;
	sub_825A4A40(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bge cr6,0x8221ff04
	if (!ctx.cr6.lt) goto loc_8221FF04;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
loc_8221FF04:
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f1,108(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 108, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f31,104(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// stb r9,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r9.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// sth r10,86(r11)
	REX_STORE_U16(ctx.r11.u32 + 86, ctx.r10.u16);
	// stw r7,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r7.u32);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r7,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x823bd0f0
	ctx.lr = 0x8221FF40;
	sub_823BD0F0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8221ffe8
	if (ctx.cr0.eq) goto loc_8221FFE8;
	// lhz r11,33(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 33);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8221ffe8
	if (ctx.cr0.eq) goto loc_8221FFE8;
	// lwz r9,12(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r11,60(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221ff8c
	if (ctx.cr6.eq) goto loc_8221FF8C;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8221ff8c
	if (!ctx.cr6.gt) goto loc_8221FF8C;
	// lwz r11,84(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221ff8c
	if (ctx.cr6.eq) goto loc_8221FF8C;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8221ff90
	goto loc_8221FF90;
loc_8221FF8C:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_8221FF90:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221ffe8
	if (ctx.cr6.eq) goto loc_8221FFE8;
	// addi r6,r31,74
	ctx.r6.s64 = ctx.r31.s64 + 74;
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r5,r31,72
	ctx.r5.s64 = ctx.r31.s64 + 72;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x823c2c38
	ctx.lr = 0x8221FFAC;
	sub_823C2C38(ctx, base);
	// lhz r10,74(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// lfs f0,-2140(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
	// li r11,76
	ctx.r11.s64 = 76;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f12,56(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.f0.u32);
loc_8221FFE8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

DEFINE_REX_FUNC(sub_8222E5F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8222E600;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af10
	ctx.lr = 0x8222E608;
	__savefpr_22(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f23,f1
	ctx.fpscr.disableFlushMode();
	ctx.f23.f64 = ctx.f1.f64;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r10,r11,12468
	ctx.r10.s64 = ctx.r11.s64 + 12468;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// mr r20,r6
	ctx.r20.u64 = ctx.r6.u64;
	// lfs f0,23492(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23492);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// lfs f13,3188(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
	// lfs f29,1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1908);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f27,f0,f13
	ctx.f27.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f22,f0,f29
	ctx.f22.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// blt cr6,0x8222e658
	if (ctx.cr6.lt) goto loc_8222E658;
	// beq cr6,0x8222e650
	if (ctx.cr6.eq) goto loc_8222E650;
	// fmr f13,f29
	ctx.f13.f64 = ctx.f29.f64;
	// b 0x8222e660
	goto loc_8222E660;
loc_8222E650:
	// lfs f13,-232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8222e660
	goto loc_8222E660;
loc_8222E658:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
loc_8222E660:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f31,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// fmuls f25,f27,f29
	ctx.f25.f64 = double(float(ctx.f27.f64 * ctx.f29.f64));
	// addi r11,r11,26028
	ctx.r11.s64 = ctx.r11.s64 + 26028;
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25404(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25404);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f0,-24492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f24,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r21,r30
	ctx.r21.u64 = ctx.r30.u64;
	// lis r24,-32112
	ctx.r24.s64 = -2104492032;
	// addi r23,r6,1340
	ctx.r23.s64 = ctx.r6.s64 + 1340;
	// addi r25,r7,1368
	ctx.r25.s64 = ctx.r7.s64 + 1368;
	// addi r29,r8,2688
	ctx.r29.s64 = ctx.r8.s64 + 2688;
	// addi r28,r9,2720
	ctx.r28.s64 = ctx.r9.s64 + 2720;
	// addi r27,r10,3280
	ctx.r27.s64 = ctx.r10.s64 + 3280;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
	// fmuls f26,f30,f0
	ctx.f26.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
loc_8222E6C0:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x825e02a0
	ctx.lr = 0x8222E6D0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8222e73c
	if (ctx.cr0.eq) goto loc_8222E73C;
	// stfs f31,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stw r27,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// stw r30,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// stb r30,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r30.u8);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r30,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r30,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// stfs f31,52(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stw r30,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,96(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f31,100(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f24,104(r3)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f29,108(r3)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stvx128 v63,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r30,124(r3)
	REX_STORE_U16(ctx.r3.u32 + 124, ctx.r30.u16);
	// stfs f31,116(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// sth r30,126(r3)
	REX_STORE_U16(ctx.r3.u32 + 126, ctx.r30.u16);
	// stfs f31,120(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// b 0x8222e740
	goto loc_8222E740;
loc_8222E73C:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_8222E740:
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// fmr f2,f25
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f25.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8222E754;
	sub_825A4A40(ctx, base);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8222e84c
	if (ctx.cr6.eq) goto loc_8222E84C;
	// lwz r11,-15508(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -15508);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8222E774;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x8222E778;
	sub_8245A220(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8222e794
	if (ctx.cr6.eq) goto loc_8222E794;
	// bl 0x8221cc98
	ctx.lr = 0x8222E78C;
	sub_8221CC98(ctx, base);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stb r30,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r30.u8);
loc_8222E794:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825e02a0
	ctx.lr = 0x8222E7A4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8222e7b8
	if (ctx.cr0.eq) goto loc_8222E7B8;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x823bdc58
	ctx.lr = 0x8222E7B4;
	sub_823BDC58(ctx, base);
	// b 0x8222e7bc
	goto loc_8222E7BC;
loc_8222E7B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8222E7BC:
	// extsw r11,r21
	ctx.r11.s64 = ctx.r21.s32;
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// fadds f0,f30,f23
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f23.f64));
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lfs f3,76(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 76);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f12,f13,f27,f28
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f27.f64, ctx.f28.f64)));
	// fnmsubs f1,f13,f26,f0
	ctx.f1.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f26.f64, -ctx.f0.f64)));
	// fadds f2,f12,f22
	ctx.f2.f64 = double(float(ctx.f12.f64 + ctx.f22.f64));
	// bl 0x8222e868
	ctx.lr = 0x8222E7FC;
	sub_8222E868(ctx, base);
	// lwz r11,112(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 112);
	// addi r3,r22,108
	ctx.r3.s64 = ctx.r22.s64 + 108;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8222e814
	if (!ctx.cr6.eq) goto loc_8222E814;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x8222e820
	goto loc_8222E820;
loc_8222E814:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8222E820:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8222e844
	if (!ctx.cr6.lt) goto loc_8222E844;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8222e84c
	goto loc_8222E84C;
loc_8222E844:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x8222E84C;
	sub_823849B0(ctx, base);
loc_8222E84C:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// cmpwi cr6,r21,5
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 5, ctx.xer);
	// blt cr6,0x8222e6c0
	if (ctx.cr6.lt) goto loc_8222E6C0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af5c
	ctx.lr = 0x8222E864;
	__restfpr_22(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82247300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82247308;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
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
	ctx.lr = 0x82247338;
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
	// beq 0x8224750c
	if (ctx.cr0.eq) goto loc_8224750C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,424(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82247364;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,424(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 424);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82247384;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r24,8(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8224750c
	if (ctx.cr6.eq) goto loc_8224750C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r29,-32226
	ctx.r29.s64 = -2111963136;
	// lis r26,-32115
	ctx.r26.s64 = -2104688640;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// lfs f30,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
loc_822473AC:
	// lwz r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82247500
	if (!ctx.cr6.eq) goto loc_82247500;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r4,124
	ctx.r4.s64 = 124;
	// bl 0x825e02a0
	ctx.lr = 0x822473C8;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82247440
	if (ctx.cr0.eq) goto loc_82247440;
	// lfs f31,36(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// bge cr6,0x822473e8
	if (!ctx.cr6.lt) goto loc_822473E8;
	// lfs f0,-6808(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -6808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,23848(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 23848);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
loc_822473E8:
	// lhz r11,6(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 6);
	// lfs f0,-8644(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r9,264(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 264);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// fmuls f29,f13,f0
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82247428;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fadds f1,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f29.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822409f8
	ctx.lr = 0x82247438;
	sub_822409F8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82247444
	goto loc_82247444;
loc_82247440:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82247444:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82247500
	if (ctx.cr6.eq) goto loc_82247500;
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// lfs f3,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,24(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82224038
	ctx.lr = 0x82247460;
	sub_82224038(ctx, base);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82247488;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stb r11,108(r31)
	REX_STORE_U8(ctx.r31.u32 + 108, ctx.r11.u8);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// lwz r11,40(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x822474b0
	if (!ctx.cr6.lt) goto loc_822474B0;
	// li r11,3
	ctx.r11.s64 = 3;
loc_822474B0:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822474C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822474D4;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822474fc
	if (!ctx.cr6.eq) goto loc_822474FC;
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
	ctx.lr = 0x822474F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82247500
	goto loc_82247500;
loc_822474FC:
	// stw r11,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r11.u32);
loc_82247500:
	// addi r30,r30,52
	ctx.r30.s64 = ctx.r30.s64 + 52;
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x822473ac
	if (!ctx.cr6.eq) goto loc_822473AC;
loc_8224750C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82256730) {
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
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r30,1
	ctx.r30.s64 = 1;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822567a4
	if (ctx.cr0.eq) goto loc_822567A4;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82256778;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stb r30,28(r3)
	REX_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r10,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r10.u32);
	// sth r11,86(r3)
	REX_STORE_U16(ctx.r3.u32 + 86, ctx.r11.u16);
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// stfs f0,108(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
loc_822567A4:
	// stb r30,279(r31)
	REX_STORE_U8(ctx.r31.u32 + 279, ctx.r30.u8);
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

DEFINE_REX_FUNC(sub_822606C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x822606C8;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82266018
	ctx.lr = 0x822606DC;
	sub_82266018(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822607dc
	if (!ctx.cr0.eq) goto loc_822607DC;
	// addis r24,r29,1
	ctx.r24.s64 = ctx.r29.s64 + 65536;
	// addi r24,r24,-3148
	ctx.r24.s64 = ctx.r24.s64 + -3148;
	// lwz r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// lwz r10,4(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r25,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r25.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x822607a4
	if (ctx.cr0.eq) goto loc_822607A4;
	// lbz r11,466(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 466);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822607a4
	if (!ctx.cr0.eq) goto loc_822607A4;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// beq cr6,0x822607a4
	if (ctx.cr6.eq) goto loc_822607A4;
	// addis r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 65536;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// addi r28,r28,-3144
	ctx.r28.s64 = ctx.r28.s64 + -3144;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_8226072C:
	// lwz r11,468(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 468);
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stb r31,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r31.u8);
	// stb r31,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r31.u8);
	// beq cr6,0x82260758
	if (ctx.cr6.eq) goto loc_82260758;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_82260758:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-13032(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r4,r11,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stb r31,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r31.u8);
	// stb r31,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r31.u8);
	// beq cr6,0x8226078c
	if (ctx.cr6.eq) goto loc_8226078C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b0af8
	ctx.lr = 0x8226078C;
	sub_823B0AF8(ctx, base);
loc_8226078C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822607a4
	if (!ctx.cr0.eq) goto loc_822607A4;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8226072c
	if (ctx.cr6.lt) goto loc_8226072C;
loc_822607A4:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82217698
	ctx.lr = 0x822607AC;
	sub_82217698(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,576(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// beq cr6,0x822607d0
	if (ctx.cr6.eq) goto loc_822607D0;
	// lfs f12,152(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f0,152(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 152, temp.u32);
	// stfs f13,576(r29)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r29.u32 + 576, temp.u32);
loc_822607D0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82231670
	ctx.lr = 0x822607DC;
	sub_82231670(ctx, base);
loc_822607DC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8226F468) {
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
	// ori r4,r4,63440
	ctx.r4.u64 = ctx.r4.u64 | 63440;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8226F490;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8226f4a0
	if (ctx.cr0.eq) goto loc_8226F4A0;
	// bl 0x8226ecd8
	ctx.lr = 0x8226F49C;
	sub_8226ECD8(ctx, base);
	// b 0x8226f4a4
	goto loc_8226F4A4;
loc_8226F4A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226F4A4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82270370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82270378;
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
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// addi r28,r3,260
	ctx.r28.s64 = ctx.r3.s64 + 260;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822703bc
	if (ctx.cr0.eq) goto loc_822703BC;
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
	ctx.lr = 0x822703BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822703BC:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,60(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822703D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r25,1
	ctx.r25.s64 = 1;
	// stb r25,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r25.u8);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// ble cr6,0x82270410
	if (!ctx.cr6.gt) goto loc_82270410;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82270410:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,64(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270428;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r25,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r25.u8);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,64(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270444;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x82270458
	if (ctx.cr6.eq) goto loc_82270458;
	// li r11,7
	ctx.r11.s64 = 7;
	// sth r11,92(r3)
	REX_STORE_U16(ctx.r3.u32 + 92, ctx.r11.u16);
loc_82270458:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// ble cr6,0x8227048c
	if (!ctx.cr6.gt) goto loc_8227048C;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,64(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227048C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227048C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,8(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8224a2a0
	ctx.lr = 0x822704B4;
	sub_8224A2A0(ctx, base);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r30,11948
	ctx.r10.s64 = ctx.r30.s64 + 11948;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,-16652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16652);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,5340(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5340);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x8226ec58
	ctx.lr = 0x822704D8;
	sub_8226EC58(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x8224a2a0
	ctx.lr = 0x822704F8;
	sub_8224A2A0(ctx, base);
	// li r6,9
	ctx.r6.s64 = 9;
	// lfs f1,11948(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 11948);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x8226ec58
	ctx.lr = 0x8227050C;
	sub_8226EC58(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// ble cr6,0x82270540
	if (!ctx.cr6.gt) goto loc_82270540;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270540;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82270540:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x8224a2a0
	ctx.lr = 0x82270560;
	sub_8224A2A0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// li r6,13
	ctx.r6.s64 = 13;
	// addi r30,r11,-4080
	ctx.r30.s64 = ctx.r11.s64 + -4080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,964(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 964);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8226ec58
	ctx.lr = 0x8227057C;
	sub_8226EC58(ctx, base);
	// li r6,14
	ctx.r6.s64 = 14;
	// lfs f1,984(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 984);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x8226ec58
	ctx.lr = 0x82270590;
	sub_8226EC58(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// ble cr6,0x822705c4
	if (!ctx.cr6.gt) goto loc_822705C4;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,56(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822705C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822705C4:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r11,-31680
	ctx.r11.s64 = ctx.r11.s64 + -31680;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,-31696
	ctx.r9.s64 = ctx.r9.s64 + -31696;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
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
	// bl 0x8255f918
	ctx.lr = 0x82270610;
	sub_8255F918(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3140
	ctx.r11.s64 = ctx.r11.s64 + -3140;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r27,r27,-3132
	ctx.r27.s64 = ctx.r27.s64 + -3132;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// stw r9,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// lwz r3,40(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270658;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r26,r11,-32768
	ctx.r26.s64 = ctx.r11.s64 + -32768;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-32640
	ctx.r11.s64 = ctx.r11.s64 + -32640;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r9,62428
	ctx.r10.u64 = ctx.r9.u64 | 62428;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// ori r9,r8,62432
	ctx.r9.u64 = ctx.r8.u64 | 62432;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfsx f1,r31,r10
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfsx f1,r31,r9
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822706B8;
	sub_8255F918(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3100
	ctx.r11.s64 = ctx.r11.s64 + -3100;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r29,r29,-3092
	ctx.r29.s64 = ctx.r29.s64 + -3092;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270700;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,0
	ctx.r9.s64 = 0;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,-31712
	ctx.r11.s64 = ctx.r10.s64 + -31712;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r9,62468
	ctx.r9.u64 = ctx.r9.u64 | 62468;
	// ori r11,r10,62472
	ctx.r11.u64 = ctx.r10.u64 | 62472;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfsx f1,r31,r9
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfsx f1,r31,r11
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82270758;
	sub_8255F918(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3060
	ctx.r11.s64 = ctx.r11.s64 + -3060;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r26,r26,-3052
	ctx.r26.s64 = ctx.r26.s64 + -3052;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822707A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62508
	ctx.r11.u64 = ctx.r11.u64 | 62508;
	// ori r10,r10,62512
	ctx.r10.u64 = ctx.r10.u64 | 62512;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f1,r31,r10
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x822707C8;
	sub_82322D08(ctx, base);
	// lbz r11,278(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 278);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82270814
	if (ctx.cr0.eq) goto loc_82270814;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232628
	ctx.lr = 0x822707E0;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82270814
	if (!ctx.cr0.eq) goto loc_82270814;
	// lbz r11,281(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 281);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82270814
	if (!ctx.cr0.eq) goto loc_82270814;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r11,10
	ctx.xer.ca = ctx.r11.u32 <= 10;
	ctx.r11.u64 = static_cast<uint64_t>(10) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// b 0x82270818
	goto loc_82270818;
loc_82270814:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82270818:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8227083c
	if (ctx.cr0.eq) goto loc_8227083C;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227083C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227083C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82322d08
	ctx.lr = 0x8227084C;
	sub_82322D08(ctx, base);
	// lbz r11,278(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 278);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82270898
	if (ctx.cr0.eq) goto loc_82270898;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232628
	ctx.lr = 0x82270864;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82270898
	if (!ctx.cr0.eq) goto loc_82270898;
	// lbz r11,281(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 281);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82270898
	if (!ctx.cr0.eq) goto loc_82270898;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r11,11
	ctx.xer.ca = ctx.r11.u32 <= 11;
	ctx.r11.u64 = static_cast<uint64_t>(11) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// b 0x8227089c
	goto loc_8227089C;
loc_82270898:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8227089C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822708c0
	if (ctx.cr0.eq) goto loc_822708C0;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822708C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822708C0:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82322d08
	ctx.lr = 0x822708D0;
	sub_82322D08(ctx, base);
	// lbz r11,278(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 278);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227091c
	if (ctx.cr0.eq) goto loc_8227091C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232628
	ctx.lr = 0x822708E8;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227091c
	if (!ctx.cr0.eq) goto loc_8227091C;
	// lbz r11,281(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 281);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8227091c
	if (!ctx.cr0.eq) goto loc_8227091C;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r11,12
	ctx.xer.ca = ctx.r11.u32 <= 12;
	ctx.r11.u64 = static_cast<uint64_t>(12) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// b 0x82270920
	goto loc_82270920;
loc_8227091C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82270920:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82270944
	if (ctx.cr0.eq) goto loc_82270944;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82270944;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82270944:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// addi r30,r31,244
	ctx.r30.s64 = ctx.r31.s64 + 244;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82270978
	if (ctx.cr0.eq) goto loc_82270978;
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
	ctx.lr = 0x82270978;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82270978:
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
	// ble cr6,0x822709ac
	if (!ctx.cr6.gt) goto loc_822709AC;
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
	ctx.lr = 0x822709AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822709AC:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,68(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822709CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r25,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r25.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A7498) {
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
	// ori r4,r4,65044
	ctx.r4.u64 = ctx.r4.u64 | 65044;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x822A74C0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822a74d0
	if (ctx.cr0.eq) goto loc_822A74D0;
	// bl 0x822a7018
	ctx.lr = 0x822A74CC;
	sub_822A7018(ctx, base);
	// b 0x822a74d4
	goto loc_822A74D4;
loc_822A74D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A74D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822A8D70) {
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
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64244
	ctx.r11.u64 = ctx.r11.u64 | 64244;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822a8da0
	if (ctx.cr0.eq) goto loc_822A8DA0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64272
	ctx.r11.u64 = ctx.r11.u64 | 64272;
	// lfsx f1,r3,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822a8dc4
	goto loc_822A8DC4;
loc_822A8DA0:
	// bl 0x82577228
	ctx.lr = 0x822A8DA4;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,26612(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26612);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_822A8DC4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822B1290) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x822B1298;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	ctx.lr = 0x822B12C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B12E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// addi r28,r9,24772
	ctx.r28.s64 = ctx.r9.s64 + 24772;
	// lfs f0,24752(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24752);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,932(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 932);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f6,232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f6.f64 = double(temp.f32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// lfs f9,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f7,30908(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 30908);
	ctx.f7.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f4,11952(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11952);
	ctx.f4.f64 = double(temp.f32);
	// addi r3,r3,-3140
	ctx.r3.s64 = ctx.r3.s64 + -3140;
	// lfs f8,24756(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24756);
	ctx.f8.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f3,-148(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -148);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f5,884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 884);
	ctx.f5.f64 = double(temp.f32);
	// addi r22,r10,11952
	ctx.r22.s64 = ctx.r10.s64 + 11952;
loc_822B1344:
	// clrldi r10,r5,32
	ctx.r10.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f13,f5,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f5.f64, -ctx.f0.f64)));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// bge cr6,0x822b1378
	if (!ctx.cr6.lt) goto loc_822B1378;
	// fmr f0,f6
	ctx.f0.f64 = ctx.f6.f64;
	// b 0x822b1384
	goto loc_822B1384;
loc_822B1378:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x822b1384
	if (!ctx.cr6.gt) goto loc_822B1384;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_822B1384:
	// fmuls f13,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
	// fmadds f1,f8,f0,f2
	ctx.f1.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f2.f64)));
	// fctidz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// subfic r6,r11,255
	ctx.xer.ca = ctx.r11.u32 <= 255;
	ctx.r6.u64 = static_cast<uint64_t>(255) - ctx.r11.u64;
	// bl 0x822ea1a8
	ctx.lr = 0x822B13A0;
	sub_822EA1A8(ctx, base);
	// clrlwi. r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fadds f13,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f9.f64));
	// beq 0x822b13b4
	if (ctx.cr0.eq) goto loc_822B13B4;
	// fmr f0,f4
	ctx.f0.f64 = ctx.f4.f64;
	// b 0x822b13b8
	goto loc_822B13B8;
loc_822B13B4:
	// fmr f0,f3
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f3.f64;
loc_822B13B8:
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// li r9,4
	ctx.r9.s64 = 4;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// addi r10,r7,-12
	ctx.r10.s64 = ctx.r7.s64 + -12;
	// rlwimi r11,r8,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_822B13D8:
	// lfs f13,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f13,12(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// stwu r11,40(r10)
	ea = 40 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822b13d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822B13D8;
	// addi r4,r4,160
	ctx.r4.s64 = ctx.r4.s64 + 160;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r4,12800
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 12800, ctx.xer);
	// blt cr6,0x822b1344
	if (ctx.cr6.lt) goto loc_822B1344;
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
	ctx.lr = 0x822B1418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r29,44
	ctx.r29.s64 = 44;
	// addi r30,r30,-3004
	ctx.r30.s64 = ctx.r30.s64 + -3004;
	// addi r23,r11,2880
	ctx.r23.s64 = ctx.r11.s64 + 2880;
loc_822B1430:
	// lbz r11,-48(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + -48);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// beq 0x822b1594
	if (ctx.cr0.eq) goto loc_822B1594;
	// li r4,1
	ctx.r4.s64 = 1;
	// bctrl 
	ctx.lr = 0x822B1458;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r30,-8
	ctx.r4.s64 = ctx.r30.s64 + -8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8255f918
	ctx.lr = 0x822B1468;
	sub_8255F918(ctx, base);
	// addi r5,r30,40
	ctx.r5.s64 = ctx.r30.s64 + 40;
	// addi r4,r30,32
	ctx.r4.s64 = ctx.r30.s64 + 32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8255f918
	ctx.lr = 0x822B1478;
	sub_8255F918(ctx, base);
	// addi r5,r30,20
	ctx.r5.s64 = ctx.r30.s64 + 20;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8255f918
	ctx.lr = 0x822B1488;
	sub_8255F918(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B14A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B14C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B14E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// lfs f4,-10344(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -10344);
	ctx.f4.f64 = double(temp.f32);
	// addi r28,r28,-924
	ctx.r28.s64 = ctx.r28.s64 + -924;
	// addi r4,r4,-856
	ctx.r4.s64 = ctx.r4.s64 + -856;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r27,r4,128
	ctx.r27.s64 = ctx.r4.s64 + 128;
	// mr r24,r28
	ctx.r24.u64 = ctx.r28.u64;
	// stfs f4,64(r28)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r28.u32 + 64, temp.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stfs f4,0(r28)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,128(r4)
	REX_STORE_U64(ctx.r4.u32 + 128, ctx.r11.u64);
loc_822B1520:
	// extsw r11,r26
	ctx.r11.s64 = ctx.r26.s32;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x825a5eb8
	ctx.lr = 0x822B1548;
	sub_825A5EB8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpwi cr6,r26,16
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 16, ctx.xer);
	// stwu r11,8(r25)
	ea = 8 + ctx.r25.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r25.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// stfsu f4,4(r24)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r24.u32;
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r24.u32 = ea;
	// blt cr6,0x822b1520
	if (ctx.cr6.lt) goto loc_822B1520;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x823c39c8
	ctx.lr = 0x822B1580;
	sub_823C39C8(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822B1594:
	// li r4,0
	ctx.r4.s64 = 0;
	// bctrl 
	ctx.lr = 0x822B159C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r30,r30,100
	ctx.r30.s64 = ctx.r30.s64 + 100;
	// cmplwi cr6,r29,108
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 108, ctx.xer);
	// blt cr6,0x822b1430
	if (ctx.cr6.lt) goto loc_822B1430;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C5CD8) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,28
	ctx.r11.u64 = ctx.r4.u32 & 0xF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x822c5cec
	if (!ctx.cr6.eq) goto loc_822C5CEC;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x822c5d08
	goto loc_822C5D08;
loc_822C5CEC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x822c5cfc
	if (!ctx.cr6.eq) goto loc_822C5CFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822c5d08
	goto loc_822C5D08;
loc_822C5CFC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822C5D08:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
	// stwx r10,r3,r11
	REX_STORE_U32(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822C7438) {
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
	ctx.lr = 0x822C7450;
	sub_82237858(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62476
	ctx.r11.u64 = ctx.r11.u64 | 62476;
	// ori r10,r10,62372
	ctx.r10.u64 = ctx.r10.u64 | 62372;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stbx r9,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u8);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
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

DEFINE_REX_FUNC(sub_822C82A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822C82A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-3124
	ctx.r11.s64 = ctx.r11.s64 + -3124;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x822c83e4
	if (!ctx.cr6.lt) goto loc_822C83E4;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// ori r8,r8,62384
	ctx.r8.u64 = ctx.r8.u64 | 62384;
	// lfs f0,25444(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25444);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lbzx r10,r3,r8
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r8.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x822c83ac
	if (!ctx.cr0.eq) goto loc_822C83AC;
	// lfs f0,25444(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25444);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,62385
	ctx.r9.u64 = ctx.r9.u64 | 62385;
	// lfs f13,8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,8(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lbzx r10,r3,r9
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x822c83e4
	if (!ctx.cr0.eq) goto loc_822C83E4;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822c83e4
	if (!ctx.cr6.gt) goto loc_822C83E4;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,116(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C836C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// lwz r10,112(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 112);
	// li r9,2
	ctx.r9.s64 = 2;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// and r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 & ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C8390;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822C8390:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822c83e4
	if (!ctx.cr6.eq) goto loc_822C83E4;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822c83e0
	goto loc_822C83E0;
loc_822C83AC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r11,r11,62385
	ctx.r11.u64 = ctx.r11.u64 | 62385;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822c83ec
	if (ctx.cr0.eq) goto loc_822C83EC;
	// bl 0x822c9130
	ctx.lr = 0x822C83C8;
	sub_822C9130(ctx, base);
loc_822C83C8:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822c83e4
	if (!ctx.cr6.eq) goto loc_822C83E4;
	// li r10,3
	ctx.r10.s64 = 3;
loc_822C83E0:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822C83E4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_822C83EC:
	// bl 0x822c8fc8
	ctx.lr = 0x822C83F0;
	sub_822C8FC8(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,26612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26612);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x822c841c
	if (!ctx.cr6.lt) goto loc_822C841C;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822c83e4
	if (!ctx.cr6.eq) goto loc_822C83E4;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x822c83e0
	goto loc_822C83E0;
loc_822C841C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,25452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25452);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x822c83c8
	if (!ctx.cr6.gt) goto loc_822C83C8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822c9130
	ctx.lr = 0x822C8434;
	sub_822C9130(ctx, base);
	// b 0x822c8390
	goto loc_822C8390;
}

DEFINE_REX_FUNC(sub_822D0158) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822D0160;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// ori r9,r9,62384
	ctx.r9.u64 = ctx.r9.u64 | 62384;
	// ori r8,r8,62412
	ctx.r8.u64 = ctx.r8.u64 | 62412;
	// li r30,0
	ctx.r30.s64 = 0;
	// lfs f31,12468(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stwx r30,r3,r11
	REX_STORE_U32(ctx.r3.u32 + ctx.r11.u32, ctx.r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfsx f31,r3,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stwx r30,r3,r8
	REX_STORE_U32(ctx.r3.u32 + ctx.r8.u32, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822D01C0;
	sub_8224A2A0(ctx, base);
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq 0x822d01d4
	if (ctx.cr0.eq) goto loc_822D01D4;
	// bl 0x822d0700
	ctx.lr = 0x822D01D0;
	sub_822D0700(ctx, base);
	// b 0x822d01d8
	goto loc_822D01D8;
loc_822D01D4:
	// bl 0x822d0590
	ctx.lr = 0x822D01D8;
	sub_822D0590(ctx, base);
loc_822D01D8:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x822D01EC;
	sub_8222FF78(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62424
	ctx.r11.u64 = ctx.r11.u64 | 62424;
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
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfsx f0,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x822d024c
	if (ctx.cr6.lt) goto loc_822D024C;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_822D024C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne 0x822d0270
	if (!ctx.cr0.eq) goto loc_822D0270;
	// li r4,2
	ctx.r4.s64 = 2;
loc_822D0270:
	// bctrl 
	ctx.lr = 0x822D0274;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// bne 0x822d02a8
	if (!ctx.cr0.eq) goto loc_822D02A8;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r9,3
	ctx.r9.s64 = 3;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r30,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r30.u32);
	// b 0x822d02ac
	goto loc_822D02AC;
loc_822D02A8:
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
loc_822D02AC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D7148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822D7150;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4236
	ctx.r4.s64 = ctx.r11.s64 + 4236;
	// bl 0x8222fa58
	ctx.lr = 0x822D7168;
	sub_8222FA58(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,-3164
	ctx.r10.s64 = ctx.r10.s64 + -3164;
	// addi r11,r11,12856
	ctx.r11.s64 = ctx.r11.s64 + 12856;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stb r30,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r30.u8);
	// addi r3,r3,-3156
	ctx.r3.s64 = ctx.r3.s64 + -3156;
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x822D7194;
	sub_822131A0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3124
	ctx.r11.s64 = ctx.r11.s64 + -3124;
	// addi r3,r3,-3116
	ctx.r3.s64 = ctx.r3.s64 + -3116;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x822D71B0;
	sub_822131A0(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r10,-3084
	ctx.r10.s64 = ctx.r10.s64 + -3084;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-3076
	ctx.r3.s64 = ctx.r3.s64 + -3076;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,4(r10)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stb r30,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r30.u8);
	// stb r30,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r30.u8);
	// bl 0x822131a0
	ctx.lr = 0x822D71D8;
	sub_822131A0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3044
	ctx.r11.s64 = ctx.r11.s64 + -3044;
	// addi r3,r3,-3036
	ctx.r3.s64 = ctx.r3.s64 + -3036;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x822D71F4;
	sub_822131A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62532
	ctx.r11.u64 = ctx.r11.u64 | 62532;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// lis r3,-32228
	ctx.r3.s64 = -2112094208;
	// ori r9,r9,62544
	ctx.r9.u64 = ctx.r9.u64 | 62544;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r10,r10,62536
	ctx.r10.u64 = ctx.r10.u64 | 62536;
	// ori r8,r8,62548
	ctx.r8.u64 = ctx.r8.u64 | 62548;
	// lfs f0,11948(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 11948);
	ctx.f0.f64 = double(temp.f32);
	// ori r6,r6,62553
	ctx.r6.u64 = ctx.r6.u64 | 62553;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// ori r7,r7,62552
	ctx.r7.u64 = ctx.r7.u64 | 62552;
	// ori r5,r5,62556
	ctx.r5.u64 = ctx.r5.u64 | 62556;
	// ld r11,2880(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 2880);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stdx r11,r31,r10
	REX_STORE_U64(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u64);
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r11,r29,62560
	ctx.r11.u64 = ctx.r29.u64 | 62560;
	// ori r10,r28,62567
	ctx.r10.u64 = ctx.r28.u64 | 62567;
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r9,-2968
	ctx.r9.s64 = ctx.r9.s64 + -2968;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stbx r8,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r8.u8);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stwx r6,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r6.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r30.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stb r30,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r30.u8);
	// ori r8,r8,62596
	ctx.r8.u64 = ctx.r8.u64 | 62596;
	// stw r30,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r30.u32);
	// ori r7,r7,62597
	ctx.r7.u64 = ctx.r7.u64 | 62597;
	// stw r30,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r30.u32);
	// ori r6,r6,62598
	ctx.r6.u64 = ctx.r6.u64 | 62598;
	// stw r30,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r30.u32);
	// ori r11,r11,62600
	ctx.r11.u64 = ctx.r11.u64 | 62600;
	// stw r30,20(r9)
	REX_STORE_U32(ctx.r9.u32 + 20, ctx.r30.u32);
	// ori r10,r10,62604
	ctx.r10.u64 = ctx.r10.u64 | 62604;
	// stb r30,24(r9)
	REX_STORE_U8(ctx.r9.u32 + 24, ctx.r30.u8);
	// ori r5,r5,62608
	ctx.r5.u64 = ctx.r5.u64 | 62608;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// ori r4,r4,62612
	ctx.r4.u64 = ctx.r4.u64 | 62612;
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stwx r30,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// stbx r30,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u8);
	// bl 0x824f0128
	ctx.lr = 0x822D72F4;
	sub_824F0128(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-2975
	ctx.r10.s64 = ctx.r10.s64 + -2975;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822D7308:
	// stbu r30,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822d7308
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822D7308;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822E8BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x822E8BB8;
	__savegprlr_23(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// ori r10,r10,62436
	ctx.r10.u64 = ctx.r10.u64 | 62436;
	// addi r25,r11,1608
	ctx.r25.s64 = ctx.r11.s64 + 1608;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lfsx f0,r3,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// lfs f11,-984(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -984);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x822e8be8
	if (!ctx.cr6.gt) goto loc_822E8BE8;
	// fmr f13,f11
	ctx.f13.f64 = ctx.f11.f64;
loc_822E8BE8:
	// addis r31,r27,1
	ctx.r31.s64 = ctx.r27.s64 + 65536;
	// addi r31,r31,-3148
	ctx.r31.s64 = ctx.r31.s64 + -3148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82222370
	ctx.lr = 0x822E8BF8;
	sub_82222370(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82568120
	ctx.lr = 0x822E8C38;
	sub_82568120(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r24,r27,88
	ctx.r24.s64 = ctx.r27.s64 + 88;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// bl 0x8255f918
	ctx.lr = 0x822E8CC0;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r26,-13032(r10)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stw r9,88(r27)
	REX_STORE_U32(ctx.r27.u32 + 88, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,92(r27)
	REX_STORE_U32(ctx.r27.u32 + 92, ctx.r11.u32);
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,92(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x822e8d1c
	if (ctx.cr6.eq) goto loc_822E8D1C;
	// addi r5,r29,1
	ctx.r5.s64 = ctx.r29.s64 + 1;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823af008
	ctx.lr = 0x822E8D1C;
	sub_823AF008(ctx, base);
loc_822E8D1C:
	// rlwinm. r10,r3,0,24,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// beq 0x822e8d3c
	if (ctx.cr0.eq) goto loc_822E8D3C;
	// rlwinm r11,r9,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
loc_822E8D3C:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// addi r28,r10,12472
	ctx.r28.s64 = ctx.r10.s64 + 12472;
	// lfs f13,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x822e8d5c
	if (!ctx.cr6.eq) goto loc_822E8D5C;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822e8d6c
	if (ctx.cr6.gt) goto loc_822E8D6C;
loc_822E8D5C:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x822e8e68
	if (!ctx.cr6.eq) goto loc_822E8E68;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8ed0
	if (!ctx.cr6.lt) goto loc_822E8ED0;
loc_822E8D6C:
	// lfs f12,-236(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// bge cr6,0x822e8d80
	if (!ctx.cr6.lt) goto loc_822E8D80;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_822E8D80:
	// rlwinm r11,r9,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FFFFFF;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x822e8dbc
	if (!ctx.cr6.eq) goto loc_822E8DBC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822e8e4c
	goto loc_822E8E4C;
loc_822E8DBC:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x822e8e10
	if (!ctx.cr6.eq) goto loc_822E8E10;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-30128(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822e8fd0
	goto loc_822E8FD0;
loc_822E8E10:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822e8ff4
	if (!ctx.cr6.eq) goto loc_822E8FF4;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f13,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// addi r10,r10,32608
	ctx.r10.s64 = ctx.r10.s64 + 32608;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E8E4C:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x822e8fd8
	goto loc_822E8FD8;
loc_822E8E68:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822e8e78
	if (!ctx.cr6.eq) goto loc_822E8E78;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x822e8ed8
	if (ctx.cr6.lt) goto loc_822E8ED8;
loc_822E8E78:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bne cr6,0x822e909c
	if (!ctx.cr6.eq) goto loc_822E909C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x822e8e9c
	if (ctx.cr6.eq) goto loc_822E8E9C;
	// addi r5,r29,-16
	ctx.r5.s64 = ctx.r29.s64 + -16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823af008
	ctx.lr = 0x822E8E9C;
	sub_823AF008(ctx, base);
loc_822E8E9C:
	// rlwinm. r10,r3,0,24,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// bne 0x822e90cc
	if (!ctx.cr0.eq) goto loc_822E90CC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x822e9008
	if (!ctx.cr6.eq) goto loc_822E9008;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bgt cr6,0x822e90c0
	if (ctx.cr6.gt) goto loc_822E90C0;
loc_822E8EC8:
	// bl 0x822e9bd0
	ctx.lr = 0x822E8ECC;
	sub_822E9BD0(ctx, base);
	// b 0x822e90c4
	goto loc_822E90C4;
loc_822E8ED0:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822e8e78
	if (!ctx.cr6.gt) goto loc_822E8E78;
loc_822E8ED8:
	// lfs f12,-236(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// bge cr6,0x822e8eec
	if (!ctx.cr6.lt) goto loc_822E8EEC;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_822E8EEC:
	// rlwinm r11,r9,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FFFFFF;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x822e8f30
	if (!ctx.cr6.eq) goto loc_822E8F30;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r10,32688
	ctx.r10.s64 = ctx.r10.s64 + 32688;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822e8fc8
	goto loc_822E8FC8;
loc_822E8F30:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x822e8f84
	if (!ctx.cr6.eq) goto loc_822E8F84;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r8,32688
	ctx.r11.s64 = ctx.r8.s64 + 32688;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
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
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822e8fd0
	goto loc_822E8FD0;
loc_822E8F84:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822e8ff4
	if (!ctx.cr6.eq) goto loc_822E8FF4;
	// lfs f13,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
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
loc_822E8FC8:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_822E8FD0:
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_822E8FD8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8231e0d8
	ctx.lr = 0x822E8FE4;
	sub_8231E0D8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_822E8FF4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62423
	ctx.r11.u64 = ctx.r11.u64 | 62423;
	// stbx r10,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x822e90cc
	goto loc_822E90CC;
loc_822E9008:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822e90cc
	if (!ctx.cr6.eq) goto loc_822E90CC;
	// lfs f12,-236(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822e9020
	if (!ctx.cr6.lt) goto loc_822E9020;
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_822E9020:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x822e905c
	if (ctx.cr6.eq) goto loc_822E905C;
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// addi r5,r29,1
	ctx.r5.s64 = ctx.r29.s64 + 1;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f10,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fmadds f12,f12,f11,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f10.f64)));
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_822E9054:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823af008
	ctx.lr = 0x822E905C;
	sub_823AF008(ctx, base);
loc_822E905C:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm. r10,r3,0,24,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x822e90cc
	if (!ctx.cr0.eq) goto loc_822E90CC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// beq cr6,0x822e9084
	if (ctx.cr6.eq) goto loc_822E9084;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x822e9880
	ctx.lr = 0x822E9080;
	sub_822E9880(ctx, base);
	// b 0x822e90c4
	goto loc_822E90C4;
loc_822E9084:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r29,1
	ctx.r5.s64 = ctx.r29.s64 + 1;
	// ble cr6,0x822e90bc
	if (!ctx.cr6.gt) goto loc_822E90BC;
	// addi r4,r30,-8
	ctx.r4.s64 = ctx.r30.s64 + -8;
	// b 0x822e8ec8
	goto loc_822E8EC8;
loc_822E909C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822e90cc
	if (!ctx.cr6.eq) goto loc_822E90CC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x822e905c
	if (ctx.cr6.eq) goto loc_822E905C;
	// addi r5,r29,8
	ctx.r5.s64 = ctx.r29.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// b 0x822e9054
	goto loc_822E9054;
loc_822E90BC:
	// addi r4,r30,8
	ctx.r4.s64 = ctx.r30.s64 + 8;
loc_822E90C0:
	// bl 0x822e9d48
	ctx.lr = 0x822E90C4;
	sub_822E9D48(ctx, base);
loc_822E90C4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822e9200
	if (!ctx.cr0.eq) goto loc_822E9200;
loc_822E90CC:
	// ld r31,0(r24)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r24.u32 + 0);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// stw r23,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r23.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stw r23,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r23.u32);
	// stw r23,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r23.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// std r31,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r31.u64);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// std r11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x822e914c
	if (ctx.cr6.eq) goto loc_822E914C;
	// addi r7,r5,16
	ctx.r7.s64 = ctx.r5.s64 + 16;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823af5b0
	ctx.lr = 0x822E914C;
	sub_823AF5B0(ctx, base);
loc_822E914C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822e91fc
	if (ctx.cr0.eq) goto loc_822E91FC;
	// lfs f0,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r31,100(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x822e9190
	if (ctx.cr6.eq) goto loc_822E9190;
	// lfs f0,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x822E9190;
	sub_823AEBD8(ctx, base);
loc_822E9190:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f6,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// add r11,r3,r31
	ctx.r11.u64 = ctx.r3.u64 + ctx.r31.u64;
	// stfs f6,152(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f6,148(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f6,156(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r31,80(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_822E91FC:
	// std r31,0(r24)
	REX_STORE_U64(ctx.r24.u32 + 0, ctx.r31.u64);
loc_822E9200:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82323000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82323008;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r28,r3,260
	ctx.r28.s64 = ctx.r3.s64 + 260;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8232303c
	if (!ctx.cr0.eq) goto loc_8232303C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82323050
	goto loc_82323050;
loc_8232303C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x82323050;
	sub_823BFA70(ctx, base);
loc_82323050:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x823230a0
	if (!ctx.cr6.eq) goto loc_823230A0;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3151
	ctx.r30.s64 = ctx.r30.s64 + -3151;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823230bc
	if (!ctx.cr0.eq) goto loc_823230BC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x82323088;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,205
	ctx.r3.s64 = 205;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d438
	ctx.lr = 0x82323098;
	sub_8257D438(ctx, base);
	// stb r27,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r27.u8);
	// b 0x823230bc
	goto loc_823230BC;
loc_823230A0:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3151
	ctx.r11.s64 = ctx.r11.s64 + -3151;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823230bc
	if (ctx.cr0.eq) goto loc_823230BC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_823230BC:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r29,r29,-3164
	ctx.r29.s64 = ctx.r29.s64 + -3164;
	// addi r26,r11,-9856
	ctx.r26.s64 = ctx.r11.s64 + -9856;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r25,r10,32720
	ctx.r25.s64 = ctx.r10.s64 + 32720;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x82323954
	if (ctx.cr6.gt) goto loc_82323954;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82323150
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82323150;
	// bdzf 4*cr6+eq,0x82323184
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82323184;
	// bdzf 4*cr6+eq,0x823231e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823231E0;
	// bdzf 4*cr6+eq,0x823236c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823236C4;
	// bdzf 4*cr6+eq,0x82323380
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82323380;
	// bdzf 4*cr6+eq,0x82323568
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82323568;
	// bne cr6,0x82323874
	if (!ctx.cr6.eq) goto loc_82323874;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82323954
	if (ctx.cr0.eq) goto loc_82323954;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82323148
	if (ctx.cr0.eq) goto loc_82323148;
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
	ctx.lr = 0x82323148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82323148:
	// stw r27,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r27.u32);
	// b 0x82323954
	goto loc_82323954;
loc_82323150:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f1,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x82323178;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
loc_8232317C:
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82323954
	goto loc_82323954;
loc_82323184:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82323954
	if (!ctx.cr0.eq) goto loc_82323954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323f80
	ctx.lr = 0x823231A0;
	sub_82323F80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323e00
	ctx.lr = 0x823231A8;
	sub_82323E00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f1,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// bne 0x82323864
	if (!ctx.cr0.eq) goto loc_82323864;
loc_823231D0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8224a2a0
	ctx.lr = 0x823231D8;
	sub_8224A2A0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8232317c
	goto loc_8232317C;
loc_823231E0:
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,-31760
	ctx.r9.s64 = ctx.r9.s64 + -31760;
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v0,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f13,-16652(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16652);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8232327c
	if (ctx.cr6.lt) goto loc_8232327C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,17056
	ctx.r11.s64 = ctx.r11.s64 + 17056;
	// lfs f13,-5108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5108);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82323280
	if (!ctx.cr6.gt) goto loc_82323280;
loc_8232327C:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_82323280:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,264(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r7,12236
	ctx.r10.s64 = ctx.r7.s64 + 12236;
	// lfs f30,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82323348
	if (!ctx.cr0.eq) goto loc_82323348;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f30,288(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// bl 0x82323f80
	ctx.lr = 0x823232FC;
	sub_82323F80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323e00
	ctx.lr = 0x82323304;
	sub_82323E00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq 0x82323338
	if (ctx.cr0.eq) goto loc_82323338;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8224a2a0
	ctx.lr = 0x8232332C;
	sub_8224A2A0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82323348
	goto loc_82323348;
loc_82323338:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8224a2a0
	ctx.lr = 0x82323348;
	sub_8224A2A0(ctx, base);
loc_82323348:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323b10
	ctx.lr = 0x82323350;
	sub_82323B10(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82323954
	if (!ctx.cr0.eq) goto loc_82323954;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82323378;
	sub_8224A2A0(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x8232317c
	goto loc_8232317C;
loc_82323380:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x82323394;
	sub_8222FF78(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82323b10
	ctx.lr = 0x823233E4;
	sub_82323B10(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r30,6
	ctx.r30.s64 = 6;
	// beq 0x82323474
	if (ctx.cr0.eq) goto loc_82323474;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r8,12236
	ctx.r8.s64 = ctx.r8.s64 + 12236;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// lfs f13,232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x82323454
	if (ctx.cr6.lt) goto loc_82323454;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82323454:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82323474
	if (ctx.cr0.eq) goto loc_82323474;
	// fabs f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f0,-20276(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -20276);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82323550
	if (ctx.cr6.lt) goto loc_82323550;
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// b 0x82323550
	goto loc_82323550;
loc_82323474:
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f13,-10372(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -10372);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r9,-32080
	ctx.r9.s64 = ctx.r9.s64 + -32080;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v0,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82323508
	if (ctx.cr6.lt) goto loc_82323508;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,17056(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17056);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8232350c
	if (!ctx.cr6.gt) goto loc_8232350C;
loc_82323508:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_8232350C:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
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
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82323550:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323b10
	ctx.lr = 0x82323558;
	sub_82323B10(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82323954
	if (!ctx.cr0.eq) goto loc_82323954;
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// b 0x82323954
	goto loc_82323954;
loc_82323568:
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// ld r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r9,-31776
	ctx.r9.s64 = ctx.r9.s64 + -31776;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lis r3,-32240
	ctx.r3.s64 = -2112880640;
	// addi r3,r3,12236
	ctx.r3.s64 = ctx.r3.s64 + 12236;
	// lfs f1,232(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// blt cr6,0x82323688
	if (ctx.cr6.lt) goto loc_82323688;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82323688:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82323954
	if (ctx.cr0.eq) goto loc_82323954;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f1,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x823236BC;
	sub_8224A2A0(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8232317c
	goto loc_8232317C;
loc_823236C4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82323954
	if (!ctx.cr0.eq) goto loc_82323954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82323f80
	ctx.lr = 0x823236E0;
	sub_82323F80(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8222ff78
	ctx.lr = 0x823236F4;
	sub_8222FF78(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
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
	// lfs f0,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r3,32256
	ctx.r9.s64 = ctx.r3.s64 + 32256;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vsubfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v59,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v6,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v0,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82323b10
	ctx.lr = 0x82323820;
	sub_82323B10(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82323954
	if (ctx.cr0.eq) goto loc_82323954;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,-20940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f1,232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x82323860
	if (ctx.cr6.lt) goto loc_82323860;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x823231d0
	goto loc_823231D0;
loc_82323860:
	// li r5,1
	ctx.r5.s64 = 1;
loc_82323864:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8224a2a0
	ctx.lr = 0x8232386C;
	sub_8224A2A0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8232317c
	goto loc_8232317C;
loc_82323874:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-3156
	ctx.r11.s64 = ctx.r11.s64 + -3156;
	// ori r10,r10,62376
	ctx.r10.u64 = ctx.r10.u64 | 62376;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r8,r9,12236
	ctx.r8.s64 = ctx.r9.s64 + 12236;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfsx f11,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f12,12236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x823238b8
	if (!ctx.cr6.lt) goto loc_823238B8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x823238c4
	goto loc_823238C4;
loc_823238B8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x823238c4
	if (!ctx.cr6.gt) goto loc_823238C4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_823238C4:
	// fsubs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r30,87(r1)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// bne 0x82323924
	if (!ctx.cr0.eq) goto loc_82323924;
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232391c
	if (ctx.cr0.eq) goto loc_8232391C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232391C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8232391C:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82323924:
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82323954;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82323954:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822301e0
	ctx.lr = 0x82323964;
	sub_822301E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823239e0
	if (ctx.cr0.eq) goto loc_823239E0;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,-18952(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -18952);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_823239E0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82376C78) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82376CA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82376d90
	if (ctx.cr0.eq) goto loc_82376D90;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82376d50
	if (!ctx.cr6.eq) goto loc_82376D50;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,240(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
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
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82376d3c
	if (ctx.cr6.eq) goto loc_82376D3C;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	ctx.lr = 0x82376D38;
	sub_823AEFA8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_82376D3C:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,292
	ctx.r4.s64 = ctx.r31.s64 + 292;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fe48
	ctx.lr = 0x82376D4C;
	sub_8235FE48(ctx, base);
	// stw r3,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r3.u32);
loc_82376D50:
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82376d90
	if (ctx.cr6.eq) goto loc_82376D90;
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82376d70
	if (ctx.cr6.eq) goto loc_82376D70;
	// addi r4,r31,292
	ctx.r4.s64 = ctx.r31.s64 + 292;
	// bl 0x823aff18
	ctx.lr = 0x82376D70;
	sub_823AFF18(ctx, base);
loc_82376D70:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82376D84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,288(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// bl 0x823af140
	ctx.lr = 0x82376D90;
	sub_823AF140(ctx, base);
loc_82376D90:
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

DEFINE_REX_FUNC(sub_8237E2A0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8237E2C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8237e34c
	if (ctx.cr0.eq) goto loc_8237E34C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8237E2E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8237e34c
	if (ctx.cr0.eq) goto loc_8237E34C;
	// lbz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 260);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8237e300
	if (ctx.cr0.eq) goto loc_8237E300;
	// addi r3,r31,264
	ctx.r3.s64 = ctx.r31.s64 + 264;
	// bl 0x823665e8
	ctx.lr = 0x8237E2FC;
	sub_823665E8(ctx, base);
	// b 0x8237e34c
	goto loc_8237E34C;
loc_8237E300:
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
	// bne 0x8237e31c
	if (!ctx.cr0.eq) goto loc_8237E31C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8237e324
	goto loc_8237E324;
loc_8237E31C:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8237E324:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,248(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r5,244(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823beba0
	ctx.lr = 0x8237E34C;
	sub_823BEBA0(ctx, base);
loc_8237E34C:
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

DEFINE_REX_FUNC(sub_8237FE98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,24000
	ctx.r3.s64 = ctx.r11.s64 + 24000;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237FF00) {
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
	ctx.lr = 0x8237FF18;
	sub_8235F428(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,24024
	ctx.r10.s64 = ctx.r10.s64 + 24024;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,12468(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// ld r10,3456(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// stb r7,245(r31)
	REX_STORE_U8(ctx.r31.u32 + 245, ctx.r7.u8);
	// lwz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r9.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,244(r31)
	REX_STORE_U8(ctx.r31.u32 + 244, ctx.r11.u8);
	// rlwinm r7,r7,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r11,246(r31)
	REX_STORE_U8(ctx.r31.u32 + 246, ctx.r11.u8);
	// std r10,232(r31)
	REX_STORE_U64(ctx.r31.u32 + 232, ctx.r10.u64);
	// ld r10,3456(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// std r10,248(r31)
	REX_STORE_U64(ctx.r31.u32 + 248, ctx.r10.u64);
	// ld r10,3456(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// stfs f0,264(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 264, temp.u32);
	// stfs f0,268(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 268, temp.u32);
	// stb r11,272(r31)
	REX_STORE_U8(ctx.r31.u32 + 272, ctx.r11.u8);
	// stw r11,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// stb r11,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r11.u8);
	// stb r11,281(r31)
	REX_STORE_U8(ctx.r31.u32 + 281, ctx.r11.u8);
	// std r10,256(r31)
	REX_STORE_U64(ctx.r31.u32 + 256, ctx.r10.u64);
	// stb r11,282(r31)
	REX_STORE_U8(ctx.r31.u32 + 282, ctx.r11.u8);
	// stw r9,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r9.u32);
	// stw r9,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r9.u32);
	// stb r11,292(r31)
	REX_STORE_U8(ctx.r31.u32 + 292, ctx.r11.u8);
	// stb r11,293(r31)
	REX_STORE_U8(ctx.r31.u32 + 293, ctx.r11.u8);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stb r11,300(r31)
	REX_STORE_U8(ctx.r31.u32 + 300, ctx.r11.u8);
	// stb r11,301(r31)
	REX_STORE_U8(ctx.r31.u32 + 301, ctx.r11.u8);
	// stw r7,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
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

DEFINE_REX_FUNC(sub_82384E00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82384E08;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// sth r4,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r4.u16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// sth r5,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r5.u16);
	// rlwinm. r11,r7,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,232(r3)
	REX_STORE_U32(ctx.r3.u32 + 232, ctx.r10.u32);
	// ble 0x82384ee4
	if (!ctx.cr0.gt) goto loc_82384EE4;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r31,r3,236
	ctx.r31.s64 = ctx.r3.s64 + 236;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
	// addi r27,r10,1340
	ctx.r27.s64 = ctx.r10.s64 + 1340;
loc_82384E44:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235fc38
	ctx.lr = 0x82384E50;
	sub_8235FC38(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82384E60;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82384e80
	if (ctx.cr0.eq) goto loc_82384E80;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// sth r11,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r11.u16);
	// b 0x82384e84
	goto loc_82384E84;
loc_82384E80:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82384E84:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384e9c
	if (!ctx.cr6.eq) goto loc_82384E9C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82384ea8
	goto loc_82384EA8;
loc_82384E9C:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_82384EA8:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82384ecc
	if (!ctx.cr6.lt) goto loc_82384ECC;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x82384ed8
	goto loc_82384ED8;
loc_82384ECC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823849b0
	ctx.lr = 0x82384ED8;
	sub_823849B0(ctx, base);
loc_82384ED8:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x82384e44
	if (!ctx.cr0.eq) goto loc_82384E44;
loc_82384EE4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82389870) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 521, ctx.xer);
	// beq cr6,0x823898a8
	if (ctx.cr6.eq) goto loc_823898A8;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x8238988c
	if (ctx.cr6.eq) goto loc_8238988C;
	// b 0x8235f668
	sub_8235F668(ctx, base);
	return;
loc_8238988C:
	// lbz r11,325(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 325);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lbz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// b 0x823898b4
	goto loc_823898B4;
loc_823898A8:
	// lbz r11,325(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 325);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
loc_823898B4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,324(r3)
	REX_STORE_U8(ctx.r3.u32 + 324, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8238AF10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwa r11,268(r3)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 268));
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// std r11,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r11.u64);
	// addi r11,r9,1608
	ctx.r11.s64 = ctx.r9.s64 + 1608;
	// lwa r10,264(r3)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 264));
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// lfs f12,1608(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1608);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,-48
	ctx.r7.s64 = ctx.r1.s64 + -48;
	// addi r9,r1,-48
	ctx.r9.s64 = ctx.r1.s64 + -48;
	// lfs f11,280(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,-48
	ctx.r5.s64 = ctx.r1.s64 + -48;
	// lfd f0,-64(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// std r10,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r10.u64);
	// lfd f13,-64(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// addi r10,r1,-64
	ctx.r10.s64 = ctx.r1.s64 + -64;
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lfs f0,-11852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11852);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,-64
	ctx.r4.s64 = ctx.r1.s64 + -64;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// lfs f13,-18544(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fadds f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// stfs f8,-64(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fsubs f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// stfs f0,-36(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// stfs f0,-40(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f0,-44(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stfs f0,-48(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f8,-52(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f8,-56(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f0,f10,f11
	ctx.f0.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f12,-36(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// stfs f12,-40(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f12,-44(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stfs f12,-48(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,-36(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// stfs f0,-40(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f0,-44(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stfs f0,-48(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-64(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-64(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// lfs f11,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,-60(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,-64(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,308(r3)
	REX_STORE_U64(ctx.r3.u32 + 308, ctx.r11.u64);
	// lfs f0,-48(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-64(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// lfs f12,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-60(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// ld r10,-64(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// std r10,316(r3)
	REX_STORE_U64(ctx.r3.u32 + 316, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82393738) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,27904
	ctx.r3.s64 = ctx.r11.s64 + 27904;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82393B80) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 535, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,252(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,256(r3)
	REX_STORE_U8(ctx.r3.u32 + 256, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82394510) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82394568
	if (ctx.cr6.eq) goto loc_82394568;
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// lwz r10,16(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x8239454c
	if (!ctx.cr0.lt) goto loc_8239454C;
	// lbz r11,234(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 234);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x82394554
	goto loc_82394554;
loc_8239454C:
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_82394554:
	// lwz r9,272(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// stw r10,272(r3)
	REX_STORE_U32(ctx.r3.u32 + 272, ctx.r10.u32);
	// b 0x82394588
	goto loc_82394588;
loc_82394568:
	// lwz r10,272(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r10,234(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 234);
	// stw r11,272(r3)
	REX_STORE_U32(ctx.r3.u32 + 272, ctx.r11.u32);
	// cntlzw r11,r10
	ctx.r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_82394588:
	// stb r11,252(r3)
	REX_STORE_U8(ctx.r3.u32 + 252, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82399888) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f1,384(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 384);
	ctx.f1.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x822ea1a8
	ctx.lr = 0x823998AC;
	sub_822EA1A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r3,-12852(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -12852);
	// lfs f0,1656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// fnmsubs f31,f1,f0,f13
	ctx.f31.f64 = double(float(-std::fma(ctx.f1.f64, ctx.f0.f64, -ctx.f13.f64)));
	// beq cr6,0x8239992c
	if (ctx.cr6.eq) goto loc_8239992C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bl 0x8257c3f0
	ctx.lr = 0x823998E4;
	sub_8257C3F0(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257cce0
	ctx.lr = 0x823998EC;
	sub_8257CCE0(ctx, base);
	// lwz r11,-12852(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8239992c
	if (ctx.cr6.eq) goto loc_8239992C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82399910
	if (ctx.cr6.eq) goto loc_82399910;
	// lfs f1,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82399918
	goto loc_82399918;
loc_82399910:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f1,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f1.f64 = double(temp.f32);
loc_82399918:
	// addi r4,r30,336
	ctx.r4.s64 = ctx.r30.s64 + 336;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257c728
	ctx.lr = 0x82399924;
	sub_8257C728(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257c278
	ctx.lr = 0x8239992C;
	sub_8257C278(ctx, base);
loc_8239992C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

DEFINE_REX_FUNC(sub_823A11A8) {
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
	ctx.lr = 0x823A11C0;
	sub_8235F428(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r9,2
	ctx.r9.s64 = 2;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,29632
	ctx.r8.s64 = ctx.r8.s64 + 29632;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stfs f0,232(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// addi r11,r31,232
	ctx.r11.s64 = ctx.r31.s64 + 232;
	// stb r10,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r10.u8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
loc_823A11F8:
	// stfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stb r10,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r10.u8);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// ld r7,3456(r8)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// std r7,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r7.u64);
	// ld r7,3456(r8)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// stdu r7,40(r11)
	ea = 40 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r7.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x823a11f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823A11F8;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stfs f0,328(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// stb r10,320(r31)
	REX_STORE_U8(ctx.r31.u32 + 320, ctx.r10.u8);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// stw r10,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r10,340(r31)
	REX_STORE_U8(ctx.r31.u32 + 340, ctx.r10.u8);
	// stb r10,341(r31)
	REX_STORE_U8(ctx.r31.u32 + 341, ctx.r10.u8);
	// stb r10,348(r31)
	REX_STORE_U8(ctx.r31.u32 + 348, ctx.r10.u8);
	// stb r10,349(r31)
	REX_STORE_U8(ctx.r31.u32 + 349, ctx.r10.u8);
	// stw r10,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r10.u32);
	// stw r10,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r10.u32);
	// stw r10,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r10.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r9,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r9.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_823A8B18) {
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
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,516
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 516, ctx.xer);
	// beq cr6,0x823a8b60
	if (ctx.cr6.eq) goto loc_823A8B60;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x823a8b44
	if (ctx.cr6.eq) goto loc_823A8B44;
	// bl 0x8235f668
	ctx.lr = 0x823A8B40;
	sub_8235F668(ctx, base);
	// b 0x823a8b74
	goto loc_823A8B74;
loc_823A8B44:
	// lbz r11,244(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 244);
	// lbz r10,20(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823a8b74
	if (ctx.cr6.eq) goto loc_823A8B74;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,260(r3)
	REX_STORE_U8(ctx.r3.u32 + 260, ctx.r11.u8);
	// b 0x823a8b74
	goto loc_823A8B74;
loc_823A8B60:
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,340
	ctx.r3.s64 = ctx.r3.s64 + 340;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8237fdd0
	ctx.lr = 0x823A8B74;
	sub_8237FDD0(ctx, base);
loc_823A8B74:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823ABAA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823ABAA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r3,284
	ctx.r3.s64 = ctx.r3.s64 + 284;
	// addi r11,r11,30896
	ctx.r11.s64 = ctx.r11.s64 + 30896;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x8245d0d8
	ctx.lr = 0x823ABAC4;
	sub_8245D0D8(ctx, base);
	// addi r3,r31,300
	ctx.r3.s64 = ctx.r31.s64 + 300;
	// bl 0x8245d0d8
	ctx.lr = 0x823ABACC;
	sub_8245D0D8(ctx, base);
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823edfb8
	ctx.lr = 0x823ABAD8;
	sub_823EDFB8(ctx, base);
	// addi r29,r31,320
	ctx.r29.s64 = ctx.r31.s64 + 320;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823edfb8
	ctx.lr = 0x823ABAE4;
	sub_823EDFB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823edfb8
	ctx.lr = 0x823ABAEC;
	sub_823EDFB8(ctx, base);
	// lwz r3,352(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823abafc
	if (ctx.cr6.eq) goto loc_823ABAFC;
	// bl 0x825e0378
	ctx.lr = 0x823ABAFC;
	sub_825E0378(ctx, base);
loc_823ABAFC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823edfb8
	ctx.lr = 0x823ABB04;
	sub_823EDFB8(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823abb14
	if (ctx.cr6.eq) goto loc_823ABB14;
	// bl 0x825e0378
	ctx.lr = 0x823ABB14;
	sub_825E0378(ctx, base);
loc_823ABB14:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r31,316
	ctx.r30.s64 = ctx.r31.s64 + 316;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r28,r11,-27424
	ctx.r28.s64 = ctx.r11.s64 + -27424;
loc_823ABB24:
	// stwu r28,-16(r30)
	ea = -16 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d0d8
	ctx.lr = 0x823ABB30;
	sub_8245D0D8(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x823abb24
	if (!ctx.cr0.lt) goto loc_823ABB24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235f568
	ctx.lr = 0x823ABB40;
	sub_8235F568(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823AF5B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x823AF5B8;
	__savegprlr_14(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// subf r28,r4,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r4.u64;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// lwz r16,-13032(r11)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// andi. r15,r8,11
	ctx.r15.u64 = ctx.r8.u64 & 11;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// rlwinm r14,r8,0,22,23
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x300;
	// subf r27,r5,r7
	ctx.r27.u64 = ctx.r7.u64 - ctx.r5.u64;
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// bge cr6,0x823af5f0
	if (!ctx.cr6.lt) goto loc_823AF5F0;
	// li r25,-1
	ctx.r25.s64 = -1;
	// b 0x823af600
	goto loc_823AF600;
loc_823AF5F0:
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// li r25,1
	ctx.r25.s64 = 1;
	// bgt cr6,0x823af600
	if (ctx.cr6.gt) goto loc_823AF600;
	// mr r25,r28
	ctx.r25.u64 = ctx.r28.u64;
loc_823AF600:
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// bge cr6,0x823af610
	if (!ctx.cr6.lt) goto loc_823AF610;
	// li r26,-1
	ctx.r26.s64 = -1;
	// b 0x823af620
	goto loc_823AF620;
loc_823AF610:
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// li r26,1
	ctx.r26.s64 = 1;
	// bgt cr6,0x823af620
	if (ctx.cr6.gt) goto loc_823AF620;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
loc_823AF620:
	// li r20,0
	ctx.r20.s64 = 0;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x823af644
	if (ctx.cr6.eq) goto loc_823AF644;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x823af644
	if (ctx.cr6.eq) goto loc_823AF644;
	// mullw. r11,r27,r28
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r28.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r20,-1
	ctx.r20.s64 = -1;
	// blt 0x823af644
	if (ctx.cr0.lt) goto loc_823AF644;
	// li r20,1
	ctx.r20.s64 = 1;
loc_823AF644:
	// extsw r11,r22
	ctx.r11.s64 = ctx.r22.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r8,r21
	ctx.r8.s64 = ctx.r21.s32;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r17,-1
	ctx.r17.s64 = -1;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r24,0
	ctx.r24.s64 = 0;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r23,0
	ctx.r23.s64 = 0;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r19,r17
	ctx.r19.u64 = ctx.r17.u64;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_823AF74C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x823aefa8
	ctx.lr = 0x823AF75C;
	sub_823AEFA8(ctx, base);
	// clrlwi r29,r3,24
	ctx.r29.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r29,r24
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x823af7e4
	if (ctx.cr6.eq) goto loc_823AF7E4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823af7e4
	if (ctx.cr6.eq) goto loc_823AF7E4;
	// cmpwi cr6,r19,-1
	ctx.cr6.compare<int32_t>(ctx.r19.s32, -1, ctx.xer);
	// bne cr6,0x823afa1c
	if (!ctx.cr6.eq) goto loc_823AFA1C;
	// cmplwi cr6,r14,256
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 256, ctx.xer);
	// beq cr6,0x823af7e0
	if (ctx.cr6.eq) goto loc_823AF7E0;
	// mr r8,r15
	ctx.r8.u64 = ctx.r15.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x823afa38
	ctx.lr = 0x823AF79C;
	sub_823AFA38(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823af7d0
	if (!ctx.cr0.eq) goto loc_823AF7D0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x823af7e0
	if (!ctx.cr6.eq) goto loc_823AF7E0;
	// mr r8,r15
	ctx.r8.u64 = ctx.r15.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x823afa38
	ctx.lr = 0x823AF7C8;
	sub_823AFA38(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823af7e0
	if (ctx.cr0.eq) goto loc_823AF7E0;
loc_823AF7D0:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r19,32(r18)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r18.u32 + 32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x823afa24
	if (ctx.cr6.eq) goto loc_823AFA24;
loc_823AF7E0:
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
loc_823AF7E4:
	// cmplwi cr6,r14,512
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 512, ctx.xer);
	// beq cr6,0x823af80c
	if (ctx.cr6.eq) goto loc_823AF80C;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x823af008
	ctx.lr = 0x823AF7FC;
	sub_823AF008(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r15,24
	ctx.r10.u64 = ctx.r15.u32 & 0xFF;
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823af958
	if (!ctx.cr0.eq) goto loc_823AF958;
loc_823AF80C:
	// clrlwi. r11,r23,24
	ctx.r11.u64 = ctx.r23.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823afa24
	if (!ctx.cr0.eq) goto loc_823AFA24;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x823af8f4
	if (ctx.cr6.eq) goto loc_823AF8F4;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x823af8f4
	if (ctx.cr6.eq) goto loc_823AF8F4;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// blt cr6,0x823af834
	if (ctx.cr6.lt) goto loc_823AF834;
	// subfic r11,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r11.u64 = static_cast<uint64_t>(15) - ctx.r11.u64;
loc_823AF834:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// clrlwi r11,r31,28
	ctx.r11.u64 = ctx.r31.u32 & 0xF;
	// blt cr6,0x823af848
	if (ctx.cr6.lt) goto loc_823AF848;
	// subfic r11,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r11.u64 = static_cast<uint64_t>(15) - ctx.r11.u64;
loc_823AF848:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mullw r10,r8,r20
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r20.s32);
	// mullw r9,r11,r20
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r20.s32);
	// mullw r5,r9,r28
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// mullw r4,r10,r27
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r27.s32);
	// rotlwi r7,r5,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// rotlwi r6,r4,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// divw r5,r5,r27
	ctx.r5.u64 = uint32_t((ctx.r27.s32 && !(ctx.r5.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r5.s32 / ctx.r27.s32 : 0);
	// andc r7,r27,r7
	ctx.r7.u64 = ctx.r27.u64 & ~ctx.r7.u64;
	// divw r4,r4,r28
	ctx.r4.u64 = uint32_t((ctx.r28.s32 && !(ctx.r4.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r4.s32 / ctx.r28.s32 : 0);
	// andc r6,r28,r6
	ctx.r6.u64 = ctx.r28.u64 & ~ctx.r6.u64;
	// twllei r27,0
	if (ctx.r27.s32 == 0 || ctx.r27.u32 < 0u) ppc_trap(ctx, base, 0);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// twlgei r7,-1
	if (ctx.r7.s32 == -1 || ctx.r7.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twlgei r6,-1
	if (ctx.r6.s32 == -1 || ctx.r6.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x823af8c4
	if (!ctx.cr6.lt) goto loc_823AF8C4;
	// mullw r11,r10,r26
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// mullw r9,r11,r27
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// rotlwi r11,r9,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r10,r8,r25
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r25.s32);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// divw r11,r9,r28
	ctx.r11.u64 = uint32_t((ctx.r28.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r9.s32 / ctx.r28.s32 : 0);
	// andc r9,r28,r8
	ctx.r9.u64 = ctx.r28.u64 & ~ctx.r8.u64;
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// twlgei r9,-1
	if (ctx.r9.s32 == -1 || ctx.r9.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// b 0x823af904
	goto loc_823AF904;
loc_823AF8C4:
	// mullw r10,r9,r25
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r25.s32);
	// mullw r9,r10,r28
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r28.s32);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r11,r11,r26
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// divw r10,r9,r27
	ctx.r10.u64 = uint32_t((ctx.r27.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r9.s32 / ctx.r27.s32 : 0);
	// andc r9,r27,r8
	ctx.r9.u64 = ctx.r27.u64 & ~ctx.r8.u64;
	// twllei r27,0
	if (ctx.r27.s32 == 0 || ctx.r27.u32 < 0u) ppc_trap(ctx, base, 0);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// twlgei r9,-1
	if (ctx.r9.s32 == -1 || ctx.r9.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// b 0x823af904
	goto loc_823AF904;
loc_823AF8F4:
	// rlwinm r11,r25,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r26,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
loc_823AF904:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x823af918
	if (!ctx.cr6.lt) goto loc_823AF918;
	// cmpw cr6,r30,r22
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r22.s32, ctx.xer);
	// blt cr6,0x823af924
	if (ctx.cr6.lt) goto loc_823AF924;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
loc_823AF918:
	// ble cr6,0x823af92c
	if (!ctx.cr6.gt) goto loc_823AF92C;
	// cmpw cr6,r30,r22
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x823af92c
	if (!ctx.cr6.gt) goto loc_823AF92C;
loc_823AF924:
	// li r23,1
	ctx.r23.s64 = 1;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
loc_823AF92C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge cr6,0x823af940
	if (!ctx.cr6.lt) goto loc_823AF940;
	// cmpw cr6,r31,r21
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r21.s32, ctx.xer);
	// blt cr6,0x823af94c
	if (ctx.cr6.lt) goto loc_823AF94C;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
loc_823AF940:
	// ble cr6,0x823af74c
	if (!ctx.cr6.gt) goto loc_823AF74C;
	// cmpw cr6,r31,r21
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x823af74c
	if (!ctx.cr6.gt) goto loc_823AF74C;
loc_823AF94C:
	// li r23,1
	ctx.r23.s64 = 1;
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
	// b 0x823af74c
	goto loc_823AF74C;
loc_823AF958:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// extsw r10,r30
	ctx.r10.s64 = ctx.r30.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// bl 0x8223e420
	ctx.lr = 0x823AF9DC;
	sub_8223E420(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// cmpwi cr6,r19,-1
	ctx.cr6.compare<int32_t>(ctx.r19.s32, -1, ctx.xer);
	// beq cr6,0x823af9fc
	if (ctx.cr6.eq) goto loc_823AF9FC;
	// lvx128 v63,r18,r11
	ea = (ctx.r18.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v1.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r10,r10,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823afa1c
	if (ctx.cr0.eq) goto loc_823AFA1C;
loc_823AF9FC:
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// stvx128 v1,r18,r11
	ea = (ctx.r18.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r9.u32);
	// stw r8,4(r18)
	REX_STORE_U32(ctx.r18.u32 + 4, ctx.r8.u32);
	// stw r17,32(r18)
	REX_STORE_U32(ctx.r18.u32 + 32, ctx.r17.u32);
	// std r10,8(r18)
	REX_STORE_U64(ctx.r18.u32 + 8, ctx.r10.u64);
loc_823AFA1C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823afa30
	goto loc_823AFA30;
loc_823AFA24:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823AFA30:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CE970) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823CE978;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823cc338
	ctx.lr = 0x823CE994;
	sub_823CC338(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ce9b4
	if (ctx.cr0.eq) goto loc_823CE9B4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x823ce9b4
	if (ctx.cr6.eq) goto loc_823CE9B4;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
loc_823CE9B4:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x823cc338
	ctx.lr = 0x823CE9C0;
	sub_823CC338(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ce9e0
	if (ctx.cr0.eq) goto loc_823CE9E0;
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x823ce9e0
	if (ctx.cr6.eq) goto loc_823CE9E0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_823CE9E0:
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823cc338
	ctx.lr = 0x823CE9EC;
	sub_823CC338(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823cea0c
	if (ctx.cr0.eq) goto loc_823CEA0C;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x823cea0c
	if (ctx.cr6.eq) goto loc_823CEA0C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
loc_823CEA0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D1038) {
	REX_FUNC_PROLOGUE();
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r10,197(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 197);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r4,188(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 188);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x823c60b0
	sub_823C60B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D2680) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823d2e00
	sub_823D2E00(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D2F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823D2F20;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af28
	ctx.lr = 0x823D2F28;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,27
	ctx.r10.s64 = 27;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823D2F3C:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,132(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 132);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823d2f3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D2F3C;
	// lbz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 132);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d311c
	if (ctx.cr0.eq) goto loc_823D311C;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r30,128(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r9,r10,12472
	ctx.r9.s64 = ctx.r10.s64 + 12472;
	// addi r28,r11,18652
	ctx.r28.s64 = ctx.r11.s64 + 18652;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// lfs f31,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f31.f64 = double(temp.f32);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// lfs f28,-236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -236);
	ctx.f28.f64 = double(temp.f32);
	// lfs f30,28376(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 28376);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,1996(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1996);
	ctx.f29.f64 = double(temp.f32);
	// bgt cr6,0x823d3020
	if (ctx.cr6.gt) goto loc_823D3020;
	// bl 0x82213210
	ctx.lr = 0x823D2F8C;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// li r8,58
	ctx.r8.s64 = 58;
	// lwz r9,-12972(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + -12972);
	// li r7,59
	ctx.r7.s64 = 59;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// li r6,60
	ctx.r6.s64 = 60;
	// stw r7,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// li r8,61
	ctx.r8.s64 = 61;
	// lbzx r11,r11,r30
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// li r7,63
	ctx.r7.s64 = 63;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// stw r8,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// li r5,62
	ctx.r5.s64 = 62;
	// li r8,64
	ctx.r8.s64 = 64;
	// li r6,65
	ctx.r6.s64 = 65;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// li r7,66
	ctx.r7.s64 = 66;
	// stw r8,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// stw r6,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r6.u32);
	// stw r7,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r11,r11,98
	ctx.r11.s64 = ctx.r11.s64 + 98;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d3020
	if (ctx.cr6.eq) goto loc_823D3020;
	// lwz r5,120(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// fmr f5,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823D3020;
	sub_823C5A58(ctx, base);
loc_823D3020:
	// lwz r11,-12972(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12972);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,620(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 620);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d3050
	if (ctx.cr6.eq) goto loc_823D3050;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,120(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823D3050;
	sub_823C5A58(ctx, base);
loc_823D3050:
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x823c8528
	ctx.lr = 0x823D3058;
	sub_823C8528(ctx, base);
	// lwz r3,112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// bl 0x823c7450
	ctx.lr = 0x823D3060;
	sub_823C7450(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,16240
	ctx.r11.s64 = ctx.r11.s64 + 16240;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r28,r11,-30132
	ctx.r28.s64 = ctx.r11.s64 + -30132;
	// lfs f29,3336(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3336);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,-30132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30132);
	ctx.f30.f64 = double(temp.f32);
loc_823D3088:
	// bl 0x82213210
	ctx.lr = 0x823D308C;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// lfsu f0,4(r29)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r29.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r29.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,120(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fsubs f3,f0,f30
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lbzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823cba60
	ctx.lr = 0x823D30B8;
	sub_823CBA60(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,108(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r11.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x823c67c0
	ctx.lr = 0x823D30D4;
	sub_823C67C0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 9, ctx.xer);
	// blt cr6,0x823d3088
	if (ctx.cr6.lt) goto loc_823D3088;
	// li r9,12
	ctx.r9.s64 = 12;
	// addi r10,r28,-20584
	ctx.r10.s64 = ctx.r28.s64 + -20584;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823D30F4:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lwz r8,128(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
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
	// bdnz 0x823d30f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823D30F4;
loc_823D311C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af74
	ctx.lr = 0x823D3128;
	__restfpr_28(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E46F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823E46F8;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r29,r5,18,14,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 18) & 0x3FFFC;
	// addi r30,r11,17432
	ctx.r30.s64 = ctx.r11.s64 + 17432;
	// clrlwi r31,r5,16
	ctx.r31.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwzx r11,r29,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// add. r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e4744
	if (ctx.cr0.eq) goto loc_823E4744;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823b5fe8
	ctx.lr = 0x823E4738;
	sub_823B5FE8(ctx, base);
	// neg r11,r3
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// andc r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r3.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
loc_823E4744:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e47c8
	if (ctx.cr0.eq) goto loc_823E47C8;
	// lwzx r11,r29,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// add. r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e47c8
	if (ctx.cr0.eq) goto loc_823E47C8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823ea418
	ctx.lr = 0x823E4760;
	sub_823EA418(ctx, base);
	// li r11,100
	ctx.r11.s64 = 100;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r9,1000
	ctx.r9.s64 = 1000;
	// li r11,3000
	ctx.r11.s64 = 3000;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bgt 0x823e4790
	if (ctx.cr0.gt) goto loc_823E4790;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x823e47b8
	goto loc_823E47B8;
loc_823E4790:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_823E4798:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r3,r9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x823e47b4
	if (!ctx.cr6.gt) goto loc_823E47B4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x823e4798
	if (ctx.cr6.lt) goto loc_823E4798;
loc_823E47B4:
	// subfic r6,r11,5
	ctx.xer.ca = ctx.r11.u32 <= 5;
	ctx.r6.u64 = static_cast<uint64_t>(5) - ctx.r11.u64;
loc_823E47B8:
	// li r5,664
	ctx.r5.s64 = 664;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823e44a0
	ctx.lr = 0x823E47C8;
	sub_823E44A0(ctx, base);
loc_823E47C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EA2A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823EA2A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r4.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,296(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// li r28,12
	ctx.r28.s64 = 12;
	// bgt cr6,0x823ea2c8
	if (ctx.cr6.gt) goto loc_823EA2C8;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_823EA2C8:
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r30,120
	ctx.r29.s64 = ctx.r30.s64 + 120;
loc_823EA2D0:
	// cmpw cr6,r31,r28
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x823ea2f8
	if (!ctx.cr6.lt) goto loc_823EA2F8;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,304(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 304);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823cc4c8
	ctx.lr = 0x823EA2F4;
	sub_823CC4C8(ctx, base);
	// b 0x823ea300
	goto loc_823EA300;
loc_823EA2F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
loc_823EA300:
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
	ctx.lr = 0x823EA324;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,12
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 12, ctx.xer);
	// blt cr6,0x823ea2d0
	if (ctx.cr6.lt) goto loc_823EA2D0;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EDDA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823EDDB0;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3855
	ctx.r11.s64 = 252641280;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r31,r11,3855
	ctx.r31.u64 = ctx.r11.u64 | 3855;
	// li r26,1
	ctx.r26.s64 = 1;
	// subf r11,r10,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x823ede18
	if (!ctx.cr6.lt) goto loc_823EDE18;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,632
	ctx.r4.s64 = ctx.r11.s64 + 632;
	// bl 0x822167f8
	ctx.lr = 0x823EDDE4;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x823EDDF0;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x823EDDF4;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x823EDE08;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x823EDE18;
	sub_8235EC48(ctx, base);
loc_823EDE18:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x823ede2c
	if (!ctx.cr6.lt) goto loc_823EDE2C;
	// li r10,8
	ctx.r10.s64 = 8;
loc_823EDE2C:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x823ede44
	if (!ctx.cr6.gt) goto loc_823EDE44;
	// subf r9,r10,r31
	ctx.r9.u64 = ctx.r31.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x823ede44
	if (ctx.cr6.gt) goto loc_823EDE44;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
loc_823EDE44:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r29,24(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823EDE64;
	sub_825E02A0(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r31,r29,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r31,r3
	ctx.r3.u64 = ctx.r31.u64 + ctx.r3.u64;
	// subf r10,r5,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r6,r3
	ctx.r28.u64 = ctx.r6.u64 + ctx.r3.u64;
	// beq 0x823edea0
	if (ctx.cr0.eq) goto loc_823EDEA0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x823EDEA0;
	sub_827388E8(ctx, base);
loc_823EDEA0:
	// lwz r5,16(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x823edf1c
	if (ctx.cr6.gt) goto loc_823EDF1C;
	// subf r11,r5,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r5.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r28
	ctx.r31.u64 = ctx.r6.u64 + ctx.r28.u64;
	// beq 0x823eded0
	if (ctx.cr0.eq) goto loc_823EDED0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827388e8
	ctx.lr = 0x823EDED0;
	sub_827388E8(ctx, base);
loc_823EDED0:
	// subf. r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823edef4
	if (ctx.cr0.eq) goto loc_823EDEF4;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823edef4
	if (ctx.cr0.eq) goto loc_823EDEF4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823EDEEC:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823edeec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823EDEEC;
loc_823EDEF4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823edf90
	if (ctx.cr6.eq) goto loc_823EDF90;
	// addi r11,r27,-4
	ctx.r11.s64 = ctx.r27.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x823edf90
	if (ctx.cr0.eq) goto loc_823EDF90;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_823EDF10:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x823edf10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823EDF10;
	// b 0x823edf90
	goto loc_823EDF90;
loc_823EDF1C:
	// rlwinm r29,r26,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r5,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r5.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823edf40
	if (ctx.cr0.eq) goto loc_823EDF40;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x827388e8
	ctx.lr = 0x823EDF40;
	sub_827388E8(ctx, base);
loc_823EDF40:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// add r5,r29,r11
	ctx.r5.u64 = ctx.r29.u64 + ctx.r11.u64;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r27
	ctx.r31.u64 = ctx.r6.u64 + ctx.r27.u64;
	// beq 0x823edf6c
	if (ctx.cr0.eq) goto loc_823EDF6C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827388e8
	ctx.lr = 0x823EDF6C;
	sub_827388E8(ctx, base);
loc_823EDF6C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x823edf90
	if (ctx.cr6.eq) goto loc_823EDF90;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi r26,0
	ctx.cr0.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq 0x823edf90
	if (ctx.cr0.eq) goto loc_823EDF90;
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
loc_823EDF88:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x823edf88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823EDF88;
loc_823EDF90:
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823edfa0
	if (ctx.cr6.eq) goto loc_823EDFA0;
	// bl 0x825e0378
	ctx.lr = 0x823EDFA0;
	sub_825E0378(ctx, base);
loc_823EDFA0:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r27,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r27.u32);
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FAD38) {
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
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// bl 0x823f9a28
	ctx.lr = 0x823FAD54;
	sub_823F9A28(ctx, base);
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lbz r10,977(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 977);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823fad98
	if (ctx.cr0.eq) goto loc_823FAD98;
	// lwz r10,160(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r9,980(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 980);
	// lbz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 12);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r10,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r11,r11,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC;
	// subfe r10,r10,r9
	temp.u8 = (~ctx.r10.u32 + ctx.r9.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r31)
	REX_STORE_U64(ctx.r31.u32 + 136, ctx.r11.u64);
loc_823FAD98:
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

DEFINE_REX_FUNC(sub_823FF300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823FF308;
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
	// li r10,18
	ctx.r10.s64 = 18;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823FF328:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,108(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 108);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823ff328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823FF328;
	// lbz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 108);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823ff68c
	if (ctx.cr0.eq) goto loc_823FF68C;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lbz r7,112(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r27,r10,2500
	ctx.r27.s64 = ctx.r10.s64 + 2500;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r10,r27,-1320
	ctx.r10.s64 = ctx.r27.s64 + -1320;
	// stb r7,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r7.u8);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lbz r7,112(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// stb r7,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r7.u8);
loc_823FF370:
	// lwz r7,100(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r9,5
	ctx.r9.s64 = 5;
	// subfc r6,r7,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r7.u32;
	ctx.r6.u64 = ctx.r11.u64 - ctx.r7.u64;
	// eqv r7,r7,r11
	ctx.r7.u64 = ~(ctx.r7.u64 ^ ctx.r11.u64);
	// rlwinm r7,r7,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addze r9,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r9.s64 = temp.s64;
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
loc_823FF390:
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r7,r31
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// stb r9,14(r7)
	REX_STORE_U8(ctx.r7.u32 + 14, ctx.r9.u8);
	// bdnz 0x823ff390
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823FF390;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x823ff370
	if (!ctx.cr0.eq) goto loc_823FF370;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r26,r11,-25236
	ctx.r26.s64 = ctx.r11.s64 + -25236;
	// addi r9,r10,12472
	ctx.r9.s64 = ctx.r10.s64 + 12472;
	// lwz r11,-12972(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -12972);
	// lfs f31,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,-236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -236);
	ctx.f30.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,540(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 540);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823ff400
	if (ctx.cr6.eq) goto loc_823FF400;
	// lfs f3,14744(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lfs f2,12888(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 12888);
	ctx.f2.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823FF400;
	sub_823C5A58(ctx, base);
loc_823FF400:
	// lwz r11,-12972(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -12972);
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,544(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 544);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823ff434
	if (ctx.cr6.eq) goto loc_823FF434;
	// lfs f2,-18916(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -18916);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lfs f3,14744(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823FF434;
	sub_823C5A58(ctx, base);
loc_823FF434:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,92(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,892(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 892);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d130
	ctx.lr = 0x823FF468;
	sub_8245D130(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r29,r11,1612
	ctx.r29.s64 = ctx.r11.s64 + 1612;
	// lfs f30,17040(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 17040);
	ctx.f30.f64 = double(temp.f32);
	// bne 0x823ff514
	if (!ctx.cr0.eq) goto loc_823FF514;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d190
	ctx.lr = 0x823FF484;
	sub_8245D190(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823ff514
	if (ctx.cr0.eq) goto loc_823FF514;
	// lfs f0,-18916(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -18916);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// fadds f29,f0,f13
	ctx.f29.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// lfs f3,-20940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823FF4B8;
	sub_823C5A58(ctx, base);
	// lwz r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// fctiwz f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f29.f64) ? int64_t(0x80000000U) : (ctx.f29.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f29.f64));
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// addi r9,r8,400
	ctx.r9.s64 = ctx.r8.s64 + 400;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// lwz r6,84(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
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
	// bl 0x823c66e8
	ctx.lr = 0x823FF514;
	sub_823C66E8(ctx, base);
loc_823FF514:
	// lwz r11,-12972(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -12972);
	// li r23,1
	ctx.r23.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r24,428(r11)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x823ff638
	if (ctx.cr6.eq) goto loc_823FF638;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f0,-76(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -76);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-18904
	ctx.r10.s64 = ctx.r10.s64 + -18904;
	// addi r25,r11,-18616
	ctx.r25.s64 = ctx.r11.s64 + -18616;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lfs f12,120(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// li r29,2
	ctx.r29.s64 = 2;
	// lfs f11,124(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f12,128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,132(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r26,-1
	ctx.r26.s64 = -1;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r27,r11,-10736
	ctx.r27.s64 = ctx.r11.s64 + -10736;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
loc_823FF58C:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r8,r30,8
	ctx.r8.s64 = ctx.r30.s64 + 8;
	// stb r23,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r23.u8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823FF5B4;
	sub_823C5C80(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// bne 0x823ff58c
	if (!ctx.cr0.eq) goto loc_823FF58C;
	// lbz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823ff638
	if (ctx.cr0.eq) goto loc_823FF638;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r30,r25,32
	ctx.r30.s64 = ctx.r25.s64 + 32;
	// lfs f0,3424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3328(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1576);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
loc_823FF600:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r5,84(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// addi r8,r30,8
	ctx.r8.s64 = ctx.r30.s64 + 8;
	// stb r23,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r23.u8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823FF628;
	sub_823C5C80(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// bne 0x823ff600
	if (!ctx.cr0.eq) goto loc_823FF600;
loc_823FF638:
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x823c8528
	ctx.lr = 0x823FF640;
	sub_823C8528(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x823cb3a8
	ctx.lr = 0x823FF648;
	sub_823CB3A8(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// neg r9,r11
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// andc r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r11.u64;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// ble cr6,0x823ff674
	if (!ctx.cr6.gt) goto loc_823FF674;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// blt cr6,0x823ff678
	if (ctx.cr6.lt) goto loc_823FF678;
loc_823FF674:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823FF678:
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// stb r9,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r9.u8);
	// stb r11,9(r10)
	REX_STORE_U8(ctx.r10.u32 + 9, ctx.r11.u8);
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x823c7450
	ctx.lr = 0x823FF68C;
	sub_823C7450(ctx, base);
loc_823FF68C:
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

DEFINE_REX_FUNC(sub_8241FB60) {
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
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r11,177(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 177);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241fbb8
	if (ctx.cr0.eq) goto loc_8241FBB8;
	// lwz r4,168(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c60b0
	ctx.lr = 0x8241FB8C;
	sub_823C60B0(ctx, base);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241fbb8
	if (ctx.cr6.eq) goto loc_8241FBB8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8241fbb8
	if (ctx.cr6.eq) goto loc_8241FBB8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x8241fbb8
	if (!ctx.cr6.gt) goto loc_8241FBB8;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c8690
	ctx.lr = 0x8241FBB8;
	sub_823C8690(ctx, base);
loc_8241FBB8:
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

DEFINE_REX_FUNC(sub_82425338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82425340;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,492(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 492);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r28,452(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 452);
	// lwz r27,456(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// bl 0x82213210
	ctx.lr = 0x82425358;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x82425368;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824253a8
	if (ctx.cr0.eq) goto loc_824253A8;
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,452(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,115
	ctx.r11.s64 = ctx.r11.s64 + 115;
	// lwz r8,504(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r10,496(r31)
	REX_STORE_U8(ctx.r31.u32 + 496, ctx.r10.u8);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// bl 0x82425290
	ctx.lr = 0x824253A0;
	sub_82425290(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x824256f0
	goto loc_824256F0;
loc_824253A8:
	// bl 0x82213210
	ctx.lr = 0x824253AC;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x824253BC;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824253dc
	if (ctx.cr0.eq) goto loc_824253DC;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,496(r31)
	REX_STORE_U8(ctx.r31.u32 + 496, ctx.r11.u8);
	// bl 0x82425290
	ctx.lr = 0x824253D4;
	sub_82425290(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824256f0
	goto loc_824256F0;
loc_824253DC:
	// bl 0x82213210
	ctx.lr = 0x824253E0;
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
	ctx.lr = 0x824253F4;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82425408
	if (!ctx.cr0.eq) goto loc_82425408;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d5f8
	ctx.lr = 0x82425408;
	sub_8242D5F8(ctx, base);
loc_82425408:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824254fc
	if (ctx.cr0.eq) goto loc_824254FC;
	// bl 0x82213210
	ctx.lr = 0x82425414;
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
	ctx.lr = 0x82425428;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242543c
	if (!ctx.cr0.eq) goto loc_8242543C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d6e8
	ctx.lr = 0x8242543C;
	sub_8242D6E8(ctx, base);
loc_8242543C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// lwz r10,452(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x824254a8
	if (!ctx.cr6.eq) goto loc_824254A8;
	// bl 0x82213210
	ctx.lr = 0x82425454;
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
	ctx.lr = 0x82425468;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242547c
	if (!ctx.cr0.eq) goto loc_8242547C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d670
	ctx.lr = 0x8242547C;
	sub_8242D670(ctx, base);
loc_8242547C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// cmpwi cr6,r29,12
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 12, ctx.xer);
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// ble cr6,0x824254a0
	if (!ctx.cr6.gt) goto loc_824254A0;
	// addi r4,r29,-12
	ctx.r4.s64 = ctx.r29.s64 + -12;
loc_82425498:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425700
	ctx.lr = 0x824254A0;
	sub_82425700(ctx, base);
loc_824254A0:
	// lwz r4,452(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// b 0x824256e0
	goto loc_824256E0;
loc_824254A8:
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// addi r9,r11,3
	ctx.r9.s64 = ctx.r11.s64 + 3;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x824254cc
	if (ctx.cr6.gt) goto loc_824254CC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824254cc
	if (!ctx.cr6.gt) goto loc_824254CC;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425700
	ctx.lr = 0x824254CC;
	sub_82425700(ctx, base);
loc_824254CC:
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// lwz r10,336(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_824254E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824254a0
	if (ctx.cr6.eq) goto loc_824254A0;
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
	// b 0x824254a0
	goto loc_824254A0;
loc_824254FC:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7df8
	ctx.lr = 0x82425504;
	sub_823C7DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82425594
	if (ctx.cr0.eq) goto loc_82425594;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7e90
	ctx.lr = 0x82425514;
	sub_823C7E90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// lwz r10,452(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8242554c
	if (!ctx.cr6.eq) goto loc_8242554C;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7d60
	ctx.lr = 0x82425534;
	sub_823C7D60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// b 0x82425498
	goto loc_82425498;
loc_8242554C:
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8242557c
	if (ctx.cr6.lt) goto loc_8242557C;
	// cmpwi cr6,r29,12
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 12, ctx.xer);
	// ble cr6,0x8242557c
	if (!ctx.cr6.gt) goto loc_8242557C;
	// addi r10,r29,-12
	ctx.r10.s64 = ctx.r29.s64 + -12;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8242557c
	if (!ctx.cr6.lt) goto loc_8242557C;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425700
	ctx.lr = 0x8242557C;
	sub_82425700(ctx, base);
loc_8242557C:
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// lwz r10,336(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x824254e0
	goto loc_824254E0;
loc_82425594:
	// bl 0x82213210
	ctx.lr = 0x82425598;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x824255A8;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82425618
	if (ctx.cr0.eq) goto loc_82425618;
	// bl 0x82213210
	ctx.lr = 0x824255B4;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x824255C4;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// addic. r11,r11,-11
	ctx.xer.ca = ctx.r11.u32 > 10;
	ctx.r11.s64 = ctx.r11.s64 + -11;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// bge 0x824255e4
	if (!ctx.cr0.lt) goto loc_824255E4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
loc_824255E4:
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r10,-11
	ctx.r10.s64 = ctx.r10.s64 + -11;
	// xoris r9,r11,32768
	ctx.r9.u64 = ctx.r11.u64 ^ 2147483648;
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
	// bl 0x82425700
	ctx.lr = 0x8242560C;
	sub_82425700(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x824256b0
	goto loc_824256B0;
loc_82425618:
	// bl 0x82213210
	ctx.lr = 0x8242561C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x8242562C;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// bl 0x82213210
	ctx.lr = 0x82425638;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x82425648;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824256f4
	if (ctx.cr0.eq) goto loc_824256F4;
	// lwz r11,452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// addi r10,r29,-1
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// addi r11,r11,11
	ctx.r11.s64 = ctx.r11.s64 + 11;
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8242566c
	if (!ctx.cr6.gt) goto loc_8242566C;
	// stw r10,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r10.u32);
loc_8242566C:
	// addi r11,r29,-12
	ctx.r11.s64 = ctx.r29.s64 + -12;
	// lwz r9,456(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,11
	ctx.r9.s64 = ctx.r9.s64 + 11;
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
	// bge cr6,0x8242569c
	if (!ctx.cr6.lt) goto loc_8242569C;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_8242569C:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82425700
	ctx.lr = 0x824256A8;
	sub_82425700(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_824256B0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824256c8
	if (ctx.cr6.eq) goto loc_824256C8;
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
loc_824256C8:
	// lwz r4,452(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x824256e0
	if (!ctx.cr6.eq) goto loc_824256E0;
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x824256f4
	if (ctx.cr6.eq) goto loc_824256F4;
loc_824256E0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,456(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// bl 0x82423e50
	ctx.lr = 0x824256EC;
	sub_82423E50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_824256F0:
	// bl 0x823c7bd8
	ctx.lr = 0x824256F4;
	sub_823C7BD8(ctx, base);
loc_824256F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82441698) {
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
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82441708
	if (!ctx.cr0.eq) goto loc_82441708;
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
loc_824416C8:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x824416dc
	if (!ctx.cr6.lt) goto loc_824416DC;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x824416fc
	goto loc_824416FC;
loc_824416DC:
	// lbz r9,21(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 21);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x824416f4
	if (ctx.cr0.eq) goto loc_824416F4;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x824416f4
	if (!ctx.cr6.lt) goto loc_824416F4;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_824416F4:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_824416FC:
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x824416c8
	if (ctx.cr0.eq) goto loc_824416C8;
loc_82441708:
	// lbz r11,21(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82441720
	if (ctx.cr0.eq) goto loc_82441720;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82441724
	goto loc_82441724;
loc_82441720:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_82441724:
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8244175c
	if (!ctx.cr0.eq) goto loc_8244175C;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
loc_82441734:
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8244174c
	if (!ctx.cr6.lt) goto loc_8244174C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82441750
	goto loc_82441750;
loc_8244174C:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_82441750:
	// lbz r8,21(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82441734
	if (ctx.cr0.eq) goto loc_82441734;
loc_8244175C:
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplw cr6,r9,r30
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82441784
	if (ctx.cr6.eq) goto loc_82441784;
loc_8244176C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// bl 0x82216520
	ctx.lr = 0x82441778;
	sub_82216520(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8244176c
	if (!ctx.cr6.eq) goto loc_8244176C;
loc_82441784:
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

DEFINE_REX_FUNC(sub_824480B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,517
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 517, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// lfs f13,2520(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2520);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,-32
	ctx.r6.s64 = ctx.r1.s64 + -32;
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// ld r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 20);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lfs f12,2524(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2524);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r11.u64);
	// lfs f13,-44(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stfs f12,-4(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f12,-12(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-48(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
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
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,-20(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-48(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-44(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// ld r11,-48(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// std r11,2520(r3)
	REX_STORE_U64(ctx.r3.u32 + 2520, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82451208) {
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
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// cmplwi cr6,r10,98
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 98, ctx.xer);
	// bne cr6,0x82451260
	if (!ctx.cr6.eq) goto loc_82451260;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r10,12468
	ctx.r30.s64 = ctx.r10.s64 + 12468;
	// lfs f1,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,100(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f2,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82451254;
	sub_825A4A40(ctx, base);
	// lfs f0,1908(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
loc_82451260:
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

DEFINE_REX_FUNC(sub_82453810) {
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
	// beq cr6,0x82453850
	if (ctx.cr6.eq) goto loc_82453850;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82453850
	if (ctx.cr6.eq) goto loc_82453850;
	// li r6,150
	ctx.r6.s64 = 150;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82454970
	ctx.lr = 0x8245384C;
	sub_82454970(ctx, base);
	// b 0x82453854
	goto loc_82453854;
loc_82453850:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82453854:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453864
	if (ctx.cr6.eq) goto loc_82453864;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82453868
	goto loc_82453868;
loc_82453864:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82453868:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824554D8) {
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
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-12928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12928);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82455568
	if (ctx.cr6.eq) goto loc_82455568;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x82454458
	ctx.lr = 0x82455500;
	sub_82454458(ctx, base);
	// lwz r11,-12928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12928);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82455544
	if (!ctx.cr6.gt) goto loc_82455544;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82455544
	if (ctx.cr6.eq) goto loc_82455544;
	// bl 0x82453ed0
	ctx.lr = 0x82455524;
	sub_82453ED0(ctx, base);
	// lwz r11,-12928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12928);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82455544
	if (ctx.cr6.eq) goto loc_82455544;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// addi r4,r10,-28848
	ctx.r4.s64 = ctx.r10.s64 + -28848;
	// bl 0x82453e40
	ctx.lr = 0x82455540;
	sub_82453E40(ctx, base);
	// lwz r11,-12928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12928);
loc_82455544:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// stw r10,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// stw r10,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// stw r10,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// stw r10,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r10.u32);
	// stb r10,84(r11)
	REX_STORE_U8(ctx.r11.u32 + 84, ctx.r10.u8);
loc_82455568:
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

DEFINE_REX_FUNC(sub_8245A220) {
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
	// lwz r8,-12872(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8245a2b8
	if (ctx.cr6.eq) goto loc_8245A2B8;
	// lwz r10,756(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 756);
	// addi r9,r8,752
	ctx.r9.s64 = ctx.r8.s64 + 752;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x8245a268
	goto loc_8245A268;
loc_8245A24C:
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r7,r3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x8245a260
	if (!ctx.cr6.lt) goto loc_8245A260;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8245a268
	goto loc_8245A268;
loc_8245A260:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8245A268:
	// lbz r7,21(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8245a24c
	if (ctx.cr0.eq) goto loc_8245A24C;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8245a298
	if (ctx.cr6.eq) goto loc_8245A298;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8245a298
	if (ctx.cr6.lt) goto loc_8245A298;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// b 0x8245a2a0
	goto loc_8245A2A0;
loc_8245A298:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
loc_8245A2A0:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,756(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 756);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8245a2b8
	if (ctx.cr6.eq) goto loc_8245A2B8;
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x8245a2bc
	goto loc_8245A2BC;
loc_8245A2B8:
	// bl 0x825fad98
	ctx.lr = 0x8245A2BC;
	sub_825FAD98(ctx, base);
loc_8245A2BC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8245FB70) {
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
	// rlwinm. r11,r4,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq 0x8245fba0
	if (ctx.cr0.eq) goto loc_8245FBA0;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8245FB94:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// add r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 + ctx.r31.u64;
	// bdnz 0x8245fb94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245FB94;
loc_8245FBA0:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi. r5,r4,30
	ctx.r5.u64 = ctx.r4.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// beq 0x8245fbc0
	if (ctx.cr0.eq) goto loc_8245FBC0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273a4b8
	ctx.lr = 0x8245FBC0;
	sub_8273A4B8(ctx, base);
loc_8245FBC0:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_82464008) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,148(r6)
	REX_STORE_U8(ctx.r6.u32 + 148, ctx.r11.u8);
	// lbz r11,1(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// stb r11,149(r6)
	REX_STORE_U8(ctx.r6.u32 + 149, ctx.r11.u8);
	// lbz r11,2(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// stb r11,150(r6)
	REX_STORE_U8(ctx.r6.u32 + 150, ctx.r11.u8);
	// lbz r11,3(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// stb r11,151(r6)
	REX_STORE_U8(ctx.r6.u32 + 151, ctx.r11.u8);
	// stb r10,140(r6)
	REX_STORE_U8(ctx.r6.u32 + 140, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82464EB8) {
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
	// lwz r3,84(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// bl 0x8259be58
	ctx.lr = 0x82464ED8;
	sub_8259BE58(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// beq 0x82464ef4
	if (ctx.cr0.eq) goto loc_82464EF4;
	// lfs f1,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x82464f30
	ctx.lr = 0x82464EF4;
	sub_82464F30(ctx, base);
loc_82464EF4:
	// lbz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 92);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82464f18
	if (ctx.cr0.eq) goto loc_82464F18;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x82464f18
	if (!ctx.cr6.lt) goto loc_82464F18;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82464f30
	ctx.lr = 0x82464F18;
	sub_82464F30(ctx, base);
loc_82464F18:
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

DEFINE_REX_FUNC(sub_8246A168) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8246A170;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,253(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 253);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246a268
	if (ctx.cr0.eq) goto loc_8246A268;
	// lwz r11,144(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 144);
	// addi r31,r28,136
	ctx.r31.s64 = ctx.r28.s64 + 136;
	// lwz r10,140(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 140);
	// li r29,0
	ctx.r29.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8246a1e8
	if (ctx.cr0.eq) goto loc_8246A1E8;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8246A1A8:
	// lwz r11,140(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 140);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A1C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8246a1e8
	if (!ctx.cr0.eq) goto loc_8246A1E8;
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
	// blt cr6,0x8246a1a8
	if (ctx.cr6.lt) goto loc_8246A1A8;
loc_8246A1E8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8246a1f8
	if (ctx.cr0.eq) goto loc_8246A1F8;
loc_8246A1F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8246a268
	goto loc_8246A268;
loc_8246A1F8:
	// lwz r10,128(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 128);
	// addi r31,r28,120
	ctx.r31.s64 = ctx.r28.s64 + 120;
	// lwz r9,124(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 124);
	// li r29,0
	ctx.r29.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi. r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8246a258
	if (ctx.cr0.eq) goto loc_8246A258;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8246A218:
	// lwz r11,124(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 124);
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A230;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8246a258
	if (!ctx.cr0.eq) goto loc_8246A258;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8246a218
	if (ctx.cr6.lt) goto loc_8246A218;
loc_8246A258:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246a1f0
	if (!ctx.cr6.eq) goto loc_8246A1F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,253(r28)
	REX_STORE_U8(ctx.r28.u32 + 253, ctx.r11.u8);
loc_8246A268:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82472DC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82472DC8;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// lfs f13,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bne cr6,0x82472df8
	if (!ctx.cr6.eq) goto loc_82472DF8;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_82472DF8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lfs f0,8068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8068);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r10,-31120
	ctx.r10.s64 = ctx.r10.s64 + -31120;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r7,22072
	ctx.r7.s64 = ctx.r7.s64 + 22072;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,316
	ctx.r4.s64 = 316;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,44(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 44);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x82472E60;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82472e98
	if (ctx.cr0.eq) goto loc_82472E98;
	// addic r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,2
	ctx.r10.s64 = 2;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// and r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x824b38e0
	ctx.lr = 0x82472E90;
	sub_824B38E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82472e9c
	goto loc_82472E9C;
loc_82472E98:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82472E9C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82472eac
	if (!ctx.cr6.eq) goto loc_82472EAC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82472eb4
	goto loc_82472EB4;
loc_82472EAC:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r27,80(r11)
	REX_STORE_U8(ctx.r11.u32 + 80, ctx.r27.u8);
loc_82472EB4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247A3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8247A3E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,308(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247A3FC;
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
	// beq 0x8247a4f8
	if (ctx.cr0.eq) goto loc_8247A4F8;
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247A428;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
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
	ctx.lr = 0x8247A448;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8247a4f0
	goto loc_8247A4F0;
loc_8247A450:
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8247a4ec
	if (ctx.cr6.eq) goto loc_8247A4EC;
	// lbz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8247a4ec
	if (ctx.cr0.eq) goto loc_8247A4EC;
	// lbz r11,49(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 49);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8247a4ec
	if (!ctx.cr0.eq) goto loc_8247A4EC;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8247A480;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8247a4ec
	if (ctx.cr0.eq) goto loc_8247A4EC;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8247A494;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8247a4ec
	if (ctx.cr0.eq) goto loc_8247A4EC;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247A4C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8247a4d4
	if (ctx.cr6.eq) goto loc_8247A4D4;
	// stw r11,112(r30)
	REX_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
loc_8247A4D4:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8247a4e4
	if (ctx.cr6.eq) goto loc_8247A4E4;
	// stb r11,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r11.u8);
loc_8247A4E4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r11.u8);
loc_8247A4EC:
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
loc_8247A4F0:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8247a450
	if (!ctx.cr6.eq) goto loc_8247A450;
loc_8247A4F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82485B18) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82485B40;
	sub_825A49B0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r10,r3,122
	ctx.r10.s64 = ctx.r3.s64 + 122;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// clrlwi r31,r10,16
	ctx.r31.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82485B60;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82485b7c
	if (ctx.cr0.eq) goto loc_82485B7C;
	// addi r5,r30,68
	ctx.r5.s64 = ctx.r30.s64 + 68;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82485c08
	ctx.lr = 0x82485B74;
	sub_82485C08(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82485b80
	goto loc_82485B80;
loc_82485B7C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82485B80:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82485bf0
	if (ctx.cr6.eq) goto loc_82485BF0;
	// ld r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 44);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
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
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82485BC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82485BCC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82485bf0
	if (!ctx.cr6.eq) goto loc_82485BF0;
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
	ctx.lr = 0x82485BF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82485BF0:
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

DEFINE_REX_FUNC(sub_8248E7B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8248E7C0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
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
	// li r4,204
	ctx.r4.s64 = 204;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8248E7E0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8248e800
	if (ctx.cr0.eq) goto loc_8248E800;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f1,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8247b060
	ctx.lr = 0x8248E7F8;
	sub_8247B060(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8248e804
	goto loc_8248E804;
loc_8248E800:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8248E804:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8248e8e8
	if (ctx.cr6.eq) goto loc_8248E8E8;
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// addi r28,r30,-32216
	ctx.r28.s64 = ctx.r30.s64 + -32216;
	// addi r11,r29,15656
	ctx.r11.s64 = ctx.r29.s64 + 15656;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,740(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 740);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-3184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3184);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8248E82C;
	sub_825A4A40(ctx, base);
	// lfs f0,728(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 728);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,15656(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 15656);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8248E844;
	sub_825A4A40(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,168(r31)
	REX_STORE_U64(ctx.r31.u32 + 168, ctx.r10.u64);
	// lis r29,-32227
	ctx.r29.s64 = -2112028672;
	// lwz r11,-4844(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -4844);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-24640(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -24640);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,1952(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1952);
	ctx.f1.f64 = double(temp.f32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8248E874;
	sub_825A4A40(ctx, base);
	// lfs f0,1952(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1952);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f2,-24640(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -24640);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8248E88C;
	sub_825A4A40(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
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
	// lfs f0,1612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1612);
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
	ctx.lr = 0x8248E8BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f13,-32216(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-4888(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-27624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27624);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f1,f0,f13,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248E8E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8248E8E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249CE48) {
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
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8249CE74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8249cf38
	if (!ctx.cr0.eq) goto loc_8249CF38;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f11,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// stfs f13,288(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// lfs f0,2408(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2408);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8249cecc
	if (!ctx.cr6.lt) goto loc_8249CECC;
	// fdivs f12,f31,f0
	ctx.f12.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f10,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,-32216
	ctx.r11.s64 = ctx.r11.s64 + -32216;
	// lfs f0,22360(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22360);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f12,f12,f0,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfs f12,296(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// ble cr6,0x8249cf18
	if (!ctx.cr6.gt) goto loc_8249CF18;
	// b 0x8249cf14
	goto loc_8249CF14;
loc_8249CECC:
	// lfs f12,700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 700);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x8249ceec
	if (!ctx.cr6.lt) goto loc_8249CEEC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-32216
	ctx.r11.s64 = ctx.r11.s64 + -32216;
	// lfs f0,22360(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22360);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8249cf14
	goto loc_8249CF14;
loc_8249CEEC:
	// fdivs f10,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r10,-32216
	ctx.r11.s64 = ctx.r10.s64 + -32216;
	// lfs f9,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,22360(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22360);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f12,f10,f12,f9
	ctx.f12.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f12.f64, -ctx.f9.f64)));
	// stfs f12,296(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x8249cf18
	if (!ctx.cr6.lt) goto loc_8249CF18;
loc_8249CF14:
	// stfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
loc_8249CF18:
	// lfs f12,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// ble cr6,0x8249cf38
	if (!ctx.cr6.gt) goto loc_8249CF38;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_8249CF38:
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

DEFINE_REX_FUNC(sub_824A3938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x824A3940;
	__savegprlr_21(ctx, base);
	// stwu r1,-592(r1)
	ea = -592 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x824a45a4
	if (ctx.cr6.eq) goto loc_824A45A4;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x824a41d0
	if (ctx.cr6.eq) goto loc_824A41D0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x824a41a0
	if (ctx.cr6.eq) goto loc_824A41A0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x824a3a6c
	if (ctx.cr6.eq) goto loc_824A3A6C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x824a39d0
	if (ctx.cr6.eq) goto loc_824A39D0;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x824a4604
	if (!ctx.cr6.eq) goto loc_824A4604;
	// lwz r10,412(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 412);
	// li r22,1
	ctx.r22.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x824a39c0
	if (!ctx.cr6.gt) goto loc_824A39C0;
	// addi r10,r3,284
	ctx.r10.s64 = ctx.r3.s64 + 284;
loc_824A3998:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x824a39bc
	if (!ctx.cr6.eq) goto loc_824A39BC;
	// lwz r8,412(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x824a3998
	if (ctx.cr6.lt) goto loc_824A3998;
	// b 0x824a39c0
	goto loc_824A39C0;
loc_824A39BC:
	// li r9,0
	ctx.r9.s64 = 0;
loc_824A39C0:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a4604
	if (ctx.cr0.eq) goto loc_824A4604;
	// stb r22,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r22.u8);
	// b 0x824a4604
	goto loc_824A4604;
loc_824A39D0:
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// addi r11,r11,-25312
	ctx.r11.s64 = ctx.r11.s64 + -25312;
	// lfs f0,-4816(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4816);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824a4604
	if (!ctx.cr6.gt) goto loc_824A4604;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x824a3a60
	if (!ctx.cr6.gt) goto loc_824A3A60;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r8,r31,284
	ctx.r8.s64 = ctx.r31.s64 + 284;
	// li r21,5
	ctx.r21.s64 = 5;
	// lwz r7,-12816(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
loc_824A3A10:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a3a4c
	if (ctx.cr6.eq) goto loc_824A3A4C;
	// lwz r10,172(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a3a4c
	if (!ctx.cr6.eq) goto loc_824A3A4C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a3a4c
	if (ctx.cr6.eq) goto loc_824A3A4C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r21,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r21.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
loc_824A3A4C:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824a3a10
	if (ctx.cr6.lt) goto loc_824A3A10;
loc_824A3A60:
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// b 0x824a4604
	goto loc_824A4604;
loc_824A3A6C:
	// lfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f13,396(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// addi r11,r11,13168
	ctx.r11.s64 = ctx.r11.s64 + 13168;
	// lfs f0,1208(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1208);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824a4604
	if (!ctx.cr6.gt) goto loc_824A4604;
	// lwz r10,376(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// lfs f1,-932(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -932);
	ctx.f1.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x824a3aa0
	if (!ctx.cr6.eq) goto loc_824A3AA0;
	// lfs f1,-696(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -696);
	ctx.f1.f64 = double(temp.f32);
loc_824A3AA0:
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lfs f5,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f5.f64 = double(temp.f32);
	// li r21,5
	ctx.r21.s64 = 5;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x824a3ec8
	if (ctx.cr6.eq) goto loc_824A3EC8;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x824a3ec8
	if (ctx.cr6.eq) goto loc_824A3EC8;
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824a3b34
	if (!ctx.cr6.eq) goto loc_824A3B34;
	// ld r10,368(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 368);
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// beq cr6,0x824a4190
	if (ctx.cr6.eq) goto loc_824A4190;
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
	// bne cr6,0x824a4190
	if (!ctx.cr6.eq) goto loc_824A4190;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a4190
	if (ctx.cr6.eq) goto loc_824A4190;
	// lfs f13,408(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x824a4708
	ctx.lr = 0x824A3B18;
	sub_824A4708(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r3,r30,340
	ctx.r3.s64 = ctx.r30.s64 + 340;
	// stw r11,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r11.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,340(r30)
	REX_STORE_U64(ctx.r30.u32 + 340, ctx.r11.u64);
	// bl 0x824a6100
	ctx.lr = 0x824A3B30;
	sub_824A6100(ctx, base);
	// b 0x824a4190
	goto loc_824A4190;
loc_824A3B34:
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a4190
	if (ctx.cr6.eq) goto loc_824A4190;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r29,r31,292
	ctx.r29.s64 = ctx.r31.s64 + 292;
	// lfs f2,-8956(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8956);
	ctx.f2.f64 = double(temp.f32);
	// addi r27,r31,316
	ctx.r27.s64 = ctx.r31.s64 + 316;
	// lwz r28,-12816(r8)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r8.u32 + -12816);
	// li r22,1
	ctx.r22.s64 = 1;
	// addi r26,r11,32720
	ctx.r26.s64 = ctx.r11.s64 + 32720;
	// addi r24,r10,32256
	ctx.r24.s64 = ctx.r10.s64 + 32256;
loc_824A3B6C:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r10,r25,2
	ctx.r10.s64 = ctx.r25.s64 + 2;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x824a4190
	if (!ctx.cr6.lt) goto loc_824A4190;
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// lfs f13,372(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r7,r1,464
	ctx.r7.s64 = ctx.r1.s64 + 464;
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// addi r4,r31,368
	ctx.r4.s64 = ctx.r31.s64 + 368;
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,368(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
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
	// stfs f13,348(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f13,344(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f13,336(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,464(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x824a3c40
	if (ctx.cr6.lt) goto loc_824A3C40;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824A3C40:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a3c50
	if (ctx.cr0.eq) goto loc_824A3C50;
	// fcmpu cr6,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// blt cr6,0x824a3c94
	if (ctx.cr6.lt) goto loc_824A3C94;
loc_824A3C50:
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// stfs f0,284(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// bgt cr6,0x824a3c84
	if (ctx.cr6.gt) goto loc_824A3C84;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824A3C84:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a3d84
	if (ctx.cr0.eq) goto loc_824A3D84;
	// fcmpu cr6,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x824a3d84
	if (!ctx.cr6.gt) goto loc_824A3D84;
loc_824A3C94:
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// stfs f0,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lfs f13,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,268(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lvx128 v7,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v0,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)));
	// lfs f0,400(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// vcmpeqfp128 v10,v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
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
	// stvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,432(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824a3d34
	if (ctx.cr6.lt) goto loc_824A3D34;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824A3D34:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a3d84
	if (ctx.cr0.eq) goto loc_824A3D84;
	// ld r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// beq cr6,0x824a3eac
	if (ctx.cr6.eq) goto loc_824A3EAC;
	// lwz r10,172(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a3eac
	if (!ctx.cr6.eq) goto loc_824A3EAC;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a3eac
	if (ctx.cr6.eq) goto loc_824A3EAC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824a4708
	ctx.lr = 0x824A3D7C;
	sub_824A4708(ctx, base);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x824a3e9c
	goto loc_824A3E9C;
loc_824A3D84:
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stfs f1,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f1,176(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stfs f1,184(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// std r11,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r11.u64);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f13,400(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stfs f1,180(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,304(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfs f0,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// frsp f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f12.f64));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
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
	// lfs f12,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// ld r11,192(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x824A3E60;
	sub_8255F918(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a3eac
	if (ctx.cr6.eq) goto loc_824A3EAC;
	// lwz r10,172(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a3eac
	if (!ctx.cr6.eq) goto loc_824A3EAC;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a3eac
	if (ctx.cr6.eq) goto loc_824A3EAC;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824a4708
	ctx.lr = 0x824A3E98;
	sub_824A4708(ctx, base);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
loc_824A3E9C:
	// stw r22,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r22.u32);
	// addi r3,r30,340
	ctx.r3.s64 = ctx.r30.s64 + 340;
	// std r11,340(r30)
	REX_STORE_U64(ctx.r30.u32 + 340, ctx.r11.u64);
	// bl 0x824a6100
	ctx.lr = 0x824A3EAC;
	sub_824A6100(ctx, base);
loc_824A3EAC:
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824a3b6c
	if (ctx.cr6.lt) goto loc_824A3B6C;
	// b 0x824a4190
	goto loc_824A4190;
loc_824A3EC8:
	// lwz r10,412(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x824a4190
	if (!ctx.cr6.gt) goto loc_824A4190;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f6,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r24,r31,368
	ctx.r24.s64 = ctx.r31.s64 + 368;
	// addi r25,r31,284
	ctx.r25.s64 = ctx.r31.s64 + 284;
	// lwz r26,-13032(r10)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// li r22,1
	ctx.r22.s64 = 1;
	// lwz r23,-12816(r9)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r9.u32 + -12816);
	// addi r27,r11,32720
	ctx.r27.s64 = ctx.r11.s64 + 32720;
loc_824A3F00:
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lfs f13,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bne cr6,0x824a3fe0
	if (!ctx.cr6.eq) goto loc_824A3FE0;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// std r11,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r11.u64);
	// lfd f0,304(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r30,r1,384
	ctx.r30.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f0,f12
	ctx.f0.f64 = double(float(ctx.f12.f64));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,384(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// b 0x824a40a0
	goto loc_824A40A0;
loc_824A3FE0:
	// std r11,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r11.u64);
	// lfd f0,288(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f1,232(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f1,228(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f1,224(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stfs f1,236(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// addi r11,r1,448
	ctx.r11.s64 = ctx.r1.s64 + 448;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r30,r1,368
	ctx.r30.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,488
	ctx.r3.s64 = ctx.r1.s64 + 488;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f0,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// fmuls f0,f13,f6
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,280(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lfs f0,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,368(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// ld r11,192(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
loc_824A40A0:
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x824A40A8;
	sub_8255F918(ctx, base);
	// ld r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// std r29,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r29.u64);
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824a40e4
	if (ctx.cr6.eq) goto loc_824A40E4;
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.f11.u64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,212(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// bl 0x823aefa8
	ctx.lr = 0x824A40E4;
	sub_823AEFA8(ctx, base);
loc_824A40E4:
	// clrlwi r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x824a4118
	if (ctx.cr6.eq) goto loc_824A4118;
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.f0.u64);
	// lwz r3,212(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x824A4118;
	sub_823AEBD8(ctx, base);
loc_824A4118:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a417c
	if (ctx.cr6.eq) goto loc_824A417C;
	// lwz r10,172(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a417c
	if (!ctx.cr6.eq) goto loc_824A417C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a417c
	if (ctx.cr6.eq) goto loc_824A417C;
	// lwz r10,416(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x824a4170
	if (!ctx.cr6.eq) goto loc_824A4170;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x824a4170
	if (!ctx.cr6.eq) goto loc_824A4170;
	// std r29,340(r11)
	REX_STORE_U64(ctx.r11.u32 + 340, ctx.r29.u64);
	// addi r3,r11,340
	ctx.r3.s64 = ctx.r11.s64 + 340;
	// stw r22,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r22.u32);
	// bl 0x824a6100
	ctx.lr = 0x824A416C;
	sub_824A6100(ctx, base);
	// b 0x824a417c
	goto loc_824A417C;
loc_824A4170:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r21,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r21.u32);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
loc_824A417C:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824a3f00
	if (ctx.cr6.lt) goto loc_824A3F00;
loc_824A4190:
	// stfs f5,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stw r21,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r21.u32);
	// stfs f5,392(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// b 0x824a4604
	goto loc_824A4604;
loc_824A41A0:
	// lfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f13,396(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// addi r11,r11,13168
	ctx.r11.s64 = ctx.r11.s64 + 13168;
	// lfs f0,1208(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1208);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824a4604
	if (!ctx.cr6.gt) goto loc_824A4604;
	// lfs f0,-700(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// b 0x824a4600
	goto loc_824A4600;
loc_824A41D0:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,376(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// addi r27,r11,13168
	ctx.r27.s64 = ctx.r11.s64 + 13168;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f1,-932(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -932);
	ctx.f1.f64 = double(temp.f32);
	// bne cr6,0x824a41ec
	if (!ctx.cr6.eq) goto loc_824A41EC;
	// lfs f1,-696(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -696);
	ctx.f1.f64 = double(temp.f32);
loc_824A41EC:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lfs f6,1208(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1208);
	ctx.f6.f64 = double(temp.f32);
	// li r22,1
	ctx.r22.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r28,-12816(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// bne cr6,0x824a4258
	if (!ctx.cr6.eq) goto loc_824A4258;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a44d8
	if (ctx.cr6.eq) goto loc_824A44D8;
	// lwz r10,172(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a44d8
	if (!ctx.cr6.eq) goto loc_824A44D8;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a44d8
	if (ctx.cr6.eq) goto loc_824A44D8;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r3,r31,368
	ctx.r3.s64 = ctx.r31.s64 + 368;
	// lfs f2,-8956(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8956);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x824a4708
	ctx.lr = 0x824A4248;
	sub_824A4708(ctx, base);
	// lwz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// stw r11,340(r30)
	REX_STORE_U32(ctx.r30.u32 + 340, ctx.r11.u32);
	// lwz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// b 0x824a44c8
	goto loc_824A44C8;
loc_824A4258:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824a44d8
	if (!ctx.cr6.eq) goto loc_824A44D8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f11,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r30,r11,32720
	ctx.r30.s64 = ctx.r11.s64 + 32720;
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r25,r1,144
	ctx.r25.s64 = ctx.r1.s64 + 144;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r26,r1,320
	ctx.r26.s64 = ctx.r1.s64 + 320;
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r29,r31,368
	ctx.r29.s64 = ctx.r31.s64 + 368;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x824A432C;
	sub_8255F918(ctx, base);
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a4470
	if (ctx.cr6.eq) goto loc_824A4470;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f11,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f6.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r24,r1,144
	ctx.r24.s64 = ctx.r1.s64 + 144;
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// addi r25,r1,80
	ctx.r25.s64 = ctx.r1.s64 + 80;
	// lfs f0,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r26,r1,176
	ctx.r26.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f0,320(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// b 0x824a4474
	goto loc_824A4474;
loc_824A4470:
	// ld r10,288(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
loc_824A4474:
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// std r10,0(r29)
	REX_STORE_U64(ctx.r29.u32 + 0, ctx.r10.u64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a44d8
	if (ctx.cr6.eq) goto loc_824A44D8;
	// lwz r10,172(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a44d8
	if (!ctx.cr6.eq) goto loc_824A44D8;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824a44d8
	if (ctx.cr6.eq) goto loc_824A44D8;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f2,-8956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8956);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x824a4708
	ctx.lr = 0x824A44B8;
	sub_824A4708(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,340(r30)
	REX_STORE_U32(ctx.r30.u32 + 340, ctx.r11.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stfs f6,408(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 408, temp.u32);
loc_824A44C8:
	// stw r22,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r22.u32);
	// addi r3,r30,340
	ctx.r3.s64 = ctx.r30.s64 + 340;
	// stw r11,344(r30)
	REX_STORE_U32(ctx.r30.u32 + 344, ctx.r11.u32);
	// bl 0x824a6100
	ctx.lr = 0x824A44D8;
	sub_824A6100(ctx, base);
loc_824A44D8:
	// ld r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 368);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f2,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f2.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x824a4708
	ctx.lr = 0x824A44EC;
	sub_824A4708(ctx, base);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a4540
	if (ctx.cr6.eq) goto loc_824A4540;
	// lwz r10,172(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824a4540
	if (!ctx.cr6.eq) goto loc_824A4540;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a4540
	if (ctx.cr6.eq) goto loc_824A4540;
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r3,r11,340
	ctx.r3.s64 = ctx.r11.s64 + 340;
	// std r10,340(r11)
	REX_STORE_U64(ctx.r11.u32 + 340, ctx.r10.u64);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x824a4538
	if (!ctx.cr6.eq) goto loc_824A4538;
	// stfs f6,408(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 408, temp.u32);
loc_824A4538:
	// stw r22,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r22.u32);
	// bl 0x824a6100
	ctx.lr = 0x824A4540;
	sub_824A6100(ctx, base);
loc_824A4540:
	// lfs f13,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r8,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r8.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,-700(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
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
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// b 0x824a4604
	goto loc_824A4604;
loc_824A45A4:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// addi r10,r10,13168
	ctx.r10.s64 = ctx.r10.s64 + 13168;
	// li r8,2
	ctx.r8.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r8,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r8.u32);
	// lfs f13,-18480(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18480);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-700(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// bne cr6,0x824a45d8
	if (!ctx.cr6.eq) goto loc_824A45D8;
	// stfs f13,408(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
loc_824A45D8:
	// li r10,4
	ctx.r10.s64 = 4;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x824a45ec
	if (!ctx.cr6.eq) goto loc_824A45EC;
	// stfs f13,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
	// stw r10,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
loc_824A45EC:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x824a4604
	if (!ctx.cr6.eq) goto loc_824A4604;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-25312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25312);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,408(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
loc_824A4600:
	// stw r10,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
loc_824A4604:
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82512A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lbz r11,309(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 309);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r9,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r9.u8);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32088);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r8,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r8.u32);
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// stb r7,309(r3)
	REX_STORE_U8(ctx.r3.u32 + 309, ctx.r7.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82514908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82514910;
	__savegprlr_20(ctx, base);
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8273af1c
	ctx.lr = 0x82514918;
	__savefpr_25(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r21,8(r4)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = ctx.f1.f64;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82514de8
	if (ctx.cr6.eq) goto loc_82514DE8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r11,15288
	ctx.r11.s64 = ctx.r11.s64 + 15288;
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f30,-2820(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2820);
	ctx.f30.f64 = double(temp.f32);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// fmr f25,f30
	ctx.f25.f64 = ctx.f30.f64;
	// beq cr6,0x82514de8
	if (ctx.cr6.eq) goto loc_82514DE8;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f28,-1008(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1008);
	ctx.f28.f64 = double(temp.f32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lfs f29,-3052(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3052);
	ctx.f29.f64 = double(temp.f32);
	// lfs f27,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r22,-32240
	ctx.r22.s64 = -2112880640;
	// li r28,3
	ctx.r28.s64 = 3;
	// addi r27,r10,-6828
	ctx.r27.s64 = ctx.r10.s64 + -6828;
	// addi r23,r9,32736
	ctx.r23.s64 = ctx.r9.s64 + 32736;
loc_82514984:
	// lwz r31,8(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82514dd0
	if (ctx.cr6.eq) goto loc_82514DD0;
	// lbz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82514a0c
	if (!ctx.cr0.eq) goto loc_82514A0C;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825149c4
	if (ctx.cr6.eq) goto loc_825149C4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825149B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825149c4
	if (!ctx.cr0.eq) goto loc_825149C4;
	// stb r30,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r30.u8);
loc_825149C4:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825149f0
	if (ctx.cr6.eq) goto loc_825149F0;
	// stb r26,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r26.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825149E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825149f0
	if (!ctx.cr0.eq) goto loc_825149F0;
	// stb r30,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r30.u8);
loc_825149F0:
	// lbz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514a0c
	if (ctx.cr0.eq) goto loc_82514A0C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f25.f64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82515008
	ctx.lr = 0x82514A0C;
	sub_82515008(ctx, base);
loc_82514A0C:
	// lbz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514dd0
	if (ctx.cr0.eq) goto loc_82514DD0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82514a9c
	if (ctx.cr6.eq) goto loc_82514A9C;
	// cmplw cr6,r21,r25
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r25.u32, ctx.xer);
	// ble cr6,0x82514a48
	if (!ctx.cr6.gt) goto loc_82514A48;
	// subf r11,r25,r21
	ctx.r11.u64 = ctx.r21.u64 - ctx.r25.u64;
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
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// b 0x82514a4c
	goto loc_82514A4C;
loc_82514A48:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
loc_82514A4C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82514a5c
	if (!ctx.cr6.lt) goto loc_82514A5C;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x82514a68
	goto loc_82514A68;
loc_82514A5C:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// ble cr6,0x82514a68
	if (!ctx.cr6.gt) goto loc_82514A68;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
loc_82514A68:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f13,11268(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 11268);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f31,f0,f27,f13
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f27.f64, ctx.f13.f64)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514A88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82514ad4
	if (ctx.cr6.eq) goto loc_82514AD4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// b 0x82514ac4
	goto loc_82514AC4;
loc_82514A9C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514AB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82514ad4
	if (ctx.cr6.eq) goto loc_82514AD4;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
loc_82514AC4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514AD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82514AD4:
	// lbz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82514b04
	if (!ctx.cr0.eq) goto loc_82514B04;
	// lbz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 68);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514b04
	if (ctx.cr0.eq) goto loc_82514B04;
	// lfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f26
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f26.f64));
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82514b04
	if (!ctx.cr6.lt) goto loc_82514B04;
	// stb r30,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r30.u8);
loc_82514B04:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82514b38
	if (ctx.cr6.eq) goto loc_82514B38;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82514b38
	if (ctx.cr6.eq) goto loc_82514B38;
	// lwz r9,4(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82514b38
	if (ctx.cr6.eq) goto loc_82514B38;
	// lbz r11,62(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 62);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514b38
	if (ctx.cr0.eq) goto loc_82514B38;
	// stb r30,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r30.u8);
loc_82514B38:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82514df8
	if (ctx.cr6.lt) goto loc_82514DF8;
	// beq cr6,0x82514e40
	if (ctx.cr6.eq) goto loc_82514E40;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82514c18
	if (ctx.cr6.lt) goto loc_82514C18;
	// bne cr6,0x82514dd0
	if (!ctx.cr6.eq) goto loc_82514DD0;
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fadds f0,f0,f26
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f26.f64));
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82514b90
	if (ctx.cr6.eq) goto loc_82514B90;
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514b90
	if (ctx.cr0.eq) goto loc_82514B90;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514B8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r30.u8);
loc_82514B90:
	// lfs f13,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17912(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 17912);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82514dd0
	if (ctx.cr6.lt) goto loc_82514DD0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbz r11,61(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 61);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82514be4
	if (ctx.cr6.eq) goto loc_82514BE4;
	// bne 0x82514bd4
	if (!ctx.cr0.eq) goto loc_82514BD4;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514BD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,61(r31)
	REX_STORE_U8(ctx.r31.u32 + 61, ctx.r30.u8);
loc_82514BD4:
	// lbz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514dd0
	if (ctx.cr0.eq) goto loc_82514DD0;
	// b 0x82514c04
	goto loc_82514C04;
loc_82514BE4:
	// bne 0x82514c04
	if (!ctx.cr0.eq) goto loc_82514C04;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514C00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,61(r31)
	REX_STORE_U8(ctx.r31.u32 + 61, ctx.r30.u8);
loc_82514C04:
	// lbz r11,61(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 61);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514dd0
	if (ctx.cr0.eq) goto loc_82514DD0;
	// stb r30,62(r31)
	REX_STORE_U8(ctx.r31.u32 + 62, ctx.r30.u8);
	// b 0x82514dd0
	goto loc_82514DD0;
loc_82514C18:
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f26
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f26.f64));
	// lfs f0,-29492(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82514c58
	if (ctx.cr6.lt) goto loc_82514C58;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8224a2a0
	ctx.lr = 0x82514C4C;
	sub_8224A2A0(ctx, base);
	// stfs f30,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stw r28,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stb r26,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r26.u8);
loc_82514C58:
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514d3c
	if (ctx.cr0.eq) goto loc_82514D3C;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r4,r31,8
	ctx.r4.s64 = ctx.r31.s64 + 8;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lfs f13,24(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x82514CE4;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ld r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 20);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,108(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82515e00
	ctx.lr = 0x82514D1C;
	sub_82515E00(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// bl 0x8255a7f0
	ctx.lr = 0x82514D28;
	sub_8255A7F0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82514d3c
	if (!ctx.cr0.eq) goto loc_82514D3C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82514e98
	ctx.lr = 0x82514D3C;
	sub_82514E98(ctx, base);
loc_82514D3C:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x82514d90
	if (!ctx.cr6.eq) goto loc_82514D90;
	// lwz r11,344(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 344);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82514d90
	if (!ctx.cr6.eq) goto loc_82514D90;
	// lwz r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x82514d90
	if (ctx.cr6.gt) goto loc_82514D90;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82514d90
	if (ctx.cr6.eq) goto loc_82514D90;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8224a2a0
	ctx.lr = 0x82514D84;
	sub_8224A2A0(ctx, base);
	// stfs f30,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stw r28,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stb r26,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r26.u8);
loc_82514D90:
	// lbz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82514dd0
	if (ctx.cr0.eq) goto loc_82514DD0;
loc_82514D9C:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82514dd0
	if (ctx.cr6.eq) goto loc_82514DD0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8224a2a0
	ctx.lr = 0x82514DC4;
	sub_8224A2A0(ctx, base);
	// stb r26,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r26.u8);
	// stw r28,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
loc_82514DCC:
	// stfs f30,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
loc_82514DD0:
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// fadds f25,f25,f29
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = double(float(ctx.f25.f64 + ctx.f29.f64));
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82514984
	if (!ctx.cr6.eq) goto loc_82514984;
loc_82514DE8:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-104
	ctx.r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8273af68
	ctx.lr = 0x82514DF4;
	__restfpr_25(ctx, base);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_82514DF8:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82514e18
	if (ctx.cr6.eq) goto loc_82514E18;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514E18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82514E18:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82514e38
	if (ctx.cr6.eq) goto loc_82514E38;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82514E38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82514E38:
	// stfs f30,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
loc_82514E40:
	// lbz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82514d9c
	if (!ctx.cr0.eq) goto loc_82514D9C;
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f26
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f26.f64));
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82514dd0
	if (ctx.cr6.lt) goto loc_82514DD0;
	// lwz r5,4(r20)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r20.u32 + 4);
	// fmr f2,f28
	ctx.f2.f64 = ctx.f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82514E74;
	sub_825A4A40(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8224a2a0
	ctx.lr = 0x82514E8C;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// b 0x82514dcc
	goto loc_82514DCC;
}

DEFINE_REX_FUNC(sub_8253CB10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8253CB18;
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8253cf78
	if (!ctx.cr0.eq) goto loc_8253CF78;
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
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8253cc1c
	if (!ctx.cr6.eq) goto loc_8253CC1C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8253cc1c
	if (ctx.cr6.eq) goto loc_8253CC1C;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8253cc1c
	if (ctx.cr0.eq) goto loc_8253CC1C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x8253CB7C;
	sub_82430A88(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
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
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
loc_8253CC1C:
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// li r29,-1
	ctx.r29.s64 = -1;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8253cd48
	if (ctx.cr6.lt) goto loc_8253CD48;
	// bne cr6,0x8253ced0
	if (!ctx.cr6.eq) goto loc_8253CED0;
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8253cc68
	if (ctx.cr6.eq) goto loc_8253CC68;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8253CC4C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8253cc64
	if (ctx.cr0.eq) goto loc_8253CC64;
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8253CC64;
	sub_82222BB0(ctx, base);
loc_8253CC64:
	// stw r29,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r29.u32);
loc_8253CC68:
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// lfs f13,4440(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8253cd0c
	if (!ctx.cr6.lt) goto loc_8253CD0C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// addi r10,r10,15088
	ctx.r10.s64 = ctx.r10.s64 + 15088;
	// lfs f12,408(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 408);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-2852(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2852);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f12,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f13.f64)));
	// lfs f12,-2620(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2620);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8253ccb4
	if (!ctx.cr6.lt) goto loc_8253CCB4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x8253ccc0
	goto loc_8253CCC0;
loc_8253CCB4:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8253ccc0
	if (!ctx.cr6.gt) goto loc_8253CCC0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8253CCC0:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lfs f13,-9856(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,119(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CD08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8253ced0
	goto loc_8253CED0;
loc_8253CD0C:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
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
	ctx.lr = 0x8253CD40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
	// b 0x8253ced0
	goto loc_8253CED0;
loc_8253CD48:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r11,15088
	ctx.r30.s64 = ctx.r11.s64 + 15088;
	// lfs f13,-712(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -712);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8253ce98
	if (!ctx.cr6.lt) goto loc_8253CE98;
	// lfs f13,-808(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -808);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8253cdbc
	if (!ctx.cr6.lt) goto loc_8253CDBC;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f13,-2620(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2620);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8253cd8c
	if (ctx.cr6.lt) goto loc_8253CD8C;
	// lfs f13,-2852(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2852);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8253cd90
	if (!ctx.cr6.gt) goto loc_8253CD90;
loc_8253CD8C:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_8253CD90:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// lfs f13,-9856(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lbz r10,119(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// b 0x8253cdcc
	goto loc_8253CDCC;
loc_8253CDBC:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_8253CDCC:
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8253CDEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f30,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, ctx.f0.f64)));
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r27,0(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CE18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,100(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 100);
	// lfs f13,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fnmsubs f1,f0,f30,f1
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f30.f64, -ctx.f1.f64)));
	// bctrl 
	ctx.lr = 0x8253CE38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CE54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmuls f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f0,3204(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3204);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8253ce8c
	if (!ctx.cr6.gt) goto loc_8253CE8C;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CE8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8253CE8C:
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// b 0x8253cecc
	goto loc_8253CECC;
loc_8253CE98:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,3204(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3204);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CEC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-2620(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2620);
	ctx.f0.f64 = double(temp.f32);
	// stw r28,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r28.u32);
loc_8253CECC:
	// stfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
loc_8253CED0:
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8253cf68
	if (ctx.cr6.eq) goto loc_8253CF68;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8253CEE8;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8253cf64
	if (ctx.cr0.eq) goto loc_8253CF64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x8253CF0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CF34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x8253CF50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253CF60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8253cf68
	goto loc_8253CF68;
loc_8253CF64:
	// stw r29,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r29.u32);
loc_8253CF68:
	// lbz r11,289(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8253cf78
	if (ctx.cr0.eq) goto loc_8253CF78;
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
loc_8253CF78:
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

DEFINE_REX_FUNC(sub_82558810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82558818;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82558848;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addic r9,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r9.s64 = ctx.r30.s64 + -1;
	// stb r29,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r29.u8);
	// addi r10,r11,12236
	ctx.r10.s64 = ctx.r11.s64 + 12236;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lis r7,-32768
	ctx.r7.s64 = -2147483648;
	// subfe r11,r9,r30
	temp.u8 = (~ctx.r9.u32 + ctx.r30.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r8,7128
	ctx.r8.s64 = ctx.r8.s64 + 7128;
	// lfs f0,232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// ori r7,r7,16
	ctx.r7.u64 = ctx.r7.u64 | 16;
	// stb r11,300(r31)
	REX_STORE_U8(ctx.r31.u32 + 300, ctx.r11.u8);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r9,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r9.u8);
	// stw r9,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r9.u32);
	// stw r7,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// beq 0x8255889c
	if (ctx.cr0.eq) goto loc_8255889C;
	// lfs f12,236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x825588a0
	goto loc_825588A0;
loc_8255889C:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_825588A0:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,180(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r11,-31824
	ctx.r11.s64 = ctx.r11.s64 + -31824;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stb r9,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r9.u8);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f13,-30132(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -30132);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
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
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82566668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82566670;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8256699c
	if (!ctx.cr0.eq) goto loc_8256699C;
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
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82566778
	if (!ctx.cr6.eq) goto loc_82566778;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82566778
	if (ctx.cr6.eq) goto loc_82566778;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82566778
	if (ctx.cr0.eq) goto loc_82566778;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x825666D8;
	sub_82430A88(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
loc_82566778:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f0,332(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6080(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6080);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82566798
	if (!ctx.cr6.lt) goto loc_82566798;
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// b 0x8256679c
	goto loc_8256679C;
loc_82566798:
	// stfs f13,332(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
loc_8256679C:
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x825667e8
	if (ctx.cr6.lt) goto loc_825667E8;
	// bne cr6,0x8256699c
	if (!ctx.cr6.eq) goto loc_8256699C;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825667dc
	if (!ctx.cr6.eq) goto loc_825667DC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f29,f0
	ctx.f12.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// stfs f12,292(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f0,3420(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3420);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// blt cr6,0x8256699c
	if (ctx.cr6.lt) goto loc_8256699C;
loc_825667DC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8256699c
	goto loc_8256699C;
loc_825667E8:
	// lfs f0,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// addi r29,r11,12236
	ctx.r29.s64 = ctx.r11.s64 + 12236;
	// li r28,1
	ctx.r28.s64 = 1;
	// lfs f13,3420(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3420);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x825668d4
	if (!ctx.cr6.lt) goto loc_825668D4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f30,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// addi r29,r11,-9856
	ctx.r29.s64 = ctx.r11.s64 + -9856;
	// lfs f12,-22360(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -22360);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f31,f0,f12
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// bge cr6,0x82566834
	if (!ctx.cr6.lt) goto loc_82566834;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
	// b 0x82566840
	goto loc_82566840;
loc_82566834:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// ble cr6,0x82566840
	if (!ctx.cr6.gt) goto loc_82566840;
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
loc_82566840:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r30,r11,-6828
	ctx.r30.s64 = ctx.r11.s64 + -6828;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r8,-3392
	ctx.r9.s64 = ctx.r8.s64 + -3392;
	// addi r8,r30,24
	ctx.r8.s64 = ctx.r30.s64 + 24;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfsx f13,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r8
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f13,f13,f31,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f31.f64, ctx.f12.f64)));
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x82566888;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// fsubs f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x825668D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8256695c
	goto loc_8256695C;
loc_825668D4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r30,r11,-6828
	ctx.r30.s64 = ctx.r11.s64 + -6828;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r8,-3392
	ctx.r9.s64 = ctx.r8.s64 + -3392;
	// addi r8,r30,24
	ctx.r8.s64 = ctx.r30.s64 + 24;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfsx f13,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r8
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x8256691C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
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
	ctx.lr = 0x82566950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stw r28,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r28.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
loc_8256695C:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x8256699c
	if (!ctx.cr6.lt) goto loc_8256699C;
	// lbz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 324);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8256699c
	if (!ctx.cr0.eq) goto loc_8256699C;
	// lfs f0,328(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,328(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8256699c
	if (!ctx.cr6.gt) goto loc_8256699C;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,328(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// stb r28,336(r31)
	REX_STORE_U8(ctx.r31.u32 + 336, ctx.r28.u8);
	// stb r28,324(r31)
	REX_STORE_U8(ctx.r31.u32 + 324, ctx.r28.u8);
loc_8256699C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

DEFINE_REX_FUNC(sub_82580070) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82580078;
	__savegprlr_23(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r23,36
	ctx.r23.s64 = 36;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825800a0
	if (!ctx.cr6.eq) goto loc_825800A0;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x825800ac
	goto loc_825800AC;
loc_825800A0:
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r8,r10,r23
	ctx.r8.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
loc_825800AC:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,1820
	ctx.r10.s64 = 119275520;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// ori r10,r10,29127
	ctx.r10.u64 = ctx.r10.u64 | 29127;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x82580114
	if (!ctx.cr6.lt) goto loc_82580114;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x825800DC;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82216678
	ctx.lr = 0x825800E8;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x825800EC;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x82580100;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82580110;
	sub_8235EC48(ctx, base);
	// b 0x825803cc
	goto loc_825803CC;
loc_82580114:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82580250
	if (!ctx.cr6.lt) goto loc_82580250;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82580138
	if (!ctx.cr6.lt) goto loc_82580138;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8258013c
	goto loc_8258013C;
loc_82580138:
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_8258013C:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82580148
	if (!ctx.cr6.lt) goto loc_82580148;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82580148:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r24,r11,36
	ctx.r24.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(36));
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82580164;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subf r11,r11,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// divw r26,r11,r23
	ctx.r26.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// mulli r25,r26,36
	ctx.r25.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(36));
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82580188
	if (ctx.cr0.eq) goto loc_82580188;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x825803d8
	ctx.lr = 0x82580188;
	sub_825803D8(ctx, base);
loc_82580188:
	// lwz r28,4(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// b 0x825801b0
	goto loc_825801B0;
loc_82580194:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x825801a8
	if (ctx.cr6.eq) goto loc_825801A8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x825803d8
	ctx.lr = 0x825801A8;
	sub_825803D8(ctx, base);
loc_825801A8:
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// addi r27,r27,36
	ctx.r27.s64 = ctx.r27.s64 + 36;
loc_825801B0:
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82580194
	if (!ctx.cr6.eq) goto loc_82580194;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r27,8(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mulli r11,r11,36
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(36));
	// add r28,r11,r30
	ctx.r28.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82580204
	if (ctx.cr6.eq) goto loc_82580204;
	// subf r11,r25,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r25.u64;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r29,r11,-36
	ctx.r29.s64 = ctx.r11.s64 + -36;
loc_825801E0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x825801f4
	if (ctx.cr6.eq) goto loc_825801F4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825803d8
	ctx.lr = 0x825801F4;
	sub_825803D8(ctx, base);
loc_825801F4:
	// addi r29,r29,36
	ctx.r29.s64 = ctx.r29.s64 + 36;
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x825801e0
	if (!ctx.cr6.eq) goto loc_825801E0;
loc_82580204:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r3.u64;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82580234
	if (ctx.cr6.eq) goto loc_82580234;
	// bl 0x82580008
	ctx.lr = 0x82580224;
	sub_82580008(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82580234
	if (ctx.cr6.eq) goto loc_82580234;
	// bl 0x825e0378
	ctx.lr = 0x82580234;
	sub_825E0378(ctx, base);
loc_82580234:
	// mulli r11,r29,36
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(36));
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// add r10,r24,r30
	ctx.r10.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x825803cc
	goto loc_825803CC;
loc_82580250:
	// subf r11,r29,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82580318
	if (!ctx.cr6.lt) goto loc_82580318;
	// bl 0x825803d8
	ctx.lr = 0x8258026C;
	sub_825803D8(ctx, base);
	// addi r30,r29,36
	ctx.r30.s64 = ctx.r29.s64 + 36;
	// lwz r27,8(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x825802a4
	if (ctx.cr6.eq) goto loc_825802A4;
	// addi r28,r30,-36
	ctx.r28.s64 = ctx.r30.s64 + -36;
loc_82580280:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82580294
	if (ctx.cr6.eq) goto loc_82580294;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825803d8
	ctx.lr = 0x82580294;
	sub_825803D8(ctx, base);
loc_82580294:
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// addi r30,r30,36
	ctx.r30.s64 = ctx.r30.s64 + 36;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82580280
	if (!ctx.cr6.eq) goto loc_82580280;
loc_825802A4:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// divw r11,r10,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
	// subfic r30,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r30.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825802e0
	if (ctx.cr6.eq) goto loc_825802E0;
loc_825802C0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x825802d4
	if (ctx.cr6.eq) goto loc_825802D4;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825803d8
	ctx.lr = 0x825802D4;
	sub_825803D8(ctx, base);
loc_825802D4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// bne 0x825802c0
	if (!ctx.cr0.eq) goto loc_825802C0;
loc_825802E0:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// addi r28,r11,-36
	ctx.r28.s64 = ctx.r11.s64 + -36;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x825803ac
	if (ctx.cr6.eq) goto loc_825803AC;
loc_825802FC:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82580528
	ctx.lr = 0x82580308;
	sub_82580528(ctx, base);
	// addi r30,r30,36
	ctx.r30.s64 = ctx.r30.s64 + 36;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x825802fc
	if (!ctx.cr6.eq) goto loc_825802FC;
	// b 0x825803ac
	goto loc_825803AC;
loc_82580318:
	// bl 0x825803d8
	ctx.lr = 0x8258031C;
	sub_825803D8(ctx, base);
	// lwz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r28,-36
	ctx.r30.s64 = ctx.r28.s64 + -36;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82580358
	if (ctx.cr6.eq) goto loc_82580358;
loc_82580334:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82580348
	if (ctx.cr6.eq) goto loc_82580348;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x825803d8
	ctx.lr = 0x82580348;
	sub_825803D8(ctx, base);
loc_82580348:
	// addi r26,r26,36
	ctx.r26.s64 = ctx.r26.s64 + 36;
	// addi r27,r27,36
	ctx.r27.s64 = ctx.r27.s64 + 36;
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82580334
	if (!ctx.cr6.eq) goto loc_82580334;
loc_82580358:
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82580384
	if (ctx.cr6.eq) goto loc_82580384;
	// subf r30,r30,r28
	ctx.r30.u64 = ctx.r28.u64 - ctx.r30.u64;
loc_8258036C:
	// addi r31,r31,-36
	ctx.r31.s64 = ctx.r31.s64 + -36;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r30,r31
	ctx.r3.u64 = ctx.r30.u64 + ctx.r31.u64;
	// bl 0x82580528
	ctx.lr = 0x8258037C;
	sub_82580528(ctx, base);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8258036c
	if (!ctx.cr6.eq) goto loc_8258036C;
loc_82580384:
	// addi r30,r29,36
	ctx.r30.s64 = ctx.r29.s64 + 36;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825803ac
	if (ctx.cr6.eq) goto loc_825803AC;
loc_82580394:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82580528
	ctx.lr = 0x825803A0;
	sub_82580528(ctx, base);
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82580394
	if (!ctx.cr6.eq) goto loc_82580394;
loc_825803AC:
	// lwz r31,132(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825803cc
	if (ctx.cr6.eq) goto loc_825803CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,136(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x8257fce8
	ctx.lr = 0x825803C4;
	sub_8257FCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825803CC;
	sub_825E0378(ctx, base);
loc_825803CC:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82597360) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// b 0x82596fd8
	sub_82596FD8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82597630) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82597638;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r29,-12836(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -12836);
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,8(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8259769c
	if (ctx.cr6.eq) goto loc_8259769C;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
loc_82597658:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82597690
	if (ctx.cr6.eq) goto loc_82597690;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82597678
	if (ctx.cr6.eq) goto loc_82597678;
	// lwz r3,-12824(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x82597678;
	sub_82599798(ctx, base);
loc_82597678:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82597688
	if (ctx.cr6.eq) goto loc_82597688;
	// bl 0x825e0378
	ctx.lr = 0x82597688;
	sub_825E0378(ctx, base);
loc_82597688:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82597690:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82597658
	if (!ctx.cr6.eq) goto loc_82597658;
loc_8259769C:
	// lwz r5,8(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x825976cc
	if (ctx.cr6.eq) goto loc_825976CC;
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
	// ble 0x825976c8
	if (!ctx.cr0.gt) goto loc_825976C8;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x825976C8;
	sub_827388E8(ctx, base);
loc_825976C8:
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
loc_825976CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259BBC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8259BBC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r3,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r31,-12820(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -12820);
	// addi r29,r31,36
	ctx.r29.s64 = ctx.r31.s64 + 36;
	// lbz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 64);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259bbf4
	if (ctx.cr0.eq) goto loc_8259BBF4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x8259BBF4;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8259BBF4:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8259bc14
	if (!ctx.cr6.eq) goto loc_8259BC14;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8259bc20
	goto loc_8259BC20;
loc_8259BC14:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8259BC20:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8259bc44
	if (!ctx.cr6.lt) goto loc_8259BC44;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r30,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r30.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8259bc4c
	goto loc_8259BC4C;
loc_8259BC44:
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// bl 0x8259acf8
	ctx.lr = 0x8259BC4C;
	sub_8259ACF8(ctx, base);
loc_8259BC4C:
	// lbz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259bc60
	if (ctx.cr0.eq) goto loc_8259BC60;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x8259BC60;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8259BC60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259FF58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8259FF60;
	__savegprlr_25(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mulli r10,r11,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// stw r30,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// stw r30,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r30.u32);
	// lwz r11,-12824(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12824);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8259fcf0
	ctx.lr = 0x8259FFA0;
	sub_8259FCF0(ctx, base);
	// lwz r26,100(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r25,104(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x825a0198
	if (ctx.cr6.eq) goto loc_825A0198;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r26,1
	ctx.r31.s64 = ctx.r26.s64 + 1;
	// addi r27,r11,4824
	ctx.r27.s64 = ctx.r11.s64 + 4824;
loc_8259FFBC:
	// lwz r11,-12824(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12824);
	// addi r9,r1,113
	ctx.r9.s64 = ctx.r1.s64 + 113;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mulli r10,r10,144
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(144));
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825a0044
	if (ctx.cr6.eq) goto loc_825A0044;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8259FFE4:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8259ffe4
	if (!ctx.cr6.eq) goto loc_8259FFE4;
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r8,r1,113
	ctx.r8.s64 = ctx.r1.s64 + 113;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// li r9,127
	ctx.r9.s64 = 127;
	// stb r6,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r6.u8);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x825a0040
	if (ctx.cr0.eq) goto loc_825A0040;
loc_825A0014:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x825a002c
	if (!ctx.cr6.gt) goto loc_825A002C;
	// stb r10,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_825A002C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x825a0014
	if (!ctx.cr0.eq) goto loc_825A0014;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825a0044
	if (ctx.cr6.eq) goto loc_825A0044;
loc_825A0040:
	// stb r30,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
loc_825A0044:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// addi r10,r1,113
	ctx.r10.s64 = ctx.r1.s64 + 113;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r9,58
	ctx.r9.s64 = 58;
	// stb r7,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r7.u8);
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
loc_825A0064:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x825a007c
	if (!ctx.cr6.gt) goto loc_825A007C;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_825A007C:
	// lbz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x825a0064
	if (!ctx.cr0.eq) goto loc_825A0064;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825a0094
	if (ctx.cr6.eq) goto loc_825A0094;
	// stb r30,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r30.u8);
loc_825A0094:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_825A009C:
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825a009c
	if (!ctx.cr6.eq) goto loc_825A009C;
	// subf r9,r31,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r31.u64;
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r1,113
	ctx.r8.s64 = ctx.r1.s64 + 113;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// stb r6,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r6.u8);
	// b 0x825a00f4
	goto loc_825A00F4;
loc_825A00D8:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x825a00f0
	if (!ctx.cr6.gt) goto loc_825A00F0;
	// stb r10,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_825A00F0:
	// lbz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
loc_825A00F4:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x825a00d8
	if (!ctx.cr0.eq) goto loc_825A00D8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825a0108
	if (ctx.cr6.eq) goto loc_825A0108;
	// stb r30,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
loc_825A0108:
	// addi r3,r1,113
	ctx.r3.s64 = ctx.r1.s64 + 113;
	// bl 0x825995a0
	ctx.lr = 0x825A0110;
	sub_825995A0(ctx, base);
	// lwz r11,-12824(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12824);
	// mulli r10,r3,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(52));
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r9,10
	ctx.r9.s64 = 10;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r9,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// beq cr6,0x825a0188
	if (ctx.cr6.eq) goto loc_825A0188;
	// lwz r10,16(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// addi r11,r28,12
	ctx.r11.s64 = ctx.r28.s64 + 12;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825a014c
	if (!ctx.cr6.eq) goto loc_825A014C;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// b 0x825a0158
	goto loc_825A0158;
loc_825A014C:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_825A0158:
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x825a017c
	if (!ctx.cr6.lt) goto loc_825A017C;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x825a0188
	goto loc_825A0188;
loc_825A017C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x8259acf8
	ctx.lr = 0x825A0188;
	sub_8259ACF8(ctx, base);
loc_825A0188:
	// addi r31,r31,128
	ctx.r31.s64 = ctx.r31.s64 + 128;
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x8259ffbc
	if (!ctx.cr6.eq) goto loc_8259FFBC;
loc_825A0198:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x825a01a8
	if (ctx.cr6.eq) goto loc_825A01A8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825e0378
	ctx.lr = 0x825A01A8;
	sub_825E0378(ctx, base);
loc_825A01A8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AF748) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,44(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// b 0x825acd90
	sub_825ACD90(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AFA28) {
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
	// bl 0x825e0178
	ctx.lr = 0x825AFA48;
	sub_825E0178(ctx, base);
	// lbz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825afa68
	if (ctx.cr0.eq) goto loc_825AFA68;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,263
	ctx.r4.s64 = 263;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825dfd80
	ctx.lr = 0x825AFA68;
	sub_825DFD80(ctx, base);
loc_825AFA68:
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
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

DEFINE_REX_FUNC(sub_825B31B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825B31B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r28,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r28.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b31f8
	if (ctx.cr6.eq) goto loc_825B31F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r29,r4,16
	ctx.r29.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B31EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r9,21(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 21);
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825b3208
	if (ctx.cr6.lt) goto loc_825B3208;
loc_825B31F8:
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_825B3208:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// rlwinm r11,r29,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFFFFFF00;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B5F78) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,0(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_825B62D0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,224(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 224);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_825B62DC:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x825b62f8
	if (ctx.cr6.eq) goto loc_825B62F8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825b62dc
	if (!ctx.cr6.eq) goto loc_825B62DC;
	// blr 
	return;
loc_825B62F8:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// b 0x825bf380
	sub_825BF380(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B7B50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825B7B58;
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
	ctx.lr = 0x825B7B78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b7bc0
	if (ctx.cr6.eq) goto loc_825B7BC0;
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
	ctx.lr = 0x825B7BA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmpw cr6,r29,r5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x825b7bc0
	if (ctx.cr6.lt) goto loc_825B7BC0;
loc_825B7BB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825B7BC0:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b7c5c
	if (ctx.cr6.eq) goto loc_825B7C5C;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lhz r31,1(r11)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r11.u32 + 1);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,65535
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 65535, ctx.xer);
	// beq cr6,0x825b7c5c
	if (ctx.cr6.eq) goto loc_825B7C5C;
loc_825B7BE0:
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
	ctx.lr = 0x825B7BF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x825b7c34
	if (ctx.cr6.eq) goto loc_825B7C34;
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
	ctx.lr = 0x825B7C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmpw cr6,r29,r7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x825b7bb4
	if (!ctx.cr6.lt) goto loc_825B7BB4;
loc_825B7C34:
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
	ctx.lr = 0x825B7C4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,65535
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 65535, ctx.xer);
	// bne cr6,0x825b7be0
	if (!ctx.cr6.eq) goto loc_825B7BE0;
loc_825B7C5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BDAD0) {
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
	// addi r9,r11,18140
	ctx.r9.s64 = ctx.r11.s64 + 18140;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x825bdb0c
	if (ctx.cr6.eq) goto loc_825BDB0C;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32805
	ctx.r4.u64 = ctx.r4.u64 | 32805;
	// bl 0x8263b710
	ctx.lr = 0x825BDB08;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825BDB0C:
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

DEFINE_REX_FUNC(sub_825BF820) {
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
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,248(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 248);
	// li r31,0
	ctx.r31.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825BF858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825bf890
	if (!ctx.cr6.eq) goto loc_825BF890;
	// bl 0x82639f50
	ctx.lr = 0x825BF864;
	sub_82639F50(ctx, base);
	// cmpwi cr6,r3,997
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 997, ctx.xer);
	// beq cr6,0x825bf890
	if (ctx.cr6.eq) goto loc_825BF890;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x825bf894
	if (!ctx.cr6.gt) goto loc_825BF894;
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
loc_825BF890:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825BF894:
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

DEFINE_REX_FUNC(sub_825C3010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825C3018;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x825C3034;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// addi r3,r31,-12
	ctx.r3.s64 = ctx.r31.s64 + -12;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// subfe r4,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r5,r8,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r11,-12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C3068;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x825C3074;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C67C0) {
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
	// bl 0x8273af28
	ctx.lr = 0x825C67D8;
	__savefpr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,56(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,32(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f30,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f30.f64 = double(temp.f32);
	// addi r9,r11,12468
	ctx.r9.s64 = ctx.r11.s64 + 12468;
	// lfs f29,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,120(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f28.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,64(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// lhz r4,1(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 1);
	// lfs f31,-232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c688c
	if (ctx.cr6.eq) goto loc_825C688C;
	// lwz r7,124(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// rlwinm r10,r4,2,14,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// lwzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x825c6888
	if (!ctx.cr6.eq) goto loc_825C6888;
	// lwz r7,128(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x825c6844
	if (ctx.cr6.eq) goto loc_825C6844;
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825c6888
	if (ctx.cr6.eq) goto loc_825C6888;
loc_825C6844:
	// cmplwi cr6,r8,65535
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 65535, ctx.xer);
	// beq cr6,0x825c688c
	if (ctx.cr6.eq) goto loc_825C688C;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_825C6850:
	// lwz r3,64(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,132(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r8,24(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825C6870;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r11,r3,2,14,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FFFC;
	// cmplwi cr6,r7,65535
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 65535, ctx.xer);
	// bne cr6,0x825c6850
	if (!ctx.cr6.eq) goto loc_825C6850;
	// b 0x825c688c
	goto loc_825C688C;
loc_825C6888:
	// lfs f31,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
loc_825C688C:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lfs f0,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f29.f64));
	// fmuls f1,f11,f30
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8273af74
	ctx.lr = 0x825C68B0;
	__restfpr_28(ctx, base);
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

DEFINE_REX_FUNC(sub_825CFE68) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r10,-4080
	ctx.r9.s64 = ctx.r10.s64 + -4080;
	// lhz r7,9(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 9);
	// lfd f0,680(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 680);
	// std r7,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825D1420) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x825D1428;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r3,184(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 184);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d147c
	if (ctx.cr6.eq) goto loc_825D147C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lhz r4,7(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 7);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825D1470;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825d1484
	if (!ctx.cr6.eq) goto loc_825D1484;
loc_825D147C:
	// lis r25,-30009
	ctx.r25.s64 = -1966669824;
	// ori r25,r25,10
	ctx.r25.u64 = ctx.r25.u64 | 10;
loc_825D1484:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// blt cr6,0x825d164c
	if (ctx.cr6.lt) goto loc_825D164C;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d14d4
	if (ctx.cr6.eq) goto loc_825D14D4;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// lhz r4,7(r9)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + 7);
	// lwz r8,16(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r7,20(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// lwz r3,56(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 56);
	// bl 0x825bb358
	ctx.lr = 0x825D14C8;
	sub_825BB358(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_825D14D4:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r26,r7,27,8,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0xFFFFFF;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825D14F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r11,r3,r26
	ctx.r11.u64 = ctx.r3.u64 + ctx.r26.u64;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x825d1648
	if (ctx.cr6.lt) goto loc_825D1648;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x825d1648
	if (ctx.cr6.lt) goto loc_825D1648;
	// lhz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 56);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d1554
	if (ctx.cr6.eq) goto loc_825D1554;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d1f20
	ctx.lr = 0x825D1528;
	sub_825D1F20(ctx, base);
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// subf r9,r26,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r26.u64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// rotlwi r11,r9,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// lhz r8,2(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// divw r6,r9,r8
	ctx.r6.u64 = uint32_t((ctx.r8.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r9.s32 / ctx.r8.s32 : 0);
	// andc r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// clrlwi r30,r6,16
	ctx.r30.u64 = ctx.r6.u32 & 0xFFFF;
	// twlgei r5,-1
	if (ctx.r5.s32 == -1 || ctx.r5.u32 > 4294967295u) ppc_trap(ctx, base, 0);
loc_825D1554:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r28,r11,12236
	ctx.r28.s64 = ctx.r11.s64 + 12236;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,232(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x825d159c
	if (ctx.cr6.eq) goto loc_825D159C;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lhz r4,7(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 7);
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r3,56(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// b 0x825d15b4
	goto loc_825D15B4;
loc_825D159C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r4,7(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 7);
	// lwz r9,88(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_825D15B4:
	// bctrl 
	ctx.lr = 0x825D15B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r29,r30,16
	ctx.r29.u64 = ctx.r30.u32 & 0xFFFF;
	// lfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_825D15C4:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// bl 0x825b5ba0
	ctx.lr = 0x825D15DC;
	sub_825B5BA0(ctx, base);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x825d15c4
	if (!ctx.cr6.gt) goto loc_825D15C4;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d1628
	if (ctx.cr6.eq) goto loc_825D1628;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lhz r4,7(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 7);
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r3,56(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// b 0x825d1640
	goto loc_825D1640;
loc_825D1628:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r4,7(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 7);
	// lwz r9,84(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_825D1640:
	// bctrl 
	ctx.lr = 0x825D1644;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// subf r30,r26,r27
	ctx.r30.u64 = ctx.r27.u64 - ctx.r26.u64;
loc_825D1648:
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
loc_825D164C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E6758) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825E6760;
	__savegprlr_27(ctx, base);
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
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E678C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// bl 0x825e6510
	ctx.lr = 0x825E67B4;
	sub_825E6510(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825e67c4
	if (ctx.cr6.eq) goto loc_825E67C4;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_825E67C4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E7E98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x825E7EA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E7EBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825e7ef8
	if (ctx.cr0.eq) goto loc_825E7EF8;
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,60
	ctx.r30.s64 = ctx.r31.s64 + 60;
	// bl 0x8273c660
	ctx.lr = 0x825E7ED0;
	sub_8273C660(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-16379
	ctx.r11.s64 = -1073414144;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// ori r3,r11,3
	ctx.r3.u64 = ctx.r11.u64 | 3;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r10,66(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 66);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r10,66(r31)
	REX_STORE_U8(ctx.r31.u32 + 66, ctx.r10.u8);
	// stw r3,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r3.u32);
	// b 0x825e81e8
	goto loc_825E81E8;
loc_825E7EF8:
	// lwz r4,76(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825e7f3c
	if (ctx.cr6.eq) goto loc_825E7F3C;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r5,r31,60
	ctx.r5.s64 = ctx.r31.s64 + 60;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E7F1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lhz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 4);
	// sth r11,64(r31)
	REX_STORE_U16(ctx.r31.u32 + 64, ctx.r11.u16);
	// lbz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 6);
	// stb r11,66(r31)
	REX_STORE_U8(ctx.r31.u32 + 66, ctx.r11.u8);
loc_825E7F3C:
	// addi r27,r29,64
	ctx.r27.s64 = ctx.r29.s64 + 64;
	// addi r5,r31,60
	ctx.r5.s64 = ctx.r31.s64 + 60;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825f30d0
	ctx.lr = 0x825E7F50;
	sub_825F30D0(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x8273c660
	ctx.lr = 0x825E7F58;
	sub_8273C660(ctx, base);
	// lbz r11,66(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 66);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r26,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// stb r11,66(r31)
	REX_STORE_U8(ctx.r31.u32 + 66, ctx.r11.u8);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// bgt cr6,0x825e8118
	if (ctx.cr6.gt) goto loc_825E8118;
	// beq cr6,0x825e8040
	if (ctx.cr6.eq) goto loc_825E8040;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825e8038
	if (ctx.cr6.eq) goto loc_825E8038;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x825e8008
	if (ctx.cr6.eq) goto loc_825E8008;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// beq cr6,0x825e7fd8
	if (ctx.cr6.eq) goto loc_825E7FD8;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bne cr6,0x825e8130
	if (!ctx.cr6.eq) goto loc_825E8130;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r28,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r28.u32);
	// stw r11,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r11.u32);
	// sth r10,228(r1)
	REX_STORE_U16(ctx.r1.u32 + 228, ctx.r10.u16);
	// stb r9,230(r1)
	REX_STORE_U8(ctx.r1.u32 + 230, ctx.r9.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_825E7FCC:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E7FD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e81d4
	goto loc_825E81D4;
loc_825E7FD8:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stw r28,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r28.u32);
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r11,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r11.u32);
	// sth r10,212(r1)
	REX_STORE_U16(ctx.r1.u32 + 212, ctx.r10.u16);
	// stb r9,214(r1)
	REX_STORE_U8(ctx.r1.u32 + 214, ctx.r9.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x825e7fcc
	goto loc_825E7FCC;
loc_825E8008:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// stw r28,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r28.u32);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// sth r10,196(r1)
	REX_STORE_U16(ctx.r1.u32 + 196, ctx.r10.u16);
	// stb r9,198(r1)
	REX_STORE_U8(ctx.r1.u32 + 198, ctx.r9.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x825e81c8
	goto loc_825E81C8;
loc_825E8038:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// b 0x825e81d8
	goto loc_825E81D8;
loc_825E8040:
	// lwz r4,76(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 76);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825e8084
	if (ctx.cr6.eq) goto loc_825E8084;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r5,r31,72
	ctx.r5.s64 = ctx.r31.s64 + 72;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E8064;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// lhz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 4);
	// sth r11,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// lbz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 6);
	// stb r11,78(r31)
	REX_STORE_U8(ctx.r31.u32 + 78, ctx.r11.u8);
loc_825E8084:
	// addi r31,r31,72
	ctx.r31.s64 = ctx.r31.s64 + 72;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x825f30d0
	ctx.lr = 0x825E8098;
	sub_825F30D0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8273c660
	ctx.lr = 0x825E80A0;
	sub_8273C660(ctx, base);
	// lwz r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// lhz r10,164(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 164);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lbz r9,166(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 166);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lhz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// lbz r6,86(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// lwz r30,160(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// sth r10,116(r1)
	REX_STORE_U16(ctx.r1.u32 + 116, ctx.r10.u16);
	// stb r9,118(r1)
	REX_STORE_U8(ctx.r1.u32 + 118, ctx.r9.u8);
	// stw r28,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r28.u32);
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// stw r8,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// sth r7,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r7.u16);
	// stb r6,134(r1)
	REX_STORE_U8(ctx.r1.u32 + 134, ctx.r6.u8);
	// lbz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 6);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r11,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r11.u8);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E8108;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273c660
	ctx.lr = 0x825E8114;
	sub_8273C660(ctx, base);
	// b 0x825e81d8
	goto loc_825E81D8;
loc_825E8118:
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// beq cr6,0x825e819c
	if (ctx.cr6.eq) goto loc_825E819C;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// beq cr6,0x825e816c
	if (ctx.cr6.eq) goto loc_825E816C;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x825e813c
	if (ctx.cr6.eq) goto loc_825E813C;
loc_825E8130:
	// lis r31,-16379
	ctx.r31.s64 = -1073414144;
	// ori r31,r31,1
	ctx.r31.u64 = ctx.r31.u64 | 1;
	// b 0x825e81d8
	goto loc_825E81D8;
loc_825E813C:
	// lbz r11,86(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// stw r28,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r28.u32);
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stb r11,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r11.u8);
	// sth r10,148(r1)
	REX_STORE_U16(ctx.r1.u32 + 148, ctx.r10.u16);
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// b 0x825e81c8
	goto loc_825E81C8;
loc_825E816C:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// stw r28,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r28.u32);
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r11,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// stb r9,182(r1)
	REX_STORE_U8(ctx.r1.u32 + 182, ctx.r9.u8);
	// sth r10,180(r1)
	REX_STORE_U16(ctx.r1.u32 + 180, ctx.r10.u16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x825e81c8
	goto loc_825E81C8;
loc_825E819C:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lhz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// sth r10,100(r1)
	REX_STORE_U16(ctx.r1.u32 + 100, ctx.r10.u16);
	// stb r9,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r9.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
loc_825E81C8:
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E81D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E81D4:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825E81D8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273c660
	ctx.lr = 0x825E81E0;
	sub_8273C660(ctx, base);
	// stw r31,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r31.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825E81E8:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FBFF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// std r5,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// addi r11,r1,32
	ctx.r11.s64 = ctx.r1.s64 + 32;
	// std r7,48(r1)
	REX_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// std r8,56(r1)
	REX_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// std r9,64(r1)
	REX_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// addi r9,r1,48
	ctx.r9.s64 = ctx.r1.s64 + 48;
	// std r10,72(r1)
	REX_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r10,r1,64
	ctx.r10.s64 = ctx.r1.s64 + 64;
	// std r6,40(r1)
	REX_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// vslw128 v58,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vmrglw128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vor128 v13,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// vmrghw128 v62,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrglw128 v61,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrghw128 v60,v59,v58
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vupkd3d128 v57,v59,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v57 = vTemp;
	// vor128 v55,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v54,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vmrghw128 v59,v58,v59
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrglw128 v58,v56,v62
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vrlimi128 v13,v63,12,2
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v63.f32), 78), 12));
	// vmrghw128 v53,v56,v62
	simde_mm_store_si128((simde__m128i*)ctx.v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vor128 v0,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmrghw128 v52,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vrlimi128 v55,v56,3,2
	simde_mm_store_ps(ctx.v55.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v56.f32), 78), 3));
	// vmrglw128 v63,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vrlimi128 v54,v61,12,2
	simde_mm_store_ps(ctx.v54.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v61.f32), 78), 12));
	// vpermwi128 v56,v58,187
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x44));
	// vpermwi128 v61,v53,5
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0xFA));
	// vrlimi128 v0,v62,3,2
	simde_mm_store_ps(ctx.v0.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v62.f32), 78), 3));
	// vpermwi128 v62,v52,5
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0xFA));
	// vpermwi128 v51,v63,187
	simde_mm_store_si128((simde__m128i*)ctx.v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x44));
	// vmulfp128 v4,v55,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v54.f32)));
	// vpermwi128 v11,v58,5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFA));
	// vmulfp128 v5,v61,v56
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vpermwi128 v12,v53,187
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0x44));
	// vpermwi128 v10,v52,187
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0x44));
	// vmulfp128 v3,v62,v51
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v51.f32)));
	// vpermwi128 v9,v63,5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFA));
	// vpermwi128 v55,v58,97
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x9E));
	// vpermwi128 v8,v58,182
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x49));
	// vpermwi128 v62,v63,97
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x9E));
	// vpermwi128 v61,v52,132
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0x7B));
	// vpermwi128 v56,v53,132
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0x7B));
	// vpermwi128 v7,v53,237
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0x12));
	// vpermwi128 v6,v63,182
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x49));
	// vpermwi128 v58,v58,204
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x33));
	// vnmsubfp v2,v12,v11,v5
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v5,v52,237
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0x12));
	// vnmsubfp v12,v0,v13,v4
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v0,v10,v9,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor128 v54,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// vor128 v51,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vor128 v50,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vpermwi128 v12,v54,198
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0x39));
	// vpermwi128 v11,v54,156
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0x63));
	// vpermwi128 v13,v50,156
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.u32), 0x63));
	// vpermwi128 v0,v50,198
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.u32), 0x39));
	// vor128 v49,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vor128 v48,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vor128 v47,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vor128 v46,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vrlimi128 v49,v51,4,2
	simde_mm_store_ps(ctx.v49.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v49.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 78), 4));
	// vrlimi128 v48,v51,8,3
	simde_mm_store_ps(ctx.v48.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 57), 8));
	// vrlimi128 v47,v51,8,1
	simde_mm_store_ps(ctx.v47.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v47.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 147), 8));
	// vrlimi128 v46,v51,4,0
	simde_mm_store_ps(ctx.v46.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v46.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 228), 4));
	// vrlimi128 v0,v51,1,1
	simde_mm_store_ps(ctx.v0.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 147), 1));
	// vmulfp128 v3,v61,v49
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v49.f32)));
	// vmulfp128 v4,v62,v48
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v48.f32)));
	// vrlimi128 v13,v51,2,2
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 78), 2));
	// vmulfp128 v2,v55,v47
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v47.f32)));
	// vmulfp128 v1,v56,v46
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v46.f32)));
	// vnmsubfp v31,v8,v0,v2
	simde_mm_store_ps(ctx.v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsldoi128 v62,v50,v51,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), 8));
	// vxor128 v2,v58,v60
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vrlimi128 v12,v51,1,3
	simde_mm_store_ps(ctx.v12.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 57), 1));
	// vpermwi128 v63,v63,204
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x33));
	// vrlimi128 v11,v51,2,0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 228), 2));
	// vpermwi128 v61,v52,114
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0x8D));
	// vpermwi128 v0,v54,78
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0xB1));
	// vnmsubfp v1,v7,v13,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v8,v62,56
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xC7));
	// li r11,16
	ctx.r11.s64 = 16;
	// vnmsubfp v4,v6,v12,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vxor128 v12,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vnmsubfp v6,v5,v11,v3
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vxor128 v11,v61,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vrlimi128 v0,v51,9,3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 57), 9));
	// vspltw128 v9,v57,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0x0));
	// vmaddfp v8,v2,v8,v31
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vpermwi128 v62,v53,114
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.u32), 0x8D));
	// vpermwi128 v10,v50,78
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v50.u32), 0xB1));
	// li r10,32
	ctx.r10.s64 = 32;
	// vmrglw128 v58,v54,v51
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// li r9,48
	ctx.r9.s64 = 48;
	// vxor128 v13,v62,v59
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vrlimi128 v10,v51,9,1
	simde_mm_store_ps(ctx.v10.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v51.f32), 147), 9));
	// vpermwi128 v7,v58,52
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xCB));
	// vmaddfp v5,v13,v10,v1
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v6,v11,v0,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v7,v12,v7,v4
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vor128 v63,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vmsum4fp128 v11,v63,v53
	simde_mm_store_ps(ctx.v11.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v53.f32), 0xFF));
	// stvx128 v11,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp v0,v11
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v11.f32)));
	// vnmsubfp v8,v11,v0,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v10,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmaddfp v0,v0,v8,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v12,v11,v0,v9
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v0,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v10,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v63,v13
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v62,v5,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v61,v7,v13
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v60,v6,v13
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82620898) {
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
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826208d0
	if (ctx.cr0.eq) goto loc_826208D0;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r4,r11,4,28,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xF;
	// bl 0x8261fa18
	ctx.lr = 0x826208CC;
	sub_8261FA18(ctx, base);
	// b 0x82620914
	goto loc_82620914;
loc_826208D0:
	// lwz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,14,18,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 14) & 0x3FFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,29,17,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x7FFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_82620914:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82627A58) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82627ad0
	if (ctx.cr6.eq) goto loc_82627AD0;
	// bl 0x82855964
	ctx.lr = 0x82627A7C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82627a90
	if (!ctx.cr6.eq) goto loc_82627A90;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2256);
	// b 0x82627a98
	goto loc_82627A98;
loc_82627A90:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2252);
loc_82627A98:
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82627ab0
	if (!ctx.cr6.eq) goto loc_82627AB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826274c0
	ctx.lr = 0x82627AB0;
	sub_826274C0(ctx, base);
loc_82627AB0:
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// lwz r10,10908(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// subf r9,r30,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subfc r11,r11,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
loc_82627AD0:
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

DEFINE_REX_FUNC(sub_8262EA90) {
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
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r30,13740(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 13740);
	// li r4,34
	ctx.r4.s64 = 34;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82626840
	ctx.lr = 0x8262EAB8;
	sub_82626840(ctx, base);
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8262ead0
	if (ctx.cr0.eq) goto loc_8262EAD0;
	// lwz r8,16936(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16936);
	// b 0x8262eb28
	goto loc_8262EB28;
loc_8262EAD0:
	// rlwinm r11,r8,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// stw r8,13740(r31)
	REX_STORE_U32(ctx.r31.u32 + 13740, ctx.r8.u32);
	// clrlwi r10,r8,3
	ctx.r10.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r3,r11,-16384
	ctx.r3.s64 = ctx.r11.s64 + -1073741824;
	// bne cr6,0x8262eb08
	if (!ctx.cr6.eq) goto loc_8262EB08;
	// lwz r11,13724(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13724);
	// stw r3,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r3.u32);
	// b 0x8262eb20
	goto loc_8262EB20;
loc_8262EB08:
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// lwz r11,13744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13744);
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
loc_8262EB20:
	// addi r4,r3,136
	ctx.r4.s64 = ctx.r3.s64 + 136;
	// bl 0x826323d0
	ctx.lr = 0x8262EB28;
	sub_826323D0(ctx, base);
loc_8262EB28:
	// addi r3,r8,8
	ctx.r3.s64 = ctx.r8.s64 + 8;
	// addi r11,r8,136
	ctx.r11.s64 = ctx.r8.s64 + 136;
	// stw r3,13744(r31)
	REX_STORE_U32(ctx.r31.u32 + 13744, ctx.r3.u32);
	// stw r11,13748(r31)
	REX_STORE_U32(ctx.r31.u32 + 13748, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82633EB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82633EC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,4(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r7,8(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r6,12(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r5,16(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r3,20(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r4,24(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r7,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r6,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// stw r5,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// bne cr6,0x82633f18
	if (!ctx.cr6.eq) goto loc_82633F18;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// b 0x82633f24
	goto loc_82633F24;
loc_82633F18:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
loc_82633F24:
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// lwz r11,15036(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15036);
	// addi r8,r1,124
	ctx.r8.s64 = ctx.r1.s64 + 124;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// beq cr6,0x82633f74
	if (ctx.cr6.eq) goto loc_82633F74;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// rlwinm r11,r10,2,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x2;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,19,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0x1FFF;
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r9,r11
	ctx.r29.u64 = ctx.r9.u64 + ctx.r11.u64;
	// b 0x82633f7c
	goto loc_82633F7C;
loc_82633F74:
	// lwz r30,13752(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 13752);
	// lwz r29,13756(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 13756);
loc_82633F7C:
	// addi r28,r31,13932
	ctx.r28.s64 = ctx.r31.s64 + 13932;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x8273a030
	ctx.lr = 0x82633F90;
	sub_8273A030(ctx, base);
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r11,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r11.u8);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633be0
	ctx.lr = 0x82633FB4;
	sub_82633BE0(ctx, base);
	// lwz r11,21752(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21752);
	// lwz r10,21756(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21756);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r30,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r30.u16);
	// li r5,56
	ctx.r5.s64 = 56;
	// sth r29,146(r1)
	REX_STORE_U16(ctx.r1.u32 + 146, ctx.r29.u16);
	// sth r11,148(r1)
	REX_STORE_U16(ctx.r1.u32 + 148, ctx.r11.u16);
	// sth r10,150(r1)
	REX_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// bl 0x8273a030
	ctx.lr = 0x82633FDC;
	sub_8273A030(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x828562f4
	ctx.lr = 0x82633FE8;
	__imp__VdCallGraphicsNotificationRoutines(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263B3D0) {
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
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// bge cr6,0x8263b42c
	if (!ctx.cr6.lt) goto loc_8263B42C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,2008(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 2008);
	// bl 0x82855a84
	ctx.lr = 0x8263B400;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8263b45c
	if (ctx.cr0.lt) goto loc_8263B45C;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// slw r4,r11,r30
	ctx.r4.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r30.u8 & 0x3F));
	// bl 0x82855aa4
	ctx.lr = 0x8263B41C;
	__imp__KeSetAffinityThread(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a64
	ctx.lr = 0x8263B428;
	__imp__ObDereferenceObject(ctx, base);
	// b 0x8263b434
	goto loc_8263B434;
loc_8263B42C:
	// lis r31,-16384
	ctx.r31.s64 = -1073741824;
	// ori r31,r31,13
	ctx.r31.u64 = ctx.r31.u64 | 13;
loc_8263B434:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8263b45c
	if (ctx.cr6.lt) goto loc_8263B45C;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8263b454
	if (ctx.cr6.eq) goto loc_8263B454;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subfic r3,r11,31
	ctx.xer.ca = ctx.r11.u32 <= 31;
	ctx.r3.u64 = static_cast<uint64_t>(31) - ctx.r11.u64;
	// b 0x8263b468
	goto loc_8263B468;
loc_8263B454:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8263b468
	goto loc_8263B468;
loc_8263B45C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8263c0a8
	ctx.lr = 0x8263B464;
	sub_8263C0A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8263B468:
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

DEFINE_REX_FUNC(sub_82641188) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r3,-30280(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -30280);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82641C78) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82641cf8
	if (ctx.cr6.eq) goto loc_82641CF8;
	// b 0x82641cd0
	goto loc_82641CD0;
loc_82641CA4:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x82641a50
	ctx.lr = 0x82641CB8;
	sub_82641A50(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x8263b710
	ctx.lr = 0x82641CD0;
	sub_8263B710(ctx, base);
loc_82641CD0:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bne cr6,0x82641ca4
	if (!ctx.cr6.eq) goto loc_82641CA4;
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8263b710
	ctx.lr = 0x82641CF0;
	sub_8263B710(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82641CF8:
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

DEFINE_REX_FUNC(sub_82644468) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x82644a10
	sub_82644A10(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826444B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x826444C0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r11,5904
	ctx.r11.s64 = ctx.r11.s64 + 5904;
	// addi r10,r10,5884
	ctx.r10.s64 = ctx.r10.s64 + 5884;
	// addi r9,r9,5868
	ctx.r9.s64 = ctx.r9.s64 + 5868;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// addi r25,r3,44
	ctx.r25.s64 = ctx.r3.s64 + 44;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644504;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x827484a0
	ctx.lr = 0x82644508;
	sub_827484A0(ctx, base);
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826446c0
	if (ctx.cr6.eq) goto loc_826446C0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826427d0
	ctx.lr = 0x82644524;
	sub_826427D0(ctx, base);
	// lwz r3,156(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82644538
	if (ctx.cr6.eq) goto loc_82644538;
	// bl 0x8264cf40
	ctx.lr = 0x82644534;
	sub_8264CF40(ctx, base);
	// stw r24,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r24.u32);
loc_82644538:
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826445cc
	if (ctx.cr6.eq) goto loc_826445CC;
	// addi r28,r31,188
	ctx.r28.s64 = ctx.r31.s64 + 188;
	// b 0x826445bc
	goto loc_826445BC;
loc_8264454C:
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82644588
	if (ctx.cr0.eq) goto loc_82644588;
	// lwz r11,512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// addi r3,r31,488
	ctx.r3.s64 = ctx.r31.s64 + 488;
	// b 0x82644574
	goto loc_82644574;
loc_82644564:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82644580
	if (ctx.cr6.eq) goto loc_82644580;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82644574:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82644564
	if (!ctx.cr6.eq) goto loc_82644564;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82644580:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x82642bc8
	ctx.lr = 0x82644588;
	sub_82642BC8(ctx, base);
loc_82644588:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826445A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826445B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x826445BC;
	sub_8264CF40(ctx, base);
loc_826445BC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8264d328
	ctx.lr = 0x826445C4;
	sub_8264D328(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8264454c
	if (!ctx.cr0.eq) goto loc_8264454C;
loc_826445CC:
	// addi r26,r31,448
	ctx.r26.s64 = ctx.r31.s64 + 448;
	// b 0x82644648
	goto loc_82644648;
loc_826445D4:
	// lwz r4,44(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r3,16032(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16032);
	// bl 0x825d5a38
	ctx.lr = 0x826445E0;
	sub_825D5A38(ctx, base);
	// lwz r3,16032(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16032);
	// lwz r4,48(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x825d5a38
	ctx.lr = 0x826445EC;
	sub_825D5A38(ctx, base);
	// addi r28,r30,4
	ctx.r28.s64 = ctx.r30.s64 + 4;
	// b 0x82644628
	goto loc_82644628;
loc_826445F4:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r27,r29,4
	ctx.r27.s64 = ctx.r29.s64 + 4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264460C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644624;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x82644628;
	sub_8264CF40(ctx, base);
loc_82644628:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82647fb8
	ctx.lr = 0x82644630;
	sub_82647FB8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x826445f4
	if (!ctx.cr0.eq) goto loc_826445F4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826432c0
	ctx.lr = 0x82644640;
	sub_826432C0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82644648;
	sub_8264CF40(ctx, base);
loc_82644648:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82647fb8
	ctx.lr = 0x82644650;
	sub_82647FB8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x826445d4
	if (!ctx.cr0.eq) goto loc_826445D4;
	// lwz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826446b0
	if (ctx.cr6.eq) goto loc_826446B0;
	// addi r28,r31,408
	ctx.r28.s64 = ctx.r31.s64 + 408;
	// b 0x826446a0
	goto loc_826446A0;
loc_8264466C:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82644684;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264469C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x826446A0;
	sub_8264CF40(ctx, base);
loc_826446A0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82647fb8
	ctx.lr = 0x826446A8;
	sub_82647FB8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8264466c
	if (!ctx.cr0.eq) goto loc_8264466C;
loc_826446B0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826424b0
	ctx.lr = 0x826446B8;
	sub_826424B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82642428
	ctx.lr = 0x826446C0;
	sub_82642428(ctx, base);
loc_826446C0:
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826446D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,16040
	ctx.r3.s64 = ctx.r31.s64 + 16040;
	// bl 0x826441f8
	ctx.lr = 0x826446E0;
	sub_826441F8(ctx, base);
	// addi r3,r31,16032
	ctx.r3.s64 = ctx.r31.s64 + 16032;
	// bl 0x8264ced8
	ctx.lr = 0x826446E8;
	sub_8264CED8(ctx, base);
	// addi r3,r31,592
	ctx.r3.s64 = ctx.r31.s64 + 592;
	// bl 0x82643fc8
	ctx.lr = 0x826446F0;
	sub_82643FC8(ctx, base);
	// addi r3,r31,536
	ctx.r3.s64 = ctx.r31.s64 + 536;
	// bl 0x826432c0
	ctx.lr = 0x826446F8;
	sub_826432C0(ctx, base);
	// addi r3,r31,488
	ctx.r3.s64 = ctx.r31.s64 + 488;
	// bl 0x826432c0
	ctx.lr = 0x82644700;
	sub_826432C0(ctx, base);
	// addi r3,r31,448
	ctx.r3.s64 = ctx.r31.s64 + 448;
	// bl 0x826432c0
	ctx.lr = 0x82644708;
	sub_826432C0(ctx, base);
	// addi r3,r31,408
	ctx.r3.s64 = ctx.r31.s64 + 408;
	// bl 0x826432c0
	ctx.lr = 0x82644710;
	sub_826432C0(ctx, base);
	// addi r3,r31,188
	ctx.r3.s64 = ctx.r31.s64 + 188;
	// bl 0x82643458
	ctx.lr = 0x82644718;
	sub_82643458(ctx, base);
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// bl 0x826420b0
	ctx.lr = 0x82644720;
	sub_826420B0(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x826420b0
	ctx.lr = 0x82644728;
	sub_826420B0(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x826420b0
	ctx.lr = 0x82644730;
	sub_826420B0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r11,r11,5832
	ctx.r11.s64 = ctx.r11.s64 + 5832;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82653758) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82653760;
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
	ctx.lr = 0x82653788;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8265379c
	if (ctx.cr6.eq) goto loc_8265379C;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x826537a0
	goto loc_826537A0;
loc_8265379C:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
loc_826537A0:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x826537b8
	if (!ctx.cr6.eq) goto loc_826537B8;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x826537B8;
	sub_8273A030(ctx, base);
loc_826537B8:
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
	ctx.lr = 0x826537D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265CBD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addic r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// li r11,1
	ctx.r11.s64 = 1;
	// subfe r31,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r31.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r10,0
	ctx.r10.s64 = 0;
	// and r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// bge cr6,0x8265cc9c
	if (!ctx.cr6.lt) goto loc_8265CC9C;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x8265cc00
	if (ctx.cr6.eq) goto loc_8265CC00;
	// li r3,32
	ctx.r3.s64 = 32;
loc_8265CC00:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8265cc10
	if (ctx.cr6.eq) goto loc_8265CC10;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// ori r3,r11,2
	ctx.r3.u64 = ctx.r11.u64 | 2;
loc_8265CC10:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8265cd30
	if (ctx.cr6.eq) goto loc_8265CD30;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ori r10,r11,4
	ctx.r10.u64 = ctx.r11.u64 | 4;
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x8265cc64
	if (!ctx.cr6.eq) goto loc_8265CC64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// ble cr6,0x8265cc44
	if (!ctx.cr6.gt) goto loc_8265CC44;
loc_8265CC34:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8265cc34
	if (ctx.cr6.gt) goto loc_8265CC34;
loc_8265CC44:
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8265CC64:
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// ble cr6,0x8265cc7c
	if (!ctx.cr6.gt) goto loc_8265CC7C;
loc_8265CC6C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8265cc6c
	if (ctx.cr6.gt) goto loc_8265CC6C;
loc_8265CC7C:
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8265CC9C:
	// bne cr6,0x8265cd2c
	if (!ctx.cr6.eq) goto loc_8265CD2C;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8265ccc0
	if (ctx.cr6.eq) goto loc_8265CCC0;
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r9,100
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 100, ctx.xer);
	// bne cr6,0x8265ccc0
	if (!ctx.cr6.eq) goto loc_8265CCC0;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8265cce0
	goto loc_8265CCE0;
loc_8265CCC0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265cccc
	if (ctx.cr6.eq) goto loc_8265CCCC;
	// li r10,64
	ctx.r10.s64 = 64;
loc_8265CCCC:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265cce0
	if (ctx.cr6.eq) goto loc_8265CCE0;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
loc_8265CCE0:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// ble cr6,0x8265ccfc
	if (!ctx.cr6.gt) goto loc_8265CCFC;
loc_8265CCEC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bgt cr6,0x8265ccec
	if (ctx.cr6.gt) goto loc_8265CCEC;
loc_8265CCFC:
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// clrlwi r7,r3,31
	ctx.r7.u64 = ctx.r3.u32 & 0x1;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8265cd30
	if (ctx.cr6.eq) goto loc_8265CD30;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// ori r3,r11,256
	ctx.r3.u64 = ctx.r11.u64 | 256;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8265CD2C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8265CD30:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82664040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r6,8(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,32(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// bne cr6,0x82664130
	if (!ctx.cr6.eq) goto loc_82664130;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r9,r11,216
	ctx.r9.s64 = ctx.r11.s64 + 216;
	// li r8,48
	ctx.r8.s64 = 48;
loc_8266408C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// dcbt r10,r8
	// dcbt r0,r9
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x826640f0
	if (ctx.cr6.eq) goto loc_826640F0;
	// lfs f7,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f0,f13,f7
	ctx.f6.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f7.f64)));
	// stfs f6,0(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f5,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f5.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f4,f0,f12,f5
	ctx.f4.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f5.f64)));
	// stfs f4,0(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f3,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f3.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f2,f0,f11,f3
	ctx.f2.f64 = double(float(std::fma(ctx.f0.f64, ctx.f11.f64, ctx.f3.f64)));
	// stfs f2,0(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f7,f0,f10,f1
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f1.f64)));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f6,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f6.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f5,f0,f9,f6
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f6.f64)));
	// stfs f5,0(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f4,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f4.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f3,f0,f8,f4
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f4.f64)));
	// stfs f3,0(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82664120
	goto loc_82664120;
loc_826640F0:
	// fmuls f7,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f6,f0,f12
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfsu f6,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f5,f0,f11
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfsu f5,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f4,f0,f10
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// stfsu f4,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f3,f0,f9
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfsu f3,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f2,f0,f8
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// stfsu f2,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
loc_82664120:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r11,216
	ctx.r9.s64 = ctx.r11.s64 + 216;
	// bdnz 0x8266408c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266408C;
	// blr 
	return;
loc_82664130:
	// lfs f7,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lfs f6,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,20(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r9,r11,216
	ctx.r9.s64 = ctx.r11.s64 + 216;
	// li r8,48
	ctx.r8.s64 = 48;
loc_8266415C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// dcbt r10,r8
	// dcbt r0,r9
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x826641c0
	if (ctx.cr6.eq) goto loc_826641C0;
	// lfs f1,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f1,f0,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f1.f64)));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f1,f0,f12,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f1.f64)));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f1,f0,f11,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f11.f64, ctx.f1.f64)));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f1,f0,f10,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f1.f64)));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f1,f0,f9,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f1.f64)));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f0,f0,f8,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f1.f64)));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x826641f0
	goto loc_826641F0;
loc_826641C0:
	// fmuls f1,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f1,f0,f11
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f1,f0,f10
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// stfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f1,f0,f9
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfsu f1,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// fmuls f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// stfsu f0,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
loc_826641F0:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fadds f13,f7,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f13.f64));
	// fadds f12,f6,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// addi r9,r11,216
	ctx.r9.s64 = ctx.r11.s64 + 216;
	// fadds f11,f5,f11
	ctx.f11.f64 = double(float(ctx.f5.f64 + ctx.f11.f64));
	// fadds f10,f4,f10
	ctx.f10.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// fadds f9,f3,f9
	ctx.f9.f64 = double(float(ctx.f3.f64 + ctx.f9.f64));
	// fadds f8,f2,f8
	ctx.f8.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// bdnz 0x8266415c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266415C;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267E0F0) {
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
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267e1f8
	if (ctx.cr6.eq) goto loc_8267E1F8;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8267e1dc
	if (ctx.cr6.eq) goto loc_8267E1DC;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8267e178
	if (!ctx.cr6.eq) goto loc_8267E178;
	// lwz r11,208(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8267e144
	if (ctx.cr6.gt) goto loc_8267E144;
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E144:
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r9,204(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// subf r8,r11,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r11.u64;
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// mulld r5,r6,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * ctx.r7.u64);
	// sradi r4,r5,20
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0xFFFFF) != 0);
	ctx.r4.s64 = ctx.r5.s64 >> 20;
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E178:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267e020
	ctx.lr = 0x8267E184;
	sub_8267E020(ctx, base);
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8267e1a0
	if (ctx.cr6.gt) goto loc_8267E1A0;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E1A0:
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// subf r8,r11,r3
	ctx.r8.u64 = ctx.r3.u64 - ctx.r11.u64;
	// lwz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// mulld r5,r6,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * ctx.r7.u64);
	// sradi r4,r5,20
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0xFFFFF) != 0);
	ctx.r4.s64 = ctx.r5.s64 >> 20;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r3,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r3.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E1DC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267e1f8
	if (ctx.cr6.eq) goto loc_8267E1F8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267e020
	ctx.lr = 0x8267E1F0;
	sub_8267E020(ctx, base);
	// subf r11,r30,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r30.u64;
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E1F8:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8267e24c
	if (ctx.cr6.eq) goto loc_8267E24C;
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8267e218
	if (ctx.cr6.gt) goto loc_8267E218;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E218:
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// subf r8,r11,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r11.u64;
	// lwz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// mulld r5,r6,r7
	ctx.r5.s64 = static_cast<int64_t>(ctx.r6.u64 * ctx.r7.u64);
	// sradi r4,r5,20
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0xFFFFF) != 0);
	ctx.r4.s64 = ctx.r5.s64 >> 20;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8267e250
	goto loc_8267E250;
loc_8267E24C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8267E250:
	// lis r10,-1024
	ctx.r10.s64 = -67108864;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8267e268
	if (!ctx.cr6.lt) goto loc_8267E268;
	// lis r4,-1024
	ctx.r4.s64 = -67108864;
	// b 0x8267e27c
	goto loc_8267E27C;
loc_8267E268:
	// lis r10,1023
	ctx.r10.s64 = 67043328;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8267e27c
	if (!ctx.cr6.gt) goto loc_8267E27C;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
loc_8267E27C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,-28716
	ctx.r3.s64 = ctx.r11.s64 + -28716;
	// bl 0x8267db90
	ctx.lr = 0x8267E288;
	sub_8267DB90(ctx, base);
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

DEFINE_REX_FUNC(sub_82689478) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x82689480;
	__savegprlr_16(ctx, base);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x826896b0
	if (ctx.cr6.eq) goto loc_826896B0;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x826896b0
	if (ctx.cr6.eq) goto loc_826896B0;
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,14
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 14, ctx.xer);
	// blt cr6,0x826896a8
	if (ctx.cr6.lt) goto loc_826896A8;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// clrlwi r17,r7,16
	ctx.r17.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r18,r11,-4624
	ctx.r18.s64 = ctx.r11.s64 + -4624;
	// addi r20,r10,-4652
	ctx.r20.s64 = ctx.r10.s64 + -4652;
	// addi r19,r9,-4680
	ctx.r19.s64 = ctx.r9.s64 + -4680;
loc_826894B8:
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// blt cr6,0x826894c8
	if (ctx.cr6.lt) goto loc_826894C8;
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_826894C8:
	// lbz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addic. r7,r11,-14
	ctx.xer.ca = ctx.r11.u32 > 13;
	ctx.r7.s64 = ctx.r11.s64 + -14;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lbzu r10,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// subf r4,r11,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r11.u64;
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lbzu r29,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r29.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// lwzx r22,r8,r19
	ctx.r22.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r19.u32);
	// lwzx r21,r8,r20
	ctx.r21.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r20.u32);
	// lwzx r24,r6,r19
	ctx.r24.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r19.u32);
	// lwzx r23,r6,r20
	ctx.r23.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r20.u32);
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r30,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r30.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r6,r11,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// add r6,r6,r29
	ctx.r6.u64 = ctx.r6.u64 + ctx.r29.u64;
	// lbz r10,1(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r27,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r27.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r31,r10,8
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// add r31,r31,r30
	ctx.r31.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r9,1(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r25,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r25.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r26,r9,8
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r11,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// add r8,r8,r25
	ctx.r8.u64 = ctx.r8.u64 + ctx.r25.u64;
	// lbz r9,1(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbzu r10,2(r3)
	ea = 2 + ctx.r3.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r26,r27
	ctx.r9.u64 = ctx.r26.u64 + ctx.r27.u64;
	// lbz r30,1(r3)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// rotlwi r28,r30,8
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r30.u32, 8);
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// srawi r28,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r28.s64 = ctx.r11.s32 >> 8;
	// srawi r26,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r26.s64 = ctx.r10.s32 >> 8;
	// addi r30,r28,128
	ctx.r30.s64 = ctx.r28.s64 + 128;
	// addi r29,r26,128
	ctx.r29.s64 = ctx.r26.s64 + 128;
	// stb r30,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r30.u8);
	// srawi r27,r9,8
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFF) != 0);
	ctx.r27.s64 = ctx.r9.s32 >> 8;
	// stbu r29,1(r5)
	ea = 1 + ctx.r5.u32;
	REX_STORE_U8(ea, ctx.r29.u8);
	ctx.r5.u32 = ea;
	// srawi r28,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r28.s64 = ctx.r8.s32 >> 8;
	// addi r30,r27,128
	ctx.r30.s64 = ctx.r27.s64 + 128;
	// addi r28,r28,128
	ctx.r28.s64 = ctx.r28.s64 + 128;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stbu r30,1(r5)
	ea = 1 + ctx.r5.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r5.u32 = ea;
	// stbu r28,1(r5)
	ea = 1 + ctx.r5.u32;
	REX_STORE_U8(ea, ctx.r28.u8);
	ctx.r5.u32 = ea;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// beq 0x826896a0
	if (ctx.cr0.eq) goto loc_826896A0;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82689594:
	// lbz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// mullw r11,r29,r21
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r21.s32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// mullw r30,r9,r22
	ctx.r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r22.s32);
	// srawi r29,r7,4
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r7.s32 >> 4;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r29,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// srawi r30,r30,8
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 8;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// cmpwi cr6,r11,32767
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32767, ctx.xer);
	// ble cr6,0x826895d8
	if (!ctx.cr6.gt) goto loc_826895D8;
	// li r11,32767
	ctx.r11.s64 = 32767;
	// b 0x826895e4
	goto loc_826895E4;
loc_826895D8:
	// cmpwi cr6,r11,-32768
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -32768, ctx.xer);
	// bge cr6,0x826895e4
	if (!ctx.cr6.lt) goto loc_826895E4;
	// li r11,-32768
	ctx.r11.s64 = -32768;
loc_826895E4:
	// rlwinm r30,r29,2,26,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x3C;
	// lwzx r30,r30,r18
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r18.u32);
	// mullw r6,r30,r6
	ctx.r6.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r6.s32);
	// srawi r28,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r28.s64 = ctx.r6.s32 >> 8;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// bge cr6,0x82689600
	if (!ctx.cr6.lt) goto loc_82689600;
	// li r28,16
	ctx.r28.s64 = 16;
loc_82689600:
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// mullw r10,r10,r23
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r23.s32);
	// extsb r30,r6
	ctx.r30.s64 = ctx.r6.s8;
	// srawi r7,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 8;
	// mullw r6,r8,r24
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r24.s32);
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// addi r7,r7,128
	ctx.r7.s64 = ctx.r7.s64 + 128;
	// srawi r10,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 4;
	// srawi r9,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 8;
	// stb r7,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r7.u8);
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmpwi cr6,r7,32767
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 32767, ctx.xer);
	// ble cr6,0x8268965c
	if (!ctx.cr6.gt) goto loc_8268965C;
	// li r7,32767
	ctx.r7.s64 = 32767;
	// b 0x82689668
	goto loc_82689668;
loc_8268965C:
	// cmpwi cr6,r7,-32768
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -32768, ctx.xer);
	// bge cr6,0x82689668
	if (!ctx.cr6.lt) goto loc_82689668;
	// li r7,-32768
	ctx.r7.s64 = -32768;
loc_82689668:
	// rlwinm r11,r30,2,26,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x3C;
	// lwzx r10,r11,r18
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// mullw r11,r10,r31
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// srawi r31,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r31.s64 = ctx.r11.s32 >> 8;
	// cmpwi cr6,r31,16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16, ctx.xer);
	// bge cr6,0x82689684
	if (!ctx.cr6.lt) goto loc_82689684;
	// li r31,16
	ctx.r31.s64 = 16;
loc_82689684:
	// srawi r11,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 8;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// stb r11,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r11.u8);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// bdnz 0x82689594
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82689594;
loc_826896A0:
	// cmplwi cr6,r4,14
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 14, ctx.xer);
	// bge cr6,0x826894b8
	if (!ctx.cr6.lt) goto loc_826894B8;
loc_826896A8:
	// subf r3,r16,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r16.u64;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826896B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269BA30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8269BA38;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,44(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8269ba64
	if (!ctx.cr6.eq) goto loc_8269BA64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_8269BA64:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8269bb40
	if (ctx.cr6.eq) goto loc_8269BB40;
loc_8269BA78:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ld r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 8);
	// cmpld cr6,r10,r29
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r29.u64, ctx.xer);
	// blt cr6,0x8269bb40
	if (ctx.cr6.lt) goto loc_8269BB40;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r30,8(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8269bb30
	if (!ctx.cr6.eq) goto loc_8269BB30;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269BAAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269bb40
	if (ctx.cr6.lt) goto loc_8269BB40;
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r9,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r7,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8269baf4
	if (ctx.cr6.eq) goto loc_8269BAF4;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// b 0x8269bafc
	goto loc_8269BAFC;
loc_8269BAF4:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8269BAFC:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bne 0x8269bb18
	if (!ctx.cr0.eq) goto loc_8269BB18;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// stw r28,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
loc_8269BB18:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x8268f838
	ctx.lr = 0x8269BB28;
	sub_8268F838(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269bb40
	if (ctx.cr6.lt) goto loc_8269BB40;
loc_8269BB30:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8269ba78
	if (!ctx.cr6.eq) goto loc_8269BA78;
loc_8269BB40:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A2B50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x826A2B58;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r4,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r6.u32);
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// stw r5,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r5.u32);
	// mr r22,r27
	ctx.r22.u64 = ctx.r27.u64;
	// sth r27,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r27.u16);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x826a2bb4
	if (ctx.cr6.eq) goto loc_826A2BB4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x826a2ba0
	if (ctx.cr6.eq) goto loc_826A2BA0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x826a2bb4
	if (!ctx.cr6.eq) goto loc_826A2BB4;
loc_826A2BA0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e870
	ctx.lr = 0x826A2BA8;
	sub_8269E870(ctx, base);
	// li r3,11
	ctx.r3.s64 = 11;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A2BB4:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x826a2bec
	if (!ctx.cr6.eq) goto loc_826A2BEC;
loc_826A2BBC:
	// lwz r11,3692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3692);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a2bd4
	if (!ctx.cr6.eq) goto loc_826A2BD4;
loc_826A2BC8:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A2BD4:
	// li r24,1
	ctx.r24.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r24.u32);
	// stw r24,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A2BEC:
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x826a2c50
	if (!ctx.cr6.eq) goto loc_826A2C50;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x826a2c50
	if (!ctx.cr6.eq) goto loc_826A2C50;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x826a2bc8
	if (ctx.cr6.lt) goto loc_826A2BC8;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x826a2c50
	if (ctx.cr6.eq) goto loc_826A2C50;
	// lwz r11,3692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3692);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a2bc8
	if (ctx.cr6.eq) goto loc_826A2BC8;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a2c38
	if (ctx.cr6.eq) goto loc_826A2C38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7168
	ctx.lr = 0x826A2C30;
	sub_826A7168(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a39e8
	if (!ctx.cr6.eq) goto loc_826A39E8;
loc_826A2C38:
	// li r24,1
	ctx.r24.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r24.u32);
	// stw r24,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A2C50:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x826a2ca8
	if (!ctx.cr6.eq) goto loc_826A2CA8;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826a2ca8
	if (!ctx.cr6.eq) goto loc_826A2CA8;
	// addi r8,r1,236
	ctx.r8.s64 = ctx.r1.s64 + 236;
	// addi r7,r1,228
	ctx.r7.s64 = ctx.r1.s64 + 228;
	// addi r6,r1,220
	ctx.r6.s64 = ctx.r1.s64 + 220;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826b96b8
	ctx.lr = 0x826A2C78;
	sub_826B96B8(ctx, base);
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// bne cr6,0x826a2c88
	if (!ctx.cr6.eq) goto loc_826A2C88;
	// li r22,4
	ctx.r22.s64 = 4;
	// b 0x826a2c90
	goto loc_826A2C90;
loc_826A2C88:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a39e8
	if (!ctx.cr6.eq) goto loc_826A39E8;
loc_826A2C90:
	// lwz r11,3696(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3696);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3450
	if (ctx.cr6.eq) goto loc_826A3450;
	// lwz r6,236(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r5,228(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r4,220(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
loc_826A2CA8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x826a2cb8
	if (!ctx.cr6.eq) goto loc_826A2CB8;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x826a2bbc
	if (ctx.cr6.eq) goto loc_826A2BBC;
loc_826A2CB8:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,-7
	ctx.r11.s64 = ctx.r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x826c88a8
	ctx.lr = 0x826A2CD0;
	sub_826C88A8(ctx, base);
	// lwz r9,80(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r8,236(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// stw r8,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,3700(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3700);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x826a3450
	if (!ctx.cr6.eq) goto loc_826A3450;
	// ld r11,3600(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 3600);
	// ld r10,3608(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 3608);
	// lwz r9,3476(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3476);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r27,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r27.u32);
	// std r8,3600(r31)
	REX_STORE_U64(ctx.r31.u32 + 3600, ctx.r8.u64);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r7,3608(r31)
	REX_STORE_U64(ctx.r31.u32 + 3608, ctx.r7.u64);
	// stw r27,22200(r31)
	REX_STORE_U32(ctx.r31.u32 + 22200, ctx.r27.u32);
	// stw r27,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r27.u32);
	// stw r27,3432(r31)
	REX_STORE_U32(ctx.r31.u32 + 3432, ctx.r27.u32);
	// bne cr6,0x826a2d28
	if (!ctx.cr6.eq) goto loc_826A2D28;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// b 0x826a2d2c
	goto loc_826A2D2C;
loc_826A2D28:
	// stw r27,3476(r31)
	REX_STORE_U32(ctx.r31.u32 + 3476, ctx.r27.u32);
loc_826A2D2C:
	// lwz r10,15504(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// beq cr6,0x826a2d4c
	if (ctx.cr6.eq) goto loc_826A2D4C;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// bne cr6,0x826a2dd0
	if (!ctx.cr6.eq) goto loc_826A2DD0;
	// lwz r11,20904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a2dd0
	if (!ctx.cr6.eq) goto loc_826A2DD0;
loc_826A2D4C:
	// lwz r11,3396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a2dac
	if (ctx.cr6.eq) goto loc_826A2DAC;
	// lis r11,-32146
	ctx.r11.s64 = -2106720256;
	// lwz r9,3188(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3188);
	// addi r8,r11,-24312
	ctx.r8.s64 = ctx.r11.s64 + -24312;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x826a2dac
	if (ctx.cr6.eq) goto loc_826A2DAC;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x826a2dac
	if (ctx.cr6.eq) goto loc_826A2DAC;
	// lwz r11,3388(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3388);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x826a2dac
	if (ctx.cr6.gt) goto loc_826A2DAC;
	// lis r11,-32146
	ctx.r11.s64 = -2106720256;
	// lis r9,-32117
	ctx.r9.s64 = -2104819712;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// addi r7,r11,-29376
	ctx.r7.s64 = ctx.r11.s64 + -29376;
	// addi r6,r9,-16648
	ctx.r6.s64 = ctx.r9.s64 + -16648;
	// addi r5,r8,2760
	ctx.r5.s64 = ctx.r8.s64 + 2760;
	// stw r7,15808(r31)
	REX_STORE_U32(ctx.r31.u32 + 15808, ctx.r7.u32);
	// stw r6,3080(r31)
	REX_STORE_U32(ctx.r31.u32 + 3080, ctx.r6.u32);
	// stw r5,15804(r31)
	REX_STORE_U32(ctx.r31.u32 + 15804, ctx.r5.u32);
	// b 0x826a2dd0
	goto loc_826A2DD0;
loc_826A2DAC:
	// lis r11,-32150
	ctx.r11.s64 = -2106982400;
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32145
	ctx.r8.s64 = -2106654720;
	// addi r7,r11,29632
	ctx.r7.s64 = ctx.r11.s64 + 29632;
	// addi r6,r9,-31088
	ctx.r6.s64 = ctx.r9.s64 + -31088;
	// addi r5,r8,-21824
	ctx.r5.s64 = ctx.r8.s64 + -21824;
	// stw r7,15804(r31)
	REX_STORE_U32(ctx.r31.u32 + 15804, ctx.r7.u32);
	// stw r6,15808(r31)
	REX_STORE_U32(ctx.r31.u32 + 15808, ctx.r6.u32);
	// stw r5,3080(r31)
	REX_STORE_U32(ctx.r31.u32 + 3080, ctx.r5.u32);
loc_826A2DD0:
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// blt cr6,0x826a2e04
	if (ctx.cr6.lt) goto loc_826A2E04;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r27,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r27.u32);
	// addi r9,r31,2664
	ctx.r9.s64 = ctx.r31.s64 + 2664;
	// addi r8,r31,2704
	ctx.r8.s64 = ctx.r31.s64 + 2704;
	// stw r11,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// stw r9,2928(r31)
	REX_STORE_U32(ctx.r31.u32 + 2928, ctx.r9.u32);
	// stw r8,2940(r31)
	REX_STORE_U32(ctx.r31.u32 + 2940, ctx.r8.u32);
	// stw r11,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r11.u32);
	// stw r11,20932(r31)
	REX_STORE_U32(ctx.r31.u32 + 20932, ctx.r11.u32);
	// stw r11,14836(r31)
	REX_STORE_U32(ctx.r31.u32 + 14836, ctx.r11.u32);
	// stw r11,21868(r31)
	REX_STORE_U32(ctx.r31.u32 + 21868, ctx.r11.u32);
loc_826A2E04:
	// li r24,1
	ctx.r24.s64 = 1;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// beq cr6,0x826a2e38
	if (ctx.cr6.eq) goto loc_826A2E38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826b2ed8
	ctx.lr = 0x826A2E18;
	sub_826B2ED8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826a33fc
	if (ctx.cr6.eq) goto loc_826A33FC;
loc_826A2E24:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e870
	ctx.lr = 0x826A2E2C;
	sub_8269E870(ctx, base);
loc_826A2E2C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A2E38:
	// lwz r11,22088(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22088);
	// li r26,2
	ctx.r26.s64 = 2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a2fc8
	if (ctx.cr6.eq) goto loc_826A2FC8;
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a2ebc
	if (!ctx.cr6.lt) goto loc_826A2EBC;
loc_826A2E64:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a2ebc
	if (ctx.cr6.eq) goto loc_826A2EBC;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r29,r11,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r29.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// bge 0x826a2eac
	if (!ctx.cr0.lt) goto loc_826A2EAC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A2EAC;
	sub_826C8B78(ctx, base);
loc_826A2EAC:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a2e64
	if (ctx.cr6.gt) goto loc_826A2E64;
loc_826A2EBC:
	// subfic r11,r29,64
	ctx.xer.ca = ctx.r29.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r29.u64;
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrldi r8,r29,32
	ctx.r8.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r29,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r29,r11,r28
	ctx.r29.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r4.u64);
	// bge 0x826a2ef8
	if (!ctx.cr0.lt) goto loc_826A2EF8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A2EF8;
	sub_826C8B78(ctx, base);
loc_826A2EF8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x826a2fc8
	if (ctx.cr6.eq) goto loc_826A2FC8;
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826a2f74
	if (!ctx.cr6.lt) goto loc_826A2F74;
loc_826A2F1C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826a2f74
	if (ctx.cr6.eq) goto loc_826A2F74;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r29,r11,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r29.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// bge 0x826a2f64
	if (!ctx.cr0.lt) goto loc_826A2F64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A2F64;
	sub_826C8B78(ctx, base);
loc_826A2F64:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826a2f1c
	if (ctx.cr6.gt) goto loc_826A2F1C;
loc_826A2F74:
	// subfic r11,r29,64
	ctx.xer.ca = ctx.r29.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r29.u64;
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrldi r8,r29,32
	ctx.r8.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r29,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r29,r11,r28
	ctx.r29.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r4.u64);
	// bge 0x826a2fb0
	if (!ctx.cr0.lt) goto loc_826A2FB0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826A2FB0;
	sub_826C8B78(ctx, base);
loc_826A2FB0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x826a2fc0
	if (!ctx.cr6.eq) goto loc_826A2FC0;
	// stw r26,22364(r31)
	REX_STORE_U32(ctx.r31.u32 + 22364, ctx.r26.u32);
	// b 0x826a2fcc
	goto loc_826A2FCC;
loc_826A2FC0:
	// stw r24,22364(r31)
	REX_STORE_U32(ctx.r31.u32 + 22364, ctx.r24.u32);
	// b 0x826a2fcc
	goto loc_826A2FCC;
loc_826A2FC8:
	// stw r27,22364(r31)
	REX_STORE_U32(ctx.r31.u32 + 22364, ctx.r27.u32);
loc_826A2FCC:
	// lwz r11,22364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22364);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// stw r27,20908(r31)
	REX_STORE_U32(ctx.r31.u32 + 20908, ctx.r27.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r27,20904(r31)
	REX_STORE_U32(ctx.r31.u32 + 20904, ctx.r27.u32);
	// bne cr6,0x826a3208
	if (!ctx.cr6.eq) goto loc_826A3208;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r11,10288
	ctx.r3.s64 = ctx.r11.s64 + 10288;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r11,r10,10216
	ctx.r11.s64 = ctx.r10.s64 + 10216;
	// stw r3,1824(r31)
	REX_STORE_U32(ctx.r31.u32 + 1824, ctx.r3.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r10,r9,9644
	ctx.r10.s64 = ctx.r9.s64 + 9644;
	// stw r11,1828(r31)
	REX_STORE_U32(ctx.r31.u32 + 1828, ctx.r11.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r9,r8,10388
	ctx.r9.s64 = ctx.r8.s64 + 10388;
	// stw r10,1836(r31)
	REX_STORE_U32(ctx.r31.u32 + 1836, ctx.r10.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r8,r7,10352
	ctx.r8.s64 = ctx.r7.s64 + 10352;
	// stw r9,1840(r31)
	REX_STORE_U32(ctx.r31.u32 + 1840, ctx.r9.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r7,r6,10424
	ctx.r7.s64 = ctx.r6.s64 + 10424;
	// stw r8,1844(r31)
	REX_STORE_U32(ctx.r31.u32 + 1844, ctx.r8.u32);
	// addi r6,r5,10460
	ctx.r6.s64 = ctx.r5.s64 + 10460;
	// addi r5,r4,10480
	ctx.r5.s64 = ctx.r4.s64 + 10480;
	// stw r7,1848(r31)
	REX_STORE_U32(ctx.r31.u32 + 1848, ctx.r7.u32);
	// stw r6,1864(r31)
	REX_STORE_U32(ctx.r31.u32 + 1864, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,1868(r31)
	REX_STORE_U32(ctx.r31.u32 + 1868, ctx.r5.u32);
	// bl 0x826a6fd8
	ctx.lr = 0x826A304C;
	sub_826A6FD8(ctx, base);
	// stw r27,20904(r31)
	REX_STORE_U32(ctx.r31.u32 + 20904, ctx.r27.u32);
	// stw r27,20908(r31)
	REX_STORE_U32(ctx.r31.u32 + 20908, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,20912(r31)
	REX_STORE_U32(ctx.r31.u32 + 20912, ctx.r27.u32);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// bl 0x826be418
	ctx.lr = 0x826A3064;
	sub_826BE418(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826b14a0
	ctx.lr = 0x826A306C;
	sub_826B14A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a2e24
	if (!ctx.cr6.eq) goto loc_826A2E24;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a3098
	if (ctx.cr6.eq) goto loc_826A3098;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3098
	if (ctx.cr6.eq) goto loc_826A3098;
	// lwz r10,22444(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22444);
	// stw r27,22444(r31)
	REX_STORE_U32(ctx.r31.u32 + 22444, ctx.r27.u32);
	// stw r10,22448(r31)
	REX_STORE_U32(ctx.r31.u32 + 22448, ctx.r10.u32);
loc_826A3098:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x826a33fc
	if (!ctx.cr6.eq) goto loc_826A33FC;
	// lwz r11,22408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a31e4
	if (ctx.cr6.eq) goto loc_826A31E4;
	// lwz r11,14820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14820);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a31e4
	if (ctx.cr6.eq) goto loc_826A31E4;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a31e4
	if (!ctx.cr6.gt) goto loc_826A31E4;
	// lwz r11,3400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3400);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a30d4
	if (!ctx.cr6.eq) goto loc_826A30D4;
	// stw r27,3400(r31)
	REX_STORE_U32(ctx.r31.u32 + 3400, ctx.r27.u32);
loc_826A30D4:
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a30ec
	if (ctx.cr6.eq) goto loc_826A30EC;
	// bl 0x826e8fd0
	ctx.lr = 0x826A30E8;
	sub_826E8FD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_826A30EC:
	// bl 0x826e9070
	ctx.lr = 0x826A30F0;
	sub_826E9070(ctx, base);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r4,3756(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r3,3744(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// bl 0x8273a030
	ctx.lr = 0x826A3108;
	sub_8273A030(ctx, base);
	// lwz r8,216(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r4,3760(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// lwz r3,3748(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mullw r5,r9,r8
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// bl 0x8273a030
	ctx.lr = 0x826A3120;
	sub_8273A030(ctx, base);
	// lwz r6,216(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r7,208(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r4,3764(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// lwz r3,3752(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// bl 0x8273a030
	ctx.lr = 0x826A3138;
	sub_8273A030(ctx, base);
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r3,1772(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1772);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x8273a590
	ctx.lr = 0x826A314C;
	sub_8273A590(ctx, base);
	// lwz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1780(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1780);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a590
	ctx.lr = 0x826A3160;
	sub_8273A590(ctx, base);
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826a31e4
	if (!ctx.cr6.gt) goto loc_826A31E4;
	// addi r8,r11,-24
	ctx.r8.s64 = ctx.r11.s64 + -24;
loc_826A3178:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826a31d4
	if (!ctx.cr6.gt) goto loc_826A31D4;
loc_826A3188:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r6,3072(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3072);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// sthx r27,r9,r6
	REX_STORE_U16(ctx.r9.u32 + ctx.r6.u32, ctx.r27.u16);
	// lwz r10,3072(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3072);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r27,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r27.u16);
	// lwz r3,3076(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3076);
	// stwx r27,r5,r3
	REX_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r27.u32);
	// lwz r10,24(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 24);
	// oris r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 131072;
	// stwu r9,24(r8)
	ea = 24 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// lwz r6,136(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x826a3188
	if (ctx.cr6.lt) goto loc_826A3188;
loc_826A31D4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826a3178
	if (ctx.cr6.lt) goto loc_826A3178;
loc_826A31E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,20912(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20912);
	// bl 0x826f0040
	ctx.lr = 0x826A31F0;
	sub_826F0040(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e7b8
	ctx.lr = 0x826A31F8;
	sub_8269E7B8(ctx, base);
	// stw r24,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r24.u32);
	// stw r24,22316(r31)
	REX_STORE_U32(ctx.r31.u32 + 22316, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A3208:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r11,10576
	ctx.r3.s64 = ctx.r11.s64 + 10576;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stw r3,1824(r31)
	REX_STORE_U32(ctx.r31.u32 + 1824, ctx.r3.u32);
	// addi r11,r10,10504
	ctx.r11.s64 = ctx.r10.s64 + 10504;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r10,r9,10640
	ctx.r10.s64 = ctx.r9.s64 + 10640;
	// stw r11,1828(r31)
	REX_STORE_U32(ctx.r31.u32 + 1828, ctx.r11.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r9,r8,10712
	ctx.r9.s64 = ctx.r8.s64 + 10712;
	// stw r10,1836(r31)
	REX_STORE_U32(ctx.r31.u32 + 1836, ctx.r10.u32);
	// addi r8,r7,10676
	ctx.r8.s64 = ctx.r7.s64 + 10676;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stw r9,1840(r31)
	REX_STORE_U32(ctx.r31.u32 + 1840, ctx.r9.u32);
	// addi r7,r6,10748
	ctx.r7.s64 = ctx.r6.s64 + 10748;
	// stw r8,1844(r31)
	REX_STORE_U32(ctx.r31.u32 + 1844, ctx.r8.u32);
	// addi r6,r5,10784
	ctx.r6.s64 = ctx.r5.s64 + 10784;
	// addi r5,r4,10804
	ctx.r5.s64 = ctx.r4.s64 + 10804;
	// stw r7,1848(r31)
	REX_STORE_U32(ctx.r31.u32 + 1848, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r6,1864(r31)
	REX_STORE_U32(ctx.r31.u32 + 1864, ctx.r6.u32);
	// stw r5,1868(r31)
	REX_STORE_U32(ctx.r31.u32 + 1868, ctx.r5.u32);
	// bne cr6,0x826a3c1c
	if (!ctx.cr6.eq) goto loc_826A3C1C;
	// bl 0x826a6fd8
	ctx.lr = 0x826A3278;
	sub_826A6FD8(ctx, base);
	// stw r24,20904(r31)
	REX_STORE_U32(ctx.r31.u32 + 20904, ctx.r24.u32);
	// stw r27,20912(r31)
	REX_STORE_U32(ctx.r31.u32 + 20912, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// bl 0x826be418
	ctx.lr = 0x826A328C;
	sub_826BE418(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826dd690
	ctx.lr = 0x826A3294;
	sub_826DD690(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a2e24
	if (!ctx.cr6.eq) goto loc_826A2E24;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a32c0
	if (ctx.cr6.eq) goto loc_826A32C0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a32c0
	if (ctx.cr6.eq) goto loc_826A32C0;
	// lwz r10,22444(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22444);
	// stw r26,22444(r31)
	REX_STORE_U32(ctx.r31.u32 + 22444, ctx.r26.u32);
	// stw r10,22448(r31)
	REX_STORE_U32(ctx.r31.u32 + 22448, ctx.r10.u32);
loc_826A32C0:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x826a33fc
	if (!ctx.cr6.eq) goto loc_826A33FC;
	// lwz r11,22408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3360
	if (ctx.cr6.eq) goto loc_826A3360;
	// lwz r11,14820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14820);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3360
	if (ctx.cr6.eq) goto loc_826A3360;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a3360
	if (!ctx.cr6.gt) goto loc_826A3360;
	// lwz r11,3400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3400);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a32fc
	if (!ctx.cr6.eq) goto loc_826A32FC;
	// stw r27,3400(r31)
	REX_STORE_U32(ctx.r31.u32 + 3400, ctx.r27.u32);
loc_826A32FC:
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3314
	if (ctx.cr6.eq) goto loc_826A3314;
	// bl 0x826e8fd0
	ctx.lr = 0x826A3310;
	sub_826E8FD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_826A3314:
	// bl 0x826e9070
	ctx.lr = 0x826A3318;
	sub_826E9070(ctx, base);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r4,3756(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r3,3744(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// bl 0x8273a030
	ctx.lr = 0x826A3330;
	sub_8273A030(ctx, base);
	// lwz r8,216(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r4,3760(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// lwz r3,3748(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mullw r5,r9,r8
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// bl 0x8273a030
	ctx.lr = 0x826A3348;
	sub_8273A030(ctx, base);
	// lwz r6,216(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r7,208(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r4,3764(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// lwz r3,3752(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// bl 0x8273a030
	ctx.lr = 0x826A3360;
	sub_8273A030(ctx, base);
loc_826A3360:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x826a33b4
	if (!ctx.cr6.gt) goto loc_826A33B4;
	// addi r10,r11,-24
	ctx.r10.s64 = ctx.r11.s64 + -24;
loc_826A3378:
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// ble cr6,0x826a33a4
	if (!ctx.cr6.gt) goto loc_826A33A4;
loc_826A3388:
	// lwz r8,24(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// oris r7,r8,2
	ctx.r7.u64 = ctx.r8.u64 | 131072;
	// stwu r7,24(r10)
	ea = 24 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r10.u32 = ea;
	// lwz r6,136(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x826a3388
	if (ctx.cr6.lt) goto loc_826A3388;
loc_826A33A4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826a3378
	if (ctx.cr6.lt) goto loc_826A3378;
loc_826A33B4:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r3,3076(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3076);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a590
	ctx.lr = 0x826A33D8;
	sub_8273A590(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,20912(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20912);
	// bl 0x826f0040
	ctx.lr = 0x826A33E4;
	sub_826F0040(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e7b8
	ctx.lr = 0x826A33EC;
	sub_8269E7B8(ctx, base);
	// stw r24,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r24.u32);
	// stw r24,22316(r31)
	REX_STORE_U32(ctx.r31.u32 + 22316, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A33FC:
	// lwz r11,22512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22512);
	// stw r24,1968(r31)
	REX_STORE_U32(ctx.r31.u32 + 1968, ctx.r24.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r27,20988(r31)
	REX_STORE_U32(ctx.r31.u32 + 20988, ctx.r27.u32);
	// beq cr6,0x826a3420
	if (ctx.cr6.eq) goto loc_826A3420;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ba728
	ctx.lr = 0x826A3418;
	sub_826BA728(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a39e8
	if (!ctx.cr6.eq) goto loc_826A39E8;
loc_826A3420:
	// lwz r10,284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826a345c
	if (ctx.cr6.eq) goto loc_826A345C;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x826a345c
	if (ctx.cr6.eq) goto loc_826A345C;
	// lwz r11,3692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3692);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a3558
	if (!ctx.cr6.eq) goto loc_826A3558;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e7b8
	ctx.lr = 0x826A3448;
	sub_8269E7B8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a39e8
	if (!ctx.cr6.eq) goto loc_826A39E8;
loc_826A3450:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A345C:
	// lwz r11,14820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14820);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3558
	if (ctx.cr6.eq) goto loc_826A3558;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a3548
	if (!ctx.cr6.gt) goto loc_826A3548;
	// lwz r11,3400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3400);
	// cmpwi cr6,r11,-3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -3, ctx.xer);
	// bne cr6,0x826a34b8
	if (!ctx.cr6.eq) goto loc_826A34B8;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x826a2bc8
	if (ctx.cr6.eq) goto loc_826A2BC8;
	// lwz r11,22296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22296);
	// lwz r10,3420(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r8,3400(r31)
	REX_STORE_U32(ctx.r31.u32 + 3400, ctx.r8.u32);
	// beq cr6,0x826a34ac
	if (ctx.cr6.eq) goto loc_826A34AC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A34AC;
	sub_826E8FD0(ctx, base);
loc_826A34AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e9070
	ctx.lr = 0x826A34B4;
	sub_826E9070(ctx, base);
	// b 0x826a3558
	goto loc_826A3558;
loc_826A34B8:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x826a34fc
	if (ctx.cr6.eq) goto loc_826A34FC;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x826a34fc
	if (ctx.cr6.eq) goto loc_826A34FC;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a34d8
	if (!ctx.cr6.eq) goto loc_826A34D8;
	// stw r27,3400(r31)
	REX_STORE_U32(ctx.r31.u32 + 3400, ctx.r27.u32);
	// b 0x826a34e4
	goto loc_826A34E4;
loc_826A34D8:
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a34ec
	if (ctx.cr6.eq) goto loc_826A34EC;
loc_826A34E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A34EC;
	sub_826E8FD0(ctx, base);
loc_826A34EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e9070
	ctx.lr = 0x826A34F4;
	sub_826E9070(ctx, base);
	// stw r27,3408(r31)
	REX_STORE_U32(ctx.r31.u32 + 3408, ctx.r27.u32);
	// b 0x826a3558
	goto loc_826A3558;
loc_826A34FC:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a3530
	if (!ctx.cr6.eq) goto loc_826A3530;
	// lwz r11,22296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22296);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a3530
	if (!ctx.cr6.eq) goto loc_826A3530;
	// stw r24,3432(r31)
	REX_STORE_U32(ctx.r31.u32 + 3432, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r24,3708(r31)
	REX_STORE_U16(ctx.r31.u32 + 3708, ctx.r24.u16);
	// bl 0x8269e7b8
	ctx.lr = 0x826A3520;
	sub_8269E7B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A3530:
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3558
	if (ctx.cr6.eq) goto loc_826A3558;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A3544;
	sub_826E8FD0(ctx, base);
	// b 0x826a3558
	goto loc_826A3558;
loc_826A3548:
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x826ab010
	ctx.lr = 0x826A3558;
	sub_826AB010(ctx, base);
loc_826A3558:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// stw r11,-13568(r10)
	REX_STORE_U32(ctx.r10.u32 + -13568, ctx.r11.u32);
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a39f0
	if (ctx.cr6.eq) goto loc_826A39F0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a39f0
	if (ctx.cr6.eq) goto loc_826A39F0;
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,-13572(r10)
	REX_STORE_U32(ctx.r10.u32 + -13572, ctx.r27.u32);
	// bl 0x826a6c98
	ctx.lr = 0x826A358C;
	sub_826A6C98(ctx, base);
	// lwz r9,14820(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 14820);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826a3750
	if (ctx.cr6.eq) goto loc_826A3750;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826a3750
	if (ctx.cr6.eq) goto loc_826A3750;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x826a3910
	if (!ctx.cr6.eq) goto loc_826A3910;
	// lwz r11,3400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3400);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a35e0
	if (!ctx.cr6.eq) goto loc_826A35E0;
	// lwz r11,22296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22296);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a35e0
	if (!ctx.cr6.eq) goto loc_826A35E0;
	// stw r24,3432(r31)
	REX_STORE_U32(ctx.r31.u32 + 3432, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r24,3708(r31)
	REX_STORE_U16(ctx.r31.u32 + 3708, ctx.r24.u16);
	// bl 0x8269e7b8
	ctx.lr = 0x826A35D4;
	sub_8269E7B8(ctx, base);
	// stw r24,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r24.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A35E0:
	// lwz r11,3408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3408);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3660
	if (ctx.cr6.eq) goto loc_826A3660;
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// stw r27,3408(r31)
	REX_STORE_U32(ctx.r31.u32 + 3408, ctx.r27.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3604
	if (ctx.cr6.eq) goto loc_826A3604;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A3604;
	sub_826E8FD0(ctx, base);
loc_826A3604:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e9070
	ctx.lr = 0x826A360C;
	sub_826E9070(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r4,3756(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r3,3744(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// bl 0x8273a030
	ctx.lr = 0x826A3624;
	sub_8273A030(ctx, base);
	// lwz r9,212(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r8,204(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r4,3760(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// lwz r3,3748(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mullw r7,r9,r8
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// srawi r5,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 2;
	// bl 0x8273a030
	ctx.lr = 0x826A3640;
	sub_8273A030(ctx, base);
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r6,212(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r4,3764(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// mullw r11,r6,r5
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lwz r3,3752(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// srawi r5,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 2;
	// bl 0x8273a030
	ctx.lr = 0x826A365C;
	sub_8273A030(ctx, base);
	// stw r24,3420(r31)
	REX_STORE_U32(ctx.r31.u32 + 3420, ctx.r24.u32);
loc_826A3660:
	// rlwinm r11,r25,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 16) & 0xFFFF0000;
	// srawi r11,r11,28
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 28;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x826a371c
	if (ctx.cr6.eq) goto loc_826A371C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a371c
	if (ctx.cr6.eq) goto loc_826A371C;
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a368c
	if (ctx.cr6.eq) goto loc_826A368C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A368C;
	sub_826E8FD0(ctx, base);
loc_826A368C:
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a36d0
	if (!ctx.cr6.eq) goto loc_826A36D0;
	// lwz r11,20904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a36d0
	if (!ctx.cr6.eq) goto loc_826A36D0;
	// lwz r11,3080(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3080);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826A36B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// stw r24,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r24.u32);
	// stw r24,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r24.u32);
	// b 0x826a3910
	goto loc_826A3910;
loc_826A36D0:
	// lwz r11,20904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3700
	if (ctx.cr6.eq) goto loc_826A3700;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82893850
	ctx.lr = 0x826A36E4;
	sub_82893850(ctx, base);
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// stw r24,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r24.u32);
	// stw r24,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r24.u32);
	// b 0x826a3910
	goto loc_826A3910;
loc_826A3700:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// li r30,6
	ctx.r30.s64 = 6;
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// stw r24,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r24.u32);
	// stw r24,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r24.u32);
	// b 0x826a3910
	goto loc_826A3910;
loc_826A371C:
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3738
	if (ctx.cr6.eq) goto loc_826A3738;
	// stw r24,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r24.u32);
	// li r30,6
	ctx.r30.s64 = 6;
	// stw r24,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r24.u32);
	// b 0x826a3910
	goto loc_826A3910;
loc_826A3738:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fa8
	ctx.lr = 0x826A3740;
	sub_826E8FA8(ctx, base);
	// stw r24,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r24.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r24,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r24.u32);
	// b 0x826a3910
	goto loc_826A3910;
loc_826A3750:
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a3818
	if (!ctx.cr6.eq) goto loc_826A3818;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ab010
	ctx.lr = 0x826A3768;
	sub_826AB010(ctx, base);
	// lwz r11,14852(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3784
	if (ctx.cr6.eq) goto loc_826A3784;
	// lwz r11,14856(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// lwz r10,14860(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x826a3848
	if (!ctx.cr6.eq) goto loc_826A3848;
loc_826A3784:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x826a3848
	if (!ctx.cr6.lt) goto loc_826A3848;
	// lwz r11,20624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20624);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3848
	if (ctx.cr6.eq) goto loc_826A3848;
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r30,15888(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 15888);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,184(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r9,164(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lwz r6,220(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r5,172(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r3,3756(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// stw r24,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r24.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x826A37D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,168(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r7,224(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r6,176(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// lwz r4,3764(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// lwz r3,3760(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// stw r24,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// lwz r30,196(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lwz r26,15884(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 15884);
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
	// bctrl 
	ctx.lr = 0x826A3814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x826a3848
	goto loc_826A3848;
loc_826A3818:
	// lwz r11,3400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3400);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a382c
	if (!ctx.cr6.eq) goto loc_826A382C;
	// stw r27,3400(r31)
	REX_STORE_U32(ctx.r31.u32 + 3400, ctx.r27.u32);
	// b 0x826a3838
	goto loc_826A3838;
loc_826A382C:
	// lwz r11,3420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3840
	if (ctx.cr6.eq) goto loc_826A3840;
loc_826A3838:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fd0
	ctx.lr = 0x826A3840;
	sub_826E8FD0(ctx, base);
loc_826A3840:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e9070
	ctx.lr = 0x826A3848;
	sub_826E9070(ctx, base);
loc_826A3848:
	// stw r27,3408(r31)
	REX_STORE_U32(ctx.r31.u32 + 3408, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ba818
	ctx.lr = 0x826A3854;
	sub_826BA818(ctx, base);
	// lwz r11,15932(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3864
	if (ctx.cr6.eq) goto loc_826A3864;
	// stw r27,15940(r31)
	REX_STORE_U32(ctx.r31.u32 + 15940, ctx.r27.u32);
loc_826A3864:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x826a38d4
	if (ctx.cr6.lt) goto loc_826A38D4;
	// lwz r11,14852(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3884
	if (ctx.cr6.eq) goto loc_826A3884;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826b02f0
	ctx.lr = 0x826A3884;
	sub_826B02F0(ctx, base);
loc_826A3884:
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3898
	if (ctx.cr6.eq) goto loc_826A3898;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7198
	ctx.lr = 0x826A3898;
	sub_826A7198(ctx, base);
loc_826A3898:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e69b0
	ctx.lr = 0x826A38A0;
	sub_826E69B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e5230
	ctx.lr = 0x826A38A8;
	sub_826E5230(ctx, base);
	// lwz r11,20904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a38c0
	if (ctx.cr6.eq) goto loc_826A38C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828936e0
	ctx.lr = 0x826A38BC;
	sub_828936E0(ctx, base);
	// b 0x826a38e4
	goto loc_826A38E4;
loc_826A38C0:
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a38d4
	if (ctx.cr6.eq) goto loc_826A38D4;
	// li r30,6
	ctx.r30.s64 = 6;
	// b 0x826a38e8
	goto loc_826A38E8;
loc_826A38D4:
	// lwz r11,15808(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15808);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826A38E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826A38E4:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_826A38E8:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// bne cr6,0x826a3908
	if (!ctx.cr6.eq) goto loc_826A3908;
	// li r22,4
	ctx.r22.s64 = 4;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// b 0x826a3910
	goto loc_826A3910;
loc_826A3908:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826a2e24
	if (!ctx.cr6.eq) goto loc_826A2E24;
loc_826A3910:
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a3920
	if (!ctx.cr6.eq) goto loc_826A3920;
	// stw r27,3404(r31)
	REX_STORE_U32(ctx.r31.u32 + 3404, ctx.r27.u32);
loc_826A3920:
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x826a3cb8
	if (!ctx.cr6.eq) goto loc_826A3CB8;
loc_826A3928:
	// li r22,4
	ctx.r22.s64 = 4;
loc_826A392C:
	// sth r24,3708(r31)
	REX_STORE_U16(ctx.r31.u32 + 3708, ctx.r24.u16);
	// sth r24,0(r23)
	REX_STORE_U16(ctx.r23.u32 + 0, ctx.r24.u16);
	// lwz r11,3476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3476);
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r10,20904(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// rlwinm r11,r9,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r8,r11,3
	ctx.r8.s64 = ctx.r11.s64 + 3;
	// stw r8,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r8.u32);
	// bne cr6,0x826a39d0
	if (!ctx.cr6.eq) goto loc_826A39D0;
	// lwz r9,20908(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20908);
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x826a39d0
	if (!ctx.cr6.eq) goto loc_826A39D0;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826a3978
	if (ctx.cr6.eq) goto loc_826A3978;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a3994
	if (!ctx.cr6.eq) goto loc_826A3994;
loc_826A3978:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826a3988
	if (ctx.cr6.eq) goto loc_826A3988;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826a3994
	if (!ctx.cr6.eq) goto loc_826A3994;
loc_826A3988:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,20912(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20912);
	// bl 0x826f0040
	ctx.lr = 0x826A3994;
	sub_826F0040(ctx, base);
loc_826A3994:
	// lwz r11,22364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22364);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a39d0
	if (!ctx.cr6.eq) goto loc_826A39D0;
	// lwz r11,22000(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22000);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a39d0
	if (!ctx.cr6.eq) goto loc_826A39D0;
	// lwz r11,22004(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22004);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a39d0
	if (!ctx.cr6.eq) goto loc_826A39D0;
	// lwz r11,22360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a39d0
	if (ctx.cr6.eq) goto loc_826A39D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269ea10
	ctx.lr = 0x826A39CC;
	sub_8269EA10(ctx, base);
	// stw r24,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r24.u32);
loc_826A39D0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e7b8
	ctx.lr = 0x826A39D8;
	sub_8269E7B8(ctx, base);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x826a39e4
	if (!ctx.cr6.eq) goto loc_826A39E4;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_826A39E4:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_826A39E8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826A39F0:
	// lwz r10,15932(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15932);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826a3a08
	if (ctx.cr6.eq) goto loc_826A3A08;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3a08
	if (ctx.cr6.eq) goto loc_826A3A08;
	// stw r27,15940(r31)
	REX_STORE_U32(ctx.r31.u32 + 15940, ctx.r27.u32);
loc_826A3A08:
	// lwz r11,14852(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3a1c
	if (ctx.cr6.eq) goto loc_826A3A1C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826b02f0
	ctx.lr = 0x826A3A1C;
	sub_826B02F0(ctx, base);
loc_826A3A1C:
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// stw r24,-13572(r10)
	REX_STORE_U32(ctx.r10.u32 + -13572, ctx.r24.u32);
	// lwz r9,20904(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20904);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826a3a40
	if (ctx.cr6.eq) goto loc_826A3A40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828935c0
	ctx.lr = 0x826A3A3C;
	sub_828935C0(ctx, base);
	// b 0x826a3a7c
	goto loc_826A3A7C;
loc_826A3A40:
	// lwz r11,3972(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3972);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3a58
	if (ctx.cr6.eq) goto loc_826A3A58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e2ab8
	ctx.lr = 0x826A3A54;
	sub_826E2AB8(ctx, base);
	// b 0x826a3a7c
	goto loc_826A3A7C;
loc_826A3A58:
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3a6c
	if (ctx.cr6.eq) goto loc_826A3A6C;
	// li r30,6
	ctx.r30.s64 = 6;
	// b 0x826a3a80
	goto loc_826A3A80;
loc_826A3A6C:
	// lwz r11,15804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15804);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826A3A7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826A3A7C:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_826A3A80:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// bne cr6,0x826a3aa0
	if (!ctx.cr6.eq) goto loc_826A3AA0;
	// li r22,4
	ctx.r22.s64 = 4;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// b 0x826a3aa8
	goto loc_826A3AA8;
loc_826A3AA0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826a2e24
	if (!ctx.cr6.eq) goto loc_826A2E24;
loc_826A3AA8:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a3c14
	if (ctx.cr6.eq) goto loc_826A3C14;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a3ac4
	if (ctx.cr6.eq) goto loc_826A3AC4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x826a3ad0
	if (!ctx.cr6.eq) goto loc_826A3AD0;
loc_826A3AC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a8718
	ctx.lr = 0x826A3ACC;
	sub_826A8718(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_826A3AD0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826a2e2c
	if (!ctx.cr6.eq) goto loc_826A2E2C;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x826a3b94
	if (ctx.cr6.lt) goto loc_826A3B94;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3b94
	if (ctx.cr6.eq) goto loc_826A3B94;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a3b94
	if (!ctx.cr6.gt) goto loc_826A3B94;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826a3b70
	if (!ctx.cr6.gt) goto loc_826A3B70;
loc_826A3B0C:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// ble cr6,0x826a3b60
	if (!ctx.cr6.gt) goto loc_826A3B60;
loc_826A3B1C:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r8,3072(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3072);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// sthx r27,r6,r8
	REX_STORE_U16(ctx.r6.u32 + ctx.r8.u32, ctx.r27.u16);
	// lwz r8,3072(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3072);
	// lwz r5,136(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mullw r9,r5,r10
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r27,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r27.u16);
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x826a3b1c
	if (ctx.cr6.lt) goto loc_826A3B1C;
loc_826A3B60:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826a3b0c
	if (ctx.cr6.lt) goto loc_826A3B0C;
loc_826A3B70:
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r3,3076(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3076);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8273a590
	ctx.lr = 0x826A3B94;
	sub_8273A590(ctx, base);
loc_826A3B94:
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a3c14
	if (!ctx.cr6.gt) goto loc_826A3C14;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3c14
	if (ctx.cr6.eq) goto loc_826A3C14;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826a3c14
	if (!ctx.cr6.gt) goto loc_826A3C14;
loc_826A3BBC:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x826a3c04
	if (!ctx.cr6.gt) goto loc_826A3C04;
loc_826A3BCC:
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r9,276(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r10,r9
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r5,r6,0,15,13
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFDFFFF;
	// stwx r5,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r4,136(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x826a3bcc
	if (ctx.cr6.lt) goto loc_826A3BCC;
loc_826A3C04:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826a3bbc
	if (ctx.cr6.lt) goto loc_826A3BBC;
loc_826A3C14:
	// stw r24,3692(r31)
	REX_STORE_U32(ctx.r31.u32 + 3692, ctx.r24.u32);
	// b 0x826a392c
	goto loc_826A392C;
loc_826A3C1C:
	// bl 0x826a6fd8
	ctx.lr = 0x826A3C20;
	sub_826A6FD8(ctx, base);
	// stw r24,20904(r31)
	REX_STORE_U32(ctx.r31.u32 + 20904, ctx.r24.u32);
	// stw r24,20908(r31)
	REX_STORE_U32(ctx.r31.u32 + 20908, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// bl 0x826be418
	ctx.lr = 0x826A3C38;
	sub_826BE418(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826dfc48
	ctx.lr = 0x826A3C40;
	sub_826DFC48(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a2e24
	if (!ctx.cr6.eq) goto loc_826A2E24;
	// lwz r11,22000(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22000);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a3c70
	if (ctx.cr6.eq) goto loc_826A3C70;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3c70
	if (ctx.cr6.eq) goto loc_826A3C70;
	// lwz r11,22444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22444);
	// stw r24,22444(r31)
	REX_STORE_U32(ctx.r31.u32 + 22444, ctx.r24.u32);
	// stw r11,22448(r31)
	REX_STORE_U32(ctx.r31.u32 + 22448, ctx.r11.u32);
	// b 0x826a3c74
	goto loc_826A3C74;
loc_826A3C70:
	// stw r26,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r26.u32);
loc_826A3C74:
	// rlwinm r11,r25,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 16) & 0xFFFF0000;
	// srawi r11,r11,28
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 28;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x826a3c98
	if (ctx.cr6.eq) goto loc_826A3C98;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a3c98
	if (ctx.cr6.eq) goto loc_826A3C98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826dc780
	ctx.lr = 0x826A3C94;
	sub_826DC780(ctx, base);
	// b 0x826a3ca0
	goto loc_826A3CA0;
loc_826A3C98:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8fa8
	ctx.lr = 0x826A3CA0;
	sub_826E8FA8(ctx, base);
loc_826A3CA0:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,22480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22480);
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// stw r10,608(r11)
	REX_STORE_U32(ctx.r11.u32 + 608, ctx.r10.u32);
	// beq cr6,0x826a3928
	if (ctx.cr6.eq) goto loc_826A3928;
loc_826A3CB8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a392c
	if (ctx.cr6.eq) goto loc_826A392C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e870
	ctx.lr = 0x826A3CC8;
	sub_8269E870(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736178) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82855ce4
	ctx.lr = 0x82736198;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82736200
	if (!ctx.cr0.eq) goto loc_82736200;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// ori r4,r4,38
	ctx.r4.u64 = ctx.r4.u64 | 38;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x82855704
	ctx.lr = 0x827361C4;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x827361d4
	if (!ctx.cr0.lt) goto loc_827361D4;
	// li r31,1627
	ctx.r31.s64 = 1627;
	// b 0x827361f8
	goto loc_827361F8;
loc_827361D4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x827361f4
	if (!ctx.cr6.eq) goto loc_827361F4;
	// bl 0x8263bcc8
	ctx.lr = 0x827361E0;
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
	// b 0x827361f8
	goto loc_827361F8;
loc_827361F4:
	// li r31,997
	ctx.r31.s64 = 997;
loc_827361F8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a64
	ctx.lr = 0x82736200;
	__imp__ObDereferenceObject(ctx, base);
loc_82736200:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_82737A90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82737ab4
	if (!ctx.cr6.lt) goto loc_82737AB4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// blr 
	return;
loc_82737AB4:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x82737b08
	if (ctx.cr6.eq) goto loc_82737B08;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// addi r9,r11,-2
	ctx.r9.s64 = ctx.r11.s64 + -2;
	// addi r10,r4,-2
	ctx.r10.s64 = ctx.r4.s64 + -2;
loc_82737AD0:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82737af0
	if (ctx.cr6.eq) goto loc_82737AF0;
	// lhz r8,2(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r8,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// rlwimi r11,r8,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// b 0x82737af4
	goto loc_82737AF4;
loc_82737AF0:
	// lhzu r11,2(r10)
	ea = 2 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U16(ea);
	ctx.r10.u32 = ea;
loc_82737AF4:
	// sthu r11,2(r9)
	ea = 2 + ctx.r9.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r9.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// bdnz 0x82737ad0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82737AD0;
loc_82737B08:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82739518) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r3,65
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 65, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmpwi cr6,r3,90
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 90, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82739AD8) {
	REX_FUNC_PROLOGUE();
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82739918
	sub_82739918(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82739AE0) {
	REX_FUNC_PROLOGUE();
	// stfd f2,24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 24, ctx.f2.u64);
	// lwz r11,24(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 24);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfd f1,16(r1)
	REX_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r9,16(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r8,20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lfd f0,24136(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 24136);
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// stw r8,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r8.u32);
	// rlwimi r11,r9,0,1,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7FFFFFFF) | (ctx.r11.u64 & 0xFFFFFFFF80000000);
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lfd f1,-16(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(__savegprlr_31) {
	REX_FUNC_PROLOGUE();
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(__restgprlr_18) {
	REX_FUNC_PROLOGUE();
	// ld r18,-120(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
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

DEFINE_REX_FUNC(__savefpr_21) {
	REX_FUNC_PROLOGUE();
	// stfd f21,-88(r12)
	ctx.fpscr.disableFlushMode();
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

DEFINE_REX_FUNC(__savevmx_14) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx v14,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx v15,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx v16,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx v17,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(__savevmx_123) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_14) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx v14,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx v15,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx v16,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(__restvmx_99) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v99.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8273EC38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8273EC40;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-16377
	ctx.r11.s64 = -1073283072;
	// stfd f1,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.f1.u64);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// ori r29,r11,65279
	ctx.r29.u64 = ctx.r11.u64 | 65279;
	// li r3,248
	ctx.r3.s64 = 248;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273f770
	ctx.lr = 0x8273EC6C;
	sub_8273F770(ctx, base);
	// lhz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 160);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,17,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x8273ecf8
	if (!ctx.cr6.eq) goto loc_8273ECF8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8273ea80
	ctx.lr = 0x8273EC88;
	sub_8273EA80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x8273ecc4
	if (!ctx.cr0.gt) goto loc_8273ECC4;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x8273edec
	if (!ctx.cr6.gt) goto loc_8273EDEC;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8273ecc4
	if (!ctx.cr6.eq) goto loc_8273ECC4;
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// li r3,25
	ctx.r3.s64 = 25;
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f0
	ctx.f2.f64 = double(ctx.f0.s64);
	// bl 0x8273f608
	ctx.lr = 0x8273ECC0;
	sub_8273F608(ctx, base);
	// b 0x8273edfc
	goto loc_8273EDFC;
loc_8273ECC4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// extsw r10,r31
	ctx.r10.s64 = ctx.r31.s32;
	// li r3,8
	ctx.r3.s64 = 8;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f13
	ctx.f2.f64 = double(ctx.f13.s64);
	// lfd f0,6304(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 6304);
	// fadd f3,f31,f0
	ctx.f3.f64 = ctx.f31.f64 + ctx.f0.f64;
loc_8273ECE4:
	// li r4,25
	ctx.r4.s64 = 25;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// bl 0x8273f688
	ctx.lr = 0x8273ECF4;
	sub_8273F688(ctx, base);
	// b 0x8273edfc
	goto loc_8273EDFC;
loc_8273ECF8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f30,24136(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x8273edec
	if (ctx.cr6.eq) goto loc_8273EDEC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8273eb08
	ctx.lr = 0x8273ED14;
	sub_8273EB08(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x8273ed34
	if (!ctx.cr6.lt) goto loc_8273ED34;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8273eda8
	if (ctx.cr6.lt) goto loc_8273EDA8;
	// b 0x8273ed48
	goto loc_8273ED48;
loc_8273ED34:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8273ed54
	if (ctx.cr6.gt) goto loc_8273ED54;
loc_8273ED48:
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmpwi cr6,r4,2560
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2560, ctx.xer);
	// ble cr6,0x8273ed80
	if (!ctx.cr6.gt) goto loc_8273ED80;
loc_8273ED54:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfd f1,-7200(r11)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r11.u32 + -7200);
	// bl 0x82739ae0
	ctx.lr = 0x8273ED64;
	sub_82739AE0(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
loc_8273ED70:
	// li r3,17
	ctx.r3.s64 = 17;
loc_8273ED74:
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
loc_8273ED78:
	// fcfid f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(ctx.f0.s64);
	// b 0x8273ece4
	goto loc_8273ECE4;
loc_8273ED80:
	// cmpwi cr6,r4,1024
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1024, ctx.xer);
	// ble cr6,0x8273eda0
	if (!ctx.cr6.gt) goto loc_8273EDA0;
	// addi r4,r4,-1536
	ctx.r4.s64 = ctx.r4.s64 + -1536;
	// bl 0x8273ea40
	ctx.lr = 0x8273ED90;
	sub_8273EA40(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8273ed70
	goto loc_8273ED70;
loc_8273EDA0:
	// cmpwi cr6,r4,-2557
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2557, ctx.xer);
	// bge cr6,0x8273edc0
	if (!ctx.cr6.lt) goto loc_8273EDC0;
loc_8273EDA8:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmul f3,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64 * ctx.f30.f64;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8273ed78
	goto loc_8273ED78;
loc_8273EDC0:
	// cmpwi cr6,r4,-1021
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1021, ctx.xer);
	// bge cr6,0x8273ede4
	if (!ctx.cr6.lt) goto loc_8273EDE4;
	// addi r4,r4,1536
	ctx.r4.s64 = ctx.r4.s64 + 1536;
	// bl 0x8273ea40
	ctx.lr = 0x8273EDD0;
	sub_8273EA40(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8273ed74
	goto loc_8273ED74;
loc_8273EDE4:
	// bl 0x8273ea40
	ctx.lr = 0x8273EDE8;
	sub_8273EA40(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_8273EDEC:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273f770
	ctx.lr = 0x8273EDF8;
	sub_8273F770(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8273EDFC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8274E948) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8274E950;
	__savegprlr_26(ctx, base);
	// clrlwi r27,r4,24
	ctx.r27.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mulli r3,r27,216
	ctx.r3.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(216));
	// mulli r4,r26,40
	ctx.r4.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(40));
	// mulli r30,r26,72
	ctx.r30.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(72));
	// mulli r31,r27,184
	ctx.r31.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(184));
	// mulli r5,r26,112
	ctx.r5.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(112));
	// mulli r29,r27,144
	ctx.r29.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(144));
	// mulli r7,r26,144
	ctx.r7.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(144));
	// mulli r6,r27,112
	ctx.r6.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(112));
	// mulli r9,r26,184
	ctx.r9.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(184));
	// mulli r8,r27,72
	ctx.r8.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(72));
	// mulli r11,r26,216
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(216));
	// mulli r10,r27,40
	ctx.r10.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(40));
	// add r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r27,r27,257
	ctx.r27.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(257));
	// sth r4,4(r28)
	REX_STORE_U16(ctx.r28.u32 + 4, ctx.r4.u16);
	// sth r27,0(r28)
	REX_STORE_U16(ctx.r28.u32 + 0, ctx.r27.u16);
	// mulli r26,r26,257
	ctx.r26.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(257));
	// sth r26,2(r28)
	REX_STORE_U16(ctx.r28.u32 + 2, ctx.r26.u16);
	// add r3,r30,r31
	ctx.r3.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + ctx.r29.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// sth r3,6(r28)
	REX_STORE_U16(ctx.r28.u32 + 6, ctx.r3.u16);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r5,8(r28)
	REX_STORE_U16(ctx.r28.u32 + 8, ctx.r5.u16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// sth r7,10(r28)
	REX_STORE_U16(ctx.r28.u32 + 10, ctx.r7.u16);
	// sth r9,12(r28)
	REX_STORE_U16(ctx.r28.u32 + 12, ctx.r9.u16);
	// sth r11,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r11.u16);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82755C68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// addi r11,r4,8
	ctx.r11.s64 = ctx.r4.s64 + 8;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,2524(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
loc_82755C9C:
	// lfs f13,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x82755cec
	if (!ctx.cr6.eq) goto loc_82755CEC;
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x82755cec
	if (!ctx.cr6.eq) goto loc_82755CEC;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x82755cec
	if (!ctx.cr6.eq) goto loc_82755CEC;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x82755cec
	if (!ctx.cr6.eq) goto loc_82755CEC;
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f0,-4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// stfs f0,-8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
loc_82755CEC:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x82755c9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82755C9C;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8275C730) {
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
	// bge cr6,0x8275c814
	if (!ctx.cr6.lt) goto loc_8275C814;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lfs f0,-30528(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30528);
	ctx.f0.f64 = double(temp.f32);
loc_8275C78C:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// rlwinm r10,r10,28,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xF;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,8(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// lhzu r10,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// rlwinm r10,r10,20,12,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,12(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz 0x8275c78c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8275C78C;
loc_8275C814:
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275c830
	if (ctx.cr6.eq) goto loc_8275C830;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275C830;
	sub_82755C68(ctx, base);
loc_8275C830:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275c84c
	if (ctx.cr6.eq) goto loc_8275C84C;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82756030
	ctx.lr = 0x8275C84C;
	sub_82756030(ctx, base);
loc_8275C84C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82762380) {
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
	// addi r4,r4,8
	ctx.r4.s64 = ctx.r4.s64 + 8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82761660
	ctx.lr = 0x827623A4;
	sub_82761660(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827623c0
	if (ctx.cr0.lt) goto loc_827623C0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827618a8
	ctx.lr = 0x827623B8;
	sub_827618A8(ctx, base);
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_827623C0:
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

DEFINE_REX_FUNC(sub_82763698) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827636A0;
	__savegprlr_24(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r31,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r29,r3,4
	ctx.r29.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-29640
	ctx.r9.s64 = ctx.r10.s64 + -29640;
	// stw r31,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// std r31,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// lis r6,21587
	ctx.r6.s64 = 1414725632;
	// std r31,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// stw r9,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// stw r31,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r31,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r31,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r31,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// ori r6,r6,20041
	ctx.r6.u64 = ctx.r6.u64 | 20041;
	// stw r31,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r31.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// stw r31,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r31.u32);
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stw r31,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// stw r31,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// bl 0x82762998
	ctx.lr = 0x82763724;
	sub_82762998(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82763910
	if (ctx.cr6.lt) goto loc_82763910;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,20
	ctx.r6.s64 = 20;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82762700
	ctx.lr = 0x82763744;
	sub_82762700(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82763910
	if (ctx.cr6.lt) goto loc_82763910;
	// lhz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x827637b0
	if (!ctx.cr6.eq) goto loc_827637B0;
	// addi r27,r1,88
	ctx.r27.s64 = ctx.r1.s64 + 88;
loc_8276375C:
	// lis r6,19282
	ctx.r6.s64 = 1263665152;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// ori r6,r6,16717
	ctx.r6.u64 = ctx.r6.u64 | 16717;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82762998
	ctx.lr = 0x82763774;
	sub_82762998(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82763910
	if (ctx.cr6.lt) goto loc_82763910;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r30,132(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r26,r11,-27856
	ctx.r26.s64 = ctx.r11.s64 + -27856;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82764508
	ctx.lr = 0x82763798;
	sub_82764508(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x827637d4
	if (!ctx.cr6.eq) goto loc_827637D4;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x827638f4
	goto loc_827638F4;
loc_827637B0:
	// lhz r10,94(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x827637c4
	if (!ctx.cr6.eq) goto loc_827637C4;
	// addi r27,r1,94
	ctx.r27.s64 = ctx.r1.s64 + 94;
	// b 0x8276375c
	goto loc_8276375C;
loc_827637C4:
	// lis r3,-28655
	ctx.r3.s64 = -1877934080;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_827637D4:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82762700
	ctx.lr = 0x827637EC;
	sub_82762700(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x827638f4
	if (ctx.cr6.lt) goto loc_827638F4;
	// lhz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82763848
	if (ctx.cr6.eq) goto loc_82763848;
	// lhz r6,2(r27)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r27.u32 + 2);
loc_82763814:
	// lhz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x82763844
	if (ctx.cr6.eq) goto loc_82763844;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// lbz r10,6(r7)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + 6);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// add r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 + ctx.r7.u64;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r7,r8,8
	ctx.r7.s64 = ctx.r8.s64 + 8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82763814
	if (ctx.cr6.lt) goto loc_82763814;
	// b 0x82763848
	goto loc_82763848;
loc_82763844:
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
loc_82763848:
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82763860
	if (ctx.cr6.lt) goto loc_82763860;
	// lis r30,-28655
	ctx.r30.s64 = -1877934080;
	// ori r30,r30,3
	ctx.r30.u64 = ctx.r30.u64 | 3;
	// b 0x827638f4
	goto loc_827638F4;
loc_82763860:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827638a8
	if (ctx.cr6.eq) goto loc_827638A8;
	// clrlwi r6,r28,16
	ctx.r6.u64 = ctx.r28.u32 & 0xFFFF;
loc_82763870:
	// cmplw cr6,r31,r6
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x82763888
	if (ctx.cr6.eq) goto loc_82763888;
	// lhz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r27.u32 + 4);
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x827638a8
	if (ctx.cr6.eq) goto loc_827638A8;
loc_82763888:
	// lbz r8,6(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82763870
	if (ctx.cr6.lt) goto loc_82763870;
loc_827638A8:
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x827638c0
	if (ctx.cr6.lt) goto loc_827638C0;
	// lis r30,-28655
	ctx.r30.s64 = -1877934080;
	// ori r30,r30,3
	ctx.r30.u64 = ctx.r30.u64 | 3;
	// b 0x827638f4
	goto loc_827638F4;
loc_827638C0:
	// lwz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2);
	// lwz r9,2(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 2);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827638dc
	if (ctx.cr6.lt) goto loc_827638DC;
	// lis r30,-28655
	ctx.r30.s64 = -1877934080;
	// ori r30,r30,3
	ctx.r30.u64 = ctx.r30.u64 | 3;
	// b 0x827638f4
	goto loc_827638F4;
loc_827638DC:
	// lwz r10,2(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 2);
	// stw r10,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// lwz r9,2(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 2);
	// lwz r8,2(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 2);
	// subf r7,r8,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r8.u64;
	// stw r7,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r7.u32);
loc_827638F4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8276390c
	if (ctx.cr6.eq) goto loc_8276390C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82764518
	ctx.lr = 0x8276390C;
	sub_82764518(ctx, base);
loc_8276390C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82763910:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827702F0) {
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
	// lwz r3,400(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 400);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r4,100(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// bl 0x82771f58
	ctx.lr = 0x82770318;
	sub_82771F58(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8277033c
	if (!ctx.cr0.lt) goto loc_8277033C;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4119
	ctx.r11.u64 = ctx.r11.u64 | 4119;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82770370
	if (!ctx.cr6.eq) goto loc_82770370;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1617
	ctx.r3.u64 = ctx.r3.u64 | 1617;
	// b 0x82770370
	goto loc_82770370;
loc_8277033C:
	// lwz r11,404(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 404);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,404(r30)
	REX_STORE_U32(ctx.r30.u32 + 404, ctx.r11.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// b 0x8277035c
	goto loc_8277035C;
loc_82770354:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_8277035C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82770354
	if (!ctx.cr6.eq) goto loc_82770354;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827700c0
	ctx.lr = 0x8277036C;
	sub_827700C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82770370:
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

DEFINE_REX_FUNC(sub_82771F90) {
	REX_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm. r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82771fa8
	if (ctx.cr0.eq) goto loc_82771FA8;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// b 0x827787b0
	sub_827787B0(ctx, base);
	return;
loc_82771FA8:
	// rlwinm. r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82771fbc
	if (ctx.cr0.eq) goto loc_82771FBC;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// b 0x82778958
	sub_82778958(ctx, base);
	return;
loc_82771FBC:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82772DF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82772E00;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 72);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,52
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 52, ctx.xer);
	// blt cr6,0x827730c8
	if (ctx.cr6.lt) goto loc_827730C8;
	// lwz r30,68(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r25,20(r30)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r24,24(r30)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x827730c8
	if (!ctx.cr6.eq) goto loc_827730C8;
	// lbz r11,35(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// lbz r10,33(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 33);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x827730c8
	if (ctx.cr6.gt) goto loc_827730C8;
	// lbz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// lbz r10,34(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 34);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x827730c8
	if (ctx.cr6.gt) goto loc_827730C8;
	// ld r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 92);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82772e68
	if (ctx.cr6.eq) goto loc_82772E68;
	// ld r10,44(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 44);
	// cmpld cr6,r11,r10
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r10.u64, ctx.xer);
	// bne cr6,0x827730c8
	if (!ctx.cr6.eq) goto loc_827730C8;
loc_82772E68:
	// lwz r8,28(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// li r26,0
	ctx.r26.s64 = 0;
	// mulli r11,r8,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// addi r29,r11,112
	ctx.r29.s64 = ctx.r11.s64 + 112;
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82772eb4
	if (ctx.cr6.eq) goto loc_82772EB4;
	// ld r7,44(r28)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r28.u32 + 44);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
loc_82772E94:
	// ld r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r6,r7
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, ctx.r7.u64, ctx.xer);
	// beq cr6,0x827730c8
	if (ctx.cr6.eq) goto loc_827730C8;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,92
	ctx.r10.s64 = ctx.r10.s64 + 92;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82772e94
	if (ctx.cr6.lt) goto loc_82772E94;
loc_82772EB4:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x827730c8
	if (!ctx.cr6.lt) goto loc_827730C8;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mulli r9,r11,92
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(92));
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r31,r9,r10
	ctx.r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r4,r28,8
	ctx.r4.s64 = ctx.r28.s64 + 8;
	// ld r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 44);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stdx r11,r9,r10
	REX_STORE_U64(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u64);
	// li r5,36
	ctx.r5.s64 = 36;
	// bl 0x8273a030
	ctx.lr = 0x82772EE8;
	sub_8273A030(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r4,r28,52
	ctx.r4.s64 = ctx.r28.s64 + 52;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8273a030
	ctx.lr = 0x82772EF8;
	sub_8273A030(ctx, base);
	// lbz r10,35(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// lbz r11,33(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 33);
	// addi r5,r30,37
	ctx.r5.s64 = ctx.r30.s64 + 37;
	// li r8,15
	ctx.r8.s64 = 15;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r9,r5,15
	ctx.r9.s64 = ctx.r5.s64 + 15;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// li r6,15
	ctx.r6.s64 = 15;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,36(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// lbz r11,34(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 34);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// lbz r11,35(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 35);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lbz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 36);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// lwz r30,32(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// lwz r10,72(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// lwz r11,36(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 36);
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r10,r10,-52
	ctx.r10.s64 = ctx.r10.s64 + -52;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82639f80
	ctx.lr = 0x82772F70;
	sub_82639F80(ctx, base);
	// sth r26,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r26.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a560
	ctx.lr = 0x82772F7C;
	sub_8273A560(ctx, base);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r9,r9,32770
	ctx.r9.u64 = ctx.r9.u64 | 32770;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r8,r11,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r11.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stb r7,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r7.u8);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// stw r30,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// stw r8,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// addi r10,r10,-24
	ctx.r10.s64 = ctx.r10.s64 + -24;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// beq cr6,0x82773058
	if (ctx.cr6.eq) goto loc_82773058;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82773054
	if (ctx.cr6.eq) goto loc_82773054;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827844a0
	ctx.lr = 0x82773008;
	sub_827844A0(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82771a88
	ctx.lr = 0x8277302C;
	sub_82771A88(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8277303c
	if (!ctx.cr0.lt) goto loc_8277303C;
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// b 0x82773048
	goto loc_82773048;
loc_8277303C:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_82773048:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82771948
	ctx.lr = 0x82773050;
	sub_82771948(ctx, base);
	// b 0x82773058
	goto loc_82773058;
loc_82773054:
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
loc_82773058:
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// stw r26,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// stw r26,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// beq cr6,0x827730b8
	if (ctx.cr6.eq) goto loc_827730B8;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827730b8
	if (ctx.cr6.eq) goto loc_827730B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82770d20
	ctx.lr = 0x82773080;
	sub_82770D20(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82771040
	ctx.lr = 0x827730A4;
	sub_82771040(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827730b0
	if (ctx.cr0.lt) goto loc_827730B0;
	// stw r24,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
loc_827730B0:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82770fe8
	ctx.lr = 0x827730B8;
	sub_82770FE8(ctx, base);
loc_827730B8:
	// lwz r11,32(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 32);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,36(r27)
	REX_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
loc_827730C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82784F68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82784F70;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82784fdc
	if (ctx.cr6.eq) goto loc_82784FDC;
	// addi r29,r11,16
	ctx.r29.s64 = ctx.r11.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x82784F90;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82784fc8
	if (ctx.cr6.eq) goto loc_82784FC8;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
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
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// b 0x82784fd0
	goto loc_82784FD0;
loc_82784FC8:
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
loc_82784FD0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x82784FD8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82784fe4
	goto loc_82784FE4;
loc_82784FDC:
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
loc_82784FE4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827871D8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// addi r10,r10,-28896
	ctx.r10.s64 = ctx.r10.s64 + -28896;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82597cc0
	sub_82597CC0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82787BB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82787BB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,4626
	ctx.r10.s64 = 303169536;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,4626
	ctx.r10.u64 = ctx.r10.u64 | 4626;
	// stw r9,108(r4)
	REX_STORE_U32(ctx.r4.u32 + 108, ctx.r9.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r9,116(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 116);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r11,r4,112
	ctx.r11.s64 = ctx.r4.s64 + 112;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82787c3c
	if (!ctx.cr6.eq) goto loc_82787C3C;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x82787c30
	if (!ctx.cr6.lt) goto loc_82787C30;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82787C08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82786ea8
	ctx.lr = 0x82787C24;
	sub_82786EA8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82787c40
	if (!ctx.cr0.eq) goto loc_82787C40;
	// b 0x82787c3c
	goto loc_82787C3C;
loc_82787C30:
	// lis r10,13364
	ctx.r10.s64 = 875823104;
	// ori r10,r10,13364
	ctx.r10.u64 = ctx.r10.u64 | 13364;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82787C3C:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82787C40:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82786970
	ctx.lr = 0x82787C4C;
	sub_82786970(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278A3D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8278A3D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,244
	ctx.r29.s64 = ctx.r3.s64 + 244;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82855b44
	ctx.lr = 0x8278A3F0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addic r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// lwz r10,448(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 448);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// subfe r11,r11,r31
	temp.u8 = (~ctx.r11.u32 + ctx.r31.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r31.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r31.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r11,31,0,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x80000000) | (ctx.r10.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r10,448(r30)
	REX_STORE_U32(ctx.r30.u32 + 448, ctx.r10.u32);
	// bne cr6,0x8278a46c
	if (!ctx.cr6.eq) goto loc_8278A46C;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// addi r31,r30,288
	ctx.r31.s64 = ctx.r30.s64 + 288;
	// b 0x8278a464
	goto loc_8278A464;
loc_8278A418:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8278a42c
	if (!ctx.cr6.eq) goto loc_8278A42C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8278a44c
	goto loc_8278A44C;
loc_8278A42C:
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
loc_8278A44C:
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x82789c80
	ctx.lr = 0x8278A454;
	sub_82789C80(ctx, base);
	// lwz r11,284(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,284(r30)
	REX_STORE_U32(ctx.r30.u32 + 284, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8278A464:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8278a418
	if (!ctx.cr6.eq) goto loc_8278A418;
loc_8278A46C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x8278A474;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278E3B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8278E3B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1048(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1048);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x8278e3ec
	if (!ctx.cr6.eq) goto loc_8278E3EC;
	// lhz r11,336(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 336);
	// andi. r11,r11,49151
	ctx.r11.u64 = ctx.r11.u64 & 49151;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r11,336(r4)
	REX_STORE_U16(ctx.r4.u32 + 336, ctx.r11.u16);
	// b 0x8278e418
	goto loc_8278E418;
loc_8278E3EC:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x82789c80
	ctx.lr = 0x8278E418;
	sub_82789C80(ctx, base);
loc_8278E418:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r11,r11,0,25,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x60;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// blt cr6,0x8278e484
	if (ctx.cr6.lt) goto loc_8278E484;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8278e484
	if (ctx.cr6.gt) goto loc_8278E484;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// subf r10,r10,r26
	ctx.r10.u64 = ctx.r26.u64 - ctx.r10.u64;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8278e484
	if (ctx.cr6.lt) goto loc_8278E484;
	// lwz r11,700(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 700);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_8278E484:
	// lhz r11,330(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 330);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8278e498
	if (ctx.cr0.eq) goto loc_8278E498;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82794db0
	ctx.lr = 0x8278E498;
	sub_82794DB0(ctx, base);
loc_8278E498:
	// lhz r11,330(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 330);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8278e528
	if (ctx.cr0.eq) goto loc_8278E528;
	// lwz r10,1036(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 1036);
	// addi r11,r28,1032
	ctx.r11.s64 = ctx.r28.s64 + 1032;
	// lhz r9,332(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 332);
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subfic r8,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r8.u64 = static_cast<uint64_t>(0) - ctx.r8.u64;
	// subfe r8,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8278e4f0
	if (ctx.cr6.eq) goto loc_8278E4F0;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
loc_8278E4CC:
	// lhz r8,324(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 324);
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// extsh. r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x8278e50c
	if (!ctx.cr0.gt) goto loc_8278E50C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8278e4f0
	if (ctx.cr6.eq) goto loc_8278E4F0;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8278e4cc
	if (!ctx.cr0.eq) goto loc_8278E4CC;
loc_8278E4F0:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// b 0x8278e53c
	goto loc_8278E53C;
loc_8278E50C:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// b 0x8278e53c
	goto loc_8278E53C;
loc_8278E528:
	// lhz r11,1076(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 1076);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,1076(r28)
	REX_STORE_U16(ctx.r28.u32 + 1076, ctx.r11.u16);
	// bl 0x82789c80
	ctx.lr = 0x8278E53C;
	sub_82789C80(ctx, base);
loc_8278E53C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82798060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82798068;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r26,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r26.u32);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r30,r3,64
	ctx.r30.s64 = ctx.r3.s64 + 64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// b 0x827980c0
	goto loc_827980C0;
loc_82798090:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
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
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// bl 0x8279bf78
	ctx.lr = 0x827980B4;
	sub_8279BF78(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x827981c4
	if (!ctx.cr0.eq) goto loc_827981C4;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_827980C0:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82798090
	if (!ctx.cr6.eq) goto loc_82798090;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279812c
	if (ctx.cr0.eq) goto loc_8279812C;
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r10,160(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r5,36(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// bne cr6,0x827980f4
	if (!ctx.cr6.eq) goto loc_827980F4;
	// lwz r9,152(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
loc_827980F4:
	// addic r4,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// lwz r8,12(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lwz r6,12(r5)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// subfe r11,r4,r11
	temp.u8 = (~ctx.r4.u32 + ctx.r11.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r7,16(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r31,232
	ctx.r3.s64 = ctx.r31.s64 + 232;
	// lwz r5,16(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x82795cf8
	ctx.lr = 0x82798124;
	sub_82795CF8(ctx, base);
loc_82798124:
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// b 0x827981c4
	goto loc_827981C4;
loc_8279812C:
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82798190
	if (ctx.cr0.eq) goto loc_82798190;
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r10,160(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r5,36(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// bne cr6,0x82798158
	if (!ctx.cr6.eq) goto loc_82798158;
	// lwz r9,152(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
loc_82798158:
	// addic r4,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// lwz r8,12(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lwz r6,12(r5)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// subfe r11,r4,r11
	temp.u8 = (~ctx.r4.u32 + ctx.r11.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r7,16(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// ori r4,r3,1
	ctx.r4.u64 = ctx.r3.u64 | 1;
	// lwz r5,16(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82795cf8
	ctx.lr = 0x8279818C;
	sub_82795CF8(ctx, base);
	// b 0x82798124
	goto loc_82798124;
loc_82798190:
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x827981c8
	if (ctx.cr0.eq) goto loc_827981C8;
	// lwz r10,208(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827981c8
	if (!ctx.cr6.eq) goto loc_827981C8;
	// rlwinm r11,r11,0,5,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82797a18
	ctx.lr = 0x827981BC;
	sub_82797A18(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_827981C4:
	// li r29,1
	ctx.r29.s64 = 1;
loc_827981C8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A2DB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// ld r9,40(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 40);
	// li r8,20
	ctx.r8.s64 = 20;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,360(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// divdu r9,r9,r8
	ctx.r9.u64 = ctx.r8.u64 ? ctx.r9.u64 / ctx.r8.u64 : 0;
	// addi r8,r3,360
	ctx.r8.s64 = ctx.r3.s64 + 360;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// sth r9,68(r3)
	REX_STORE_U16(ctx.r3.u32 + 68, ctx.r9.u16);
	// std r11,296(r3)
	REX_STORE_U64(ctx.r3.u32 + 296, ctx.r11.u64);
	// stw r11,304(r3)
	REX_STORE_U32(ctx.r3.u32 + 304, ctx.r11.u32);
	// stb r11,308(r3)
	REX_STORE_U8(ctx.r3.u32 + 308, ctx.r11.u8);
	// stw r11,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r11.u32);
	// beq cr6,0x827a2e48
	if (ctx.cr6.eq) goto loc_827A2E48;
	// addi r7,r3,352
	ctx.r7.s64 = ctx.r3.s64 + 352;
loc_827A2DF4:
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827a2e1c
	if (ctx.cr6.eq) goto loc_827A2E1C;
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x827a2e10
	if (!ctx.cr6.eq) goto loc_827A2E10;
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
loc_827A2E10:
	// lwz r6,4(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_827A2E1C:
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827a2e34
	if (ctx.cr6.eq) goto loc_827A2E34;
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x827a2e38
	goto loc_827A2E38;
loc_827A2E34:
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_827A2E38:
	// stw r10,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827a2df4
	if (!ctx.cr6.eq) goto loc_827A2DF4;
loc_827A2E48:
	// li r10,25
	ctx.r10.s64 = 25;
	// addi r11,r3,72
	ctx.r11.s64 = ctx.r3.s64 + 72;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_827A2E54:
	// ld r10,280(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 280);
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x827a2e54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A2E54;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827A92F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x827A9300;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827a9330
	if (ctx.cr6.eq) goto loc_827A9330;
	// addi r30,r4,-4
	ctx.r30.s64 = ctx.r4.s64 + -4;
	// addi r29,r5,-4
	ctx.r29.s64 = ctx.r5.s64 + -4;
loc_827A9318:
	// lfsu f1,4(r30)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r30.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r30.u32 = ea;
	// bl 0x82739a10
	ctx.lr = 0x827A9320;
	sub_82739A10(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfsu f0,4(r29)
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x827a9318
	if (!ctx.cr0.eq) goto loc_827A9318;
loc_827A9330:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AC020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lha r11,8(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 8));
	// cmpwi cr6,r11,84
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 84, ctx.xer);
	// bgt cr6,0x827ac060
	if (ctx.cr6.gt) goto loc_827AC060;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-9136(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9136);
	ctx.f0.f64 = double(temp.f32);
loc_827AC038:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lfsx f13,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f13,r9,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// ble cr6,0x827ac038
	if (!ctx.cr6.gt) goto loc_827AC038;
	// b 0x827ac068
	goto loc_827AC068;
loc_827AC060:
	// li r11,84
	ctx.r11.s64 = 84;
	// sth r11,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r11.u16);
loc_827AC068:
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r11.u16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,22168
	ctx.r9.s64 = ctx.r11.s64 + 22168;
	// lfs f0,22168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10476(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD4C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADA50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADFA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10156(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10156);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AED48) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9716(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9716);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFA70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B05B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0E28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,23352
	ctx.r9.s64 = ctx.r11.s64 + 23352;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B36A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7444(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3D58) {
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
	// lfs f0,23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4EF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-6740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6740);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-6736(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -6736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5830) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6456(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7470) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5736(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5736);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5620(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8878) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,24504
	ctx.r9.s64 = ctx.r11.s64 + 24504;
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5056(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,24664
	ctx.r9.s64 = ctx.r11.s64 + 24664;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA5E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4196(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB2A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BBF28) {
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
	// lfs f0,25440(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-3420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BCE70) {
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
	// lfs f13,-3020(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3020);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2968(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDD98) {
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
	// lfs f0,25768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2632);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BEFA0) {
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
	// lfs f0,25992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1496(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1496);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1492(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1F40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -732);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -188);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-184(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3D08) {
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
	// lfs f0,27224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,224(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4DB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 788);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,792(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5B38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,27736
	ctx.r9.s64 = ctx.r11.s64 + 27736;
	// lfs f0,27736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1188(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8808) {
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
	// lfs f0,28584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2436(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2436);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2556(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9A60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2988(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2988);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD470) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4704(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4704);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE2D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5228(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF148) {
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
	// lfs f0,29672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D03B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6188);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D14A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30060);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6680(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D30C0) {
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
	// lfs f0,30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7440(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7440);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7504(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D42F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D53E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8924(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6FD8) {
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
	// lfs f0,30952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8258) {
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
	// lfs f0,31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D94E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA5C0) {
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
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10796(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB7F0) {
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
	// lfs f0,31688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11328(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11328);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11444(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCA90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDA48) {
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
	// lfs f0,32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12468(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DEBE8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12988(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFE98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13980(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3E90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15404(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4E20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5BF0) {
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
	// lfs f0,16212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-31128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31128);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,16228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7108) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-28600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16736(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16736);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E80E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-26712
	ctx.r9.s64 = ctx.r11.s64 + -26712;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17272(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-24020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA368) {
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
	// lfs f0,-23656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18124(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18124);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,18820(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18820);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,18824(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC230) {
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
	// lfs f0,19080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19080);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22384(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22384);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,19104(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 19104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDB38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEC60) {
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
	// lfs f0,-20152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20152);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20240(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20240);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,20260(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 20260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0538) {
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
	// lfs f0,-19080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20948(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18244);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2960) {
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
	// lfs f0,21928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21928);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17880);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,21952(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 21952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F46A0) {
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
	// lfs f0,-16680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22904(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22904);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5780) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-15888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23492(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F67A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23940);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7648) {
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
	// lfs f0,-14040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8D10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9BB0) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25364(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FAEB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-9688
	ctx.r9.s64 = ctx.r11.s64 + -9688;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25908(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-9496
	ctx.r9.s64 = ctx.r11.s64 + -9496;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD620) {
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
	// lfs f0,-9304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE980) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27508(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27508);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27620(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFC98) {
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
	// lfs f0,-8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28060(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28060);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28176(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800FD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801D88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802BF8) {
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
	// lfs f0,-8408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29504(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29504);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29564(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803FA0) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30136(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,30708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30708);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,30712(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 30712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7876);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806BB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,31416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31416);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,31420(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 31420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807628) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808480) {
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
	// lfs f0,-7512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32144(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809800) {
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
	// lfs f0,-7320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32632);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280AC58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32340(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32340);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32232(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BB78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DAD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-6576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6576);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30864(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E480) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-30576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30576);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30572(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280EDE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FCE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810DE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811D88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-28896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28896);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-28892(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -28892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28608(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28608, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813570) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27740(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815448) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828163E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817320) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26304(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828183F8) {
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
	// lfs f0,-3896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25784(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25784, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828195F8) {
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
	// lfs f0,-3672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25256(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AA88) {
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
	// lfs f0,-3224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24684(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24684);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BD68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24076(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DD88) {
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
	// lfs f0,-2504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23108(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F140) {
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
	// lfs f0,-2200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22572(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22572);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22524(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828215A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-21568(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21568);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828224C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21020(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828244C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825320) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19180(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828271C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-464
	ctx.r9.s64 = ctx.r11.s64 + -464;
	// lfs f0,-464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18724(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -18724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18248(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829348) {
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
	// lfs f0,-80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17860(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17860);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17740(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A5D8) {
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
	// lfs f0,152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17264);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,424
	ctx.r9.s64 = ctx.r11.s64 + 424;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16620(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282CDC0) {
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
	// lfs f0,624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16140);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E110) {
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
	// lfs f0,872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15568);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15452(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F550) {
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
	// lfs f12,-14956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828308B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828317D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13828(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828326F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828346D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835710) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12024(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12024);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11940(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828369F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-11392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-11388(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837478) {
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
	// lfs f0,2808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11192(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11192);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11076(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-24424(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24424);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-10480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A8F0) {
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
	// lfs f0,3408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9656);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BD28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3716(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3716);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CB48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DA88) {
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
	// lfs f0,4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EF08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-7500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7500);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7496(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F8E0) {
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
	// lfs f12,-7324(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7324);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840EB0) {
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
	// lfs f0,4688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6672(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6672);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-6020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6020);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-6016(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -6016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842B40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843A40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5284);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844B58) {
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
	// lfs f0,5480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845D50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-4232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4228(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828477B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,6032
	ctx.r9.s64 = ctx.r11.s64 + 6032;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848C90) {
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
	// lfs f0,6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2836(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A0C0) {
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
	// lfs f0,6512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r9,r9,32608
	ctx.r9.s64 = ctx.r9.s64 + 32608;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r8,-1652
	ctx.r11.s64 = ctx.r8.s64 + -1652;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f13,-1652(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + -1652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E0E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EF80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,80(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 80, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FF28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1492(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852FA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1988(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853F50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r8,r9,2528
	ctx.r8.s64 = ctx.r9.s64 + 2528;
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82873F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82873F20;
	__savegprlr_27(ctx, base);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v63,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,16
	ctx.r11.s64 = 16;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// vspltish v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x1)));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r31,r3,r4
	ctx.r31.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,48
	ctx.r30.s64 = 48;
	// lvx128 v60,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,96
	ctx.r29.s64 = 96;
	// lvx128 v59,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,144
	ctx.r28.s64 = 144;
	// lvx128 v58,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 8, ctx.xer);
	// lvx128 v57,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v6,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsl v5,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v4,v63,v57,v6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v3,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v2,v61,v58,v5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v31,v60,v56,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// vperm128 v30,v59,v55,v1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v54,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v12,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v11,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v9,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v29,v62,v54,v7
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vslh v28,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v27,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v26,v10,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v25,v9,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v24,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v23,v27,v12
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v22,v26,v11
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v21,v25,v10
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v20,v28,v24
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vadduhm v19,v23,v11
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v18,v22,v10
	simde_mm_store_si128((simde__m128i*)ctx.v18.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v17,v21,v9
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vadduhm v16,v20,v12
	simde_mm_store_si128((simde__m128i*)ctx.v16.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// stvx128 v19,r5,r30
	ea = (ctx.r5.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r5,r29
	ea = (ctx.r5.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v17,r5,r28
	ea = (ctx.r5.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x828740b0
	if (!ctx.cr6.eq) goto loc_828740B0;
	// add r10,r9,r4
	ctx.r10.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lvx128 v53,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r8,r4,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// add r31,r9,r4
	ctx.r31.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lvx128 v52,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,192
	ctx.r30.s64 = 192;
	// lvx128 v51,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,240
	ctx.r29.s64 = 240;
	// lvx128 v50,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,288
	ctx.r28.s64 = 288;
	// lvx128 v49,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,336
	ctx.r27.s64 = 336;
	// lvx128 v48,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsl v6,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v5,v53,v51,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvsl v4,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v3,v52,v49,v6
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v47,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v2,v50,v48,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v46,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v1,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v12,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v31,v47,v46,v1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vmrghb v11,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v30,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v0,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v29,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v28,v10,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v27,v30,v9
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vslh v26,v0,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v25,v29,v12
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v24,v28,v11
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v23,v27,v12
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v22,v26,v10
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v21,v25,v11
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vadduhm v20,v24,v10
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// stvx128 v23,r5,r30
	ea = (ctx.r5.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v19,v22,v0
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// stvx128 v21,r5,r29
	ea = (ctx.r5.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v20,r5,r28
	ea = (ctx.r5.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v19,r5,r27
	ea = (ctx.r5.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_828740B0:
	// cmpwi cr6,r6,8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 8, ctx.xer);
	// bne cr6,0x82874128
	if (!ctx.cr6.eq) goto loc_82874128;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// addi r6,r5,16
	ctx.r6.s64 = ctx.r5.s64 + 16;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x82874128
	if (!ctx.cr6.gt) goto loc_82874128;
	// addi r8,r7,-1
	ctx.r8.s64 = ctx.r7.s64 + -1;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r7,r10,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// subf r31,r10,r4
	ctx.r31.u64 = ctx.r4.u64 - ctx.r10.u64;
	// addi r9,r6,-48
	ctx.r9.s64 = ctx.r6.s64 + -48;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_828740EC:
	// lbzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// lbzux r6,r7,r10
	ea = ctx.r7.u32 + ctx.r10.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r7.u32 = ea;
	// rotlwi r4,r5,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// add r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 + ctx.r6.u64;
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// sth r6,48(r9)
	REX_STORE_U16(ctx.r9.u32 + 48, ctx.r6.u16);
	// sthu r5,96(r9)
	ea = 96 + ctx.r9.u32;
	REX_STORE_U16(ea, ctx.r5.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x828740ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828740EC;
loc_82874128:
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

