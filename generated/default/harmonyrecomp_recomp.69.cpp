#include "harmonyrecomp_funcs.69.h"

DEFINE_REX_FUNC(sub_822156B0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-12788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12788);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,108(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822156E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-12788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12788);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,112(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82215704;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8221574c
	goto loc_8221574C;
loc_82215714:
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8221573c
	if (ctx.cr0.gt) goto loc_8221573C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221573C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221573C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x82215744;
	sub_82216520(ctx, base);
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8221574C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82215714
	if (!ctx.cr6.eq) goto loc_82215714;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8221579c
	goto loc_8221579C;
loc_82215764:
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8221578c
	if (ctx.cr0.gt) goto loc_8221578C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221578C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221578C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x82215794;
	sub_82216520(ctx, base);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8221579C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82215764
	if (!ctx.cr6.eq) goto loc_82215764;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x822157ec
	goto loc_822157EC;
loc_822157B4:
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x822157dc
	if (ctx.cr0.gt) goto loc_822157DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822157DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822157DC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x822157E4;
	sub_82216520(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_822157EC:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822157b4
	if (!ctx.cr6.eq) goto loc_822157B4;
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8221583c
	goto loc_8221583C;
loc_82215804:
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8221582c
	if (ctx.cr0.gt) goto loc_8221582C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221582C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221582C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x82215834;
	sub_82216520(ctx, base);
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8221583C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82215804
	if (!ctx.cr6.eq) goto loc_82215804;
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

DEFINE_REX_FUNC(sub_822263A0) {
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
	// lfs f0,104(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f12,112(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,108(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f11,116(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f0,f12,f1,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f1.f64, ctx.f0.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f0,f11,f1,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f1.f64, ctx.f13.f64)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bctrl 
	ctx.lr = 0x822263FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lwz r4,132(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lfs f11,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// lwz r3,128(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// fsubs f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f6,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// fsubs f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// lfs f0,-9856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f12,f11,f31,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f31.f64, ctx.f12.f64)));
	// stfs f12,60(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// fmadds f13,f13,f31,f6
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f31.f64, ctx.f6.f64)));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r30,r11,24
	ctx.r30.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x8222c580
	ctx.lr = 0x82226450;
	sub_8222C580(ctx, base);
	// rlwinm r11,r3,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF00;
	// lwz r4,148(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | ctx.r30.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bl 0x8222c580
	ctx.lr = 0x8222646C;
	sub_8222C580(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r3,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF00;
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f10,168(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 168);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f8,136(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 136);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,140(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// lfs f9,164(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// or r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 | ctx.r30.u64;
	// lbz r7,93(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 93);
	// stb r9,93(r31)
	REX_STORE_U8(ctx.r31.u32 + 93, ctx.r9.u8);
	// lfs f0,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// lfs f13,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmadds f8,f7,f31,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f7.f64, ctx.f31.f64, ctx.f8.f64)));
	// fmadds f11,f11,f0,f9
	ctx.f11.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f9.f64)));
	// fsubs f9,f6,f8
	ctx.f9.f64 = double(float(ctx.f6.f64 - ctx.f8.f64));
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctid f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f7,f13,f0,f11
	ctx.f7.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f11.f64)));
	// fadds f1,f7,f12
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x822264E4;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x822264F4;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82225fa8
	ctx.lr = 0x82226508;
	sub_82225FA8(ctx, base);
	// fmr f1,f8
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f8.f64;
	// bl 0x82226050
	ctx.lr = 0x82226510;
	sub_82226050(ctx, base);
	// stb r7,93(r31)
	REX_STORE_U8(ctx.r31.u32 + 93, ctx.r7.u8);
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

DEFINE_REX_FUNC(sub_82239D90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82239D98;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af18
	ctx.lr = 0x82239DA0;
	__savefpr_24(ctx, base);
	// stwu r1,-1040(r1)
	ea = -1040 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,176(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 176);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f24,f1
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8223ab98
	if (ctx.cr0.eq) goto loc_8223AB98;
	// bl 0x824281d8
	ctx.lr = 0x82239DBC;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82239dec
	if (!ctx.cr0.eq) goto loc_82239DEC;
	// bl 0x82444358
	ctx.lr = 0x82239DC8;
	sub_82444358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82239dec
	if (ctx.cr0.eq) goto loc_82239DEC;
	// bl 0x824443c8
	ctx.lr = 0x82239DD4;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82239dec
	if (ctx.cr0.eq) goto loc_82239DEC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82430a10
	ctx.lr = 0x82239DE4;
	sub_82430A10(ctx, base);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,188(r31)
	REX_STORE_U64(ctx.r31.u32 + 188, ctx.r11.u64);
loc_82239DEC:
	// lbz r11,177(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 177);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8223a24c
	if (!ctx.cr0.eq) goto loc_8223A24C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r16,0
	ctx.r16.s64 = 0;
	// stb r11,177(r31)
	REX_STORE_U8(ctx.r31.u32 + 177, ctx.r11.u8);
	// addi r27,r31,236
	ctx.r27.s64 = ctx.r31.s64 + 236;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// mr r22,r16
	ctx.r22.u64 = ctx.r16.u64;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ab98
	if (ctx.cr0.eq) goto loc_8223AB98;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// lis r25,-32111
	ctx.r25.s64 = -2104426496;
	// lfs f30,-18420(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18420);
	ctx.f30.f64 = double(temp.f32);
	// lis r23,-32112
	ctx.r23.s64 = -2104492032;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// addi r24,r11,32720
	ctx.r24.s64 = ctx.r11.s64 + 32720;
	// addi r26,r10,23536
	ctx.r26.s64 = ctx.r10.s64 + 23536;
loc_82239E48:
	// lfs f2,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 204);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82239E58;
	sub_825A4A40(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,208(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 208);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x82239E6C;
	sub_825A4A40(ctx, base);
	// lbz r11,178(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 178);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82239f04
	if (!ctx.cr0.eq) goto loc_82239F04;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r11,-12816(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12816);
	// lwzx r10,r28,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8223a228
	if (!ctx.cr6.eq) goto loc_8223A228;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223a228
	if (ctx.cr6.eq) goto loc_8223A228;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f1,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f1,156(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// stfs f1,152(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r7,r1,496
	ctx.r7.s64 = ctx.r1.s64 + 496;
	// stfs f31,428(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,424(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stfs f31,420(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stfs f31,416(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,496(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,464(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// ld r10,288(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// b 0x8223a224
	goto loc_8223A224;
loc_82239F04:
	// lwz r30,-13032(r23)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r23.u32 + -13032);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82239fe0
	if (ctx.cr6.eq) goto loc_82239FE0;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aebd8
	ctx.lr = 0x82239F34;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82239fe0
	if (ctx.cr0.eq) goto loc_82239FE0;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r11,-12816(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12816);
	// lwzx r10,r28,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8223a228
	if (!ctx.cr6.eq) goto loc_8223A228;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223a228
	if (ctx.cr6.eq) goto loc_8223A228;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// stfs f31,484(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// stfs f31,488(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// stfs f31,492(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f31,480(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// addi r7,r1,400
	ctx.r7.s64 = ctx.r1.s64 + 400;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// b 0x8223a224
	goto loc_8223A224;
loc_82239FE0:
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// ld r11,3456(r25)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r25.u32 + 3456);
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// stw r16,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r16.u32);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// stw r16,516(r1)
	REX_STORE_U32(ctx.r1.u32 + 516, ctx.r16.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// vslw128 v62,v62,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stw r16,544(r1)
	REX_STORE_U32(ctx.r1.u32 + 544, ctx.r16.u32);
	// std r11,520(r1)
	REX_STORE_U64(ctx.r1.u32 + 520, ctx.r11.u64);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223a050
	if (ctx.cr6.eq) goto loc_8223A050;
	// fctiwz f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// fctiwz f13,f1
	ctx.f13.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fadds f0,f1,f30
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r7,100(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823af5b0
	ctx.lr = 0x8223A050;
	sub_823AF5B0(ctx, base);
loc_8223A050:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223a19c
	if (ctx.cr0.eq) goto loc_8223A19C;
	// lfs f6,524(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 524);
	ctx.f6.f64 = double(temp.f32);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// lfs f5,520(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 520);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8223a090
	if (ctx.cr6.eq) goto loc_8223A090;
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// fctiwz f0,f5
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aebd8
	ctx.lr = 0x8223A090;
	sub_823AEBD8(ctx, base);
loc_8223A090:
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r11,-12816(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12816);
	// lwzx r10,r28,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8223a228
	if (!ctx.cr6.eq) goto loc_8223A228;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223a228
	if (ctx.cr6.eq) goto loc_8223A228;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f5,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,336
	ctx.r7.s64 = ctx.r1.s64 + 336;
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f6,232(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f6,224(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// stfs f6,228(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// stfs f6,236(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f5,180(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f5,176(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f5,188(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f0,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
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
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
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
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,352(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// b 0x8223a224
	goto loc_8223A224;
loc_8223A19C:
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r11,-12816(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12816);
	// lwzx r10,r28,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8223a228
	if (!ctx.cr6.eq) goto loc_8223A228;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223a228
	if (ctx.cr6.eq) goto loc_8223A228;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stfs f1,312(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f1,304(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stfs f31,284(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r8,r1,448
	ctx.r8.s64 = ctx.r1.s64 + 448;
	// stfs f31,276(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// stfs f1,308(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f1,316(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f31,280(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f31,272(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
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
	// lfs f0,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ld r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
loc_8223A224:
	// std r10,80(r11)
	REX_STORE_U64(ctx.r11.u32 + 80, ctx.r10.u64);
loc_8223A228:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82239e48
	if (ctx.cr6.lt) goto loc_82239E48;
	// b 0x8223ab98
	goto loc_8223AB98;
loc_8223A24C:
	// lbz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 224);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8223ab98
	if (!ctx.cr0.eq) goto loc_8223AB98;
	// li r16,0
	ctx.r16.s64 = 0;
	// mr r15,r16
	ctx.r15.u64 = ctx.r16.u64;
	// stw r16,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r16.u32);
	// stw r16,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r16.u32);
	// mr r18,r16
	ctx.r18.u64 = ctx.r16.u64;
	// mr r22,r16
	ctx.r22.u64 = ctx.r16.u64;
	// stw r16,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r16.u32);
	// mr r14,r16
	ctx.r14.u64 = ctx.r16.u64;
	// bl 0x824281d8
	ctx.lr = 0x8223A27C;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223a32c
	if (ctx.cr0.eq) goto loc_8223A32C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,-12952(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8223a2c4
	if (ctx.cr6.eq) goto loc_8223A2C4;
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mr r9,r16
	ctx.r9.u64 = ctx.r16.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8223A2A4:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223a2b4
	if (ctx.cr6.eq) goto loc_8223A2B4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_8223A2B4:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8223a2a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8223A2A4;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// b 0x8223a2c8
	goto loc_8223A2C8;
loc_8223A2C4:
	// mr r27,r16
	ctx.r27.u64 = ctx.r16.u64;
loc_8223A2C8:
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8223a354
	if (ctx.cr6.eq) goto loc_8223A354;
	// addi r29,r31,204
	ctx.r29.s64 = ctx.r31.s64 + 204;
	// addi r28,r31,196
	ctx.r28.s64 = ctx.r31.s64 + 196;
loc_8223A2DC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8242a650
	ctx.lr = 0x8223A2E4;
	sub_8242A650(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// bl 0x82429a18
	ctx.lr = 0x8223A2EC;
	sub_82429A18(ctx, base);
	// clrlwi r4,r26,24
	ctx.r4.u64 = ctx.r26.u32 & 0xFF;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82429668
	ctx.lr = 0x8223A2F8;
	sub_82429668(ctx, base);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8223fba8
	ctx.lr = 0x8223A308;
	sub_8223FBA8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223a31c
	if (ctx.cr0.eq) goto loc_8223A31C;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8223ac78
	ctx.lr = 0x8223A31C;
	sub_8223AC78(ctx, base);
loc_8223A31C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8223a2dc
	if (ctx.cr6.lt) goto loc_8223A2DC;
	// b 0x8223a350
	goto loc_8223A350;
loc_8223A32C:
	// addi r5,r31,188
	ctx.r5.s64 = ctx.r31.s64 + 188;
	// addi r4,r31,204
	ctx.r4.s64 = ctx.r31.s64 + 204;
	// addi r3,r31,196
	ctx.r3.s64 = ctx.r31.s64 + 196;
	// bl 0x8223fba8
	ctx.lr = 0x8223A33C;
	sub_8223FBA8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223a354
	if (ctx.cr0.eq) goto loc_8223A354;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8223ac78
	ctx.lr = 0x8223A350;
	sub_8223AC78(ctx, base);
loc_8223A350:
	// lwz r15,148(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
loc_8223A354:
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// addi r19,r31,236
	ctx.r19.s64 = ctx.r31.s64 + 236;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// mr r23,r16
	ctx.r23.u64 = ctx.r16.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ab6c
	if (ctx.cr0.eq) goto loc_8223AB6C;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// addi r8,r10,-27352
	ctx.r8.s64 = ctx.r10.s64 + -27352;
	// lis r7,-32241
	ctx.r7.s64 = -2112946176;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// lfs f26,-27352(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27352);
	ctx.f26.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f30,-6412(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6412);
	ctx.f30.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f29,-4864(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4864);
	ctx.f29.f64 = double(temp.f32);
	// lfs f27,-11572(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -11572);
	ctx.f27.f64 = double(temp.f32);
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// lfs f25,20068(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 20068);
	ctx.f25.f64 = double(temp.f32);
	// li r27,1
	ctx.r27.s64 = 1;
	// lfs f28,12468(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12468);
	ctx.f28.f64 = double(temp.f32);
	// lis r24,-32111
	ctx.r24.s64 = -2104426496;
	// lis r17,-32112
	ctx.r17.s64 = -2104492032;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// addi r21,r11,32256
	ctx.r21.s64 = ctx.r11.s64 + 32256;
	// addi r20,r10,32720
	ctx.r20.s64 = ctx.r10.s64 + 32720;
	// addi r25,r9,23536
	ctx.r25.s64 = ctx.r9.s64 + 23536;
loc_8223A3C8:
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r10,-12816(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + -12816);
	// lwzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r8,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8223ab4c
	if (!ctx.cr6.eq) goto loc_8223AB4C;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8223ab4c
	if (ctx.cr6.eq) goto loc_8223AB4C;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8223aa9c
	if (!ctx.cr0.eq) goto loc_8223AA9C;
	// lbz r10,466(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 466);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8223ab4c
	if (ctx.cr0.eq) goto loc_8223AB4C;
	// stb r27,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r27.u8);
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r30,240(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// bl 0x825a4a40
	ctx.lr = 0x8223A42C;
	sub_825A4A40(ctx, base);
	// lwzx r11,r30,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// stfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,204(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 204);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8223A444;
	sub_825A4A40(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,208(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 208);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8223A458;
	sub_825A4A40(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// mr r29,r16
	ctx.r29.u64 = ctx.r16.u64;
	// subf r11,r15,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r15.u64;
	// srawi r30,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r30.s64 = ctx.r11.s32 >> 3;
loc_8223A468:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8223a5fc
	if (ctx.cr6.eq) goto loc_8223A5FC;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stfs f1,316(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f1,312(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// stfs f1,304(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r7,r1,800
	ctx.r7.s64 = ctx.r1.s64 + 800;
	// stfs f31,284(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r6,r1,576
	ctx.r6.s64 = ctx.r1.s64 + 576;
	// stfs f31,272(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f31,280(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// mr r11,r15
	ctx.r11.u64 = ctx.r15.u64;
	// stfs f31,276(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// stfs f1,308(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lvx128 v5,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,800(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
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
	// lfs f0,576(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 576);
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
loc_8223A4EC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r5,r1,752
	ctx.r5.s64 = ctx.r1.s64 + 752;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r4,r1,624
	ctx.r4.s64 = ctx.r1.s64 + 624;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r10,r1,720
	ctx.r10.s64 = ctx.r1.s64 + 720;
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,752(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 752);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,228(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f0,624(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v5
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)));
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
	// vnmsubfp v4,v12,v11,v5
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v13,v13,v4,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v13.f32)));
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
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfs f0,720(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 720);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bge cr6,0x8223a5f4
	if (!ctx.cr6.lt) goto loc_8223A5F4;
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
loc_8223A5F4:
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8223a4ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8223A4EC;
loc_8223A5FC:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x8223a638
	if (!ctx.cr0.eq) goto loc_8223A638;
	// cmplwi cr6,r29,8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 8, ctx.xer);
	// bgt cr6,0x8223a638
	if (ctx.cr6.gt) goto loc_8223A638;
	// lfs f2,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 204);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8223A620;
	sub_825A4A40(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,208(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 208);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x8223A634;
	sub_825A4A40(ctx, base);
	// b 0x8223a468
	goto loc_8223A468;
loc_8223A638:
	// lbz r11,178(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 178);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8223a69c
	if (!ctx.cr0.eq) goto loc_8223A69C;
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// stfs f31,396(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f31,388(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// addi r11,r1,560
	ctx.r11.s64 = ctx.r1.s64 + 560;
	// stfs f31,384(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r9,r1,656
	ctx.r9.s64 = ctx.r1.s64 + 656;
	// stfs f31,392(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r8,r1,784
	ctx.r8.s64 = ctx.r1.s64 + 784;
	// stfs f1,572(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f1,568(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f1,564(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// stfs f1,560(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
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
	// lfs f0,656(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 656);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,784(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 784);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// b 0x8223a938
	goto loc_8223A938;
loc_8223A69C:
	// lwz r30,-13032(r17)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r17.u32 + -13032);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8223a750
	if (ctx.cr6.eq) goto loc_8223A750;
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// fctiwz f0,f31
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,108(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823aebd8
	ctx.lr = 0x8223A6CC;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8223a750
	if (ctx.cr0.eq) goto loc_8223A750;
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f31,460(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// stfs f31,456(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// std r11,480(r1)
	REX_STORE_U64(ctx.r1.u32 + 480, ctx.r11.u64);
	// stfs f31,452(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f31,448(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// addi r11,r1,688
	ctx.r11.s64 = ctx.r1.s64 + 688;
	// lwz r8,240(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// addi r7,r1,592
	ctx.r7.s64 = ctx.r1.s64 + 592;
	// lwzx r8,r8,r28
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r28.u32);
	// lfd f0,480(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 480);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lfs f0,688(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 688);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,592(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 592);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// ld r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r11,12(r8)
	REX_STORE_U64(ctx.r8.u32 + 12, ctx.r11.u64);
	// b 0x8223a944
	goto loc_8223A944;
loc_8223A750:
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// ld r11,3456(r24)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r24.u32 + 3456);
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// stw r16,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r16.u32);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// stw r16,516(r1)
	REX_STORE_U32(ctx.r1.u32 + 516, ctx.r16.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// vslw128 v62,v62,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stw r16,544(r1)
	REX_STORE_U32(ctx.r1.u32 + 544, ctx.r16.u32);
	// std r11,520(r1)
	REX_STORE_U64(ctx.r1.u32 + 520, ctx.r11.u64);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223a7c0
	if (ctx.cr6.eq) goto loc_8223A7C0;
	// fctiwz f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f13,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// fctiwz f13,f31
	ctx.f13.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// fadds f0,f1,f26
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f26.f64));
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lwz r7,92(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823af5b0
	ctx.lr = 0x8223A7C0;
	sub_823AF5B0(ctx, base);
loc_8223A7C0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223a8e4
	if (ctx.cr0.eq) goto loc_8223A8E4;
	// lfs f6,524(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 524);
	ctx.f6.f64 = double(temp.f32);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// lfs f5,520(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 520);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8223a800
	if (ctx.cr6.eq) goto loc_8223A800;
	// fctiwz f0,f5
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,108(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823aebd8
	ctx.lr = 0x8223A800;
	sub_823AEBD8(ctx, base);
loc_8223A800:
	// addi r10,r1,608
	ctx.r10.s64 = ctx.r1.s64 + 608;
	// lvx128 v63,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f6,352(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f6,356(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// std r11,416(r1)
	REX_STORE_U64(ctx.r1.u32 + 416, ctx.r11.u64);
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// addi r6,r1,336
	ctx.r6.s64 = ctx.r1.s64 + 336;
	// stfs f5,348(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,640
	ctx.r7.s64 = ctx.r1.s64 + 640;
	// stfs f5,344(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// stfs f5,340(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// addi r4,r1,672
	ctx.r4.s64 = ctx.r1.s64 + 672;
	// stfs f5,336(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// stfs f6,364(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// lwz r5,240(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stfs f6,360(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// lwzx r5,r5,r28
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r28.u32);
	// lfd f0,416(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 416);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,608(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 608);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stfs f0,376(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,412(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f0,400(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,640(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 640);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,440(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f0,436(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// stfs f0,432(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// stfs f0,444(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,672(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,704(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 704);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,12(r5)
	REX_STORE_U64(ctx.r5.u32 + 12, ctx.r11.u64);
	// b 0x8223a944
	goto loc_8223A944;
loc_8223A8E4:
	// addi r10,r1,464
	ctx.r10.s64 = ctx.r1.s64 + 464;
	// stfs f1,476(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stfs f1,472(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// addi r9,r1,736
	ctx.r9.s64 = ctx.r1.s64 + 736;
	// stfs f1,468(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// addi r11,r1,496
	ctx.r11.s64 = ctx.r1.s64 + 496;
	// stfs f1,464(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// addi r8,r1,768
	ctx.r8.s64 = ctx.r1.s64 + 768;
	// stfs f31,508(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// stfs f31,504(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f31,500(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f31,496(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
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
	// lfs f0,736(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 736);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,768(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_8223A938:
	// lwz r7,240(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwzx r7,r7,r28
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r28.u32);
	// std r11,12(r7)
	REX_STORE_U64(ctx.r7.u32 + 12, ctx.r11.u64);
loc_8223A944:
	// bl 0x824281d8
	ctx.lr = 0x8223A948;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ab4c
	if (ctx.cr0.eq) goto loc_8223AB4C;
	// bl 0x8242a5e0
	ctx.lr = 0x8223A954;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223a964
	if (!ctx.cr0.eq) goto loc_8223A964;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// b 0x8223a968
	goto loc_8223A968;
loc_8223A964:
	// bl 0x8242aa28
	ctx.lr = 0x8223A968;
	sub_8242AA28(ctx, base);
loc_8223A968:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ab4c
	if (ctx.cr0.eq) goto loc_8223AB4C;
	// clrlwi. r11,r14,24
	ctx.r11.u64 = ctx.r14.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223aa0c
	if (!ctx.cr0.eq) goto loc_8223AA0C;
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,212(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// sth r8,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r8.u16);
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// lbz r7,1(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// stb r9,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// stb r8,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r8.u8);
	// stb r7,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r7.u8);
	// bl 0x82429a18
	ctx.lr = 0x8223A9C0;
	sub_82429A18(ctx, base);
	// fmuls f0,f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f25.f64));
	// clrlwi r11,r18,16
	ctx.r11.u64 = ctx.r18.u32 & 0xFFFF;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// mr r14,r27
	ctx.r14.u64 = ctx.r27.u64;
	// clrlwi r18,r11,16
	ctx.r18.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r22,r30,4
	ctx.r22.s64 = ctx.r30.s64 + 4;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// lbz r9,1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r8,2(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r10,3(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// stb r9,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r9.u8);
	// stb r8,2(r30)
	REX_STORE_U8(ctx.r30.u32 + 2, ctx.r8.u8);
	// stb r10,3(r30)
	REX_STORE_U8(ctx.r30.u32 + 3, ctx.r10.u8);
loc_8223AA0C:
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stb r23,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r23.u8);
	// lwzx r6,r11,r28
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// addi r4,r6,12
	ctx.r4.s64 = ctx.r6.s64 + 12;
	// bl 0x82428150
	ctx.lr = 0x8223AA24;
	sub_82428150(ctx, base);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// clrlwi r11,r18,16
	ctx.r11.u64 = ctx.r18.u32 & 0xFFFF;
	// lbz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r11,9
	ctx.r7.s64 = ctx.r11.s64 + 9;
	// addi r11,r22,1
	ctx.r11.s64 = ctx.r22.s64 + 1;
	// lbz r4,1(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// clrlwi r18,r7,16
	ctx.r18.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stb r10,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r10.u8);
	// lbz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r6,2(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r9,3(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// stb r10,1(r22)
	REX_STORE_U8(ctx.r22.u32 + 1, ctx.r10.u8);
	// lbz r10,2(r8)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// lbz r8,3(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// stb r7,2(r22)
	REX_STORE_U8(ctx.r22.u32 + 2, ctx.r7.u8);
	// stb r6,3(r22)
	REX_STORE_U8(ctx.r22.u32 + 3, ctx.r6.u8);
	// stb r9,4(r22)
	REX_STORE_U8(ctx.r22.u32 + 4, ctx.r9.u8);
	// addi r22,r11,4
	ctx.r22.s64 = ctx.r11.s64 + 4;
	// stb r5,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// stb r4,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r4.u8);
	// stb r10,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r10.u8);
	// stb r8,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r8.u8);
	// b 0x8223ab4c
	goto loc_8223AB4C;
loc_8223AA9C:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f24
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f24.f64));
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lwz r9,240(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwzx r11,r9,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8223ab4c
	if (!ctx.cr6.lt) goto loc_8223AB4C;
	// lwz r10,216(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8223aaf4
	if (ctx.cr6.eq) goto loc_8223AAF4;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8223ab4c
	if (!ctx.cr6.lt) goto loc_8223AB4C;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8223aaf4
	if (ctx.cr6.eq) goto loc_8223AAF4;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8223aaf4
	if (!ctx.cr6.gt) goto loc_8223AAF4;
	// stb r27,224(r31)
	REX_STORE_U8(ctx.r31.u32 + 224, ctx.r27.u8);
loc_8223AAF4:
	// lwzx r11,r9,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lfs f0,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// stw r8,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r8.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stfs f0,152(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// stfs f28,576(r3)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r3.u32 + 576, temp.u32);
	// stb r16,465(r3)
	REX_STORE_U8(ctx.r3.u32 + 465, ctx.r16.u8);
	// stfs f28,564(r3)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r3.u32 + 564, temp.u32);
	// stb r16,466(r3)
	REX_STORE_U8(ctx.r3.u32 + 466, ctx.r16.u8);
	// stw r9,452(r3)
	REX_STORE_U32(ctx.r3.u32 + 452, ctx.r9.u32);
	// stb r16,554(r3)
	REX_STORE_U8(ctx.r3.u32 + 554, ctx.r16.u8);
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stb r16,580(r3)
	REX_STORE_U8(ctx.r3.u32 + 580, ctx.r16.u8);
	// bctrl 
	ctx.lr = 0x8223AB40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// lwzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// stb r16,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r16.u8);
loc_8223AB4C:
	// lwz r11,8(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// lwz r10,4(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 4);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8223a3c8
	if (ctx.cr6.lt) goto loc_8223A3C8;
loc_8223AB6C:
	// clrlwi. r11,r18,16
	ctx.r11.u64 = ctx.r18.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223ab88
	if (ctx.cr0.eq) goto loc_8223AB88;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r4,172(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82429ff8
	ctx.lr = 0x8223AB88;
	sub_82429FF8(ctx, base);
loc_8223AB88:
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8223ab98
	if (ctx.cr6.eq) goto loc_8223AB98;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x825e0378
	ctx.lr = 0x8223AB98;
	sub_825E0378(ctx, base);
loc_8223AB98:
	// addi r1,r1,1040
	ctx.r1.s64 = ctx.r1.s64 + 1040;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af64
	ctx.lr = 0x8223ABA4;
	__restfpr_24(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D3130) {
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
	// bl 0x82230a18
	ctx.lr = 0x822D3148;
	sub_82230A18(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232b18
	ctx.lr = 0x822D3154;
	sub_82232B18(ctx, base);
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

DEFINE_REX_FUNC(sub_822D3BD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822D3BE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r10,r10,11948
	ctx.r10.s64 = ctx.r10.s64 + 11948;
	// addi r11,r11,-3100
	ctx.r11.s64 = ctx.r11.s64 + -3100;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// lfs f0,-13508(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -13508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f0,5144(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5144);
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
	// ble cr6,0x822d3c2c
	if (!ctx.cr6.gt) goto loc_822D3C2C;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822D3C2C:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822d3ed0
	if (ctx.cr6.lt) goto loc_822D3ED0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d48c0
	ctx.lr = 0x822D3C44;
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq 0x822d3cf8
	if (ctx.cr0.eq) goto loc_822D3CF8;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// bl 0x8222ff78
	ctx.lr = 0x822D3C68;
	sub_8222FF78(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x822d4858
	ctx.lr = 0x822D3C70;
	sub_822D4858(ctx, base);
	// clrlwi. r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x822d3cb4
	if (ctx.cr0.eq) goto loc_822D3CB4;
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
	ctx.lr = 0x822D3C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822d3cb4
	if (!ctx.cr0.eq) goto loc_822D3CB4;
loc_822D3C98:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d3ed0
	if (!ctx.cr6.eq) goto loc_822D3ED0;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x822d3ecc
	goto loc_822D3ECC;
loc_822D3CB4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x822d3cdc
	if (!ctx.cr6.eq) goto loc_822D3CDC;
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
	ctx.lr = 0x822D3CD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x822d3c98
	if (ctx.cr6.eq) goto loc_822D3C98;
loc_822D3CDC:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d3ed0
	if (!ctx.cr6.eq) goto loc_822D3ED0;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822d3ecc
	goto loc_822D3ECC;
loc_822D3CF8:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3136
	ctx.r29.s64 = ctx.r29.s64 + -3136;
	// bl 0x8222ff78
	ctx.lr = 0x822D3D04;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822d6708
	ctx.lr = 0x822D3D0C;
	sub_822D6708(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62432
	ctx.r11.u64 = ctx.r11.u64 | 62432;
	// lfsx f0,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x822d3e14
	if (!ctx.cr6.gt) goto loc_822D3E14;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x822D3D34;
	sub_8222FF78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822d4858
	ctx.lr = 0x822D3D3C;
	sub_822D4858(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r8,r9,62376
	ctx.r8.u64 = ctx.r9.u64 | 62376;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r9,r6,62416
	ctx.r9.u64 = ctx.r6.u64 | 62416;
	// beq 0x822d3db4
	if (ctx.cr0.eq) goto loc_822D3DB4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x822d3d98
	if (ctx.cr6.gt) goto loc_822D3D98;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D3D98:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d3db4
	if (ctx.cr0.eq) goto loc_822D3DB4;
	// lwzx r6,r31,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// add r11,r31,r8
	ctx.r11.u64 = ctx.r31.u64 + ctx.r8.u64;
	// cmpwi cr6,r6,-1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, -1, ctx.xer);
	// bne cr6,0x822d3db4
	if (!ctx.cr6.eq) goto loc_822D3DB4;
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_822D3DB4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822d3ed0
	if (!ctx.cr6.eq) goto loc_822D3ED0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r31,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822d3df4
	if (ctx.cr6.lt) goto loc_822D3DF4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D3DF4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d3ed0
	if (ctx.cr0.eq) goto loc_822D3ED0;
	// lwzx r10,r31,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// add r11,r31,r8
	ctx.r11.u64 = ctx.r31.u64 + ctx.r8.u64;
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d3ed0
	if (!ctx.cr6.eq) goto loc_822D3ED0;
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// b 0x822d3ed0
	goto loc_822D3ED0;
loc_822D3E14:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x822d3ed0
	if (!ctx.cr6.lt) goto loc_822D3ED0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// ori r11,r10,62384
	ctx.r11.u64 = ctx.r10.u64 | 62384;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822d3e5c
	if (!ctx.cr0.eq) goto loc_822D3E5C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62464
	ctx.r11.u64 = ctx.r11.u64 | 62464;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822d3ed0
	if (ctx.cr0.eq) goto loc_822D3ED0;
loc_822D3E5C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,-3128
	ctx.r30.s64 = ctx.r30.s64 + -3128;
	// bl 0x8222ff78
	ctx.lr = 0x822D3E78;
	sub_8222FF78(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x822d4858
	ctx.lr = 0x822D3E80;
	sub_822D4858(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822D3E9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d3ed0
	if (!ctx.cr6.eq) goto loc_822D3ED0;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bne 0x822d3ec8
	if (!ctx.cr0.eq) goto loc_822D3EC8;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
loc_822D3EC8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_822D3ECC:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822D3ED0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822EEFC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822EEFC8;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r26,r26,-2880
	ctx.r26.s64 = ctx.r26.s64 + -2880;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822ef24c
	if (ctx.cr6.eq) goto loc_822EF24C;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// ori r9,r9,62380
	ctx.r9.u64 = ctx.r9.u64 | 62380;
	// addi r27,r11,15088
	ctx.r27.s64 = ctx.r11.s64 + 15088;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwzx r11,r3,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x822ef150
	if (!ctx.cr6.eq) goto loc_822EF150;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62388
	ctx.r11.u64 = ctx.r11.u64 | 62388;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ef150
	if (ctx.cr6.eq) goto loc_822EF150;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-2884
	ctx.r11.s64 = ctx.r11.s64 + -2884;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x822ef150
	if (ctx.cr0.eq) goto loc_822EF150;
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,40(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// ori r9,r9,62452
	ctx.r9.u64 = ctx.r9.u64 | 62452;
	// lfs f13,-828(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -828);
	ctx.f13.f64 = double(temp.f32);
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfsx f0,r3,r9
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f30,r3,r11
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	ctx.f30.f64 = double(temp.f32);
	// bne cr6,0x822ef06c
	if (!ctx.cr6.eq) goto loc_822EF06C;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// fsubs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x822ef074
	goto loc_822EF074;
loc_822EF06C:
	// li r28,2
	ctx.r28.s64 = 2;
	// fadds f31,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_822EF074:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,300
	ctx.r4.s64 = 300;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x822EF08C;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x822ef0e0
	if (ctx.cr0.eq) goto loc_822EF0E0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824689b0
	ctx.lr = 0x822EF0A8;
	sub_824689B0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,-2620(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2620);
	ctx.f0.f64 = double(temp.f32);
	// stw r28,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r28.u32);
	// addi r10,r11,-20016
	ctx.r10.s64 = ctx.r11.s64 + -20016;
	// stfs f0,288(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stw r29,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r29.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r29,296(r31)
	REX_STORE_U8(ctx.r31.u32 + 296, ctx.r29.u8);
	// stb r29,297(r31)
	REX_STORE_U8(ctx.r31.u32 + 297, ctx.r29.u8);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// stw r10,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// b 0x822ef0e4
	goto loc_822EF0E4;
loc_822EF0E0:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_822EF0E4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ef150
	if (ctx.cr6.eq) goto loc_822EF150;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 | 1;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,44(r11)
	REX_STORE_U64(ctx.r11.u32 + 44, ctx.r10.u64);
loc_822EF150:
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-2883
	ctx.r11.s64 = ctx.r11.s64 + -2883;
	// ori r31,r10,62556
	ctx.r31.u64 = ctx.r10.u64 | 62556;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822ef214
	if (ctx.cr0.eq) goto loc_822EF214;
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lfs f13,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// ori r11,r11,62560
	ctx.r11.u64 = ctx.r11.u64 | 62560;
	// lwz r10,40(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfsx f0,r30,r31
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f12,r30,r11
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// bne cr6,0x822ef1a0
	if (!ctx.cr6.eq) goto loc_822EF1A0;
	// li r7,1
	ctx.r7.s64 = 1;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x822ef1a8
	goto loc_822EF1A8;
loc_822EF1A0:
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_822EF1A8:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r4,51
	ctx.r4.s64 = 51;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
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
	// bl 0x824b5440
	ctx.lr = 0x822EF214;
	sub_824B5440(ctx, base);
loc_822EF214:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62328
	ctx.r11.u64 = ctx.r11.u64 | 62328;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822ef244
	if (ctx.cr0.eq) goto loc_822EF244;
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lwzx r10,r30,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// addis r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 65536;
	// addi r9,r9,-3204
	ctx.r9.s64 = ctx.r9.s64 + -3204;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_822EF244:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822ef260
	ctx.lr = 0x822EF24C;
	sub_822EF260(ctx, base);
loc_822EF24C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82301CE8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,16383
	ctx.r11.s64 = 1073676288;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82301d60
	if (!ctx.cr6.lt) goto loc_82301D60;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x82301D2C;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x82301D38;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x82301D3C;
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
	ctx.lr = 0x82301D50;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82301D60;
	sub_8235EC48(ctx, base);
loc_82301D60:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_823050A8) {
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
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f30,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// lbz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8230512c
	if (ctx.cr0.eq) goto loc_8230512C;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82305108;
	sub_8224A2A0(ctx, base);
	// stfs f30,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305124;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
loc_8230512C:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,-3096
	ctx.r10.s64 = ctx.r10.s64 + -3096;
	// addi r11,r11,-30132
	ctx.r11.s64 = ctx.r11.s64 + -30132;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f13,4760(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4760);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8230516c
	if (ctx.cr6.lt) goto loc_8230516C;
	// lfs f13,4764(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4764);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82305180
	if (ctx.cr6.lt) goto loc_82305180;
	// lfs f13,4768(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4768);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305174
	if (!ctx.cr6.lt) goto loc_82305174;
loc_8230516C:
	// stfs f30,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// b 0x823051d4
	goto loc_823051D4;
loc_82305174:
	// lfs f13,4772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4772);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8230519c
	if (!ctx.cr6.lt) goto loc_8230519C;
loc_82305180:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r10,62448
	ctx.r11.u64 = ctx.r10.u64 | 62448;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// b 0x823051d4
	goto loc_823051D4;
loc_8230519C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stfs f30,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
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
	// beq cr6,0x823051d4
	if (ctx.cr6.eq) goto loc_823051D4;
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// stfs f30,0(r10)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r9,19392
	ctx.r9.s64 = ctx.r9.s64 + 19392;
	// stb r10,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r10.u8);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_823051D4:
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

DEFINE_REX_FUNC(sub_8230B568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8230B570;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r29,r29,-3020
	ctx.r29.s64 = ctx.r29.s64 + -3020;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r26,r9,62520
	ctx.r26.u64 = ctx.r9.u64 | 62520;
	// ori r27,r8,62524
	ctx.r27.u64 = ctx.r8.u64 | 62524;
	// addi r25,r11,-32216
	ctx.r25.s64 = ctx.r11.s64 + -32216;
	// addi r28,r10,-5872
	ctx.r28.s64 = ctx.r10.s64 + -5872;
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8230b6b8
	if (ctx.cr0.eq) goto loc_8230B6B8;
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
	// stw r30,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r30.u32);
	// stw r30,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r30.u32);
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
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
	// lfsx f1,r3,r8
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8230B624;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,-3136(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -3136);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62412
	ctx.r11.u64 = ctx.r11.u64 | 62412;
	// ori r10,r10,62440
	ctx.r10.u64 = ctx.r10.u64 | 62440;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r9,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u8);
	// bl 0x8230cf60
	ctx.lr = 0x8230B654;
	sub_8230CF60(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,62517
	ctx.r11.u64 = ctx.r11.u64 | 62517;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// bl 0x8234d920
	ctx.lr = 0x8230B66C;
	sub_8234D920(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f1,30616(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 30616);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r24,r11,-4080
	ctx.r24.s64 = ctx.r11.s64 + -4080;
	// lfs f2,984(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 984);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8230B684;
	sub_825A4A40(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,964(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 964);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x8230B698;
	sub_825A4A40(ctx, base);
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
	// stfsx f1,r31,r27
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r26
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r26.u32, temp.u32);
	// stb r30,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r30.u8);
loc_8230B6B8:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r29,r29,-3140
	ctx.r29.s64 = ctx.r29.s64 + -3140;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// bl 0x8230cf60
	ctx.lr = 0x8230B6DC;
	sub_8230CF60(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234d920
	ctx.lr = 0x8230B6E8;
	sub_8234D920(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,2088(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 2088);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r31,r27
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
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
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r31,r26
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r26.u32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// bl 0x8230ab98
	ctx.lr = 0x8230B794;
	sub_8230AB98(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62416
	ctx.r11.u64 = ctx.r11.u64 | 62416;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8230b810
	if (!ctx.cr6.gt) goto loc_8230B810;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r5,r11,-588
	ctx.r5.s64 = ctx.r11.s64 + -588;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8255f918
	ctx.lr = 0x8230B7C0;
	sub_8255F918(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8230d580
	ctx.lr = 0x8230B7D0;
	sub_8230D580(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x82222370
	ctx.lr = 0x8230B7E4;
	sub_82222370(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4312(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4312);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8230b800
	if (!ctx.cr6.lt) goto loc_8230B800;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8230B800:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230b810
	if (ctx.cr0.eq) goto loc_8230B810;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8230cd50
	ctx.lr = 0x8230B810;
	sub_8230CD50(ctx, base);
loc_8230B810:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8230ce20
	ctx.lr = 0x8230B818;
	sub_8230CE20(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82324840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82324848;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3164
	ctx.r30.s64 = ctx.r30.s64 + -3164;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82324e4c
	if (ctx.cr6.eq) goto loc_82324E4C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82324c0c
	if (ctx.cr6.eq) goto loc_82324C0C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x82324ef0
	if (!ctx.cr6.eq) goto loc_82324EF0;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// addi r26,r26,-3096
	ctx.r26.s64 = ctx.r26.s64 + -3096;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82324a1c
	if (ctx.cr6.eq) goto loc_82324A1C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82324900
	if (ctx.cr6.eq) goto loc_82324900;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82324ef0
	if (!ctx.cr6.eq) goto loc_82324EF0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// ori r11,r11,62476
	ctx.r11.u64 = ctx.r11.u64 | 62476;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823248c0
	if (ctx.cr6.eq) goto loc_823248C0;
	// stb r28,292(r11)
	REX_STORE_U8(ctx.r11.u32 + 292, ctx.r28.u8);
loc_823248C0:
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
	ctx.lr = 0x823248E4;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
	// ori r11,r11,62452
	ctx.r11.u64 = ctx.r11.u64 | 62452;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x82324ef0
	goto loc_82324EF0;
loc_82324900:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,17092
	ctx.r11.s64 = ctx.r11.s64 + 17092;
	// ori r10,r10,62456
	ctx.r10.u64 = ctx.r10.u64 | 62456;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lfs f0,-18652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18652);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r9,-31120
	ctx.r9.s64 = ctx.r9.s64 + -31120;
	// lfsx f13,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82324964;
	sub_8222FF78(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ori r6,r6,62476
	ctx.r6.u64 = ctx.r6.u64 | 62476;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r31,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// beq cr6,0x82324ef0
	if (ctx.cr6.eq) goto loc_82324EF0;
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,44(r11)
	REX_STORE_U64(ctx.r11.u32 + 44, ctx.r10.u64);
	// b 0x82324ef0
	goto loc_82324EF0;
loc_82324A1C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r29,r11,17092
	ctx.r29.s64 = ctx.r11.s64 + 17092;
	// addi r27,r27,-3084
	ctx.r27.s64 = ctx.r27.s64 + -3084;
	// lfs f0,3252(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82324bfc
	if (!ctx.cr6.gt) goto loc_82324BFC;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// li r28,2
	ctx.r28.s64 = 2;
	// addi r30,r30,-3060
	ctx.r30.s64 = ctx.r30.s64 + -3060;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82324bf8
	if (ctx.cr6.eq) goto loc_82324BF8;
	// lis r25,-32115
	ctx.r25.s64 = -2104688640;
	// lfs f1,27332(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 27332);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x82324A60;
	sub_82738BE0(ctx, base);
	// lfs f0,27332(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 27332);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x82324A80;
	sub_82738CC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,-18652(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -18652);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// addi r25,r1,112
	ctx.r25.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,192
	ctx.r24.s64 = ctx.r1.s64 + 192;
	// lfsx f12,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-31120
	ctx.r11.s64 = ctx.r11.s64 + -31120;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82324B24;
	sub_8222FF78(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
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
	// lfs f11,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,44(r8)
	REX_STORE_U64(ctx.r8.u32 + 44, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x82324BD8;
	sub_8231E0D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// std r10,296(r11)
	REX_STORE_U64(ctx.r11.u32 + 296, ctx.r10.u64);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r28,324(r11)
	REX_STORE_U32(ctx.r11.u32 + 324, ctx.r28.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stb r9,292(r11)
	REX_STORE_U8(ctx.r11.u32 + 292, ctx.r9.u8);
loc_82324BF8:
	// stw r28,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
loc_82324BFC:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// b 0x82324ef0
	goto loc_82324EF0;
loc_82324C0C:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-3063
	ctx.r10.s64 = ctx.r10.s64 + -3063;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82324ef0
	if (ctx.cr0.eq) goto loc_82324EF0;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stb r28,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r28.u8);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r29,r11,17092
	ctx.r29.s64 = ctx.r11.s64 + 17092;
	// addi r30,r10,-28808
	ctx.r30.s64 = ctx.r10.s64 + -28808;
	// lfs f31,17092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17092);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// lfs f1,-3408(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -3408);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82324C4C;
	sub_825A4A40(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// lfs f1,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82324C64;
	sub_825A4A40(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,360
	ctx.r4.s64 = 360;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82324C80;
	sub_825E02A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r27,r11,62456
	ctx.r27.u64 = ctx.r11.u64 | 62456;
	// beq 0x82324d04
	if (ctx.cr0.eq) goto loc_82324D04;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// fsubs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfsx f13,r31,r27
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x824d2250
	ctx.lr = 0x82324CFC;
	sub_824D2250(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82324d08
	goto loc_82324D08;
loc_82324D04:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_82324D08:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82324e34
	if (ctx.cr6.eq) goto loc_82324E34;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lfs f0,-18652(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -18652);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-32528
	ctx.r10.s64 = ctx.r10.s64 + -32528;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82324D64;
	sub_8222FF78(ctx, base);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ori r5,r5,62470
	ctx.r5.u64 = ctx.r5.u64 | 62470;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f13,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,44(r30)
	REX_STORE_U64(ctx.r30.u32 + 44, ctx.r11.u64);
	// lfs f0,168(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,196(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 196, temp.u32);
	// lbzx r11,r31,r5
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r5.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82324e34
	if (ctx.cr0.eq) goto loc_82324E34;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82324E34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82324E34:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-3076
	ctx.r10.s64 = ctx.r10.s64 + -3076;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// b 0x82324ef0
	goto loc_82324EF0;
loc_82324E4C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r30,r30,-3104
	ctx.r30.s64 = ctx.r30.s64 + -3104;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r29,r11,2880
	ctx.r29.s64 = ctx.r11.s64 + 2880;
	// stb r10,285(r31)
	REX_STORE_U8(ctx.r31.u32 + 285, ctx.r10.u8);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r4,356
	ctx.r4.s64 = 356;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82324E84;
	sub_825E02A0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x82324ee0
	if (ctx.cr0.eq) goto loc_82324EE0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f31,27328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27328);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x82324EA8;
	sub_8222FF78(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r11,r10,-28808
	ctx.r11.s64 = ctx.r10.s64 + -28808;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f2,-12104(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12104);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8247e4a0
	ctx.lr = 0x82324EDC;
	sub_8247E4A0(ctx, base);
	// b 0x82324ee4
	goto loc_82324EE4;
loc_82324EE0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82324EE4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62476
	ctx.r11.u64 = ctx.r11.u64 | 62476;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
loc_82324EF0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235EA48) {
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
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8235EA74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82615e10
	ctx.lr = 0x8235EA78;
	sub_82615E10(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8235ea88
	if (!ctx.cr0.eq) goto loc_8235EA88;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8235eac0
	goto loc_8235EAC0;
loc_8235EA88:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8235EA9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8235EAB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// extsb r11,r30
	ctx.r11.s64 = ctx.r30.s8;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8235EAC0:
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

DEFINE_REX_FUNC(sub_8235FC38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8235FC40;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r27,r11,22072
	ctx.r27.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,188
	ctx.r4.s64 = 188;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,44(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8235FC64;
	sub_825E02A0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8235fc80
	if (ctx.cr0.eq) goto loc_8235FC80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823bdc58
	ctx.lr = 0x8235FC78;
	sub_823BDC58(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8235fc84
	goto loc_8235FC84;
loc_8235FC80:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_8235FC84:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r29,88(r30)
	REX_STORE_U32(ctx.r30.u32 + 88, ctx.r29.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r29,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,86(r30)
	REX_STORE_U16(ctx.r30.u32 + 86, ctx.r11.u16);
	// addi r31,r28,48
	ctx.r31.s64 = ctx.r28.s64 + 48;
	// stb r9,28(r30)
	REX_STORE_U8(ctx.r30.u32 + 28, ctx.r9.u8);
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,100(r30)
	REX_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
	// stfs f0,108(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 108, temp.u32);
	// stfs f0,104(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 104, temp.u32);
	// lwz r11,76(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// lwz r10,72(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 72);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi. r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8235fce4
	if (!ctx.cr0.eq) goto loc_8235FCE4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8235fce4
	if (ctx.cr6.gt) goto loc_8235FCE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824b79f0
	ctx.lr = 0x8235FCE4;
	sub_824B79F0(ctx, base);
loc_8235FCE4:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r11,r9
	ctx.r28.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r28,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8235fd04
	if (ctx.cr6.gt) goto loc_8235FD04;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_8235FD04:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8235fd30
	if (!ctx.cr6.eq) goto loc_8235FD30;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 44);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825e02a0
	ctx.lr = 0x8235FD28;
	sub_825E02A0(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stwx r3,r29,r11
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, ctx.r3.u32);
loc_8235FD30:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r10,r28,2,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xC;
	// lwzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// add. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235fd48
	if (ctx.cr0.eq) goto loc_8235FD48;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8235FD48:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82366960) {
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
	// bl 0x823669b8
	ctx.lr = 0x82366980;
	sub_823669B8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82366998
	if (ctx.cr0.eq) goto loc_82366998;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82366998
	if (ctx.cr6.eq) goto loc_82366998;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82366998;
	sub_825E0378(ctx, base);
loc_82366998:
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

DEFINE_REX_FUNC(sub_823682C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823682C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x823682D4;
	sub_8235F428(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,20584
	ctx.r10.s64 = ctx.r11.s64 + 20584;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r30.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r30,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r30.u32);
	// stw r30,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r30.u32);
	// lis r9,-32201
	ctx.r9.s64 = -2110324736;
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// addi r10,r10,-27424
	ctx.r10.s64 = ctx.r10.s64 + -27424;
	// stw r11,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
	// addi r3,r31,296
	ctx.r3.s64 = ctx.r31.s64 + 296;
	// stb r29,248(r31)
	REX_STORE_U8(ctx.r31.u32 + 248, ctx.r29.u8);
	// addi r4,r9,-26488
	ctx.r4.s64 = ctx.r9.s64 + -26488;
	// stw r30,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r30,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// stw r30,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r30.u32);
	// stw r10,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r10.u32);
	// stw r11,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// stw r30,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r30.u32);
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// stb r30,292(r31)
	REX_STORE_U8(ctx.r31.u32 + 292, ctx.r30.u8);
	// stb r30,293(r31)
	REX_STORE_U8(ctx.r31.u32 + 293, ctx.r30.u8);
	// bl 0x82366838
	ctx.lr = 0x8236834C;
	sub_82366838(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r29,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r29.u32);
	// addi r11,r11,2688
	ctx.r11.s64 = ctx.r11.s64 + 2688;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// ld r9,3456(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// li r10,3
	ctx.r10.s64 = 3;
	// std r9,396(r31)
	REX_STORE_U64(ctx.r31.u32 + 396, ctx.r9.u64);
	// li r11,3
	ctx.r11.s64 = 3;
	// ld r9,3128(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 3128);
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// std r9,404(r31)
	REX_STORE_U64(ctx.r31.u32 + 404, ctx.r9.u64);
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// stw r10,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r10.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// ld r9,2880(r6)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r6.u32 + 2880);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r30,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r30.u32);
	// addi r11,r31,452
	ctx.r11.s64 = ctx.r31.s64 + 452;
	// stb r30,432(r31)
	REX_STORE_U8(ctx.r31.u32 + 432, ctx.r30.u8);
	// std r9,420(r31)
	REX_STORE_U64(ctx.r31.u32 + 420, ctx.r9.u64);
	// stfs f0,436(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 436, temp.u32);
	// stw r30,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r30.u32);
	// stw r10,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r10.u32);
	// stw r30,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r30.u32);
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
loc_823683C0:
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stw r30,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r30,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// stwu r30,20(r11)
	ea = 20 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x823683c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823683C0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236DBB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8236DBC0;
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
	ctx.lr = 0x8236DBE8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8236dc04
	if (ctx.cr0.eq) goto loc_8236DC04;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8236dc10
	ctx.lr = 0x8236DC00;
	sub_8236DC10(ctx, base);
	// b 0x8236dc08
	goto loc_8236DC08;
loc_8236DC04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8236DC08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236FB18) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8236fb50
	if (!ctx.cr6.eq) goto loc_8236FB50;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8236db00
	ctx.lr = 0x8236FB34;
	sub_8236DB00(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,12236
	ctx.r10.s64 = ctx.r11.s64 + 12236;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f2,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2044(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2044);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8236f680
	ctx.lr = 0x8236FB50;
	sub_8236F680(ctx, base);
loc_8236FB50:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82370688) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,21880
	ctx.r3.s64 = ctx.r11.s64 + 21880;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823706F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823706F8;
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
	// bl 0x8235f428
	ctx.lr = 0x82370708;
	sub_8235F428(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r8,r11,12236
	ctx.r8.s64 = ctx.r11.s64 + 12236;
	// addi r10,r10,21912
	ctx.r10.s64 = ctx.r10.s64 + 21912;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r7,7
	ctx.r7.s64 = 7;
	// stw r30,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r30.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stw r30,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r30.u32);
	// stw r30,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r30.u32);
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
	// lfs f31,232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// stw r30,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// lfs f12,-23056(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23056);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// li r8,11
	ctx.r8.s64 = 11;
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r30,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// addi r6,r6,2688
	ctx.r6.s64 = ctx.r6.s64 + 2688;
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r7.u32);
	// lfs f13,-24640(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24640);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stfs f31,284(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// std r11,272(r31)
	REX_STORE_U64(ctx.r31.u32 + 272, ctx.r11.u64);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stb r30,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r30.u8);
	// stfs f31,288(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stfs f31,292(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// addi r29,r31,10284
	ctx.r29.s64 = ctx.r31.s64 + 10284;
	// stfs f31,300(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r8,10248(r31)
	REX_STORE_U32(ctx.r31.u32 + 10248, ctx.r8.u32);
	// stw r4,10252(r31)
	REX_STORE_U32(ctx.r31.u32 + 10252, ctx.r4.u32);
	// stfs f13,1704(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 1704, temp.u32);
	// stfs f0,1708(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1708, temp.u32);
	// stw r30,10236(r31)
	REX_STORE_U32(ctx.r31.u32 + 10236, ctx.r30.u32);
	// stfs f12,1712(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 1712, temp.u32);
	// stw r30,10240(r31)
	REX_STORE_U32(ctx.r31.u32 + 10240, ctx.r30.u32);
	// stfs f31,1716(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1716, temp.u32);
	// stw r30,10244(r31)
	REX_STORE_U32(ctx.r31.u32 + 10244, ctx.r30.u32);
	// stfs f31,1720(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 1720, temp.u32);
	// stw r3,10260(r31)
	REX_STORE_U32(ctx.r31.u32 + 10260, ctx.r3.u32);
	// stw r6,10256(r31)
	REX_STORE_U32(ctx.r31.u32 + 10256, ctx.r6.u32);
	// addi r8,r11,22072
	ctx.r8.s64 = ctx.r11.s64 + 22072;
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// li r4,4
	ctx.r4.s64 = 4;
	// std r11,10264(r31)
	REX_STORE_U64(ctx.r31.u32 + 10264, ctx.r11.u64);
	// ld r11,3128(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3128);
	// std r11,10272(r31)
	REX_STORE_U64(ctx.r31.u32 + 10272, ctx.r11.u64);
	// stb r30,10280(r31)
	REX_STORE_U8(ctx.r31.u32 + 10280, ctx.r30.u8);
	// lwz r3,44(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82370808;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82370818
	if (ctx.cr0.eq) goto loc_82370818;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8237081c
	goto loc_8237081C;
loc_82370818:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8237081C:
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stw r30,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r30,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
	// stw r30,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r30.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f31,10324(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 10324, temp.u32);
	// stb r30,10328(r31)
	REX_STORE_U8(ctx.r31.u32 + 10328, ctx.r30.u8);
	// stb r30,10329(r31)
	REX_STORE_U8(ctx.r31.u32 + 10329, ctx.r30.u8);
	// std r11,10316(r31)
	REX_STORE_U64(ctx.r31.u32 + 10316, ctx.r11.u64);
	// bl 0x825a4640
	ctx.lr = 0x82370850;
	sub_825A4640(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825a48b0
	ctx.lr = 0x8237086C;
	sub_825A48B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82373be0
	ctx.lr = 0x82370874;
	sub_82373BE0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237C1E8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,244(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 244);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8237c230
	if (!ctx.cr6.gt) goto loc_8237C230;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12844(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12844);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237c22c
	if (ctx.cr6.eq) goto loc_8237C22C;
	// bl 0x8257fae8
	ctx.lr = 0x8237C224;
	sub_8257FAE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8237c230
	goto loc_8237C230;
loc_8237C22C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8237C230:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8237C240;
	sub_8235EC48(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8237c260
	if (ctx.cr6.eq) goto loc_8237C260;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82238f98
	ctx.lr = 0x8237C254;
	sub_82238F98(ctx, base);
	// li r4,58
	ctx.r4.s64 = 58;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8236a1b8
	ctx.lr = 0x8237C260;
	sub_8236A1B8(ctx, base);
loc_8237C260:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r11,22756
	ctx.r4.s64 = ctx.r11.s64 + 22756;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822390c0
	ctx.lr = 0x8237C274;
	sub_822390C0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r6,248(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r4,r11,22736
	ctx.r4.s64 = ctx.r11.s64 + 22736;
	// lwz r5,244(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 244);
	// bl 0x82738a28
	ctx.lr = 0x8237C28C;
	sub_82738A28(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8237C294:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8237c294
	if (!ctx.cr6.eq) goto loc_8237C294;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822390c0
	ctx.lr = 0x8237C2BC;
	sub_822390C0(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8237c2d0
	if (!ctx.cr6.lt) goto loc_8237C2D0;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_8237C2D0:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r30,256
	ctx.r3.s64 = ctx.r30.s64 + 256;
	// bl 0x8245d000
	ctx.lr = 0x8237C2DC;
	sub_8245D000(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8237C2EC;
	sub_8235EC48(ctx, base);
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

DEFINE_REX_FUNC(sub_8237F3A0) {
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
	// bl 0x8237f3f8
	ctx.lr = 0x8237F3C0;
	sub_8237F3F8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8237f3d8
	if (ctx.cr0.eq) goto loc_8237F3D8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8237f3d8
	if (ctx.cr6.eq) goto loc_8237F3D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8237F3D8;
	sub_825E0378(ctx, base);
loc_8237F3D8:
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

DEFINE_REX_FUNC(sub_82381090) {
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
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bne cr6,0x82381118
	if (!ctx.cr6.eq) goto loc_82381118;
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lbz r4,20(r4)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x824299b8
	ctx.lr = 0x823810BC;
	sub_824299B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82381118
	if (ctx.cr0.eq) goto loc_82381118;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lbz r11,272(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 272);
	// beq 0x823810f4
	if (ctx.cr0.eq) goto loc_823810F4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82381118
	if (!ctx.cr0.eq) goto loc_82381118;
	// lwz r11,276(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82381118
	if (!ctx.cr6.eq) goto loc_82381118;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,280(r5)
	REX_STORE_U8(ctx.r5.u32 + 280, ctx.r10.u8);
	// b 0x82381110
	goto loc_82381110;
loc_823810F4:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82381118
	if (!ctx.cr0.eq) goto loc_82381118;
	// lwz r11,276(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82381118
	if (!ctx.cr6.eq) goto loc_82381118;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,280(r5)
	REX_STORE_U8(ctx.r5.u32 + 280, ctx.r11.u8);
loc_82381110:
	// stb r11,272(r5)
	REX_STORE_U8(ctx.r5.u32 + 272, ctx.r11.u8);
	// stw r3,276(r5)
	REX_STORE_U32(ctx.r5.u32 + 276, ctx.r3.u32);
loc_82381118:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823846E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823846E8;
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r10,12468
	ctx.r29.s64 = ctx.r10.s64 + 12468;
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r28,r9,-9856
	ctx.r28.s64 = ctx.r9.s64 + -9856;
	// blt cr6,0x82384728
	if (ctx.cr6.lt) goto loc_82384728;
	// beq cr6,0x82384740
	if (ctx.cr6.eq) goto loc_82384740;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82384894
	if (ctx.cr6.lt) goto loc_82384894;
	// b 0x823848d8
	goto loc_823848D8;
loc_82384728:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823848d8
	if (ctx.cr6.lt) goto loc_823848D8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82384740:
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x82384764;
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
	ctx.lr = 0x82384778;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,2,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x4;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x82577228
	ctx.lr = 0x8238478C;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lfs f0,-10072(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -10072);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r27,92(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82577290
	ctx.lr = 0x823847B8;
	sub_82577290(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,4440(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4440);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x825a4a90
	ctx.lr = 0x823847F0;
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
	ctx.lr = 0x82384804;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divwu r10,r11,r27
	ctx.r10.u64 = uint32_t(ctx.r27.u32 ? ctx.r11.u32 / ctx.r27.u32 : 0);
	// twllei r27,0
	if (ctx.r27.s32 == 0 || ctx.r27.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r10,r10,r27
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r27.s32);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// bl 0x825a4a90
	ctx.lr = 0x8238483C;
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
	ctx.lr = 0x82384850;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// divwu r10,r3,r26
	ctx.r10.u64 = uint32_t(ctx.r26.u32 ? ctx.r3.u32 / ctx.r26.u32 : 0);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f31,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// twllei r26,0
	if (ctx.r26.s32 == 0 || ctx.r26.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r10,r10,r26
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stb r30,17(r31)
	REX_STORE_U8(ctx.r31.u32 + 17, ctx.r30.u8);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82384894:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x823848b4
	if (ctx.cr6.lt) goto loc_823848B4;
	// stfs f31,4(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// b 0x823848dc
	goto loc_823848DC;
loc_823848B4:
	// fsubs f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_823848D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823848DC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238FEF8) {
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
	// bl 0x823905e0
	ctx.lr = 0x8238FF10;
	sub_823905E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x8238FF18;
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

DEFINE_REX_FUNC(sub_82390FC8) {
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
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823910a4
	if (ctx.cr6.lt) goto loc_823910A4;
	// beq cr6,0x8239100c
	if (ctx.cr6.eq) goto loc_8239100C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x823910d4
	if (!ctx.cr6.lt) goto loc_823910D4;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,22(r3)
	REX_STORE_U8(ctx.r3.u32 + 22, ctx.r11.u8);
	// sth r10,14(r3)
	REX_STORE_U16(ctx.r3.u32 + 14, ctx.r10.u16);
	// b 0x823910d4
	goto loc_823910D4;
loc_8239100C:
	// lbz r11,253(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 253);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823910d4
	if (ctx.cr0.eq) goto loc_823910D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82391118
	ctx.lr = 0x82391020;
	sub_82391118(ctx, base);
	// bl 0x824281d8
	ctx.lr = 0x82391024;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// beq 0x82391094
	if (ctx.cr0.eq) goto loc_82391094;
	// lbz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 252);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82391094
	if (ctx.cr0.eq) goto loc_82391094;
	// lbz r11,254(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 254);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82391094
	if (!ctx.cr0.eq) goto loc_82391094;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stb r30,254(r31)
	REX_STORE_U8(ctx.r31.u32 + 254, ctx.r30.u8);
	// li r8,521
	ctx.r8.s64 = 521;
	// addi r9,r9,20580
	ctx.r9.s64 = ctx.r9.s64 + 20580;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// beq cr6,0x82391094
	if (ctx.cr6.eq) goto loc_82391094;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82364590
	ctx.lr = 0x82391094;
	sub_82364590(ctx, base);
loc_82391094:
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r30,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r30.u8);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// b 0x823910d4
	goto loc_823910D4;
loc_823910A4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823910B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823910d4
	if (!ctx.cr0.eq) goto loc_823910D4;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823910D4:
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

DEFINE_REX_FUNC(sub_82397508) {
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
	ctx.lr = 0x82397524;
	sub_8235F428(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r10,28528
	ctx.r10.s64 = ctx.r10.s64 + 28528;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r11,r31,416
	ctx.r11.s64 = ctx.r31.s64 + 416;
	// stfs f0,264(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 264, temp.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r8,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r8.u32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stw r30,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r30.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r30,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// sth r30,252(r31)
	REX_STORE_U16(ctx.r31.u32 + 252, ctx.r30.u16);
	// addi r6,r11,2836
	ctx.r6.s64 = ctx.r11.s64 + 2836;
	// sth r30,254(r31)
	REX_STORE_U16(ctx.r31.u32 + 254, ctx.r30.u16);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r30,260(r31)
	REX_STORE_U8(ctx.r31.u32 + 260, ctx.r30.u8);
	// stb r30,268(r31)
	REX_STORE_U8(ctx.r31.u32 + 268, ctx.r30.u8);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stb r30,276(r31)
	REX_STORE_U8(ctx.r31.u32 + 276, ctx.r30.u8);
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// stb r30,288(r31)
	REX_STORE_U8(ctx.r31.u32 + 288, ctx.r30.u8);
	// stb r30,300(r31)
	REX_STORE_U8(ctx.r31.u32 + 300, ctx.r30.u8);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stb r30,316(r31)
	REX_STORE_U8(ctx.r31.u32 + 316, ctx.r30.u8);
	// stw r30,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r30.u32);
	// stw r30,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r30.u32);
	// std r10,304(r31)
	REX_STORE_U64(ctx.r31.u32 + 304, ctx.r10.u64);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// stfs f0,348(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// std r11,328(r31)
	REX_STORE_U64(ctx.r31.u32 + 328, ctx.r11.u64);
	// stfs f0,352(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r11,356(r31)
	REX_STORE_U64(ctx.r31.u32 + 356, ctx.r11.u64);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r11,364(r31)
	REX_STORE_U64(ctx.r31.u32 + 364, ctx.r11.u64);
	// ld r11,2880(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 2880);
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// stb r30,400(r31)
	REX_STORE_U8(ctx.r31.u32 + 400, ctx.r30.u8);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stb r30,401(r31)
	REX_STORE_U8(ctx.r31.u32 + 401, ctx.r30.u8);
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stb r30,412(r31)
	REX_STORE_U8(ctx.r31.u32 + 412, ctx.r30.u8);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// std r11,372(r31)
	REX_STORE_U64(ctx.r31.u32 + 372, ctx.r11.u64);
	// stfs f0,404(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 404, temp.u32);
	// stfs f0,408(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
	// stw r7,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r7.u32);
	// stw r6,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r6.u32);
	// stb r30,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r30.u8);
	// stw r30,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// stw r30,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r30.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4640
	ctx.lr = 0x82397628;
	sub_825A4640(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825a48b0
	ctx.lr = 0x82397644;
	sub_825A48B0(ctx, base);
	// stw r30,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r30.u32);
	// stw r30,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
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

DEFINE_REX_FUNC(sub_823A4A48) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,29912
	ctx.r3.s64 = ctx.r11.s64 + 29912;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A4D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823A4D28;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823a4f24
	if (ctx.cr6.lt) goto loc_823A4F24;
	// beq cr6,0x823a4d70
	if (ctx.cr6.eq) goto loc_823A4D70;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x823a4f40
	if (!ctx.cr6.lt) goto loc_823A4F40;
	// lfs f0,232(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f13,232(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x823a4f40
	if (!ctx.cr6.lt) goto loc_823A4F40;
	// stfs f0,232(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// b 0x823a4f38
	goto loc_823A4F38;
loc_823A4D70:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lbz r10,244(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 244);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// addi r28,r11,2880
	ctx.r28.s64 = ctx.r11.s64 + 2880;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r31,0
	ctx.r31.s64 = 0;
	// stb r10,120(r1)
	REX_STORE_U8(ctx.r1.u32 + 120, ctx.r10.u8);
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// lwz r11,-13032(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -13032);
	// li r9,-1
	ctx.r9.s64 = -1;
	// ld r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r7,r30,248
	ctx.r7.s64 = ctx.r30.s64 + 248;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// stw r31,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r31,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r31,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// stw r31,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// stw r7,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stb r31,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r31.u8);
	// stb r31,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r31.u8);
	// beq cr6,0x823a4e14
	if (ctx.cr6.eq) goto loc_823A4E14;
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 | 1;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823b0d90
	ctx.lr = 0x823A4E0C;
	sub_823B0D90(ctx, base);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,-13032(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -13032);
loc_823A4E14:
	// clrlwi. r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x823a4f40
	if (ctx.cr0.eq) goto loc_823A4F40;
	// lwz r10,24(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x823a4f40
	if (ctx.cr6.lt) goto loc_823A4F40;
	// stw r31,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// beq cr6,0x823a4e60
	if (ctx.cr6.eq) goto loc_823A4E60;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823b0d90
	ctx.lr = 0x823A4E60;
	sub_823B0D90(ctx, base);
loc_823A4E60:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823a4f40
	if (ctx.cr0.eq) goto loc_823A4F40;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b2da0
	ctx.lr = 0x823A4E74;
	sub_823B2DA0(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82218a48
	ctx.lr = 0x823A4E94;
	sub_82218A48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A4EA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x823a4f00
	if (ctx.cr0.eq) goto loc_823A4F00;
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
	ctx.lr = 0x823A4EC8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823a4ef8
	if (ctx.cr0.eq) goto loc_823A4EF8;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r9,521
	ctx.r9.s64 = 521;
	// stw r29,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r29.u32);
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// b 0x823a4efc
	goto loc_823A4EFC;
loc_823A4EF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823A4EFC:
	// bl 0x825a2ef8
	ctx.lr = 0x823A4F00;
	sub_825A2EF8(ctx, base);
loc_823A4F00:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,232(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 232, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x823a4f1c
	if (ctx.cr6.gt) goto loc_823A4F1C;
	// lfs f0,1908(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,232(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 232, temp.u32);
loc_823A4F1C:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x823a4f3c
	goto loc_823A4F3C;
loc_823A4F24:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A4F38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823A4F38:
	// li r11,1
	ctx.r11.s64 = 1;
loc_823A4F3C:
	// stw r11,228(r30)
	REX_STORE_U32(ctx.r30.u32 + 228, ctx.r11.u32);
loc_823A4F40:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B24E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lfs f13,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// lfs f0,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// addi r4,r1,-32
	ctx.r4.s64 = ctx.r1.s64 + -32;
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// addi r11,r1,-48
	ctx.r11.s64 = ctx.r1.s64 + -48;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-48
	ctx.r7.s64 = ctx.r1.s64 + -48;
	// stfs f0,-36(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// addi r6,r1,-48
	ctx.r6.s64 = ctx.r1.s64 + -48;
	// stfs f0,-40(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// stfs f0,-44(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// lis r31,-32225
	ctx.r31.s64 = -2111897600;
	// stfs f0,-48(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,32256
	ctx.r11.s64 = ctx.r31.s64 + 32256;
	// lfs f12,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-48(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,-36(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// stfs f12,-40(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f12,-44(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v7,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f0,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,-20(r1)
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,-20(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,-48(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lfs f13,14376(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// vmulfp128 v12,v0,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vcmpeqfp128 v9,v0,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v11,v0,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v10,v13,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v8,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v6,v13,v62
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v7,v12,v10,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v10,v9,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v13,v13,v7,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v8,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v12,v63,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v13,v0,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsel v10,v11,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v12,v13,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823C12F0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x823bd038
	ctx.lr = 0x823C130C;
	sub_823BD038(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x823c131c
	if (!ctx.cr0.eq) goto loc_823C131C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823c1440
	goto loc_823C1440;
loc_823C131C:
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,56(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c1360
	if (ctx.cr6.eq) goto loc_823C1360;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x823c1360
	if (!ctx.cr6.gt) goto loc_823C1360;
	// lwz r11,76(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c1360
	if (ctx.cr6.eq) goto loc_823C1360;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// mulli r10,r10,22
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(22));
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x823c1364
	goto loc_823C1364;
loc_823C1360:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823C1364:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// addi r10,r10,14376
	ctx.r10.s64 = ctx.r10.s64 + 14376;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// lfs f13,-2140(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x823c1380
	if (!ctx.cr6.eq) goto loc_823C1380;
	// lfs f13,-1904(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1904);
	ctx.f13.f64 = double(temp.f32);
loc_823C1380:
	// lha r9,0(r11)
	ctx.r9.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 0));
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// li r3,1
	ctx.r3.s64 = 1;
	// lha r10,33(r30)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r30.u32 + 33));
	// lha r8,2(r11)
	ctx.r8.s64 = int16_t(REX_LOAD_U16(ctx.r11.u32 + 2));
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lhz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lha r4,35(r30)
	ctx.r4.s64 = int16_t(REX_LOAD_U16(ctx.r30.u32 + 35));
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lfd f10,88(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f8,88(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// std r4,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfd f7,88(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fmadds f12,f8,f0,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f12.f64)));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f7,f7
	ctx.f7.f64 = double(float(ctx.f7.f64));
	// fmadds f0,f10,f0,f9
	ctx.f0.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f9.f64)));
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fsubs f0,f0,f7
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f7.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lhz r11,94(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// sth r11,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r11.u16);
	// lhz r11,94(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// sth r11,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r11.u16);
loc_823C1440:
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

DEFINE_REX_FUNC(sub_823C9570) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823C9578;
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
	// beq cr6,0x823c9598
	if (ctx.cr6.eq) goto loc_823C9598;
	// bl 0x823bdef8
	ctx.lr = 0x823C9598;
	sub_823BDEF8(ctx, base);
loc_823C9598:
	// addi r31,r29,36
	ctx.r31.s64 = ctx.r29.s64 + 36;
	// li r30,4
	ctx.r30.s64 = 4;
loc_823C95A0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c95b0
	if (ctx.cr6.eq) goto loc_823C95B0;
	// bl 0x823bdef8
	ctx.lr = 0x823C95B0;
	sub_823BDEF8(ctx, base);
loc_823C95B0:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x823c95a0
	if (!ctx.cr0.eq) goto loc_823C95A0;
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
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CC6A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823CC6B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,8(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// bl 0x823cc410
	ctx.lr = 0x823CC6BC;
	sub_823CC410(ctx, base);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x823cc73c
	if (ctx.cr6.eq) goto loc_823CC73C;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r30,r11,17432
	ctx.r30.s64 = ctx.r11.s64 + 17432;
loc_823CC6D8:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
loc_823CC6E4:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x823cc704
	if (ctx.cr6.lt) goto loc_823CC704;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x823cc6e4
	if (ctx.cr6.lt) goto loc_823CC6E4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_823CC704:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x823cc724
	if (!ctx.cr6.eq) goto loc_823CC724;
	// bl 0x823b47e8
	ctx.lr = 0x823CC710;
	sub_823B47E8(ctx, base);
	// bl 0x824537a8
	ctx.lr = 0x823CC714;
	sub_824537A8(ctx, base);
	// subf r11,r3,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r3.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x823cc728
	goto loc_823CC728;
loc_823CC724:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823CC728:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823cc73c
	if (!ctx.cr0.eq) goto loc_823CC73C;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x823cc6d8
	if (!ctx.cr6.eq) goto loc_823CC6D8;
loc_823CC73C:
	// subf r11,r31,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r31.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CFF78) {
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
	ctx.lr = 0x823CFF88;
	sub_82213210(ctx, base);
	// lbz r11,4039(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4039);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cff9c
	if (ctx.cr0.eq) goto loc_823CFF9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823cffa4
	goto loc_823CFFA4;
loc_823CFF9C:
	// bl 0x82213210
	ctx.lr = 0x823CFFA0;
	sub_82213210(ctx, base);
	// lbz r3,4033(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
loc_823CFFA4:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82445010
	ctx.lr = 0x823CFFAC;
	sub_82445010(ctx, base);
	// lfs f0,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
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

DEFINE_REX_FUNC(sub_823D2690) {
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
	// lbz r11,133(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 133);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d26e8
	if (ctx.cr0.eq) goto loc_823D26E8;
	// lwz r4,124(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c60b0
	ctx.lr = 0x823D26BC;
	sub_823C60B0(ctx, base);
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d26e8
	if (ctx.cr6.eq) goto loc_823D26E8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823d26e8
	if (ctx.cr6.eq) goto loc_823D26E8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x823d26e8
	if (!ctx.cr6.gt) goto loc_823D26E8;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c8690
	ctx.lr = 0x823D26E8;
	sub_823C8690(ctx, base);
loc_823D26E8:
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

DEFINE_REX_FUNC(sub_823D7EC8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823d8118
	sub_823D8118(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D88F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823D88F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,24
	ctx.r11.s64 = 24;
	// li r10,25
	ctx.r10.s64 = 25;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r9,26
	ctx.r9.s64 = 26;
	// li r11,27
	ctx.r11.s64 = 27;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r9,29
	ctx.r9.s64 = 29;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r11,33
	ctx.r11.s64 = 33;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r10,34
	ctx.r10.s64 = 34;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// li r9,35
	ctx.r9.s64 = 35;
	// li r11,36
	ctx.r11.s64 = 36;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,37
	ctx.r10.s64 = 37;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// li r9,38
	ctx.r9.s64 = 38;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stw r10,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r28,r11,12704
	ctx.r28.s64 = ctx.r11.s64 + 12704;
loc_823D8984:
	// lwzx r31,r30,r28
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// bl 0x82213210
	ctx.lr = 0x823D898C;
	sub_82213210(ctx, base);
	// addi r29,r3,4120
	ctx.r29.s64 = ctx.r3.s64 + 4120;
	// bl 0x82213210
	ctx.lr = 0x823D8994;
	sub_82213210(ctx, base);
	// lbz r11,4033(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x823d89c0
	if (!ctx.cr6.lt) goto loc_823D89C0;
	// cmplwi cr6,r31,15
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 15, ctx.xer);
	// bge cr6,0x823d89c0
	if (!ctx.cr6.lt) goto loc_823D89C0;
	// mulli r11,r11,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(15));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
loc_823D89C0:
	// bl 0x823b4940
	ctx.lr = 0x823D89C4;
	sub_823B4940(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823c7af0
	ctx.lr = 0x823D89D4;
	sub_823C7AF0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
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
	ctx.lr = 0x823D8A04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r30,60
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 60, ctx.xer);
	// blt cr6,0x823d8984
	if (ctx.cr6.lt) goto loc_823D8984;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823DEE80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x823DEE88;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af28
	ctx.lr = 0x823DEE90;
	__savefpr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,45
	ctx.r10.s64 = 45;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823DEEA4:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,204(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 204);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x823deea4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823DEEA4;
	// lbz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 204);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823df348
	if (ctx.cr0.eq) goto loc_823DF348;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// addi r19,r11,15088
	ctx.r19.s64 = ctx.r11.s64 + 15088;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r24,-32114
	ctx.r24.s64 = -2104623104;
	// addi r21,r11,2500
	ctx.r21.s64 = ctx.r11.s64 + 2500;
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
	// lfs f29,-2616(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2616);
	ctx.f29.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,780(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 780);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823def10
	if (ctx.cr6.eq) goto loc_823DEF10;
	// lfs f2,-26680(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -26680);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,192(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// lfs f3,14744(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// fmr f5,f29
	ctx.f5.f64 = ctx.f29.f64;
	// lfs f1,-2852(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2852);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// bl 0x823c5a58
	ctx.lr = 0x823DEF0C;
	sub_823C5A58(ctx, base);
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
loc_823DEF10:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r25,r11,1612
	ctx.r25.s64 = ctx.r11.s64 + 1612;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r20,-1
	ctx.r20.s64 = -1;
	// lwz r27,428(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 428);
	// addi r23,r10,-30128
	ctx.r23.s64 = ctx.r10.s64 + -30128;
	// addi r22,r11,-26664
	ctx.r22.s64 = ctx.r11.s64 + -26664;
	// lfs f31,-992(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -992);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// lfs f28,17040(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 17040);
	ctx.f28.f64 = double(temp.f32);
	// beq cr6,0x823deffc
	if (ctx.cr6.eq) goto loc_823DEFFC;
	// lfs f0,4816(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4816);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f13,4892(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4892);
	ctx.f13.f64 = double(temp.f32);
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// lfs f12,344(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 344);
	ctx.f12.f64 = double(temp.f32);
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// lfs f11,348(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 348);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f12,352(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 352);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,356(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 356);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f7,f11,f13
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f0,-3800(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -3800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,22124(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 22124);
	ctx.f13.f64 = double(temp.f32);
	// li r29,2
	ctx.r29.s64 = 2;
	// lfs f12,-2620(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -2620);
	ctx.f12.f64 = double(temp.f32);
	// addi r26,r11,-10736
	ctx.r26.s64 = ctx.r11.s64 + -10736;
	// lfs f11,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f8,136(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f7,140(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_823DEFC0:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r5,192(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f28.f64;
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// addi r8,r30,8
	ctx.r8.s64 = ctx.r30.s64 + 8;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823c5c80
	ctx.lr = 0x823DEFEC;
	sub_823C5C80(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// bne 0x823defc0
	if (!ctx.cr0.eq) goto loc_823DEFC0;
loc_823DEFFC:
	// li r28,0
	ctx.r28.s64 = 0;
	// lfs f3,14744(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f2,17780(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 17780);
	ctx.f2.f64 = double(temp.f32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// lwz r3,180(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r6,192(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823DF02C;
	sub_823C67C0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f2,-26680(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -26680);
	ctx.f2.f64 = double(temp.f32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// lfs f3,14744(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 14744);
	ctx.f3.f64 = double(temp.f32);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r6,192(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r3,180(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823DF058;
	sub_823C67C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dfe30
	ctx.lr = 0x823DF060;
	sub_823DFE30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dff50
	ctx.lr = 0x823DF068;
	sub_823DFF50(ctx, base);
	// lwz r3,188(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// bl 0x823c8528
	ctx.lr = 0x823DF070;
	sub_823C8528(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823e0070
	ctx.lr = 0x823DF078;
	sub_823E0070(ctx, base);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r11,r21,7048
	ctx.r11.s64 = ctx.r21.s64 + 7048;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x823DF08C;
	sub_82213210(ctx, base);
	// addi r29,r3,4120
	ctx.r29.s64 = ctx.r3.s64 + 4120;
	// bl 0x82213210
	ctx.lr = 0x823DF094;
	sub_82213210(ctx, base);
	// lbz r11,4033(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x823df274
	if (!ctx.cr6.lt) goto loc_823DF274;
	// cmplwi cr6,r30,15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 15, ctx.xer);
	// bge cr6,0x823df274
	if (!ctx.cr6.lt) goto loc_823DF274;
	// mulli r11,r11,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(15));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r11,r29
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823df274
	if (ctx.cr6.eq) goto loc_823DF274;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,-12856(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x823df274
	if (ctx.cr6.eq) goto loc_823DF274;
	// addi r10,r21,14932
	ctx.r10.s64 = ctx.r21.s64 + 14932;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_823DF0E0:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x823df100
	if (ctx.cr6.lt) goto loc_823DF100;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x823df0e0
	if (ctx.cr6.lt) goto loc_823DF0E0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_823DF100:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x823df134
	if (ctx.cr6.eq) goto loc_823DF134;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x823df12c
	if (ctx.cr6.eq) goto loc_823DF12C;
	// ble cr6,0x823df124
	if (!ctx.cr6.gt) goto loc_823DF124;
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// bgt cr6,0x823df124
	if (ctx.cr6.gt) goto loc_823DF124;
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x823df138
	goto loc_823DF138;
loc_823DF124:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x823df138
	goto loc_823DF138;
loc_823DF12C:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x823df138
	goto loc_823DF138;
loc_823DF134:
	// li r11,2
	ctx.r11.s64 = 2;
loc_823DF138:
	// lwz r10,228(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 228);
	// lwz r8,224(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 224);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823df184
	if (!ctx.cr6.lt) goto loc_823DF184;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x823df184
	if (ctx.cr6.eq) goto loc_823DF184;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8245d130
	ctx.lr = 0x823DF16C;
	sub_8245D130(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823df184
	if (!ctx.cr0.eq) goto loc_823DF184;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8245d190
	ctx.lr = 0x823DF17C;
	sub_8245D190(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x823df188
	goto loc_823DF188;
loc_823DF184:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_823DF188:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823df274
	if (ctx.cr6.eq) goto loc_823DF274;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823b4f20
	ctx.lr = 0x823DF198;
	sub_823B4F20(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r11,-4080
	ctx.r9.s64 = ctx.r11.s64 + -4080;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// stb r28,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r28.u8);
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// lfs f0,-10568(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -10568);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f1,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// lwz r5,192(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// subf r10,r8,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lfs f13,3304(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3304);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lfs f12,3308(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3308);
	ctx.f12.f64 = double(temp.f32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r8,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// extsw r9,r7
	ctx.r9.s64 = ctx.r7.s32;
	// lfd f12,128(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f10,128(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x823DF274;
	sub_823C5C80(ctx, base);
loc_823DF274:
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lfs f31,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823df2c4
	if (ctx.cr6.eq) goto loc_823DF2C4;
	// li r4,58
	ctx.r4.s64 = 58;
	// bgt cr6,0x823df294
	if (ctx.cr6.gt) goto loc_823DF294;
	// li r4,59
	ctx.r4.s64 = 59;
loc_823DF294:
	// lfs f0,188(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 188);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,184(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// lwz r6,192(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// fadds f3,f0,f31
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// fsubs f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823DF2C4;
	sub_823C67C0(ctx, base);
loc_823DF2C4:
	// lwz r11,220(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823df30c
	if (ctx.cr6.eq) goto loc_823DF30C;
	// li r4,58
	ctx.r4.s64 = 58;
	// bgt cr6,0x823df2dc
	if (ctx.cr6.gt) goto loc_823DF2DC;
	// li r4,59
	ctx.r4.s64 = 59;
loc_823DF2DC:
	// lfs f0,204(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 204);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,200(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// lwz r6,192(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// fadds f3,f0,f31
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stb r28,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r28.u8);
	// fsubs f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x823c67c0
	ctx.lr = 0x823DF30C;
	sub_823C67C0(ctx, base);
loc_823DF30C:
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r21,7016
	ctx.r10.s64 = ctx.r21.s64 + 7016;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_823DF320:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lwz r8,200(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
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
	// bdnz 0x823df320
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823DF320;
loc_823DF348:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af74
	ctx.lr = 0x823DF354;
	__restfpr_28(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82403E30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82403E38;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x82403E44;
	sub_82213210(ctx, base);
	// lbz r11,4033(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82403e58
	if (!ctx.cr6.lt) goto loc_82403E58;
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x82403e68
	goto loc_82403E68;
loc_82403E58:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// li r27,16
	ctx.r27.s64 = 16;
	// bgt cr6,0x82403e68
	if (ctx.cr6.gt) goto loc_82403E68;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_82403E68:
	// lwz r11,792(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 792);
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82403f2c
	if (ctx.cr6.eq) goto loc_82403F2C;
	// addi r25,r30,768
	ctx.r25.s64 = ctx.r30.s64 + 768;
	// li r26,3
	ctx.r26.s64 = 3;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
loc_82403E88:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82403ea8
	if (ctx.cr6.eq) goto loc_82403EA8;
	// lwz r3,-12824(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x82403E9C;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82403EA8:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82403e88
	if (!ctx.cr0.eq) goto loc_82403E88;
	// stw r27,792(r30)
	REX_STORE_U32(ctx.r30.u32 + 792, ctx.r27.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stb r29,796(r30)
	REX_STORE_U8(ctx.r30.u32 + 796, ctx.r29.u8);
	// bl 0x82443da0
	ctx.lr = 0x82403EC4;
	sub_82443DA0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82444448
	ctx.lr = 0x82403ED0;
	sub_82444448(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82403ee4
	if (ctx.cr0.eq) goto loc_82403EE4;
	// bl 0x825995a0
	ctx.lr = 0x82403EDC;
	sub_825995A0(ctx, base);
	// stw r3,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// stw r29,780(r30)
	REX_STORE_U32(ctx.r30.u32 + 780, ctx.r29.u32);
loc_82403EE4:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82444448
	ctx.lr = 0x82403EF0;
	sub_82444448(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82403f04
	if (ctx.cr0.eq) goto loc_82403F04;
	// bl 0x825995a0
	ctx.lr = 0x82403EFC;
	sub_825995A0(ctx, base);
	// stw r3,772(r30)
	REX_STORE_U32(ctx.r30.u32 + 772, ctx.r3.u32);
	// stw r29,784(r30)
	REX_STORE_U32(ctx.r30.u32 + 784, ctx.r29.u32);
loc_82403F04:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82444448
	ctx.lr = 0x82403F10;
	sub_82444448(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82403f24
	if (ctx.cr0.eq) goto loc_82403F24;
	// bl 0x825995a0
	ctx.lr = 0x82403F1C;
	sub_825995A0(ctx, base);
	// stw r3,776(r30)
	REX_STORE_U32(ctx.r30.u32 + 776, ctx.r3.u32);
	// stw r29,788(r30)
	REX_STORE_U32(ctx.r30.u32 + 788, ctx.r29.u32);
loc_82403F24:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,796(r30)
	REX_STORE_U8(ctx.r30.u32 + 796, ctx.r11.u8);
loc_82403F2C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240AA30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8240AA38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240aa58
	if (ctx.cr6.eq) goto loc_8240AA58;
	// bl 0x823c74f0
	ctx.lr = 0x8240AA58;
	sub_823C74F0(ctx, base);
loc_8240AA58:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x8240AA78;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8240aa88
	if (ctx.cr0.eq) goto loc_8240AA88;
	// bl 0x823c9508
	ctx.lr = 0x8240AA84;
	sub_823C9508(ctx, base);
	// b 0x8240aa8c
	goto loc_8240AA8C;
loc_8240AA88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8240AA8C:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// stw r29,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r29.u32);
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r11.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240E1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8240E1D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subf r11,r5,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r5.u64;
	// lwz r9,76(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-15500
	ctx.r10.s64 = ctx.r10.s64 + -15500;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,-17176
	ctx.r11.s64 = ctx.r11.s64 + -17176;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// lwzx r30,r8,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r8,r28,-19936
	ctx.r8.s64 = ctx.r28.s64 + -19936;
	// rlwinm r5,r30,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,-29492(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lfs f13,-4112(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4112);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r5,r11
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r5,r10
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
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
	// std r11,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x8240E24C;
	sub_823C82A8(ctx, base);
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lfs f0,-19936(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -19936);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r11,r30,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f12,52(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,48(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x8240E28C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
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
	ctx.lr = 0x8240E2C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82417E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82417E88;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x823c5778
	ctx.lr = 0x82417E98;
	sub_823C5778(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-30872
	ctx.r9.s64 = ctx.r11.s64 + -30872;
	// stw r10,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r10.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// li r4,76
	ctx.r4.s64 = 76;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82417EC4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82417ed8
	if (ctx.cr0.eq) goto loc_82417ED8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x824181c8
	ctx.lr = 0x82417ED4;
	sub_824181C8(ctx, base);
	// b 0x82417edc
	goto loc_82417EDC;
loc_82417ED8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82417EDC:
	// stw r3,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r3.u32);
	// stw r31,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r31.u32);
	// lwz r31,156(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x82457b58
	ctx.lr = 0x82417EF0;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x82417EF4;
	sub_825FD7A0(ctx, base);
	// stw r3,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82418818
	ctx.lr = 0x82417F00;
	sub_82418818(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82417F10;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82417f20
	if (ctx.cr0.eq) goto loc_82417F20;
	// bl 0x823c8308
	ctx.lr = 0x82417F1C;
	sub_823C8308(ctx, base);
	// b 0x82417f24
	goto loc_82417F24;
loc_82417F20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82417F24:
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82417fb0
	if (ctx.cr6.eq) goto loc_82417FB0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82417fb0
	if (ctx.cr6.lt) goto loc_82417FB0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x82417fb0
	if (!ctx.cr6.lt) goto loc_82417FB0;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-18180
	ctx.r10.s64 = ctx.r10.s64 + -18180;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// addi r11,r11,-14240
	ctx.r11.s64 = ctx.r11.s64 + -14240;
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lis r5,-32228
	ctx.r5.s64 = -2112094208;
	// lwzx r10,r8,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,-30132(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -30132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-11144(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -11144);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r10,r8
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
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
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x82417FB0;
	sub_823C82A8(ctx, base);
loc_82417FB0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82425700) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82425708;
	__savegprlr_28(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,456(r3)
	REX_STORE_U32(ctx.r3.u32 + 456, ctx.r4.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,492(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 492);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// li r28,12
	ctx.r28.s64 = 12;
	// bgt cr6,0x82425728
	if (ctx.cr6.gt) goto loc_82425728;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_82425728:
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r30,196
	ctx.r29.s64 = ctx.r30.s64 + 196;
loc_82425730:
	// cmpw cr6,r31,r28
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x82425758
	if (!ctx.cr6.lt) goto loc_82425758;
	// lwz r11,456(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 456);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,504(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 504);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823cc4c8
	ctx.lr = 0x82425754;
	sub_823CC4C8(ctx, base);
	// b 0x82425760
	goto loc_82425760;
loc_82425758:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
loc_82425760:
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
	ctx.lr = 0x82425784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,12
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 12, ctx.xer);
	// blt cr6,0x82425730
	if (ctx.cr6.lt) goto loc_82425730;
	// addi r29,r30,244
	ctx.r29.s64 = ctx.r30.s64 + 244;
	// li r31,12
	ctx.r31.s64 = 12;
loc_82425798:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c7af0
	ctx.lr = 0x824257A8;
	sub_823C7AF0(ctx, base);
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
	ctx.lr = 0x824257CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82425798
	if (!ctx.cr0.eq) goto loc_82425798;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82424400
	ctx.lr = 0x824257DC;
	sub_82424400(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8242AF68) {
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
	// lbz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-30536
	ctx.r11.s64 = ctx.r11.s64 + -30536;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x8242afa8
	if (ctx.cr0.eq) goto loc_8242AFA8;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bne cr6,0x8242afa8
	if (!ctx.cr6.eq) goto loc_8242AFA8;
	// bl 0x82639e58
	ctx.lr = 0x8242AFA8;
	sub_82639E58(ctx, base);
loc_8242AFA8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-76
	ctx.r11.s64 = ctx.r11.s64 + -76;
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

DEFINE_REX_FUNC(sub_8242D7C8) {
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
	// bl 0x82213210
	ctx.lr = 0x8242D7E8;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8242d804
	if (ctx.cr6.eq) goto loc_8242D804;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825a82c0
	ctx.lr = 0x8242D800;
	sub_825A82C0(ctx, base);
	// b 0x8242d818
	goto loc_8242D818;
loc_8242D804:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r31,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-12956(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12956);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
loc_8242D818:
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

DEFINE_REX_FUNC(sub_82432290) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82432298;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824322B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824322D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x823c2bd0
	ctx.lr = 0x824322DC;
	sub_823C2BD0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r7,-12944(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + -12944);
loc_824322EC:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82432318
	if (ctx.cr6.eq) goto loc_82432318;
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82432318
	if (ctx.cr6.eq) goto loc_82432318;
	// li r6,150
	ctx.r6.s64 = 150;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r7,12
	ctx.r4.s64 = ctx.r7.s64 + 12;
	// bl 0x82454970
	ctx.lr = 0x82432310;
	sub_82454970(ctx, base);
	// lwz r7,-12944(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + -12944);
	// b 0x8243231c
	goto loc_8243231C;
loc_82432318:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8243231C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82432360
	if (ctx.cr6.eq) goto loc_82432360;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// bge cr6,0x82432360
	if (!ctx.cr6.lt) goto loc_82432360;
	// cmplwi cr6,r26,2
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 2, ctx.xer);
	// blt cr6,0x82432344
	if (ctx.cr6.lt) goto loc_82432344;
	// cmplwi cr6,r26,4
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 4, ctx.xer);
	// bge cr6,0x82432348
	if (!ctx.cr6.lt) goto loc_82432348;
	// li r28,1
	ctx.r28.s64 = 1;
	// b 0x82432348
	goto loc_82432348;
loc_82432344:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82432348:
	// mulli r11,r28,3
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(3));
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r3
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r3.u32);
	// b 0x82432364
	goto loc_82432364;
loc_82432360:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82432364:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// addi r3,r11,172
	ctx.r3.s64 = ctx.r11.s64 + 172;
	// lwz r8,168(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r9.u32);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82432394
	if (!ctx.cr6.eq) goto loc_82432394;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x824323a0
	goto loc_824323A0;
loc_82432394:
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
loc_824323A0:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x824323c4
	if (!ctx.cr6.lt) goto loc_824323C4;
	// addi r11,r4,2
	ctx.r11.s64 = ctx.r4.s64 + 2;
	// sth r10,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r10.u16);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x824323d0
	goto loc_824323D0;
loc_824323C4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823c2cf0
	ctx.lr = 0x824323CC;
	sub_823C2CF0(ctx, base);
	// lwz r7,-12944(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + -12944);
loc_824323D0:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// blt cr6,0x824322ec
	if (ctx.cr6.lt) goto loc_824322EC;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243AEA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f29.u64);
	// stfd f30,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243AED8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8243afe4
	if (!ctx.cr0.eq) goto loc_8243AFE4;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243AEF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8243afe4
	if (!ctx.cr0.eq) goto loc_8243AFE4;
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243ae28
	ctx.lr = 0x8243AF08;
	sub_8243AE28(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r11,12236
	ctx.r10.s64 = ctx.r11.s64 + 12236;
	// lfs f30,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// beq cr6,0x8243af38
	if (ctx.cr6.eq) goto loc_8243AF38;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// beq cr6,0x8243aff4
	if (ctx.cr6.eq) goto loc_8243AFF4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,26028(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26028);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8243af4c
	goto loc_8243AF4C;
loc_8243AF38:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x8243aff4
	if (ctx.cr6.eq) goto loc_8243AFF4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f13,748(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 748);
	ctx.f13.f64 = double(temp.f32);
loc_8243AF4C:
	// fmadds f0,f13,f29,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, ctx.f0.f64)));
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8243af64
	if (!ctx.cr6.lt) goto loc_8243AF64;
	// stfs f31,108(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// b 0x8243af70
	goto loc_8243AF70;
loc_8243AF64:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8243af70
	if (!ctx.cr6.gt) goto loc_8243AF70;
	// stfs f30,108(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
loc_8243AF70:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243AF88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243aff4
	if (ctx.cr0.eq) goto loc_8243AFF4;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bne cr6,0x8243afb8
	if (!ctx.cr6.eq) goto loc_8243AFB8;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8243AFA0:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,2528(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2528);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8244ba70
	ctx.lr = 0x8243AFB4;
	sub_8244BA70(ctx, base);
	// b 0x8243aff4
	goto loc_8243AFF4;
loc_8243AFB8:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bne cr6,0x8243aff4
	if (!ctx.cr6.eq) goto loc_8243AFF4;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,948(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 948);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243AFD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8243aff4
	if (!ctx.cr0.eq) goto loc_8243AFF4;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8243afa0
	goto loc_8243AFA0;
loc_8243AFE4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f0,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
loc_8243AFF4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82446998) {
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
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82446a28
	if (!ctx.cr6.eq) goto loc_82446A28;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82446a28
	if (ctx.cr6.eq) goto loc_82446A28;
	// lwz r11,8(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// rlwinm. r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824469f0
	if (ctx.cr0.eq) goto loc_824469F0;
	// stw r8,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// b 0x82446a28
	goto loc_82446A28;
loc_824469F0:
	// rlwinm. r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82446a08
	if (ctx.cr0.eq) goto loc_82446A08;
	// lwz r3,88(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x82446A00;
	sub_824443C8(ctx, base);
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// b 0x82446a28
	goto loc_82446A28;
loc_82446A08:
	// rlwinm. r11,r11,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82446a28
	if (ctx.cr0.eq) goto loc_82446A28;
	// lwz r3,88(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x82446A18;
	sub_824443C8(ctx, base);
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// lwz r3,92(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 92);
	// bl 0x824443c8
	ctx.lr = 0x82446A24;
	sub_824443C8(ctx, base);
	// stw r3,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
loc_82446A28:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8244BA70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8244BA78;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r30,12(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// b 0x8244bac0
	goto loc_8244BAC0;
loc_8244BA98:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244babc
	if (ctx.cr6.eq) goto loc_8244BABC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244BAB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpw cr6,r3,r29
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8244bacc
	if (ctx.cr6.eq) goto loc_8244BACC;
loc_8244BABC:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_8244BAC0:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8244ba98
	if (!ctx.cr6.eq) goto loc_8244BA98;
	// b 0x8244baf0
	goto loc_8244BAF0;
loc_8244BACC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r27,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r27.u32);
	// stw r26,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r26.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244BAF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8244BAF0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244D8F8) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244db98
	if (ctx.cr6.eq) goto loc_8244DB98;
	// clrlwi. r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8244db78
	if (ctx.cr0.eq) goto loc_8244DB78;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,868(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 868);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244D938;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8244db98
	if (!ctx.cr0.eq) goto loc_8244DB98;
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8244d980
	if (ctx.cr6.eq) goto loc_8244D980;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8244D958;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244d980
	if (ctx.cr0.eq) goto loc_8244D980;
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8244d980
	if (ctx.cr6.eq) goto loc_8244D980;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x8244D978;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r11.u32);
loc_8244D980:
	// lwz r31,44(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8244da88
	if (!ctx.cr6.eq) goto loc_8244DA88;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8244d9c8
	if (ctx.cr6.eq) goto loc_8244D9C8;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8244da3c
	if (ctx.cr6.eq) goto loc_8244DA3C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8244da44
	if (ctx.cr6.eq) goto loc_8244DA44;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8244da34
	if (ctx.cr6.eq) goto loc_8244DA34;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8244da2c
	if (ctx.cr6.eq) goto loc_8244DA2C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8244da24
	if (ctx.cr6.eq) goto loc_8244DA24;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// b 0x8244da18
	goto loc_8244DA18;
loc_8244D9C8:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8244da48
	if (ctx.cr6.eq) goto loc_8244DA48;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 960);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244D9EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8244da44
	if (ctx.cr6.eq) goto loc_8244DA44;
	// cmpwi cr6,r3,10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10, ctx.xer);
	// beq cr6,0x8244da3c
	if (ctx.cr6.eq) goto loc_8244DA3C;
	// cmpwi cr6,r3,17
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 17, ctx.xer);
	// beq cr6,0x8244da34
	if (ctx.cr6.eq) goto loc_8244DA34;
	// cmpwi cr6,r3,18
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 18, ctx.xer);
	// beq cr6,0x8244da2c
	if (ctx.cr6.eq) goto loc_8244DA2C;
	// cmpwi cr6,r3,19
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 19, ctx.xer);
	// beq cr6,0x8244da24
	if (ctx.cr6.eq) goto loc_8244DA24;
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
loc_8244DA18:
	// bne cr6,0x8244da48
	if (!ctx.cr6.eq) goto loc_8244DA48;
	// li r31,6
	ctx.r31.s64 = 6;
	// b 0x8244da48
	goto loc_8244DA48;
loc_8244DA24:
	// li r31,5
	ctx.r31.s64 = 5;
	// b 0x8244da48
	goto loc_8244DA48;
loc_8244DA2C:
	// li r31,4
	ctx.r31.s64 = 4;
	// b 0x8244da48
	goto loc_8244DA48;
loc_8244DA34:
	// li r31,3
	ctx.r31.s64 = 3;
	// b 0x8244da48
	goto loc_8244DA48;
loc_8244DA3C:
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x8244da48
	goto loc_8244DA48;
loc_8244DA44:
	// li r31,2
	ctx.r31.s64 = 2;
loc_8244DA48:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8244DA60;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8244db30
	if (ctx.cr0.eq) goto loc_8244DB30;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lfs f2,15288(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15288);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20196(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 20196);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8244db1c
	goto loc_8244DB1C;
loc_8244DA88:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8244DAA0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8244db30
	if (ctx.cr0.eq) goto loc_8244DB30;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8244db08
	if (ctx.cr6.eq) goto loc_8244DB08;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8244db00
	if (ctx.cr6.eq) goto loc_8244DB00;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8244daf8
	if (ctx.cr6.eq) goto loc_8244DAF8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8244daf0
	if (ctx.cr6.eq) goto loc_8244DAF0;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8244dae8
	if (ctx.cr6.eq) goto loc_8244DAE8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8244db0c
	if (!ctx.cr6.eq) goto loc_8244DB0C;
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8244db0c
	goto loc_8244DB0C;
loc_8244DAE8:
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x8244db0c
	goto loc_8244DB0C;
loc_8244DAF0:
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x8244db0c
	goto loc_8244DB0C;
loc_8244DAF8:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x8244db0c
	goto loc_8244DB0C;
loc_8244DB00:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x8244db0c
	goto loc_8244DB0C;
loc_8244DB08:
	// li r5,1
	ctx.r5.s64 = 1;
loc_8244DB0C:
	// lbz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 16);
	// lfs f2,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
loc_8244DB1C:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8221ef68
	ctx.lr = 0x8244DB28;
	sub_8221EF68(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8244db34
	goto loc_8244DB34;
loc_8244DB30:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8244DB34:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8244db98
	if (ctx.cr6.eq) goto loc_8244DB98;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8244DB48;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8244db98
	if (!ctx.cr6.eq) goto loc_8244DB98;
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
	ctx.lr = 0x8244DB74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8244db98
	goto loc_8244DB98;
loc_8244DB78:
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8244db98
	if (ctx.cr6.eq) goto loc_8244DB98;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x8244DB90;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r11.u32);
loc_8244DB98:
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

DEFINE_REX_FUNC(sub_82460220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// lfs f13,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// vsubfp128 v12,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f0,-12(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
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
	// lvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v11,v62,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v13,v11,v1,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v12,v1,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// ld r11,-32(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8246B4B8) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8246b5bc
	if (ctx.cr0.eq) goto loc_8246B5BC;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8246b500
	if (ctx.cr0.eq) goto loc_8246B500;
loc_8246B4EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b2d08
	ctx.lr = 0x8246B4F4;
	sub_823B2D08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,124(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 124);
	// b 0x8246b60c
	goto loc_8246B60C;
loc_8246B500:
	// lwz r9,4(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm. r9,r9,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8246b62c
	if (ctx.cr0.eq) goto loc_8246B62C;
	// clrlwi. r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8246b62c
	if (ctx.cr0.eq) goto loc_8246B62C;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r10,r8,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8246b574
	if (!ctx.cr6.eq) goto loc_8246B574;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246b574
	if (ctx.cr6.eq) goto loc_8246B574;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8246b574
	if (!ctx.cr0.eq) goto loc_8246B574;
	// rlwinm. r10,r11,0,27,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8246b574
	if (!ctx.cr0.eq) goto loc_8246B574;
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8246b574
	if (!ctx.cr0.eq) goto loc_8246B574;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,12(r4)
	REX_STORE_U8(ctx.r4.u32 + 12, ctx.r11.u8);
	// stb r11,13(r4)
	REX_STORE_U8(ctx.r4.u32 + 13, ctx.r11.u8);
	// b 0x8246b62c
	goto loc_8246B62C;
loc_8246B574:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b2d08
	ctx.lr = 0x8246B57C;
	sub_823B2D08(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bge cr6,0x8246b5b4
	if (!ctx.cr6.lt) goto loc_8246B5B4;
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
loc_8246B5AC:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// b 0x8246b628
	goto loc_8246B628;
loc_8246B5B4:
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// b 0x8246b5ac
	goto loc_8246B5AC;
loc_8246B5BC:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8246b62c
	if (ctx.cr0.eq) goto loc_8246B62C;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8246b5e4
	if (ctx.cr0.eq) goto loc_8246B5E4;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi. r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8246b4ec
	if (!ctx.cr0.eq) goto loc_8246B4EC;
loc_8246B5E4:
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8246b62c
	if (ctx.cr0.eq) goto loc_8246B62C;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8246b62c
	if (ctx.cr0.eq) goto loc_8246B62C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b2d08
	ctx.lr = 0x8246B604;
	sub_823B2D08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,128(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 128);
loc_8246B60C:
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_8246B628:
	// bctrl 
	ctx.lr = 0x8246B62C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8246B62C:
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

DEFINE_REX_FUNC(sub_82476FD0) {
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
	// bl 0x82477b40
	ctx.lr = 0x82476FE8;
	sub_82477B40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477930
	ctx.lr = 0x82476FF0;
	sub_82477930(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477a58
	ctx.lr = 0x82476FF8;
	sub_82477A58(ctx, base);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247700C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82477d80
	ctx.lr = 0x82477014;
	sub_82477D80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82478070
	ctx.lr = 0x8247701C;
	sub_82478070(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82478530
	ctx.lr = 0x82477024;
	sub_82478530(ctx, base);
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

DEFINE_REX_FUNC(sub_82479F58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82479F60;
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
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479F7C;
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
	// beq 0x8247a078
	if (ctx.cr0.eq) goto loc_8247A078;
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479FA8;
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
	// lwz r11,1020(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479FC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8247a070
	goto loc_8247A070;
loc_82479FD0:
	// lwz r30,48(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8247a06c
	if (ctx.cr6.eq) goto loc_8247A06C;
	// lbz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 52);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8247a06c
	if (ctx.cr0.eq) goto loc_8247A06C;
	// lbz r11,53(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 53);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8247a06c
	if (!ctx.cr0.eq) goto loc_8247A06C;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8247A000;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8247a06c
	if (ctx.cr0.eq) goto loc_8247A06C;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8247A014;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8247a06c
	if (ctx.cr0.eq) goto loc_8247A06C;
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
	ctx.lr = 0x8247A044;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8247a054
	if (ctx.cr6.eq) goto loc_8247A054;
	// sth r11,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r11.u16);
loc_8247A054:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8247a064
	if (ctx.cr6.eq) goto loc_8247A064;
	// stb r11,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r11.u8);
loc_8247A064:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,52(r31)
	REX_STORE_U8(ctx.r31.u32 + 52, ctx.r11.u8);
loc_8247A06C:
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
loc_8247A070:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82479fd0
	if (!ctx.cr6.eq) goto loc_82479FD0;
loc_8247A078:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82484530) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82484538;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1976(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1976);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,1972(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1972);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r29,r3,1968
	ctx.r29.s64 = ctx.r3.s64 + 1968;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82484604
	if (ctx.cr0.eq) goto loc_82484604;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// addi r27,r3,304
	ctx.r27.s64 = ctx.r3.s64 + 304;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
loc_82484574:
	// lwz r11,1972(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1972);
	// lwzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x824845e0
	if (ctx.cr6.eq) goto loc_824845E0;
	// lbz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x824845e0
	if (!ctx.cr0.eq) goto loc_824845E0;
	// lwz r10,-13032(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stb r31,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r31.u8);
	// stb r31,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r31.u8);
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
	// beq cr6,0x824845d8
	if (ctx.cr6.eq) goto loc_824845D8;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b0af8
	ctx.lr = 0x824845D8;
	sub_823B0AF8(ctx, base);
loc_824845D8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82484604
	if (!ctx.cr0.eq) goto loc_82484604;
loc_824845E0:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r27,r27,28
	ctx.r27.s64 = ctx.r27.s64 + 28;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82484574
	if (ctx.cr6.lt) goto loc_82484574;
loc_82484604:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82217698
	ctx.lr = 0x8248460C;
	sub_82217698(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82468f80
	ctx.lr = 0x82484618;
	sub_82468F80(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248EED0) {
	REX_FUNC_PROLOGUE();
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
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8248ef58
	if (ctx.cr0.eq) goto loc_8248EF58;
	// lbz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8248ef20
	if (!ctx.cr6.lt) goto loc_8248EF20;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x8248ef5c
	goto loc_8248EF5C;
loc_8248EF20:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8248ef30
	if (!ctx.cr6.lt) goto loc_8248EF30;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8248ef5c
	goto loc_8248EF5C;
loc_8248EF30:
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8248ef40
	if (!ctx.cr6.lt) goto loc_8248EF40;
	// li r11,8
	ctx.r11.s64 = 8;
	// b 0x8248ef5c
	goto loc_8248EF5C;
loc_8248EF40:
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x8248ef50
	if (!ctx.cr6.lt) goto loc_8248EF50;
	// li r11,10
	ctx.r11.s64 = 10;
	// b 0x8248ef5c
	goto loc_8248EF5C;
loc_8248EF50:
	// li r11,12
	ctx.r11.s64 = 12;
	// b 0x8248ef5c
	goto loc_8248EF5C;
loc_8248EF58:
	// li r11,50
	ctx.r11.s64 = 50;
loc_8248EF5C:
	// stw r11,336(r3)
	REX_STORE_U32(ctx.r3.u32 + 336, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824917E8) {
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
	// bl 0x824693b8
	ctx.lr = 0x82491800;
	sub_824693B8(ctx, base);
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blt cr6,0x82491854
	if (ctx.cr6.lt) goto loc_82491854;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82491854
	if (ctx.cr6.gt) goto loc_82491854;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x82491830;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82491868
	ctx.lr = 0x82491838;
	sub_82491868(ctx, base);
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
	ctx.lr = 0x82491854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82491854:
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

DEFINE_REX_FUNC(sub_82496000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82496008;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,312(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// li r11,32
	ctx.r11.s64 = 32;
	// lwz r8,316(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// lfs f0,300(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,300(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r30,r3,312
	ctx.r30.s64 = ctx.r3.s64 + 312;
	// addi r29,r3,320
	ctx.r29.s64 = ctx.r3.s64 + 320;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r28,r3,328
	ctx.r28.s64 = ctx.r3.s64 + 328;
	// stw r9,320(r3)
	REX_STORE_U32(ctx.r3.u32 + 320, ctx.r9.u32);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// stw r8,324(r3)
	REX_STORE_U32(ctx.r3.u32 + 324, ctx.r8.u32);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// stw r9,328(r3)
	REX_STORE_U32(ctx.r3.u32 + 328, ctx.r9.u32);
	// addi r10,r3,356
	ctx.r10.s64 = ctx.r3.s64 + 356;
	// stw r8,332(r3)
	REX_STORE_U32(ctx.r3.u32 + 332, ctx.r8.u32);
	// li r25,0
	ctx.r25.s64 = 0;
loc_82496064:
	// stbu r25,32(r10)
	ea = 32 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82496064
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82496064;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r25,1412(r31)
	REX_STORE_U32(ctx.r31.u32 + 1412, ctx.r25.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r11,12468
	ctx.r27.s64 = ctx.r11.s64 + 12468;
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// li r26,6
	ctx.r26.s64 = 6;
	// lwz r11,-13032(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// lfs f30,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824960c4
	if (ctx.cr6.eq) goto loc_824960C4;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r6,1
	ctx.r6.s64 = 1;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aebd8
	ctx.lr = 0x824960BC;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x824960dc
	if (!ctx.cr0.eq) goto loc_824960DC;
loc_824960C4:
	// lbz r11,4013(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 4013);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824960dc
	if (!ctx.cr0.eq) goto loc_824960DC;
	// lbz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82496100
	if (ctx.cr0.eq) goto loc_82496100;
loc_824960DC:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// beq cr6,0x82496100
	if (ctx.cr6.eq) goto loc_82496100;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x82496100
	if (ctx.cr6.eq) goto loc_82496100;
	// stfs f30,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8249b238
	ctx.lr = 0x824960FC;
	sub_8249B238(ctx, base);
	// stw r26,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r26.u32);
loc_82496100:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x82496618
	if (ctx.cr6.gt) goto loc_82496618;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82496168
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82496168;
	// bdzf 4*cr6+eq,0x8249622c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8249622C;
	// bdzf 4*cr6+eq,0x82496278
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82496278;
	// bdzf 4*cr6+eq,0x824963a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824963A0;
	// bdzf 4*cr6+eq,0x824964ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824964AC;
	// bdzf 4*cr6+eq,0x824965b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824965B4;
	// bne cr6,0x82496610
	if (!ctx.cr6.eq) goto loc_82496610;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f30,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f30,348(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,4012(r31)
	REX_STORE_U8(ctx.r31.u32 + 4012, ctx.r11.u8);
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// bl 0x8249b700
	ctx.lr = 0x8249614C;
	sub_8249B700(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,7216
	ctx.r3.s64 = ctx.r11.s64 + 7216;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8257d4d8
	ctx.lr = 0x82496160;
	sub_8257D4D8(ctx, base);
loc_82496160:
	// stw r3,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r3.u32);
	// b 0x82496618
	goto loc_82496618;
loc_82496168:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f12,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f12,f31
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// stfs f12,348(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82496190
	if (!ctx.cr6.gt) goto loc_82496190;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_82496190:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8249b7e0
	ctx.lr = 0x8249619C;
	sub_8249B7E0(ctx, base);
	// lbz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 360);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbz r11,4012(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 4012);
	// bne 0x824961e0
	if (!ctx.cr0.eq) goto loc_824961E0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824961d0
	if (ctx.cr0.eq) goto loc_824961D0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,1392(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1392);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824961d0
	if (!ctx.cr6.gt) goto loc_824961D0;
	// stb r25,4012(r31)
	REX_STORE_U8(ctx.r31.u32 + 4012, ctx.r25.u8);
loc_824961D0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-30128
	ctx.r11.s64 = ctx.r11.s64 + -30128;
	// lfs f0,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17424);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82496214
	goto loc_82496214;
loc_824961E0:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82496204
	if (ctx.cr0.eq) goto loc_82496204;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-30128
	ctx.r11.s64 = ctx.r11.s64 + -30128;
	// lfs f0,-17424(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17424);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82496204
	if (!ctx.cr6.gt) goto loc_82496204;
	// stb r25,4012(r31)
	REX_STORE_U8(ctx.r31.u32 + 4012, ctx.r25.u8);
loc_82496204:
	// lbz r11,361(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 361);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82496220
	if (!ctx.cr0.eq) goto loc_82496220;
	// lfs f0,2620(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2620);
	ctx.f0.f64 = double(temp.f32);
loc_82496214:
	// lfs f13,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82496618
	if (!ctx.cr6.gt) goto loc_82496618;
loc_82496220:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// b 0x82496618
	goto loc_82496618;
loc_8249622C:
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82496248
	if (ctx.cr6.eq) goto loc_82496248;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x82496248;
	sub_825765F0(ctx, base);
loc_82496248:
	// lwz r3,4032(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4032);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82496268
	if (ctx.cr6.eq) goto loc_82496268;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82496268;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82496268:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-22760
	ctx.r3.s64 = ctx.r11.s64 + -22760;
	// bl 0x8257d590
	ctx.lr = 0x82496274;
	sub_8257D590(ctx, base);
	// b 0x82496160
	goto loc_82496160;
loc_82496278:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824962a0
	if (!ctx.cr6.gt) goto loc_824962A0;
	// li r11,4
	ctx.r11.s64 = 4;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f30,300(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824962A0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f11,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,-30128
	ctx.r11.s64 = ctx.r11.s64 + -30128;
	// addi r27,r10,32720
	ctx.r27.s64 = ctx.r10.s64 + 32720;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f0,-11328(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11328);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82496308;
	sub_8255F918(ctx, base);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stw r7,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r7.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f0,-18544(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18544);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82496364:
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82496374;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r6,r31,292
	ctx.r6.s64 = ctx.r31.s64 + 292;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// bl 0x824968a0
	ctx.lr = 0x8249639C;
	sub_824968A0(ctx, base);
	// b 0x82496618
	goto loc_82496618;
loc_824963A0:
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,360(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 360);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r11,-30128
	ctx.r11.s64 = ctx.r11.s64 + -30128;
	// bne 0x824963c8
	if (!ctx.cr0.eq) goto loc_824963C8;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// b 0x824963d8
	goto loc_824963D8;
loc_824963C8:
	// lbz r10,362(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 362);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x824963e0
	if (!ctx.cr0.eq) goto loc_824963E0;
	// lfs f13,2620(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2620);
	ctx.f13.f64 = double(temp.f32);
loc_824963D8:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824963ec
	if (!ctx.cr6.gt) goto loc_824963EC;
loc_824963E0:
	// li r10,5
	ctx.r10.s64 = 5;
	// stfs f30,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r10,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
loc_824963EC:
	// lfs f0,-11328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11328);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f11,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r27,r10,32720
	ctx.r27.s64 = ctx.r10.s64 + 32720;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8249644C;
	sub_8255F918(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lfs f0,-18544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18544);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
loc_8249648C:
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// b 0x82496364
	goto loc_82496364;
loc_824964AC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r11,-30128
	ctx.r27.s64 = ctx.r11.s64 + -30128;
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f31,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f31.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82496510
	if (!ctx.cr6.lt) goto loc_82496510;
	// stfs f30,304(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8249b238
	ctx.lr = 0x824964D8;
	sub_8249B238(ctx, base);
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// stw r26,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r26.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x824964f0
	if (!ctx.cr6.eq) goto loc_824964F0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// b 0x824964f4
	goto loc_824964F4;
loc_824964F0:
	// bl 0x82576728
	ctx.lr = 0x824964F4;
	sub_82576728(ctx, base);
loc_824964F4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82496510
	if (ctx.cr0.eq) goto loc_82496510;
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82496510
	if (ctx.cr6.eq) goto loc_82496510;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x82496510;
	sub_825765F0(ctx, base);
loc_82496510:
	// lfs f0,-11328(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -11328);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f11,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r27,r10,32720
	ctx.r27.s64 = ctx.r10.s64 + 32720;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82496570;
	sub_8255F918(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lfs f0,-18544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18544);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
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
	// b 0x8249648c
	goto loc_8249648C;
loc_824965B4:
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,344(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824965d8
	if (!ctx.cr6.gt) goto loc_824965D8;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824965D8:
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x824965ec
	if (!ctx.cr6.eq) goto loc_824965EC;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// b 0x824965f0
	goto loc_824965F0;
loc_824965EC:
	// bl 0x82576728
	ctx.lr = 0x824965F0;
	sub_82576728(ctx, base);
loc_824965F0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82496618
	if (ctx.cr0.eq) goto loc_82496618;
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82496618
	if (ctx.cr6.eq) goto loc_82496618;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x8249660C;
	sub_825765F0(ctx, base);
	// b 0x82496618
	goto loc_82496618;
loc_82496610:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82496618:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D0708) {
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
	// lwz r11,280(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 280);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824d0840
	if (ctx.cr6.eq) goto loc_824D0840;
	// bl 0x824281d8
	ctx.lr = 0x824D0734;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d0780
	if (!ctx.cr0.eq) goto loc_824D0780;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,280(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
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
	// bne cr6,0x824d0840
	if (!ctx.cr6.eq) goto loc_824D0840;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824d0840
	if (ctx.cr6.eq) goto loc_824D0840;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x824D0774;
	sub_82430A88(ctx, base);
loc_824D0774:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// b 0x824d0850
	goto loc_824D0850;
loc_824D0780:
	// bl 0x82429a18
	ctx.lr = 0x824D0784;
	sub_82429A18(ctx, base);
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// bl 0x82429960
	ctx.lr = 0x824D078C;
	sub_82429960(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82429668
	ctx.lr = 0x824D0798;
	sub_82429668(ctx, base);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,3456
	ctx.r11.s64 = ctx.r11.s64 + 3456;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
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
	// bne 0x824d0834
	if (!ctx.cr0.eq) goto loc_824D0834;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// beq 0x824d0838
	if (ctx.cr0.eq) goto loc_824D0838;
loc_824D0834:
	// li r11,1
	ctx.r11.s64 = 1;
loc_824D0838:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d0774
	if (!ctx.cr0.eq) goto loc_824D0774;
loc_824D0840:
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
loc_824D0850:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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

DEFINE_REX_FUNC(sub_824DA780) {
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
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r10,3204
	ctx.r3.s64 = ctx.r10.s64 + 3204;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824DA7B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x824DA7B4;
	sub_8245A220(ctx, base);
	// stw r3,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r3.u32);
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

DEFINE_REX_FUNC(sub_824DBFF8) {
	REX_FUNC_PROLOGUE();
	// lbz r11,436(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 436);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// b 0x82468e98
	sub_82468E98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824DCC48) {
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
	// lbz r11,436(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 436);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824dcdb8
	if (!ctx.cr0.eq) goto loc_824DCDB8;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x824dccb0
	if (ctx.cr6.gt) goto loc_824DCCB0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824DCCB0:
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r11,32432
	ctx.r8.s64 = ctx.r11.s64 + 32432;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,-13032(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824dcd30
	if (ctx.cr0.eq) goto loc_824DCD30;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824dcd6c
	if (ctx.cr6.eq) goto loc_824DCD6C;
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
	// bl 0x823ae578
	ctx.lr = 0x824DCD2C;
	sub_823AE578(ctx, base);
	// b 0x824dcd68
	goto loc_824DCD68;
loc_824DCD30:
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824dcd6c
	if (ctx.cr6.eq) goto loc_824DCD6C;
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
	// bl 0x823ae2c0
	ctx.lr = 0x824DCD68;
	sub_823AE2C0(ctx, base);
loc_824DCD68:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824DCD6C:
	// mullw. r11,r11,r11
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824dcdb0
	if (ctx.cr0.eq) goto loc_824DCDB0;
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
	// addi r10,r10,-32496
	ctx.r10.s64 = ctx.r10.s64 + -32496;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
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
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
loc_824DCDB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82468f80
	ctx.lr = 0x824DCDB8;
	sub_82468F80(ctx, base);
loc_824DCDB8:
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

DEFINE_REX_FUNC(sub_824E6910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824E6918;
	__savegprlr_26(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E6938;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// lfs f0,17288(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17288);
	ctx.f0.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r30,-13032(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r8,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r9,2688
	ctx.r9.s64 = ctx.r9.s64 + 2688;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r9,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// lvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r11.u64);
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// beq cr6,0x824e6ac0
	if (ctx.cr6.eq) goto loc_824E6AC0;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x824E6ABC;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824E6AC0:
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
	// lwz r7,292(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
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
	// beq cr6,0x824e6b08
	if (ctx.cr6.eq) goto loc_824E6B08;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823b0938
	ctx.lr = 0x824E6B04;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824E6B08:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F9E58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824F9E60;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// clrlwi r27,r7,24
	ctx.r27.u64 = ctx.r7.u32 & 0xFF;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// addi r4,r10,-9796
	ctx.r4.s64 = ctx.r10.s64 + -9796;
	// li r8,9
	ctx.r8.s64 = 9;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x824F9E9C;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-9784
	ctx.r9.s64 = ctx.r11.s64 + -9784;
	// addi r10,r10,12236
	ctx.r10.s64 = ctx.r10.s64 + 12236;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addic r7,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r7.s64 = ctx.r29.s64 + -1;
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// lfs f0,232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// subfe r11,r7,r29
	temp.u8 = (~ctx.r7.u32 + ctx.r29.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r7.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stb r9,329(r31)
	REX_STORE_U8(ctx.r31.u32 + 329, ctx.r9.u8);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r9,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r9.u32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stb r27,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r27.u8);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stw r5,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r5.u32);
	// lfs f0,-20940(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r11.u8);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,32528
	ctx.r8.s64 = ctx.r8.s64 + 32528;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824f9f4c
	if (ctx.cr0.eq) goto loc_824F9F4C;
	// lfs f12,236(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x824f9f50
	goto loc_824F9F50;
loc_824F9F4C:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_824F9F50:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f13,-2184(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2184);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r4,274(r31)
	REX_STORE_U8(ctx.r31.u32 + 274, ctx.r4.u8);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825074E0) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,269(r3)
	REX_STORE_U8(ctx.r3.u32 + 269, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82507738) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82507740;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82507934
	if (!ctx.cr0.eq) goto loc_82507934;
	// lbz r11,289(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82507768
	if (ctx.cr0.eq) goto loc_82507768;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
loc_82507768:
	// lwa r10,304(r31)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 304));
	// lfs f0,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// stfs f13,316(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// addi r27,r11,-2184
	ctx.r27.s64 = ctx.r11.s64 + -2184;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r28,r11,12236
	ctx.r28.s64 = ctx.r11.s64 + 12236;
	// lfs f0,3720(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 3720);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82507828
	if (!ctx.cr6.gt) goto loc_82507828;
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// lfs f0,232(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82507820
	goto loc_82507820;
loc_825077BC:
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82507818
	if (ctx.cr6.lt) goto loc_82507818;
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// addi r30,r31,376
	ctx.r30.s64 = ctx.r31.s64 + 376;
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82507810
	if (ctx.cr6.eq) goto loc_82507810;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x825e0378
	ctx.lr = 0x82507804;
	sub_825E0378(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82507810:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x8250781c
	goto loc_8250781C;
loc_82507818:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8250781C:
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
loc_82507820:
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825077bc
	if (!ctx.cr6.eq) goto loc_825077BC;
loc_82507828:
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x82507830;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82507934
	if (ctx.cr0.eq) goto loc_82507934;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x82507840;
	sub_82430A88(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,32496
	ctx.r11.s64 = ctx.r11.s64 + 32496;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lbz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 296);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82507888
	if (ctx.cr0.eq) goto loc_82507888;
	// lfs f11,236(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 236);
	ctx.f11.f64 = double(temp.f32);
	// b 0x8250788c
	goto loc_8250788C;
loc_82507888:
	// lfs f11,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
loc_8250788C:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f12,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
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
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
loc_82507934:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825171B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825171B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,324(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f1.f64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8251730c
	if (!ctx.cr6.eq) goto loc_8251730C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,292(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r11,624
	ctx.r29.s64 = ctx.r11.s64 + 624;
	// lfs f0,10496(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 10496);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8251730c
	if (!ctx.cr6.lt) goto loc_8251730C;
	// lwz r11,300(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bge cr6,0x8251730c
	if (!ctx.cr6.lt) goto loc_8251730C;
	// lbz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 320);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8251730c
	if (!ctx.cr0.eq) goto loc_8251730C;
	// lfs f0,316(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lfs f13,312(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,316(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 316, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8251730c
	if (!ctx.cr6.gt) goto loc_8251730C;
	// ld r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 52);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ld r10,44(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// bl 0x8255f918
	ctx.lr = 0x82517240;
	sub_8255F918(ctx, base);
	// ld r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// bl 0x82517460
	ctx.lr = 0x82517248;
	sub_82517460(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82517304
	if (!ctx.cr0.eq) goto loc_82517304;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f3,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f3.f64 = double(temp.f32);
	// lfs f9,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f2,f9,f3,f0
	ctx.f2.f64 = double(float(std::fma(ctx.f9.f64, ctx.f3.f64, ctx.f0.f64)));
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x82517268;
	sub_822EA1A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = ctx.f1.f64;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82517280;
	sub_822EA1A8(ctx, base);
	// lwz r30,300(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// ble cr6,0x825172ac
	if (!ctx.cr6.gt) goto loc_825172AC;
	// lfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f0,f6
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f6.f64));
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lfs f0,14280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14280);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825172ac
	if (!ctx.cr6.gt) goto loc_825172AC;
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
loc_825172AC:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x825172D8;
	sub_8255F918(ctx, base);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// lbz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// lfs f5,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f5.f64 = double(temp.f32);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lfs f4,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f4.f64 = double(temp.f32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x82516c48
	ctx.lr = 0x82517304;
	sub_82516C48(ctx, base);
loc_82517304:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,320(r31)
	REX_STORE_U8(ctx.r31.u32 + 320, ctx.r11.u8);
loc_8251730C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825214D8) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82521B20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82521B28;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,88(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x824443c8
	ctx.lr = 0x82521B3C;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82521b6c
	if (ctx.cr0.eq) goto loc_82521B6C;
	// lbz r11,2364(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82521b60
	if (ctx.cr0.eq) goto loc_82521B60;
	// lbz r11,2365(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2365);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x82521b64
	if (ctx.cr0.eq) goto loc_82521B64;
loc_82521B60:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82521B64:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82521c98
	if (!ctx.cr0.eq) goto loc_82521C98;
loc_82521B6C:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82521be8
	if (ctx.cr0.eq) goto loc_82521BE8;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// lwz r8,172(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82521bb0
	if (!ctx.cr6.eq) goto loc_82521BB0;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82521bb4
	if (!ctx.cr6.eq) goto loc_82521BB4;
loc_82521BB0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82521BB4:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82521c98
	if (ctx.cr0.eq) goto loc_82521C98;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82521c98
	if (!ctx.cr6.eq) goto loc_82521C98;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82521c98
	if (ctx.cr6.eq) goto loc_82521C98;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r11,r11,30,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x82521c58
	goto loc_82521C58;
loc_82521BE8:
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82521c98
	if (ctx.cr0.eq) goto loc_82521C98;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// lwz r8,172(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82521c24
	if (!ctx.cr6.eq) goto loc_82521C24;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82521c28
	if (!ctx.cr6.eq) goto loc_82521C28;
loc_82521C24:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82521C28:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82521c98
	if (ctx.cr0.eq) goto loc_82521C98;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82521c98
	if (!ctx.cr6.eq) goto loc_82521C98;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82521c98
	if (ctx.cr6.eq) goto loc_82521C98;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_82521C58:
	// beq 0x82521c98
	if (ctx.cr0.eq) goto loc_82521C98;
	// lbz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 348);
	// addi r31,r30,320
	ctx.r31.s64 = ctx.r30.s64 + 320;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82521c74
	if (ctx.cr0.eq) goto loc_82521C74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b44
	ctx.lr = 0x82521C74;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82521C74:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r3,r30,352
	ctx.r3.s64 = ctx.r30.s64 + 352;
	// addi r4,r11,16
	ctx.r4.s64 = ctx.r11.s64 + 16;
	// bl 0x82396cc8
	ctx.lr = 0x82521C84;
	sub_82396CC8(ctx, base);
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82521c98
	if (ctx.cr0.eq) goto loc_82521C98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b34
	ctx.lr = 0x82521C98;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82521C98:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252C400) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8252C408;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,288(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 288);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8252c47c
	if (ctx.cr0.eq) goto loc_8252C47C;
	// addi r31,r3,296
	ctx.r31.s64 = ctx.r3.s64 + 296;
	// li r29,4
	ctx.r29.s64 = 4;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
loc_8252C428:
	// lwz r10,-12816(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12816);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r9,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8252c464
	if (!ctx.cr6.eq) goto loc_8252C464;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252c464
	if (ctx.cr6.eq) goto loc_8252C464;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8252C464;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8252C464:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x8252c428
	if (!ctx.cr0.eq) goto loc_8252C428;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r28)
	REX_STORE_U8(ctx.r28.u32 + 23, ctx.r11.u8);
	// b 0x8252c498
	goto loc_8252C498;
loc_8252C47C:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r9,r28,296
	ctx.r9.s64 = ctx.r28.s64 + 296;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8252C490:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8252c490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8252C490;
loc_8252C498:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252FA08) {
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
	// lfs f0,-29492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82531768) {
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
	// bl 0x825317c0
	ctx.lr = 0x82531788;
	sub_825317C0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825317a0
	if (ctx.cr0.eq) goto loc_825317A0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825317a0
	if (ctx.cr6.eq) goto loc_825317A0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825317A0;
	sub_825E0378(ctx, base);
loc_825317A0:
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

DEFINE_REX_FUNC(sub_825344C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825344C8;
	__savegprlr_29(ctx, base);
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
	// addi r4,r10,-15368
	ctx.r4.s64 = ctx.r10.s64 + -15368;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,9
	ctx.r8.s64 = 9;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x825344FC;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,-288
	ctx.r11.s64 = ctx.r11.s64 + -288;
	// stb r10,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r10.u8);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x825a4640
	ctx.lr = 0x82534518;
	sub_825A4640(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825a48b0
	ctx.lr = 0x82534534;
	sub_825A48B0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addic r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// li r9,50
	ctx.r9.s64 = 50;
	// subfe r10,r10,r29
	temp.u8 = (~ctx.r10.u32 + ctx.r29.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r9,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r9.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r10.u8);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8253AF88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8253AF90;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,332(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,1472
	ctx.r10.s64 = ctx.r10.s64 + 1472;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8253afe0
	if (ctx.cr6.eq) goto loc_8253AFE0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8253AFC0;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8253afd8
	if (ctx.cr0.eq) goto loc_8253AFD8;
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8253AFD8;
	sub_82222BB0(ctx, base);
loc_8253AFD8:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
loc_8253AFE0:
	// lwz r3,336(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8253aff8
	if (ctx.cr6.eq) goto loc_8253AFF8;
	// bl 0x8221cc98
	ctx.lr = 0x8253AFF4;
	sub_8221CC98(ctx, base);
	// stw r28,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r28.u32);
loc_8253AFF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x8253B000;
	sub_82469FB0(ctx, base);
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// addi r30,r31,348
	ctx.r30.s64 = ctx.r31.s64 + 348;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r28,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r28.u32);
	// beq cr6,0x8253b040
	if (ctx.cr6.eq) goto loc_8253B040;
loc_8253B028:
	// lwz r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x8253B030;
	sub_825E0378(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8253b028
	if (!ctx.cr6.eq) goto loc_8253B028;
loc_8253B040:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8253b050
	if (ctx.cr6.eq) goto loc_8253B050;
	// bl 0x825e0378
	ctx.lr = 0x8253B050;
	sub_825E0378(ctx, base);
loc_8253B050:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x8253B068;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8253b078
	if (ctx.cr0.eq) goto loc_8253B078;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8253B078;
	sub_825E0378(ctx, base);
loc_8253B078:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82541928) {
	REX_FUNC_PROLOGUE();
	// b 0x82541970
	sub_82541970(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82541970) {
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
	// lwz r11,304(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82541a70
	if (ctx.cr6.eq) goto loc_82541A70;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82541a70
	if (ctx.cr6.eq) goto loc_82541A70;
	// ld r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// li r3,169
	ctx.r3.s64 = 169;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x825419D0;
	sub_82240A58(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vslw128 v61,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r9,32416
	ctx.r11.s64 = ctx.r9.s64 + 32416;
	// lfs f0,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vxor128 v62,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	ctx.r11.s64 = 0;
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,68(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stw r6,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r6.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
loc_82541A70:
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

DEFINE_REX_FUNC(sub_8254BB70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// lfs f13,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,-20(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f12,-4(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f12,-12(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
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

DEFINE_REX_FUNC(sub_82550FC0) {
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
	// addi r11,r11,5288
	ctx.r11.s64 = ctx.r11.s64 + 5288;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x82550FEC;
	sub_82469FB0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x82550FF4;
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
	ctx.lr = 0x82551008;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82551018
	if (ctx.cr0.eq) goto loc_82551018;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82551018;
	sub_825E0378(ctx, base);
loc_82551018:
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

DEFINE_REX_FUNC(sub_82553058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82553060;
	__savegprlr_28(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	ctx.lr = 0x82553084;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8255309C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f12,-11140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11140);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmuls f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r30,-13032(r6)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r6.u32 + -13032);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r5,2688
	ctx.r6.s64 = ctx.r5.s64 + 2688;
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r5,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r5.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r6,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v58,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// vsubfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// stfs f13,172(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stvx128 v59,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r11.u64);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// beq cr6,0x8255321c
	if (ctx.cr6.eq) goto loc_8255321C;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x82553218;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8255321C:
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
	// li r11,-1
	ctx.r11.s64 = -1;
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// beq cr6,0x82553268
	if (ctx.cr6.eq) goto loc_82553268;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r11,2880
	ctx.r10.s64 = ctx.r11.s64 + 2880;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x823b0938
	ctx.lr = 0x82553264;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82553268:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82564F98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82564FA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825651d0
	if (ctx.cr6.eq) goto loc_825651D0;
	// ld r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f12,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r30,348(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 348);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r29,r1,160
	ctx.r29.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r11,14376
	ctx.r9.s64 = ctx.r11.s64 + 14376;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,424(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
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
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f12,-2140(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2140);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x825650fc
	if (ctx.cr6.eq) goto loc_825650FC;
	// lfs f0,-1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_82565074:
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r6,12(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r5,4(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// stw r6,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// lbz r8,115(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 115);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r8.u8);
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r8,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r8.u32);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,348(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 348);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82565074
	if (!ctx.cr6.eq) goto loc_82565074;
loc_825650FC:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82565114
	if (ctx.cr6.eq) goto loc_82565114;
	// lfs f0,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82565118
	goto loc_82565118;
loc_82565114:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_82565118:
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fdivs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwa r9,84(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// lwz r11,-15432(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15432);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r10,-15444(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15444);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lwa r10,100(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 100));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// lfd f10,80(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmsubs f2,f13,f0,f10
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, -ctx.f10.f64)));
	// fnmsubs f1,f12,f0,f11
	ctx.f1.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f11.f64)));
	// bl 0x8254f4d0
	ctx.lr = 0x825651B0;
	sub_8254F4D0(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x825651C0;
	sub_8273A030(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x825651D0;
	sub_82459D08(ctx, base);
loc_825651D0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825764E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-16508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16508);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82576570
	if (!ctx.cr6.eq) goto loc_82576570;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,12708
	ctx.r4.s64 = ctx.r11.s64 + 12708;
	// bl 0x827396b0
	ctx.lr = 0x8257651C;
	sub_827396B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825765d0
	if (!ctx.cr0.eq) goto loc_825765D0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,12656
	ctx.r4.s64 = ctx.r11.s64 + 12656;
	// bl 0x82738a28
	ctx.lr = 0x82576534;
	sub_82738A28(ctx, base);
	// addi r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 3;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8257653C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8257653c
	if (!ctx.cr6.eq) goto loc_8257653C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82576550:
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
	// bne cr6,0x82576550
	if (!ctx.cr6.eq) goto loc_82576550;
loc_82576568:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// b 0x825765d4
	goto loc_825765D4;
loc_82576570:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,12704
	ctx.r4.s64 = ctx.r11.s64 + 12704;
	// bl 0x827396b0
	ctx.lr = 0x82576580;
	sub_827396B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825765d0
	if (!ctx.cr0.eq) goto loc_825765D0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,12676
	ctx.r4.s64 = ctx.r11.s64 + 12676;
	// bl 0x82738a28
	ctx.lr = 0x82576598;
	sub_82738A28(ctx, base);
	// addi r10,r31,2
	ctx.r10.s64 = ctx.r31.s64 + 2;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_825765A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825765a0
	if (!ctx.cr6.eq) goto loc_825765A0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_825765B4:
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
	// bne cr6,0x825765b4
	if (!ctx.cr6.eq) goto loc_825765B4;
	// b 0x82576568
	goto loc_82576568;
loc_825765D0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825765D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82576350
	ctx.lr = 0x825765DC;
	sub_82576350(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8257C4F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8257C4F8;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af28
	ctx.lr = 0x8257C500;
	__savefpr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// fmr f29,f2
	ctx.f29.f64 = ctx.f2.f64;
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,-12852(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -12852);
	// lfs f30,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f2,f30
	ctx.cr6.compare(ctx.f2.f64, ctx.f30.f64);
	// bne cr6,0x8257c570
	if (!ctx.cr6.eq) goto loc_8257C570;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8257c3f0
	ctx.lr = 0x8257C534;
	sub_8257C3F0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257c54c
	if (ctx.cr6.eq) goto loc_8257C54C;
	// lfs f1,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8257c550
	goto loc_8257C550;
loc_8257C54C:
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
loc_8257C550:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257c728
	ctx.lr = 0x8257C55C;
	sub_8257C728(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257c278
	ctx.lr = 0x8257C564;
	sub_8257C278(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257cce0
	ctx.lr = 0x8257C56C;
	sub_8257CCE0(ctx, base);
	// b 0x8257c714
	goto loc_8257C714;
loc_8257C570:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r10.u8);
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257c590
	if (ctx.cr6.eq) goto loc_8257C590;
	// lfs f28,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f28.f64 = double(temp.f32);
	// b 0x8257c594
	goto loc_8257C594;
loc_8257C590:
	// lfs f28,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
loc_8257C594:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// bne cr6,0x8257c5ac
	if (!ctx.cr6.eq) goto loc_8257C5AC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r11.u8);
	// bl 0x8257cb10
	ctx.lr = 0x8257C5A8;
	sub_8257CB10(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_8257C5AC:
	// fsubs f0,f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f28.f64));
	// stfs f31,28(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fdivs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f29.f64));
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x8257c5d0
	if (ctx.cr6.gt) goto loc_8257C5D0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8257C5D0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,17(r31)
	REX_STORE_U8(ctx.r31.u32 + 17, ctx.r11.u8);
	// bne 0x8257c5e4
	if (!ctx.cr0.eq) goto loc_8257C5E4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257cce0
	ctx.lr = 0x8257C5E4;
	sub_8257CCE0(ctx, base);
loc_8257C5E4:
	// lbz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 16);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8257c600
	if (ctx.cr0.eq) goto loc_8257C600;
	// bl 0x8257cbf0
	ctx.lr = 0x8257C5FC;
	sub_8257CBF0(ctx, base);
	// b 0x8257c608
	goto loc_8257C608;
loc_8257C600:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8257c728
	ctx.lr = 0x8257C608;
	sub_8257C728(ctx, base);
loc_8257C608:
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// std r11,20(r31)
	REX_STORE_U64(ctx.r31.u32 + 20, ctx.r11.u64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8257c2e8
	ctx.lr = 0x8257C61C;
	sub_8257C2E8(ctx, base);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f29,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f29,120(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f29,116(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f29,112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x8257C63C;
	sub_82322D08(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r9,432
	ctx.r9.s64 = 432;
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vrefp128 v0,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v7,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v5,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v9,v63,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vcmpeqfp128 v3,v63,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vnmsubfp v1,v7,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vnmsubfp v6,v5,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vcmpeqfp128 v11,v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vcmpeqfp128 v2,v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v0,v1,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v6,v0,v6,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v4,v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v2,v3,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8))));
	// vnmsubfp v5,v8,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v13,v10,v6,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v11,v7,v5,v7
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v13,v6,v13,v6
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v10,v11,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v12,v13,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v62,v62,v10
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v63,v63,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// std r11,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r11.u64);
loc_8257C714:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af74
	ctx.lr = 0x8257C720;
	__restfpr_28(ctx, base);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82592880) {
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
	// bl 0x82591b08
	ctx.lr = 0x82592894;
	sub_82591B08(ctx, base);
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

DEFINE_REX_FUNC(sub_82592F18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82592F20;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af20
	ctx.lr = 0x82592F28;
	__savefpr_26(ctx, base);
	// addi r12,r1,-160
	ctx.r12.s64 = ctx.r1.s64 + -160;
	// bl 0x8273b364
	ctx.lr = 0x82592F30;
	__savevmx_122(ctx, base);
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,115(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 115);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82593e84
	if (ctx.cr0.eq) goto loc_82593E84;
	// lbz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 64);
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82592f64
	if (!ctx.cr0.eq) goto loc_82592F64;
	// bl 0x82594950
	ctx.lr = 0x82592F58;
	sub_82594950(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82592f64
	if (!ctx.cr0.eq) goto loc_82592F64;
	// stb r25,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r25.u8);
loc_82592F64:
	// lbz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 64);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82593e84
	if (ctx.cr0.eq) goto loc_82593E84;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r24,r11,14480
	ctx.r24.s64 = ctx.r11.s64 + 14480;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// li r23,0
	ctx.r23.s64 = 0;
	// lfs f26,-2244(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2244);
	ctx.f26.f64 = double(temp.f32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r22,r10,-11120
	ctx.r22.s64 = ctx.r10.s64 + -11120;
	// addi r20,r9,2464
	ctx.r20.s64 = ctx.r9.s64 + 2464;
	// addi r19,r8,-15476
	ctx.r19.s64 = ctx.r8.s64 + -15476;
	// addi r21,r7,-4080
	ctx.r21.s64 = ctx.r7.s64 + -4080;
	// blt cr6,0x82593424
	if (ctx.cr6.lt) goto loc_82593424;
	// beq cr6,0x82593418
	if (ctx.cr6.eq) goto loc_82593418;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x825933e8
	if (ctx.cr6.lt) goto loc_825933E8;
	// beq cr6,0x8259313c
	if (ctx.cr6.eq) goto loc_8259313C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82592fe0
	if (ctx.cr6.lt) goto loc_82592FE0;
	// bne cr6,0x82593700
	if (!ctx.cr6.eq) goto loc_82593700;
	// bl 0x82576260
	ctx.lr = 0x82592FCC;
	sub_82576260(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82593e84
	if (!ctx.cr0.eq) goto loc_82593E84;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,115(r31)
	REX_STORE_U8(ctx.r31.u32 + 115, ctx.r11.u8);
	// b 0x82593e84
	goto loc_82593E84;
loc_82592FE0:
	// lbz r11,65(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82592ffc
	if (ctx.cr0.eq) goto loc_82592FFC;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// li r30,23
	ctx.r30.s64 = 23;
	// li r28,84
	ctx.r28.s64 = 84;
	// b 0x82593008
	goto loc_82593008;
loc_82592FFC:
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// li r30,17
	ctx.r30.s64 = 17;
	// li r28,19
	ctx.r28.s64 = 19;
loc_82593008:
	// lfs f31,-2012(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2012);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825930b8
	if (ctx.cr6.eq) goto loc_825930B8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8259302C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x82593064
	if (!ctx.cr6.eq) goto loc_82593064;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82593064
	if (!ctx.cr0.eq) goto loc_82593064;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// bl 0x8224a2a0
	ctx.lr = 0x82593064;
	sub_8224A2A0(ctx, base);
loc_82593064:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x8259306C;
	sub_825A43F0(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82593090;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x825930b8
	if (!ctx.cr6.eq) goto loc_825930B8;
	// lfs f13,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15560(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 15560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825930b8
	if (!ctx.cr6.gt) goto loc_825930B8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r23,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r23.u32);
loc_825930B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x825930C0;
	sub_825A43F0(ctx, base);
	// lfs f13,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1764(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 1764);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f1,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f1.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82593700
	if (ctx.cr6.gt) goto loc_82593700;
	// stfs f31,68(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stb r25,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r25.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x825752c0
	ctx.lr = 0x825930EC;
	sub_825752C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82593134
	if (ctx.cr0.eq) goto loc_82593134;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x825752c0
	ctx.lr = 0x82593100;
	sub_825752C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82593134
	if (ctx.cr0.eq) goto loc_82593134;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x825752c0
	ctx.lr = 0x82593114;
	sub_825752C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82593134
	if (ctx.cr0.eq) goto loc_82593134;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x825752c0
	ctx.lr = 0x82593128;
	sub_825752C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82593134
	if (ctx.cr0.eq) goto loc_82593134;
	// bl 0x825753b0
	ctx.lr = 0x82593134;
	sub_825753B0(ctx, base);
loc_82593134:
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8259341c
	goto loc_8259341C;
loc_8259313C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x82593144;
	sub_825A43F0(ctx, base);
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,65(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8259316c
	if (ctx.cr0.eq) goto loc_8259316C;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// li r30,23
	ctx.r30.s64 = 23;
	// li r28,84
	ctx.r28.s64 = 84;
	// b 0x82593178
	goto loc_82593178;
loc_8259316C:
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// li r30,17
	ctx.r30.s64 = 17;
	// li r28,19
	ctx.r28.s64 = 19;
loc_82593178:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82593364
	if (ctx.cr6.lt) goto loc_82593364;
	// beq cr6,0x82593294
	if (ctx.cr6.eq) goto loc_82593294;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x825931f4
	if (ctx.cr6.lt) goto loc_825931F4;
	// bne cr6,0x825933d4
	if (!ctx.cr6.eq) goto loc_825933D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x8259319C;
	sub_825A43F0(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825933d4
	if (ctx.cr6.eq) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825931C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// bne cr6,0x825933d4
	if (!ctx.cr6.eq) goto loc_825933D4;
	// lfs f13,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15560(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 15560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825933d4
	if (!ctx.cr6.gt) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r23,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r23.u32);
	// b 0x825933c8
	goto loc_825933C8;
loc_825931F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x825931FC;
	sub_825A43F0(ctx, base);
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// lfs f31,-2012(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2012);
	ctx.f31.f64 = double(temp.f32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82593234
	if (ctx.cr6.eq) goto loc_82593234;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-16508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16508);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8259322c
	if (!ctx.cr6.eq) goto loc_8259322C;
	// lfs f0,0(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82593238
	goto loc_82593238;
loc_8259322C:
	// lfs f0,-9776(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + -9776);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82593238
	goto loc_82593238;
loc_82593234:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82593238:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825933d4
	if (ctx.cr6.lt) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// clrlwi r4,r28,16
	ctx.r4.u64 = ctx.r28.u32 & 0xFFFF;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// beq cr6,0x82593274
	if (ctx.cr6.eq) goto loc_82593274;
	// li r5,1
	ctx.r5.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8224a2a0
	ctx.lr = 0x82593268;
	sub_8224A2A0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,15224
	ctx.r3.s64 = ctx.r11.s64 + 15224;
	// b 0x82593288
	goto loc_82593288;
loc_82593274:
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,30856(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 30856);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x82593280;
	sub_8224A2A0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,15236
	ctx.r3.s64 = ctx.r11.s64 + 15236;
loc_82593288:
	// bl 0x825764e8
	ctx.lr = 0x8259328C;
	sub_825764E8(ctx, base);
	// stfs f31,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// b 0x825933c8
	goto loc_825933C8;
loc_82593294:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x8259329C;
	sub_825A43F0(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8259330c
	if (ctx.cr6.eq) goto loc_8259330C;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825932C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x825933d4
	if (!ctx.cr6.eq) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x825933d4
	if (!ctx.cr0.eq) goto loc_825933D4;
loc_825932E8:
	// lfs f1,-2012(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2012);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// stfs f1,44(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x82593308;
	sub_8224A2A0(ctx, base);
	// b 0x825933c8
	goto loc_825933C8;
loc_8259330C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-16508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16508);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82593324
	if (!ctx.cr6.eq) goto loc_82593324;
	// lfs f31,15520(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 15520);
	ctx.f31.f64 = double(temp.f32);
	// b 0x8259332c
	goto loc_8259332C;
loc_82593324:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f31,25012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25012);
	ctx.f31.f64 = double(temp.f32);
loc_8259332C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82593344;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x825933d4
	if (!ctx.cr6.eq) goto loc_825933D4;
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x825933d4
	if (ctx.cr6.lt) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// b 0x825932e8
	goto loc_825932E8;
loc_82593364:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x8259336C;
	sub_825A43F0(ctx, base);
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// blt cr6,0x825933d4
	if (ctx.cr6.lt) goto loc_825933D4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-2012(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2012);
	ctx.f1.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r4,r30,16
	ctx.r4.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x825933A0;
	sub_8224A2A0(ctx, base);
	// lbz r11,65(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// stfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825933bc
	if (ctx.cr0.eq) goto loc_825933BC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,15200
	ctx.r3.s64 = ctx.r11.s64 + 15200;
	// b 0x825933c4
	goto loc_825933C4;
loc_825933BC:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,15212
	ctx.r3.s64 = ctx.r11.s64 + 15212;
loc_825933C4:
	// bl 0x825764e8
	ctx.lr = 0x825933C8;
	sub_825764E8(ctx, base);
loc_825933C8:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_825933D4:
	// lbz r11,117(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 117);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82593700
	if (ctx.cr0.eq) goto loc_82593700;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8259341c
	goto loc_8259341C;
loc_825933E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a43f0
	ctx.lr = 0x825933F0;
	sub_825A43F0(ctx, base);
	// lfs f13,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1764(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 1764);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f0,5620(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 5620);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82593700
	if (ctx.cr6.lt) goto loc_82593700;
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8259341c
	goto loc_8259341C;
loc_82593418:
	// li r11,2
	ctx.r11.s64 = 2;
loc_8259341C:
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// b 0x82593700
	goto loc_82593700;
loc_82593424:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
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
	// beq cr6,0x8259345c
	if (ctx.cr6.eq) goto loc_8259345C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8259345c
	if (ctx.cr6.eq) goto loc_8259345C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bne cr6,0x82593460
	if (!ctx.cr6.eq) goto loc_82593460;
loc_8259345C:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_82593460:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82593700
	if (!ctx.cr0.eq) goto loc_82593700;
	// lwz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x8259be58
	ctx.lr = 0x82593470;
	sub_8259BE58(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x82593478;
	sub_825FA250(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r25,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r25,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x825934A0;
	sub_825F9CF8(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x8259be58
	ctx.lr = 0x825934A8;
	sub_8259BE58(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x825934B0;
	sub_825FA250(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r25,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r25,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x825934D8;
	sub_825F9CF8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,-30272
	ctx.r11.s64 = ctx.r11.s64 + -30272;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,-30288
	ctx.r8.s64 = ctx.r8.s64 + -30288;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r4,r1,168
	ctx.r4.s64 = ctx.r1.s64 + 168;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8259352C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,4708(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 4708);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82593548;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,65(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8259355c
	if (ctx.cr0.eq) goto loc_8259355C;
	// lfs f13,1768(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 1768);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82593560
	goto loc_82593560;
loc_8259355C:
	// lfs f13,-2012(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -2012);
	ctx.f13.f64 = double(temp.f32);
loc_82593560:
	// lfs f0,340(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r11,-30304
	ctx.r11.s64 = ctx.r11.s64 + -30304;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825935C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f1,4708(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 4708);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825935E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
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
	ctx.lr = 0x82593600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f31,-200(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -200);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// li r30,8
	ctx.r30.s64 = 8;
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
	// lis r26,-32114
	ctx.r26.s64 = -2104623104;
loc_82593618:
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// lfs f0,8456(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8456);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lfs f0,8464(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8464);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f13,8460(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8460);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwzx r3,r7,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfs f11,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825936A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x825936B8;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r7,1
	ctx.r7.s64 = 1;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r6,1
	ctx.r6.s64 = 1;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x8224a2a0
	ctx.lr = 0x825936EC;
	sub_8224A2A0(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r30,28
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 28, ctx.xer);
	// blt cr6,0x82593618
	if (ctx.cr6.lt) goto loc_82593618;
	// stw r25,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r25.u32);
loc_82593700:
	// lbz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 116);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82593e84
	if (!ctx.cr0.eq) goto loc_82593E84;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259378c
	if (ctx.cr0.eq) goto loc_8259378C;
	// li r11,255
	ctx.r11.s64 = 255;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// stb r11,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r11.u8);
	// stb r11,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r11.u8);
loc_8259373C:
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lbz r10,151(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 151);
	// stb r10,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x8259376C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8259373c
	if (ctx.cr6.lt) goto loc_8259373C;
loc_8259378C:
	// lfs f27,29780(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 29780);
	ctx.f27.f64 = double(temp.f32);
	// stb r23,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r23.u8);
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// stb r23,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r23.u8);
	// addi r29,r31,72
	ctx.r29.s64 = ctx.r31.s64 + 72;
	// stb r23,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r23.u8);
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// lis r26,-32111
	ctx.r26.s64 = -2104426496;
loc_825937AC:
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lfs f13,1728(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 1728);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-572(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -572);
	ctx.f12.f64 = double(temp.f32);
	// fadds f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lbz r11,151(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 151);
	// stb r11,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// bl 0x825975c8
	ctx.lr = 0x825937D4;
	sub_825975C8(ctx, base);
	// lwz r11,-13064(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -13064);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82593adc
	if (ctx.cr6.eq) goto loc_82593ADC;
	// li r11,980
	ctx.r11.s64 = 980;
	// lwz r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r6,-8
	ctx.r6.s64 = -8;
	// fmr f3,f26
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f26.f64;
	// sth r11,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// bl 0x8235ddb8
	ctx.lr = 0x82593808;
	sub_8235DDB8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82593adc
	if (ctx.cr0.eq) goto loc_82593ADC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x82593820;
	sub_82459D08(ctx, base);
	// vspltisw128 v123,0
	simde_mm_store_si128((simde__m128i*)ctx.v123.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f1,-880(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -880);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vupkd3d128 v122,v123,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v123.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v123.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v122 = vTemp;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// vpermwi128 v127,v122,234
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x15));
	// vpermwi128 v126,v122,186
	simde_mm_store_si128((simde__m128i*)ctx.v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x45));
	// vpermwi128 v125,v122,174
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x51));
	// vpermwi128 v124,v122,171
	simde_mm_store_si128((simde__m128i*)ctx.v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x54));
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823c96b0
	ctx.lr = 0x82593864;
	sub_823C96B0(ctx, base);
	// li r11,-2244
	ctx.r11.s64 = -2244;
	// vpermwi128 v62,v122,171
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x54));
	// extsw r9,r28
	ctx.r9.s64 = ctx.r28.s32;
	// vor128 v63,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v123.u8));
	// li r10,29780
	ctx.r10.s64 = 29780;
	// vor128 v61,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v123.u8));
	// std r9,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lfs f13,4012(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 4012);
	ctx.f13.f64 = double(temp.f32);
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lfs f12,28212(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 28212);
	ctx.f12.f64 = double(temp.f32);
	// lvlx128 v60,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v63,v60,2,2
	simde_mm_store_ps(ctx.v63.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 78), 2));
	// vmulfp128 v11,v59,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v127.f32)));
	// lvlx128 v60,r22,r10
	temp.u32 = ctx.r22.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vrlimi128 v61,v60,4,3
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 57), 4));
	// vmulfp128 v9,v59,v127
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v12,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// vspltw128 v10,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vrlimi128 v60,v123,7,0
	simde_mm_store_ps(ctx.v60.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v123.f32), 228), 7));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v7,v58,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v6,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vmaddcfp128 v12,v126,v12,v11
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vor128 v11,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v126.u8));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// vspltw128 v3,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// stfs f26,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vspltw128 v5,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// stfs f26,124(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vmulfp128 v4,v59,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vpermwi128 v0,v122,174
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x51));
	// vpermwi128 v13,v122,186
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x45));
	// vmaddcfp128 v11,v10,v11,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vor128 v10,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v126.u8));
	// frsp f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// lfs f0,-304(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vspltw128 v31,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vor128 v9,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// vmaddcfp128 v10,v8,v10,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor128 v8,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// vpermwi128 v59,v122,234
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x15));
	// vor128 v7,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// vspltw128 v29,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vspltw128 v30,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddcfp128 v8,v6,v8,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v12,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v126.u8));
	// vor128 v6,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// fmadds f0,f11,f13,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vmaddfp128 v11,v3,v125,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v125.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddcfp128 v12,v5,v12,v4
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp128 v10,v2,v125,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v125.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddcfp128 v9,v1,v9,v12
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v12,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v124.u8));
	// vmaddcfp128 v7,v30,v7,v10
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v5,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// vmaddcfp128 v12,v31,v12,v11
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// vmaddfp128 v8,v5,v124,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v124.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// li r5,64
	ctx.r5.s64 = 64;
	// lvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddcfp128 v6,v29,v6,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// vor128 v58,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v30,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v7,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v27,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v62,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// vspltw128 v61,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xFF));
	// vspltw128 v4,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xAA));
	// vspltw v2,v8,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xAA));
	// vmulfp128 v5,v62,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v62,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v6.u8));
	// vmulfp128 v1,v61,v63
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw v28,v8,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x55));
	// vspltw v25,v8,3
	simde_mm_store_si128((simde__m128i*)ctx.v25.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x0));
	// vmulfp128 v6,v60,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v3,v58,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x55));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v31,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0x0));
	// vspltw128 v29,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v26,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vmaddfp v8,v4,v12,v5
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v5,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v4,v61,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v7,v7,v12,v6
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v8,v3,v11,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v6,v5,v12,v4
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v12,v2,v12,v1
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v7,v30,v11,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v8,v31,v10,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v6,v29,v11,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v12,v28,v11,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v27,v10,v7
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor128 v63,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vmaddfp v8,v26,v10,v6
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v26.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v12,v25,v10,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v25.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v62,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v7,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vspltw128 v5,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v29,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vmulfp128 v10,v61,v59
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v4,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v28,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vmulfp128 v3,v60,v59
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vor128 v63,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vspltw128 v60,v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xFF));
	// vspltw v31,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xAA));
	// vspltw v8,v12,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x55));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v2,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v30,v60,v59
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vspltw128 v11,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vmaddfp v6,v7,v13,v10
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v7,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vmulfp128 v1,v61,v59
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vspltw v12,v12,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x0));
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vmaddfp v6,v5,v0,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v5,v4,v13,v3
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v4,v2,v13,v1
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v3,v31,v13,v30
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vmaddfp v5,v28,v0,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vmaddfp v13,v7,v0,v4
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// vmaddfp v6,v29,v9,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// vmaddfp v0,v8,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v10,v10,v9,v5
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v13,v11,v9,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v6,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x82593ADC;
	sub_8273A030(ctx, base);
loc_82593ADC:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// blt cr6,0x825937ac
	if (ctx.cr6.lt) goto loc_825937AC;
	// lfs f31,1772(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 1772);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lfs f29,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,0(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f28,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
loc_82593B00:
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x82593b14
	if (!ctx.cr6.eq) goto loc_82593B14;
	// lbz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82593e78
	if (ctx.cr0.eq) goto loc_82593E78;
loc_82593B14:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x82593b28
	if (!ctx.cr6.eq) goto loc_82593B28;
	// lbz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82593e78
	if (ctx.cr0.eq) goto loc_82593E78;
loc_82593B28:
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x82593b3c
	if (!ctx.cr6.eq) goto loc_82593B3C;
	// lbz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82593e78
	if (!ctx.cr0.eq) goto loc_82593E78;
loc_82593B3C:
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,1728(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 1728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-572(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -572);
	ctx.f13.f64 = double(temp.f32);
	// stb r23,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r23.u8);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stb r23,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r23.u8);
	// stb r23,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r23.u8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lbz r11,135(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 135);
	// stb r11,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// bl 0x825975c8
	ctx.lr = 0x82593B78;
	sub_825975C8(ctx, base);
	// lwz r11,-13064(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -13064);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82593b90
	if (!ctx.cr6.eq) goto loc_82593B90;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// b 0x82593bb4
	goto loc_82593BB4;
loc_82593B90:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r23,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmr f3,f26
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f26.f64;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// bl 0x8235ddb8
	ctx.lr = 0x82593BB0;
	sub_8235DDB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82593BB4:
	// stfs f31,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f29,180(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f30,188(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f28,192(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f31,200(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f30,204(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// beq cr6,0x82593e78
	if (ctx.cr6.eq) goto loc_82593E78;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x82593BEC;
	sub_82459D08(ctx, base);
	// vspltisw128 v123,0
	simde_mm_store_si128((simde__m128i*)ctx.v123.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// lfs f1,-880(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -880);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// vupkd3d128 v122,v123,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v123.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v123.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v122 = vTemp;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// vpermwi128 v127,v122,234
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x15));
	// vpermwi128 v126,v122,186
	simde_mm_store_si128((simde__m128i*)ctx.v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x45));
	// vpermwi128 v125,v122,174
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x51));
	// vpermwi128 v124,v122,171
	simde_mm_store_si128((simde__m128i*)ctx.v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x54));
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823c96b0
	ctx.lr = 0x82593C30;
	sub_823C96B0(ctx, base);
	// vpermwi128 v62,v122,171
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x54));
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// vor128 v63,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v123.u8));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f26,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r8,-2244
	ctx.r8.s64 = -2244;
	// stfs f26,124(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// li r7,29780
	ctx.r7.s64 = 29780;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// lfsx f0,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v12,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vor128 v30,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_load_si128((simde__m128i*)ctx.v125.u8));
	// lfsx f0,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v11,v60,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vspltw128 v4,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// lvlx128 v59,r24,r8
	temp.u32 = ctx.r24.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v123,v59,2,2
	simde_mm_store_ps(ctx.v123.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v123.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v59.f32), 78), 2));
	// lvlx128 v60,r22,r7
	temp.u32 = ctx.r22.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v61,v60,4,3
	simde_mm_store_ps(ctx.v61.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v60.f32), 57), 4));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vmaddfp128 v11,v10,v126,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v59,v123,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xFF));
	// vrlimi128 v60,v63,7,0
	simde_mm_store_ps(ctx.v60.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v63.f32), 228), 7));
	// vspltw128 v2,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// vspltw128 v31,v123,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0xAA));
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// vmulfp128 v3,v58,v127
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v8,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vmulfp128 v1,v59,v127
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v63,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v7,v123,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x55));
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// vspltw128 v5,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// vspltw128 v10,v123,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v123.u32), 0x0));
	// vmulfp128 v6,v63,v127
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// vspltw128 v9,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v0,v122,174
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x51));
	// vpermwi128 v13,v122,186
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x45));
	// vmaddcfp128 v30,v12,v30,v11
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v30.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vpermwi128 v62,v122,234
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v122.u32), 0x15));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp128 v3,v2,v126,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp128 v1,v31,v126,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp128 v6,v5,v126,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v126.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddcfp128 v4,v124,v4,v30
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v124.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddcfp128 v8,v125,v8,v3
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddcfp128 v7,v125,v7,v1
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddcfp128 v9,v125,v9,v6
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v125.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v61,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v4.u8));
	// vmaddcfp128 v11,v124,v11,v8
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v124.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddcfp128 v10,v124,v10,v7
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v124.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddcfp128 v12,v124,v12,v9
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v124.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v30,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v4,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vspltw128 v8,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vor128 v61,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vmulfp128 v31,v60,v63
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v60,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// lvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// lvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// vspltw128 v28,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// lvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// li r5,64
	ctx.r5.s64 = 64;
	// vspltw128 v3,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vor128 v61,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vspltw128 v24,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmulfp128 v29,v59,v63
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v5,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v25,v58,v63
	simde_mm_store_ps(ctx.v25.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v26,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v6,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmulfp128 v27,v60,v63
	simde_mm_store_ps(ctx.v27.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v29,v28,v12,v29
	simde_mm_store_ps(ctx.v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v25,v24,v12,v25
	simde_mm_store_ps(ctx.v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v24.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v25.f32)));
	// vmaddfp v27,v26,v12,v27
	simde_mm_store_ps(ctx.v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v26.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v27.f32)));
	// vmaddfp v12,v30,v12,v31
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v3,v3,v11,v29
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v1,v1,v11,v25
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v25.f32)));
	// vmaddfp v2,v2,v11,v27
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v27.f32)));
	// vmaddfp v12,v4,v11,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v7,v10,v3
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v5,v5,v10,v1
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v6,v6,v10,v2
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v12,v8,v10,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v61,v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xFF));
	// vspltw v31,v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xAA));
	// vspltw128 v63,v5,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), 0xFF));
	// vspltw v27,v5,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), 0xAA));
	// vmulfp128 v1,v61,v62
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw v4,v5,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), 0x55));
	// vspltw v8,v5,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v5.u32), 0x0));
	// vmulfp128 v28,v63,v62
	simde_mm_store_ps(ctx.v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v63,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v6.u8));
	// vspltw v6,v11,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x55));
	// vspltw128 v60,v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xFF));
	// vspltw v2,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xAA));
	// vspltw v7,v12,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x55));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vmulfp128 v3,v60,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw128 v29,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vspltw128 v5,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw v11,v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x0));
	// vmulfp128 v30,v61,v62
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw128 v10,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vmaddfp v1,v31,v13,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vspltw v12,v12,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x0));
	// vmaddfp v28,v27,v13,v28
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// vmaddfp v3,v2,v13,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v30,v29,v13,v30
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v13,v6,v0,v1
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v4,v4,v0,v28
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// vmaddfp v5,v5,v0,v30
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v0,v7,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v13,v11,v9,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v8,v8,v9,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v10,v10,v9,v5
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v0,v12,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v8,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x82593E78;
	sub_8273A030(ctx, base);
loc_82593E78:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// blt cr6,0x82593b00
	if (ctx.cr6.lt) goto loc_82593B00;
loc_82593E84:
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// addi r12,r1,-160
	ctx.r12.s64 = ctx.r1.s64 + -160;
	// bl 0x8273b5fc
	ctx.lr = 0x82593E90;
	__restvmx_122(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af6c
	ctx.lr = 0x82593E98;
	__restfpr_26(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263F170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8263F178;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// rlwinm r29,r11,16,16,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF;
	// li r27,64
	ctx.r27.s64 = 64;
	// rlwinm r10,r29,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 16) & 0xFFFF0000;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
loc_8263F1A4:
	// addi r10,r30,24
	ctx.r10.s64 = ctx.r30.s64 + 24;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// beq cr6,0x8263f228
	if (ctx.cr6.eq) goto loc_8263F228;
	// lwz r11,48(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 48);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8263f238
	if (ctx.cr6.gt) goto loc_8263F238;
	// lwz r11,28(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8263f238
	if (ctx.cr6.gt) goto loc_8263F238;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8263e210
	ctx.lr = 0x8263F1E8;
	sub_8263E210(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x8263f238
	if (ctx.cr0.eq) goto loc_8263F238;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bl 0x8263e4a0
	ctx.lr = 0x8263F20C;
	sub_8263E4A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263e8a8
	ctx.lr = 0x8263F220;
	sub_8263E8A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8263f3a4
	goto loc_8263F3A4;
loc_8263F228:
	// clrlwi r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// bne cr6,0x8263f238
	if (!ctx.cr6.eq) goto loc_8263F238;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_8263F238:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// blt cr6,0x8263f1a4
	if (ctx.cr6.lt) goto loc_8263F1A4;
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// beq cr6,0x8263f3a0
	if (ctx.cr6.eq) goto loc_8263F3A0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8263f3a0
	if (ctx.cr0.eq) goto loc_8263F3A0;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addis r30,r28,1
	ctx.r30.s64 = ctx.r28.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bgt cr6,0x8263f284
	if (ctx.cr6.gt) goto loc_8263F284;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_8263F284:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// lwz r7,1424(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1424);
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82855be4
	ctx.lr = 0x8263F2A0;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8263f2f4
	if (!ctx.cr0.lt) goto loc_8263F2F4;
loc_8263F2A8:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8263f2ec
	if (ctx.cr6.eq) goto loc_8263F2EC;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8263f2c8
	if (!ctx.cr6.lt) goto loc_8263F2C8;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
loc_8263F2C8:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// lwz r7,1424(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1424);
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82855be4
	ctx.lr = 0x8263F2E4;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8263f2a8
	if (ctx.cr0.lt) goto loc_8263F2A8;
loc_8263F2EC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8263f3a0
	if (ctx.cr6.lt) goto loc_8263F3A0;
loc_8263F2F4:
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bgt cr6,0x8263f318
	if (ctx.cr6.gt) goto loc_8263F318;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
loc_8263F318:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// lwz r7,1424(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1424);
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82855be4
	ctx.lr = 0x8263F334;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8263f388
	if (ctx.cr0.lt) goto loc_8263F388;
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x8263f008
	ctx.lr = 0x8263F364;
	sub_8263F008(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8263f374
	if (!ctx.cr0.eq) goto loc_8263F374;
	// lis r30,-16384
	ctx.r30.s64 = -1073741824;
	// ori r30,r30,23
	ctx.r30.u64 = ctx.r30.u64 | 23;
loc_8263F374:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8263f388
	if (ctx.cr6.lt) goto loc_8263F388;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// b 0x8263f3a4
	goto loc_8263F3A4;
loc_8263F388:
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r6,1424(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1424);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82855bf4
	ctx.lr = 0x8263F3A0;
	__imp__NtFreeVirtualMemory(ctx, base);
loc_8263F3A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8263F3A4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264C878) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x82653758
	sub_82653758(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264CB30) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x82654498
	sub_82654498(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264CB68) {
	REX_FUNC_PROLOGUE();
	// lwz r3,136(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8264CD18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8264CD20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r31,r3,28
	ctx.r31.s64 = ctx.r3.s64 + 28;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264CD44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,380(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 380);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8264cd60
	if (!ctx.cr6.eq) goto loc_8264CD60;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8264CD60:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264CD74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264ED18) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-36
	ctx.r3.s64 = ctx.r3.s64 + -36;
	// b 0x8264eb20
	sub_8264EB20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264F300) {
	REX_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8264F540) {
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
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,7660
	ctx.r10.s64 = ctx.r11.s64 + 7660;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
loc_8264F564:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8264f584
	if (!ctx.cr0.eq) goto loc_8264F584;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8264f564
	if (!ctx.cr6.eq) goto loc_8264F564;
loc_8264F584:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8264f5b4
	if (!ctx.cr0.eq) goto loc_8264F5B4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// bne cr6,0x8264f59c
	if (!ctx.cr6.eq) goto loc_8264F59C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8264F59C:
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264F5B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8264f5bc
	goto loc_8264F5BC;
loc_8264F5B4:
	// bl 0x8264e8b0
	ctx.lr = 0x8264F5B8;
	sub_8264E8B0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8264F5BC:
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

DEFINE_REX_FUNC(sub_826539E0) {
	REX_FUNC_PROLOGUE();
	// lwz r10,28(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82653a34
	if (ctx.cr6.eq) goto loc_82653A34;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// beq cr6,0x82653a10
	if (ctx.cr6.eq) goto loc_82653A10;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// b 0x82653a18
	goto loc_82653A18;
loc_82653A10:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
loc_82653A18:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
loc_82653A34:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826571C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x826571C8;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af24
	ctx.lr = 0x826571D0;
	__savefpr_27(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,352(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 352);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r19,360(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r31,384(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 384);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r23,34(r11)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r11.u32 + 34);
	// beq cr6,0x82657814
	if (ctx.cr6.eq) goto loc_82657814;
	// lwz r11,424(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265720c
	if (ctx.cr6.eq) goto loc_8265720C;
	// li r19,6
	ctx.r19.s64 = 6;
loc_8265720C:
	// cmpwi cr6,r23,6
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 6, ctx.xer);
	// bne cr6,0x82657444
	if (!ctx.cr6.eq) goto loc_82657444;
	// cmpwi cr6,r19,2
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 2, ctx.xer);
	// bne cr6,0x82657444
	if (!ctx.cr6.eq) goto loc_82657444;
	// lwz r11,372(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,12(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,16(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,20(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// blt cr6,0x826573c4
	if (ctx.cr6.lt) goto loc_826573C4;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82657278:
	// lfs f2,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f10
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// lfs f31,20(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f2,f2,f4
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f4.f64));
	// lfs f30,12(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f1,f31,f9,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f9.f64, ctx.f1.f64)));
	// fmadds f2,f31,f3,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f3.f64, ctx.f2.f64)));
	// fmadds f1,f30,f11,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f30.f64, ctx.f11.f64, ctx.f1.f64)));
	// fmadds f2,f30,f5,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f30.f64, ctx.f5.f64, ctx.f2.f64)));
	// fmadds f1,f29,f12,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f29.f64, ctx.f12.f64, ctx.f1.f64)));
	// fmadds f2,f29,f6,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f29.f64, ctx.f6.f64, ctx.f2.f64)));
	// fmadds f1,f28,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f28.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f2,f28,f7,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f28.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f1,f27,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f27.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,0(r28)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// fmadds f2,f27,f8,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f8.f64, ctx.f2.f64)));
	// stfs f2,4(r28)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// lfs f1,44(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,36(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,32(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,40(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f29,f30,f10
	ctx.f29.f64 = double(float(ctx.f30.f64 * ctx.f10.f64));
	// fmuls f30,f30,f4
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f4.f64));
	// lfs f28,24(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 24);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f29,f1,f9,f29
	ctx.f29.f64 = double(float(std::fma(ctx.f1.f64, ctx.f9.f64, ctx.f29.f64)));
	// lfs f27,28(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 28);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f1,f1,f3,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f3.f64, ctx.f30.f64)));
	// fmadds f30,f2,f11,f29
	ctx.f30.f64 = double(float(std::fma(ctx.f2.f64, ctx.f11.f64, ctx.f29.f64)));
	// fmadds f2,f2,f5,f1
	ctx.f2.f64 = double(float(std::fma(ctx.f2.f64, ctx.f5.f64, ctx.f1.f64)));
	// fmadds f1,f31,f12,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f30.f64)));
	// fmadds f2,f31,f6,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f6.f64, ctx.f2.f64)));
	// fmadds f1,f27,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f27.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f2,f27,f7,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f1,f28,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f28.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,8(r28)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// fmadds f2,f28,f8,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f28.f64, ctx.f8.f64, ctx.f2.f64)));
	// stfs f2,12(r28)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// lfs f1,68(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,60(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,56(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 56);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,64(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f29,f30,f10
	ctx.f29.f64 = double(float(ctx.f30.f64 * ctx.f10.f64));
	// fmuls f30,f30,f4
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f4.f64));
	// lfs f28,48(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f29,f1,f9,f29
	ctx.f29.f64 = double(float(std::fma(ctx.f1.f64, ctx.f9.f64, ctx.f29.f64)));
	// lfs f27,52(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f1,f1,f3,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f3.f64, ctx.f30.f64)));
	// fmadds f30,f2,f11,f29
	ctx.f30.f64 = double(float(std::fma(ctx.f2.f64, ctx.f11.f64, ctx.f29.f64)));
	// fmadds f2,f2,f5,f1
	ctx.f2.f64 = double(float(std::fma(ctx.f2.f64, ctx.f5.f64, ctx.f1.f64)));
	// fmadds f1,f31,f12,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f30.f64)));
	// fmadds f2,f31,f6,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f6.f64, ctx.f2.f64)));
	// fmadds f1,f27,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f27.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f2,f27,f7,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f1,f28,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f28.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,16(r28)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 16, temp.u32);
	// fmadds f2,f28,f8,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f28.f64, ctx.f8.f64, ctx.f2.f64)));
	// stfs f2,20(r28)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r28.u32 + 20, temp.u32);
	// lfs f1,92(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,84(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,80(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 80);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,88(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 88);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f29,f30,f10
	ctx.f29.f64 = double(float(ctx.f30.f64 * ctx.f10.f64));
	// fmuls f30,f30,f4
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f4.f64));
	// lfs f28,72(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 72);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f29,f1,f9,f29
	ctx.f29.f64 = double(float(std::fma(ctx.f1.f64, ctx.f9.f64, ctx.f29.f64)));
	// lfs f27,76(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 76);
	ctx.f27.f64 = double(temp.f32);
	// addi r29,r29,96
	ctx.r29.s64 = ctx.r29.s64 + 96;
	// fmadds f1,f1,f3,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f3.f64, ctx.f30.f64)));
	// fmadds f30,f2,f11,f29
	ctx.f30.f64 = double(float(std::fma(ctx.f2.f64, ctx.f11.f64, ctx.f29.f64)));
	// fmadds f2,f2,f5,f1
	ctx.f2.f64 = double(float(std::fma(ctx.f2.f64, ctx.f5.f64, ctx.f1.f64)));
	// fmadds f1,f31,f12,f30
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f30.f64)));
	// fmadds f2,f31,f6,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f6.f64, ctx.f2.f64)));
	// fmadds f1,f27,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f27.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f2,f27,f7,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f1,f28,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f28.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,24(r28)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r28.u32 + 24, temp.u32);
	// fmadds f2,f28,f8,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f28.f64, ctx.f8.f64, ctx.f2.f64)));
	// stfs f2,28(r28)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r28.u32 + 28, temp.u32);
	// addi r28,r28,32
	ctx.r28.s64 = ctx.r28.s64 + 32;
	// bdnz 0x82657278
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82657278;
loc_826573C4:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x82657814
	if (!ctx.cr6.lt) goto loc_82657814;
	// subf r9,r10,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r10.u64;
	// addi r10,r28,-4
	ctx.r10.s64 = ctx.r28.s64 + -4;
	// addi r11,r29,-4
	ctx.r11.s64 = ctx.r29.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826573DC:
	// lfs f2,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f10
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// lfs f31,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f30,f2,f4
	ctx.f30.f64 = double(float(ctx.f2.f64 * ctx.f4.f64));
	// lfs f29,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f27.f64 = double(temp.f32);
	// lfsu f2,24(r11)
	ea = 24 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f2.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fmadds f1,f2,f9,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f2.f64, ctx.f9.f64, ctx.f1.f64)));
	// fmadds f2,f2,f3,f30
	ctx.f2.f64 = double(float(std::fma(ctx.f2.f64, ctx.f3.f64, ctx.f30.f64)));
	// fmadds f1,f27,f11,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f27.f64, ctx.f11.f64, ctx.f1.f64)));
	// fmadds f2,f27,f5,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f5.f64, ctx.f2.f64)));
	// fmadds f1,f28,f12,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f28.f64, ctx.f12.f64, ctx.f1.f64)));
	// fmadds f2,f28,f6,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f28.f64, ctx.f6.f64, ctx.f2.f64)));
	// fmadds f1,f29,f13,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f29.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f2,f29,f7,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f29.f64, ctx.f7.f64, ctx.f2.f64)));
	// fmadds f1,f31,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f1,4(r10)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fmadds f2,f31,f8,f2
	ctx.f2.f64 = double(float(std::fma(ctx.f31.f64, ctx.f8.f64, ctx.f2.f64)));
	// stfsu f2,8(r10)
	ea = 8 + ctx.r10.u32;
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826573dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826573DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af70
	ctx.lr = 0x82657440;
	__restfpr_27(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_82657444:
	// cmpw cr6,r23,r19
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r19.s32, ctx.xer);
	// blt cr6,0x82657624
	if (ctx.cr6.lt) goto loc_82657624;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x82657814
	if (!ctx.cr6.gt) goto loc_82657814;
	// rlwinm r25,r23,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r19,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
loc_82657460:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a590
	ctx.lr = 0x82657470;
	sub_8273A590(ctx, base);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// ble cr6,0x82657580
	if (!ctx.cr6.gt) goto loc_82657580;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
loc_82657480:
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// blt cr6,0x8265753c
	if (ctx.cr6.lt) goto loc_8265753C;
	// addi r10,r23,-4
	ctx.r10.s64 = ctx.r23.s64 + -4;
	// neg r7,r29
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r29.u64);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r29,8
	ctx.r10.s64 = ctx.r29.s64 + 8;
	// addi r6,r7,4
	ctx.r6.s64 = ctx.r7.s64 + 4;
	// addi r5,r7,-8
	ctx.r5.s64 = ctx.r7.s64 + -8;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826574B4:
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// add r8,r5,r10
	ctx.r8.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lfs f0,-8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lfsx f12,r7,r8
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f11,r11,r31
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lfs f10,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// fmr f9,f11
	ctx.f9.f64 = ctx.f11.f64;
	// lwzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lfs f8,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f8,f10,f11
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f10.f64, ctx.f11.f64)));
	// stfsx f7,r11,r31
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lfs f6,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// lwzx r8,r7,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lfsx f4,r8,r9
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f4,f6,f7
	ctx.f3.f64 = double(float(std::fma(ctx.f4.f64, ctx.f6.f64, ctx.f7.f64)));
	// stfsx f3,r11,r31
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lfs f2,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lwzx r8,r7,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lfsx f0,r8,r10
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f0,f2,f3
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f2.f64, ctx.f3.f64)));
	// stfsx f13,r11,r31
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bdnz 0x826574b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826574B4;
loc_8265753C:
	// cmpw cr6,r4,r23
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r23.s32, ctx.xer);
	// bge cr6,0x82657574
	if (!ctx.cr6.lt) goto loc_82657574;
	// subf r9,r4,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r4.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82657550:
	// lwz r9,372(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lfsx f0,r10,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lfsx f12,r8,r10
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f11,r11,r31
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// bdnz 0x82657550
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82657550;
loc_82657574:
	// addic. r3,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82657480
	if (!ctx.cr0.eq) goto loc_82657480;
loc_82657580:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r19,4
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 4, ctx.xer);
	// blt cr6,0x826575d4
	if (ctx.cr6.lt) goto loc_826575D4;
	// addi r11,r19,-4
	ctx.r11.s64 = ctx.r19.s64 + -4;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// subf r7,r28,r31
	ctx.r7.u64 = ctx.r31.u64 - ctx.r28.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826575AC:
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfsx f13,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f12,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsu f0,16(r10)
	ea = 16 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826575ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826575AC;
loc_826575D4:
	// cmpw cr6,r8,r19
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x82657600
	if (!ctx.cr6.lt) goto loc_82657600;
	// subf r9,r8,r19
	ctx.r9.u64 = ctx.r19.u64 - ctx.r8.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r28,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r28.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826575F0:
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x826575f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826575F0;
loc_82657600:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// add r29,r25,r29
	ctx.r29.u64 = ctx.r25.u64 + ctx.r29.u64;
	// add r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 + ctx.r28.u64;
	// bne 0x82657460
	if (!ctx.cr0.eq) goto loc_82657460;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af70
	ctx.lr = 0x82657620;
	__restfpr_27(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_82657624:
	// addi r11,r5,-1
	ctx.r11.s64 = ctx.r5.s64 + -1;
	// mullw r10,r11,r23
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r23.s32);
	// mullw r9,r11,r19
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r19.s32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r10,r4
	ctx.r28.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r27,r9,r6
	ctx.r27.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82657814
	if (ctx.cr6.lt) goto loc_82657814;
	// neg r11,r19
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r19.u64);
	// neg r10,r23
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r23.u64);
	// rlwinm r22,r23,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r24,r19,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r21,r11,2,0,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r20,r10,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r26,r27,r31
	ctx.r26.u64 = ctx.r31.u64 - ctx.r27.u64;
	// subfic r29,r28,-8
	ctx.xer.ca = ctx.r28.u32 <= 4294967288;
	ctx.r29.u64 = static_cast<uint64_t>(-8) - ctx.r28.u64;
loc_8265766C:
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a590
	ctx.lr = 0x8265767C;
	sub_8273A590(ctx, base);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// ble cr6,0x82657784
	if (!ctx.cr6.gt) goto loc_82657784;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
loc_8265768C:
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// blt cr6,0x82657740
	if (ctx.cr6.lt) goto loc_82657740;
	// addi r10,r23,-4
	ctx.r10.s64 = ctx.r23.s64 + -4;
	// li r9,8
	ctx.r9.s64 = 8;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r29,12
	ctx.r6.s64 = ctx.r29.s64 + 12;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r28,8
	ctx.r10.s64 = ctx.r28.s64 + 8;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826576B8:
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lfs f0,-8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r3,r7,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lfsx f12,r3,r8
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f11,r11,r31
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// lfs f10,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// fmr f9,f11
	ctx.f9.f64 = ctx.f11.f64;
	// lwz r7,372(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lwzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lfs f8,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f8,f10,f11
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f10.f64, ctx.f11.f64)));
	// stfsx f7,r11,r31
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// lwz r8,372(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// lfs f6,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwzx r7,r8,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// lfsx f4,r7,r9
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f4,f6,f7
	ctx.f3.f64 = double(float(std::fma(ctx.f4.f64, ctx.f6.f64, ctx.f7.f64)));
	// stfsx f3,r11,r31
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// lwz r3,372(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// lfs f1,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r8,r3,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lfsx f0,r8,r6
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f0,f1,f3
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f1.f64, ctx.f3.f64)));
	// stfsx f13,r11,r31
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// bdnz 0x826576b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826576B8;
loc_82657740:
	// cmpw cr6,r5,r23
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r23.s32, ctx.xer);
	// bge cr6,0x82657778
	if (!ctx.cr6.lt) goto loc_82657778;
	// subf r9,r5,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r5.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82657754:
	// lwz r9,372(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lfsx f0,r10,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lfsx f12,r8,r10
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f11,r11,r31
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
	// bdnz 0x82657754
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82657754;
loc_82657778:
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x8265768c
	if (!ctx.cr0.eq) goto loc_8265768C;
loc_82657784:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r19,4
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 4, ctx.xer);
	// blt cr6,0x826577d4
	if (ctx.cr6.lt) goto loc_826577D4;
	// addi r11,r19,-4
	ctx.r11.s64 = ctx.r19.s64 + -4;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826577AC:
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfsx f13,r11,r26
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f12,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfsu f0,16(r10)
	ea = 16 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x826577ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826577AC;
loc_826577D4:
	// cmpw cr6,r8,r19
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x826577fc
	if (!ctx.cr6.lt) goto loc_826577FC;
	// subf r10,r8,r19
	ctx.r10.u64 = ctx.r19.u64 - ctx.r8.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826577EC:
	// lfsx f0,r11,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x826577ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826577EC;
loc_826577FC:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// subf r28,r22,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r22.u64;
	// subf r29,r20,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r20.u64;
	// subf r27,r24,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r24.u64;
	// subf r26,r21,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r21.u64;
	// bge 0x8265766c
	if (!ctx.cr0.lt) goto loc_8265766C;
loc_82657814:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af70
	ctx.lr = 0x82657824;
	__restfpr_27(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269B908) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8269B910;
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
	// bne cr6,0x8269b93c
	if (!ctx.cr6.eq) goto loc_8269B93C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_8269B93C:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8269ba24
	if (ctx.cr6.eq) goto loc_8269BA24;
loc_8269B950:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269ba24
	if (ctx.cr6.eq) goto loc_8269BA24;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ld r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 8);
	// cmpld cr6,r10,r29
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r29.u64, ctx.xer);
	// bgt cr6,0x8269ba24
	if (ctx.cr6.gt) goto loc_8269BA24;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r30,12(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8269ba10
	if (!ctx.cr6.eq) goto loc_8269BA10;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269B98C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269ba24
	if (ctx.cr6.lt) goto loc_8269BA24;
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
	// beq cr6,0x8269b9d4
	if (ctx.cr6.eq) goto loc_8269B9D4;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// b 0x8269b9dc
	goto loc_8269B9DC;
loc_8269B9D4:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8269B9DC:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bne 0x8269b9f8
	if (!ctx.cr0.eq) goto loc_8269B9F8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// stw r28,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
loc_8269B9F8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x8268f838
	ctx.lr = 0x8269BA08;
	sub_8268F838(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269ba24
	if (ctx.cr6.lt) goto loc_8269BA24;
loc_8269BA10:
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8269b950
	if (!ctx.cr6.eq) goto loc_8269B950;
loc_8269BA24:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A5490) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x826A5498;
	__savegprlr_16(ctx, base);
	// stwu r1,-1392(r1)
	ea = -1392 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r17,r8
	ctx.r17.u64 = ctx.r8.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826a54c8
	if (!ctx.cr6.eq) goto loc_826A54C8;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826A54C8:
	// lwz r11,3692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3692);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a54e0
	if (!ctx.cr6.eq) goto loc_826A54E0;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826A54E0:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// li r18,0
	ctx.r18.s64 = 0;
	// stw r18,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r18.u32);
	// lwz r10,3948(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826a556c
	if (ctx.cr6.eq) goto loc_826A556C;
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r10,r11,21849
	ctx.r10.u64 = ctx.r11.u64 | 21849;
	// cmplw cr6,r20,r10
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826a5544
	if (ctx.cr6.eq) goto loc_826A5544;
	// lis r11,22870
	ctx.r11.s64 = 1498808320;
	// ori r10,r11,22869
	ctx.r10.u64 = ctx.r11.u64 | 22869;
	// cmplw cr6,r20,r10
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826a5544
	if (ctx.cr6.eq) goto loc_826A5544;
	// lis r11,21849
	ctx.r11.s64 = 1431896064;
	// ori r10,r11,22105
	ctx.r10.u64 = ctx.r11.u64 | 22105;
	// cmplw cr6,r20,r10
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826a5544
	if (ctx.cr6.eq) goto loc_826A5544;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x826a554c
	if (ctx.cr6.eq) goto loc_826A554C;
	// cmplwi cr6,r20,3
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 3, ctx.xer);
	// beq cr6,0x826a5544
	if (ctx.cr6.eq) goto loc_826A5544;
loc_826A5538:
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826A5544:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x826a5558
	if (!ctx.cr6.eq) goto loc_826A5558;
loc_826A554C:
	// clrlwi r11,r21,16
	ctx.r11.u64 = ctx.r21.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x826a5538
	if (ctx.cr6.eq) goto loc_826A5538;
loc_826A5558:
	// cmplwi cr6,r20,3
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 3, ctx.xer);
	// bne cr6,0x826a556c
	if (!ctx.cr6.eq) goto loc_826A556C;
	// clrlwi r11,r21,16
	ctx.r11.u64 = ctx.r21.u32 & 0xFFFF;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x826a5538
	if (ctx.cr6.eq) goto loc_826A5538;
loc_826A556C:
	// lwz r11,22356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22356);
	// li r19,1
	ctx.r19.s64 = 1;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a5588
	if (!ctx.cr6.eq) goto loc_826A5588;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269ee10
	ctx.lr = 0x826A5584;
	sub_8269EE10(ctx, base);
	// b 0x826a5ed0
	goto loc_826A5ED0;
loc_826A5588:
	// lwz r11,3448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3448);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a55b0
	if (!ctx.cr6.eq) goto loc_826A55B0;
	// lwz r11,22316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22316);
	// stw r18,3448(r31)
	REX_STORE_U32(ctx.r31.u32 + 3448, ctx.r18.u32);
	// sth r19,3708(r31)
	REX_STORE_U16(ctx.r31.u32 + 3708, ctx.r19.u16);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a5ed0
	if (!ctx.cr6.eq) goto loc_826A5ED0;
	// stw r18,22316(r31)
	REX_STORE_U32(ctx.r31.u32 + 22316, ctx.r18.u32);
	// b 0x826a5ab8
	goto loc_826A5AB8;
loc_826A55B0:
	// lhz r11,3708(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 3708);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826a55c8
	if (!ctx.cr6.eq) goto loc_826A55C8;
	// li r3,9
	ctx.r3.s64 = 9;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826A55C8:
	// lwz r11,15332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15332);
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// bne cr6,0x826a581c
	if (!ctx.cr6.eq) goto loc_826A581C;
	// li r19,1
	ctx.r19.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a55ec
	if (!ctx.cr6.eq) goto loc_826A55EC;
	// lwz r11,15400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a55f4
	if (ctx.cr6.eq) goto loc_826A55F4;
loc_826A55EC:
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
	// b 0x826a55f8
	goto loc_826A55F8;
loc_826A55F4:
	// stw r18,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r18.u32);
loc_826A55F8:
	// lwz r11,14824(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14824);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a568c
	if (ctx.cr6.eq) goto loc_826A568C;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5618
	if (ctx.cr6.eq) goto loc_826A5618;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x826a5660
	if (!ctx.cr6.eq) goto loc_826A5660;
loc_826A5618:
	// lwz r10,14804(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826a5630
	if (!ctx.cr6.eq) goto loc_826A5630;
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// stw r11,14832(r31)
	REX_STORE_U32(ctx.r31.u32 + 14832, ctx.r11.u32);
	// b 0x826a5660
	goto loc_826A5660;
loc_826A5630:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a5660
	if (ctx.cr6.eq) goto loc_826A5660;
	// lwz r11,14832(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14832);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5658
	if (!ctx.cr6.eq) goto loc_826A5658;
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a5658
	if (!ctx.cr6.eq) goto loc_826A5658;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7198
	ctx.lr = 0x826A5658;
	sub_826A7198(ctx, base);
loc_826A5658:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ef918
	ctx.lr = 0x826A5660;
	sub_826EF918(ctx, base);
loc_826A5660:
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a568c
	if (ctx.cr6.eq) goto loc_826A568C;
	// lwz r11,15596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15596);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5684
	if (!ctx.cr6.eq) goto loc_826A5684;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c7b88
	ctx.lr = 0x826A5680;
	sub_826C7B88(ctx, base);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A5684:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826efa38
	ctx.lr = 0x826A568C;
	sub_826EFA38(ctx, base);
loc_826A568C:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x826a56bc
	if (!ctx.cr6.eq) goto loc_826A56BC;
	// lwz r11,22140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22140);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a56b0
	if (!ctx.cr6.eq) goto loc_826A56B0;
	// lwz r11,22144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a56bc
	if (ctx.cr6.eq) goto loc_826A56BC;
loc_826A56B0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826efe18
	ctx.lr = 0x826A56B8;
	sub_826EFE18(ctx, base);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A56BC:
	// lwz r11,14852(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a57ac
	if (ctx.cr6.eq) goto loc_826A57AC;
	// lwz r11,14856(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a57ac
	if (ctx.cr6.eq) goto loc_826A57AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c35e0
	ctx.lr = 0x826A56E0;
	sub_826C35E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c30a8
	ctx.lr = 0x826A56E8;
	sub_826C30A8(ctx, base);
	// lwz r11,15596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15596);
	// lwz r10,224(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r7,220(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r29,14856(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// lwz r28,14860(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// rotlwi r11,r29,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// stw r18,14856(r31)
	REX_STORE_U32(ctx.r31.u32 + 14856, ctx.r18.u32);
	// mulli r11,r11,84
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(84));
	// stw r29,14860(r31)
	REX_STORE_U32(ctx.r31.u32 + 14860, ctx.r29.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x826a5764
	if (ctx.cr6.eq) goto loc_826A5764;
	// lwz r9,3776(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
	// lwz r8,3772(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r6,3768(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r10,14936(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 14936);
	// lwz r5,3808(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lwz r4,3804(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r30,3800(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// add r6,r5,r10
	ctx.r6.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lwz r11,14932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 14932);
	// add r5,r4,r10
	ctx.r5.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x826c4138
	ctx.lr = 0x826A5758;
	sub_826C4138(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7090
	ctx.lr = 0x826A5760;
	sub_826A7090(ctx, base);
	// b 0x826a57a0
	goto loc_826A57A0;
loc_826A5764:
	// lwz r9,3808(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r8,3804(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r6,3800(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r10,14936(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 14936);
	// lwz r5,3752(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lwz r4,3748(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r30,3744(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r6,r5,r10
	ctx.r6.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lwz r11,14932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 14932);
	// add r5,r4,r10
	ctx.r5.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x826c4138
	ctx.lr = 0x826A57A0;
	sub_826C4138(ctx, base);
loc_826A57A0:
	// stw r28,14860(r31)
	REX_STORE_U32(ctx.r31.u32 + 14860, ctx.r28.u32);
	// stw r29,14856(r31)
	REX_STORE_U32(ctx.r31.u32 + 14856, ctx.r29.u32);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A57AC:
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a580c
	if (!ctx.cr6.gt) goto loc_826A580C;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a57cc
	if (ctx.cr6.eq) goto loc_826A57CC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x826a57ec
	if (!ctx.cr6.eq) goto loc_826A57EC;
loc_826A57CC:
	// lwz r11,3476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3476);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5804
	if (ctx.cr6.eq) goto loc_826A5804;
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a5804
	if (ctx.cr6.eq) goto loc_826A5804;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a5804
	if (ctx.cr6.eq) goto loc_826A5804;
loc_826A57EC:
	// stw r19,3420(r31)
	REX_STORE_U32(ctx.r31.u32 + 3420, ctx.r19.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r19,15532(r31)
	REX_STORE_U32(ctx.r31.u32 + 15532, ctx.r19.u32);
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// bl 0x8269ee70
	ctx.lr = 0x826A5800;
	sub_8269EE70(ctx, base);
	// b 0x826a6328
	goto loc_826A6328;
loc_826A5804:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// stw r18,3420(r31)
	REX_STORE_U32(ctx.r31.u32 + 3420, ctx.r18.u32);
loc_826A580C:
	// stw r19,15532(r31)
	REX_STORE_U32(ctx.r31.u32 + 15532, ctx.r19.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269ee70
	ctx.lr = 0x826A5818;
	sub_8269EE70(ctx, base);
	// b 0x826a6328
	goto loc_826A6328;
loc_826A581C:
	// li r10,2
	ctx.r10.s64 = 2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,15584(r31)
	REX_STORE_U32(ctx.r31.u32 + 15584, ctx.r10.u32);
	// bne cr6,0x826a5838
	if (!ctx.cr6.eq) goto loc_826A5838;
	// lwz r11,15400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a59d0
	if (ctx.cr6.eq) goto loc_826A59D0;
loc_826A5838:
	// lwz r11,15340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// lwz r10,15344(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// stw r18,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r18.u32);
	// srawi r8,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 4;
	// stw r18,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r18.u32);
	// srawi r3,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 4;
	// stw r9,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r9.u32);
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r3,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r3.u32);
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r7,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r7.u32);
	// stw r6,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r6.u32);
	// stw r8,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r8.u32);
	// lwz r4,3380(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3380);
	// bl 0x82700a18
	ctx.lr = 0x826A5884;
	sub_82700A18(ctx, base);
	// lwz r8,3380(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3380);
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// li r19,1
	ctx.r19.s64 = 1;
	// lwz r4,208(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// rlwinm r9,r5,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// rlwinm r7,r4,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,216(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// divwu r8,r10,r8
	ctx.r8.u64 = uint32_t(ctx.r8.u32 ? ctx.r10.u32 / ctx.r8.u32 : 0);
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r3,3836(r31)
	REX_STORE_U32(ctx.r31.u32 + 3836, ctx.r3.u32);
	// stw r3,3872(r31)
	REX_STORE_U32(ctx.r31.u32 + 3872, ctx.r3.u32);
	// cmpw cr6,r29,r5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r5.s32, ctx.xer);
	// stw r8,3840(r31)
	REX_STORE_U32(ctx.r31.u32 + 3840, ctx.r8.u32);
	// stw r5,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r5.u32);
	// stw r4,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r4.u32);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r6,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r6.u32);
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// stw r7,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r7.u32);
	// bne cr6,0x826a58f0
	if (!ctx.cr6.eq) goto loc_826A58F0;
	// lwz r9,92(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// beq cr6,0x826a58f4
	if (ctx.cr6.eq) goto loc_826A58F4;
loc_826A58F0:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_826A58F4:
	// lwz r9,15340(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,15344(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// addi r6,r9,15
	ctx.r6.s64 = ctx.r9.s64 + 15;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// addi r5,r8,15
	ctx.r5.s64 = ctx.r8.s64 + 15;
	// srawi r11,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 4;
	// srawi r10,r5,4
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 4;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// mullw r4,r10,r11
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// stw r4,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r4.u32);
	// bne cr6,0x826a5940
	if (!ctx.cr6.eq) goto loc_826A5940;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826a5944
	if (ctx.cr6.eq) goto loc_826A5944;
loc_826A5940:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_826A5944:
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r20,15520(r31)
	REX_STORE_U32(ctx.r31.u32 + 15520, ctx.r20.u32);
	// sth r21,15524(r31)
	REX_STORE_U16(ctx.r31.u32 + 15524, ctx.r21.u16);
	// stw r30,15536(r31)
	REX_STORE_U32(ctx.r31.u32 + 15536, ctx.r30.u32);
	// beq cr6,0x826a5968
	if (ctx.cr6.eq) goto loc_826A5968;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x826a5968
	if (ctx.cr6.eq) goto loc_826A5968;
	// stw r18,15536(r31)
	REX_STORE_U32(ctx.r31.u32 + 15536, ctx.r18.u32);
loc_826A5968:
	// lwz r11,15536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15536);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826a5990
	if (ctx.cr6.eq) goto loc_826A5990;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x826a5990
	if (ctx.cr6.eq) goto loc_826A5990;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// bne cr6,0x826a59a0
	if (!ctx.cr6.eq) goto loc_826A59A0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// b 0x826a59a0
	goto loc_826A59A0;
loc_826A5990:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// bne cr6,0x826a59a0
	if (!ctx.cr6.eq) goto loc_826A59A0;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_826A59A0:
	// stw r11,15528(r31)
	REX_STORE_U32(ctx.r31.u32 + 15528, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827004f0
	ctx.lr = 0x826A59AC;
	sub_827004F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a633c
	if (!ctx.cr6.eq) goto loc_826A633C;
	// stw r19,15516(r31)
	REX_STORE_U32(ctx.r31.u32 + 15516, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82700388
	ctx.lr = 0x826A59C4;
	sub_82700388(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a633c
	if (!ctx.cr6.eq) goto loc_826A633C;
	// b 0x826a6328
	goto loc_826A6328;
loc_826A59D0:
	// stw r20,15520(r31)
	REX_STORE_U32(ctx.r31.u32 + 15520, ctx.r20.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// sth r21,15524(r31)
	REX_STORE_U16(ctx.r31.u32 + 15524, ctx.r21.u16);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r30,15536(r31)
	REX_STORE_U32(ctx.r31.u32 + 15536, ctx.r30.u32);
	// bne cr6,0x826a59ec
	if (!ctx.cr6.eq) goto loc_826A59EC;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
loc_826A59EC:
	// stw r11,15528(r31)
	REX_STORE_U32(ctx.r31.u32 + 15528, ctx.r11.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a5a04
	if (ctx.cr6.eq) goto loc_826A5A04;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x826a5a04
	if (ctx.cr6.eq) goto loc_826A5A04;
	// stw r18,15536(r31)
	REX_STORE_U32(ctx.r31.u32 + 15536, ctx.r18.u32);
loc_826A5A04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827004f0
	ctx.lr = 0x826A5A0C;
	sub_827004F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a633c
	if (!ctx.cr6.eq) goto loc_826A633C;
	// stw r19,15516(r31)
	REX_STORE_U32(ctx.r31.u32 + 15516, ctx.r19.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a4df0
	ctx.lr = 0x826A5A20;
	sub_826A4DF0(ctx, base);
	// lwz r11,3668(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3668);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x826a5a4c
	if (!ctx.cr6.eq) goto loc_826A5A4C;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5a68
	if (!ctx.cr6.eq) goto loc_826A5A68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8128
	ctx.lr = 0x826A5A40;
	sub_826C8128(ctx, base);
	// lwz r11,15580(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15580);
	// stw r11,3668(r31)
	REX_STORE_U32(ctx.r31.u32 + 3668, ctx.r11.u32);
	// b 0x826a5a68
	goto loc_826A5A68;
loc_826A5A4C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x826a5a60
	if (ctx.cr6.lt) goto loc_826A5A60;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x826a5a60
	if (ctx.cr6.gt) goto loc_826A5A60;
	// stw r11,15580(r31)
	REX_STORE_U32(ctx.r31.u32 + 15580, ctx.r11.u32);
loc_826A5A60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8128
	ctx.lr = 0x826A5A68;
	sub_826C8128(ctx, base);
loc_826A5A68:
	// lwz r11,15540(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15540);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5ab8
	if (ctx.cr6.eq) goto loc_826A5AB8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a0050
	ctx.lr = 0x826A5A7C;
	sub_826A0050(ctx, base);
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// lwz r5,140(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x826a5aa4
	if (ctx.cr6.eq) goto loc_826A5AA4;
	// lwz r11,15892(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15892);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826A5AA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x826a5aac
	goto loc_826A5AAC;
loc_826A5AA4:
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x826c7cf0
	ctx.lr = 0x826A5AAC;
	sub_826C7CF0(ctx, base);
loc_826A5AAC:
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a00b0
	ctx.lr = 0x826A5AB8;
	sub_826A00B0(ctx, base);
loc_826A5AB8:
	// lwz r11,14824(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14824);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5b4c
	if (ctx.cr6.eq) goto loc_826A5B4C;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5ad8
	if (ctx.cr6.eq) goto loc_826A5AD8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x826a5b20
	if (!ctx.cr6.eq) goto loc_826A5B20;
loc_826A5AD8:
	// lwz r10,14804(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826a5af0
	if (!ctx.cr6.eq) goto loc_826A5AF0;
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// stw r11,14832(r31)
	REX_STORE_U32(ctx.r31.u32 + 14832, ctx.r11.u32);
	// b 0x826a5b20
	goto loc_826A5B20;
loc_826A5AF0:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a5b20
	if (ctx.cr6.eq) goto loc_826A5B20;
	// lwz r11,14832(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14832);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5b18
	if (!ctx.cr6.eq) goto loc_826A5B18;
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826a5b18
	if (!ctx.cr6.eq) goto loc_826A5B18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7198
	ctx.lr = 0x826A5B18;
	sub_826A7198(ctx, base);
loc_826A5B18:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ef918
	ctx.lr = 0x826A5B20;
	sub_826EF918(ctx, base);
loc_826A5B20:
	// lwz r11,14828(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5b4c
	if (ctx.cr6.eq) goto loc_826A5B4C;
	// lwz r11,15596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15596);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5b44
	if (!ctx.cr6.eq) goto loc_826A5B44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c7b88
	ctx.lr = 0x826A5B40;
	sub_826C7B88(ctx, base);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A5B44:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8f70
	ctx.lr = 0x826A5B4C;
	sub_826E8F70(ctx, base);
loc_826A5B4C:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x826a5b7c
	if (!ctx.cr6.eq) goto loc_826A5B7C;
	// lwz r11,22140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22140);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5b70
	if (!ctx.cr6.eq) goto loc_826A5B70;
	// lwz r11,22144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5b7c
	if (ctx.cr6.eq) goto loc_826A5B7C;
loc_826A5B70:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826efe18
	ctx.lr = 0x826A5B78;
	sub_826EFE18(ctx, base);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A5B7C:
	// lwz r11,14856(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5e74
	if (ctx.cr6.eq) goto loc_826A5E74;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c35e0
	ctx.lr = 0x826A5B94;
	sub_826C35E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c30a8
	ctx.lr = 0x826A5B9C;
	sub_826C30A8(ctx, base);
	// lwz r11,15596(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15596);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r29,14856(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// lwz r28,14860(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// lwz r11,15932(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15932);
	// stw r18,14856(r31)
	REX_STORE_U32(ctx.r31.u32 + 14856, ctx.r18.u32);
	// stw r29,14860(r31)
	REX_STORE_U32(ctx.r31.u32 + 14860, ctx.r29.u32);
	// beq cr6,0x826a5d14
	if (ctx.cr6.eq) goto loc_826A5D14;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5cb4
	if (ctx.cr6.eq) goto loc_826A5CB4;
	// lwz r11,20640(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20640);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5cb4
	if (!ctx.cr6.eq) goto loc_826A5CB4;
	// lwz r10,3728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3728);
	// li r8,8
	ctx.r8.s64 = 8;
	// lwz r9,584(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 584);
	// mulli r11,r9,68
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(68));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// stw r7,584(r10)
	REX_STORE_U32(ctx.r10.u32 + 584, ctx.r7.u32);
	// stw r8,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r8.u32);
	// lwz r6,3728(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3728);
	// stw r6,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// lwz r5,14860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r5,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(84));
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r3,14932(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 14932);
	// stw r3,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r3.u32);
	// lwz r10,14860(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r10,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(84));
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r8,14936(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 14936);
	// stw r8,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r8.u32);
	// lwz r7,220(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// stw r7,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r7.u32);
	// lwz r6,224(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// stw r6,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r6.u32);
	// lwz r5,14856(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// stw r5,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// lwz r4,14860(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// stw r4,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r4.u32);
	// lwz r3,14860(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r3,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(84));
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r9,14916(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 14916);
	// stw r9,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r9.u32);
	// lwz r8,14860(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r8,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(84));
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r6,14920(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 14920);
	// stw r6,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r6.u32);
	// lwz r5,14860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r5,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(84));
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r3,14904(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 14904);
	// stw r3,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r3.u32);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// stw r9,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// lwz r8,180(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// stw r8,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// lwz r7,192(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// stw r7,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r7.u32);
	// lwz r6,188(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r6,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// lwz r5,200(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// stw r5,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r5.u32);
	// b 0x826a5e68
	goto loc_826A5E68;
loc_826A5CB4:
	// lwz r11,14860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,224(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mulli r11,r11,84
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(84));
	// lwz r9,3776(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
	// lwz r8,3772(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r7,3768(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// lwz r30,220(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r6,3808(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r5,3804(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r4,3800(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 + ctx.r30.u64;
	// lwz r10,14936(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 14936);
	// lwz r11,14932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 14932);
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bl 0x826c4138
	ctx.lr = 0x826A5D08;
	sub_826C4138(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a7090
	ctx.lr = 0x826A5D10;
	sub_826A7090(ctx, base);
	// b 0x826a5e68
	goto loc_826A5E68;
loc_826A5D14:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5e14
	if (ctx.cr6.eq) goto loc_826A5E14;
	// lwz r11,20640(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20640);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a5e14
	if (!ctx.cr6.eq) goto loc_826A5E14;
	// lwz r11,3728(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3728);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r18,584(r11)
	REX_STORE_U32(ctx.r11.u32 + 584, ctx.r18.u32);
	// lwz r10,3728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3728);
	// lwz r9,584(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 584);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,584(r10)
	REX_STORE_U32(ctx.r10.u32 + 584, ctx.r7.u32);
	// mulli r11,r9,68
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(68));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// stw r8,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r8.u32);
	// lwz r6,3712(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// stw r6,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// lwz r5,14860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r5,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(84));
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r3,14932(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 14932);
	// stw r3,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r3.u32);
	// lwz r10,14860(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r10,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(84));
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r8,14936(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 14936);
	// stw r8,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r8.u32);
	// lwz r7,220(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// stw r7,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r7.u32);
	// lwz r6,224(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// stw r6,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r6.u32);
	// lwz r5,14856(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// stw r5,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// lwz r4,14860(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// stw r4,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r4.u32);
	// lwz r3,14860(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r3,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(84));
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r9,14916(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 14916);
	// stw r9,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r9.u32);
	// lwz r8,14860(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r8,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(84));
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r6,14920(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 14920);
	// stw r6,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r6.u32);
	// lwz r5,14860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mulli r10,r5,84
	ctx.r10.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(84));
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r3,14904(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 14904);
	// stw r3,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r3.u32);
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// stw r9,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// lwz r8,180(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// stw r8,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// lwz r7,192(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// stw r7,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r7.u32);
	// lwz r6,188(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r6,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// lwz r5,200(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// stw r5,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r5.u32);
	// b 0x826a5e68
	goto loc_826A5E68;
loc_826A5E14:
	// lwz r11,14860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14860);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,224(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mulli r11,r11,84
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(84));
	// lwz r9,3808(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r8,3804(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r7,3800(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r30,220(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r6,3752(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r5,3748(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r4,3744(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 + ctx.r30.u64;
	// lwz r10,14936(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 14936);
	// lwz r11,14932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 14932);
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bl 0x826c4138
	ctx.lr = 0x826A5E68;
	sub_826C4138(ctx, base);
loc_826A5E68:
	// stw r28,14860(r31)
	REX_STORE_U32(ctx.r31.u32 + 14860, ctx.r28.u32);
	// stw r29,14856(r31)
	REX_STORE_U32(ctx.r31.u32 + 14856, ctx.r29.u32);
	// stw r19,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r19.u32);
loc_826A5E74:
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// stw r18,22360(r31)
	REX_STORE_U32(ctx.r31.u32 + 22360, ctx.r18.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a5ec8
	if (!ctx.cr6.gt) goto loc_826A5EC8;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a5e98
	if (ctx.cr6.eq) goto loc_826A5E98;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x826a5eb8
	if (!ctx.cr6.eq) goto loc_826A5EB8;
loc_826A5E98:
	// lwz r11,3476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3476);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a5ec0
	if (ctx.cr6.eq) goto loc_826A5EC0;
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826a5ec0
	if (ctx.cr6.eq) goto loc_826A5EC0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x826a5ec0
	if (ctx.cr6.eq) goto loc_826A5EC0;
loc_826A5EB8:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// b 0x826a5ec4
	goto loc_826A5EC4;
loc_826A5EC0:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_826A5EC4:
	// stw r11,3420(r31)
	REX_STORE_U32(ctx.r31.u32 + 3420, ctx.r11.u32);
loc_826A5EC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269ee70
	ctx.lr = 0x826A5ED0;
	sub_8269EE70(ctx, base);
loc_826A5ED0:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,184
	ctx.r4.s64 = ctx.r1.s64 + 184;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269f3d8
	ctx.lr = 0x826A5EE0;
	sub_8269F3D8(ctx, base);
	// lwz r25,15504(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r25,7
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 7, ctx.xer);
	// beq cr6,0x826a5ef4
	if (ctx.cr6.eq) goto loc_826A5EF4;
	// cmpwi cr6,r25,6
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 6, ctx.xer);
	// bne cr6,0x826a6310
	if (!ctx.cr6.eq) goto loc_826A6310;
loc_826A5EF4:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a630c
	if (!ctx.cr6.eq) goto loc_826A630C;
	// lwz r11,3740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3740);
	// li r29,64
	ctx.r29.s64 = 64;
	// lwz r10,22112(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22112);
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r18.u32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// lwz r23,4(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r22,8(r11)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r24,0(r11)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bne cr6,0x826a5f74
	if (!ctx.cr6.eq) goto loc_826A5F74;
	// lwz r11,14804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826a5f74
	if (!ctx.cr6.gt) goto loc_826A5F74;
	// ld r11,3600(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 3600);
	// cmpdi cr6,r11,1
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 1, ctx.xer);
	// ble cr6,0x826a5f74
	if (!ctx.cr6.gt) goto loc_826A5F74;
	// lwz r10,22280(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22280);
	// lwz r11,22308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22308);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x826a5f54
	if (ctx.cr6.gt) goto loc_826A5F54;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_826A5F54:
	// lwz r11,22312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22312);
	// lwz r10,22284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22284);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826a5f6c
	if (!ctx.cr6.gt) goto loc_826A5F6C;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// b 0x826a5f7c
	goto loc_826A5F7C;
loc_826A5F6C:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// b 0x826a5f7c
	goto loc_826A5F7C;
loc_826A5F74:
	// lwz r8,156(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r4,160(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
loc_826A5F7C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bne cr6,0x826a5f8c
	if (!ctx.cr6.eq) goto loc_826A5F8C;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
loc_826A5F8C:
	// lwz r9,15332(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15332);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r5,15528(r31)
	REX_STORE_U32(ctx.r31.u32 + 15528, ctx.r5.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826a5fb0
	if (!ctx.cr6.eq) goto loc_826A5FB0;
	// addi r11,r8,15
	ctx.r11.s64 = ctx.r8.s64 + 15;
	// srawi r8,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 4;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r8,r7,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
loc_826A5FB0:
	// lwz r30,3948(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a5fe0
	if (ctx.cr6.eq) goto loc_826A5FE0;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// addi r28,r8,64
	ctx.r28.s64 = ctx.r8.s64 + 64;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// b 0x826a5ff4
	goto loc_826A5FF4;
loc_826A5FE0:
	// mr r28,r18
	ctx.r28.u64 = ctx.r18.u64;
	// mr r27,r18
	ctx.r27.u64 = ctx.r18.u64;
	// mr r26,r18
	ctx.r26.u64 = ctx.r18.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,32
	ctx.r7.s64 = 32;
loc_826A5FF4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826a6008
	if (!ctx.cr6.eq) goto loc_826A6008;
	// lwz r11,15400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a6014
	if (ctx.cr6.eq) goto loc_826A6014;
loc_826A6008:
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
loc_826A6014:
	// cmplwi cr6,r20,3
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 3, ctx.xer);
	// bne cr6,0x826a608c
	if (!ctx.cr6.eq) goto loc_826A608C;
	// clrlwi r11,r21,16
	ctx.r11.u64 = ctx.r21.u32 & 0xFFFF;
	// li r9,31
	ctx.r9.s64 = 31;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x826a6044
	if (!ctx.cr6.eq) goto loc_826A6044;
	// lis r3,0
	ctx.r3.s64 = 0;
	// stw r9,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r9.u32);
	// li r16,2016
	ctx.r16.s64 = 2016;
	// ori r3,r3,63488
	ctx.r3.u64 = ctx.r3.u64 | 63488;
	// stw r16,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r16.u32);
	// stw r3,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
loc_826A6044:
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bne cr6,0x826a6064
	if (!ctx.cr6.eq) goto loc_826A6064;
	// stw r9,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r9.u32);
	// li r11,31744
	ctx.r11.s64 = 31744;
	// li r9,992
	ctx.r9.s64 = 992;
	// stw r11,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r11.u32);
	// li r21,16
	ctx.r21.s64 = 16;
	// stw r9,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r9.u32);
loc_826A6064:
	// clrlwi r11,r21,16
	ctx.r11.u64 = ctx.r21.u32 & 0xFFFF;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bne cr6,0x826a608c
	if (!ctx.cr6.eq) goto loc_826A608C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// ori r3,r11,65280
	ctx.r3.u64 = ctx.r11.u64 | 65280;
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r9,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r9.u32);
	// stw r3,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r3.u32);
	// stw r11,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r11.u32);
loc_826A608C:
	// lwz r11,22264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22264);
	// li r9,40
	ctx.r9.s64 = 40;
	// stw r5,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r5.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// bne cr6,0x826a60ac
	if (!ctx.cr6.eq) goto loc_826A60AC;
	// lwz r11,22344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22344);
loc_826A60AC:
	// clrlwi r3,r21,16
	ctx.r3.u64 = ctx.r21.u32 & 0xFFFF;
	// lwz r16,15536(r31)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r31.u32 + 15536);
	// sth r21,206(r1)
	REX_STORE_U16(ctx.r1.u32 + 206, ctx.r21.u16);
	// mullw r5,r3,r5
	ctx.r5.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// stw r20,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r20.u32);
	// sth r19,204(r1)
	REX_STORE_U16(ctx.r1.u32 + 204, ctx.r19.u16);
	// stw r18,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r18.u32);
	// stw r18,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, ctx.r18.u32);
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// stw r18,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r18.u32);
	// stw r18,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r18.u32);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// rlwinm r5,r3,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// cmpwi cr6,r16,2
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 2, ctx.xer);
	// stw r5,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r5.u32);
	// bne cr6,0x826a60f4
	if (!ctx.cr6.eq) goto loc_826A60F4;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
loc_826A60F4:
	// stw r9,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r3,21880(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 21880);
	// add r11,r8,r29
	ctx.r11.u64 = ctx.r8.u64 + ctx.r29.u64;
	// add r9,r4,r29
	ctx.r9.u64 = ctx.r4.u64 + ctx.r29.u64;
	// sth r19,156(r1)
	REX_STORE_U16(ctx.r1.u32 + 156, ctx.r19.u16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// sth r5,158(r1)
	REX_STORE_U16(ctx.r1.u32 + 158, ctx.r5.u16);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// bne cr6,0x826a61d0
	if (!ctx.cr6.eq) goto loc_826A61D0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a6134
	if (ctx.cr6.eq) goto loc_826A6134;
	// lis r8,12593
	ctx.r8.s64 = 825294848;
	// ori r5,r8,13392
	ctx.r5.u64 = ctx.r8.u64 | 13392;
	// b 0x826a613c
	goto loc_826A613C;
loc_826A6134:
	// lis r8,12338
	ctx.r8.s64 = 808583168;
	// ori r5,r8,13385
	ctx.r5.u64 = ctx.r8.u64 | 13385;
loc_826A613C:
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r5,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r25,7
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 7, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// bne cr6,0x826a6184
	if (!ctx.cr6.eq) goto loc_826A6184;
	// ld r11,3600(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 3600);
	// cmpdi cr6,r11,1
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 1, ctx.xer);
	// ble cr6,0x826a6174
	if (!ctx.cr6.gt) goto loc_826A6174;
	// lwz r11,21904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21904);
	// b 0x826a6178
	goto loc_826A6178;
loc_826A6174:
	// lwz r11,21900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21900);
loc_826A6178:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,2
	ctx.r11.s64 = 2;
	// beq cr6,0x826a6188
	if (ctx.cr6.eq) goto loc_826A6188;
loc_826A6184:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_826A6188:
	// stw r26,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r27,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x826fc9a8
	ctx.lr = 0x826A61B4;
	sub_826FC9A8(ctx, base);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// stw r3,21880(r31)
	REX_STORE_U32(ctx.r31.u32 + 21880, ctx.r3.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a626c
	if (ctx.cr6.eq) goto loc_826A626C;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
loc_826A61D0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a61e4
	if (ctx.cr6.eq) goto loc_826A61E4;
	// lis r8,12593
	ctx.r8.s64 = 825294848;
	// ori r5,r8,13392
	ctx.r5.u64 = ctx.r8.u64 | 13392;
	// b 0x826a61ec
	goto loc_826A61EC;
loc_826A61E4:
	// lis r8,12338
	ctx.r8.s64 = 808583168;
	// ori r5,r8,13385
	ctx.r5.u64 = ctx.r8.u64 | 13385;
loc_826A61EC:
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r5,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r25,7
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 7, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// bne cr6,0x826a6234
	if (!ctx.cr6.eq) goto loc_826A6234;
	// ld r11,3600(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 3600);
	// cmpdi cr6,r11,1
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 1, ctx.xer);
	// ble cr6,0x826a6224
	if (!ctx.cr6.gt) goto loc_826A6224;
	// lwz r11,21904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21904);
	// b 0x826a6228
	goto loc_826A6228;
loc_826A6224:
	// lwz r11,21900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21900);
loc_826A6228:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,2
	ctx.r11.s64 = 2;
	// beq cr6,0x826a6238
	if (ctx.cr6.eq) goto loc_826A6238;
loc_826A6234:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_826A6238:
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stw r26,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// stw r27,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// bl 0x826fcce8
	ctx.lr = 0x826A6260;
	sub_826FCCE8(ctx, base);
	// stw r3,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a633c
	if (!ctx.cr6.eq) goto loc_826A633C;
loc_826A626C:
	// lwz r8,21880(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 21880);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x826a5538
	if (ctx.cr6.eq) goto loc_826A5538;
	// lwz r11,3948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a62a8
	if (ctx.cr6.eq) goto loc_826A62A8;
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// addi r10,r27,1
	ctx.r10.s64 = ctx.r27.s64 + 1;
	// addi r7,r26,1
	ctx.r7.s64 = ctx.r26.s64 + 1;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r24,r9,r24
	ctx.r24.u64 = ctx.r9.u64 + ctx.r24.u64;
	// add r23,r10,r23
	ctx.r23.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r22,r11,r22
	ctx.r22.u64 = ctx.r11.u64 + ctx.r22.u64;
loc_826A62A8:
	// lwz r11,22368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22368);
	// stw r11,52(r8)
	REX_STORE_U32(ctx.r8.u32 + 52, ctx.r11.u32);
	// lwz r10,22368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22368);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x826a62ec
	if (!ctx.cr6.eq) goto loc_826A62EC;
	// lwz r11,22372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22372);
	// stw r11,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
	// lwz r10,22376(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22376);
	// stw r10,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r10.u32);
	// lwz r9,22380(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 22380);
	// stw r9,48(r8)
	REX_STORE_U32(ctx.r8.u32 + 48, ctx.r9.u32);
	// lwz r7,22384(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 22384);
	// stw r7,14624(r8)
	REX_STORE_U32(ctx.r8.u32 + 14624, ctx.r7.u32);
	// lwz r6,22388(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 22388);
	// stw r6,14628(r8)
	REX_STORE_U32(ctx.r8.u32 + 14628, ctx.r6.u32);
	// lwz r5,22392(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 22392);
	// stw r5,14632(r8)
	REX_STORE_U32(ctx.r8.u32 + 14632, ctx.r5.u32);
loc_826A62EC:
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// lwz r3,21880(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 21880);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x826fccb8
	ctx.lr = 0x826A6304;
	sub_826FCCB8(ctx, base);
	// stw r18,22112(r31)
	REX_STORE_U32(ctx.r31.u32 + 22112, ctx.r18.u32);
	// b 0x826a632c
	goto loc_826A632C;
loc_826A630C:
	// cmpwi cr6,r25,6
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 6, ctx.xer);
loc_826A6310:
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82700388
	ctx.lr = 0x826A631C;
	sub_82700388(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a633c
	if (!ctx.cr6.eq) goto loc_826A633C;
	// stw r18,22112(r31)
	REX_STORE_U32(ctx.r31.u32 + 22112, ctx.r18.u32);
loc_826A6328:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826A632C:
	// lhz r11,3708(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 3708);
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,3708(r31)
	REX_STORE_U16(ctx.r31.u32 + 3708, ctx.r10.u16);
loc_826A633C:
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8272A0C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8272A0D0;
	__savegprlr_14(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,16
	ctx.r11.s64 = 16;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r26,r10,25680
	ctx.r26.s64 = ctx.r10.s64 + 25680;
	// beq cr6,0x8272a5cc
	if (ctx.cr6.eq) goto loc_8272A5CC;
	// stw r7,-192(r1)
	REX_STORE_U32(ctx.r1.u32 + -192, ctx.r7.u32);
	// subf r10,r8,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r8.u64;
	// add r31,r4,r8
	ctx.r31.u64 = ctx.r4.u64 + ctx.r8.u64;
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r3,r8,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r8.u64;
	// lvlx128 v62,r4,r8
	temp.u32 = ctx.r4.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r29,r1,-192
	ctx.r29.s64 = ctx.r1.s64 + -192;
	// lvrx128 v61,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// add r9,r31,r8
	ctx.r9.u64 = ctx.r31.u64 + ctx.r8.u64;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// subf r6,r8,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r30,r9,r8
	ctx.r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lvlx128 v59,r31,r8
	temp.u32 = ctx.r31.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lvrx128 v58,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v57,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v21,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvlx128 v56,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v20,v62,v58
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvlx128 v55,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r31,r10,r8
	ctx.r31.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvrx128 v54,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltisb v14,-1
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_set1_epi8(char(0xFF)));
	// lvlx128 v53,r0,r28
	temp.u32 = ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v24,v55,v54
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8)));
	// lvrx128 v52,r11,r28
	temp.u32 = ctx.r11.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// lvrx128 v51,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v25,v53,v52
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// lvrx128 v50,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v23,v57,v51
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// lvrx128 v49,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v22,v60,v50
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8)));
	// lvrx128 v48,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v19,v59,v49
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// vor128 v18,v56,v48
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// lvx128 v1,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltish v26,4
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_set1_epi16(short(0x4)));
	// li r25,0
	ctx.r25.s64 = 0;
	// lvx128 v12,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v25
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsplth v27,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_set1_epi16(short(0xD0C))));
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// vmrghb v12,v0,v24
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r27,r8,-4
	ctx.r27.s64 = ctx.r8.s64 + -4;
	// vmrghb v9,v0,v23
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v11,v0,v22
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v16,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vmrghb v10,v0,v21
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v8,v0,v20
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v7,v0,v19
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v18
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltisw v17,4
	simde_mm_store_si128((simde__m128i*)ctx.v17.u32, simde_mm_set1_epi32(int(0x4)));
	// vupkhsh v15,v16
	simde_mm_store_si128((simde__m128i*)ctx.v15.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16))));
loc_8272A1C0:
	// vsubshs v3,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r30,r1,-192
	ctx.r30.s64 = ctx.r1.s64 + -192;
	// vsubshs v2,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v29,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v28,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v4,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v31,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v30,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vor128 v47,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stvx128 v4,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v45,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor128 v43,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vsubshs v12,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v10,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v8,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vor128 v46,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vor128 v44,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vsubshs v4,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v11,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v9,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vor128 v42,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vmaxsh v29,v12,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v28,v10,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmaxsh v2,v8,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v30,v11,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v31,v9,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v12,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v29,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vcmpgtuh v28,v13,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vcmpgtuh v2,v13,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// lvx128 v7,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtuh v30,v13,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmaxsh v3,v7,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtuh v31,v13,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v31.u16)));
	// vmaxsh v12,v12,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v29,v29,v28
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vcmpgtuh v3,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vaddshs v28,v31,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v3,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtuh v2,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vaddshs v31,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vaddshs v30,v2,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v29,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v3,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vperm v3,v3,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vcmpgtsh. v29,v3,v26
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), 0xFFFF);
	// mfocrf r24,2
	ctx.r24.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r30,r24,0,26,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x20;
	// vor128 v12,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v47.u8));
	// vor128 v11,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v46.u8));
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v45.u8));
	// vor128 v9,v44,v44
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v44.u8));
	// vor128 v8,v43,v43
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v43.u8));
	// vor128 v7,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v42.u8));
	// beq cr6,0x8272a4f4
	if (ctx.cr6.eq) goto loc_8272A4F4;
	// vminsh v31,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vminsh v2,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vmaxsh v28,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vmaxsh v30,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vor128 v41,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vminsh v2,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vminsh v0,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vmaxsh v30,v28,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v31,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vminsh v28,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v2,v31,v30
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v2,v2,v28
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vcmpgtsh. v30,v16,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), 0xFFFF);
	// vupkhsh v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// vcmpgtsw. v28,v15,v31
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v15.u32), simde_mm_load_si128((simde__m128i*)ctx.v31.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)), 0xF);
	// vand128 v63,v30,v29
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// mfocrf r30,2
	ctx.r30.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsw. v31,v15,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v15.u32), simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)), 0xF);
	// mfocrf r28,2
	ctx.r28.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupkhsh v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// vcmpgtsw. v28,v30,v17
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)), 0xF);
	// mfocrf r29,2
	ctx.r29.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v2,v3,v17
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)), 0xF);
	// mfocrf r23,2
	ctx.r23.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r22,r29,0,26,26
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// vor128 v0,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v41.u8));
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmplwi cr6,r22,32
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 32, ctx.xer);
	// beq cr6,0x8272a328
	if (ctx.cr6.eq) goto loc_8272A328;
	// rlwinm r30,r30,0,26,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// bne cr6,0x8272a340
	if (!ctx.cr6.eq) goto loc_8272A340;
loc_8272A328:
	// rlwinm r30,r29,0,26,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// beq cr6,0x8272a4f4
	if (ctx.cr6.eq) goto loc_8272A4F4;
	// rlwinm r30,r28,0,26,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// beq cr6,0x8272a4f4
	if (ctx.cr6.eq) goto loc_8272A4F4;
loc_8272A340:
	// vsubshs v31,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r23,r1,-208
	ctx.r23.s64 = ctx.r1.s64 + -208;
	// vsubshs v3,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// addi r22,r1,-224
	ctx.r22.s64 = ctx.r1.s64 + -224;
	// vaddshs v30,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// addi r21,r1,-176
	ctx.r21.s64 = ctx.r1.s64 + -176;
	// vaddshs v2,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// addi r30,r1,-256
	ctx.r30.s64 = ctx.r1.s64 + -256;
	// vmaxsh v4,v31,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r29,r1,-240
	ctx.r29.s64 = ctx.r1.s64 + -240;
	// vsubshs v28,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// addi r28,r1,-272
	ctx.r28.s64 = ctx.r1.s64 + -272;
	// vaddshs v31,v30,v26
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vandc128 v39,v12,v63
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vcmpgtsh v30,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmaxsh v3,v28,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vor128 v60,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vor128 v61,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vandc128 v37,v7,v30
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vand128 v36,v5,v30
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vcmpgtsh v4,v27,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vaddshs v3,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v28,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vxor128 v5,v36,v37
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// vandc128 v34,v12,v4
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vand128 v33,v6,v4
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stvx128 v3,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v38,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vaddshs v30,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v3,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vxor128 v6,v33,v34
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8)));
	// vsubshs v4,v5,v9
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// stvx128 v30,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v59,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vandc128 v40,v9,v63
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vaddshs v30,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v12,v2,v3
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v0,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v3,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vaddshs v11,v6,v9
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// stvx128 v4,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v4,v31,v12
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v30,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v3,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vandc128 v35,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vandc128 v32,v7,v63
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vandc128 v62,v8,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)));
	// vaddshs v30,v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// lvx128 v0,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v31,v11,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// lvx128 v0,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v31,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// lvx128 v12,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v30,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v28,v28,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v4,v12,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand128 v58,v31,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v57,v30,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vsrah v3,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v31,v4,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v2,v0,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v30,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vxor128 v56,v58,v40
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8)));
	// vxor128 v55,v57,v39
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8)));
	// vand128 v54,v3,v63
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v53,v2,v63
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v51,v31,v63
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v50,v30,v63
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vpkshus128 v52,v55,v56
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v56.s16), simde_mm_load_si128((simde__m128i*)ctx.v55.s16)));
	// vxor128 v3,v54,v35
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8)));
	// vxor128 v49,v53,v32
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8)));
	// vxor128 v48,v51,v62
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vxor128 v4,v50,v38
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8)));
	// stvx128 v52,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-248(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// lwz r23,-256(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// vpkshus128 v47,v48,v49
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v49.s16), simde_mm_load_si128((simde__m128i*)ctx.v48.s16)));
	// vpkshus128 v46,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// stvx128 v47,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r23,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r23.u32);
	// stvx128 v46,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,-232(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// lwz r23,-272(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// vor128 v0,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// lwz r22,-264(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// lwz r29,-240(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// stw r29,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
	// stw r28,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r28.u32);
	// stwx r23,r27,r31
	REX_STORE_U32(ctx.r27.u32 + ctx.r31.u32, ctx.r23.u32);
	// lwz r28,-268(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r23,-260(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// lwz r21,-252(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// lwz r20,-244(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// stw r22,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r22.u32);
	// lwz r30,-236(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// lwz r29,-228(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// stw r21,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r21.u32);
	// stw r20,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r20.u32);
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stwx r28,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r28.u32);
	// stw r23,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r23.u32);
	// b 0x8272a4fc
	goto loc_8272A4FC;
loc_8272A4F4:
	// vor v3,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor v4,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
loc_8272A4FC:
	// rlwinm r30,r24,0,24,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r30,128
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 128, ctx.xer);
	// beq cr6,0x8272a584
	if (ctx.cr6.eq) goto loc_8272A584;
	// vsubshs v2,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vxor128 v45,v14,v29
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// vsubshs v31,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v31,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsh v30,v27,v31
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v31.u16)));
	// vcmpgtsh v29,v31,v13
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vand128 v44,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vand128 v30,v44,v45
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// vcmpequh. v28,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), 0xFFFF);
	// blt cr6,0x8272a584
	if (ctx.cr6.lt) goto loc_8272A584;
	// vspltish v29,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_set1_epi16(short(0x2)));
	// addi r30,r1,-272
	ctx.r30.s64 = ctx.r1.s64 + -272;
	// vspltish v28,15
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_set1_epi16(short(0xF)));
	// vsrah v31,v31,v29
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v2,v2,v28
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v29,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vand v28,v2,v29
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// vsubshs v2,v31,v28
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vand v2,v2,v30
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vsubshs v31,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v30,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vpkshus128 v43,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// stvx128 v43,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r24,-268(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r29,-264(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// lwz r28,-260(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// lwz r30,-272(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// stw r24,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r24.u32);
	// stw r29,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r29.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_8272A584:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8272a5c0
	if (!ctx.cr6.eq) goto loc_8272A5C0;
	// vmrglb v6,v0,v25
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// vmrglb v12,v0,v24
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// vmrglb v9,v0,v23
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// vmrglb v11,v0,v22
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// vmrglb v10,v0,v21
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// vmrglb v8,v0,v20
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v7,v0,v19
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v5,v0,v18
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
loc_8272A5C0:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// blt cr6,0x8272a1c0
	if (ctx.cr6.lt) goto loc_8272A1C0;
loc_8272A5CC:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8272abfc
	if (ctx.cr6.eq) goto loc_8272ABFC;
	// addi r10,r4,-4
	ctx.r10.s64 = ctx.r4.s64 + -4;
	// stw r7,-192(r1)
	REX_STORE_U32(ctx.r1.u32 + -192, ctx.r7.u32);
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// addi r7,r1,-192
	ctx.r7.s64 = ctx.r1.s64 + -192;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvx128 v1,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,0
	ctx.r26.s64 = 0;
	// vspltisb v21,-1
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_set1_epi8(char(0xFF)));
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// vspltish v20,2
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_set1_epi16(short(0x2)));
	// lvlx128 v42,r10,r8
	temp.u32 = ctx.r10.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// add r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lvlx128 v41,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v40,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltish v25,4
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_set1_epi16(short(0x4)));
	// add r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lvrx128 v39,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v38,r6,r8
	temp.u32 = ctx.r6.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v12,v41,v39
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8)));
	// add r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 + ctx.r8.u64;
	// lvrx128 v37,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v36,r5,r8
	temp.u32 = ctx.r5.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v11,v42,v37
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// add r31,r3,r8
	ctx.r31.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lvrx128 v35,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v34,r4,r8
	temp.u32 = ctx.r4.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v10,v40,v35
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8)));
	// add r30,r31,r8
	ctx.r30.u64 = ctx.r31.u64 + ctx.r8.u64;
	// lvrx128 v33,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v32,r3,r8
	temp.u32 = ctx.r3.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v9,v38,v33
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v33.u8)));
	// lvrx128 v63,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vmrghb v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvlx128 v62,r31,r8
	temp.u32 = ctx.r31.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v8,v36,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvrx128 v61,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vmrghb v11,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvrx128 v60,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v7,v34,v61
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvrx128 v59,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v6,v32,v60
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vor128 v5,v62,v59
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v30,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stw r26,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r26.u32);
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghh v4,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghh v3,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v2,v10,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrghh v31,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vmrglh v12,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v11,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrglh v10,v10,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrglh v9,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vsplth v27,v30,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_set1_epi16(short(0xD0C))));
	// vmrghh v8,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrghh v7,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v6,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrglh v5,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vaddshs v24,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vmrghh v4,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v3,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v31,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v2,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v12,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrglh v11,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrghh v7,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vmrglh v10,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vspltisw v23,4
	simde_mm_store_si128((simde__m128i*)ctx.v23.u32, simde_mm_set1_epi32(int(0x4)));
	// vmrghh v9,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrglh v6,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrghh v5,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v8,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vupkhsh v22,v24
	simde_mm_store_si128((simde__m128i*)ctx.v22.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16))));
loc_8272A714:
	// vsubshs v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v28,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v30,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v29,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsubshs v2,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v26,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v17,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v19,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v18,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v16,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v15,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v4,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vmaxsh v14,v26,v3
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v3,v17,v28
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmaxsh v28,v19,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v29,v18,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v26,v16,v31
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vmaxsh v19,v15,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v18,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v17,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vcmpgtuh v3,v13,v26
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vcmpgtuh v16,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vcmpgtuh v2,v13,v19
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v19.u16)));
	// vmaxsh v30,v18,v4
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v15,v13,v28
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vcmpgtuh v31,v13,v14
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v14.u16)));
	// vaddshs v29,v16,v17
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vcmpgtuh v19,v13,v30
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vaddshs v28,v3,v15
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v15.s16)));
	// vaddshs v26,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v18,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vaddshs v17,v19,v26
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vaddshs v16,v17,v18
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vsubshs v3,v0,v16
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vperm v3,v3,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vcmpgtsh. v26,v3,v25
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), 0xFFFF);
	// mfocrf r27,2
	ctx.r27.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r7,r27,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x8272aa20
	if (ctx.cr6.eq) goto loc_8272AA20;
	// vminsh v2,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vminsh v31,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vmaxsh v30,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vmaxsh v29,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vminsh v28,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vminsh v19,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v18,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vmaxsh v17,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vminsh v16,v28,v19
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vmaxsh v15,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vsubshs v2,v15,v16
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vcmpgtsh. v31,v24,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), 0xFFFF);
	// vupkhsh v14,v2
	simde_mm_store_si128((simde__m128i*)ctx.v14.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// vcmpgtsw. v30,v22,v14
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), simde_mm_load_si128((simde__m128i*)ctx.v14.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v30.u32)), 0xF);
	// vand128 v63,v31,v26
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// mfocrf r7,2
	ctx.r7.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v29,v2
	simde_mm_store_si128((simde__m128i*)ctx.v29.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsw. v28,v22,v29
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), simde_mm_load_si128((simde__m128i*)ctx.v29.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)), 0xF);
	// mfocrf r28,2
	ctx.r28.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupkhsh v19,v3
	simde_mm_store_si128((simde__m128i*)ctx.v19.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// vcmpgtsw. v18,v19,v23
	simde_mm_store_si128((simde__m128i*)ctx.v18.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), simde_mm_load_si128((simde__m128i*)ctx.v23.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v18.u32)), 0xF);
	// mfocrf r29,2
	ctx.r29.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v17,v3
	simde_mm_store_si128((simde__m128i*)ctx.v17.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v16,v17,v23
	simde_mm_store_si128((simde__m128i*)ctx.v16.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v17.u32), simde_mm_load_si128((simde__m128i*)ctx.v23.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v16.u32)), 0xF);
	// mfocrf r25,2
	ctx.r25.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r24,r29,0,26,26
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r24,32
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 32, ctx.xer);
	// beq cr6,0x8272a838
	if (ctx.cr6.eq) goto loc_8272A838;
	// rlwinm r7,r7,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// bne cr6,0x8272a850
	if (!ctx.cr6.eq) goto loc_8272A850;
loc_8272A838:
	// rlwinm r7,r29,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x8272aa20
	if (ctx.cr6.eq) goto loc_8272AA20;
	// rlwinm r7,r28,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x8272aa20
	if (ctx.cr6.eq) goto loc_8272AA20;
loc_8272A850:
	// vsubshs v3,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r7,r1,-272
	ctx.r7.s64 = ctx.r1.s64 + -272;
	// vsubshs v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r29,r1,-224
	ctx.r29.s64 = ctx.r1.s64 + -224;
	// vor128 v58,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// addi r28,r1,-240
	ctx.r28.s64 = ctx.r1.s64 + -240;
	// vaddshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// addi r26,r1,-256
	ctx.r26.s64 = ctx.r1.s64 + -256;
	// vsubshs v30,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v29,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vor128 v57,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vaddshs v2,v31,v25
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vmaxsh v28,v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v19,v27,v29
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vaddshs v31,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v18,v10,v5
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vcmpgtsh v17,v27,v28
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vandc128 v55,v5,v19
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vand128 v54,v8,v19
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8)));
	// vaddshs v16,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vandc128 v52,v11,v17
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vand128 v51,v12,v17
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v17.u8)));
	// vxor128 v8,v54,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// vandc128 v56,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vandc128 v53,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vxor128 v12,v51,v52
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// vaddshs v3,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v15,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v14,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v30,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v4,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v29,v31,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v28,v15,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v19,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v17,v4,v30
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v15,v12,v7
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v4,v2,v29
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vaddshs v3,v19,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vandc128 v50,v7,v63
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vandc128 v49,v9,v63
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vaddshs v2,v16,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v31,v18,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v30,v17,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v29,v15,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v19,v14,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v14.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v18,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v17,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v16,v29,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v15,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand128 v46,v18,v63
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v45,v17,v63
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v44,v16,v63
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vsrah v14,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v4,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v3,v15,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vxor128 v29,v46,v56
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// vxor128 v43,v45,v53
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8)));
	// vxor128 v42,v44,v50
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8)));
	// vand128 v40,v4,v63
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v39,v3,v63
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vandc128 v48,v6,v63
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vpkshus128 v4,v58,v43
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v43.s16), simde_mm_load_si128((simde__m128i*)ctx.v58.s16)));
	// vandc128 v47,v5,v63
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vpkshus128 v3,v42,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v42.s16)));
	// vand128 v41,v14,v63
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v38,v40,v48
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// vxor128 v37,v39,v47
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8)));
	// vmrghb v30,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vxor128 v28,v41,v49
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// vmrglb v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vpkshus128 v31,v37,v57
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v57.s16), simde_mm_load_si128((simde__m128i*)ctx.v37.s16)));
	// vpkshus128 v2,v28,v38
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v38.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmrghb v19,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrglb v18,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrghb v3,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vmrglb v2,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// stvx128 v19,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-220(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// vmrghb v17,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// vmrglb v16,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// stvx128 v16,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,-256(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// lwz r21,-252(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// stvx128 v17,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,-248(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// lwz r18,-272(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// lwz r17,-268(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r16,-264(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// lwz r15,-260(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// lwz r14,-224(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -224);
	// stw r18,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r18.u32);
	// lwz r29,-216(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// stw r17,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r17.u32);
	// lwz r28,-212(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -212);
	// stw r16,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r16.u32);
	// stw r15,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r15.u32);
	// stw r14,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r14.u32);
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// lwz r23,-228(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// lwz r19,-244(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// lwz r26,-240(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// lwz r25,-236(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// lwz r24,-232(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// stw r26,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r26.u32);
	// stw r25,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r25.u32);
	// stw r24,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r24.u32);
	// stw r23,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r23.u32);
	// stw r22,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r22.u32);
	// stw r21,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r21.u32);
	// stw r20,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r20.u32);
	// lwz r26,-288(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// stw r19,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r19.u32);
	// b 0x8272aa28
	goto loc_8272AA28;
loc_8272AA20:
	// vor v28,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vor v29,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
loc_8272AA28:
	// rlwinm r7,r27,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,128
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 128, ctx.xer);
	// beq cr6,0x8272aae4
	if (ctx.cr6.eq) goto loc_8272AAE4;
	// vsubshs v3,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vxor128 v36,v21,v26
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// vsubshs v4,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v2,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vcmpgtsh v31,v4,v13
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vand128 v35,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vand128 v2,v35,v36
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)ctx.v36.u8)));
	// vcmpequh. v30,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), 0xFFFF);
	// blt cr6,0x8272aae4
	if (ctx.cr6.lt) goto loc_8272AAE4;
	// vsrah v4,v4,v20
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vspltish v31,15
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_set1_epi16(short(0xF)));
	// addi r7,r1,-192
	ctx.r7.s64 = ctx.r1.s64 + -192;
	// addi r29,r1,-208
	ctx.r29.s64 = ctx.r1.s64 + -208;
	// vaddshs v30,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v26,v3,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vand v19,v26,v30
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vsubshs v18,v4,v19
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vand v4,v18,v2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vaddshs v17,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsubshs v16,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vpkshus v15,v17,v17
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// vpkshus v14,v16,v16
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vmrghb v4,v15,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// vmrghh v3,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// stvx128 v3,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,-192(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// stvx128 v2,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,-180(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -180);
	// lwz r27,-208(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -208);
	// lwz r25,-204(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -204);
	// lwz r24,-200(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// lwz r23,-196(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -196);
	// sth r22,3(r10)
	REX_STORE_U16(ctx.r10.u32 + 3, ctx.r22.u16);
	// lwz r7,-188(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// lwz r28,-184(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -184);
	// sth r7,3(r9)
	REX_STORE_U16(ctx.r9.u32 + 3, ctx.r7.u16);
	// sth r28,3(r6)
	REX_STORE_U16(ctx.r6.u32 + 3, ctx.r28.u16);
	// sth r29,3(r5)
	REX_STORE_U16(ctx.r5.u32 + 3, ctx.r29.u16);
	// sth r27,3(r4)
	REX_STORE_U16(ctx.r4.u32 + 3, ctx.r27.u16);
	// sth r25,3(r3)
	REX_STORE_U16(ctx.r3.u32 + 3, ctx.r25.u16);
	// sth r24,3(r31)
	REX_STORE_U16(ctx.r31.u32 + 3, ctx.r24.u16);
	// sth r23,3(r30)
	REX_STORE_U16(ctx.r30.u32 + 3, ctx.r23.u16);
loc_8272AAE4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x8272abec
	if (!ctx.cr6.eq) goto loc_8272ABEC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// add r4,r4,r8
	ctx.r4.u64 = ctx.r4.u64 + ctx.r8.u64;
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lvlx128 v34,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r31,r31,r8
	ctx.r31.u64 = ctx.r31.u64 + ctx.r8.u64;
	// lvlx128 v33,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r30,r30,r8
	ctx.r30.u64 = ctx.r30.u64 + ctx.r8.u64;
	// lvlx128 v32,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v62,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v61,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v60,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v59,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v58,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v57,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v12,v34,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvrx128 v56,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v11,v33,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// lvrx128 v55,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v10,v32,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// lvrx128 v54,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v9,v63,v55
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// lvrx128 v53,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v8,v62,v54
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8)));
	// lvrx128 v52,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v7,v61,v53
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8)));
	// lvrx128 v51,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v6,v60,v52
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// vor128 v5,v59,v51
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// vmrghb v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v11,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghh v4,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghh v3,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v2,v10,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrghh v31,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vmrglh v12,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v11,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrglh v10,v10,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrglh v9,v9,v5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vmrghh v8,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrghh v7,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v6,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrglh v5,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrghh v4,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v3,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v31,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v2,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v12,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrglh v11,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrghh v7,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vmrglh v10,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vmrghh v9,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrglh v6,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrghh v5,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v8,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
loc_8272ABEC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r26,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r26.u32);
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// blt cr6,0x8272a714
	if (ctx.cr6.lt) goto loc_8272A714;
loc_8272ABFC:
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B4358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,23720
	ctx.r9.s64 = ctx.r11.s64 + 23720;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5570) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-6264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6264);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-6108(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -6108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6940) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5948(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8B28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24580);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4980(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B98B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4580(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA6E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB4D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC2E0) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3308(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD580) {
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
	// lfs f0,25688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2764(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1860(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0348) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1452(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1452);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1400(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1400, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1368) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1008(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1008);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-924(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-428(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C34C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,40(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C43E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6EF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// addi r9,r9,-31120
	ctx.r9.s64 = ctx.r9.s64 + -31120;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r8,1792
	ctx.r11.s64 = ctx.r8.s64 + 1792;
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
	// stfs f13,1792(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 1792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9A80) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3096(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAC68) {
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
	// lfs f0,28968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3620(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBE10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4160(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCEB8) {
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
	// lfs f0,29288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4520(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4520);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE180) {
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
	// lfs f0,29480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5188(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5628(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5628);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0218) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0FD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1F78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,30120
	ctx.r9.s64 = ctx.r11.s64 + 30120;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D32D8) {
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
	// lfs f0,30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7564(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4580) {
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
	// lfs f0,30504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8108(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D57F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,8640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8640);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8644(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D61A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D70B8) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,9908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9908);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9912(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 9912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8D18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10188);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9AD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DABA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,10980(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10980);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11084(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB9E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC798) {
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
	// lfs f12,11744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11900(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDC20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,12516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE9B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32228);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13372, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E08F0) {
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
	// lfs f0,32504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13728(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13728);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2A80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4A70) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15744(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-30648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16300(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16300);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6F38) {
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
	// lfs f0,-28600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16792(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8210) {
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
	// lfs f0,-26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17304(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA4F0) {
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
	// lfs f0,-23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23624);
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
	// stfs f0,18284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-22536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,18756(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18756);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18860(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19268(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED890) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,19720
	ctx.r6.s64 = ctx.r8.s64 + 19720;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,19720(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 19720);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,19720(r8)
	REX_STORE_U32(ctx.r8.u32 + 19720, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,19720(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 19720);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,19720(r8)
	REX_STORE_U32(ctx.r8.u32 + 19720, ctx.r11.u32);
	// stb r9,19720(r8)
	REX_STORE_U8(ctx.r8.u32 + 19720, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF008) {
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
	// lfs f0,-19900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19900);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,20360(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 20360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0BC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1B88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,22472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,22476(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 22476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F46F0) {
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
	// lfs f0,-16680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22904(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22904);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F68C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23980(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7880) {
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
	// lfs f0,-14008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14008);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,24412(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 24412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA2D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,25456(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25456);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FBFC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD090) {
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
	// lfs f0,-9368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26892(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27872(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800190) {
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
	// lfs f0,-8856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28220(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28220);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28324(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828014A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28772(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28772);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802378) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803178) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804288) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805F58) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30976);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-7704
	ctx.r9.s64 = ctx.r11.s64 + -7704;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808758) {
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
	// lfs f0,-7512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32740(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A8E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B7E0) {
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
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31984(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31984);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31896(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CBA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-6744
	ctx.r9.s64 = ctx.r11.s64 + -6744;
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31300(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -31300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DBC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E9E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-30420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30420);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30416(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F450) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30112(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828104D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811450) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29160(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828122A8) {
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
	// lfs f0,-5656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28804);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28740(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813630) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828143D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27716(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828154E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27204);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828164C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26732);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817468) {
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
	// lfs f0,-4232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26320(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26320);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828185C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-3896
	ctx.r9.s64 = ctx.r11.s64 + -3896;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-3896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25732(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AB28) {
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
	// lfs f0,-3224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24684(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24684);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24612(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BE38) {
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
	// lfs f0,-3032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24052(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23476);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E288) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23012(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -23012);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22960(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F200) {
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
	// lfs f0,-2200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22572(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22572);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22504(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828204F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828216A8) {
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
	// lfs f0,-1784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21432(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822A70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823890) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828249C0) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20040(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20040);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19920(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825BF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19364);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826DC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827C00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828BF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-17956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17956);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-17952(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -17952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829598) {
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
	// lfs f0,-17712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,736(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 736);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17676(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A6F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,152
	ctx.r9.s64 = ctx.r11.s64 + 152;
	// lfs f0,152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17164(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -17164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16700(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C810) {
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
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16348);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f0,f13,f12
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f0,-16188(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282DA88) {
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
	// lfs f0,792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282EED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15152(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15152);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FDA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830B70) {
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
	// lfs f0,1416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832288) {
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
	// lfs f0,1768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833468) {
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
	// lfs f0,1992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13084);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834A18) {
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
	// lfs f12,-12432(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12432);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837AF0) {
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
	// lfs f0,2872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10888(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838F98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-10408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10408);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-10288(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839940) {
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
	// lfs f0,3232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283AD68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,3472
	ctx.r9.s64 = ctx.r11.s64 + 3472;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,3472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9412(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,3712
	ctx.r9.s64 = ctx.r11.s64 + 3712;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,3712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8824(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8324(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8324);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F3C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828404F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841390) {
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
	// lfs f0,4752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6496);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842750) {
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
	// lfs f0,4992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5840(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843B00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844C38) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4744(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845E20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,5744
	ctx.r9.s64 = ctx.r11.s64 + 5744;
	// lfs f0,5744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4204(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3732);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847ED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,6112
	ctx.r9.s64 = ctx.r11.s64 + 6112;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3236(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2768(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2768);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B0C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1776(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D158) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-828(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-340(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EFE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,92(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 92, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FFC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850F98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1056(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851FA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853028) {
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
	// lfs f0,8568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82854390) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r10,32688
	ctx.r10.s64 = ctx.r10.s64 + 32688;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r9,r9,3184
	ctx.r9.s64 = ctx.r9.s64 + 3184;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// li r6,48
	ctx.r6.s64 = 48;
	// vmrghw128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vor128 v58,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmrghw128 v62,v60,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vmrghw128 v61,v59,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vor128 v57,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vmrghw128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// vor128 v62,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vmrghw128 v60,v58,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrghw128 v59,v57,v59
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// vmrghw128 v58,v58,v62
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrghw128 v62,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vor128 v61,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// vor128 v60,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v63,v59,v58
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v61,v61,v56
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrghw128 v60,v60,v57
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// stvx128 v62,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// stvx128 v63,r9,r7
	ea = (ctx.r9.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r9,r6
	ea = (ctx.r9.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8288AC40) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,48
	ctx.r6.s64 = 48;
	// beq cr6,0x8288ac5c
	if (ctx.cr6.eq) goto loc_8288AC5C;
	// b 0x828847a0
	sub_828847A0(ctx, base);
	return;
loc_8288AC5C:
	// b 0x828827e8
	sub_828827E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8288B7C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8288B7D0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// lbz r25,668(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 668);
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// addi r27,r3,232
	ctx.r27.s64 = ctx.r3.s64 + 232;
	// lwz r10,24(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// clrlwi r26,r25,30
	ctx.r26.u64 = ctx.r25.u32 & 0x3;
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r4,632(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 632);
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
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
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8288b848
	if (ctx.cr6.lt) goto loc_8288B848;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288B840;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288b8a0
	goto loc_8288B8A0;
loc_8288B848:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8288b89c
	if (!ctx.cr6.gt) goto loc_8288B89C;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8288B854:
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
	// lbzx r23,r3,r27
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r27.u32);
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
	// bdnz 0x8288b854
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288B854;
loc_8288B89C:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8288B8A0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8288b90c
	if (!ctx.cr6.eq) goto loc_8288B90C;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r26,31
	ctx.r10.u64 = ctx.r26.u32 & 0x1;
	// rlwinm r9,r26,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x8;
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
	// b 0x8288b928
	goto loc_8288B928;
loc_8288B90C:
	// rlwinm r10,r26,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x8;
	// clrlwi r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x82871330
	ctx.lr = 0x8288B928;
	sub_82871330(ctx, base);
loc_8288B928:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r9,r25,30,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// clrlwi r26,r9,30
	ctx.r26.u64 = ctx.r9.u32 & 0x3;
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
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8288b984
	if (ctx.cr6.lt) goto loc_8288B984;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288B97C;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288b9dc
	goto loc_8288B9DC;
loc_8288B984:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8288b9d8
	if (!ctx.cr6.gt) goto loc_8288B9D8;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8288B990:
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
	// lbzx r29,r3,r27
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r27.u32);
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
	// bdnz 0x8288b990
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288B990;
loc_8288B9D8:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8288B9DC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r26,31
	ctx.r10.u64 = ctx.r26.u32 & 0x1;
	// bne cr6,0x8288ba4c
	if (!ctx.cr6.eq) goto loc_8288BA4C;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// rlwinm r9,r26,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x8;
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
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_8288BA4C:
	// rlwinm r11,r26,2,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x82871330
	ctx.lr = 0x8288BA64;
	sub_82871330(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82894C88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82894C90;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 52);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lhz r10,50(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 50);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r31,r11,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r30,1320(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 1320);
	// rlwinm r28,r10,31,1,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mullw r11,r28,r31
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r31.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8273a590
	ctx.lr = 0x82894CC8;
	sub_8273A590(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82894d9c
	if (ctx.cr6.eq) goto loc_82894D9C;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r10,r30,-6
	ctx.r10.s64 = ctx.r30.s64 + -6;
	// addi r11,r29,-24
	ctx.r11.s64 = ctx.r29.s64 + -24;
	// addi r9,r9,16408
	ctx.r9.s64 = ctx.r9.s64 + 16408;
loc_82894CE0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82894d94
	if (ctx.cr6.eq) goto loc_82894D94;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
loc_82894CEC:
	// lbz r6,33(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 33);
	// addi r7,r9,-56
	ctx.r7.s64 = ctx.r9.s64 + -56;
	// lbz r4,32(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 32);
	// addi r5,r9,-56
	ctx.r5.s64 = ctx.r9.s64 + -56;
	// rotlwi r8,r6,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// lbz r6,35(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 35);
	// lbz r3,34(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 34);
	// or r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rotlwi r6,r6,3
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// addi r4,r9,-16
	ctx.r4.s64 = ctx.r9.s64 + -16;
	// or r3,r6,r3
	ctx.r3.u64 = ctx.r6.u64 | ctx.r3.u64;
	// addi r6,r9,-16
	ctx.r6.s64 = ctx.r9.s64 + -16;
	// lbzx r8,r8,r7
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// stb r8,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r8.u8);
	// lbzx r7,r3,r5
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r5.u32);
	// stb r7,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r7.u8);
	// lbz r30,34(r11)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 34);
	// lbz r3,33(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 33);
	// lbz r8,35(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 35);
	// lbz r7,6(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// lbz r5,32(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 32);
	// rlwinm r5,r5,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r30,r30,1,23,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0x1FC;
	// rlwinm r8,r8,1,23,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1FC;
	// rlwinm r3,r3,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// or r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 | ctx.r30.u64;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// lbzx r5,r5,r4
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// stb r5,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r5.u8);
	// lbzx r4,r3,r6
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r6.u32);
	// stb r4,9(r10)
	REX_STORE_U8(ctx.r10.u32 + 9, ctx.r4.u8);
	// lbz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 36);
	// lbzx r6,r8,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// stb r6,10(r10)
	REX_STORE_U8(ctx.r10.u32 + 10, ctx.r6.u8);
	// lbz r4,37(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 37);
	// lbzx r3,r4,r9
	ctx.r3.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// stb r3,11(r10)
	REX_STORE_U8(ctx.r10.u32 + 11, ctx.r3.u8);
	// lhzu r8,24(r11)
	ea = 24 + ctx.r11.u32;
	ctx.r8.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// rotlwi r8,r8,7
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 7);
	// or r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stbu r7,6(r10)
	ea = 6 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82894cec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82894CEC;
loc_82894D94:
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82894ce0
	if (!ctx.cr0.eq) goto loc_82894CE0;
loc_82894D9C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

